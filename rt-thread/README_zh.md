如何修改console到USB_VCOM
1.打开USB_Device框架并设置虚拟串口
2.在board.h中
	#define BSP_USING_USBDEVICE
3.在stm32f4xx_hal_conf.h
	#define HAL_PCD_MODULE_ENABLED
	#define HSE_VALUE    ((uint32_t)12000000U)
4.利用CubeMX工具，生成void system_clock_config(int target_freq_mhz)函数配置HSE，修改原工程的SYSTEM_CLOCK_CONFIG函数
	void system_clock_config(int target_freq_mhz)
5.利用CubeMX工具，生成hal_usb_pin（void)函数，配置USB的2根数据脚的GPIO配置
	复制到drv_clk.c末尾，并INIT_BOARD_EXPORT(hal_usb_pin);

 



