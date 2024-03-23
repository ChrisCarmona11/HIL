h=fopen('error_1.dat');
data2=fread(h);
fclose(h);
data2 = uint8(data2');
new_data2=readxpcfile(data2);
plot(new_data2.data)
SumErr_1=sum(abs(new_data2.data(:,1)))


