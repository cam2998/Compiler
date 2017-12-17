			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$v0, 			5
			syscall
			move			$t0, 			$v0
			sw			$t0, 			_x
			li			$t0, 			2
			sw			$t0, 			_y
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_y
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L1
			syscall
			lw			$t0, 			_y
			addi			$t0, 			$t0, 			1
			sw			$t0, 			_y
			lw			$t0, 			_y
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			addi			$t0, 			$t0, 			-1
			sw			$t0, 			_x
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			addi			$t0, 			$t0, 			-1
			sw			$t0, 			_x
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			addi			$t0, 			$t0, 			-1
			sw			$t0, 			_x
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
L2:			.asciiz			"-- = "
L1:			.asciiz			"++ = "
