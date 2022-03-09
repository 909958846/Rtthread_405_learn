/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-05     RT-Thread    first version
 */

#include <rtthread.h>
#include <vconsole.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

static rt_device_t usb_device=RT_NULL;
int usb_change_shell(void)
{
    usb_device=rt_device_find("vcom");
    if(usb_device==RT_NULL)
    {
        rt_kprintf("not found vcom device!\n");
        return -1;
    }
    vconsole_switch(usb_device);
    return RT_EOK;
}

int main(void)
{
    int count = 1;
    //rt_thread_delay(1000);
    usb_change_shell();
    rt_thread_delay(10000);
    rt_show_version();
    LOG_D("Hello RT-Thread!");
    while (count++)
    {
        //LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }
    return RT_EOK;
}



MSH_CMD_EXPORT(usb_change_shell, usb change shell);


