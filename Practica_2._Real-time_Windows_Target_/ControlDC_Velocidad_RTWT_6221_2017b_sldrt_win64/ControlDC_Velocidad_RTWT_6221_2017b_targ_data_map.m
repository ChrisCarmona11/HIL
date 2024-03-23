  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ControlDC_Velocidad_RTWT_6221_2017b_P)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.T
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.PIDController_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Duty
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_DutyFinalValue
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_FinalValue
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Frequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.PIDController_I
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_InitialValue
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_InputFilter
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_MaxMissedTicks
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_MaxMissedTicks
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_MaxMissedTicks
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.PIDController_P
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_YieldWhenWaiting
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_YieldWhenWaiting
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_BitMode
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_Channels
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_Channels
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Channels
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DeadZone_Start
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.DeadZone_End
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.ConsignaVelocidad_Amplitude
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.ConsignaVelocidad_Frequency
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Normalizacion2_Gain
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.UnitDelay_InitialCondition
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Normalizacion1_Gain
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Integrator_IC
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Saturation_UpperSat
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Saturation_LowerSat
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Constant1_Value
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Constant_Value
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Constant3_Value
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.Constant2_Value
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ControlDC_Velocidad_RTWT_6221_2017b_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Normalizacion2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.EncoderInput_o1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.UnitDelay
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Sum
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.RateTransition1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Normalizacion1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Sum1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.DerivativeGain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Constant1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.ManualSwitch
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Constant3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Constant2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.Product2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.IntegralGain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_B.EncoderInput_o2
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ControlDC_Velocidad_RTWT_6221_2017b_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeA
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeB
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.Conrtol_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.ConsignaRPM_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.Control_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.Direction_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.Error1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.EstadosResta_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.DigitalOutput1_PWORK
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.FrequencyOutput1_PWORK
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.RPM_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.RPM3_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ControlDC_Velocidad_RTWT_6221_2017b_DW.Ticks_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1379066141;
  targMap.checksum1 = 1194921155;
  targMap.checksum2 = 3972692041;
  targMap.checksum3 = 3550116033;

