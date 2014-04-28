
/*
 * Ovlymgr.c -- Runtime Overlay Manager for the GDB testsuite.
 */
#include <pebble.h>
#include "ovlymgr.h"

/* Local functions and data: */

extern char __load_start_foo_v0, __load_stop_foo_v0;
extern char __load_start_foo_v1, __load_stop_foo_v1;
extern char __load_start_foo_v2, __load_stop_foo_v2;

// extern unsigned long _ovly_table[][4];
// extern unsigned long _novlys __attribute__ ((section (".data")));
enum ovly_index { VMA, SIZE, LMA, MAPPED};

static void ovly_copy (unsigned long dst, unsigned long src, long size);

/* OverlayLoad:
 * Copy the overlay into its runtime region,
 * and mark the overlay as "mapped".
 */

bool
OverlayLoad (unsigned long ovlyno)
{
  unsigned long i;

  APP_LOG(APP_LOG_LEVEL_DEBUG,"OverlayLoad %d %p %p", (int)ovlyno, &__load_start_foo_v0, &__load_stop_foo_v0);

  switch(ovlyno){
    case 0 : memcpy ((char *) 0x1b4, &__load_start_foo_v0, &__load_stop_foo_v0 - &__load_start_foo_v0); return true;
    case 1 : memcpy ((char *) 0x1b4, &__load_start_foo_v1, &__load_stop_foo_v1 - &__load_start_foo_v1); return true;
    case 2 : memcpy ((char *) 0x1b4, &__load_start_foo_v2, &__load_stop_foo_v2 - &__load_start_foo_v2); return true;
    default: return false;
  }

  // if (ovlyno >= _novlys)
  //   return false; //TODO exit (-1);	/* fail, bad ovly number */

  // if (_ovly_table[ovlyno][MAPPED])
  //   return true;	/* this overlay already mapped -- nothing to do! */

  // for (i = 0; i < _novlys; i++)
  //   if (i == ovlyno)
  //     _ovly_table[i][MAPPED] = 1;	/* this one now mapped */
  //   else if (_ovly_table[i][VMA] == _ovly_table[ovlyno][VMA])
  //     _ovly_table[i][MAPPED] = 0;	/* this one now un-mapped */

  // ovly_copy (_ovly_table[ovlyno][VMA], 
	 //     _ovly_table[ovlyno][LMA], 
	 //     _ovly_table[ovlyno][SIZE]);

  return false;
}

static void
ovly_copy (unsigned long dst, unsigned long src, long size)
{
  memcpy ((void *) dst, (void *) src, size);
  return;
}
