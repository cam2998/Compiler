			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			li			$t0, 			0
			sw			$t0, 			_y
LOOP2:
			li			$t0, 			0
			sw			$t0, 			_x
LOOP1:
			lw			$t0, 			_x
			li			$t1, 			1
			ble			$t0, 			$t1, 			L1
#:			sgt			$t2, 			$t0, 			$t1
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
			li			$t0, 			10
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
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_y
			li			$t1, 			3
			ble			$t0, 			$t1, 			L4
#:			sgt			$t3, 			$t0, 			$t1
#:			beqz			$t3, 			L4
			b			EXIT2
L4:
			lw			$t0, 			_y
			li			$t1, 			4
			ble			$t0, 			$t1, 			L5
#:			sgt			$t4, 			$t0, 			$t1
#:			beqz			$t4, 			L5
			b			EXIT2
L5:
			lw			$t0, 			_y
			li			$t1, 			5
			ble			$t0, 			$t1, 			L6
#:			sgt			$t5, 			$t0, 			$t1
#:			beqz			$t5, 			L6
			b			EXIT2
L6:
			li			$v0, 			4
			la			$a0, 			L7
			syscall
			lw			$t0, 			_y
			li			$v0, 			1
			move			$a0, 			$t0
			syscall
			li			$t0, 			10
			li			$v0, 			11
			move			$a0, 			$t0
			syscall
			lw			$t0, 			_y
			addi			$t0, 			$t0, 			1
			sw			$t0, 			_y
			b			LOOP2
EXIT2:
			li			$v0, 			4
			la			$a0, 			L8
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
L8:			.asciiz			"Out Of Loop Outer Loop"
L7:			.asciiz			"y="
L3:			.asciiz			"Out Of Loop Inner Loop"
L2:			.asciiz			"x="
