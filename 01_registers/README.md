### TODO:

Toggle the Qt Py's Neopixel LED when the BOOT button is pressed, using only direct register reads to access the boot button status. You may use the SDK to initialize the board and the pins, and the WS2812 example code to toggle the Neopixel. 


To use the direct register read, first we need to find the address of register we need to control.
Refer to the schemetic, notice that the BOOT button is related to GPIO21, so next step is to look up the datasheet to find the address of register of GPIO21. the result is that the address of GPIO21_STATUS IS 0x400140a8. Then we can read the register value and control the RP2040 through direct register reads.
=======

### Result

After click the boot button, the color of LED has changed.

<div align=center>
<img src="https://github.com/lihzhao14/ese5190_lab2B_part1-10/blob/main/01_registers/image/1.gif" width="450">  
</div>
