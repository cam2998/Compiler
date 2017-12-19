			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			la			$t0, 			62
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			5
			syscall
			move			$t0, 			$v0
			sw			$t0, 			_x
			la			$t0, 			62
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			5
			syscall
			move			$t0, 			$v0
			sw			$t0, 			_y
			la			$t0, 			120
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			la			$t0, 			61
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			la			$t0, 			121
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			la			$t0, 			61
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_y
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
L4:
			lw			$t0, 			_x
			lw			$t1, 			_y
			beq			$t0, 			$t1, 			L1
#:			sne			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L1
			lw			$t0, 			_x
			lw			$t1, 			_y
			bge			$t0, 			$t1, 			L2
#:			slt			$t3, 			$t0, 			$t1
#:			beqz			$t3, 			L2
			lw			$t0, 			_y
			lw			$t1, 			_x
			sub			$t4, 			$t0, 			$t1
			sw			$t4, 			_y
			b			L3
L2:
			lw			$t0, 			_x
			lw			$t1, 			_y
			sub			$t4, 			$t0, 			$t1
			sw			$t4, 			_x
L3:
			b			L4
L1:
			la			$t0, 			103
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			la			$t0, 			61
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_x
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			la			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
