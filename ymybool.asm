			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			1
			sw			$t0, 			_x
			li			$t0, 			2
			sw			$t0, 			_y
			li			$t0, 			3
			sw			$t0, 			_z
			lw			$t0, 			_x
			lw			$t1, 			_y
			bge			$t0, 			$t1, 			L1
#:			slt			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L1
			lw			$t0, 			_y
			lw			$t1, 			_z
			bge			$t0, 			$t1, 			L2
#:			slt			$t3, 			$t0, 			$t1
#:			beqz			$t3, 			L2
			lw			$t0, 			_x
			lw			$t1, 			_y
			add			$t4, 			$t0, 			$t1
			lw			$t0, 			_z
			bne			$t4, 			$t0, 			L3
#:			se			$t1, 			$t4, 			$t0
#:			beqz			$t1, 			L3
			li			$v0, 			4
			la			$a0, 			L4
			syscall
L1:
L2:
L3:
			lw			$t0, 			_x
			lw			$t4, 			_y
			ble			$t0, 			$t4, 			L5
#:			sgt			$t5, 			$t0, 			$t4
#:			beqz			$t5, 			L5
			b			L8
L5:
			lw			$t0, 			_y
			lw			$t4, 			_z
			bge			$t0, 			$t4, 			L6
#:			slt			$t6, 			$t0, 			$t4
#:			beqz			$t6, 			L6
			lw			$t0, 			_x
			lw			$t4, 			_y
			add			$t7, 			$t0, 			$t4
			lw			$t0, 			_z
			bne			$t7, 			$t0, 			L7
#:			se			$t4, 			$t7, 			$t0
#:			beqz			$t4, 			L7
L8:
			li			$v0, 			4
			la			$a0, 			L9
			syscall
L6:
L7:
			lw			$t0, 			_x
			lw			$t7, 			_y
			ble			$t0, 			$t7, 			L10
#:			sgt			$t8, 			$t0, 			$t7
#:			beqz			$t8, 			L10
			b			L12
L10:
			lw			$t0, 			_y
			lw			$t7, 			_z
			ble			$t0, 			$t7, 			L11
#:			sgt			$t9, 			$t0, 			$t7
#:			beqz			$t9, 			L11
L12:
			li			$v0, 			4
			la			$a0, 			L13
			syscall
L11:
			lw			$t0, 			_x
			lw			$t7, 			_y
			ble			$t0, 			$t7, 			L14
#:			sgt			$s0, 			$t0, 			$t7
#:			beqz			$s0, 			L14
			b			L16
L14:
			lw			$t0, 			_y
			lw			$t7, 			_z
			ble			$t0, 			$t7, 			L15
#:			sgt			$s1, 			$t0, 			$t7
#:			beqz			$s1, 			L15
L16:
			b			L17
L15:
			li			$v0, 			4
			la			$a0, 			L18
			syscall
L17:
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
_z:			.word			0
L18:			.asciiz			"forth true\n"
L13:			.asciiz			"third true\n"
L9:			.asciiz			"second true\n"
L4:			.asciiz			"first true\n"
