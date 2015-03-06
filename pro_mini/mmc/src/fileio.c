#include "fileio.h"

int init_sd(void) {
	DSTATUS driveStatus;

	//printf("Attempting to launch sdcard...");

	driveStatus = 1;
	while (driveStatus != 0)
	{
		printf("\n\rAttempting to init sdcard...");
		driveStatus = disk_initialize(0);
		//printf("\n\rNever reached!");
		if((driveStatus & STA_NOINIT) ||   (driveStatus & STA_NODISK) ||   (driveStatus & STA_PROTECT)   )
		{
			printf(" error driveStatus %8b\n\r" ,driveStatus);
		}
		else
		{
			printf(" Drivestatus OK\n\r");
		}
	}
}