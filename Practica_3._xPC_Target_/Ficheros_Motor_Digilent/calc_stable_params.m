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

cont_flag = 0;
error_flag = 0;

%Esta variable me va a decir que ha cambiado la sig_consigna
lastTimeEnterStableZone = 0; 
% Mediante esta bandera puedo saber si el analisis ha iniciado para
% evitares errores al inicio.
analisysInitiatedFlag = 0;
for i = 1: length(sig_consigna)
  % Cuando la sig_consigna cambia empieza un ciclo. Se empieza guardando
  % el valor de referencia
  if currentReferenceValue ~= sig_consigna(i) %~= significa not equal en matlab

      % timesToStabilize_vector = [timesToStabilize_vector; currentTimeCounter, sig_posicion(i)];

      currentReferenceValue = sig_consigna(i);
      referenceGap = abs(currentReferenceValue * 0.05);
      % Si la ref está alrededor de 0 se toma un margen fijo de ancho 2
      if (currentReferenceValue > -2) && ( currentReferenceValue < 2)
          referenceGap = 2;
          %Estoy hay que mirarlo bien en los apuntes de control 1
      end
      % Resetear contador de tiempo de establecimiento y flags
      currentTimeCounter = 0; cont_flag = 0; error_flag = 0;
  else
      currentTimeCounter = currentTimeCounter + 1;
      % Para evitar problemas en el arranque
      if (analisysInitiatedFlag == 0) & (sig_posicion(i) ~= 0)
          analisysInitiatedFlag = 1;

      end
      % Ya arrancado
      if analisysInitiatedFlag == 1
          if (sig_posicion(i) >= currentReferenceValue - referenceGap) & (sig_posicion(i) <= currentReferenceValue + referenceGap)
              lastTimeEnterStableZone = sig_posicion(i - 1); 
              % Este delta de posicion se usa para verificar que la señal
              % en una tolerancia menor al %1 y que por tanto ya no vuelve
              % a salir de los margenes estabels de +- %5
   
              % MinimumPositionChange
              % MinimumPositionChange = 
              pos_change = abs(sig_posicion(i) * 0.01); % tolerancia: 1%
              if (abs(sig_posicion(i) - lastTimeEnterStableZone) <= pos_change) && (cont_flag == 0)
                  timesToStabilize_vector = [timesToStabilize_vector; currentTimeCounter, sig_posicion(i)];
                  % Se activa flag para que no guarde t_stable varias veces
                  cont_flag = 1;
              end
              % Para el error en la permanente
              if (sig_posicion(i) == lastTimeEnterStableZone) & (error_flag == 0)
                  error_flag = 1;
                  error_gap = abs(sig_posicion(i) - currentReferenceValue);
                  stable_errors = [stable_errors; currentTimeCounter, error_gap];
              end
          end
      end
  end
end
stable_params = [timesToStabilize_vector, stable_errors];
end