arduino-cli compile --fqbn arduino:avr:uno test/MyFirstSketch
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno test/MyFirstSketch