# Web Programmable DSLR Intervalometer
Wirelessly programmable timelapses for Nikon DSLRs using mbed and Raspberry Pi

Developed and maintained by:
- Mufutau Akuruyejo @MufuteeVC
- Daniil Budanov @danbudanov
- Georgiy Pyantkovsky @Georgiyukr

## Description
In this project, we combine a **Raspberry Pi**-based webserver with an embedded 
system running on the ARM **mbed**-enabled LPC1768 microcontroller to operate
timelapses with user-defined intervals and durations on any Nikon DSLR
supporting the Nikon ML-L3 IR Remote interface.

A `Flask` web server runs on the Pi and provides a web interface to configure the
timelapse. Once enabled, the Pi sends a trigger signal to the mbed periodically
throughout the specified duration in seconds. The mbed modulates a `38.4 kHz`
waveform with a control signal and transmits this using an IR LED to the camera. 

Once a photo is taken, `twilio` is used to send an SMS notification to the user's
phone that a photo has been taken. The user is able to start and stop the
timelapse's operation at any time, as well as to fire a test image, using the
web interface.

## Hardware Setup
The system is wired as follows:
![hardware setup](images/breadboard.png)

A `QED-123 880nm IR LED` is connected to the `mbed` microcontroller's `p21` in
series with a `220 ohm` current limiting resistor. A wire connects the
Raspberry Pi's `GPIO8` to the mbed's `p20`, and this node is pulled up through
a `10k` resistor.

All signalling operates on `3.3 V` logic.

### Motivation
- Technology that enables taking pictures remotely with the Nikon Camera
- A programmable system that gives flexibility on the amount of shots to take and interval between them
- The taken pictures are stored on the camera. Also, notification is sent to the phone in form of SMS
- Portability +  Accuracy +  Reliability = Useful Device 

### Signal generated
![signal1](https://bayesianadventures.files.wordpress.com/2013/08/pic4.png)

### Overall Architecture

### Hardware Specification

### Software Specification
- Flask for creating the web page
- Twilio for sending SMS

### Manual
- The user sets the interval and how long the shots should be taken on the webpage.
- Upon turning the power on, the system goes online
- Pictures are taken automatically and stored in the SD Card
- SMS sent to phone indicating process done

### Demo
- 
