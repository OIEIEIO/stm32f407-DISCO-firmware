#include "main.h"
#include "stm32f4xx.h"

// Delay function
void delay(uint32_t count) {
    while(count--) {}
}

int main(){

    // Configure LEDs
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable the clock of port D of the GPIO
    GPIOD->MODER |= GPIO_MODER_MODER12_0; // Green LED, set pin 12 as output
    GPIOD->MODER |= GPIO_MODER_MODER13_0; // Orange LED, set pin 13 as output
    GPIOD->MODER |= GPIO_MODER_MODER14_0; // Red LED, set pin 14 as output
    GPIOD->MODER |= GPIO_MODER_MODER15_0; // Blue LED, set pin 15 as output

    // Configure User Button
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable the clock for GPIOA
    GPIOA->MODER &= ~(GPIO_MODER_MODER0); // Set pin 0 as input (default after reset)

    uint8_t pattern = 0; // Start with the chasing pattern

    while(1){
        if(GPIOA->IDR & (1 << 0)) { // Check if user button is pressed
            delay(100000); // Simple debounce
            if(GPIOA->IDR & (1 << 0)) { // Check again to confirm button press
                pattern++;
                if (pattern > 3) {
                    pattern = 0;
                }
                while(GPIOA->IDR & (1 << 0)); // Wait for button release
            }
        }

        switch(pattern) {
            case 0:  // Chasing pattern
                GPIOD->BSRR = 1<<12;
                delay(500000);
                GPIOD->BSRR = 1<<(12+16);

                GPIOD->BSRR = 1<<13;
                delay(500000);
                GPIOD->BSRR = 1<<(13+16);

                GPIOD->BSRR = 1<<14;
                delay(500000);
                GPIOD->BSRR = 1<<(14+16);

                GPIOD->BSRR = 1<<15;
                delay(500000);
                GPIOD->BSRR = 1<<(15+16);

                delay(500000);
                break;

            case 1:  // All LEDs blinking pattern
                GPIOD->BSRR = 1<<12 | 1<<13 | 1<<14 | 1<<15; // All LEDs ON
                delay(500000);
                GPIOD->BSRR = 1<<(12+16) | 1<<(13+16) | 1<<(14+16) | 1<<(15+16); // All LEDs OFF
                delay(500000);
                break;

            case 2:  // LEDs light up one by one
                GPIOD->BSRR = 1<<12;  // Green LED ON
                delay(500000);
                GPIOD->BSRR = 1<<13;  // Orange LED ON
                delay(500000);
                GPIOD->BSRR = 1<<14;  // Red LED ON
                delay(500000);
                GPIOD->BSRR = 1<<15;  // Blue LED ON
                delay(500000);
                break;

            case 3:  // LEDs turn off one by one
                GPIOD->BSRR = 1<<(12+16);  // Green LED OFF
                delay(500000);
                GPIOD->BSRR = 1<<(13+16);  // Orange LED OFF
                delay(500000);
                GPIOD->BSRR = 1<<(14+16);  // Red LED OFF
                delay(500000);
                GPIOD->BSRR = 1<<(15+16);  // Blue LED OFF
                delay(500000);
                break;

            default:
                break;
        }
    }
}

