/*
 * This source code is a part of coLinux source package.
 *
 * Dan Aloni <da-x@colinux.org>, 2004 (c)
 *
 * The code is licensed under the GPL. See the COPYING file at
 * the root directory.
 *
 */

#include "linux_inc.h"

#include <colinux/common/version.h>

#include "manager.h"

co_manager_t *global_manager = NULL;

static int __init test_module_init(void)
{
	printk("colinux: module loaded (%s, %s)\n", COLINUX_VERSION, COLINUX_COMPILE_TIME);

	global_manager = co_os_malloc(sizeof(co_manager_t));
	if (global_manager == NULL) {
		printk("colinux: allocation error\n");
		return -1;
	}

	co_manager_load(global_manager);

	return 0;
}

static void __exit test_module_exit(void)
{
	if (global_manager != NULL) {
		co_manager_unload(global_manager);
		co_os_free(global_manager);
	}

	printk("colinux: module unloaded\n");
}

MODULE_LICENSE("GPL");
module_init(test_module_init);
module_exit(test_module_exit);
