#include <pebble.h>

extern void foo(int x);

// Some RW and ZI data
char* func1_string = "func1 called\n";
int func1_values[20];

void func1(void)
{
	unsigned int i;
	APP_LOG(APP_LOG_LEVEL_DEBUG,func1_string);
	for(i = 19; i; i--)
	{
		func1_values[i] = rand();
		foo(i);
		APP_LOG(APP_LOG_LEVEL_DEBUG,"%d ", func1_values[i]);
	}
	APP_LOG(APP_LOG_LEVEL_DEBUG,"\n");
}
