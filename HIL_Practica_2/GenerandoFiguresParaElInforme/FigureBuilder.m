%este script construye figuras de todos los .mat que encuentre en el
%directorio

clear all;
close all;

colores = {'blue' 'red' 'green' 'magenta' 'orange' 'black'};

directoryPath= "C:\Users\chris\Master\HIL\Prac2\GenerandoFiguresParaElInforme";
files= dir(directoryPath);

for i = 3:length(files)
    fileName=files(i).name;
    fileExtension= fileName(length(fileName)-3:length(fileName));
    if (fileExtension=='.mat')
        filepath = fullfile(directoryPath, fileName);
        disp(fileName)
        disp(i)
        Data= load(filepath);
        fieldNames= fieldnames(Data);
        field=fieldNames{1,1};
        figure(i)
        nombre=split(fileName,'.');
        titulo= nombre{1,1};
        
        title(string(titulo));
        dimensions=Data.(field).signals.dimensions;
        for j=1:dimensions
            if length(Data.(field).time)>1
                plot(Data.(field).time,Data.(field).signals.values(:,j),colores{1,j});  
            else
                plot(Data.(field).signals.values(:,j),colores{1,j});    
            end
            hold on;
        end
        hold off;
        saveName=directoryPath+'\Figures\'+titulo;
        saveas(gcf, saveName,'fig');
    end

end

