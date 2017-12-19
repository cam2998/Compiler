			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$t0, 			0
			sw			$t0, 			_x
LOOP1:
			lw			$t0, 			_x
			li			$t1, 			5
			bne			$t0, 			$t1, 			L1
#:			se			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L1
			b			EXIT1
L1:
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			addi			$t0, 			$t0, 			1
			sw			$t0, 			_x
			b			LOOP1
EXIT1:
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
_z:			.word			0
L3:			.asciiz			"\n Out of Loop\n"
L2:			.asciiz			"x="
