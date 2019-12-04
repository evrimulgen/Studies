#code assembleur correspondant au code C

.data
	x: .word
	y: .word

.text
	la $a0,x
	li $v0,5
	syscall
	sw $v0,($a0)
sqr : 	
	lw $t1,($a0)
	mult $t1,$t1
	mfhi $t2
	mflo $t3
	