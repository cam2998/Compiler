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
			li			$t0, 			4
			sw			$t0, 			_x
			jr			$ra
_second:
			li			$t0, 			6
			sw			$t0, 			_y
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
L2:			.asciiz			"hello"
L1:			.asciiz			"hi"
