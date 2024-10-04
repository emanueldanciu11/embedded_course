/*
 * stm32f401xx.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Emi
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include <stdint.h>

#define __vo volatile

/***************************************************START:Processor specific details**********************************************
*
*ARM CORTEX M4 NVIC_ISERx Register Adresses
*/

#define NVIC_ISER0                  ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1                  ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2                  ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3                  ((__vo uint32_t*)0xE000E10C)      


/*
*ARM CORTEX M4 NVIC_ICERx Register Adresses
*/

#define NVIC_ICER0                  ((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1                  ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2                  ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3                  ((__vo uint32_t*)0xE000E18C)

/*
*ARM CORTEX M4 NVIC_ICERx Register Adresses
*/

#define NO_PR_BITS_IMPLEMENTED      4
#define NVIC_PR_BASE_ADDR           ((__vo uint32_t*)0xE000E400)

/***************************************************STOP:Processor specific details**********************************************/

/*
 *  Base Addresses of FLASH and ROM Memory
 */

#define FLASH_BASEADDR				0x08000000UL
#define SRAM1_BASEADDR				0x20000000UL
#define ROM_BASEADDR				0x1FFF0000UL
#define SRAM						SRAM1_BASEADDR

/*
 *  AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR				0x40000000UL
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR			0x40010000UL
#define AHB1PERIPH_BASEADDR			0x40020000UL
#define AHB2PERIPH_BASEADDR			0x05000000UL

/*
 *  Specific Peripheral Base Addresses Hanging on AHB1
 */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000UL)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400UL)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800UL)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00UL)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000UL)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00UL)
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0X3800UL)

/*
 *  Specific Peripheral Base Addresses Hanging on APB1
 */

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800UL)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00UL)

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400UL)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800UL)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00UL)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400UL)
#define USART3_BASEADDR				//DOESN'T EXIST

#define UART4_BASEADDR				//DOESN'T EXIST
#define UART5_BASEADDR				//DOESN'T EXIST

/*
 *  Specific Peripheral Base Addresses Hanging on APB2
 */

#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000UL)
#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000UL)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400UL)
#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00UL)
#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800UL)

/*
 *  Type Casted Peripheral Definition
 */

#define GPIO						((GPIO_RegDef_t*)APB1PERIPH_BASEADDR)
#define RCC							((RCC_RegDef_t*)RCC_BASEADDR)
#define I2C1						((I2C1_RegDef_t*)I2C1_BASEADDR)

#define GPIOA           			((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB           			((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC       			    ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD          				((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE           			((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOH           			((GPIO_RegDef_t*) GPIOH_BASEADDR)

#define EXTI                        ((EXTI_RegDef_t*) EXTI_BASEADDR)

#define SYSCFG                      ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 *  GPIO Clock Enable Macros
 */

#define GPIOA_CLKEN()				(RCC -> AHB1ENR |= (1<<0))
#define GPIOB_CLKEN()				(RCC -> AHB1ENR |= (1<<1))
#define GPIOC_CLKEN()				(RCC -> AHB1ENR |= (1<<2))
#define GPIOD_CLKEN()				(RCC -> AHB1ENR |= (1<<3))
#define GPIOE_CLKEN()				(RCC -> AHB1ENR |= (1<<4))
#define GPIOH_CLKEN()				(RCC -> AHB1ENR |= (1<<7))

/*
 *  GPIO Clock Reset Macros
 */

#define GPIOA_REG_RESET()			do{(RCC -> AHB1RSTR |= (1<<0));		(RCC -> AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()			do{(RCC -> AHB1RSTR |= (1<<1));		(RCC -> AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()			do{(RCC -> AHB1RSTR |= (1<<2));		(RCC -> AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()			do{(RCC -> AHB1RSTR |= (1<<3));		(RCC -> AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()			do{(RCC -> AHB1RSTR |= (1<<4));		(RCC -> AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOH_REG_RESET()			do{(RCC -> AHB1RSTR |= (1<<5));		(RCC -> AHB1RSTR &= ~(1<<5)); }while(0)

/*
 *  I2C Clock Enable Macros
 */

#define I2C1_CLKEN()				(RCC -> APB1ENR |= (1<<21))
#define I2C2_CLKEN()				(RCC -> APB1ENR |= (1<<22))
#define I2C3_CLKEN()				(RCC -> APB1ENR |= (1<<23))

/*
 *  SPI Clock Enable Macros
 */

#define SPI1_CLKEN()				(RCC -> APB2ENR |= (1<<12))
#define SPI2_CLKEN()				(RCC -> APB1ENR |= (1<<14))
#define SPI3_CLKEN()				(RCC -> APB1ENR |= (1<<15))

/*
 *  SPI Clock Enable Macros
 */

#define GPIO_BASEADDR_TO_CODE(x)   ((x == GPIOA) ? 0 :\
                                    (x == GPIOB) ? 1 :\
                                    (x == GPIOC) ? 2 :\
                                    (x == GPIOD) ? 3 :\
                                    (x == GPIOE) ? 4 :\
                                    (x == GPIOH) ? 5 :0)

/*
 *  UART Clock Enable Macros
 */

#define USART1_CLKEN()				(RCC -> APB2ENR |= (1<<4))
#define USART2_CLKEN()				(RCC -> APB1ENR |= (1<<14))
#define USART6_CLKEN()			    (RCC -> APB2ENR |= (1<<5))

/*
 *  SYSCFG Clock Enable Macros
 */

#define SYSCFG_CLKEN()				(RCC -> APB2ENR |= (1<<14))

/*
 *  GPIO Clock Disable Macros
 */

#define GPIOA_CLKDIS()				(RCC -> AHB1ENR &= ~(1<<0))
#define GPIOB_CLKDIS()				(RCC -> AHB1ENR &= ~(1<<1))
#define GPIOC_CLKDIS()				(RCC -> AHB1ENR &= ~(1<<2))
#define GPIOD_CLKDIS()				(RCC -> AHB1ENR &= ~(1<<3))
#define GPIOE_CLKDIS()				(RCC -> AHB1ENR &= ~(1<<4))
#define GPIOH_CLKDIS()				(RCC -> AHB1ENR &= ~(1<<7))

/*
 *  I2C Clock Disable Macros
 */

#define I2C1_CLKDIS()				(RCC -> APB1ENR &= ~(1<<21))
#define I2C2_CLKDIS()				(RCC -> APB1ENR &= ~(1<<22))
#define I2C3_CLKDIS()				(RCC -> APB1ENR &= ~(1<<23))

/*
 *  SPI Clock Disable Macros
 */

#define SPI1_CLKDIS()				(RCC -> APB2ENR &= ~(1<<12))
#define SPI2_CLKDIS()				(RCC -> APB1ENR &= ~(1<<14))
#define SPI3_CLKDIS()				(RCC -> APB1ENR &= ~(1<<15))

/*
 *  UART Clock Disable Macros
 */

#define USART1_CLKDIS()				(RCC -> APB2ENR &= ~(1<<4))
#define USART2_CLKDIS()				(RCC -> APB1ENR &= ~(1<<14))
#define USART6_CLKDIS()				(RCC -> APB2ENR &= ~(1<<5))
/*
 *  SYSCFG Clock Disable Macros
 */

#define SYSCFG_CLKDIS()				(RCC -> APB2ENR &= ~(1<<14))

/*
 *  Structure of GPIOx Peripheral Registers
 */

typedef struct
{
	__vo uint32_t MODER;			//GPIO port mode register						Address offset: 0x00
	__vo uint32_t OTYPER;			//GPIO port output type register				Address offset: 0x04
	__vo uint32_t OSPEEDR;			//GPIO port output speed register				Address offset: 0x08
	__vo uint32_t PUPDR;			//GPIO port pull-up/pull-down register			Address offset: 0x0C
	__vo uint32_t IDR;				//GPIO port input data register					Address offset: 0x10
	__vo uint32_t ODR;				//GPIO port output data register				Address offset: 0x14
	__vo uint32_t BSRR;				//GPIO port bit set/reset register				Address offset: 0x18
	__vo uint32_t LCKR;				//GPIO port configuration lock register			Address offset: 0x1C
	__vo uint32_t AFR[2];				//GPIO alternate function low register			Address offset: 0x20
}GPIO_RegDef_t;

/*
 *  Structure of RCC Peripheral Registers
 */

typedef struct
{
    __vo uint32_t CR;           /* RCC clock control register,                                  Address offset: 0x00    */
    __vo uint32_t PLLCFGR;      /* RCC PLL configuration register,                              Address offset: 0x04    */
    __vo uint32_t CFGR;         /* RCC clock configuration register,                            Address offset: 0x08    */
    __vo uint32_t CIR;          /* RCC clock interrupt register,                                Address offset: 0x0C    */
    __vo uint32_t AHB1RSTR;     /* RCC AHB1 peripheral reset register,                          Address offset: 0x10    */
    __vo uint32_t AHB2RSTR;     /* RCC AHB2 peripheral reset register,                          Address offset: 0x14    */
    __vo uint32_t AHB3RSTR;     /* RCC AHB3 peripheral reset register,                          Address offset: 0x18    */
    uint32_t      RESERVED0;    /* RCC reserved register,                                       Address offset: 0x1C    */
    __vo uint32_t APB1RSTR;     /* RCC APB1 peripheral reset register,                          Address offset: 0x20 	*/
    __vo uint32_t APB2RSTR;     /* RCC APB2 peripheral reset register,                          Address offset: 0x24    */
    uint32_t      RESERVED1[2]; /* RCC reserved register,                                       Address offset: 0x28-2C */
    __vo uint32_t AHB1ENR;      /* RCC AHB1 peripheral clock enable register,                   Address offset: 0x30    */
    __vo uint32_t AHB2ENR;      /* RCC AHB2 peripheral clock enable register,                   Address offset: 0x34    */
    __vo uint32_t AHB3ENR;      /* RCC AHB3 peripheral clock enable register,                   Address offset: 0x38    */
    uint32_t      RESERVED2;    /* RCC reserved register,                                       Address offset: 0x3C    */
    __vo uint32_t APB1ENR;      /* RCC APB1 peripheral clock enable register,                   Address offset: 0x40    */
    __vo uint32_t APB2ENR;      /* RCC APB2 peripheral clock enable register,                   Address offset: 0x44    */
    uint32_t      RESERVED3[2];	/* RCC reserved register,                                       Address offset: 0x48-4C */
    __vo uint32_t AHB1LPENR;    /* RCC AHB1 peripheral clock enable in low power mode register,	Address offset: 0x50    */
    __vo uint32_t AHB2LPENR;	/* RCC AHB2 peripheral clock enable in low power mode register,	Address offset: 0x54 	*/
    __vo uint32_t AHB3LPENR;	/* RCC AHB3 peripheral clock enable in low power mode register,	Address offset: 0x58 	*/
    uint32_t      RESERVED4;    /* RCC reserved register,                                       Address offset: 0x5C    */
    __vo uint32_t APB1LPENR;    /* RCC APB1 peripheral clock enable in low power mode register,	Address offset: 0x60    */
    __vo uint32_t APB2LPENR;    /* RCC APB2 peripheral clock enable in low power mode register,	Address offset: 0x64    */
    uint32_t      RESERVED5[2]; /* RCC reserved register,                                       Address offset: 0x68-6C */
    __vo uint32_t BDCR;         /* RCC back up domain control register,                         Address offset: 0x70    */
    __vo uint32_t CSR;          /* RCC clock control & status register,                         Address offset: 0x74    */
    uint32_t      RESERVED6[2]; /* RCC reserved register,                                       Address offset: 0x78-7C */
    __vo uint32_t SSCGR;        /* RCC spread spectrum clock generation register,               Address offset: 0x80    */
    __vo uint32_t PLLI2SCFGR;   /* RCC PLLI2S configuration register,                           Address offset: 0x84    */
    __vo uint32_t PLLSAICFGR;   /* RCC PLL configuration register,                              Address offset: 0x88    */
    __vo uint32_t DCKCFGR;      /* RCC dedicated clock configuration register,                  Address offset: 0x8C    */
    __vo uint32_t CKGATENR;     /* RCC clock gated enable register,                             Address offset: 0x90    */
    __vo uint32_t DCKCFGR2;     /* RCC dedicated clock configuration register 2,                Address offset: 0x94    */
}RCC_RegDef_t;

/*
 *  Structure of I2C Peripheral Registers
 */

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
}I2C1_RegDef_t;

/*
 *  Structure of EXTI Peripheral Registers
 */

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;

/*
 *  Structure of SYSCONFIG register
 */

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;
	__vo uint32_t RESERVED2[2];
    __vo uint32_t CFGR;
}SYSCFG_RegDef_t;

/*
 *  Peripheral pointers for accessing Peripheral Registers
 */

/*extern GPIO_RegDef_t *pGPIOx;
extern RCC_RegDef_t *pRCC;
extern I2C1_RegDef_t *pI2C1;*/

/*
 * Interrupt request numbers for F4xx family microcontriller
 */

#define IRQ_NO_EXTI0                6
#define IRQ_NO_EXTI1                7
#define IRQ_NO_EXTI2                8
#define IRQ_NO_EXTI3                9
#define IRQ_NO_EXTI4                10
#define IRQ_NO_EXTI9_5              23
#define IRQ_NO_EXTI15_10            40

/*
 * Generic Macros
 */

#define NVIC_IRQ_PRI0               0
#define NVIC_IRQ_PRI1               1
#define NVIC_IRQ_PRI2               2
#define NVIC_IRQ_PRI3               3
#define NVIC_IRQ_PRI4               4
#define NVIC_IRQ_PRI5               5
#define NVIC_IRQ_PRI6               6
#define NVIC_IRQ_PRI7               7
#define NVIC_IRQ_PRI8               8
#define NVIC_IRQ_PRI9               9
#define NVIC_IRQ_PRI15              15



/*
 * Generic Macros
 */

#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET
#define FLAG_SET        SET
#define FLAG_RESET      RESET

#include "stm32f401xx_gpio_drivers.h"

#endif /* INC_STM32F401XX_H_ */
