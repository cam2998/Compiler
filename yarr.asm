			.text
			.globl			__start
__start:
			jal			_main
			li			$v0, 			10
			syscall

_main:
			li			$t0, 			0
			sw			$t0, 			_y
L4:
			lw			$t0, 			_y
			li			$t1, 			8
			bge			$t0, 			$t1, 			L1
#:			slt			$t2, 			$t0, 			$t1
#:			beqz			$t2, 			L1
			lw			$t1, 			_y
			addi			$t4, 			$zero, 			4
			mul			$t0, 			$t0, 			$t4
			la			$t3, 			_c
			add			$t3, 			$t3, 			$t0
			sw			$t1, 			($t3)
			li			$v0, 			4
			la			$a0, 			L2
			syscall
			lw			$t1, 			_y
			li			$v0, 			1
			move			$a0, 			$t1
			syscall
			li			$v0, 			4
			la			$a0, 			L3
			syscall
			lw			$t1, 			_y
			li			$v0, 			1
			move			$a0, 			$t1
			syscall
			la			$t1, 			10
			li			$v0, 			11
			move			$a0, 			$t1
			syscall
			lw			$t0, 			_y
			addi			$t0, 			$t0, 			1
			sw			$t0, 			_y
			b			L4
L1:
			li			$t1, 			0
			sw			$t1, 			_y
L8:
			lw			$t1, 			_y
			li			$t3, 			8
			bge			$t1, 			$t3, 			L5
#:			slt			$t4, 			$t1, 			$t3
#:			beqz			$t4, 			L5
			li			$v0, 			4
			la			$a0, 			L6
			syscall
			lw			$t1, 			_y
			li			$v0, 			1
			move			$a0, 			$t1
			syscall
			li			$v0, 			4
			la			$a0, 			L7
			syscall
			lw			$t1, 			_y
			addi			$t6, 			$zero, 			4
			mul			$t1, 			$t1, 			$t6
			la			$t5, 			_c
			add			$t5, 			$t5, 			$t1
			lw			$t3, 			($t5)
			sw			$t3, 			_x
			lw			$t3, 			_x
			li			$v0, 			1
			move			$a0, 			$t3
			syscall
			la			$t3, 			10
			li			$v0, 			11
			move			$a0, 			$t3
			syscall
			lw			$t1, 			_y
			addi			$t1, 			$t1, 			1
			sw			$t1, 			_y
			b			L8
L5:
			jr			$ra
			.data
_x:			.word			0
_y:			.word			0
_c:			.word			0,0,0,0,0,0,0,0
L7:			.asciiz			"]="
L6:			.asciiz			"c["
L3:			.asciiz			" at position "
L2:			.asciiz			"Putting "
