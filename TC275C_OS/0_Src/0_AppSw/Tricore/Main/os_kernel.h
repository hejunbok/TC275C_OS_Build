/*
 * os_kernel.h
 *
 *  Created on: Aug 26, 2015
 *      Author: tz68d9
 */

#ifndef OS_KERNEL_H_
#define OS_KERNEL_H_

#include "os_kernel_cfg.h"

#define PTHREAD_COND_INITIALIZER {NULL}
#define PTHREAD_MUTEX_INITIALIZER {false,NULL}

#define PTHREAD_CONTROL_BLOCK(_name,_priority,_policy,_stacksize) static struct { \
    pthread_t next,prev;\
    uint32_t lcx; \
    uint32_t priority; \
    uint32_t policy; \
    uint32_t *arg; \
    uint32_t stack[_stacksize]; \
    } _##_name = {0,(pthread_t)&_##_name,0,_priority,_policy,NULL,{_stacksize+1}};\
    \
    pthread_t _name = (pthread_t)&_##_name;

//! Scheduling policy
enum sched_policy_e {
    SCHED_FIFO, SCHED_RR, SCHED_OTHER
};

//! User mode definition
enum user_e {
    USER0, USER1, SUPER
};
//! Call depth definition
enum call_depth_overflow_e {
    CALL_DEPTH_OVERFLOW_AT_64 = 0,
    CALL_DEPTH_OVERFLOW_AT_32 = 0x40,
    CALL_DEPTH_OVERFLOW_AT_16 = 0x60,
    CALL_DEPTH_OVERFLOW_AT_8 = 0x70,
    CALL_DEPTH_OVERFLOW_AT_4 = 0x78,
    CALL_DEPTH_OVERFLOW_AT_2 = 0x7C,
    CALL_DEPTH_TRAP_EVERY_CALL = 0x7E,
    CALL_DEPTH_OVERFLOW_DISABLED = 0x7F,
};

//! Description of the thread attributes.
typedef struct {
    enum user_e mode;//!< thread mode must be 0 user_e
    uint32_t call_depth_overflow;//!< call depth overflow
    uint32_t stacksize;//!< stacksize
} pthread_attr_t;

//! Description the thread record.
typedef struct pthread_s {
    struct pthread_s *next; //!< Next thread pointer
    struct pthread_s *prev; //!< Previous thread pointer
    uint32_t lcx; //!< Lower context pointer
    uint32_t priority; //!< Thread priority must be 0 to \ref PTHREAD_PRIO_MAX
    uint32_t policy; //!< Policy is one of sched_policy_e
    uint32_t *arg; //!< Container that saves the argument passed to the thread function
    uint32_t stack[1]; //!< Stack. The size 1 is only a dummy. Memory allocation is done via \ref PTHREAD_CONTROL_BLOCK
}*pthread_t;

//! Description of a thread mutex.
typedef struct {
    uint32_t lock;//!< mutex lock status is one of <true | false>
    pthread_t owner; //!< owner thread
    pthread_t blocked_threads; //!< list threads waiting for mutex
} pthread_mutex_t;

//! Description of a thread conditional variable.
typedef struct {
    pthread_t blocked_threads; //!< list threads waiting for condition
} pthread_cond_t;

int pthread_create_np(pthread_t, const pthread_attr_t *, void(*)(void *),
        void *);
void start_core0_os(void);
void start_core1_os(void);
void start_core2_os(void);

inline uint32_t os_getCoreId(void)
{
   uint32_t core_id;

   core_id=__mfcr(CPU_CORE_ID);
   
   return (core_id&0x7);
}

//! Start threads
inline void pthread_start_np(void) {
    extern  uint32_t  core0_os_pthread_runnable;
    extern  pthread_t core0_os_pthread_running;
    extern  pthread_t core0_os_pthread_runnable_threads[PTHREAD_PRIO_MAX];

	extern  uint32_t  core1_os_pthread_runnable;
    extern  pthread_t core1_os_pthread_running;
    extern  pthread_t core1_os_pthread_runnable_threads[PTHREAD_PRIO_MAX];

	extern  uint32_t  core2_os_pthread_runnable;
    extern  pthread_t core2_os_pthread_running;
    extern  pthread_t core2_os_pthread_runnable_threads[PTHREAD_PRIO_MAX];

    pthread_t thread;
 
	if(os_getCoreId()==0)
	{
      assert(core0_os_pthread_runnable != 0);
      thread = core0_os_pthread_runnable_threads[31 - __clz(core0_os_pthread_runnable)]; //  get ready thread with highest priority ready
      assert(thread);
      assert(thread->lcx);
    
      core0_os_pthread_running = thread;//
      __mtcr(CPU_PSW, 0x00000980);        /* clear PSW.IS */

      __dsync();
      __mtcr(CPU_PCXI,  thread->lcx);
      __rslcx();
	}
    else if(os_getCoreId()==1)
	{
      assert(core1_os_pthread_runnable != 0);
      thread = core1_os_pthread_runnable_threads[31 - __clz(core1_os_pthread_runnable)]; //  get ready thread with highest priority ready
      assert(thread);
      assert(thread->lcx);
    
      core1_os_pthread_running = thread;//
      __mtcr(CPU_PSW, 0x00000980);        /* clear PSW.IS */

      __dsync();
      __mtcr(CPU_PCXI,  thread->lcx);
      __rslcx();         // restore the lower context
	}
	else if(os_getCoreId()==2)
	{
      assert(core2_os_pthread_runnable != 0);
      thread = core2_os_pthread_runnable_threads[31 - __clz(core2_os_pthread_runnable)]; //  get ready thread with highest priority ready
      assert(thread);
      assert(thread->lcx);
    
      core2_os_pthread_running = thread;//
      __mtcr(CPU_PSW, 0x00000980);        /* clear PSW.IS */

      __dsync();
      __mtcr(CPU_PCXI,  thread->lcx);
      __rslcx();         // restore the lower context
	}	
    __asm(" mov d2,#0"); // the return value is 2
    __asm(" rfe");       // restore the upper context
}

//!  TriCore context structure
typedef union {
    struct {
        uint32_t pcxi; //!< upper context PCXI
        uint32_t psw; //!< upper context PSW
        void * a10; //!< upper context A10 (SP)
        void * a11; //!< upper context A11 (RA)
        uint32_t d8; //!< upper context D8
        uint32_t d9; //!< upper context D9
        uint32_t d10; //!< upper context D10
        uint32_t d11; //!< upper context D11
        uint32_t a12; //!< upper context A12
        uint32_t a13; //!< upper context A13
        uint32_t a14; //!< upper context A14
        uint32_t a15; //!< upper context A15
        uint32_t d12; //!< upper context D12
        uint32_t d13; //!< upper context D13
        uint32_t d14; //!< upper context D14
        uint32_t d15; //!< upper context D15
    } u; //!< upper context
    struct {
        uint32_t pcxi; //!< lower context PCXI
        void (*pc)(void*); //!< lower context saved PC
        uint32_t a2; //!< lower context A2
        uint32_t a3; //!< lower context A3
        uint32_t d0; //!< lower context D0
        uint32_t d1; //!< lower context D1
        uint32_t d2; //!< lower context D2
        uint32_t d3; //!< lower context D3
        void * a4; //!< lower context A4
        uint32_t a5; //!< lower context A5
        uint32_t a6; //!< lower context A6
        uint32_t a7; //!< lower context A7
        uint32_t d4; //!< lower context D4
        uint32_t d5; //!< lower context D5
        uint32_t d6; //!< lower context D6
        uint32_t d7; //!< lower context D7
    } l; //!< lower context
} context_t;

inline context_t *cx_to_addr(uint32_t cx) {
    uint32_t seg_nr = __extru(cx, 16, 4);
    return (context_t *) __insert(seg_nr << 28, cx, 6, 16);
}

inline void delay_ms(uint32_t _milliseconds) {
    __asm( "  mov.u d15,#1000 \n"
            "  mov.a a15,d15  \n"
            "  nop16          \n"
            "  nop16          \n"
            "  loop a15,*-4    \n"
            "  loop %0,*-8   \n"
            ::"a"((_milliseconds*200)/2): "a15","d15");
}

//! Insert NEZ.A instruction
inline uint32_t neza(void *p) {
    int ret;
    __asm("nez.a %0,%1":"=d"(ret):"a"(p));
    return ret;
}

/* The functions are called by app */
int pthread_mutex_lock(pthread_mutex_t *mutex) ;//!<  [in] mutex pointer
int pthread_mutex_unlock(pthread_mutex_t *mutex) ;
//! Wait on a condition
int pthread_cond_wait(pthread_cond_t *cond);//!< [in] condition pointer
int pthread_cond_broadcast(pthread_cond_t *cond); //!< [in] condition pointer
//! Wait on a condition
int pthread_cond_timedwait_np(pthread_cond_t *cond,//!< [in] condition pointer
        pthread_mutex_t *mutex,//!< [in] mutex pointer
        uint16_t reltime,
        uint32_t task_id); //!< [in] relative time are the relative time STM_TIM4 ticks.NOT PORTABLE.


#endif /* OS_KERNEL_H_ */
