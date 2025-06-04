/*
 * Copyright (c) 2023 ITE Corporation. All Rights Reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "../include/include.h"
#include <zephyr/sys/time_units.h>

//LOG_MODULE_REGISTER(app, LOG_LEVEL_INF);

K_THREAD_STACK_DEFINE(thread_stack_tmr_main, 1024);
struct k_thread thread_mainservice;
k_tid_t mainthreadid;

K_THREAD_STACK_DEFINE(thread_stack_thermal, 1024);
struct k_thread thread_thermalservice;
k_tid_t thermalthreadid;

K_THREAD_STACK_DEFINE(thread_stack_pcm, 1024);
struct k_thread thread_pcmservice;
k_tid_t pcmthreadid;

K_THREAD_STACK_DEFINE(thread_stack_powersourcedetect, 1024);
struct k_thread thread_powersourcedetectservice;
k_tid_t powersourcedetectthreadid;

K_THREAD_STACK_DEFINE(thread_stack_rtc, 1024);
struct k_thread thread_rtcservice;
k_tid_t rtcthreadid;


static uint32_t zephyr_kernal_version = 0;
int main(void)
{
	zephyr_kernal_version = sys_kernel_version_get();
	//	uint32_t major = SYS_KERNEL_VER_MAJOR(zephyr_kernal_version);
	//	uint32_t minor = SYS_KERNEL_VER_MINOR(zephyr_kernal_version);
	//	uint32_t patch = SYS_KERNEL_VER_PATCHLEVEL(zephyr_kernal_version);
	SYS_PRINT("Zephyr kernel version: %d.%d.%d\n", SYS_KERNEL_VER_MAJOR(zephyr_kernal_version), SYS_KERNEL_VER_MINOR(zephyr_kernal_version), SYS_KERNEL_VER_PATCHLEVEL(zephyr_kernal_version));
	SYS_PRINT("Hello IT82202, %s\n", EC_VER);
	board_init();
	Reload_EC_Ver();
	SYS_PRINT("IT82202, %s \n\n", EC_VER);
	mainthreadid = k_thread_create(&thread_mainservice, thread_stack_tmr_main, K_THREAD_STACK_SIZEOF(thread_stack_tmr_main),
								   ThreadMainService, NULL, NULL, NULL,
								   0, K_USER, K_NO_WAIT);
	thermalthreadid = k_thread_create(&thread_thermalservice, thread_stack_thermal, K_THREAD_STACK_SIZEOF(thread_stack_thermal),
									  threadThermalService, NULL, NULL, NULL,
									  0, K_USER, K_NO_WAIT);
#if (_SUPPORT_HP_PCM)
	pcmthreadid = k_thread_create(&thread_pcmservice, thread_stack_pcm, K_THREAD_STACK_SIZEOF(thread_stack_pcm),
								  threadPCMService, NULL, NULL, NULL,
								  0, K_USER, K_NO_WAIT);
	//k_thread_suspend(pcmthreadid); // default as suspend
#endif
#if (_SUPPORT_RT_ACDC_DETECT_via_PCM_wT)
	powersourcedetectthreadid = k_thread_create(&thread_pcmservice, thread_stack_powersourcedetect, K_THREAD_STACK_SIZEOF(thread_stack_powersourcedetect),
								threadPowerSourceDetectService, NULL, NULL, NULL,
								0, K_USER, K_NO_WAIT);
#endif
#if (_SUPPORT_HP_RTC)
	rtcthreadid = k_thread_create(&thread_rtcservice, thread_stack_rtc, K_THREAD_STACK_SIZEOF(thread_stack_rtc),
								  threadRTCService, NULL, NULL, NULL,
								  0, K_USER, K_NO_WAIT);
#endif

	while (1)
	{
		//SYS_PRINT("main\n");
		k_sleep(K_FOREVER);
	}

	return 0;
}
