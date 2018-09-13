/*******************************************************************************
* File Name: SDA.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SDA_ALIASES_H) /* Pins SDA_ALIASES_H */
#define CY_PINS_SDA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SDA_0			(SDA__0__PC)
#define SDA_0_PS		(SDA__0__PS)
#define SDA_0_PC		(SDA__0__PC)
#define SDA_0_DR		(SDA__0__DR)
#define SDA_0_SHIFT	(SDA__0__SHIFT)
#define SDA_0_INTR	((uint16)((uint16)0x0003u << (SDA__0__SHIFT*2u)))

#define SDA_INTR_ALL	 ((uint16)(SDA_0_INTR))


#endif /* End Pins SDA_ALIASES_H */


/* [] END OF FILE */
