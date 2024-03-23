%Si todavia estamos concetados al Target Pc y el .dat
%continua en el disco remoto...
fsys=xpctarget.fs;
h=fsys.fopen('out_tot.dat');
data2=fsys.fread(h);
fsys.fclose(h);
data2 = uint8(data2');
new_data2=readxpcfile(data2);
plot(new_data2.data)
SumErr_1=sum(abs(new_data2.data(:,1)))


