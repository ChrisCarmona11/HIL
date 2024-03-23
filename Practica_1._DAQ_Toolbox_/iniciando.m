ai=analoginput('nidaq','Dev1');
ao=analogoutput('nidaq','Dev1');
ic=addchannel(ai,[2 0]); 		% Adding the first two differential
                                % inputs to the input object
ic.inputrange=[0 10];                       % Setting the sensor and input
ic(1).SensorRange=ic(1).InputRange; 		% ranges from 0 to 10 volts
ic(1).UnitsRange=ic(1).InputRange;
ic(1).ChannelName='Drain-Source Voltage';	% Naming channel 2 (1st index)
ic(2).UnitsRange=ic(2).InputRange*10; 		% Measuring current indirectly:
ic(2).SensorRange=ic(2).InputRange; 		% I = V/R, where R is 100? and
ic(2).Units='mA';                       	% 1000 mA = 1 A
ic(2).ChannelName='Drain-Source Current';	% Naming channel 0 (2nd index)
ic
oc=addchannel(ao,[0 1]);                % Adding 2 channels to the output object
oc.UnitsRange=oc(1).OutputRange; 		% The unit range on all channels will
                                        % be the same as the default output
                                        % range (-5V to 5V)
oc(1).ChannelName='Vin';                % Naming the output channels, according
oc(2).ChannelName='Vgs';                % to circuit schematic
oc