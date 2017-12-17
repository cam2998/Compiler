			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall
_main:
			li			$t0, 			0
			sw			$t0, 			_x
			li			$t0, 			5
			sw			$t0, 			_y
L6:
			lw			$t0, 			_x
			li			$t1, 			5
			bge			$t0, 			$t1, 			L1
#:			slt			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L1
			lw			$t0, 			_y
			li			$t1, 			2
			ble			$t0, 			$t1, 			L2
#:			sgt			$t3, 			$t0, 			$t1
#:			beqz			$t3, 			L2
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			lw			$t0, 			_y
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L4
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
			lw			$t0, 			_x
			addi			$t0, 			$t0, 			1
			sw			$t0, 			_x
			lw			$t0, 			_y
			addi			$t0, 			$t0, 			-1
			sw			$t0, 			_y
			b			L6
L1:
L2:
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			lw			$t0, 			_y
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$v0, 			4
			la			$a0, 			L4
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
			la			$a0, 			L7
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
L7:			.asciiz			"done"
L5:			.asciiz			"loop"
L4:			.asciiz			"x="
L3:			.asciiz			"y="
