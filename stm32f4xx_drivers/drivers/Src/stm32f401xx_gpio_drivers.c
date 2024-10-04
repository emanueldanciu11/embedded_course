/*
 * stm32f4xx_gpio_drivers.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Emi
 */


#include "stm32f401xx.h"
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
        	GPIOC_CLKDIS();
        }
        else if(pGPIOx == GPIOD)
        {
        	GPIOD_CLKDIS();
        }
        else if(pGPIOx == GPIOE)
        {
        	GPIOE_CLKDIS();
        }
        else if(pGPIOx == GPIOH)
        {
        	GPIOH_CLKDIS();
        }        
    }
}


/*
 * Init and reset
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
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0; //temp register
    //1.configure mode of gpio pin
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_ANALOG) 
    {
        //no interrupt mode
        temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << 2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        pGPIOHandle->pGPIOx->MODER |= temp;
        temp = 0;
    }else
    {
        //interrupt mode(will code later)
        if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
        {
            //1. configure the FTSR
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            //1. reset the RTSR
            EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        }else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
        {
            //1. configure the RTSR
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            //1. reset the FTSR
            EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        }else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FRT)
        {
            //1. configure both FTSR AND RTSR
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        }

        //2. configure the GPIO port selection in SYSCFG_EXTICR
        uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;      //select the register
        uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;      //select the bit position
        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
        SYSCFG->EXTICR[temp1] = portcode<<(temp2 * 4);                       //verifica daca varianta SYSCFG->EXTICR[temp1] |= portcode<<(temp2 * 4); este mai buna (|= in loc de =)
        SYSCFG_CLKEN();
        //.3 configure the exti interrupt delivery using IMR
        EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);     //this line allows the EXTI line to be delivered to the NVIC(WORKS AS A GATE BETWEEN THE EXtI AND THE NVIC, EACH BIT OF THE REGISTER CORESPONDS TO A EXTI LINE)

    }

    //2.configure speed of gpio pin
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << 2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;
    temp = 0;

    //3.configure pupd of gpio pin
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << 2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->PUPDR |= temp;
    temp = 0;

    //4.configure optype of gpio pin
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;
    temp = 0;

    //5.configure alt. func. mode of gpio pin  
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        //configure the alt. function register
        uint8_t  temp1=0, temp2=0;
        temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0XF << (4 * temp2));        
        pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));

    }
}
/*****************************************************************
 * @fn          - GPIO_Rst
 *
 * @brief       - This function resets the GPIO peripherals
 *
 * @param[in]   - Pointer to GPIO port
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

    void GPIO_Rst(GPIO_RegDef_t *pGPIOx)
    {
        if(pGPIOx == GPIOA)
        {
        	GPIOA_REG_RESET();
        }
        else if(pGPIOx == GPIOB)
        {
        	GPIOB_REG_RESET();
        }
        else if(pGPIOx == GPIOC)
        {
        	GPIOC_REG_RESET();
        }
        else if(pGPIOx == GPIOD)
        {
        	GPIOD_REG_RESET();
        }
        else if(pGPIOx == GPIOE)
        {
        	GPIOE_REG_RESET();
        }
        else if(pGPIOx == GPIOH)
        {
        	GPIOH_REG_RESET();
        }
    }
    
/*
 * Data read and write
 */

/*****************************************************************
 * @fn          - GPIO_ReadFromInputPin
 *
 * @brief       - This function reads and return the value of a specific pin
 *
 * @param[in]   - Pointer to GPIO port
 * 
 * @param[in]   - Variable that holds pin number
 *
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    uint8_t value;

    value = (uint8_t)((pGPIOx->IDR>>PinNumber) & 0x00000001);

    return value;
}

/*****************************************************************
 * @fn          - GPIO_ReadFromInputPort
 *
 * @brief       - This function reads and return the value of a specific port
 *
 * @param[in]   - Pointer to GPIO port
 *
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    uint16_t value;

    value = (uint16_t) (pGPIOx->IDR);

    return value;
}

/*****************************************************************
 * @fn          - GPIO_WriteToOutputPin
 *
 * @brief       - This function writes to output port register
 *
 * @param[in]   - Pointer to GPIO port
 *
 * @param[in]   - Pin number variable
 *
 * @param[in]   - Value to be written on the register bit field
 * 
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
    if(Value == GPIO_PIN_SET)
    {
        //write 1 to the coresponding bit field in the output data register
        pGPIOx->ODR |= 1<<PinNumber;
    }else
    {
        //write 0 to the coresponding bit field in the output data register
        pGPIOx->ODR &= ~(1<<PinNumber);
    }
}

/*****************************************************************
 * @fn          - GPIO_WriteToOutputPort
 *
 * @brief       - This function reads and return the value of a specific port
 *
 * @param[in]   - Pointer to GPIO port
 *
 * @param[in]   - Value to be wwritten on to the portr register
 * 
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
        pGPIOx->ODR = (uint16_t)Value;
}

/*****************************************************************
 * @fn          - GPIO_WriteToOutputPort
 *
 * @brief       - This function reads and return the value of a specific port
 *
 * @param[in]   - Pointer to GPIO port
 *
 * @param[in]   - Value to be wwritten on to the portr register
 * 
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1<<PinNumber);
}

/*
 * IRQ Configuration 
 */


void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi) //enable de interrupt line in ENVIC(IRQNumber coresponds to the pin number)
{
    if(EnorDi == ENABLE)
    {
        if(IRQNumber <= 31)
        {
            *NVIC_ISER0 |= (1 << IRQNumber);

        }else if ((IRQNumber > 31) && (IRQNumber < 64))
        {
            *NVIC_ISER1 |= (1 << (IRQNumber & 32));

        }else if((IRQNumber >= 64) && (IRQNumber < 96))
        {
            *NVIC_ISER2 |= (1 << (IRQNumber & 64));

        }
    }else
    {
        if(IRQNumber <= 31)
        {
            *NVIC_ICER0 |= (1 << IRQNumber);

        }else if ((IRQNumber > 31) && (IRQNumber < 64))
        {
            *NVIC_ICER1 |= (1 << (IRQNumber & 32));

        }else if((IRQNumber >= 64) && (IRQNumber < 96))
        {
            *NVIC_ICER2 |= (1 << (IRQNumber & 64));
            
        }
    }
       
}

/*****************************************************************
 * @fn          - GPIO_IRQPriorityConfig
 *
 * @brief       - Config priority of IRQ
 *
 * @param[in]   - Number of the IRQ
 * 
 * @param[in]   - IRQ Priority
 * 
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
    uint8_t iprx = IRQNumber / 4; // interrupt priority register number
    uint8_t iprx_section = IRQNumber % 4; // interrupt priority register bit section(4 sections each, 4 IRQ can be configured per register

    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);   //only 4 bits of the 8 bit section are used(0000XXXX-0000XXXX-0000XXX-0000XXXX)
    *(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift_amount);
}

/*****************************************************************
 * @fn          - GPIO_IRQHandling
 *
 * @brief       - IRQ handeling
 *
 * @param[in]   - Pin number
 * 
 * @return      - none
 *
 * @Note        - None
 *
 *****************************************************************/
void GPIO_IRQHandling(uint8_t PinNumber)
{
    //clear the exti pr register corresponding to the pin number
    if(EXTI->PR & (1<< PinNumber))
    {
        //clear
        EXTI->PR |= (1 << PinNumber);
    }
}