%Si tenemos el fichero .dat ya almacenado en nuestro
%directorio de trabajo
h=fopen('error_3.dat');
data2=fread(h);
data2 = uint8(data2');
new_data2=readxpcfile(data2);
plot(new_data2.data)
SumErr_1=sum(abs(new_data2.data(:,1)))


