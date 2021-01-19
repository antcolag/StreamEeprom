#ifndef STREAM_EEPROM_H
#define STREAM_EEPROM_H

#include<Arduino.h>
#include<EEPROM.h>


struct StreamEeprom : Stream, EEPROMClass {
	unsigned current = 0;
	int available( ) {
		int free = (int) EEPROMClass::length() - (int) current;
		return free > 0 ? free : 0;
	}

	virtual void flush( ) {}

	int peek( ) {
		return EEPROMClass::read(current);
	}

	int read( ){
		if(available( )){
			return EEPROMClass::read(current++);
		}
	}

	size_t write( uint8_t u_Data ){
		if(available( )){
			EEPROMClass::update(current++, u_Data);
			return 1;
		}
		return 0;
	}
};

struct FlushableStreamEeprom : StreamEeprom {
	void flush( ) {
		current = 0;
	}
};

#endif