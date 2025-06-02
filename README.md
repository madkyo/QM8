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
