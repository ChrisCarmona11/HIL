function stable_params = calc_stable_params(sig_consigna,sig_posicion)
%calc_stable_params Calcula tiempo de establecimiento
%   Detailed explanation goes here

%Registros para guardar datos
timesToStabilize_vector = []; stable_errors = [];

%Primera referencia
currentReferenceValue = sig_consigna(1);

%Contador de ciclos de tiempo para estabilizaciones
currentTimeCounter = 0; 

%El margen que debe cumplir para decir que es estable 
referenceGap = currentReferenceValue * 0.05;

inStableZone = 0;
time_inStableZone = 0;
errorMeasuredFlag= 0;

%Esta variable me va a decir que ha cambiado la sig_consigna
lastTimeEnterStableZone = 0; 
% Mediante esta bandera puedo saber si el analisis ha iniciado para
% evitares errores al inicio.
analisysInitiatedFlag = 0;

contadorEscalones = 1;
for i = 1: length(sig_consigna)
  % Cuando la sig_consigna cambia empieza un ciclo. Se empieza guardando
  % el valor de referencia
  if currentReferenceValue ~= sig_consigna(i) %~= significa not equal en matlab
      
      disp(["Escalon numero",contadorEscalones]);
      contadorEscalones=contadorEscalones+1;
     
      if inStableZone == 1
        timesToStabilize_vector = [timesToStabilize_vector; time_inStableZone, lastTimeEnterStableZone];
        inStableZone =0;
        
      end
   
      currentReferenceValue = sig_consigna(i);
      %  if contadorEscalones ==9
      %   disp("miniscalon")
      % end

      referenceGap = (abs(currentReferenceValue-sig_posicion(i-1)) * 0.05);
      if referenceGap<2
            referenceGap=2;
      end 
      %Reiniciar los contadores y flags
      currentTimeCounter = 0; inStableZone = 0;errorMeasuredFlag=0;
  else
      currentTimeCounter = currentTimeCounter + 1;
      % Para evitar problemas en el arranque
      if (analisysInitiatedFlag == 0) & (sig_posicion(i) ~= 0)
          analisysInitiatedFlag = 1;
      end

      % Ya arrancado

      if analisysInitiatedFlag == 1
          %proceso para saber si estoy dentro de la zona estable
          if (sig_posicion(i) >= currentReferenceValue - referenceGap) & (sig_posicion(i) <= currentReferenceValue + referenceGap) 
              if inStableZone==0
                  lastTimeEnterStableZone = sig_posicion(i - 1); 
                  inStableZone=1;
                  time_inStableZone = currentTimeCounter;
              end
          else
              inStableZone=0;
          end

          % Para el error en la permanente
          if (inStableZone) & (abs(sig_posicion(i)-sig_posicion(i-10))<=1)
              if errorMeasuredFlag == 0
                  errorMeasuredFlag = 1;
                  error_gap = abs(sig_posicion(i) - currentReferenceValue);
                  stable_errors = [stable_errors; currentTimeCounter, error_gap];
              end
          end
      end
  end
end
%Como dependo de que haya un salto para guardar el ultimo paso no vera un
%salto posteior asi que se mete asi a mano.
if inStableZone == 1
    timesToStabilize_vector = [timesToStabilize_vector; time_inStableZone, lastTimeEnterStableZone];
end

stable_params = [timesToStabilize_vector, stable_errors];
end