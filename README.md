# midi-x-connect

Midi Cross Connect

This project describes how to build a MIDI cross connect cable.

## The normal case
Midi with 5-Pin DIN connectors is unidirectional. You can connect an output of one device to an input of another device. All devices use female connectors and a cable with male connectors on both sides

## USB MIDI

With USB Midi there are devices and hosts. For example a typical Master Keyboard only has a MIDI output connector and in addition a USB connector, that can be connected to a host. The host may be a computer, or also a tablet PC like the IPad.

### Example
If you have a Master keyboard like the Arturia MINILAB 3, you can connect it with a "Camera connection kit" to an IPad. In this case you can use Garageband or any other APP that is able to use MIDI input out of the box. You can also connect this master keyboard to a Windows PC running a DAW software or a virtual Instrument.

## Connect two computers with Midi

If you want to connect two computers, like a Raspberry PI and a Windows PC with a USB cable with MIDI, this does not work with a standard cable. 

## Solution with standard equipment

You can connect a USB Midi device to Computer A and another USB MIDI device to Computer B. The DIN connectors you are cross-connectiong (IN to OUT and OUT to IN) with two MIDI DIN cables. In case you need only one direction, you need only one cable.

This solution has some disadvantages:
You need 4 cables and two boxes which are quite expensive. In case you use two cheap USB-A to MIDI cables, you need a gender changer in between.

## The midi-x-connect project

This GitHub project describes how to create a simple hardware solution to connect two computers with USB-A socket.

### The hardware
For the hardware you need two Arduino Micro boards. They are quite cheap and there are only 3 wires needed to connect these boards. Each board has an USB-3 connector, that connects with a standartd USB-3 to USB-A cable

### The software
There are two Arduino project for the read-software and the write-software.

The software translates the binary MIDI protocol to an ASCII format on the serial connection. The serial ports of the Arduino boards are crossconnected: 
Ground to Ground
TX (transmit) to RX (Receive)
RX (Receive) to TX (Transmit)

The simple solution uses an electric connection with wires. A solution with optocoplers is also possible, if you want to avoid ground loops in Audio Equipment

## Use cases that work

### Raspberry PI and IPad
The midi-x-connect works successfully in a connection from Raspberry PI to an IPad

Known Software solution:
Ardour 8.2 on Raspberry and GarageBand on IPadd

What can you do?

You can use Ardour and route the Output to GarageBand. The IPad is able to play piano sounds

### Raspberry PI and Windows 10 PC

You can use Ardour and route the Output to a Virtual Instrument on the Windows PC. Known Software solution is "Kontakt 7" with a virtual Piano or UVI Workstation 64 with a virtual Piano.








