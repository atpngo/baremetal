#include "Serial.h"
#include <avr/io.h>
#include <string.h>

Serial::Serial() {

}

Serial::~Serial() {

}

void Serial::begin(unsigned long baudrate) {
    unsigned long ubrr = calculateUBBR(baudrate);
    // Set baudrate high and low
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    // RX and TX control and status register
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Set frame: 8 data, 2 stp bits
    UCSR0C = (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);

    return;
}

void Serial::write(char* message) {
    for (int i=0; i<strlen(message); i++) {
        writeChar(message[i]);
    }
    return;
}

void Serial::writeln(const char* message) {
    int bufferSize = strlen(message) + 2;
    char buffer[bufferSize];
    strcpy(buffer, message);
    buffer[bufferSize-2] = '\n';
    buffer[bufferSize-1] = '\0';
    write(buffer);
}

void Serial::writeChar(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
    return;
}

unsigned long Serial::calculateUBBR(unsigned long baudrate) {
    // clock speed constant
    unsigned long clockRate = 16000000UL;
    // calculate ubrr from baudrate
    return clockRate/16.0/baudrate-1;
}
