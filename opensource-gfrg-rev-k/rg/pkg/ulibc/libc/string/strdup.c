/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include "_string.h"
#include <stdlib.h>

#ifdef WANT_WIDE
libc_hidden_proto(wcslen)
# define Wstrdup wcsdup
# define Wstrlen wcslen
#else
libc_hidden_proto(strdup)
libc_hidden_proto(strlen)
# define Wstrdup strdup
# define Wstrlen strlen
#endif
libc_hidden_proto(memcpy)

Wchar *Wstrdup(register const Wchar *s1)
{
#ifdef __CONFIG_RG_DBG_ULIBC_MALLOC__
	void *alloc_ra = __builtin_return_address(0);
#endif
	register Wchar *s;
	register size_t l = (Wstrlen(s1) + 1) * sizeof(Wchar);

	if ((s = malloc(l)) != NULL) {
		memcpy(s, s1, l);
#ifdef __CONFIG_RG_DBG_ULIBC_MALLOC__
		mem_save_alloc_ra(s, alloc_ra);
#endif
	}

	return s;
}

#ifndef WANT_WIDE
libc_hidden_def(strdup)
#endif
