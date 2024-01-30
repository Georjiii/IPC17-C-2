/*
 * @Author: IPC15-ÀîÌì¿­
 * @Date: 2023-11-1 20:55:18
 * @LastEditTime: 2023-11-1 20:55:18
 * @FilePath: \USER\main.c
 * @custom_steing_obkoro1:  Read only, do not modify place!!!
 */
#include "sys.h" //The <lwoopc.h> is already included here
#include "delay.h"
#include "usart.h"
//#include "usart2.h"	
#include "led.h"
#include "stdio.h"
#include "math.h"
#include "OLED.h"
#include "bee.h"  
#include "w25q128.h"
#include "HMC5883L.h"
#include "math.h"
#include "icm20602.h"
#include "bmi088.h"
#include "bmp280.h"
#include "clock.h"

extern uint8_t Second;
uint8_t Minute=0;
uint8_t Hour=0;


int main(void)
{  

	OLED_Init();
	TIM3_Init(10000,8400);
    while (1)
	{
		if(Second>=60)
		{
			Second=0;
			Minute++;
		
		}
		if(Minute>=60)
		{
			Minute=0;
			Hour++;
		}
		if(Hour>=24)
		{
		 Hour=0;
		 Second++;
		}
		OLED_ShowNum(4,1,Hour,2);
		OLED_ShowChar(4,3,':');
		OLED_ShowNum(4,4,Minute,2);
		OLED_ShowChar(4,6,':');
		OLED_ShowNum(4,7,Second,2);
	}
		
}

