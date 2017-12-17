			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			0
			sw			$t0, 			_x
L4:
			lw			$t0, 			_x
			li			$t1, 			5
			bge			$t0, 			$t1, 			L1
#:			slt			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L1
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			addi			$t0, 			$t0, 			1
			sw			$t0, 			_x
			b			L4
L1:
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L5
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			jr			$ra
			.data
_x:			.word			0
L5:			.asciiz			"done"
L3:			.asciiz			"loop"
L2:			.asciiz			"x="
