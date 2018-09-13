/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include "TFT.h"
#include <stdio.h>  

extern uint16_t MAX_X, MAX_Y ; 
#define SYSTICK_EACH_10_HZ (10u)
#define SYSTICK_RELOAD (CYDEV_BCLK__SYSCLK__HZ / SYSTICK_EACH_10_HZ)
CY_ISR_PROTO(SysTickIsrHandler);
int main(void)
{ 
    int i,j;
    char timeBuffer[16u];
   PWM_Start();
    
uint32_t min=0;
uint32_t hr=0;
uint32_t tim1;
 SPIM_Start();
 TFT_Init(1);
 TFT_ClearScreen();
RTC_Start ();
    RTC_SetPeriod(1u,SYSTICK_EACH_10_HZ);
         CySysTickStart();
    /*config Systick Timer to Generate interruos every 100ms*/
   CySysTickSetReload(SYSTICK_RELOAD);
   for (i=0u; i <CY_SYS_SYST_NUM_OF_CALLBACKS; ++i)
    {
        if (CySysTickGetCallback(i) == NULL)
        {
  
            CySysTickSetCallback(i,SysTickIsrHandler);
            break;
        }
     } 
    CyGlobalIntEnable;
    ring_Write(0);
    TFT_FillRectangle(0,  0,   127,   157, BLUE2);
    for(;;)
    { 
        
        tim1=RTC_GetTime ();
       
      // landscape with connector on left
   // TFT_FillScreen(0, MAX_X, 0, MAX_Y, BLACK);	
    //     DrawStringBl(char *string,uint16_t poX, uint16_t poY, uint16_t size,uint16_t fgcolor,uint16_t bgcolor);
    //DrawStringBl("TFT Testing...",  15, 50, 2, RED, GREEN);
 TFT_FillRectangle(5, 100, 20, 50, 0x0000);
 sprintf(timeBuffer,"%02u:%02u:%02u",RTC_GetHours(tim1),RTC_GetMinutes(tim1),RTC_GetSecond(tim1));
//    CyDelay(5000);
if(min!=RTC_GetMinutes(tim1)){
min=RTC_GetMinutes(tim1);
 TFT_FillRectangle(5, 50, 20, 50, 0x0000);
}

if(hr!=RTC_GetHours(tim1)){
hr=RTC_GetHours(tim1);
 TFT_FillRectangle(5, 30, 20, 40, 0x0000);
for(j=0;j<hr;j++)
{
ring_Write(~ring_Read());
CyDelay(100);
}
}
    //  FillRectangle(X, Y, length, width, color);
    //TFT_FillRectangle(0,  0,   20,    20, BLUE2);
 DrawString(timeBuffer,  5, 30, 2, BLUE2);
    //  DrawString(char *string, poX, poY, size,    fgcolor);
   // TFT_DrawString (Text,          5,   1,    1,    WHITE);
 ring_Write(0);
CyDelay(900);
    }
    
}
void SysTickIsrHandler(void)
{
    RTC_Update();
}
/* [] END OF FILE */
