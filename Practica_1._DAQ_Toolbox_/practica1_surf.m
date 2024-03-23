Vgs = repmat(VgsList,[length(Vds(:,1)),1]);
surf(Vds, Vgs, Id); % Plot 3-D surface
xlabel('V_{ds} (V)');
ylabel('V_{gs} (V)');
zlabel('I_{d} (mA)');
title('\bf{Operating Characteristics for JFET}');