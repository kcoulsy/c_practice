#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// This is a very basic fake GPIO where we are causing an LED to blink
// the purpose is to practice bitwise operations

// the register - each bit is a pin
uint8_t GPIO = 0;

// pretending there is an LED connected to pin 3
#define LED_PIN 3

void gpio_set(uint8_t pin) {
    GPIO |= (1 << pin);
}

void gpio_unset(uint8_t pin) {
    GPIO &= ~(1 << pin);
}

int gpio_read(uint8_t pin) {
    return (GPIO & (1 << pin)) != 0;
}

void print_pins() {
    system("cls");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (GPIO >> i) & 1);
    }
    printf("\n");
}

void delay(void) {
    // hacky sleep
    for (volatile int i = 0; i < 100000000; i++);
}

int main(void) {
    while (1) {
        gpio_set(LED_PIN);     // LED ON
        print_pins();
        delay();

        gpio_unset(LED_PIN);   // LED OFF
        print_pins();
        delay();
    }
    return 0;
}
