/*******************************************************************************
* File Name: rst.h  
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

#if !defined(CY_PINS_rst_ALIASES_H) /* Pins rst_ALIASES_H */
#define CY_PINS_rst_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define rst_0			(rst__0__PC)
#define rst_0_PS		(rst__0__PS)
#define rst_0_PC		(rst__0__PC)
#define rst_0_DR		(rst__0__DR)
#define rst_0_SHIFT	(rst__0__SHIFT)
#define rst_0_INTR	((uint16)((uint16)0x0003u << (rst__0__SHIFT*2u)))

#define rst_INTR_ALL	 ((uint16)(rst_0_INTR))


#endif /* End Pins rst_ALIASES_H */


/* [] END OF FILE */
