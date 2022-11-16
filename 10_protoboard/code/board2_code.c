#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "boards/adafruit_qtpy_rp2040.h"

const uint Out_A0=29;
    gpio_init(Out_A0);
    gpio_set_dir(Out_A0,GPIO_OUT);
    gpio_put(Out_A0,0);

    //GPIO in test
    const uint Out_A1=28;
    gpio_init(Out_A1);
    gpio_set_dir(Out_A1,GPIO_OUT);
    gpio_put(Out_A1,0);
    
    while(1){
        scanf("%d",&input_num);

        if (input_num==1)
        {
            gpio_put(Out_A0,1);
            gpio_put(Out_A1,1);
            printf("led on\n");
            sleep_ms(800);
        }
        else if (input_num==0)
        {
            gpio_put(Out_A0,0);
            gpio_put(Out_A1,0);
            printf("led off\n");
            sleep_ms(800);
        }
        input_num=0;