/*
 * stm32f4xx_gpio_drivers.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Emi
 */


#include "stm32f401xx_gpio_drivers.h"

/*
 * Peripheral Clock setup
 */

/*****************************************************************
 * @fn          - GPIO_PeriClockControl
 *
 * @brief       - This function enables or disables peripheral
 *                clock for the given GPIO port
 *
 * @param[in]   - Base address of the GPIO peripheral
 * @param[in]   - Macros: Enable or Disable
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == GPIOA)
        {
        	GPIOA_CLKEN();
        }
        else if(pGPIOx == GPIOB)
        {
        	GPIOB_CLKEN();
        }
        else if(pGPIOx == GPIOC)
        {
        	GPIOC_CLKEN();
        }
        else if(pGPIOx == GPIOD)
        {
        	GPIOD_CLKEN();
        }
        else if(pGPIOx == GPIOE)
        {
        	GPIOE_CLKEN();
        }
        else if(pGPIOx == GPIOH)
        {
        	GPIOH_CLKEN();
        }
    }
    else
    {
        if(pGPIOx == GPIOA)
        {
        	GPIOA_CLKDIS();
        }
        else if(pGPIOx == GPIOB)
        {
        	GPIOB_CLKDIS();
        }
        else if(pGPIOx == GPIOC)
        {
        	GPIOD_CLKDIS();
        }
        else if(pGPIOx == GPIOD)
        {
        	GPIOE_CLKDIS();
        }
        else if(pGPIOx == GPIOE)
        {
        	GPIOH_CLKDIS();
        }
    }
}


/*
 * Init and De-Init
 */

/*****************************************************************
 * @fn          - GPIO_Init
 *
 * @brief       - This function initialize GPIO peripherals
 *
 * @param[in]   - Pointer to GPIO Handle structure
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
