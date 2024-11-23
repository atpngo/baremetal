#ifndef SERIAL_H
#define SERIAL_H


class Serial {
    public:
        Serial();
        ~Serial();
        void begin(unsigned long baudrate);
        void write(char* message);
        void writeln(const char* message);
    private:
        void writeChar(unsigned char data);
        unsigned long calculateUBBR(unsigned long baudrate);
};

#endif // SERIAL_H