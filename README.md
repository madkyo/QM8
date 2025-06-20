# QM8
feature release
## Building and Flashing an EC Image
Prebuilt Image

Build instructions

Build instructions (zephyr)-

Flash instructions

- Main FW (464kb)

- ECFlashApp.efi -V Queries and prints the EC Firmware Version currently running on EC.

- ECFlashApp.efi -V <EC_FW>.bin Parses the EC firmware version from the binary's header and prints them.

- ECFlashApp.efi -U <EC_FW>.bin Updates the EC's Active partition with the binary passed and shall reset the EC. (Note: This shall update the EC firmware only if there is a version mismatch between EC's Firmware version and Binary's Firmware Version).

 

FW (960kb) in HW Recovery Mode (UART Flash Programming Mode)

ECFlashApp.efi -PR <EC_FW>.bin Erase and updates the entire EC internal flash - inclduing EC's Second stage bootloader, Active and Backup Partition

- Easy to write
- Supports **bold** and *italic* text
- Code blocks:

```python
def hello():
    print("Hello, World!")
```

## Links

[GitHub](https://github.com)

## Images

![GitHub Logo](https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png)

```
nuvoton
```
Please refer to the steps in the following link to configure your Zephyr environment:
https://docs.zephyrproject.org/4.1.0/develop/getting_started/index.html => NOTE: version 4.1.0.
(a) Install chocolatey.
(b) Get Zephyr and install Python dependencies
       - see also https://docs.nxp.com/bundle/GUIGUIDERUG_V1-6-0/page/topics/zephyr.html:
          => Get Zephyr and install Python dependencies: step 4 (Zephyr’s scripts\requirements.txt … Install them with pip3).
                 pip3 install -r %HOMEPATH%\zephyrproject\zephyr\scripts\requirements.txt
(c) Install the Zephyr SDK
(d) Build the Blinky Sample => if your environment is setup probably, you should be able to do this without error.
 
west build -p always -b npcx4m8f_evb samples\basic\blinky

```
qualcomm
```

Please refer the commands below to upgrade EC.

EC has 2nd BBK:

ECFlashApp -V  [Check the current EC FW version]
ECFlashApp -F -U <Main FW bin>   [Upgrade e-flash(ACPI I2C)]
ECFlashApp -V  <bin> [Check the binary FW version]
ECFlashApp -WUR <cmd> [Writes command over UART and reads the response]
EC in Programming mode:

ECFlashApp -PR <FW bin> [Upgrade e-flash(Hardware protocol)]
ECFlashApp -OP ENBBK [Request entering into EC boot block]
ECFlashApp -CR [Get Corruption Status] 
ECFlashApp -OP DISBBK [Request exiting from EC boot block]  