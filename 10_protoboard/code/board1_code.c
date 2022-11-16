/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "boards/adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150

int input_A0; 
int input_A1; 
int A1_state;

int main() {
    //set_sys_clock_48();
    stdio_init_all();
    // printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    //set the power pin of ws2812 to on
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
        //A0 pin
        printf("Please enter the value of pin A0\n");
        scanf("%d",&input_A0);
        printf("Input A0 is %d\n",input_A0);
        sleep_ms(800);
        if (input_A0==1)
        {
            gpio_put(Out_A0,1);
            printf("led A0 on\n");
            sleep_ms(800);
        }
        else if (input_A0==0)
        {
            gpio_put(Out_A0,0);
            printf("led A0 off\n");
            sleep_ms(800);
        }
        input_A0=0;

        //A1 pin
        printf("Please enter the value of pin A1\n");
        scanf("%d",&input_A1);
        printf("Input A1 is %d\n",input_A1);
        sleep_ms(800);
        if (input_A1==1)
        {
            gpio_put(Out_A1,1);
            printf("led A1 on\n");
            sleep_ms(800);
        }
        else if (input_A1==0)
        {
            gpio_put(Out_A1,0);
            printf("led A1 off\n");
            sleep_ms(800);
        }
        input_A1=0;


        
    }

}
    

    
