# hc-sr04-demo
Simple arduino code to poll and oversample the inexpensive HC-SR04 Ultrasonic Rangefinder board without libraries

The current code is written for the NodeMCU V2 board (an ESP8266 breakout board) but is easily modifyable to work with most if not any arduino compatible device.

CAUTION: Note that the ECHO voltage from the HC-SR04 is 5v TTL.  This will DESTROY pins on your device if it is not 3.3v compatible and fail to use a level shifter.

A simple voltage divider (two resistors) works well.  Connect a 1K resistor to the ECHO pin of the HC-SR04. The second lead connects to a 2K resistor. The second lead of the 2K resistor connects to ground.  The center-tap of these two resistors will now divide the 5v ECHO signal to 3.3v.  Be sure your power sources share a common ground with no long ground-loops to improve signal quality.
