#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include "neopixel.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "ws2812.pio.h"
#include "boards/adafruit_qtpy_rp2040.h"

#define QTPY_BOOT_PIN 21


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

void set_neopixel_color(uint32_t color);
static inline void put_pixel(uint32_t pixel_grb);
void set_neopixel_color(uint32_t color)
{
 uint32_t r= color&(uint32_t)0x00ff0000;
 uint32_t g= color&(uint32_t)0x0000ff00;
 uint32_t b= color&(uint32_t)0x000000ff;
 put_pixel(r |g|b);
}

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}


int Boot_button; 

int main() {
    //set_sys_clock_48();
    stdio_init_all();

    //set the power pin of ws2812 to on
    const uint WS2812_POWER_PIN=PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(WS2812_POWER_PIN);
    gpio_set_dir(WS2812_POWER_PIN,GPIO_OUT);
    gpio_put(WS2812_POWER_PIN,1);

    const uint Boot_button=21;
    gpio_init(Boot_button);
    gpio_set_dir(Boot_button,GPIO_OUT);
    gpio_put(Boot_button,1);

    gpio_set_dir(Boot_button,GPIO_IN);

    //todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    //int make_play=0; 
    VALUE GPIO21_state;
    ADDRESS GPIO21_ADDRESS=0x400140a8;
    while (1) {

        GPIO21_state=register_read(GPIO21_ADDRESS); 

        if ( GPIO21_state==0x70e0300)
        {
            set_neopixel_color(0x33ff99);
            printf("The state of GPIO21 is 0x%x\n",GPIO21_state);
            sleep_ms(200);
        }
        else if(GPIO21_state==0x300)
        {
            set_neopixel_color(0xff3399);
            printf("The state of GPIO21 is 0x%x\n",GPIO21_state);
            sleep_ms(200);
        }
    
        }    
    }
    
