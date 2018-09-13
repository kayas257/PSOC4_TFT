/*******************************************************************************
* File Name: ring.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ring_H) /* Pins ring_H */
#define CY_PINS_ring_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ring_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} ring_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ring_Read(void);
void    ring_Write(uint8 value);
uint8   ring_ReadDataReg(void);
#if defined(ring__PC) || (CY_PSOC4_4200L) 
    void    ring_SetDriveMode(uint8 mode);
#endif
void    ring_SetInterruptMode(uint16 position, uint16 mode);
uint8   ring_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ring_Sleep(void); 
void ring_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ring__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ring_DRIVE_MODE_BITS        (3)
    #define ring_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ring_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ring_SetDriveMode() function.
         *  @{
         */
        #define ring_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ring_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ring_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ring_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ring_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ring_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ring_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ring_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ring_MASK               ring__MASK
#define ring_SHIFT              ring__SHIFT
#define ring_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ring_SetInterruptMode() function.
     *  @{
     */
        #define ring_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ring_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ring_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ring_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ring__SIO)
    #define ring_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ring__PC) && (CY_PSOC4_4200L)
    #define ring_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ring_USBIO_DISABLE              ((uint32)(~ring_USBIO_ENABLE))
    #define ring_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ring_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ring_USBIO_ENTER_SLEEP          ((uint32)((1u << ring_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ring_USBIO_SUSPEND_DEL_SHIFT)))
    #define ring_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ring_USBIO_SUSPEND_SHIFT)))
    #define ring_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ring_USBIO_SUSPEND_DEL_SHIFT)))
    #define ring_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ring__PC)
    /* Port Configuration */
    #define ring_PC                 (* (reg32 *) ring__PC)
#endif
/* Pin State */
#define ring_PS                     (* (reg32 *) ring__PS)
/* Data Register */
#define ring_DR                     (* (reg32 *) ring__DR)
/* Input Buffer Disable Override */
#define ring_INP_DIS                (* (reg32 *) ring__PC2)

/* Interrupt configuration Registers */
#define ring_INTCFG                 (* (reg32 *) ring__INTCFG)
#define ring_INTSTAT                (* (reg32 *) ring__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ring_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ring__SIO)
    #define ring_SIO_REG            (* (reg32 *) ring__SIO)
#endif /* (ring__SIO_CFG) */

/* USBIO registers */
#if !defined(ring__PC) && (CY_PSOC4_4200L)
    #define ring_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ring_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ring_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ring_DRIVE_MODE_SHIFT       (0x00u)
#define ring_DRIVE_MODE_MASK        (0x07u << ring_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ring_H */


/* [] END OF FILE */
