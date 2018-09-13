/*******************************************************************************
* File Name: ring.c  
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
#include "ring.h"

static ring_BACKUP_STRUCT  ring_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: ring_Sleep
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
*  \snippet ring_SUT.c usage_ring_Sleep_Wakeup
*******************************************************************************/
void ring_Sleep(void)
{
    #if defined(ring__PC)
        ring_backup.pcState = ring_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            ring_backup.usbState = ring_CR1_REG;
            ring_USB_POWER_REG |= ring_USBIO_ENTER_SLEEP;
            ring_CR1_REG &= ring_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ring__SIO)
        ring_backup.sioState = ring_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        ring_SIO_REG &= (uint32)(~ring_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: ring_Wakeup
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
*  Refer to ring_Sleep() for an example usage.
*******************************************************************************/
void ring_Wakeup(void)
{
    #if defined(ring__PC)
        ring_PC = ring_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            ring_USB_POWER_REG &= ring_USBIO_EXIT_SLEEP_PH1;
            ring_CR1_REG = ring_backup.usbState;
            ring_USB_POWER_REG &= ring_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ring__SIO)
        ring_SIO_REG = ring_backup.sioState;
    #endif
}


/* [] END OF FILE */
