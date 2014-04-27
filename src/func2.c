#include <pebble.h>

extern void foo(int x);

// Some RW and ZI data
char* func2_string = "func2 called\n";
int func2_values[10];

void func2(void)
{
	APP_LOG(APP_LOG_LEVEL_DEBUG,func2_string);
	foo(func2_values[9]);
}
