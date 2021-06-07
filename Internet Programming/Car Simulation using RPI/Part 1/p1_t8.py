import requests 
import import datetime
LED1=1
SW1=1
ts=datetime.datetime.now()
print "Sending the following to the server at " + str(ts) 
print "Set LED1 to " + str(LED1)
data = {'username': 'ben', 'password': 'thatpass', 'LED1':LED1, 'SW1':SW1}
res = requests.post("https://yourdomain.000webhostapp.com/scripts/sync_app_data.php", json=data)
r = res.json()
ts = datetime.datetime.now() 
print "==============Server Response at " + str(ts) + "=============="
if r['success']==1:
print "+++++Server request successful: "
		 print "The status of LED1 is " + str(r['LED1'])
		 print "The status of SW1 is " + str(r['SW1'])
else: print ">>>>> Server request failed - Error #" + str(r['error'])
