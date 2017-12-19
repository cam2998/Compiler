			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			6
			sw			$t0, 			_g
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_g
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
L2:
			lw			$t1, 			_g
			li			$t2, 			10
			bgt			$t1, 			$t2, 			L1
#:			sle			$t3, 			$t1, 			$t2
#:			beqz			$t3, 			L1
			li			$t1, 			2
			sw			$t1, 			_k
			lw			$t1, 			_g
			lw			$t2, 			_k
			add			$t4, 			$t1, 			$t2
			sw			$t4, 			_g
			la			$t1, 			10
			li			$v0, 			11
			move			$a0, 			$t1
			syscall
			lw			$t1, 			_g
			li			$v0, 			1
			move			$a0, 			$t1
			syscall
			b			L2
L1:
			la			$t1, 			10
			li			$v0, 			11
			move			$a0, 			$t1
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			la			$t2, 			10
			li			$v0, 			11
			move			$a0, 			$t2
			syscall
			jr			$ra
			.data
_k:			.word			0
_g:			.word			0
_x:			.word			0
_y:			.word			0
_z:			.word			0
L3:			.asciiz			"Printing K next. Should be nothing since its out of scope\n"
