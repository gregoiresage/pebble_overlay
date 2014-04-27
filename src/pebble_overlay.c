#include <pebble.h>

/* Functions provided by the overlays */
extern void func1(void);
extern void func2(void);

int main(void)
{
  APP_LOG(APP_LOG_LEVEL_DEBUG,"Start of main()...\n");
  func1();
  func2();

  /*
   * Call func2() again to demonstrate that we don't need to
   * reload the overlay
   */
  func2();

  func1();
  APP_LOG(APP_LOG_LEVEL_DEBUG,"End of main()...\n");
 
  return 0;
}
