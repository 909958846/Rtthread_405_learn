/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-05     RealThread   first version
 */

#include "board.h"

I2C_HandleTypeDef hi2c;
#define CHIPADDRESS 0x08
#define MEMADDRESS 0x0001
#define MEMADDRESS_SIZE 0x02

int hal_i2c_pin()
{
    //Enable the Peripheral Clock
    __HAL_RCC_I2C1_CLK_ENABLE();

    //Configure the Peripheral GPIO
    //I2C1_SCL=PB6
    //I2C1_SDA=PB7
    GPIO_InitTypeDef GPIO_Init_Struct={0};
    GPIO_Init_Struct.Pin=GPIO_PIN_6|GPIO_PIN_7;
    GPIO_Init_Struct.Mode=GPIO_MODE_AF_OD;
    GPIO_Init_Struct.Pull=GPIO_NOPULL;
    GPIO_Init_Struct.Speed=GPIO_SPEED_FREQ_HIGH;
    GPIO_Init_Struct.Alternate=GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_Init_Struct);

    //Configure the Peripheral Parameter
    hi2c.Init.ClockSpeed=400000;
    //Slave Features
    hi2c.Init.AddressingMode=I2C_ADDRESSINGMODE_7BIT;
    hi2c.Init.OwnAddress1=0;
    hi2c.Init.DualAddressMode=I2C_DUALADDRESS_DISABLE;
    hi2c.Init.OwnAddress2=0;
    hi2c.Init.GeneralCallMode=I2C_GENERALCALL_DISABLE;
    hi2c.Init.NoStretchMode=I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c);
    return RT_EOK;
}

INIT_BOARD_EXPORT(hal_i2c_pin);


static void i2c_eeprom_sample(int argc, char *argv[])
{
    char data[16]={0};
    rt_kprintf(argv);
    rt_kprintf(argv[0]);
    rt_kprintf(argv[2]);
    rt_kprintf(argv[3]);
    if (argv[0]=="r")
    {
        rt_kprintf(argv);
        rt_kprintf(argv[0]);
        rt_kprintf(argv[2]);
        rt_kprintf(argv[3]);
        //HAL_I2C_Mem_Read(&hi2c, argv[1], argv[2], MemAddSize, data, argv[3], -1);
        //rt_kprintf(data);
    }
}
//argc 表示参数的个数 argv表示命令行参数字符串指针数组
MSH_CMD_EXPORT(i2c_eeprom_sample,i2c_eeprom_sample r 0x08 0x0001 0x05);

