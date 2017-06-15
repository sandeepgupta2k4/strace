/*
 * As each dispatcher has a wide range of possible errors, there is need
 * use separate and basic error interface.
 *
 * Copyright (c) 2017 Edgar A. Kaziakhmedov <edgar.kaziakhmedov@virtuozzo.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ASINFO_ERROR_INTERFACE_H
#define ASINFO_ERROR_INTERFACE_H

/* errors which using last_arch */
enum error_arch {
	NO_ERROR_BIT,
	AD_UNSUP_ARCH_BIT = 1,
	ABI_CANNOT_DETECT_BIT,

	ERROR_ARCH_LAST
};

enum error_no_arg {
	SD_NO_MATCHES_FND_BIT = ERROR_ARCH_LAST,

	ERROR_NO_ARG_LAST
};

enum error_arch_abi {
	ABI_WRONG4ARCH_BIT = ERROR_NO_ARG_LAST,

	ERROR_ARCH_ABI_LAST
};

#define ENUM_FLAG(name) name = name##_BIT
enum common_error {
	ENUM_FLAG(NO_ERROR),
	/* arch dispatcher range */
	ENUM_FLAG(AD_UNSUP_ARCH),
	/* abi dipatcher range */
	ENUM_FLAG(ABI_CANNOT_DETECT),
	ENUM_FLAG(ABI_WRONG4ARCH),
	/* syscall dispatcher range */
	ENUM_FLAG(SD_NO_MATCHES_FND)
};
#undef ENUM_FLAG

#define BITMASK(hi, lo) ((1 << (hi)) - (1 << (lo)))
#define ERROR_ARCH_MASK  BITMASK(ERROR_ARCH_LAST, 0)
#define ERROR_NO_ARG_MASK BITMASK(ERROR_NO_ARG_LAST, ERROR_ARCH_LAST)
#define ERROR_ARCH_ABI_MASK BITMASK(ERROR_ARCH_ABI_LAST, ERROR_NO_ARG_LAST)

#define ERROR_MSG_MAX_LEN 255

struct error_service {
	char string[ERROR_MSG_MAX_LEN];
	enum common_error last_error;
	char *last_arch;
	char *last_abi;
	char *last_sc;
};

struct error_service *es_create(void);

enum common_error es_error(struct error_service *s);

void es_set_error(struct error_service *s, enum common_error se);

void es_set_option(struct error_service *e, char *arch, char *abi, char *sc);

const char *es_get_serror(struct error_service *e);

void es_free(struct error_service *e);

#endif /* !ASINFO_ERROR_INTERFACE_H */
