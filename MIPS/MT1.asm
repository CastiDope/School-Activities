# Title: MIDTERM 1		  				  Filename: MT1.asm
# Author: John Lawrence H. Castillejo				  Date: 11/24/2022
# Description: A program that asks the user to enter an unsigned number and read it. Then swap the bits at odd positions with those at even positions and display the resulting number.
# Input: An integer
# Output: The swap bits of even and odd position and the resulf of it.

.data
str1: 	.asciiz	 "Enter number: "
str2: 	.asciiz	 "Result is: "
	
.globl main
.text
main:
li $v0, 4	
la $a0, str1	# Display prompt string
syscall			
li $v0, 5	# Reads an integer and saves it into temporary memory
syscall		
move $t0, $v0	
la $a0, str2	# Displays swapped string
li $v0, 4	
syscall		
# loading hex values for getting the even and odd bits
li $s5, 0xAAAAAAAA	# 10101010 10101010 10101010 10101010
li $s6, 0x55555555	# 0010101 0010101 0010101 0010101 
# get all even bits
and $s1, $t0, $s5	# $s1 = $t0 & 0xAAAAAAAA
# get all odd bits
and $s2, $t0, $s6	# $s2 = $t0 & 0x55555555
srl $s1, $s1, 1		# Right shift even bits 
sll $s2, $s2, 1		# Left Shift even bits
or $s3, $s1, $s2	# combine new odd and even bits 
move $a0, $s3		
li $v0, 1			
syscall			
li $v0, 10		# Exit program
syscall			
