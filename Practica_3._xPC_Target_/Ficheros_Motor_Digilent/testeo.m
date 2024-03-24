%posicion_t = [1,2,5,-4,-3,-4,-2,4];
%consigna_t = [3,3,3,-2,-2,-2,-2,3];

% Consigna y posicion estan guardados al reves en el .mat
times_array = calc_stable_params(posicion, consigna);
%rebose_val = calc_rebose(posicion,consigna);
max_stable_time = 0.01 * max(times_array(:, 1));

% stable_times = [];
% ref_val = consigna(1);
% cont_stable = 0; ref_gap = ref_val * 0.05;
% cont_flag = 0;
% pos_prev = 0; init = 0;
% for i = 1: length(consigna)
%   % Cuando la consigna cambia empieza un ciclo. Se empieza guardando
%   % el valor de referencia
%   if ref_val ~= consigna(i)
%       ref_val = consigna(i);
%       ref_gap = abs(ref_val * 0.05);
%       % Si la ref está alrededor de 0 se toma un margen fijo de ancho 2
%       if (ref_val > -2) && ( ref_val < 2)
%           ref_gap = 2;
%       end
%       % Resetear contador de tiempo de establecimiento
%       cont_stable = 0; cont_flag = 0;
%   else
%       cont_stable = cont_stable + 1;
%       % Para evitar problemas en el arranque
%       if (init == 0) & (posicion(i) ~= 0)
%           init = 1;
%       end
%       % Ya arrancado
%       if init == 1
%           if (posicion(i) >= ref_val - ref_gap) & (posicion(i) <= ref_val + ref_gap)
%               pos_prev = posicion(i - 1);
%               % Para verificar que la señal se está estabilizando
%               pos_change = abs(posicion(i) * 0.01); % tolerancia: 1%
%               if (abs(posicion(i) - pos_prev) <= pos_change) && (cont_flag == 0)
%                   stable_times = [stable_times; cont_stable, posicion(i)];
%                   % Se activa flag para que no guarde t_stable varias veces
%                   cont_flag = 1;
%               end
%           end
%       end
%   end
% end