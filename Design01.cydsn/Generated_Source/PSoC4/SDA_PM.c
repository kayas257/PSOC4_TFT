/*******************************************************************************
* File Name: SDA.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SDA.h"

static SDA_BACKUP_STRUCT  SDA_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SDA_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet SDA_SUT.c usage_SDA_Sleep_Wakeup
*******************************************************************************/
void SDA_Sleep(void)
{
    #if defined(SDA__PC)
        SDA_backup.pcState = SDA_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SDA_backup.usbState = SDA_CR1_REG;
            SDA_USB_POWER_REG |= SDA_USBIO_ENTER_SLEEP;
            SDA_CR1_REG &= SDA_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SDA__SIO)
        SDA_backup.sioState = SDA_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SDA_SIO_REG &= (uint32)(~SDA_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SDA_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to SDA_Sleep() for an example usage.
*******************************************************************************/
void SDA_Wakeup(void)
{
    #if defined(SDA__PC)
        SDA_PC = SDA_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SDA_USB_POWER_REG &= SDA_USBIO_EXIT_SLEEP_PH1;
            SDA_CR1_REG = SDA_backup.usbState;
            SDA_USB_POWER_REG &= SDA_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SDA__SIO)
        SDA_SIO_REG = SDA_backup.sioState;
    #endif
}


/* [] END OF FILE */
