StreamEeprom
===

The simplest interface to use the Arduino EEPROM as a Stream
There are two classes in this library
- `StreamEeprom` -> implements the Stream function on the EEPROMClass
- `FlushableStreamEeprom` -> extends the above class adding the possibility to reset the pointer to the current byte by calling `flush` method
