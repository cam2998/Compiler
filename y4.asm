			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$v0, 			4
			la			$a0, 			L1
			syscall
			li			$v0, 			5
			syscall
			move			$t0, 			$v0
			sw			$t0, 			_x
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			li			$t0, 			1
			sw			$t0, 			_fac
L5:
			lw			$t0, 			_x
			li			$t1, 			0
			ble			$t0, 			$t1, 			L4
#:			sgt			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L4
			lw			$t0, 			_fac
			lw			$t1, 			_x
			mul			$t3, 			$t0, 			$t1
			sw			$t3, 			_fac
			lw			$t0, 			_x
			li			$t1, 			1
			sub			$t3, 			$t0, 			$t1
			sw			$t3, 			_x
			b			L5
L4:
			li			$v0, 			4
			la			$a0, 			L6
			syscall
			lw			$t0, 			_fac
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			jr			$ra
			.data
_x:			.word			0
_fac:			.word			0
L6:			.asciiz			"factorial = "
L3:			.asciiz			"\n"
L2:			.asciiz			"x = "
L1:			.asciiz			"> "
