#!/bin/bash

BIN=arduino

avr-objcopy -O ihex ${BIN}.elf ${BIN}.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:${BIN}.hex -D
