%VlegendStr={}; 				% Build up a legend string
%for VgsCt=1:length(VgsList),
%	legendStr{VgsCt}=[num2str(VgsList(VgsCt)) 'V'];
%end
h=plot(Vds,Id);
legend(h(5:end),legendStr(5:end));
xlabel('V_{ds} (V)');
ylabel('I_{d} (mA)');
title('\bf{Lines of constant V_{gs} for JFET');
