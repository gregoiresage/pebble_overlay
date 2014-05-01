#pragma once

/*
 * Sample runtime overlay manager.
 */

#include <pebble.h>

/* Entry Points: */

bool OverlayLoad   (unsigned long ovlyno);

int foo() __attribute__ ((section (".foo"))) ;
