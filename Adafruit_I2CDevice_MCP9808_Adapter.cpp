/*!
 * Copyright (C) 2022 Carl J. White III
 *
 * @file Adafruit_BME280.cpp
 *
 * @section author Author
 *
 * Written by Carl J. White III.
 *
 * @section license License
 *
 * BSD license, all text here must be included in any redistribution.
 * See the LICENSE file for details.
 *
 */

#include "Adafruit_I2CDevice_MCP9808_Adapter.h"
#include "I2CInterface.h"

#include <iostream>

using namespace std;

Adafruit_I2CDevice_MCP9808_Adapter::Adafruit_I2CDevice_MCP9808_Adapter(I2CInterface &interface) : 
    Adafruit_I2CDevice_Adapter(interface)
{
}

Adafruit_I2CDevice_MCP9808_Adapter::~Adafruit_I2CDevice_MCP9808_Adapter()
{
}

bool Adafruit_I2CDevice_MCP9808_Adapter::write_then_read (const uint8_t *write_buffer, size_t write_len,
                                                          uint8_t *read_buffer, size_t read_len,
                                                          bool stop)
{
    if (write_len == 1)
    {
        int reg = write_buffer[0];
        
        if (read_len == 1)
        {
            read_buffer[0] = (uint8_t)(interface.readReg8(reg));
        }
        else if (read_len == 2)
        {
            read_buffer[0] = (uint8_t)(interface.readReg16(reg));
            read_buffer[1] = (uint8_t)(interface.readReg16(reg) >> 8);
        }
        else
        {
            return false;
        }

        return true;
    }

    return false;
}

