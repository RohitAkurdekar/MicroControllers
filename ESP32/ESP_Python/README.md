# MicroPython for ESP32

1. Install python and pip3

        $ sudo apt install python3 -y && sudo apt install pip3  -y

2. Install esptool
        
        $ sudo pip3 install esptool
        
3. Install thonny python editor

        $ sudo pip3 install thonny -y
        
        $ sudo apt install python3-tk -y
4. Use thonny to edit and upload code
5. Thonny settings:
  
    * Go to Tools &rarr; Options &rarr; Interpreter &rarr; Select MicroPython (ESP32) instead of local python3
    * Select port
    * if any permission error occurs:
      
          $ ls -l /dev/ttyUSB0
          
          crw-rw---- 1 root dialout 188, 0 Apr 25 22:41 /dev/ttyUSB0
          
          $ sudo usermod -a -G dialout rohit
          
          dialout is group of /dev/ttyUSB and rohit is username of current working shell
