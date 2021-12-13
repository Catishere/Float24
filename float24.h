#ifndef FLOAT24_H
#define FLOAT24_H

#define CHOPMASK        ((1UL << 24) - 1)
#define F32_SIGN        0b10000000000000000000000000000000
#define F32_EXP         0b01111111100000000000000000000000
#define F32_MANT        0b00000000011111111111111111111111

#define F24_SIGN        0b100000000000000000000000
#define F24_EXP         0b011111100000000000000000
#define F24_MANT        0b000000011111111111111111
#define F24_NINF        0b111111100000000000000000
#define F24_PINF        0b011111100000000000000000
#define F24_NAN         0b111111111111111111111111
#define F24_MANT_PREP   0b000000100000000000000000
#define F24_EXP_CARRY   0b000001000000000000000000

#define F32TOF24_SIGN   0b10000000000000000000000000000000
#define F32TOF24_EXP    0b01111110000000000000000000000000
#define F32TOF24_MANT   0b00000000011111111111111111000000
#define F32TOF24_MANT_OFFSET 2

#include <cmath>
#include <cstring>
#include <iostream>

class Float24
{
    char value[3];
    Float24 newtonDivision(Float24 guess, Float24 divider);
public:
    int8_t getExponent();
    Float24 operator+(Float24 f2);
    Float24 operator-(Float24 f2);
    Float24 operator-();
    Float24 operator/(Float24 f2);
    Float24 operator*(Float24 f2);
    bool operator==(Float24 f2);
    void operator+=(Float24 f2);
    void operator/=(Float24 f2);
    void operator*=(Float24 f2);
    bool equals(Float24 f2, int precision);
    float toFloat32();
    Float24(float number);
    Float24();
    friend std::ostream& operator<<(std::ostream &cout, Float24 &obj);
};

#endif // FLOAT24_H
