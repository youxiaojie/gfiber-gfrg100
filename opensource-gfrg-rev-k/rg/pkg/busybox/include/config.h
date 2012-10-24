#include <rg_config.h>

/* Version Number */
#define BB_VER "1.01"
#define BB_BT "2005.09.07-07:38+0000"

#define HAVE_DOT_CONFIG 1

/*
 * General Configuration
 */
#define CONFIG_FEATURE_BUFFERS_USE_MALLOC 1
#undef CONFIG_FEATURE_BUFFERS_GO_ON_STACK
#undef CONFIG_FEATURE_BUFFERS_GO_IN_BSS
#define CONFIG_FEATURE_VERBOSE_USAGE 1
#undef CONFIG_FEATURE_INSTALLER
#undef CONFIG_LOCALE_SUPPORT
#undef CONFIG_FEATURE_DEVFS
#undef CONFIG_FEATURE_DEVPTS
#define CONFIG_FEATURE_CLEAN_UP 1
#undef CONFIG_FEATURE_SUID
#undef CONFIG_SELINUX

/*
 * Build Options
 */
#undef CONFIG_STATIC
#ifdef CONFIG_RG_LARGE_FILE_SUPPORT
#define CONFIG_LFS 1
#endif
#undef USING_CROSS_COMPILER
#define EXTRA_CFLAGS_OPTIONS ""

/*
 * Installation Options
 */
#undef CONFIG_INSTALL_NO_USR
#define PREFIX "./_install"

/*
 * Archival Utilities
 */
#undef CONFIG_AR
#undef CONFIG_BUNZIP2
#undef CONFIG_CPIO
#undef CONFIG_DPKG_DEB
#ifdef CONFIG_RG_DPKG
#define CONFIG_DPKG 1
#define CONFIG_FEATURE_DEB_TAR_GZ 1
#endif
#if defined(CONFIG_RG_DOCSIS)||defined(CONFIG_RG_DPKG)
#define CONFIG_GUNZIP 1
#endif
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_GZIP 1
#endif
#undef CONFIG_RPM2CPIO
#undef CONFIG_RPM
#if defined(CONFIG_RG_DOCSIS)||defined(CONFIG_RG_DPKG)
#define CONFIG_TAR 1
#endif
#undef CONFIG_UNCOMPRESS
#undef CONFIG_UNZIP

/*
 * Coreutils
 */

#ifndef CONFIG_RG_RGLOADER
#undef CONFIG_BASENAME
#undef CONFIG_CAL
#define CONFIG_CAT 1
#define CONFIG_CHGRP 1
#define CONFIG_CHMOD 1
#define CONFIG_CHOWN 1
#undef CONFIG_CHROOT
#undef CONFIG_CMP
#define CONFIG_CP 1
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_CUT 1
#endif
#undef CONFIG_DATE
#define CONFIG_DD 1
#define CONFIG_DF 1
#undef CONFIG_DIRNAME
#undef CONFIG_DOS2UNIX
#undef CONFIG_DU
#define CONFIG_ECHO 1
#undef CONFIG_FEATURE_FANCY_ECHO
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_ENV 1
#define CONFIG_EXPR 1
#define CONFIG_FALSE 1
#endif
#undef CONFIG_FOLD
#undef CONFIG_HEAD
#undef CONFIG_HOSTID
#undef CONFIG_ID
#undef CONFIG_INSTALL
#undef CONFIG_LENGTH
#define CONFIG_LN 1
#undef CONFIG_LOGNAME
#define CONFIG_LS 1
#define CONFIG_FEATURE_LS_FILETYPES 1
#define CONFIG_FEATURE_LS_FOLLOWLINKS 1
#define CONFIG_FEATURE_LS_RECURSIVE 1
#define CONFIG_FEATURE_LS_SORTFILES 1
#define CONFIG_FEATURE_LS_TIMESTAMPS 1
#define CONFIG_FEATURE_LS_USERNAME 1
#undef CONFIG_FEATURE_LS_COLOR
#undef CONFIG_MD5SUM
#define CONFIG_MKDIR 1
#undef CONFIG_MKFIFO
#define CONFIG_MKNOD 1
#define CONFIG_MV 1
#undef CONFIG_OD
#undef CONFIG_PRINTF
#undef CONFIG_PWD
#undef CONFIG_REALPATH
#define CONFIG_RM 1
#define CONFIG_RMDIR 1
#undef CONFIG_SEQ
#undef CONFIG_SHA1SUM
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_SLEEP 1
#endif
#define CONFIG_SORT 1
#define CONFIG_STTY 1
#define CONFIG_SYNC 1
#undef CONFIG_TAIL
#undef CONFIG_TEE
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_TEST 1
#define CONFIG_TOUCH 1
#define CONFIG_TR 1
#define CONFIG_TRUE 1
#endif
#undef CONFIG_TTY
#undef CONFIG_UNAME
#undef CONFIG_UNIQ
#undef CONFIG_USLEEP
#undef CONFIG_UUDECODE
#undef CONFIG_UUENCODE
#undef CONFIG_WATCH
#undef CONFIG_WC
#undef CONFIG_WHO
#undef CONFIG_WHOAMI
#undef CONFIG_YES

/*
 * Common options for cp and mv
 */
#undef CONFIG_FEATURE_PRESERVE_HARDLINKS

/*
 * Common options for ls and more
 */
#define CONFIG_FEATURE_AUTOWIDTH 1

/*
 * Common options for df, du, ls
 */
#define CONFIG_FEATURE_HUMAN_READABLE 1

/*
 * Console Utilities
 */
#undef CONFIG_CHVT
#undef CONFIG_CLEAR
#undef CONFIG_DEALLOCVT
#undef CONFIG_DUMPKMAP
#undef CONFIG_LOADFONT
#undef CONFIG_LOADKMAP
#undef CONFIG_OPENVT
#undef CONFIG_RESET
#undef CONFIG_SETKEYCODES

/*
 * Debian Utilities
 */
#undef CONFIG_MKTEMP
#undef CONFIG_PIPE_PROGRESS
#undef CONFIG_READLINK
#undef CONFIG_RUN_PARTS
#undef CONFIG_START_STOP_DAEMON
#undef CONFIG_WHICH

/*
 * Editors
 */
#undef CONFIG_AWK
#undef CONFIG_PATCH
#undef CONFIG_SED
#undef CONFIG_VI

/*
 * Finding Utilities
 */
#undef CONFIG_FIND
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_GREP 1
#endif
#undef CONFIG_XARGS

#endif   /*end of ifndef CONFIG_RG_RGLOADER */

/*
 * Init Utilities
 */
#if defined(CONFIG_OPENRG) || defined (CONFIG_RG_RGLOADER)
  #undef CONFIG_INIT
  #undef CONFIG_FEATURE_USE_INITTAB
#else
  #define CONFIG_INIT
  #define CONFIG_FEATURE_USE_INITTAB
#endif 
#undef CONFIG_HALT
#undef CONFIG_POWEROFF
#if defined(CONFIG_OPENRG) || defined (CONFIG_RG_RGLOADER)
  #undef CONFIG_REBOOT
#else
  #define CONFIG_REBOOT
#endif 
#undef CONFIG_MESG

/*
 * Login/Password Management Utilities
 */
#undef CONFIG_USE_BB_PWD_GRP
#undef CONFIG_ADDGROUP
#undef CONFIG_DELGROUP
#undef CONFIG_ADDUSER
#undef CONFIG_DELUSER
#undef CONFIG_GETTY
#undef CONFIG_LOGIN
#undef CONFIG_PASSWD
#undef CONFIG_SU
#undef CONFIG_SULOGIN
#undef CONFIG_VLOCK

/*
 * Miscellaneous Utilities
 */
#undef CONFIG_ADJTIMEX
#undef CONFIG_CROND
#undef CONFIG_CRONTAB
#undef CONFIG_DC
#undef CONFIG_DEVFSD
#undef CONFIG_LAST
#undef CONFIG_HDPARM
#undef CONFIG_MAKEDEVS
#undef CONFIG_MT
#undef CONFIG_RX
#undef CONFIG_STRINGS
#undef CONFIG_TIME
#undef CONFIG_WATCHDOG

/*
 * Linux Module Utilities
 */
#define CONFIG_INSMOD 1
#ifdef CONFIG_RG_OS_LINUX_26
#define CONFIG_FEATURE_2_6_MODULES 1
#undef CONFIG_FEATURE_2_4_MODULES
#else
#define CONFIG_FEATURE_2_4_MODULES 1
#undef CONFIG_FEATURE_2_6_MODULES
#endif

#undef CONFIG_FEATURE_INSMOD_VERSION_CHECKING
#undef CONFIG_FEATURE_INSMOD_KSYMOOPS_SYMBOLS
#undef CONFIG_FEATURE_INSMOD_LOADINKMEM
#undef CONFIG_FEATURE_INSMOD_LOAD_MAP
#define CONFIG_LSMOD 1
#undef CONFIG_MODPROBE
#define CONFIG_RMMOD 1
#undef CONFIG_FEATURE_CHECK_TAINTED_MODULE
#ifdef CONFIG_FEATURE_2_6_MODULES
#undef CONFIG_FEATURE_QUERY_MODULE_INTERFACE
#else
#define CONFIG_FEATURE_QUERY_MODULE_INTERFACE 1
#endif

/*
 * Networking Utilities
 */

#ifndef CONFIG_RG_RGLOADER

#ifdef CONFIG_RG_IPV6
#define CONFIG_FEATURE_IPV6 1
#endif
#undef CONFIG_ARPING
#undef CONFIG_FTPGET
#undef CONFIG_FTPPUT
#undef CONFIG_HOSTNAME
#undef CONFIG_HTTPD
#define CONFIG_IFCONFIG 1
#define CONFIG_FEATURE_IFCONFIG_STATUS 1
#undef CONFIG_FEATURE_IFCONFIG_SLIP
#define CONFIG_FEATURE_IFCONFIG_MEMSTART_IOADDR_IRQ 1
#define CONFIG_FEATURE_IFCONFIG_HW 1
#undef CONFIG_FEATURE_IFCONFIG_BROADCAST_PLUS
#undef CONFIG_IFUPDOWN
#undef CONFIG_INETD
#undef CONFIG_IP
#undef CONFIG_IPCALC
#undef CONFIG_IPADDR
#undef CONFIG_IPLINK
#undef CONFIG_IPROUTE
#undef CONFIG_IPTUNNEL
#undef CONFIG_NAMEIF
#ifdef CONFIG_RG_DOCSIS
#define  CONFIG_NC 1
#endif
#undef CONFIG_NETSTAT
#undef CONFIG_NSLOOKUP
#define CONFIG_PING 1
#ifdef CONFIG_RG_IPV6
#define CONFIG_PING6 1
#endif
#ifdef CONFIG_RG_SPEED_TEST
#define CONFIG_FEATURE_FANCY_PING
#endif
#define CONFIG_ROUTE 1
#undef CONFIG_TELNET
#undef CONFIG_TELNETD
#define CONFIG_TFTP 1
#define CONFIG_FEATURE_TFTP_GET 1
#define CONFIG_FEATURE_TFTP_PUT 1
#undef CONFIG_FEATURE_TFTP_BLOCKSIZE
#undef CONFIG_FEATURE_TFTP_DEBUG
#undef CONFIG_TRACEROUTE
#undef CONFIG_VCONFIG
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_WGET 1
#endif

/*
 * udhcp Server/Client
 */
#undef CONFIG_UDHCPD
#undef CONFIG_UDHCPC

/*
 * Process Utilities
 */
#define CONFIG_FREE 1
#define CONFIG_KILL 1
#define CONFIG_KILLALL 1
#undef CONFIG_PIDOF
#define CONFIG_PS 1
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_RENICE 1
#endif

#ifndef CONFIG_RG_RGLOADER
  #define CONFIG_TOP 1
  #define FEATURE_CPU_USAGE_PERCENTAGE 1
#endif
#define CONFIG_UPTIME 1

/*
 * Another Bourne-like Shell
 */
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_FEATURE_SH_IS_MSH 1
#undef CONFIG_FEATURE_SH_IS_LASH
#else
#define CONFIG_FEATURE_SH_IS_LASH 1
#undef CONFIG_FEATURE_SH_IS_MSH
#endif
#undef CONFIG_FEATURE_SH_IS_ASH
#undef CONFIG_FEATURE_SH_IS_HUSH
#undef CONFIG_FEATURE_SH_IS_NONE
#ifdef CONFIG_RG_DOCSIS
#define CONFIG_MSH 1
#undef CONFIG_LASH
#else
#undef CONFIG_MSH
#define CONFIG_LASH 1
#endif
#undef CONFIG_ASH
#undef CONFIG_HUSH
#define CONFIG_FEATURE_COMMAND_EDITING 1
#define CONFIG_FEATURE_COMMAND_HISTORY 64
#define CONFIG_FEATURE_COMMAND_TAB_COMPLETION 1

/*
 * System Logging Utilities
 */
#undef CONFIG_SYSLOGD
#undef CONFIG_LOGGER

/*
 * Linux System Utilities
 */
#undef CONFIG_DMESG
#undef CONFIG_FBSET
#undef CONFIG_FDFLUSH
#undef CONFIG_FDFORMAT
#undef CONFIG_FDISK
#undef CONFIG_FREERAMDISK
#undef CONFIG_FSCK_MINIX
#undef CONFIG_MKFS_MINIX
#undef CONFIG_GETOPT
#undef CONFIG_HEXDUMP
#undef CONFIG_HWCLOCK
#ifdef CONFIG_BLK_DEV_LOOP
  #define CONFIG_LOSETUP 1
#endif
#define CONFIG_MKSWAP 1
#undef CONFIG_MORE
#undef CONFIG_PIVOT_ROOT
#undef CONFIG_RDATE
#define CONFIG_SWAPONOFF 1
#define CONFIG_MOUNT 1
#ifdef CONFIG_NFS_FS
#define CONFIG_NFSMOUNT 1
#else
#undef CONFIG_NFSMOUNT
#endif
#define CONFIG_UMOUNT 1
#define CONFIG_FEATURE_MOUNT_FORCE 1

/*
 * Common options for mount/umount
 */
#define CONFIG_FEATURE_MOUNT_LOOP 1

#endif  /* endif for ifndef CONFIG_RG_RGLOADER */

/* 
#define CONFIG_FEATURE_MTAB_SUPPORT 1
#define CONFIG_FEATURE_MTAB_FILENAME "/etc/mtab"
*/

/*
 * Debugging Options
 */
#undef CONFIG_DEBUG
