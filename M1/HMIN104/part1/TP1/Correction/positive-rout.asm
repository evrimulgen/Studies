# positive-rout.asm

.data
positive: .asciiz "positive\n"
negative: .asciiz "negative\n"

.text
main:	li $v0, 5
	syscall
	move $a0, $v0
	jal pos
	li $v0, 10
	syscall

pos:	li $t0, 0
	blt $a0, $t0, neg
	li $v0, 4
	la $a0, positive
	syscall
	j end
neg:	li $v0, 4
	la $a0, negative
	syscall
end:	jr $ra
