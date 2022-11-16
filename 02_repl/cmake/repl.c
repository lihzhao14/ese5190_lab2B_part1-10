#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "boards/adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150


#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

typedef          uint32_t   VALUE;
typedef volatile uint32_t * ADDRESS;

VALUE register_read(ADDRESS address) {
    return *address;
}

void register_write(ADDRESS address, VALUE value) {
    *address = value;
}


int fun_sel; 
long int target_address;
long int value;
VALUE address_value;


int main() {

    stdio_init_all();
    while (!stdio_usb_connected()) {
      printf(".");
      sleep_ms(500);
    }
    printf("\nNow let's read and write freely\n");
    while(1){
    printf("Press 1 to read the value in the address, Press 2 to write the value into the address\n");
    scanf(" %x",fun_sel);

    if (fun_sel==1)
    {
        printf("You have selected to read the value, please enter the address you want to read\n");
        scanf(" %x",target_address);
        address_value=register_read((ADDRESS)target_address);
        printf("The value in the address is 0x%x\n",address_value);
    }
    else if (fun_sel==2)
    {
        printf("You have selected to write the value, please enter the address you want to write\n");
        scanf(" %x",target_address);
        printf("Please enter the value you want to write\n");
        scanf(" %x",address_value);
        register_write((ADDRESS)address_value,(VALUE)value);
    }
    }
}