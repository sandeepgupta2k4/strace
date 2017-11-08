# Automake input for asinfo tests.
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

OS = linux
AM_COLOR_TESTS = always
AM_CFLAGS = $(WARN_CFLAGS)
AM_CPPFLAGS = $(ARCH_MFLAGS) \
	      -I$(builddir) \
	      -I$(builddir)/.. \
	      -I$(top_builddir) \
	      -I$(top_srcdir)
AM_LDFLAGS = $(ARCH_MFLAGS)

check_PROGRAMS = set_arch set_mult_arch list_arch set_abi set_mult_abi \
		 get_arch_abi get_sname get_snum com_disp_wrong_keys \
		 multiarch_get_sname multiarch_get_snum format_output
TESTS = set_arch.test set_mult_arch.test list_arch.test set_abi.test \
	set_mult_abi.test get_arch_abi.test get_sname.test get_snum.test \
	com_disp_wrong_keys.test multiarch_get_sname.test \
	multiarch_get_snum.test format_output.test

set_arch_SOURCES = set_arch.c
set_mult_arch_SOURCES = set_mult_arch.c
list_arch_SOURCES = list_arch.c
set_abi_SOURCES = set_abi.c
set_mult_abi_SOURCES = set_mult_abi.c
get_arch_abi_SOURCES = get_arch_abi.c
get_sname_SOURCES = get_sname.c
get_snum_SOURCES = get_snum.c
com_disp_wrong_keys_SOURCES = com_disp_wrong_keys.c
multiarch_get_sname_SOURCES = multiarch_get_sname.c
multiarch_get_snum_SOURCES = multiarch_get_snum.c
format_output_SOURCES = format_output.c

EXTRA_DIST = $(TESTS) init.sh ref_asinfo_output.h

clean-local: clean-local-check
.PHONY: clean-local-check
clean-local-check:
	-rm -rf -- $(TESTS:.test=.dir)
