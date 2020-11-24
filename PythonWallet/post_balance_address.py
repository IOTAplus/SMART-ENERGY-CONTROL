'''
In this example we generate 1 address with a security level of 2 (default)
for a given seed. This is the first available, unused address for this seed.
'''

from iota import Iota
import pprint
import time
import json
import requests

# This is a demonstration seed, always generate your own seed!
my_seed = 'EDFCUGAMUKFUTSNERKXBVFTMRPGQRLFMYOHHSVCYDTZRJWULKHKRTGCEUMPD9NPFGWFTRTKLQSQRWZDMY'
# This is a demonstration url, put yours. It's the one for keepy it's the same for the TTGO / ESP32!
url = "http://192.168.1.200:3002/messages"
# This node should work but you can use your own or another one. Here you find more: https://thetangle.org/nodes 
node = 'https://nodes.thetangle.org:443'


api = Iota(
    adapter= node,
    seed = my_seed)

#print('\nThe balance for your seed:\n')
#pprint.pprint(api.get_account_data())

# We want the first address for this seed (index 0), make sure it hasn't been spent from before!
# Script actually runs until you load up your address
success = False
    # Gather addresses, balance and bundles

# response['balance'] is an integer!
while success == False:
    try:
        addresses = api.get_new_addresses(index=0, count=1, security_level=2, checksum=True)
        #this cointains the last unused and save address of your SEED.
        address = str(addresses['addresses'][0])
        print('\nLast unused address: %s' % address)
        response = api.get_balances(addresses=[address])
        #this contains the pure balance of your SEED as a string.
        balance= str(response["balances"]).replace("[","").replace("]","").replace("'","").replace("'","")
        print('Your balance:')
        pprint.pprint(balance)
        
#http post
        #This is the message which will be sent to keepy. The addres and the balance get filled in automatically
        message = {"iot2tangle":[{"sensor": "Wallet","data":[{"Address":address},{"Balance":balance}]}],"device": "Raspi-HTTP","timestamp": "1601653408"}
        print("Sending following to url: "+url)
        print(message)
        
        #this is the JSON response of the POST Request
        httpResponseCode = requests.post(url,json=message)
        pprint.pprint(httpResponseCode)
        
    except:
        #This happens when the programmed failed or the buttons "ctrl"+"c" where pushed.
        time.sleep(3) #If you push again the buttons "ctrl"+"c" you go out of the programm
        print("It did not worked. trying again.")

