#Écrire une routine qui permute le contenu de deux variables entières
#de la zone de données avec une variable locale pour effectuer la
#permutation.

.data
	var1: .word 5
	var2: .word 6
	space: .asciiz "\n"
.text
	la $a1,var1
	la $a2,var2
	jal display
	jal permutation
	jal display
	li $v0,10
	syscall
permutation : 
	lw $t1,($a1)
	lw $t2,($a2)
	sw $t2,($a1)
	sw $t1,($a2)		
	jr $ra
display :
	lw $a0,var1
	li $v0,1
	syscall	  
	lw $a0,var2
	li $v0,1
	syscall	
	la $a0,space  
	li $v0,4
	syscall	  
	jr $ra