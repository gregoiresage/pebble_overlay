
#include <pebble.h>
#include "ovlymgr.h"

/* OverlayLoad:
 */

bool
OverlayLoad (unsigned long ovlyno)
{
  ResHandle rh = resource_get_handle(RESOURCE_ID_FOO_BIN_0);

  if(ovlyno == 0){
    rh = resource_get_handle(RESOURCE_ID_FOO_BIN_0);
  }
  else if(ovlyno == 1){
    rh = resource_get_handle(RESOURCE_ID_FOO_BIN_1);
  }
  else {
    return false;
  }
    
  size_t size = resource_size(rh);

  // uint8_t* buffer = malloc(size * sizeof(uint8_t));
  resource_load(rh, (uint8_t*)(&foo - 1), size); 

  // APP_LOG(APP_LOG_LEVEL_DEBUG,"foo %02x", *(uint8_t *)(&foo - 1));

  // for(size_t i=0; i<size; i++){
  //   if(buffer[i] != ( *((uint8_t *)(&foo + i - 1)))){
  //     APP_LOG(APP_LOG_LEVEL_DEBUG,"foo %02x %02x errrrrrrrrrrr", (uint8_t)buffer[i], *((uint8_t *)(&foo + i - 1)));
  //   }
  //   else {
  //     APP_LOG(APP_LOG_LEVEL_DEBUG,"foo %02x %02x", (uint8_t)buffer[i], *((uint8_t *)(&foo + i - 1)));
  //   }
  // }

  // memcpy(&foo - 1, buffer, size);

  // free(buffer);
  
  return false;
}


// int foo() __attribute__ ((section (".foo"))) ;

// int foo() {
//   APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v0");
//   return 0;
// }

int foo() {
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  APP_LOG(APP_LOG_LEVEL_DEBUG,"foo_v1");
  return 1;
}