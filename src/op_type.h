#ifndef X64ASM_SRC_OP_TYPE_H
#define X64ASM_SRC_OP_TYPE_H

namespace x64asm {

/** Any of the types which appear in the Intel Manual. */
enum class OpType {
	// Condition Registers (cr.h)
	CR = 0,
	CR_0234,
	CR_8,

	// Debug Registers (dr.h)
	DR,

	// EFLAGS Register bits (eflags.h)
	EFLAG,

	// Conditional Jump Hint (hint.h)
	HINT,

	// Immediates (imm.h)
	IMM,
	IMM_8,
	IMM_16,
	IMM_32,
	IMM_64,
	ZERO,
	ONE,
	THREE,

	// Labels (label.h)
	LABEL,

	// Memory (m.h)
	M,
	M_8,
	M_16,
	M_32,
	M_64,
	M_128,
	M_256,
	M_PAIR_16_64,
	M_PTR_16_16,
	M_PTR_16_32,
	M_PTR_16_64,
	M_16_INT,
	M_32_INT,
	M_64_INT,
	M_32_FP,
	M_64_FP,
	M_80_FP,
	M_80_BCD,
	M_2_BYTE,
	M_14_BYTE,
	M_28_BYTE,
	M_94_BYTE,
	M_108_BYTE,
	M_512_BYTE,

	// MMX Registers (mm.h)
	MM,

	// Modifiers (modifier.h)
	MODIFIER,
	PREF_66,
	PREF_REX_W,
	FAR,

	// Memory Offsets (moffs.h)
	MOFFS,
	MOFFS_8,
	MOFFS_16,
	MOFFS_32,
	MOFFS_64,

	// Operands (operand.h)
	OPERAND,
	ATOMIC_OPERAND,
	COMPOUND_OPERAND,

	// General Purpose Registers (r.h)
	R,
	RL,
	RH,
	RB,
	AL,
	CL,
	R_16,
	AX,
	DX,
	ADDR_R,
	R_32,
	EAX,
	R_64,
	RAX,

	// Relatives Addresses (rel.h)
	REL,
	REL_8,
	REL_32,

	// Segment Registers (sreg.h)
	SREG,
	FS,
	GS,

	// Floating Point Stack Registers (st.h)
	ST,
	ST_0,

	// XMM Registers (xmm.h)
	XMM,
	XMM_0,

	// YMM Registers (ymm.h)
	YMM
};

} // namespace x64asm

#endif
