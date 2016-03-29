Modified from https://github.com/samyk/usbdriveby

Hardware: Teensy 2.0 (likely works on the ++ and 3.0 versions as well)

Acts as a pseudo-keyboard and inserts a reverse shell into the crontab. 

For research & learning purposes only.

## Changes:

1. Removes DNS spoofing
2. Removes Little Snitch workaround
3. Changes timing
4. Uses bash instead of perl

## Usage

1. Setup your Arduino IDE to use Teensy (see teensy site).
2. Under Tools > USB Type : choose Serial, Keyboard, Mouse, Joystick
3. Update the sketch to point to your listening server
4. Burn sketch to device
5. Plug into Mac OSX Machine when unlocked. Device will blink when finished.
6. On your machine run netcat in listening mode on whatever port you defined in your sketch.
..* If using OSX for this machine, you may need to run as 'nc -l -p <port number>', depends on if you installed via brew or ports.

