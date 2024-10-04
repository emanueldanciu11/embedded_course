#include "stm32f401xx.h"
#include <stdint.h>
#include <string.h>
void delay()
{
    for(uint32_t i = 0; i < 500000/2; i++);
}

int main()
{
    GPIO_Handle_t GpioLed, GpioBtn;
    memset(&GpioLed, 0, sizeof(GpioLed));
    memset(&GpioBtn, 0, sizeof(GpioBtn));

    GpioLed.pGPIOx = GPIOA; // CHANGE WITH THE RIGHT PORT
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1; //CHANGE WITH THE RIGHT PIN
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioLed);

    GpioBtn.pGPIOx = GPIOD; // CHANGE WITH THE RIGHT PORT
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13; //CHANGE WITH THE RIGHT PIN
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioBtn);

    GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_1,GPIO_PIN_RESET);

    GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRI15);
    GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

    while(1)
    {
        GpioBtn.pGPIOx->IDR |= 1 << GpioBtn.GPIO_PinConfig.GPIO_PinNumber;
        delay();
        GpioBtn.pGPIOx->IDR |= 1 << GpioBtn.GPIO_PinConfig.GPIO_PinNumber;
        delay();

    }

    return 0;
}

void EXTI15_10_IRQHandler(void)
{       
          //  delay();
        GPIO_IRQHandling(GPIO_PIN_NO_1);
        GPIO_ToggleOutputPin(GPIOD ,GPIO_PIN_NO_13);
}