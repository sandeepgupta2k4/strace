/* ARCH_blackfin */
static const struct_sysent blackfin_32bit_sysent[] = {
	#include "bfin/syscallent.h"
};
static const int blackfin_32bit_usr1 = 0;
const int blackfin_32bit_usr2 = 0;
/* ARCH_ia64 */
struct_sysent ia64_64bit_sysent[] = {
	#include "ia64/syscallent.h"
};
static const int ia64_64bit_usr1 = 0;
static const int ia64_64bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_m68k */
static const struct_sysent m68k_32bit_sysent[] = {
	#include "m68k/syscallent.h"
};
static const int m68k_32bit_usr1 = 0;
static const int m68k_32bit_usr2 = 0;
/* ARCH_sparc64 64bit ABI */
static const struct_sysent sparc64_64bit_sysent[] = {
	#include "sparc64/syscallent.h"
};
static const int sparc64_64bit_usr1 = 0;
static const int sparc64_64bit_usr2 = 0;
/* ARCH_sparc and 32bit ABI */
static const struct_sysent sparc_32bit_sysent[] = {
	#include "sparc/syscallent.h"
};
static const int sparc_32bit_usr1 = 0;
static const int sparc_32bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_metag */
static const struct_sysent metag_32bit_sysent[] = {
	#include "metag/syscallent.h"
};
static const int metag_32bit_usr1 = 0;
static const int metag_32bit_usr2 = 0;
/* ARCH_mips n64 ABI */
#ifndef LINUX_MIPSN64
# define LINUX_MIPSN64 1
# define NOW_DEFINED 1
#endif
static const struct_sysent mips64_n64_sysent[] = {
	#include "dummy.h"
	#include "mips/syscallent-compat.h"
	#include "mips/syscallent-n64.h"
};
#ifdef NOW_DEFINED
# undef LINUX_MIPSN32
# undef NOW_DEFINED
#endif
static const int mips64_n64_usr1 = 0;
static const int mips64_n64_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_mips n32 ABI */
#ifndef LINUX_MIPSN32
# define LINUX_MIPSN32 1
# define NOW_DEFINED 1
#endif
static const struct_sysent mips64_n32_sysent[] = {
	#include "dummy.h"
	#include "mips/syscallent-compat.h"
	#include "mips/syscallent-n32.h"
};
#ifdef NOW_DEFINED
# undef LINUX_MIPSN32
# undef NOW_DEFINED
#endif
static const int mips64_n32_usr1 = 0;
static const int mips64_n32_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_mips o32 ABI */
#ifndef LINUX_MIPSO32
# define LINUX_MIPSO32 1
# define NOW_DEFINED 1
#endif
static const struct_sysent mips_o32_sysent[] = {
	#include "dummy.h"
	#include "mips/syscallent-compat.h"
	#include "mips/syscallent-o32.h"
};
#ifdef NOW_DEFINED
# undef LINUX_MIPSO32
# undef NOW_DEFINED
#endif
static const int mips_o32_usr1 = 0;
static const int mips_o32_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_alpha */
static const struct_sysent alpha_64bit_sysent[] = {
	#include "alpha/syscallent.h"
};
static const int alpha_64bit_usr1 = 0;
static const int alpha_64bit_usr2 = 0;
/* ARCH_ppc64 64bit ABI */
static const struct_sysent ppc64_64bit_sysent[] = {
	#include "powerpc64/syscallent.h"
};
static const int ppc64_64bit_usr1 = 0;
static const int ppc64_64bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_ppc and 32bit */
static const struct_sysent ppc_32bit_sysent[] = {
	#include "powerpc/syscallent.h"
};
static const int ppc_32bit_usr1 = 0;
static const int ppc_32bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_aarch64 64bit ABI */
static const struct_sysent aarch64_64bit_sysent[] = {
	#include "aarch64/syscallent.h"
};
static const int aarch64_64bit_usr1 = 0;
static const int aarch64_64bit_usr2 = 0;
/* ARCH_arm OABI*/
#ifdef __ARM_EABI__
# undef __ARM_EABI__
# define NOW_UNDEFINED 1
#endif
static const struct_sysent arm_oabi_sysent[] = {
	#include "arm/syscallent.h"
};
static const int arm_oabi_usr1 = ARM_FIRST_SHUFFLED_SYSCALL;
static const int arm_oabi_usr2 = ARM_LAST_SPECIAL_SYSCALL;
#undef ARM_FIRST_SHUFFLED_SYSCALL
#undef ARM_LAST_SPECIAL_SYSCALL
#undef SYS_socket_subcall
#ifdef NOW_UNDEFINED
# define __ARM_EABI__ 1
# undef NOW_UNDEFINED
#endif
/* ARCH_arm EABI*/
#ifndef __ARM_EABI__
# define __ARM_EABI__ 1
# define NOW_DEFINED 1
#endif
static const struct_sysent arm_eabi_sysent[] = {
	#include "arm/syscallent.h"
};
static const int arm_eabi_usr1 = ARM_FIRST_SHUFFLED_SYSCALL;
static const int arm_eabi_usr2 = ARM_LAST_SPECIAL_SYSCALL;
#undef ARM_FIRST_SHUFFLED_SYSCALL
#undef ARM_LAST_SPECIAL_SYSCALL
#ifdef NOW_DEFINED
# undef __ARM_EABI__
# undef NOW_DEFINED
#endif
/* ARCH_avr32 */
static const struct_sysent avr32_32bit_sysent[] = {
	#include "avr32/syscallent.h"
};
static const int avr32_32bit_usr1 = 0;
static const int avr32_32bit_usr2 = 0;
/* ARCH_arc */
static const struct_sysent arc_32bit_sysent[] = {
	#include "arc/syscallent.h"
};
static const int arc_32bit_usr1 = 0;
static const int arc_32bit_usr2 = 0;
/* ARCH_s390x */
static const struct_sysent s390x_64bit_sysent[] = {
	#include "s390x/syscallent.h"
};
static const int s390x_64bit_usr1 = 0;
static const int s390x_64bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_s390 */
static const struct_sysent s390_32bit_sysent[] = {
	#include "s390/syscallent.h"
};
static const int s390_32bit_usr1 = 0;
static const int s390_32bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_hppa */
static const struct_sysent hppa_32bit_sysent[] = {
	#include "hppa/syscallent.h"
};
static const int hppa_32bit_usr1 = 0;
static const int hppa_32bit_usr2 = 0;
/* ARCH_sh64 */
static const struct_sysent sh64_64bit_sysent[] = {
	#include "sh64/syscallent.h"
};
static const int sh64_64bit_usr1 = 0;
static const int sh64_64bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_sh */
static const struct_sysent sh_32bit_sysent[] = {
	#include "sh/syscallent.h"
};
static const int sh_32bit_usr1 = 0;
static const int sh_32bit_usr2 = 0;
/* ARCH_x86_64 64bit ABI mode */
static const struct_sysent x86_64_64bit_sysent[] = {
	#include "x86_64/syscallent.h"
};
static const int x86_64_64bit_usr1 = 0;
static const int x86_64_64bit_usr2 = 0;
/* ARCH_x86_64 x32 ABI mode */
static const struct_sysent x86_64_x32_sysent[] = {
	#include "x86_64/syscallent2.h"
};
static const int x86_64_x32_usr1 = 0;
static const int x86_64_x32_usr2 = 0;
/* ARCH_x86 */
static const struct_sysent x86_32bit_sysent[] = {
	#include "i386/syscallent.h"
};
static const int x86_32bit_usr1 = 0;
static const int x86_32bit_usr2 = 0;
#undef SYS_socket_subcall
/* ARCH_tile 64bit ABI mode */
static const struct_sysent tile_64bit_sysent[] = {
	#include "tile/syscallent.h"
};
static const int tile_64bit_usr1 = 0;
static const int tile_64bit_usr2 = 0;
/* ARCH_tile 32bit ABI mode */
static const struct_sysent tile_32bit_sysent[] = {
	#include "tile/syscallent1.h"
};
static const int tile_32bit_usr1 = 0;
static const int tile_32bit_usr2 = 0;
/* ARCH_microblaze */
static const struct_sysent microblaze_32bit_sysent[] = {
	#include "microblaze/syscallent.h"
};
static const int microblaze_32bit_usr1 = 0;
static const int microblaze_32bit_usr2 = 0;
/* ARCH_nios2 */
static const struct_sysent nios2_32bit_sysent[] = {
	#include "nios2/syscallent.h"
};
static const int nios2_32bit_usr1 = 0;
static const int nios2_32bit_usr2 = 0;
/* ARCH_openrisc */
struct_sysent openrisc_32bit_sysent[] = {
	#include "or1k/syscallent.h"
};
static const int openrisc_32bit_usr1 = 0;
static const int openrisc_32bit_usr2 = 0;
/* ARCH_xtensa */
static const struct_sysent xtensa_32bit_sysent[] = {
	#include "xtensa/syscallent.h"
};
static const int xtensa_32bit_usr1 = 0;
static const int xtensa_32bit_usr2 = 0;
/* ARCH_riscv 64bit ABI mode */
static const struct_sysent riscv_64bit_sysent[] = {
	#include "riscv/syscallent.h"
};
static const int riscv_64bit_usr1 = 0;
static const int riscv_64bit_usr2 = 0;
/* ARCH_riscv 32bit ABI mode */
static const struct_sysent riscv_32bit_sysent[] = {
	#include "riscv/syscallent1.h"
};
static const int riscv_32bit_usr1 = 0;
static const int riscv_32bit_usr2 = 0;
