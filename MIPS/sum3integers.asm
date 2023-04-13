# Title: SUM OF THREE INEGERS					Filename: sum3num.asm
# Author: John Lawrence H. Castillejo				Date: 10/11/2022
# Description: Computes the sum of three integers.
# Input: Requests three numbers.
# Output: The sum of three integers inputted

.data
prompt:  .asciiz 	"Please enter three numbers: \n"
sum_msg: .asciiz 	"The sum is: "

.text
.globl main
main:
	la	$a0,prompt
	li	$v0,4
	syscall
	li	$v0,5
	syscall 
	move	$t0,$v0
	li	$v0,5
	syscall
	move	$t1,$v0
	li	$v0, 5
	syscall
	move	$t2,$v0
	addu	$t0,$t0,$t1
	addu	$t0,$t0,$t2
	la	$a0,sum_msg
	li	$v0,4
	syscall
	move	$a0,$t0
	li	$v0,1
	syscall
	li	$v0,10
	syscall
	
