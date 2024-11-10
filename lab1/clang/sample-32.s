	.text
	.file	"sample.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$8, %esp
	movl	$0, -4(%ebp)
	movl	$4, -8(%ebp)
	cmpl	$0, -8(%ebp)
	je	.LBB0_2
# %bb.1:
	movl	-8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -8(%ebp)
	jmp	.LBB0_3
.LBB0_2:
	movl	-8(%ebp), %eax
	shll	$2, %eax
	movl	%eax, -8(%ebp)
.LBB0_3:
	xorl	%eax, %eax
	addl	$8, %esp
	popl	%ebp
	.cfi_def_cfa %esp, 4
	retl
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
