
hello:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000100003f50 _main:
100003f50: 55                          	pushq	%rbp
100003f51: 48 89 e5                    	movq	%rsp, %rbp
100003f54: 48 83 ec 20                 	subq	$32, %rsp
100003f58: c7 45 fc 00 00 00 00        	movl	$0, -4(%rbp)
100003f5f: 89 7d f8                    	movl	%edi, -8(%rbp)
100003f62: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100003f66: 48 8d 3d 35 00 00 00        	leaq	53(%rip), %rdi
100003f6d: b0 00                       	movb	$0, %al
100003f6f: e8 0e 00 00 00              	callq	14 <dyld_stub_binder+0x100003f82>
100003f74: 31 c9                       	xorl	%ecx, %ecx
100003f76: 89 45 ec                    	movl	%eax, -20(%rbp)
100003f79: 89 c8                       	movl	%ecx, %eax
100003f7b: 48 83 c4 20                 	addq	$32, %rsp
100003f7f: 5d                          	popq	%rbp
100003f80: c3                          	retq

Disassembly of section __TEXT,__stubs:

0000000100003f82 __stubs:
100003f82: ff 25 78 40 00 00           	jmpq	*16504(%rip)

Disassembly of section __TEXT,__stub_helper:

0000000100003f88 __stub_helper:
100003f88: 4c 8d 1d 79 40 00 00        	leaq	16505(%rip), %r11
100003f8f: 41 53                       	pushq	%r11
100003f91: ff 25 69 00 00 00           	jmpq	*105(%rip)
100003f97: 90                          	nop
100003f98: 68 00 00 00 00              	pushq	$0
100003f9d: e9 e6 ff ff ff              	jmp	-26 <__stub_helper>
