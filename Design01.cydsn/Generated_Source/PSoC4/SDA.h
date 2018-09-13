/*******************************************************************************
* File Name: SDA.h  
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

#if !defined(CY_PINS_SDA_H) /* Pins SDA_H */
#define CY_PINS_SDA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SDA_aliases.h"


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
} SDA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SDA_Read(void);
void    SDA_Write(uint8 value);
uint8   SDA_ReadDataReg(void);
#if defined(SDA__PC) || (CY_PSOC4_4200L) 
    void    SDA_SetDriveMode(uint8 mode);
#endif
void    SDA_SetInterruptMode(uint16 position, uint16 mode);
uint8   SDA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SDA_Sleep(void); 
void SDA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SDA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SDA_DRIVE_MODE_BITS        (3)
    #define SDA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SDA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SDA_SetDriveMode() function.
         *  @{
         */
        #define SDA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SDA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SDA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SDA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SDA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SDA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SDA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SDA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SDA_MASK               SDA__MASK
#define SDA_SHIFT              SDA__SHIFT
#define SDA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SDA_SetInterruptMode() function.
     *  @{
     */
        #define SDA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SDA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SDA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SDA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SDA__SIO)
    #define SDA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SDA__PC) && (CY_PSOC4_4200L)
    #define SDA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SDA_USBIO_DISABLE              ((uint32)(~SDA_USBIO_ENABLE))
    #define SDA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SDA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SDA_USBIO_ENTER_SLEEP          ((uint32)((1u << SDA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SDA_USBIO_SUSPEND_DEL_SHIFT)))
    #define SDA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SDA_USBIO_SUSPEND_SHIFT)))
    #define SDA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SDA_USBIO_SUSPEND_DEL_SHIFT)))
    #define SDA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SDA__PC)
    /* Port Configuration */
    #define SDA_PC                 (* (reg32 *) SDA__PC)
#endif
/* Pin State */
#define SDA_PS                     (* (reg32 *) SDA__PS)
/* Data Register */
#define SDA_DR                     (* (reg32 *) SDA__DR)
/* Input Buffer Disable Override */
#define SDA_INP_DIS                (* (reg32 *) SDA__PC2)

/* Interrupt configuration Registers */
#define SDA_INTCFG                 (* (reg32 *) SDA__INTCFG)
#define SDA_INTSTAT                (* (reg32 *) SDA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SDA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SDA__SIO)
    #define SDA_SIO_REG            (* (reg32 *) SDA__SIO)
#endif /* (SDA__SIO_CFG) */

/* USBIO registers */
#if !defined(SDA__PC) && (CY_PSOC4_4200L)
    #define SDA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SDA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SDA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SDA_DRIVE_MODE_SHIFT       (0x00u)
#define SDA_DRIVE_MODE_MASK        (0x07u << SDA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SDA_H */


/* [] END OF FILE */
