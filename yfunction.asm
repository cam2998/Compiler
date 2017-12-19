			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			3
			sw			$t0, 			_x
			li			$v0, 			4
			la			$a0, 			L1
			syscall
			addi			$sp, 			$sp, 			-4
			sw			$ra, 			0($sp)
			jal			_second
			lw			$ra, 			0($sp)
			addi			$sp, 			$sp, 			4
			move			$t0, 			$v0
			sw			$t0, 			_x
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
			jr			$ra
_second:
			li			$t0, 			6
			sw			$t0, 			_y
			lw			$t0, 			_y
			move			$v0, 			$t0
			jr			$ra
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
L2:			.asciiz			"should now be x=6\n x="
L1:			.asciiz			"x=3 before call\n"
