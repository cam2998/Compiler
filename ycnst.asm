			.text
			.globl			__start
__start:
			li			$t0, 			100
			sw			$t0, 			_this
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$v0, 			4
			la			$a0, 			L1
			syscall
			lw			$t1, 			_this
			li			$v0, 			1
			move			$a0, 			$t1
			syscall
			li			$t1, 			10
			li			$v0, 			11
			move			$a0, 			$t1
			syscall
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t2, 			_this
			li			$v0, 			1
			move			$a0, 			$t2
			syscall
			li			$t2, 			10
			li			$v0, 			11
			move			$a0, 			$t2
			syscall
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
_z:			.word			0
_this:			.word			0
L2:			.asciiz			"This should still be 100 even after someone tries to set it to something else\n"
L1:			.asciiz			"This should equal 100 \n"
