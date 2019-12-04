#Demander la saisie d’un entier et dire si cet entier est pair ou non (afficher le résultat).
.data
	pair: .asciiz "pair ! \n"
	impair: .asciiz "impair ! \n"

.text
	li $v0,5
	syscall
	li $t0,2
	div $v0,$t0
	mfhi $t1
	beq $t1,0,yes
	la $a0,impair
	li $v0,4
	syscall
	j end
yes: 
	la $a0,pair
	li $v0,4
	syscall
	
end : 
	li $v0,10
	syscall	