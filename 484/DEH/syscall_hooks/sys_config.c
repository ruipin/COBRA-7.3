#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sc_info.h"
#include "utilities.h"

#include "sys_config.h"

/*
	error_code sys_config_open(u32 equeue_id, vm::ptr<u32> config_id);
	error_code sys_config_close(u32 equeue_id);
	error_code sys_config_register_service(ppu_thread& ppu, u32 config_id, s64 b, u32 c, u32 d, vm::ptr<u32> data, u32 size, vm::ptr<u32> output);
	error_code sys_config_add_service_listener(u32 config_id, s64 id, u32 c, u32 d, u32 unk, u32 f, vm::ptr<u32> service_listener_handle);
	error_code sys_config_get_service_event(u32 config_id, u32 event_id, vm::ptr<void> event, u64 size);
*/

SCI_CB_DUMP_BUFFER(sys_config_get_service_event, 3, 4)


int sc_sys_config_init(void) {
	SCI_CREATE_GROUP(sys_config, SCT_DEFAULT);

	SCI_FROM_NAME(sys_config_open)
	sys_config_open->nargs = 2;
	sys_config_open->arg_fmt[0] = "equeue_id=0x%lx";
	sys_config_open->arg_fmt[1] = "config_id=*0x%lx";

	SCI_FROM_NAME(sys_config_close)
	sys_config_close->nargs = 1;
	sys_config_close->arg_fmt[0] = "equeue_id=0x%lx";

	SCI_FROM_NAME(sys_config_register_service)
	sys_config_register_service->nargs = 7;
	sys_config_register_service->arg_fmt[0] = "config_id=0x%lx";
	sys_config_register_service->arg_fmt[1] = "b=0x%lx";
	sys_config_register_service->arg_fmt[2] = "c=0x%lx";
	sys_config_register_service->arg_fmt[3] = "d=0x%lx";
	sys_config_register_service->arg_fmt[4] = "data=*0x%lx";
	sys_config_register_service->arg_fmt[5] = "size=%ld";
	sys_config_register_service->arg_fmt[6] = "output=*0x%lx";

	SCI_FROM_NAME(sys_config_add_service_listener)
	sys_config_add_service_listener->nargs = 7;
	sys_config_add_service_listener->arg_fmt[0] = "config_id=0x%lx";
	sys_config_add_service_listener->arg_fmt[1] = "id=0x%lx";
	sys_config_add_service_listener->arg_fmt[2] = "c=0x%lx";
	sys_config_add_service_listener->arg_fmt[3] = "d=0x%lx";
	sys_config_add_service_listener->arg_fmt[4] = "unk=0x%lx";
	sys_config_add_service_listener->arg_fmt[5] = "f=0x%lx";
	sys_config_add_service_listener->arg_fmt[6] = "handle=*0x%lx";

	SCI_FROM_NAME(sys_config_get_service_event)
	SCI_REGISTER_CBS(sys_config_get_service_event)
	sys_config_get_service_event->nargs = 4;
	sys_config_get_service_event->arg_fmt[0] = "config_id=0x%lx";
	sys_config_get_service_event->arg_fmt[1] = "event_id=0x%lx";
	sys_config_get_service_event->arg_fmt[2] = "event=*0x%lx";
	sys_config_get_service_event->arg_fmt[3] = "size=%ld";
	sys_config_get_service_event->trace = SCT_TRACE_POST;

	return 0;
}
