import serial

# 设置串口参数，根据你的Arduino配置进行更改
ser = serial.Serial('/dev/ttyUSB0', 9600)  # 串口设备和波特率
# 发送数据到Arduino
data_to_send = "Hello, Arduino!\n"  # 要发送的数据，确保以换行符结尾
ser.write(data_to_send.encode())  # 将数据编码并发送
ser.close()


ser = serial.Serial('/dev/ttyUSB0', 9600)  # 串口设备和波特率
s = ser.readline()
print(s)
# 关闭串口连接
ser.close()
