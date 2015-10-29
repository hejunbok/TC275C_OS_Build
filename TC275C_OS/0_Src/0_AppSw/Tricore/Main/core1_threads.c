/*-----------------------------------------------------------------------------------
|
|   File name:    Appcore1.c
|   Created on:   Aug 26, 2015
|   Author:       Yanpeng.xi
|   Description:
|                 Multicore OS based on Aurix 275C app kit and TASKING 4.3 compiler
|
--------------------------------------------------------------------------------------*/
#define  THREAD_GLOBAL_CONFIG_DEFINITION DISABLE
#include "os_type.h"
#include "os.h"
#include <stdlib.h>
#include "core1_tasks.h"
#include "core1_thread_cfg.h"
#include "core1_kernel_abstract.h"
#include "os_trace.h"

#pragma align 16

// period threads...
#if (CORE1_THREAD0_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th0,CORE1_THREAD0_PRIORITY,SCHED_FIFO,CORE1_THREAD0_STACK_SIZE)
#endif
#if (CORE1_THREAD1_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th1, CORE1_THREAD1_PRIORITY,SCHED_FIFO,CORE1_THREAD1_STACK_SIZE)
#endif
#if (CORE1_THREAD2_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th2, CORE1_THREAD2_PRIORITY,SCHED_FIFO,CORE1_THREAD2_STACK_SIZE)
#endif
#if (CORE1_THREAD3_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th3, CORE1_THREAD3_PRIORITY,SCHED_FIFO,CORE1_THREAD3_STACK_SIZE)
#endif
#if (CORE1_THREAD4_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th4, CORE1_THREAD4_PRIORITY,SCHED_FIFO,CORE1_THREAD4_STACK_SIZE)
#endif
#if (CORE1_THREAD5_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th5, CORE1_THREAD5_PRIORITY,SCHED_FIFO,CORE1_THREAD5_STACK_SIZE)
#endif
#if (CORE1_THREAD6_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th6, CORE1_THREAD6_PRIORITY,SCHED_FIFO,CORE1_THREAD6_STACK_SIZE)
#endif
#if (CORE1_THREAD7_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th7, CORE1_THREAD7_PRIORITY,SCHED_FIFO,CORE1_THREAD7_STACK_SIZE)
#endif
#if (CORE1_THREAD8_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th8, CORE1_THREAD8_PRIORITY,SCHED_FIFO,CORE1_THREAD8_STACK_SIZE)
#endif
#if (CORE1_THREAD9_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th9, CORE1_THREAD9_PRIORITY,SCHED_FIFO,CORE1_THREAD9_STACK_SIZE)
#endif
#if (CORE1_THREAD10_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th10,CORE1_THREAD10_PRIORITY,SCHED_FIFO,CORE1_THREAD10_STACK_SIZE)
#endif
#if (CORE1_THREAD11_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th11,CORE1_THREAD11_PRIORITY,SCHED_FIFO,CORE1_THREAD11_STACK_SIZE)
#endif
#if (CORE1_THREAD12_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th12,CORE1_THREAD12_PRIORITY,SCHED_FIFO,CORE1_THREAD12_STACK_SIZE)
#endif
#if (CORE1_THREAD13_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th13,CORE1_THREAD13_PRIORITY,SCHED_FIFO,CORE1_THREAD13_STACK_SIZE)
#endif
#if (CORE1_THREAD14_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th14,CORE1_THREAD14_PRIORITY,SCHED_FIFO,CORE1_THREAD14_STACK_SIZE)
#endif
#if (CORE1_THREAD15_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th15,CORE1_THREAD15_PRIORITY,SCHED_FIFO,CORE1_THREAD15_STACK_SIZE)
#endif
#if (CORE1_THREAD16_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th16,CORE1_THREAD16_PRIORITY,SCHED_FIFO,CORE1_THREAD16_STACK_SIZE)
#endif
#if (CORE1_THREAD17_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th17,CORE1_THREAD17_PRIORITY,SCHED_FIFO,CORE1_THREAD17_STACK_SIZE)
#endif
#if (CORE1_THREAD18_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th18,CORE1_THREAD18_PRIORITY,SCHED_FIFO,CORE1_THREAD18_STACK_SIZE)
#endif
#if (CORE1_THREAD19_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th19,CORE1_THREAD19_PRIORITY,SCHED_FIFO,CORE1_THREAD19_STACK_SIZE)
#endif
#if (CORE1_THREAD20_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th20,CORE1_THREAD20_PRIORITY,SCHED_FIFO,CORE1_THREAD20_STACK_SIZE)
#endif
#if (CORE1_THREAD21_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th21,CORE1_THREAD21_PRIORITY,SCHED_FIFO,CORE1_THREAD21_STACK_SIZE)
#endif
#if (CORE1_THREAD22_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th22,CORE1_THREAD22_PRIORITY,SCHED_FIFO,CORE1_THREAD22_STACK_SIZE)
#endif
#if (CORE1_THREAD23_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th23,CORE1_THREAD23_PRIORITY,SCHED_FIFO,CORE1_THREAD23_STACK_SIZE)
#endif
#if (CORE1_THREAD24_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th24,CORE1_THREAD24_PRIORITY,SCHED_FIFO,CORE1_THREAD24_STACK_SIZE)
#endif
#if (CORE1_THREAD25_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th25,CORE1_THREAD25_PRIORITY,SCHED_FIFO,CORE1_THREAD25_STACK_SIZE)
#endif
#if (CORE1_THREAD26_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th26,CORE1_THREAD26_PRIORITY,SCHED_FIFO,CORE1_THREAD26_STACK_SIZE)
#endif
#if (CORE1_THREAD27_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th27,CORE1_THREAD27_PRIORITY,SCHED_FIFO,CORE1_THREAD27_STACK_SIZE)
#endif
#if (CORE1_THREAD28_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th28,CORE1_THREAD28_PRIORITY,SCHED_FIFO,CORE1_THREAD28_STACK_SIZE)
#endif
#if (CORE1_THREAD29_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th29,CORE1_THREAD29_PRIORITY,SCHED_FIFO,CORE1_THREAD29_STACK_SIZE)
#endif
#if (CORE1_THREAD30_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th30,CORE1_THREAD30_PRIORITY,SCHED_FIFO,CORE1_THREAD30_STACK_SIZE)
#endif
#if (CORE1_THREAD31_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th31,CORE1_THREAD31_PRIORITY,SCHED_FIFO,CORE1_THREAD31_STACK_SIZE)
#endif
#if (CORE1_THREAD32_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th32,CORE1_THREAD32_PRIORITY,SCHED_FIFO,CORE1_THREAD32_STACK_SIZE)
#endif
#if (CORE1_THREAD33_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th33,CORE1_THREAD33_PRIORITY,SCHED_FIFO,CORE1_THREAD33_STACK_SIZE)
#endif
#if (CORE1_THREAD34_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th34,CORE1_THREAD34_PRIORITY,SCHED_FIFO,CORE1_THREAD34_STACK_SIZE)
#endif
#if (CORE1_THREAD35_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th35,CORE1_THREAD35_PRIORITY,SCHED_FIFO,CORE1_THREAD35_STACK_SIZE)
#endif
#if (CORE1_THREAD36_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th36,CORE1_THREAD36_PRIORITY,SCHED_FIFO,CORE1_THREAD36_STACK_SIZE)
#endif
#if (CORE1_THREAD37_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th37,CORE1_THREAD37_PRIORITY,SCHED_FIFO,CORE1_THREAD37_STACK_SIZE)
#endif
#if (CORE1_THREAD38_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th38,CORE1_THREAD38_PRIORITY,SCHED_FIFO,CORE1_THREAD38_STACK_SIZE)
#endif
#if (CORE1_THREAD39_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th39,CORE1_THREAD39_PRIORITY,SCHED_FIFO,CORE1_THREAD39_STACK_SIZE)
#endif
#if (CORE1_THREAD40_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th40,CORE1_THREAD40_PRIORITY,SCHED_FIFO,CORE1_THREAD40_STACK_SIZE)
#endif
#if (CORE1_THREAD41_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th41,CORE1_THREAD41_PRIORITY,SCHED_FIFO,CORE1_THREAD41_STACK_SIZE)
#endif
#if (CORE1_THREAD42_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th42,CORE1_THREAD42_PRIORITY,SCHED_FIFO,CORE1_THREAD42_STACK_SIZE)
#endif
#if (CORE1_THREAD43_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th43,CORE1_THREAD43_PRIORITY,SCHED_FIFO,CORE1_THREAD43_STACK_SIZE)
#endif
#if (CORE1_THREAD44_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th44,CORE1_THREAD44_PRIORITY,SCHED_FIFO,CORE1_THREAD44_STACK_SIZE)
#endif
#if (CORE1_THREAD45_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th45,CORE1_THREAD45_PRIORITY,SCHED_FIFO,CORE1_THREAD45_STACK_SIZE)
#endif
#if (CORE1_THREAD46_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th46,CORE1_THREAD46_PRIORITY,SCHED_FIFO,CORE1_THREAD46_STACK_SIZE)
#endif
#if (CORE1_THREAD47_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th47,CORE1_THREAD47_PRIORITY,SCHED_FIFO,CORE1_THREAD47_STACK_SIZE)
#endif
#if (CORE1_THREAD48_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th48,CORE1_THREAD48_PRIORITY,SCHED_FIFO,CORE1_THREAD48_STACK_SIZE)
#endif
#if (CORE1_THREAD49_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th49,CORE1_THREAD49_PRIORITY,SCHED_FIFO,CORE1_THREAD49_STACK_SIZE)
#endif
#if (CORE1_THREAD50_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th50,CORE1_THREAD50_PRIORITY,SCHED_FIFO,CORE1_THREAD50_STACK_SIZE)
#endif
#if (CORE1_THREAD51_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th51,CORE1_THREAD51_PRIORITY,SCHED_FIFO,CORE1_THREAD51_STACK_SIZE)
#endif
#if (CORE1_THREAD52_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th52,CORE1_THREAD52_PRIORITY,SCHED_FIFO,CORE1_THREAD52_STACK_SIZE)
#endif
#if (CORE1_THREAD53_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th53,CORE1_THREAD53_PRIORITY,SCHED_FIFO,CORE1_THREAD53_STACK_SIZE)
#endif
#if (CORE1_THREAD54_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th54,CORE1_THREAD54_PRIORITY,SCHED_FIFO,CORE1_THREAD54_STACK_SIZE)
#endif
#if (CORE1_THREAD55_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th55,CORE1_THREAD55_PRIORITY,SCHED_FIFO,CORE1_THREAD55_STACK_SIZE)
#endif
#if (CORE1_THREAD56_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th56,CORE1_THREAD56_PRIORITY,SCHED_FIFO,CORE1_THREAD56_STACK_SIZE)
#endif
#if (CORE1_THREAD57_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th57,CORE1_THREAD57_PRIORITY,SCHED_FIFO,CORE1_THREAD57_STACK_SIZE)
#endif
#if (CORE1_THREAD58_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th58,CORE1_THREAD58_PRIORITY,SCHED_FIFO,CORE1_THREAD58_STACK_SIZE)
#endif
#if (CORE1_THREAD59_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th59,CORE1_THREAD59_PRIORITY,SCHED_FIFO,CORE1_THREAD59_STACK_SIZE)
#endif
#if (CORE1_THREAD60_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th60,CORE1_THREAD60_PRIORITY,SCHED_FIFO,CORE1_THREAD60_STACK_SIZE)
#endif
#if (CORE1_THREAD61_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th61,CORE1_THREAD61_PRIORITY,SCHED_FIFO,CORE1_THREAD61_STACK_SIZE)
#endif
#if (CORE1_THREAD62_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th62,CORE1_THREAD62_PRIORITY,SCHED_FIFO,CORE1_THREAD62_STACK_SIZE)
#endif
#if (CORE1_THREAD63_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th63,CORE1_THREAD63_PRIORITY,SCHED_FIFO,CORE1_THREAD63_STACK_SIZE)
#endif
#if (CORE1_THREAD64_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th64,CORE1_THREAD64_PRIORITY,SCHED_FIFO,CORE1_THREAD64_STACK_SIZE)
#endif
#if (CORE1_THREAD65_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th65,CORE1_THREAD65_PRIORITY,SCHED_FIFO,CORE1_THREAD65_STACK_SIZE)
#endif
#if (CORE1_THREAD66_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th66,CORE1_THREAD66_PRIORITY,SCHED_FIFO,CORE1_THREAD66_STACK_SIZE)
#endif
#if (CORE1_THREAD67_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th67,CORE1_THREAD67_PRIORITY,SCHED_FIFO,CORE1_THREAD67_STACK_SIZE)
#endif
#if (CORE1_THREAD68_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th68,CORE1_THREAD68_PRIORITY,SCHED_FIFO,CORE1_THREAD68_STACK_SIZE)
#endif
#if (CORE1_THREAD69_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th69,CORE1_THREAD69_PRIORITY,SCHED_FIFO,CORE1_THREAD69_STACK_SIZE)
#endif
#if (CORE1_THREAD70_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th70,CORE1_THREAD70_PRIORITY,SCHED_FIFO,CORE1_THREAD70_STACK_SIZE)
#endif
#if (CORE1_THREAD71_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th71,CORE1_THREAD71_PRIORITY,SCHED_FIFO,CORE1_THREAD71_STACK_SIZE)
#endif
#if (CORE1_THREAD72_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th72,CORE1_THREAD72_PRIORITY,SCHED_FIFO,CORE1_THREAD72_STACK_SIZE)
#endif
#if (CORE1_THREAD73_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th73,CORE1_THREAD73_PRIORITY,SCHED_FIFO,CORE1_THREAD73_STACK_SIZE)
#endif
#if (CORE1_THREAD74_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th74,CORE1_THREAD74_PRIORITY,SCHED_FIFO,CORE1_THREAD74_STACK_SIZE)
#endif
#if (CORE1_THREAD75_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th75,CORE1_THREAD75_PRIORITY,SCHED_FIFO,CORE1_THREAD75_STACK_SIZE)
#endif
#if (CORE1_THREAD76_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th76,CORE1_THREAD76_PRIORITY,SCHED_FIFO,CORE1_THREAD76_STACK_SIZE)
#endif
#if (CORE1_THREAD77_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th77,CORE1_THREAD77_PRIORITY,SCHED_FIFO,CORE1_THREAD77_STACK_SIZE)
#endif
#if (CORE1_THREAD78_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th78,CORE1_THREAD78_PRIORITY,SCHED_FIFO,CORE1_THREAD78_STACK_SIZE)
#endif
#if (CORE1_THREAD79_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th79,CORE1_THREAD79_PRIORITY,SCHED_FIFO,CORE1_THREAD79_STACK_SIZE)
#endif
#if (CORE1_THREAD80_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th80,CORE1_THREAD80_PRIORITY,SCHED_FIFO,CORE1_THREAD80_STACK_SIZE)
#endif
#if (CORE1_THREAD81_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th81,CORE1_THREAD81_PRIORITY,SCHED_FIFO,CORE1_THREAD81_STACK_SIZE)
#endif
#if (CORE1_THREAD82_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th82,CORE1_THREAD82_PRIORITY,SCHED_FIFO,CORE1_THREAD82_STACK_SIZE)
#endif
#if (CORE1_THREAD83_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th83,CORE1_THREAD83_PRIORITY,SCHED_FIFO,CORE1_THREAD83_STACK_SIZE)
#endif
#if (CORE1_THREAD84_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th84,CORE1_THREAD84_PRIORITY,SCHED_FIFO,CORE1_THREAD84_STACK_SIZE)
#endif
#if (CORE1_THREAD85_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th85,CORE1_THREAD85_PRIORITY,SCHED_FIFO,CORE1_THREAD85_STACK_SIZE)
#endif
#if (CORE1_THREAD86_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th86,CORE1_THREAD86_PRIORITY,SCHED_FIFO,CORE1_THREAD86_STACK_SIZE)
#endif
#if (CORE1_THREAD87_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th87,CORE1_THREAD87_PRIORITY,SCHED_FIFO,CORE1_THREAD87_STACK_SIZE)
#endif
#if (CORE1_THREAD88_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th88,CORE1_THREAD88_PRIORITY,SCHED_FIFO,CORE1_THREAD88_STACK_SIZE)
#endif
#if (CORE1_THREAD89_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th89,CORE1_THREAD89_PRIORITY,SCHED_FIFO,CORE1_THREAD89_STACK_SIZE)
#endif
#if (CORE1_THREAD90_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th90,CORE1_THREAD90_PRIORITY,SCHED_FIFO,CORE1_THREAD90_STACK_SIZE)
#endif
#if (CORE1_THREAD91_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th91,CORE1_THREAD91_PRIORITY,SCHED_FIFO,CORE1_THREAD91_STACK_SIZE)
#endif
#if (CORE1_THREAD92_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th92,CORE1_THREAD92_PRIORITY,SCHED_FIFO,CORE1_THREAD92_STACK_SIZE)
#endif
#if (CORE1_THREAD93_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th93,CORE1_THREAD93_PRIORITY,SCHED_FIFO,CORE1_THREAD93_STACK_SIZE)
#endif
#if (CORE1_THREAD94_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th94,CORE1_THREAD94_PRIORITY,SCHED_FIFO,CORE1_THREAD94_STACK_SIZE)
#endif
#if (CORE1_THREAD95_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th95,CORE1_THREAD95_PRIORITY,SCHED_FIFO,CORE1_THREAD95_STACK_SIZE)
#endif
#if (CORE1_THREAD96_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th96,CORE1_THREAD96_PRIORITY,SCHED_FIFO,CORE1_THREAD96_STACK_SIZE)
#endif
#if (CORE1_THREAD97_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th97,CORE1_THREAD97_PRIORITY,SCHED_FIFO,CORE1_THREAD97_STACK_SIZE)
#endif
#if (CORE1_THREAD98_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th98,CORE1_THREAD98_PRIORITY,SCHED_FIFO,CORE1_THREAD98_STACK_SIZE)
#endif
#if (CORE1_THREAD99_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th99,CORE1_THREAD99_PRIORITY,SCHED_FIFO,CORE1_THREAD99_STACK_SIZE)
#endif
#if (CORE1_THREAD100_SWITCH == ON) 
CORE1_PTHREAD_CONTROL_BLOCK(core1_os_th100,CORE1_THREAD100_PRIORITY,SCHED_FIFO,CORE1_THREAD100_STACK_SIZE)
#endif
#pragma align restore

#if (CORE1_THREAD0_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(0)
#endif
#if (CORE1_THREAD1_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(1)
#endif
#if (CORE1_THREAD2_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(2)
#endif
#if (CORE1_THREAD3_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(3)
#endif
#if (CORE1_THREAD4_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(4)
#endif
#if (CORE1_THREAD5_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(5)
#endif
#if (CORE1_THREAD6_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(6)
#endif
#if (CORE1_THREAD7_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(7)
#endif
#if (CORE1_THREAD8_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(8)
#endif
#if (CORE1_THREAD9_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(9)
#endif
#if (CORE1_THREAD10_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(10)
#endif
#if (CORE1_THREAD11_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(11)
#endif
#if (CORE1_THREAD12_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(12)
#endif
#if (CORE1_THREAD13_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(13)
#endif
#if (CORE1_THREAD14_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(14)
#endif
#if (CORE1_THREAD15_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(15)
#endif
#if (CORE1_THREAD16_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(16)
#endif
#if (CORE1_THREAD17_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(17)
#endif
#if (CORE1_THREAD18_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(18)
#endif
#if (CORE1_THREAD19_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(19)
#endif
#if (CORE1_THREAD20_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(20)
#endif
#if (CORE1_THREAD21_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(21)
#endif
#if (CORE1_THREAD22_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(22)
#endif
#if (CORE1_THREAD23_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(23)
#endif
#if (CORE1_THREAD24_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(24)
#endif
#if (CORE1_THREAD25_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(25)
#endif
#if (CORE1_THREAD26_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(26)
#endif
#if (CORE1_THREAD27_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(27)
#endif
#if (CORE1_THREAD28_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(28)
#endif
#if (CORE1_THREAD29_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(29)
#endif
#if (CORE1_THREAD30_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(30)
#endif
#if (CORE1_THREAD31_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(31)
#endif
#if (CORE1_THREAD32_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(32)
#endif
#if (CORE1_THREAD33_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(33)
#endif
#if (CORE1_THREAD34_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(34)
#endif
#if (CORE1_THREAD35_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(35)
#endif
#if (CORE1_THREAD36_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(36)
#endif
#if (CORE1_THREAD37_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(37)
#endif
#if (CORE1_THREAD38_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(38)
#endif
#if (CORE1_THREAD39_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(39)
#endif
#if (CORE1_THREAD40_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(40)
#endif
#if (CORE1_THREAD41_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(41)
#endif
#if (CORE1_THREAD42_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(42)
#endif
#if (CORE1_THREAD43_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(43)
#endif
#if (CORE1_THREAD44_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(44)
#endif
#if (CORE1_THREAD45_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(45)
#endif
#if (CORE1_THREAD46_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(46)
#endif
#if (CORE1_THREAD47_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(47)
#endif
#if (CORE1_THREAD48_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(48)
#endif
#if (CORE1_THREAD49_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(49)
#endif
#if (CORE1_THREAD50_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(50)
#endif
#if (CORE1_THREAD51_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(51)
#endif
#if (CORE1_THREAD55_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(55)
#endif
#if (CORE1_THREAD52_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(52)
#endif
#if (CORE1_THREAD54_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(54)
#endif
#if (CORE1_THREAD55_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(55)
#endif
#if (CORE1_THREAD56_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(56)
#endif
#if (CORE1_THREAD57_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(57)
#endif
#if (CORE1_THREAD58_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(58)
#endif
#if (CORE1_THREAD59_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(59)
#endif
#if (CORE1_THREAD60_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(60)
#endif
#if (CORE1_THREAD61_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(61)
#endif
#if (CORE1_THREAD62_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(62)
#endif
#if (CORE1_THREAD63_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(63)
#endif
#if (CORE1_THREAD64_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(64)
#endif
#if (CORE1_THREAD65_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(65)
#endif
#if (CORE1_THREAD66_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(66)
#endif
#if (CORE1_THREAD67_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(67)
#endif
#if (CORE1_THREAD68_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(68)
#endif
#if (CORE1_THREAD69_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(69)
#endif
#if (CORE1_THREAD70_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(70)
#endif
#if (CORE1_THREAD71_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(71)
#endif
#if (CORE1_THREAD72_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(72)
#endif
#if (CORE1_THREAD73_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(73)
#endif
#if (CORE1_THREAD74_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(74)
#endif
#if (CORE1_THREAD75_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(75)
#endif
#if (CORE1_THREAD76_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(76)
#endif
#if (CORE1_THREAD77_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(77)
#endif
#if (CORE1_THREAD78_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(78)
#endif
#if (CORE1_THREAD79_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(79)
#endif
#if (CORE1_THREAD80_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(80)
#endif
#if (CORE1_THREAD81_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(81)
#endif
#if (CORE1_THREAD82_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(82)
#endif
#if (CORE1_THREAD83_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(83)
#endif
#if (CORE1_THREAD84_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(84)
#endif
#if (CORE1_THREAD85_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(85)
#endif
#if (CORE1_THREAD86_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(86)
#endif
#if (CORE1_THREAD87_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(87)
#endif
#if (CORE1_THREAD88_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(88)
#endif
#if (CORE1_THREAD89_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(89)
#endif
#if (CORE1_THREAD90_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(90)
#endif
#if (CORE1_THREAD91_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(91)
#endif
#if (CORE1_THREAD92_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(92)
#endif
#if (CORE1_THREAD93_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(93)
#endif
#if (CORE1_THREAD94_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(94)
#endif
#if (CORE1_THREAD95_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(95)
#endif
#if (CORE1_THREAD96_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(96)
#endif
#if (CORE1_THREAD97_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(97)
#endif
#if (CORE1_THREAD98_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(98)
#endif
#if (CORE1_THREAD99_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(99)
#endif
#if (CORE1_THREAD100_SWITCH == ON) 
CORE1_PTHREAD_DEFINITION_BLOCK(100)
#endif

void start_core1_os(void) {

#if (CORE1_OS_SWITCH == ON)
#if (CORE1_THREAD0_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(0)
#endif
#if (CORE1_THREAD1_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(1)
#endif
#if (CORE1_THREAD2_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(2)
#endif
#if 0
#if (CORE1_THREAD3_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(3)
#endif
#if (CORE1_THREAD4_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(4)
#endif
#if (CORE1_THREAD5_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(5)
#endif
#if (CORE1_THREAD6_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(6)
#endif
#if (CORE1_THREAD7_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(7)
#endif
#if (CORE1_THREAD8_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(8)
#endif
#if (CORE1_THREAD9_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(9)
#endif
#endif

#if (CORE1_THREAD10_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(10)
#endif
#if (CORE1_THREAD11_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(11)
#endif
#if (CORE1_THREAD12_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(12)
#endif
#if (CORE1_THREAD13_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(13)
#endif
#if (CORE1_THREAD14_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(14)
#endif
#if (CORE1_THREAD15_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(15)
#endif
#if (CORE1_THREAD16_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(16)
#endif
#if (CORE1_THREAD17_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(17)
#endif
#if (CORE1_THREAD18_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(18)
#endif
#if (CORE1_THREAD19_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(19)
#endif
#if (CORE1_THREAD20_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(20)
#endif
#if (CORE1_THREAD21_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(21)
#endif
#if (CORE1_THREAD22_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(22)
#endif
#if (CORE1_THREAD23_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(23)
#endif
#if (CORE1_THREAD24_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(24)
#endif
#if (CORE1_THREAD25_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(25)
#endif
#if (CORE1_THREAD26_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(26)
#endif
#if (CORE1_THREAD27_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(27)
#endif
#if (CORE1_THREAD28_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(28)
#endif
#if (CORE1_THREAD29_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(29)
#endif
#if (CORE1_THREAD30_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(30)
#endif
#if (CORE1_THREAD31_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(31)
#endif
#if (CORE1_THREAD32_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(32)
#endif
#if (CORE1_THREAD33_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(33)
#endif
#if (CORE1_THREAD34_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(34)
#endif
#if (CORE1_THREAD35_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(35)
#endif
#if (CORE1_THREAD36_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(36)
#endif
#if (CORE1_THREAD37_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(37)
#endif
#if (CORE1_THREAD38_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(38)
#endif
#if (CORE1_THREAD39_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(39)
#endif
#if (CORE1_THREAD40_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(40)
#endif
#if (CORE1_THREAD41_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(41)
#endif
#if (CORE1_THREAD42_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(42)
#endif
#if (CORE1_THREAD43_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(43)
#endif
#if (CORE1_THREAD44_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(44)
#endif
#if (CORE1_THREAD45_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(45)
#endif
#if (CORE1_THREAD46_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(46)
#endif
#if (CORE1_THREAD47_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(47)
#endif
#if (CORE1_THREAD48_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(48)
#endif
#if (CORE1_THREAD49_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(49)
#endif
#if (CORE1_THREAD50_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(50)
#endif
#if (CORE1_THREAD51_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(51)
#endif
#if (CORE1_THREAD52_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(52)
#endif
#if (CORE1_THREAD53_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(53)
#endif
#if (CORE1_THREAD54_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(54)
#endif
#if (CORE1_THREAD55_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(55)
#endif
#if (CORE1_THREAD56_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(56)
#endif
#if (CORE1_THREAD57_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(57)
#endif
#if (CORE1_THREAD58_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(58)
#endif
#if (CORE1_THREAD59_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(59)
#endif
#if (CORE1_THREAD60_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(60)
#endif
#if (CORE1_THREAD61_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(61)
#endif
#if (CORE1_THREAD62_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(62)
#endif
#if (CORE1_THREAD63_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(63)
#endif
#if (CORE1_THREAD64_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(64)
#endif
#if (CORE1_THREAD65_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(65)
#endif
#if (CORE1_THREAD66_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(66)
#endif
#if (CORE1_THREAD67_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(67)
#endif
#if (CORE1_THREAD68_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(68)
#endif
#if (CORE1_THREAD69_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(69)
#endif
#if (CORE1_THREAD70_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(70)
#endif
#if (CORE1_THREAD71_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(71)
#endif
#if (CORE1_THREAD72_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(72)
#endif
#if (CORE1_THREAD73_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(73)
#endif
#if (CORE1_THREAD74_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(74)
#endif
#if (CORE1_THREAD75_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(75)
#endif
#if (CORE1_THREAD76_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(76)
#endif
#if (CORE1_THREAD77_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(77)
#endif
#if (CORE1_THREAD78_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(78)
#endif
#if (CORE1_THREAD79_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(79)
#endif
#if (CORE1_THREAD80_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(80)
#endif
#if (CORE1_THREAD81_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(81)
#endif
#if (CORE1_THREAD82_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(82)
#endif
#if (CORE1_THREAD83_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(83)
#endif
#if (CORE1_THREAD84_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(84)
#endif
#if (CORE1_THREAD85_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(85)
#endif
#if (CORE1_THREAD86_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(86)
#endif
#if (CORE1_THREAD87_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(87)
#endif
#if (CORE1_THREAD88_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(88)
#endif
#if (CORE1_THREAD89_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(89)
#endif
#if (CORE1_THREAD90_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(90)
#endif
#if (CORE1_THREAD91_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(91)
#endif
#if (CORE1_THREAD92_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(92)
#endif
#if (CORE1_THREAD93_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(93)
#endif
#if (CORE1_THREAD94_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(94)
#endif
#if (CORE1_THREAD95_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(95)
#endif
#if (CORE1_THREAD96_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(96)
#endif
#if (CORE1_THREAD97_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(97)
#endif
#if (CORE1_THREAD98_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(98)
#endif
#if (CORE1_THREAD99_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(99)
#endif
#if (CORE1_THREAD100_SWITCH == ON) 
    CORE1_PTHREAD_CREATION_BLOCK(100)
#endif

	CORE1_PTHREAD_START_BLOCK()
#endif
}

