function pt=Control_Mov_PI_Digilentpt
pt = [];

  
pt(1).blockname = 'PI Controller';
pt(1).paramname = 'P';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'Control_Mov_PI_Digilent_P.PIController_P';
pt(1).baseaddr   = '&Control_Mov_PI_Digilent_P.PIController_P';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'PI Controller';
pt(2).paramname = 'I';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'Control_Mov_PI_Digilent_P.PIController_I';
pt(2).baseaddr   = '&Control_Mov_PI_Digilent_P.PIController_I';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'PI Controller';
pt(3).paramname = 'D';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'Control_Mov_PI_Digilent_P.PIController_D';
pt(3).baseaddr   = '&Control_Mov_PI_Digilent_P.PIController_D';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'Constant1';
pt(4).paramname = 'Value';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'Control_Mov_PI_Digilent_P.Constant1_Value';
pt(4).baseaddr   = '&Control_Mov_PI_Digilent_P.Constant1_Value';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'PCI 6221 ENC ';
pt(5).paramname = 'P1';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P1';
pt(5).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P1';
pt(5).dtname     = 'real_T';



  
pt(6).blockname = 'PCI 6221 ENC ';
pt(6).paramname = 'P2';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P2';
pt(6).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P2';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'PCI 6221 ENC ';
pt(7).paramname = 'P3';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P3';
pt(7).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P3';
pt(7).dtname     = 'real_T';



  
pt(8).blockname = 'PCI 6221 ENC ';
pt(8).paramname = 'P4';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';
pt(8).isStruct  = false;
pt(8).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P4';
pt(8).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P4';
pt(8).dtname     = 'real_T';



  
pt(9).blockname = 'PCI 6221 ENC ';
pt(9).paramname = 'P5';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';
pt(9).isStruct  = false;
pt(9).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P5';
pt(9).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P5';
pt(9).dtname     = 'real_T';



  
pt(10).blockname = 'PCI 6221 ENC ';
pt(10).paramname = 'P6';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';
pt(10).isStruct  = false;
pt(10).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P6';
pt(10).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P6';
pt(10).dtname     = 'real_T';



  
pt(11).blockname = 'PCI 6221 ENC ';
pt(11).paramname = 'P7';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';
pt(11).isStruct  = false;
pt(11).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P7';
pt(11).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P7';
pt(11).dtname     = 'real_T';



  
pt(12).blockname = 'PCI 6221 ENC ';
pt(12).paramname = 'P8';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';
pt(12).isStruct  = false;
pt(12).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P8';
pt(12).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P8';
pt(12).dtname     = 'real_T';



  
pt(13).blockname = 'PCI 6221 ENC ';
pt(13).paramname = 'P9';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';
pt(13).isStruct  = false;
pt(13).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P9';
pt(13).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P9';
pt(13).dtname     = 'real_T';



  
pt(14).blockname = 'PCI 6221 ENC ';
pt(14).paramname = 'P10';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';
pt(14).isStruct  = false;
pt(14).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221ENC_P10';
pt(14).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221ENC_P10';
pt(14).dtname     = 'real_T';



  
pt(15).blockname = 'PCI-6221 DA';
pt(15).paramname = 'P1';
pt(15).class     = 'vector';
pt(15).nrows     = 1;
pt(15).ncols     = 2;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';
pt(15).isStruct  = false;
pt(15).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P1';
pt(15).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P1[0]';
pt(15).dtname     = 'real_T';



  
pt(16).blockname = 'PCI-6221 DA';
pt(16).paramname = 'P2';
pt(16).class     = 'vector';
pt(16).nrows     = 1;
pt(16).ncols     = 2;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';
pt(16).isStruct  = false;
pt(16).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P2';
pt(16).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P2[0]';
pt(16).dtname     = 'real_T';



  
pt(17).blockname = 'PCI-6221 DA';
pt(17).paramname = 'P3';
pt(17).class     = 'vector';
pt(17).nrows     = 1;
pt(17).ncols     = 2;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';
pt(17).isStruct  = false;
pt(17).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P3';
pt(17).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P3[0]';
pt(17).dtname     = 'real_T';



  
pt(18).blockname = 'PCI-6221 DA';
pt(18).paramname = 'P4';
pt(18).class     = 'vector';
pt(18).nrows     = 1;
pt(18).ncols     = 2;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';
pt(18).isStruct  = false;
pt(18).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P4';
pt(18).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P4[0]';
pt(18).dtname     = 'real_T';



  
pt(19).blockname = 'PCI-6221 DA';
pt(19).paramname = 'P5';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';
pt(19).isStruct  = false;
pt(19).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P5';
pt(19).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P5';
pt(19).dtname     = 'real_T';



  
pt(20).blockname = 'PCI-6221 DA';
pt(20).paramname = 'P6';
pt(20).class     = 'scalar';
pt(20).nrows     = 1;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';
pt(20).isStruct  = false;
pt(20).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P6';
pt(20).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P6';
pt(20).dtname     = 'real_T';



  
pt(21).blockname = 'PCI-6221 DA';
pt(21).paramname = 'P7';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';
pt(21).isStruct  = false;
pt(21).symbol     = 'Control_Mov_PI_Digilent_P.PCI6221DA_P7';
pt(21).baseaddr   = '&Control_Mov_PI_Digilent_P.PCI6221DA_P7';
pt(21).dtname     = 'real_T';



  
pt(22).blockname = 'PI Controller/Integrator';
pt(22).paramname = 'InitialCondition';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';
pt(22).isStruct  = false;
pt(22).symbol     = 'Control_Mov_PI_Digilent_P.Integrator_IC';
pt(22).baseaddr   = '&Control_Mov_PI_Digilent_P.Integrator_IC';
pt(22).dtname     = 'real_T';


function len = getlenPT
len = 22;

