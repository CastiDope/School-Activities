# Title: Machine Problem 3
# Author: John Lawrence H. Castillejo
# Date: 10/12/2022
# Description: A program that greets the user with its name.
# Input: A string
# Output: Greeting with the string you input.

.data
putname: .asciiz	 "Enter your name: "
greet:   .asciiz	 "Hello, "
name:	 .space	  20	 
.text

main:
    li $v0, 4
    la $a0, putname
    syscall
    li $v0, 8
    la $a0, name
    li $a1, 40
    syscall
    li $v0, 4
    la $a0, greet
    syscall
    li $v0, 4
    la $a0, name
    syscall
    li $v0, 10
    syscall
