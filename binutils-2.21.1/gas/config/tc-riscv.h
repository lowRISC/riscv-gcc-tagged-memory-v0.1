/* tc-mips.h -- header file for tc-mips.c.
   Copyright 1993, 1994, 1995, 1996, 1997, 2000, 2001, 2002, 2003, 2004,
   2005, 2006, 2007  Free Software Foundation, Inc.
   Contributed by the OSF and Ralph Campbell.
   Written by Keith Knowles and Ralph Campbell, working independently.
   Modified for ECOFF support by Ian Lance Taylor of Cygnus Support.

   This file is part of GAS.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#ifndef TC_RISCV
#define TC_RISCV

#include "opcode/riscv.h"

struct frag;
struct expressionS;

#define TARGET_BYTES_BIG_ENDIAN 0

#define TARGET_ARCH bfd_arch_riscv

#define WORKING_DOT_WORD	1
#define OLD_FLOAT_READS
#define REPEAT_CONS_EXPRESSIONS
#define RELOC_EXPANSION_POSSIBLE
#define MAX_RELOC_EXPANSION 3
#define LOCAL_LABELS_FB 1

#define md_relax_frag(segment, fragp, stretch) \
  mips_relax_frag(segment, fragp, stretch)
extern int mips_relax_frag (asection *, struct frag *, long);

#define md_section_align(seg,size)	(size)
#define md_undefined_symbol(name)	(0)
#define md_operand(x)

#define NOP_OPCODE RISCV_NOP

extern void mips_handle_align (struct frag *);
#define HANDLE_ALIGN(fragp)  mips_handle_align (fragp)

#define MAX_MEM_FOR_RS_ALIGN_CODE  (1 + 2)

struct insn_label_list;
struct mips_segment_info {
  struct insn_label_list *labels;
  unsigned int mips16 : 1;
};
#define TC_SEGMENT_INFO_TYPE struct mips_segment_info

/* This field is nonzero if the symbol is the target of a MIPS16 jump.  */
#define TC_SYMFIELD_TYPE int

/* The ISA of the target may change based on command-line arguments.  */
#define TARGET_FORMAT mips_target_format()
extern const char *mips_target_format (void);

#define md_after_parse_args() mips_after_parse_args()
extern void mips_after_parse_args (void);

#define tc_init_after_args() mips_init_after_args()
extern void mips_init_after_args (void);

#define md_parse_long_option(arg) mips_parse_long_option (arg)
extern int mips_parse_long_option (const char *);

#define tc_frob_label(sym) mips_define_label (sym)
extern void mips_define_label (symbolS *);

/* Let the linker resolve all the relocs due to relaxation. */
#define tc_fix_adjustable(fixp) 0
#define md_allow_local_subtract(l,r,s) 0

/* Values passed to md_apply_fix don't include symbol values.  */
#define MD_APPLY_SYM_VALUE(FIX) 0

/* Global syms must not be resolved, to support ELF shared libraries.  */
#define EXTERN_FORCE_RELOC			\
  (OUTPUT_FLAVOR == bfd_target_elf_flavour)

#define TC_FORCE_RELOCATION_SUB_SAME(FIX, SEG) ((SEG)->flags & SEC_CODE)
#define TC_FORCE_RELOCATION_SUB_LOCAL(FIX, SEG) 1
#define TC_VALIDATE_FIX_SUB(FIX, SEG) TC_FORCE_RELOCATION_SUB_SAME(FIX, SEG)
#define DIFF_EXPR_OK 1

extern void mips_pop_insert (void);
#define md_pop_insert()		mips_pop_insert()

extern void mips_clear_insn_labels (void);
#define md_flush_pending_output mips_clear_insn_labels

extern void mips_enable_auto_align (void);
#define md_elf_section_change_hook()	mips_enable_auto_align()

enum dwarf2_format;
extern enum dwarf2_format mips_dwarf2_format (asection *);
#define DWARF2_FORMAT(SEC) mips_dwarf2_format (SEC)

extern int mips_dwarf2_addr_size (void);
#define DWARF2_ADDR_SIZE(bfd) mips_dwarf2_addr_size ()
#define DWARF2_FDE_RELOC_SIZE mips_dwarf2_addr_size ()

#define TARGET_USE_CFIPOP 1

#define tc_cfi_frame_initial_instructions mips_cfi_frame_initial_instructions
extern void mips_cfi_frame_initial_instructions (void);

#define tc_regname_to_dw2regnum tc_mips_regname_to_dw2regnum
extern int tc_mips_regname_to_dw2regnum (char *regname);

#define DWARF2_DEFAULT_RETURN_COLUMN LINK_REG
#define DWARF2_CIE_DATA_ALIGNMENT (-4)

#define elf_tc_final_processing riscv_elf_final_processing
extern void riscv_elf_final_processing (void);

#endif /* TC_RISCV */
