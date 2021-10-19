import serial
import time

Arduino_Serial = serial.Serial('COM7', 9600)
Arduino_Serial.readline()
Arduino_Serial.timeout = 1
print("input 1 to 0")


Arduino_Serial.write('x'.encode())


while True:  # infinite loop


    input_data = input()
    print ("you entered", input_data)

# LED ON
    if (input_data == '1'):
        Arduino_Serial.write("1".encode())
        print("LED On")

# LED OFF
    if (input_data == '2'):
        Arduino_Serial.write('2'.encode())
        print("LED Off")

# DOOR OPEN
    if (input_data == '3'):
        Arduino_Serial.write('3'.encode())
        print("LED On")
        time.sleep(2)
        Arduino_Serial.write('4'.encode())

# DOOR CLOSE
    if (input_data == '4'):
        Arduino_Serial.write('5'.encode())
        print("LED On")
        time.sleep(1)
        Arduino_Serial.write('6'.encode())

# LED INTENSITY level-1
    if (input_data == '7'):
        Arduino_Serial.write('7'.encode())
        print("LED duty")

# LED INTENSITY level-2

    if (input_data == '8'): #level-2
        Arduino_Serial.write('8'.encode())
        print("LED duty")

# LED INTENSITY level-3

    if (input_data == '9'): #level-3
        Arduino_Serial.write('9'.encode())
        print("LED duty")

# FOR MOTION SENSOR
    if (input_data == '0'): #level-3
        while True:
            Arduino_Serial.write('0'.encode())
            time.sleep(0.5)
            print(Arduino_Serial.readline().decode('ascii'))

# FOR GUN
    if (input_data == 'A'):
        Arduino_Serial.write('3'.encode())
        print("LED On")
        time.sleep(2)
        Arduino_Serial.write('4'.encode())
