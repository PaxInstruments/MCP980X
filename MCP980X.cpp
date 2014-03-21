/*-----------------------------------------------------------------------------*
 * Arduino library for Microchip MCP9800/1/2/3 2-Wire High-Accuracy            *
 * Temperature Sensor                                                          *
 *                                                                             *
 * Jack Christensen 21Mar2014 v1.0                                             *
 *                                                                             *
 * "Arduino library for Microchip MCP9800/1/2/3" by Jack Christensen           *
 * is licensed under CC BY-SA 4.0,                                             *
 * http://creativecommons.org/licenses/by-sa/4.0/                              *
 *-----------------------------------------------------------------------------*/

#include <MCP980X.h>

//instantiate a temperature sensor object given the least three significant bits of its I2C address (0-7)
MCP980X::MCP980X(int LS_ADDR_BITS)
{
    _devAddr = MCP980X_BASE_ADDR + (LS_ADDR_BITS & 7);
}

void MCP980X::begin(void)
{
    Wire.begin();
}

//read one of the sensor's three temperature registers.
//returns the temperature as an integer which is °C times 16.
int MCP980X::readTempC16(MCP980X_REGS_t reg)
{
    Wire.beginTransmission(_devAddr);
    Wire.write(reg);
    Wire.endTransmission();
    
    Wire.requestFrom(_devAddr, 2);
    int8_t msb = Wire.read();
    uint8_t lsb = Wire.read();
    return (msb << 4) + (lsb >> 4);
}

//read one of the sensor's three temperature registers.
//returns the temperature as an integer which is °F times 10.
int MCP980X::readTempF10(MCP980X_REGS_t reg)
{
    long tF160 = (long)readTempC16(reg) * 18L;
    int tF10 = tF160 / 16;
    if ( (tF160 & 15) >= 8) ++tF10;    //round up to the next tenth if needed
//    if ( tF160 % 16 >= 8) ++tF10;    //(tF160 & 15) should be more efficient
    tF10 += 320;                    //add in the offset (*10)
    return tF10;
}

void MCP980X::writeTempC2(MCP980X_REGS_t reg, int value)
{
    union intByte_t {
        int i;
        byte b[2];
    } t;
    
    if (reg > AMBIENT) {   //ambient temp reg is read-only
        t.i = value << 7;
        Wire.beginTransmission(_devAddr);
        Wire.write(reg);
        Wire.write(t.b[1]);
        Wire.write(t.b[0]);
        Wire.endTransmission();
    }
}

//read the sensor's configuration register
uint8_t MCP980X::readConfig(void)
{
    Wire.beginTransmission(_devAddr);
    Wire.write(CONFIG_REG);
    Wire.endTransmission();
    
    Wire.requestFrom(_devAddr, 1);
    return Wire.read();
}

//read the sensor's configuration register
void MCP980X::writeConfig(uint8_t value)
{
    Wire.beginTransmission(_devAddr);
    Wire.write(CONFIG_REG);
    Wire.write(value);
    Wire.endTransmission();
}
