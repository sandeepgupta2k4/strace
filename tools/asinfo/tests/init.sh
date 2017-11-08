#!/bin/sh
#
# Copyright (c) 2011-2017 The strace developers.
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

ME_="${0##*/}"
LOG="log"
OUT="out"
EXP="exp"
ASINFO="../../asinfo"

fail_() { warn_ "$ME_: failed test: $*"; exit 1; }
warn_() { printf >&2 '%s\n' "$*"; }

run_prog()
{
	if [ $# -eq 0 ]; then
		set -- "../$NAME"
	fi
	args="$*"
	"$@" || {
		rc=$?
		if [ $rc != 0 ]; then
			fail_ "$args failed with code $rc"
		fi
	}
}


dump_log_and_fail_with()
{
	cat < "$LOG" >&2
	fail_ "$*"
}

run_asinfo()
{
	args="$*"
	$ASINFO "$@" 2>&1
}

match_diff()
{
	local output expected error
	if [ $# -eq 0 ]; then
		output="$LOG"
	else
		output="$1"; shift
	fi
	if [ $# -eq 0 ]; then
		expected="$srcdir/$NAME.expected"
	else
		expected="$1"; shift
	fi
	if [ $# -eq 0 ]; then
		error="$STRACE $args output mismatch"
	else
		error="$1"; shift
	fi

	diff -u -- "$expected" "$output" ||
		fail_ "$error"
}

NAME="${ME_%.test}"
TESTDIR="$NAME.dir"
rm -rf -- "$TESTDIR"
mkdir -- "$TESTDIR"
cd "$TESTDIR"
case "$srcdir" in
	/*) ;;
	*) srcdir="../$srcdir" ;;
esac
