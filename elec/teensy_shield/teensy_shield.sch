EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 26
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 6300 1550 600  2500
U 55E5CC66
F0 "mcu" 50
F1 "mcu.sch" 50
F2 "GND" I L 6300 1700 60 
F3 "Vin" I L 6300 1800 60 
F4 "PWM1" O L 6300 2000 60 
F5 "DIR1" O L 6300 2100 60 
F6 "ANGLE1" I L 6300 2200 60 
F7 "CURRENT1" I L 6300 2300 60 
F8 "EN1" O L 6300 2400 60 
F9 "PWM2" O L 6300 2600 60 
F10 "DIR2" O L 6300 2700 60 
F11 "ANGLE2" I L 6300 2800 60 
F12 "CURRENT2" I L 6300 2900 60 
F13 "EN2" O L 6300 3000 60 
F14 "PWM3" O L 6300 3200 60 
F15 "DIR3" O L 6300 3300 60 
F16 "ANGLE3" I L 6300 3400 60 
F17 "CURRENT3" I L 6300 3500 60 
F18 "EN3" O L 6300 3600 60 
F19 "SDA" I L 6300 3800 60 
F20 "SCL" I L 6300 3900 60 
$EndSheet
$Sheet
S 3700 4550 750  500 
U 55E614B3
F0 "accelero" 50
F1 "accelero.sch" 50
F2 "GND" I R 4450 4650 60 
F3 "Vin" I R 4450 4750 60 
F4 "SDA" I R 4450 4850 60 
F5 "SCL" I R 4450 4950 60 
$EndSheet
$Sheet
S 3900 950  550  1050
U 55E6307C
F0 "joint1" 50
F1 "joint.sch" 50
F2 "GND" I R 4450 1050 60 
F3 "Vin_log" I R 4450 1150 60 
F4 "Vin_pow" I R 4450 1250 60 
F5 "PWM" I R 4450 1400 60 
F6 "DIR" I R 4450 1500 60 
F7 "ANGLE" O R 4450 1650 60 
F8 "CURRENT" O R 4450 1750 60 
F9 "EN" I R 4450 1900 60 
$EndSheet
$Sheet
S 3900 2150 550  1050
U 55E6307C
F0 "joint2" 50
F1 "joint.sch" 50
F2 "GND" I R 4450 2250 60 
F3 "Vin_log" I R 4450 2350 60 
F4 "Vin_pow" I R 4450 2450 60 
F5 "PWM" I R 4450 2600 60 
F6 "DIR" I R 4450 2700 60 
F7 "ANGLE" O R 4450 2850 60 
F8 "CURRENT" O R 4450 2950 60 
F9 "EN" I R 4450 3100 60 
$EndSheet
$Sheet
S 3900 3350 550  1050
U 55E6307C
F0 "joint3" 50
F1 "joint.sch" 50
F2 "GND" I R 4450 3450 60 
F3 "Vin_log" I R 4450 3550 60 
F4 "Vin_pow" I R 4450 3650 60 
F5 "PWM" I R 4450 3800 60 
F6 "DIR" I R 4450 3900 60 
F7 "ANGLE" O R 4450 4050 60 
F8 "CURRENT" O R 4450 4150 60 
F9 "EN" I R 4450 4300 60 
$EndSheet
Wire Wire Line
	6300 2000 5500 2000
Wire Wire Line
	5500 2000 5500 1400
Wire Wire Line
	5500 1400 4450 1400
Wire Wire Line
	6300 2100 5400 2100
Wire Wire Line
	5400 2100 5400 1500
Wire Wire Line
	5400 1500 4450 1500
Wire Wire Line
	6300 2200 5300 2200
Wire Wire Line
	5300 2200 5300 1650
Wire Wire Line
	5300 1650 4450 1650
Wire Wire Line
	6300 2300 5200 2300
Wire Wire Line
	5200 2300 5200 1750
Wire Wire Line
	5200 1750 4450 1750
Wire Wire Line
	6300 2400 5100 2400
Wire Wire Line
	5100 2400 5100 1900
Wire Wire Line
	5100 1900 4450 1900
Wire Wire Line
	6300 2600 4450 2600
Wire Wire Line
	6300 2700 4450 2700
Wire Wire Line
	6300 2800 5350 2800
Wire Wire Line
	5350 2800 5350 2850
Wire Wire Line
	5350 2850 4450 2850
Wire Wire Line
	6300 2900 5450 2900
Wire Wire Line
	5450 2900 5450 2950
Wire Wire Line
	5450 2950 4450 2950
Wire Wire Line
	6300 3000 5550 3000
Wire Wire Line
	5550 3000 5550 3100
Wire Wire Line
	5550 3100 4450 3100
Wire Wire Line
	6300 3200 5150 3200
Wire Wire Line
	5150 3200 5150 3800
Wire Wire Line
	5150 3800 4450 3800
Wire Wire Line
	6300 3300 5250 3300
Wire Wire Line
	5250 3300 5250 3900
Wire Wire Line
	5250 3900 4450 3900
Wire Wire Line
	6300 3400 5350 3400
Wire Wire Line
	5350 3400 5350 4050
Wire Wire Line
	5350 4050 4450 4050
Wire Wire Line
	6300 3500 5450 3500
Wire Wire Line
	5450 3500 5450 4150
Wire Wire Line
	5450 4150 4450 4150
Wire Wire Line
	6300 3600 5550 3600
Wire Wire Line
	5550 3600 5550 4300
Wire Wire Line
	5550 4300 4450 4300
Wire Wire Line
	6300 3800 5650 3800
Wire Wire Line
	5650 3800 5650 4850
Wire Wire Line
	5650 4850 4450 4850
Wire Wire Line
	6300 3900 5750 3900
Wire Wire Line
	5750 3900 5750 4950
Wire Wire Line
	5750 4950 4450 4950
$Sheet
S 8050 2050 550  300 
U 55E71B9E
F0 "alim_pow" 50
F1 "alim_pow.sch" 50
F2 "GND" I L 8050 2150 60 
F3 "Vout" O L 8050 2250 60 
$EndSheet
$Sheet
S 8050 2700 550  400 
U 55E71C2E
F0 "alim_log" 50
F1 "alim_log.sch" 50
F2 "GND" I L 8050 2850 60 
F3 "Vout" O L 8050 2950 60 
$EndSheet
Text Label 6300 1700 2    60   ~ 0
GND
Text Label 8050 2850 2    60   ~ 0
GND
Text Label 8050 2150 2    60   ~ 0
GND
Text Label 4450 1050 0    60   ~ 0
GND
Text Label 4450 2250 0    60   ~ 0
GND
Text Label 4450 3450 0    60   ~ 0
GND
Text Label 4450 4650 0    60   ~ 0
GND
Text Label 4450 1150 0    60   ~ 0
Vlog
Text Label 4450 2350 0    60   ~ 0
Vlog
Text Label 4450 3550 0    60   ~ 0
Vlog
Text Label 4450 4750 0    60   ~ 0
Vlog
Text Label 6300 1800 2    60   ~ 0
Vlog
Text Label 8050 2950 2    60   ~ 0
Vlog
Text Label 8050 2250 2    60   ~ 0
Vpow
Text Label 4450 1250 0    60   ~ 0
Vpow
Text Label 4450 2450 0    60   ~ 0
Vpow
Text Label 4450 3650 0    60   ~ 0
Vpow
$EndSCHEMATC
