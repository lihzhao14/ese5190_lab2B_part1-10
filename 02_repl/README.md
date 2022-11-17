### TODO:

Create a REPL to let you read and write RP2040 registers from a console. You should be able to:
- select any 32-bit address to read/write (even if not a valid RP2020 address)
- read/write any 32-bit value to this address
- read/write using any of the atomic bit-setting aliases and a 32-bit mask


This is a program that user can input the address they want to read or write
First the user would select the mode they want to use,
If they want to read the value in a register, first press 1 to select read mode. 
Then input the address of register they want to read, then the program will return the value in that register.(sometimes it fail because the address does not exist )

If the user want to write certain value into the register.first press2 to select write mode.
Then input the address of register they want to write as read mode and input the value you want to write into the register,the program will alter the register value.

