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
 *  UART Clock Enable Macros
 */

#define USART1_CLKEN				(RCC -> APB2ENR |= (1<<4))
#define USART2_CLKEN				(RCC -> APB1ENR |= (1<<14))
#define USART6_CLKEN				(RCC -> APB2ENR |= (1<<5))

/*
 *  SYSCFG Clock Enable Macros
 */

#define SYSCFG_CLKEN				(RCC -> APB2ENR |= (1<<14))

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
	__vo uint32_t AFRL;				//GPIO alternate function low register			Address offset: 0x20
	__vo uint32_t AFRH;				//GPIO alternate function HHIGH register		Address offset: 0x24

}GPIO_RegDef_t;

/*
 *  Structure of RCC Peripheral Registers
 */

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	uint32_t	  RESERVED0[2];
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t	  RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	uint32_t	  RESERVED2[2];
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t	  RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	uint32_t	  RESERVED4[2];
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t	  RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t	  RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	uint32_t	  RESERVED7;
	__vo uint32_t DCKCFGR;
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
 *  Peripheral pointers for accessing Peripheral Registers
 */

GPIO_RegDef_t *pGPIOx = 	GPIO;
RCC_RegDef_t *pRCC =		RCC;
I2C1_RegDef_t *pI2C1 = 		I2C1;

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

#endif /* INC_STM32F401XX_H_ */