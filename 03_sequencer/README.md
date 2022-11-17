### TODO:

Create a 'sequencer' that allows you to record BOOT button presses and play them on the Neopixel, and also play a sequence of read/write commands. You should be able to:
- record at a least a few seconds of button input to your RP2040 (in RAM)
- replay a recorded sequence on your NeoPixel
- loop a recording
- save a recording to your laptop (the Python Serial library is one way to do this)
- play a recording from your laptop
- record 'macros' (a sequence of console commands) based on keystrokes in your serial console
- hand-edit a list of register read/write commands on your laptop, and play them on the RP2040
- include multiple I/O sources in a recording, and remap among the following:
    - inputs: BOOT button, console commands, register read/write commands
    - outputs: neopixel color, neopixel brightness, data over serial, register read/write commands










For the sequencer programming
We use pyserial library to communicate with the board. To record or replay, must use the python program to monitor the RP2040 behave.

The python program will ask user to select record mode or replay mode
If user select record mode, the python program will collect the register value information send from the RP2040(which is set in the RP2040 program), 
then the python program will print these information to a external txt file so that the record function is realized.

If user select replay mode, the python will read the record and send to the RP2040 through the serial port. The RP2040 will receive the message from PC
and write certain command into the register. In this way, we can successfully replay the command record
=======
### Result

<div align=center>
<img src="https://github.com/lihzhao14/ese5190_lab2B_part1-10/blob/main/03_sequencer/sequencer_demo.gif.gif" width="550">  
</div>

