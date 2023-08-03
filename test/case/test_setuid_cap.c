/*
 * Copyright (c) 2021 Alibaba Group Holding Limited
 * Express UDP is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 *
 */

#include "lib.h"
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>


int main(int argc, char **argv)
{
	struct libconf libconf = {};
	char *keep_cap;
	int pid;

	keep_cap = getenv("keep_cap");

	if (keep_cap && *keep_cap == '1')
		libconf.conf.keep_cap = true;

	libconf.conf.group_num     = 10;
	libconf.conf.force_xdp     = true;
	libconf.conf.isolate_group = true;

	libconf.conf.map_dict_n    = 10;
	libconf.fork               = 1;
	libconf.fork_loop          = 1;

	/* setuid to nobody */
	libconf.nobody             = 1;

	stdmain(&libconf);

	return 0;
}
