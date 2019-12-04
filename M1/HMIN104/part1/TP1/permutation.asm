#Initialiser un tableau de 3 entiers (sans le saisir) et permuter les éléments de ce tableau

.data
	array : .space 12 #  declare 12 bytes of storage to hold array of 3 integers
   	# t0 t1 t2  --> t2 t1 t0
   	var : .asciiz  "\n"
.text
	la $t0,array
	li $t1,1
	sw $t1,($t0)
	li $t1,2
	sw $t1,4($t0)
	li $t1,3
	sw $t1,8($t0)
	jal display
	lw $t1,($t0)
	lw $t2,8($t0)
	sw $t1,8($t0)
	sw $t2,($t0)
	jal display
	li $v0,10
	syscall
	
display : 
	 lw $a0,($t0)
	 li $v0,1
	 syscall
	 lw $a0,4($t0)
	 li $v0,1
	 syscall
	 lw $a0,8($t0)
	 li $v0,1
	 syscall
	 la $a0,var
	 li $v0,4
	 syscall
	 jr $ra
	  
