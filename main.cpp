#include "Serial.h"
#include <util/delay.h>

int main() {
    Serial serial;
    serial.begin(9600);
    while (1) {
        serial.writeln("hello world");
        _delay_ms(1000);
    }
    return 0;
}