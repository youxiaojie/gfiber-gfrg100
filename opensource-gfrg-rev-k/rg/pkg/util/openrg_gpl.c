/****************************************************************************
 *
 * rg/pkg/util/openrg_gpl.c * 
 * 
 * Modifications by Jungo Ltd. Copyright (C) 2008 Jungo Ltd.  
 * All Rights reserved. 
 * 
 * This program is free software; 
 * you can redistribute it and/or modify it under 
 * the terms of the GNU General Public License version 2 as published by 
 * the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty 
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the GNU General Public License v2 for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. 
 * If not, write to the Free Software Foundation, 
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA, 
 * or contact Jungo Ltd. 
 * at http://www.jungo.com/openrg/opensource_ack.html
 * 
 * 
 * 
 */

#include <rg_config.h>
#ifdef CONFIG_GLIBC
#include <syslog/glibc/ulibc_syslog.h>
#endif
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/if.h>

#include "openrg_gpl.h"
#include <util/rg_error_syslog.h>
#include <util/rg_error.h>
#include <util/rg_openlog.h>

void sys_sleep(unsigned int seconds)
{
    sleep(seconds);
}

void socket_close(int fd)
{
    close(fd);
}

/* normally should be called with src_ip==0 and src_port==0 */
int sock_socket(int type, u32 src_ip, u16 src_port)
{
    int sock = -1;
    struct sockaddr_in sa;

    if ((sock = socket(AF_INET, type, 0))<0)
	return rg_error(LERR, "sock_socket: failed socket()");
    MZERO(sa);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = src_ip;
    sa.sin_port = src_port; 
    if (src_port)
    {
	int opt = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, 
	    (void *)&opt, sizeof(opt))<0)
	{
	    rg_error(LERR, "sock_socket: failed setsockopt(SO_REUSEADDR)");
	    goto Error;
	}
	if ((bind(sock, (struct sockaddr *)&sa, sizeof(sa)))<0)
	{
	    rg_error(LERR, "sock_socket: failed bind(): %s", strerror(errno));
	    goto Error;
	}
    }
    else
    {
	if ((bind(sock, (struct sockaddr *)&sa, sizeof(sa)))<0)
	{
	    rg_error(LERR, "sock_socket: failed bind()");
	    goto Error;
	}
    }
    
    rg_error(LDEBUG, "sock_socket: created fd %d for ip %s port %d", sock,
	inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    return sock;
    
Error:
    if (sock>=0)
	close(sock);
    return -1;
}

static void rg_reboot(void)
{
    rg_error(LINFO, "rebooting!");

#ifdef HAVE_KILL
    /* signal the init process (openrg or init) to reboot. */
    kill(1, SIGINT);
#else
    /* This code generates three types of exception: 
     * division by 0 - handled by FPU/Emulator, 
     * unaligned access (float at wrong alignment) - for non-MMU out there
     * segmentation  - 1 is not legal at most MMU platforms.
     */
    *(float *)1 = 1 / 0.0;
#endif
}

int rg_error_full(int entity_id, rg_error_level_t severity,
    const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = rg_vsyslog(entity_id, severity, rg_reboot, format, ap);
    va_end(ap);

    return ret;
}

#define RG_IOCTL_PREFIX_BASE 0xD0
#define RG_IOCTL_PREFIX_KOS (RG_IOCTL_PREFIX_BASE + 8)
#define RG_IOCTL_SIOCSETRGCHRDEVTYPE \
    _IOW(RG_IOCTL_PREFIX_KOS, 3, struct ifreq)

int gpl_sys_rg_chrdev_open(int type, int mode)
{
    int fd = open("/dev/rg_chrdev", mode, 0);

    if (fd < 0)
    {
	rg_error(LERR, "Cannot open /dev/rg_chrdev %d %m", type);
	return fd;
    }

    if (ioctl(fd, RG_IOCTL_SIOCSETRGCHRDEVTYPE, type))
	return rg_error(LERR, "Cannot open /dev/rg_chrdev %d %m", type);

    return fd;
}

