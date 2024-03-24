function rebose_val = calc_rebose(consigna,posicion)
%calc_rebose Calcular rebose máximo.
%   Detailed explanation goes here
rebose_val = 0;
if max(abs(posicion)) == max(posicion)
    rebose_val = max(posicion);
elseif max(abs(posicion)) == -min(posicion)
    rebose_val = min(posicion);
end
ref_val = consigna(posicion == rebose_val);
rebose_val = abs(rebose_val - ref_val);
end