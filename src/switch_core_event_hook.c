
#include "switch.h"
#include "private/switch_core_pvt.h"

NEW_HOOK_DECL(outgoing_channel)
	NEW_HOOK_DECL(receive_message)
	NEW_HOOK_DECL(receive_event)
	NEW_HOOK_DECL(state_change)
	NEW_HOOK_DECL(state_run)
	NEW_HOOK_DECL(read_frame)
	NEW_HOOK_DECL(write_frame)
	NEW_HOOK_DECL(video_read_frame)
	NEW_HOOK_DECL(video_write_frame)
	NEW_HOOK_DECL(kill_channel)
	NEW_HOOK_DECL(send_dtmf)
	NEW_HOOK_DECL(recv_dtmf)

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
