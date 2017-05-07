#include <stdint.h>
#include <stdbool.h>
#include <util/atomic.h>

#ifdef __cplusplus
extern "C" {
#endif

extern volatile uint8_t EVENT0;

// see driver_isr.c
extern volatile bool button_state_on;

extern volatile uint16_t time;

extern uint16_t capture_buffer[256];
extern volatile uint8_t capture_write_ptr;

#define BTN_CHG 0
#define NEW_512HZ_CYCLE 1
#define CAPTURE_FINISHED 2

static inline bool is_button_change(void) {
  return EVENT0 & (1 << BTN_CHG);
}

static inline void set_button_change(void) {
  EVENT0 |= (1 << BTN_CHG);
}

static inline void clear_button_change(void) {
    EVENT0 &= ~(1 << BTN_CHG);
}


static inline bool is_new_512hz_cycle(void) {
  return EVENT0 & (1 << NEW_512HZ_CYCLE);
}

static inline void set_new_512hz_cycle(void) {
  EVENT0 |= (1 << NEW_512HZ_CYCLE);
}

static inline void clear_new_512hz_cycle(void) {
    EVENT0 &= ~(1 << NEW_512HZ_CYCLE);
}

static inline bool is_capture_finished(void) {
  return EVENT0 & (1 << CAPTURE_FINISHED);
}

static inline void set_capture_finished(void) {
  EVENT0 |= (1 << CAPTURE_FINISHED);
}

static inline void clear_capture_finished(void) {
    EVENT0 &= ~(1 << CAPTURE_FINISHED);
}


static inline uint16_t read_time(void) {
  uint16_t ret;
  ATOMIC_BLOCK(ATOMIC_FORCEON) {
    ret = time;
  }
  return ret;
}

#ifdef __cplusplus
}
#endif
