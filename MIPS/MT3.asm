# Title: MIDTERM 3		  				  Filename: MT3.asm
# Author: John Lawrence H. Castillejo				  Date: 11/24/2022
# Description: A program that defines a one-dimensional array of 10 integers in the static area of the data segment, asks the user to input all 10 array elements, computes, and displays their sum.
# Input: 10 array elements.
# Output: The sum of the array elements.

.data
num0: .space 50
str0: .asciiz "Input ten integers:\n"
str2: .asciiz "Another important string"
str1: .asciiz "The sum of the array is: "

.text
.globl main
main:
        li $v0,4
        la $a0, str0          # Get the integers by using array elements.
        syscall
        li $s1, 0             # Address of string to print
        li $t0, 0
        j loop                # Initiate loop    
loop:
        li $v0, 5             # Address of the integers
        syscall
        addi $t0, $t0, 4
        sw $v0, num0 ($t0)
        move $t6, $v0         # Addition of the integers
        addu $s1, $s1, $t6
        beq $t0, 40, exit     # Exit Loop
        j loop
exit:
        li $v0, 4
        la $a0, str1
        syscall
        li $v0, 1            # Displays sum
        move $a0, $s1
        syscall
        li $v0, 10           # Exit program
        syscall
