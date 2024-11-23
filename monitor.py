import serial

# Replace 'COM3' with the appropriate port name and 9600 with the baud rate
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) 

while True:
    # Read a line of data from the serial port
    line = ser.readline().decode('utf-8').strip()
    if line:
        print(line)