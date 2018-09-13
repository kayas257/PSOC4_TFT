/*******************************************************************************
* File Name: ring.h  
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

#if !defined(CY_PINS_ring_ALIASES_H) /* Pins ring_ALIASES_H */
#define CY_PINS_ring_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ring_0			(ring__0__PC)
#define ring_0_PS		(ring__0__PS)
#define ring_0_PC		(ring__0__PC)
#define ring_0_DR		(ring__0__DR)
#define ring_0_SHIFT	(ring__0__SHIFT)
#define ring_0_INTR	((uint16)((uint16)0x0003u << (ring__0__SHIFT*2u)))

#define ring_INTR_ALL	 ((uint16)(ring_0_INTR))


#endif /* End Pins ring_ALIASES_H */


/* [] END OF FILE */
