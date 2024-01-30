#include "clock.h"
#include "stdlib.h"

pClock pthis;
void Clock_Print(void);
void Clock_Add(void);

pClock Clock_Create(void){
	
	pClock clock_c = (pClock)malloc(sizeof(pClock));
	
	if(clock_c == NULL)
		
	return NULL;
	
	clock_c->Second = 0;
	clock_c->Minute = 0;
	clock_c->Hour = 0;
	
	clock_c->pClock_Add = Clock_Add;
	clock_c->pClock_Print = Clock_Print;
	
	pthis = clock_c;
	return clock_c;
	
	
}

pClock Clock_CreateWithArgs(uint8_t Second,uint8_t Minute,uint8_t Hour)
{
	pClock clock_c = Clock_Create();
	if(clock_c == NULL)
		
		return NULL;

	Count = Second;
	clock_c->Second = Second;
	clock_c->Minute = Minute;
	clock_c->Hour = Hour;
	
	return clock_c;

}

void Clock_Print(void)
{
	OLED_ShowNum(1,1,pthis->Hour,2);
	OLED_ShowString(1, 3, ":");
	OLED_ShowNum(1,4,pthis->Minute,2);
	OLED_ShowString(1, 6, ":");
	OLED_ShowNum(1,7,pthis->Second,2);

}

void Clock_Add(void)
{
	pthis->Second = Count;
	if(pthis->Second == 60)
	{
		pthis->Minute ++;
		pthis->Second =0;
		Count =0;
		
		if(pthis->Minute == 60)
		{
			pthis->Hour ++;
			pthis->Minute=0;
			
			if(pthis->Hour == 24)
			{
				pthis->Hour =0;
			}
	
}

}

}








