
a.out:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000100003fa0 _swap_int:
100003fa0: 55                          	pushq	%rbp
100003fa1: 48 89 e5                    	movq	%rsp, %rbp
100003fa4: 8b 07                       	movl	(%rdi), %eax
100003fa6: 8b 0e                       	movl	(%rsi), %ecx
100003fa8: 89 0f                       	movl	%ecx, (%rdi)
100003faa: 89 06                       	movl	%eax, (%rsi)
100003fac: 5d                          	popq	%rbp
100003fad: c3                          	retq
100003fae: 66 90                       	nop

0000000100003fb0 _main:
100003fb0: 55                          	pushq	%rbp
100003fb1: 48 89 e5                    	movq	%rsp, %rbp
100003fb4: 31 c0                       	xorl	%eax, %eax
100003fb6: 5d                          	popq	%rbp
100003fb7: c3                          	retq
