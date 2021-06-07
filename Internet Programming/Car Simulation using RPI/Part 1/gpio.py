#!/usr/bin/python
import requests #import JSONRequests library
import time #import time library for sleep function
import datetime #import datetime library for timestamp
import RPi.GPIO as GPIO #import GPIO library
GPIO.cleanup()
GPIO.setmode(GPIO.BCM) #set the pins according to BCM scheme
GPIO.setup(4,GPIO.OUT) #configure BCM Pin #4 as OUTPUT
GPIO.setup(17,GPIO.IN) #configure BCM Pin #17 as INPUT
GPIO.setup(18,GPIO.OUT) #configure BCM Pin #4 as OUTPUT
GPIO.setup(23,GPIO.IN)

i=0; n=30; delay=10  #limit number of tries to 5 (initially set it to 1 for debugging)
while i<n:
	LED1=GPIO.input(4) #read what BCM Pin #4 is set to (LED1)
	SW1=GPIO.input(17) #read the status of BCM Pin #17 (SW1)
        LED2=GPIO.input(18) #read what BCM Pin #4 is set to (LED2)
        SW2=GPIO.input(23) #read the status of BCM Pin #23 (SW2)

	data = {'username': 'JB', 'password': 'jbpass', 'SW1': SW1,'SW2':SW2, 'LED1': LED1,'LED2':LED2, 'SENDER': 'RPI' }
	res = requests.post("https://map3.hostingerapp.com/scripts/sync_data2.php", json=data)
#	print(res.text)
#in case of errors (especially, syntax) , you may want to print res.text and comment out the statements below
	r = res.json()
        print res.text
	ts = datetime.datetime.now() #get the time stamp
	print "==============Server Response at " + str(ts) + "=============="
	if r['success']==1:
		print "+++++Server request successful: "
		if LED1!=r['LED1']:
			print "Changing LED1 status as requested by the server"
			if r['LED1']==1:
				GPIO.output(4,GPIO.HIGH)
			else: GPIO.output(4,GPIO.LOW)
		if LED2!=r['LED2']:
                        print "Changing LED2 status as requested by the server"
			if r['LED2']==1:
                                GPIO.output(18,GPIO.HIGH)
                        else: GPIO.output(18,GPIO.LOW)

			print "The status of LED1 is " + str(r['LED1'])
			print "The status of SW1 is " + str(r['SW1'])
                        print "The status of LED2 is " + str(r['LED2'])
                        print "The status of SW2 is " + str(r['SW2'])

	else: print ">>>>> Server request failed - Error #" + str(r['error'])
	time.sleep(delay) #wait for delay seconds before sending another request
	i+=1
GPIO.cleanup()
