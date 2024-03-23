#include "slrtappmapping.h"
#include "./maps/Control_Mov_PI_Digilent.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <Control_Mov_PI_Digilent> */
		{ /* SignalMapInfo */
			Control_Mov_PI_Digilent_BIOMAP,
			Control_Mov_PI_Digilent_LBLMAP,
			Control_Mov_PI_Digilent_SIDMAP,
			Control_Mov_PI_Digilent_SBIO,
			Control_Mov_PI_Digilent_SLBL,
			{0,10},
			11,
		},
		{ /* ParamMapInfo */
			Control_Mov_PI_Digilent_PTIDSMAP,
			Control_Mov_PI_Digilent_PTNAMESMAP,
			Control_Mov_PI_Digilent_SPTMAP,
			{0,21},
			22,
		},
		"Control_Mov_PI_Digilent",
		"",
		"Control_Mov_PI_Digilent",
		1,
		Control_Mov_PI_Digilent_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}