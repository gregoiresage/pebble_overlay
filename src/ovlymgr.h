#pragma once

/*
 * Sample runtime overlay manager.
 */

#include <pebble.h>

/* Entry Points: */

bool OverlayLoad   (unsigned long ovlyno);
bool OverlayUnload (unsigned long ovlyno);
