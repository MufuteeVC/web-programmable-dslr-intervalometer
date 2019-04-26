from flask import Flask, render_template, request
import RPi.GPIO as GPIO
from time import sleep, time
import os
from twilio.rest import Client
account_sid = "AC9b921e839c2469747669730140b6c153"
auth_token = "638ee7ef6468cd476a6039fa0fb1416d"

client = Client(account_sid, auth_token)

from threading import Thread, Lock

TRIGGER_DURATION = 1 # seconds

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)
app = Flask(__name__)

config_mutex = Lock()
trigger_mutex = Lock()

trigger_config = {
        "state": False,
        "interval_s": 5, # seconds
        "duration_s": 60, # seconds
        "last_start_s": 0
        }

@app.route('/')
def main():
    return render_template('main.html', **trigger_config)

@app.route('/send', methods = ['GET','POST'])
def submit():
    if request.method == "POST":
        interval_seconds = int(request.form['interval'])
        duration_seconds = int(request.form['duration'])

        config_mutex.acquire()
        trigger_config["interval_s"] = interval_seconds
        trigger_config["duration_s"] = duration_seconds
        trigger_config["state"] = False
        config_mutex.release()
        
    return render_template('main.html', **trigger_config)

@app.route('/toggle', methods = ['GET'])
def toggle_state():
    config_mutex.acquire()
    old_state = trigger_config["state"]
    trigger_config["state"] = not old_state
    if(trigger_config["state"] == True):
        trigger_config["last_start_s"] = time()
    config_mutex.release()

    return render_template('main.html', **trigger_config)

@app.route('/trigger', methods = ['GET'])
def trigger():
    trigger_mutex.acquire()
    GPIO.output(8, GPIO.LOW)
    sleep(TRIGGER_DURATION)
    GPIO.output(8, GPIO.HIGH)
    trigger_mutex.release()

    return render_template('main.html', **trigger_config)

def interval_trigger(tc):
    while(True):
        config_mutex.acquire()
        state = trigger_config.get("state")
        start_time = trigger_config.get("last_start_s")
        current_duration = trigger_config.get("duration_s")
        sleep_interval = trigger_config.get("interval_s")
#        client.messages.create(
#                to = "+14044572051",
#                from_="+14044767927",
#                body = "Pictures are currently taking"
#            )
        
        config_mutex.release()

        while((time() < start_time + current_duration) and state):
            
            config_mutex.acquire()
            print("Pictures are taking")
            state = trigger_config.get("state")
            config_mutex.release()
            if (state == False):
                break

            trigger_mutex.acquire()
            GPIO.output(8, GPIO.LOW)
            sleep(TRIGGER_DURATION)
            GPIO.output(8, GPIO.HIGH)
            trigger_mutex.release()
            sleep(sleep_interval)
            


if __name__== "__main__":
    trigger_thread = Thread(target=interval_trigger, args=(trigger_config,), 
            name="interval_trigger")
    trigger_thread.start()

    app.run(threaded=True)
