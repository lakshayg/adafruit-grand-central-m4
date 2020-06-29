#include "Adafruit_SPIFlash.h"
#include "SdFat.h"

#if !defined(EXTERNAL_FLASH_USE_QSPI)
#error "SPI flash is not defined for the board"
#endif

Adafruit_FlashTransport_QSPI flashTransport;
Adafruit_SPIFlash flash(&flashTransport);
FatFileSystem fatfs;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // wait for native usb
  }

  flash.begin();
  fatfs.begin(&flash);

  Serial.print("JEDEC ID: ");
  Serial.println(flash.getJEDECID(), HEX);
  Serial.print("Flash size: ");
  Serial.println(flash.size());

  // List files
  Serial.println("$ ls /");
  fatfs.ls("/");

  Serial.println("$ ls .fseventsd/");
  fatfs.ls(".fseventsd/");

  Serial.println("$ ls lib/");
  fatfs.ls("lib/");

  Serial.println("$ cat data.csv");
  File datafile;
  if (datafile = fatfs.open("data.csv")) {
    char data[4096];
    datafile.read(data, 4096);
    Serial.print(data);
  } else {
    Serial.println("File does not exist");
  }
}

void loop() {
}
