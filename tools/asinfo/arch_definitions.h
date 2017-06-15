/* [],[bfin/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(blackfin,	32bit,		PASS({}),					PASS({"blackfin", "bfin"})			),
/* [],[ia64/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(ia64,		64bit,		PASS({}),					PASS({"ia64"})					),
/* [],[m68k/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(m68k,		32bit,		PASS({}),					PASS({"m68k"})					),
/* [],[sparc64/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(sparc64,	64bit,		PASS({ARCH_sparc_32bit}),			PASS({"sparc64"})				),
/* [],[sparc/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(sparc,		32bit,		PASS({}),					PASS({"sparc"})					),
/* [],[metag/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(metag,		32bit,		PASS({}),					PASS({"metag"})					),
/* [LINUX_MIPSN64],[dummy.h,mips/syscallent-compat.h,mips/syscallent-n64.h],[0,0] */
ARCH_DESC_DEFINE(mips64,	n64,		PASS({ARCH_mips64_n32, ARCH_mips_o32}),		PASS({"mips64", "mips64le"})			),
/* [LINUX_MIPSN32],[dummy.h,mips/syscallent-compat.h,mips/syscallent-n32.h],[0,0] */
ARCH_DESC_DEFINE(mips64,	n32,		PASS({ARCH_mips_o32}),				PASS({})					),
/* [LINUX_MIPSO32],[dummy.h,mips/syscallent-compat.h,mips/syscallent-o32.h],[0,0] */
ARCH_DESC_DEFINE(mips,		o32,		PASS({}),					PASS({"mips", "mipsle"})			),
/* [],[alpha/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(alpha,		64bit,		PASS({}),					PASS({"alpha"})					),
/* [],[powerpc64/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(ppc64,		64bit,		PASS({ARCH_ppc_32bit}),				PASS({"ppc64", "ppc64le", "powerpc64"})		),
/* [],[powerpc/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(ppc,		32bit,		PASS({}),					PASS({"ppc", "ppcle", "powerpc"})		),
/* [],[aarch64/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(aarch64,	64bit,		PASS({ARCH_arm_eabi}),				PASS({"aarch64", "arm64"})			),
/* [!__ARM_EABI__],[arm/syscallent.h],[ARM_FIRST_SHUFFLED_SYSCALL,ARM_LAST_SPECIAL_SYSCALL] */
ARCH_DESC_DEFINE(arm,		oabi,		PASS({ARCH_arm_eabi}),				PASS({"arm"})					),
/* [__ARM_EABI__],[arm/syscallent.h],[ARM_FIRST_SHUFFLED_SYSCALL,ARM_LAST_SPECIAL_SYSCALL] */
ARCH_DESC_DEFINE(arm,		eabi,		PASS({}),					PASS({})					),
/* [],[avr32/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(avr32,		32bit,		PASS({}),					PASS({"avr32"})					),
/* [],[arc/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(arc,		32bit,		PASS({}),					PASS({"arc"})					),
/* [],[s390x/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(s390x,		64bit,		PASS({}),					PASS({"s390x"})					),
/* [],[s390/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(s390,		32bit,		PASS({}),					PASS({"s390"})					),
/* [],[hppa/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(hppa,		32bit,		PASS({}),					PASS({"parisc", "hppa"})			),
/* [],[sh64/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(sh64,		64bit,		PASS({}),					PASS({"sh64"})					),
/* [],[sh/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(sh,		32bit,		PASS({}),					PASS({"sh"})					),
/* [],[x86_64/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(x86_64,	64bit,		PASS({ARCH_x86_64_x32, ARCH_x86_32bit}),	PASS({"x86_64", "amd64", "EM64T"})		),
/* [],[x86_64/syscallent2.h],[0,0] */
ARCH_DESC_DEFINE(x86_64,	x32,		PASS({ARCH_x86_32bit}),				PASS({})					),
/* [],[i386/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(x86,		32bit,		PASS({}),					PASS({"x86", "i386", "i486", "i586", "i686"})	),
/* [],[tile/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(tile,		64bit,		PASS({ARCH_tile_32bit}),			PASS({"tile", "tilegx"})			),
/* [],[tile/syscallent1.h],[0,0] */
ARCH_DESC_DEFINE(tile,		32bit,		PASS({}),					PASS({"tilepro"})				),
/* [],[microblaze/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(microblaze,	32bit,		PASS({}),					PASS({"microblaze"})				),
/* [],[nios2/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(nios2,		32bit,		PASS({}),					PASS({"nios2"})					),
/* [],[or1k/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(openrisc,	32bit,		PASS({}),					PASS({"openrisc", "or1k"})			),
/* [],[xtensa/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(xtensa,	32bit,		PASS({}),					PASS({"xtensa"})				),
/* [],[riscv/syscallent.h],[0,0] */
ARCH_DESC_DEFINE(riscv,		64bit,		PASS({ARCH_riscv_32bit}),			PASS({"riscv"})					),
/* [],[riscv/syscallent1.h],[0,0] */
ARCH_DESC_DEFINE(riscv,		32bit,		PASS({}),					PASS({})					)
