/* Support program for testing gdb's ability to debug overlays
   in the inferior.  */

#include <pebble.h>
#include "ovlymgr.h"

extern int foo ();

int main ()
{
  OverlayLoad (0);
  foo();
  OverlayLoad (1);
  foo();
  OverlayLoad (2);
  foo();

  app_event_loop();
  
  return 0;
}