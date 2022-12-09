#include "RaspberryPiI2C.h"
#include "Adafruit_MCP9808.h"
#include "Adafruit_I2CDevice_Adapter.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    RaspberryPiI2C device(MCP9808_I2CADDR_DEFAULT);
    Adafruit_I2CDevice_Adapter adapter(device);

    Adafruit_MCP9808 sensor(adapter);
    
    if (sensor.begin())
    {
        cout << "Temperature = " << sensor.readTempC() << " C" << endl;
    }

    return 0;
}
