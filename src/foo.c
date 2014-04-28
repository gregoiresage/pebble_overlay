#include <pebble.h>

int foo_v0() __attribute__((noinline,section(".s_foo_v0")));
int foo_v0() {
	APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v0");
  return 0;
}

int foo_v1() __attribute__((noinline,section(".s_foo_v1")));
int foo_v1() {
	APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  return 1;
}

int foo_v2() __attribute__((noinline,section(".s_foo_v2")));
int foo_v2() {
	APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v2");
   return 2;
}

