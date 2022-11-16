import serial
import time


##define the board
port='COM6'
Myboard=serial.Serial(port)
Myboard.baudrate=115200
print(Myboard)

while 1:
    print('Press 1 for record; Press 2 for replay')
    fun_sel=input()
    print(fun_sel)

##Record mode
    if fun_sel=='1':
        count=0
        while count<=100:
            board_output=Myboard.readline()
            print(board_output)
            board_output=str(board_output)[2:-5]+'\n'
            board_output=board_output.split(',')
            time.sleep(1/100)
            count=count+1
            print(count)
            logs=open('logs.txt',mode='a')
            logs.writelines(board_output)
            logs.close
            if count>100:
                print('Record finished')
                Myboard.close


##Replay mode
    elif fun_sel=='2':
        count=0
        while count<=100:
            logs=open('logs.txt',mode='r+')
            command=logs.readlines()
            ##print(command[count])
            if command[count]=='70e0300\n':
                print('70e0300')
                Myboard.write(bytearray('A','ascii'))
            elif command[count]=='300\n':
                print('300')
                Myboard.write(bytearray('B','ascii'))
            count=count+1
            time.sleep(1/2)
            if count>100:
                print('Replay finished')
                logs.close
                Myboard.close
    
    else:
        break
        







