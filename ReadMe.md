# Arduino MCP980X Temperature Sensor Library v1.0 #
https://github.com/JChristensen/MCP980X
ReadMe file  
Jack Christensen Mar 2014

![CC BY-SA](http://mirrors.creativecommons.org/presskit/buttons/80x15/png/by-sa.png)

## Introduction ##
**Arduino Library for Microchip MCP9800/1/2/3 2-Wire High-Accuracy Temperature Sensors**

A basic implementation that exposes all functionality of the [Microchip MCP980X sensors](http://www.microchip.com/wwwproducts/Devices.aspx?dDocName=en020949). Temperatures are dealt with in the integer domain to avoid the code size and runtime overhead associated with floating-point. Still, it is easy enough to perform the necessary conversions should the user wish to work in floating-point format.

Temperatures read from the device's registers are returned as °C\*16. (If the device resolution is set to less than 12 bits, the corresponding lower order bits are simply returned as zero.) Temperatures can alternately be read as °F\*10.

When writing the Hysteresis and Limit-Set registers, the value must be given as °C*2, which corresponds to the internal representation in these registers.

Bit masks for the control register are provided in the **MCP980X.h** file.     

"Arduino Library for Microchip MCP9800/1/2/3" by Jack Christensen is licensed under [CC BY-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/).


## Installation ##
To use the **MCP980X** library:  
- Go to https://github.com/JChristensen/MCP980X, click the **Download ZIP** button and save the ZIP file to a convenient location on your PC.
- Uncompress the downloaded file.  This will result in a folder containing all the files for the library, that has a name that includes the branch name, usually **MCP980X-master**.
- Rename the folder to just **MCP980X**.
- Copy the renamed folder to the Arduino sketchbook\libraries folder.

## Examples ##
The following example sketch is included with the **MCP980X** library:
- **MCP980X_EX1:** Demonstrates basic reading of ambient temperature in Celsius and Fahrenheit, conversion to floating-point, changing device options via the Cofiguration register, and changing the Limit-Set and Hysteresis registers.

## Usage notes ##
The **MCP980X** library is designed for use with Arduino version 1.0 or later.

To use the **MCP980X** library, the standard Arduino Wire library must also be included.  For brevity, this include is not repeated in the examples below:
```c++
#include <Wire.h>         //http://arduino.cc/en/Reference/Wire (included with Arduino IDE)
```
## Enumeration ##

###MCP980X_REGS_t
#####Description
Symbolic names for the MCP980X registers.
#####Values
AMBIENT -- for the Ambient Temperature Register  
HYSTERESIS -- for the Temperature Hysteresis Register  
LIMITSET -- for the Temperature Limit-Set Register

## Constructor ##

###MCP980X(int LS_ADDR_BITS)
#####Description
Instantiates...
#####Syntax
`MCP980X mySensor(0);`
#####Parameters
Least-significant three bits of the device address *(int)*.

## Methods ##
###begin(void)
#####Description
...
#####Syntax
`mySensor.begin(void);`
#####Parameters
**foo:** ...
#####Returns
None.
#####Example
```c++
MCP980X mySensor(0);
mySensor.begin();
```
###readTempC16(MCP980X_REGS_t reg)
#####Description
...
#####Syntax
`mySensor.readTempC16(MCP980X_REGS_t reg);`
#####Parameters
**foo:** ...
#####Returns
None.
#####Example
```c++
...
```
###readTempF10(MCP980X_REGS_t reg)
#####Description
...
#####Syntax
`mySensor.readTempF10(MCP980X_REGS_t reg);`
#####Parameters
**foo:** ...
#####Returns
None.
#####Example
```c++
...
```
###writeTempC2(MCP980X_REGS_t reg, int value)
#####Description
...
#####Syntax
`mySensor.writeTempC2(MCP980X_REGS_t reg, int value);`
#####Parameters
**foo:** ...
#####Returns
None.
#####Example
```c++
...
```
###readConfig(void)
#####Description
...
#####Syntax
`mySensor.readConfig(void);`
#####Parameters
**foo:** ...
#####Returns
None.
#####Example
```c++
...
```
###writeConfig(uint8_t value)
#####Description
...
#####Syntax
`mySensor.writeConfig(uint8_t value);`
#####Parameters
**foo:** ...
#####Returns
None.
#####Example
```c++
...
```
