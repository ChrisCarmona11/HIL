clear all;
tg = xpc;
tg_P = getparam(tg, 'PI Controller/P');
tg_I = getparam(tg, 'PI Controller/I');
flag = 0; p=[1,5,10]./10; i=[0.01,0.05,0.1];
for k = 1 : 1 : 3
  P=p(k); 
  setparam(tg,'PI Controller','P',P);       % Set damping factor (Gain1/Gain)
    for j = 1 : 1 : 3                % Loop over damping factor z
      I=i(j);
      setparam(tg,'PI Controller','I',I);       % Set damping factor (Gain1/Gain)
      
      %Reiniciando los buffers
      y = zeros(51,1); s = zeros(51,1); e = zeros(51,1);
      
      %Ejecución de la simulación
      start(tg);                            % Start model execution
      pause(1*tg.StopTime);               
      
      
      %Cargar datos para guardar.
      output_salida = getscope(tg,3);
      consigna_salida_vec= output_salida.Data;
      
      output_error = getscope(tg,6);
      error_vec = output_error.Data;
      %Nos intera guarda:
      
      %la consigna y salida
      y    = cat(1,y, consigna_salida_vec(:, 1)); %señal de salida
      %la señal de control
      s    = cat(1,s, consigna_salida_vec(:, 2)); %señal de consigna
      %la señal de error
      e    = cat(1,e, error_vec);
      pause(0.5)
      t    = tg.TimeLog;                       % Upload time vector
      consigna = s;
      posicion = y;
      
      %% Calcular SumERR
      SumErr=sum(abs(error_vec));
      %% Calcular rebose
      % Lo que se calcula es el rebose máximo de todo el proceso.
      rebose_val = calc_rebose(posicion,consigna);

      %% Calcular tiempo de establecimiento y Error en permanente
      % La misma función devuelve los valores de tiempo y los errores. Con
      % estos se puede el máxmimo, el mínimo, la media...
      stable_params = calc_stable_params(posicion, consigna);

      time_step = 0.01;
      max_stable_time = time_step * max(stable_params(:, 1));
      max_stable_error = max(stable_params(:, 4));

      %% Guardar y plotear
      save (['Control PI_',num2str(P),'_',num2str(I),'.mat'],'consigna','posicion','error_vec','P','I','SumErr');
      plot(t, s,'b',t, y,'r');                  % Plot data for current run
      set(gca, 'XLim', [t(1), t(end)], 'YLim', [-50, 400]);
      title(['DC Motor: Proportional Gairg = ', num2str(P),'Integral Gain = ',num2str(I)]);
      xlabel('Time'); ylabel('Output');
      drawnow;
      saveas(gcf, ['P=', num2str(P),'_I=',num2str(I),'.fig'], 'fig')    % Guarda las figuras
      end
  end
save Total.mat