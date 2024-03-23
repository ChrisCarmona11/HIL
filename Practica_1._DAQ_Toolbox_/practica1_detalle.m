Vds=[ ]; 						% Initializing Drain Voltage &
Id=[ ]; 						% Drain to Source Current
VgsList = [-4.5:.5:-2 -1.75:.25:0];
for Vgs = VgsList
	data=[ ];
	for Vin = -5:0.005:5
		putsample(ao,[Vin,Vgs]); 		% Output drain-source, gate voltages
		data=[data; getsample(ai)]; 		% Acquire vector of all inputs
	end 						% for Vgs
	Vds = [Vds data(:,1)]; 				% Setting up voltage matrix
	Id = [Id data(:,2)]; 				% Setting up current matrix
end 	
