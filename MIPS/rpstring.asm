# Title: READING AND PRINTING A STRING				Filename: rpstring.asm
# Author: John Lawrence H. Castillejo				Date: 10/11/2022
# Description: This program will print read and print a string.
# Input: A string.
# Output: The inputted string.

.data 
	str: .space 10	

.text
.globl main
main:
	la	$a0, str
	li	$a1, 10
	li	$v0, 8
	syscall
	li	$v0, 4
	syscall
	li	$v0, 10
	syscall	
