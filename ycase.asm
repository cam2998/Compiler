			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			2
			sw			$t0, 			_x
			lw			$t0, 			_x
			move			$t1, 			$t0
C4:
			li			$t2, 			4
			bne			$t1, 			$t2, 			C3
			b			B5
C3:
			li			$t2, 			3
			bne			$t1, 			$t2, 			C2
			b			B4
C2:
			li			$t2, 			2
			bne			$t1, 			$t2, 			C1
			b			B3
C1:
			li			$t2, 			1
			bne			$t1, 			$t2, 			C0
			b			B2
C0:
B1:
			li			$t1, 			10000
			sw			$t1, 			_x
			b			S0
B2:
			li			$t3, 			10
			sw			$t3, 			_x
			b			S0
B3:
			li			$t3, 			20
			sw			$t3, 			_x
			b			S0
B4:
			li			$t3, 			20
			sw			$t3, 			_x
			b			S0
B5:
			li			$t3, 			20
			sw			$t3, 			_x
			b			S0
S0:
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
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
			.data
_x:			.word			0
_y:			.word			0
_z:			.word			0
