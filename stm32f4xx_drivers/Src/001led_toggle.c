#include "stm32f401xx.h"
#include <stdint.h>
void delay()
{
    for(uint32_t i = 0; i < 500000; i++);
}

int main()
{
    GPIO_Handle_t GpioLed, GpioBtn;

    GpioLed.pGPIOx = GPIOA; // CHANGE WITH THE RIGHT PORT
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1; //CHANGE WITH THE RIGHT PIN
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioLed);

    GpioBtn.pGPIOx = GPIOD; // CHANGE WITH THE RIGHT PORT
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3; //CHANGE WITH THE RIGHT PIN
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioBtn);



    /*while(1)
    {
        if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_2)) //CHANGE WITH THE RIGHT PIN AND PORT
        {
            delay();
            GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_1); //CHANGE WITH THE RIGHT PIN AND PORT
        }
    }*/

    while(1)
    {
            GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_1); //CHANGE WITH THE RIGHT PIN AND PORT
    }
    

}
