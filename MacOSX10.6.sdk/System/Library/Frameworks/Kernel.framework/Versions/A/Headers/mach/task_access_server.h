#ifndef	_task_access_server_
#define	_task_access_server_

/* Module task_access */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry   *function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	task_access_MSG_COUNT
#define	task_access_MSG_COUNT	2
#endif	/* task_access_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>

#ifdef __BeforeMigServerHeader
__BeforeMigServerHeader
#endif /* __BeforeMigServerHeader */


/* Routine check_task_access */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t check_task_access
(
	mach_port_t task_access_port,
	int32_t calling_pid,
	uint32_t calling_gid,
	int32_t target_pid,
	audit_token_t caller_cred
);

/* Routine find_code_signature */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t find_code_signature
(
	mach_port_t task_access_port,
	int32_t new_pid
);

extern boolean_t task_access_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

extern mig_routine_t task_access_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
extern const struct task_access_subsystem {
	mig_server_routine_t	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[2];
} task_access_subsystem;

/* typedefs for all requests */

#ifndef __Request__task_access_subsystem__defined
#define __Request__task_access_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int32_t calling_pid;
		uint32_t calling_gid;
		int32_t target_pid;
	} __Request__check_task_access_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int32_t new_pid;
	} __Request__find_code_signature_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__task_access_subsystem__defined */


/* union of all requests */

#ifndef __RequestUnion__task_access_subsystem__defined
#define __RequestUnion__task_access_subsystem__defined
union __RequestUnion__task_access_subsystem {
	__Request__check_task_access_t Request_check_task_access;
	__Request__find_code_signature_t Request_find_code_signature;
};
#endif /* __RequestUnion__task_access_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__task_access_subsystem__defined
#define __Reply__task_access_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__check_task_access_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__find_code_signature_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__task_access_subsystem__defined */


/* union of all replies */

#ifndef __ReplyUnion__task_access_subsystem__defined
#define __ReplyUnion__task_access_subsystem__defined
union __ReplyUnion__task_access_subsystem {
	__Reply__check_task_access_t Reply_check_task_access;
	__Reply__find_code_signature_t Reply_find_code_signature;
};
#endif /* __RequestUnion__task_access_subsystem__defined */

#ifndef subsystem_to_name_map_task_access
#define subsystem_to_name_map_task_access \
    { "check_task_access", 27000 },\
    { "find_code_signature", 27001 }
#endif

#ifdef __AfterMigServerHeader
__AfterMigServerHeader
#endif /* __AfterMigServerHeader */

#endif	 /* _task_access_server_ */