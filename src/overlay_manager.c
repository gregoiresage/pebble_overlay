/* Basic overlay manager */
#include <pebble.h>

/* Number of overlays present */
#define NUM_OVERLAYS 2

/* struct to hold addresses and lengths */
typedef struct overlay_region_t_struct
{
	void* load_ro_base;
	void* load_rw_base;
	void* exec_zi_base;
	unsigned int ro_length;
	unsigned int zi_length;
} overlay_region_t;

/* Record for current overlay */
int current_overlay = 0;

/* Array describing the overlays */
extern const overlay_region_t overlay_regions[NUM_OVERLAYS];

/* execution bases of the overlay regions - defined in overlay_list.s */
extern void * const code_base;
extern void * const data_base;

void load_overlay(int n)
{
 	const overlay_region_t * selected_region;

	if(n == current_overlay)
	{
		APP_LOG(APP_LOG_LEVEL_DEBUG,"Overlay %d already loaded.\n", n);
		return;
	}
	
	/* boundary check */
	if(n<1 || n>NUM_OVERLAYS)
	{
		APP_LOG(APP_LOG_LEVEL_DEBUG,"Error - invalid overlay number %d specified\n", n);
		exit(1);
	}
	
	/* Load the corresponding overlay */
	APP_LOG(APP_LOG_LEVEL_DEBUG,"Loading overlay %d...\n", n);
	
	/* set selected region */
	selected_region = &overlay_regions[n-1];
	
	/* load code overlay */
	memcpy(code_base, selected_region->load_ro_base, selected_region->ro_length);
	
	/* load data overlay */
	memcpy(data_base, selected_region->load_rw_base, (unsigned int)selected_region->exec_zi_base - (unsigned int)data_base);
	
	/* Comment out the next line if your overlays have any static ZI variables
	 * and should not be reinitialized each time, and move them out of the
	 * overlay region in your scatter file */
	memset(selected_region->exec_zi_base, 0, selected_region->zi_length);

	/* update record of current overlay */
	current_overlay=n;
	
	APP_LOG(APP_LOG_LEVEL_DEBUG,"...Done.\n");
	
}
