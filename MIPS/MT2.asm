# Title: MIDTERM 2		  				  Filename: MT2.asm
# Author: John Lawrence H. Castillejo				  Date: 11/24/2022
# Description: A program that asks the user to enter a positive integer number n and then prints the nth number in the Fibonacci sequence.
# Input: An integer.
# Output: The nth number in the Fibonacci sequence.

.data
enter1: .asciiz "Enter a number:\n"
display1: .asciiz "The nth value is:\n"
display2: .asciiz "The nth value is:\n0"

.text
li $v0, 4
la $a0, enter1
syscall
li $v0, 5
syscall
beq $v0, 0, equalToZero
move $a0, $v0	# Call function fibonacci
jal fibonacci
move $a1, $v0	# save return value to a1
li $v0, 4	
la $a0, display1
syscall
li $v0, 1 	# Print result
move $a0, $a1
syscall
li $v0, 10 	# Exit Program
syscall
fibonacci:
addi $sp, $sp, -12
sw $ra, 8($sp)
sw $s0, 4($sp)
sw $s1, 0($sp)
move $s0, $a0
li $v0, 1 
ble $s0, 0x2, fibonacciExit 
addi $a0, $s0, -1
jal fibonacci
move $s1, $v0 
addi $a0, $s0, -2 
jal fibonacci
add $v0, $s1, $v0 
fibonacciExit:

lw $ra, 8($sp)
lw $s0, 4($sp)
lw $s1, 0($sp)
addi $sp, $sp, 12
jr $ra

equalToZero:
li $v0, 4
la $a0, display2
syscall
