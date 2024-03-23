function xcp = Control_Mov_PI_Digilentxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'Control_Mov_PI_Digilent';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.01;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'Control_Mov_PI_Digilent_B.Constant1';
    
xcp.signals(2).symbol =  'Control_Mov_PI_Digilent_B.EncoderGradosReductora153';
    
xcp.signals(3).symbol =  'Control_Mov_PI_Digilent_B.PCI6221ENC';
    
xcp.signals(4).symbol =  'Control_Mov_PI_Digilent_B.Sum';
    
xcp.signals(5).symbol =  'Control_Mov_PI_Digilent_B.IdealDerivative';
    
xcp.signals(6).symbol =  'Control_Mov_PI_Digilent_B.DerivativeGain';
    
xcp.signals(7).symbol =  'Control_Mov_PI_Digilent_B.IntegralGain';
    
xcp.signals(8).symbol =  'Control_Mov_PI_Digilent_B.ProportionalGain';
    
xcp.signals(9).symbol =  'Control_Mov_PI_Digilent_B.Integrator';
    
xcp.signals(10).symbol =  'Control_Mov_PI_Digilent_B.Sum_i';
    
xcp.signals(11).symbol =  'Control_Mov_PI_Digilent_B.FromWs';
         
xcp.parameters(1).symbol = 'Control_Mov_PI_Digilent_P.PIController_P';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&Control_Mov_PI_Digilent_P.PIController_P';     
         
xcp.parameters(2).symbol = 'Control_Mov_PI_Digilent_P.PIController_I';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&Control_Mov_PI_Digilent_P.PIController_I';     
         
xcp.parameters(3).symbol = 'Control_Mov_PI_Digilent_P.PIController_D';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&Control_Mov_PI_Digilent_P.PIController_D';     
         
xcp.parameters(4).symbol = 'Control_Mov_PI_Digilent_P.Constant1_Value';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&Control_Mov_PI_Digilent_P.Constant1_Value';     
         
xcp.parameters(5).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P1';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P1';     
         
xcp.parameters(6).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P2';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P2';     
         
xcp.parameters(7).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P3';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P3';     
         
xcp.parameters(8).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P4';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P4';     
         
xcp.parameters(9).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P5';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P5';     
         
xcp.parameters(10).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P6';
xcp.parameters(10).size   =  1;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P6';     
         
xcp.parameters(11).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P7';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P7';     
         
xcp.parameters(12).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P8';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P8';     
         
xcp.parameters(13).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P9';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P9';     
         
xcp.parameters(14).symbol = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P10';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P10';     
         
xcp.parameters(15).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P1';
xcp.parameters(15).size   =  2;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P1[0]';     
         
xcp.parameters(16).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P2';
xcp.parameters(16).size   =  2;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P2[0]';     
         
xcp.parameters(17).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P3';
xcp.parameters(17).size   =  2;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P3[0]';     
         
xcp.parameters(18).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P4';
xcp.parameters(18).size   =  2;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P4[0]';     
         
xcp.parameters(19).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P5';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P5';     
         
xcp.parameters(20).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P6';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P6';     
         
xcp.parameters(21).symbol = 'Control_Mov_PI_Digilent_P.PCI6221DA_P7';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&Control_Mov_PI_Digilent_P.PCI6221DA_P7';     
         
xcp.parameters(22).symbol = 'Control_Mov_PI_Digilent_P.Integrator_IC';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&Control_Mov_PI_Digilent_P.Integrator_IC';     

function n = getNumParameters
n = 22;

function n = getNumSignals
n = 11;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

