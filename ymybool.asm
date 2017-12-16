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
			lw			$t1, 			_x
			lw			$t4, 			_y
			add			$t5, 			$t1, 			$t4
			lw			$t1, 			_z
			bne			$t5, 			$t1, 			L3
#:			se			$t4, 			$t5, 			$t1
#:			beqz			$t4, 			L3
			li			$v0, 			4
			la			$a0, 			L4
			syscall
L1:
L2:
L3:
			lw			$t5, 			_x
			lw			$t6, 			_y
			ble			$t5, 			$t6, 			L5
#:			sgt			$t7, 			$t5, 			$t6
#:			beqz			$t7, 			L5
			b			L9
L5:
			lw			$t5, 			_y
			lw			$t6, 			_z
			bge			$t5, 			$t6, 			L6
#:			slt			$t8, 			$t5, 			$t6
#:			beqz			$t8, 			L6
			lw			$t5, 			_x
			lw			$t6, 			_y
			add			$t9, 			$t5, 			$t6
			lw			$t5, 			_z
			bne			$t9, 			$t5, 			L7
#:			se			$t6, 			$t9, 			$t5
#:			beqz			$t6, 			L7
L9:
			li			$v0, 			4
			la			$a0, 			L10
			syscall
L6:
L7:
			lw			$s0, 			_x
			lw			$s1, 			_y
			ble			$s0, 			$s1, 			L11
#:			sgt			$s2, 			$s0, 			$s1
#:			beqz			$s2, 			L11
			b			L14
L11:
			lw			$s0, 			_y
			lw			$s1, 			_z
			ble			$s0, 			$s1, 			L12
#:			sgt			$s3, 			$s0, 			$s1
#:			beqz			$s3, 			L12
L14:
			li			$v0, 			4
			la			$a0, 			L15
			syscall
L12:
			lw			$s1, 			_x
			lw			$s4, 			_y
			ble			$s1, 			$s4, 			L16
#:			sgt, 			$s1, 			$s4
#:			beqz, 			L16
			b			L19
L16:
			lw			$s1, 			_y
			lw			$s4, 			_z
			ble			$s1, 			$s4, 			L17
#:			sgt, 			$s1, 			$s4
#:			beqz, 			L17
L19:
			b			L20
L17:
			li			$v0, 			4
			la			$a0, 			L21
			syscall
L20:
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
_z:			.word			0
L21:			.asciiz			"forth true\n"
L15:			.asciiz			"third true\n"
L10:			.asciiz			"second true\n"
L4:			.asciiz			"first true\n"
