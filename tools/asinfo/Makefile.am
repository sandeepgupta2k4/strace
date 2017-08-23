# Automake input for asinfo.
#
# Copyright (c) 2017 Edgar Kaziakhmedov <edgar.kaziakhmedov@virtuozzo.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

bin_PROGRAMS = asinfo
man_MANS = asinfo.1

OS = linux

AUTOMAKE_OPTIONS = subdir-objects

AM_CFLAGS = $(WARN_CFLAGS)
AM_CPPFLAGS = -I$(builddir) \
	      -I$(top_builddir)/$(OS) \
	      -I$(top_srcdir)/$(OS) \
	      -I$(top_builddir) \
	      -I$(top_srcdir)

include Makemodule.am

asinfo_CPPFLAGS = $(AM_CPPFLAGS)
asinfo_CFLAGS = $(AM_CFLAGS)

asinfo_SOURCES =		\
	arch_definitions.h	\
	arch_interface.c	\
	$(ARCH_AUX_FILES)	\
	arch_interface.h	\
	asinfo.c		\
	../../basic_filters.c	\
	dispatchers.c		\
	dispatchers.h		\
	error_interface.c	\
	error_interface.h	\
	../../error_prints.c	\
	../../error_prints.h	\
	../../filter.h		\
	../../macros.h		\
	../../number_set.c	\
	../../number_set.h	\
	request_msgs.h		\
	../../string_to_uint.h	\
	../../string_to_uint.c	\
	syscall_interface.c	\
	syscall_interface.h	\
	../../sysent_shorthand_defs.h \
	../../sysent_shorthand_undefs.h \
	../../xmalloc.c		\
	../../xmalloc.h		\
	#end of asinfo_SOURCES
