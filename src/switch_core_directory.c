

#include <switch.h>
#include "private/switch_core_pvt.h"

SWITCH_DECLARE(switch_status_t) switch_core_directory_open(switch_directory_handle_t *dh,
														   char *module_name, char *source, char *dsn, char *passwd, switch_memory_pool_t *pool)
{
	switch_status_t status;

	if ((dh->directory_interface = switch_loadable_module_get_directory_interface(module_name)) == 0) {
		switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_ERROR, "Invalid directory module [%s]!\n", module_name);
		return SWITCH_STATUS_GENERR;
	}

	if (pool) {
		dh->memory_pool = pool;
	} else {
		if ((status = switch_core_new_memory_pool(&dh->memory_pool)) != SWITCH_STATUS_SUCCESS) {
			UNPROTECT_INTERFACE(dh->directory_interface);
			return status;
		}
		switch_set_flag(dh, SWITCH_DIRECTORY_FLAG_FREE_POOL);
	}

	return dh->directory_interface->directory_open(dh, source, dsn, passwd);
}

SWITCH_DECLARE(switch_status_t) switch_core_directory_query(switch_directory_handle_t *dh, char *base, char *query)
{
	return dh->directory_interface->directory_query(dh, base, query);
}

SWITCH_DECLARE(switch_status_t) switch_core_directory_next(switch_directory_handle_t *dh)
{
	return dh->directory_interface->directory_next(dh);
}

SWITCH_DECLARE(switch_status_t) switch_core_directory_next_pair(switch_directory_handle_t *dh, char **var, char **val)
{
	return dh->directory_interface->directory_next_pair(dh, var, val);
}

SWITCH_DECLARE(switch_status_t) switch_core_directory_close(switch_directory_handle_t *dh)
{
	switch_status_t status;

	status = dh->directory_interface->directory_close(dh);
	UNPROTECT_INTERFACE(dh->directory_interface);

	if (switch_test_flag(dh, SWITCH_DIRECTORY_FLAG_FREE_POOL)) {
		switch_core_destroy_memory_pool(&dh->memory_pool);
	}

	return status;
}

/* For Emacs:
 * Local Variables:
 * mode:c
 * indent-tabs-mode:t
 * tab-width:4
 * c-basic-offset:4
 * End:
 * For VIM:
 * vim:set softtabstop=4 shiftwidth=4 tabstop=4 noet:
 */
