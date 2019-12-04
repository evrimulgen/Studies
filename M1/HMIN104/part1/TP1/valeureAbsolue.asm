#Demander la saisie d’un entier et rendre la valeur absolue de cet entier
#(afficher le résultat) ;


.text
	li $v0,5
	syscall
	li $t0,0
	blt $v0,$t0,neg
	addi $a0,$v0,0
	li $v0,1
	syscall
	j end
neg : 
	neg $a0,$v0
	li $v0,1
	syscall
	j end
end :
	li $v0,10
	syscall		

		