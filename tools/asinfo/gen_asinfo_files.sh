#!/bin/sh
#
# Code generator simplifies addition of new architecture to asinfo tool
#
# Copyright (c) 2017 Edgar A. Kaziakhmedov <edgar.kaziakhmedov@virtuozzo.com>
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

cur_pers=""

gen_pers_line()
{
	local out_file="$1"
	local line="$2"
	local arch_abi=""

	LC_COLLATE=C
	arch_abi="$(printf %s "${line}" |
		    sed 's/ARCH_DESC_DEFINE(//' | cut -d, -f 1,2 |
		    sed 's/,/_/g')"
	cur_pers="${arch_abi}"
	echo "ARCH_${arch_abi}," >> "${out_file}"
}

gen_includes_block()
{
	local out_file="$1"
	local line="$2"
	local def is_def includes include nums num count

	(
	LC_COLLATE=C
	echo "/* ${cur_pers} */"
	def="$(printf %s "${line#*\*}" | cut -d] -f 1 | sed 's/.*[][]//g')"
	#Generate define construction
	if [ "${def#!}" != "" ] && [ $(printf %.1s "${def}") = "!" ]; then
		cat <<-EOF
		#ifdef ${def#!}
		# undef ${def#!}
		# define ${def#!}_DUMMY_UNDEFINE
		#endif
		EOF
		is_def="def"
	else if [ "${def#!}" != "" ]; then
		cat <<-EOF
		#ifndef ${def}
		# define ${def}
		# define ${def}_DUMMY_DEFINE
		#endif
		EOF
		is_def="undef"
	fi
	fi
	#Generate includes
	includes="$(printf %s "${line#*\*}" | cut -d] -f 2 | sed 's/.*[][]//g')"
	echo "static const struct_sysent ${cur_pers}_sysent[] = {"
	for include in $(echo "${includes}" | sed "s/,/ /g")
	do
		echo "	#include \"${include}\""
	done
	echo "};"
	#Undefine definitions, if it is required
	if [ "${is_def}" = "def" ]; then
		cat <<-EOF
		#ifdef ${def#!}_DUMMY_UNDEFINE
		# define ${def#!} 1
		# undef ${def#!}_DUMMY_UNDEFINE
		#endif
		EOF
	else if [ "${is_def}" = "undef" ]; then
		cat <<-EOF
		#ifdef ${def#!}_DUMMY_DEFINE
		# undef ${def#!}
		# undef ${def#!}_DUMMY_DEFINE
		#endif
		EOF
	fi
	fi
	#Generate arch specific numbers
	nums="$(printf %s "${line#*\*}" | cut -d] -f 3 | sed 's/.*[][]//g')"
	count=1
	for num in $(echo "${nums}" | sed "s/,/ /g")
	do
		echo "static const int ${cur_pers}_usr${count} = ${num};"
		count=$((count+1))
		case "${num}" in
		*[A-Za-z_]*) echo "#undef ${num}" ;;
		*) ;;
		esac
	done
	if [ $count -eq 1 ]; then
		echo "static const int ${cur_pers}_usr${count} = 0;"
	fi
	echo "#undef SYS_socket_subcall"
	) >> "${out_file}"
	echo "${def}" >> "${out_file}"
}

main()
{
	set -- "${0%/*}" "${0%/*}"

	local input="$1"
	local output="$2"
	local defs_file="arch_definitions.h"
	local pers_file="arch_personalities.h"
	local includes_file="arch_includes.h"
	local pline=""

	echo "ARCH_no_pers," > "${output}/${pers_file}"
	echo -n > "${output}/${includes_file}"

	#Main work
	while read line; do
		line="$(printf %s "${line}" | sed 's/[[:space:]]//g')"
		if $(printf %s "${line}" |
		     grep -F "ARCH_DESC_DEFINE" > /dev/null); then
			gen_pers_line "${output}/${pers_file}" "${line}"
		fi
		if $(printf %s "${pline}" | grep -F "/*" > /dev/null); then
			gen_includes_block "${output}/${includes_file}"\
					   "${pline}"
		fi
		pline="${line}"
	done < "${input}/${defs_file}"
	#Makemodule.am
	(
	printf \
"ARCH_AUX_FILES = ${includes_file} ${pers_file}\n\
\$(top_srcdir)/tools/asinfo/${includes_file}: \
\$(top_srcdir)/tools/asinfo/${defs_file} \
\$(top_srcdir)/tools/asinfo/gen_asinfo_files.sh\n\
	\$(AM_V_GEN)\$(top_srcdir)/tools/asinfo/gen_asinfo_files.sh\n\
\$(top_srcdir)/tools/asinfo/${pers_file}: \
\$(top_srcdir)/tools/asinfo/${defs_file} \
\$(top_srcdir)/tools/asinfo/gen_asinfo_files.sh\n\
	\$(AM_V_GEN)\$(top_srcdir)/tools/asinfo/gen_asinfo_files.sh"
	) > "${output}/Makemodule.am"
	#.gitignore
	(
	printf \
"/${includes_file}\n\
/${pers_file}\n\
/Makemodule.am\n\
/.gitignore\n\
/asinfo.1"
	) > "${output}/.gitignore"
}

main "$@"
