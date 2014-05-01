/* Support program for testing gdb's ability to debug overlays
   in the inferior.  */

#include <pebble.h>
#include "ovlymgr.h"

int main ()
{
  OverlayLoad (0);
  APP_LOG(APP_LOG_LEVEL_DEBUG,"main 0 %d", foo());
  OverlayLoad (1);
  APP_LOG(APP_LOG_LEVEL_DEBUG,"main 1 %d", foo());
  
  app_event_loop();
  
  return 0;
}