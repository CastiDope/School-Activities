# Title: Machine Problem 9
# Author: John Lawrence H. Castillejo
# Date: 10/27/2022
# Description: It will display the sum of the range from first integer to the last integer.
# Input: Two integers
# Output: Displays the sum of all numbers from n1 to n2.

.data
int1: 	.asciiz "Enter first integer: "
int2: 	.asciiz "Enter second integer: "
result: .asciiz "The sum is: "
newLine:.asciiz "\n"

.text
main:

la $a0, int1		# prompt for n1
li $v0, 4
syscall
li $v0, 5
syscall
move $t0, $v0		# copy n1 to t0
la $a0, int2		# prompt for n2
li $v0, 4
syscall
li $v0, 5
syscall			# copy n2 to t1
move $t1, $v0		# start with sum=0 and i=n1
li $t2, 0       	# $t2 is sum
move $t3, $t0   	# $t3 is i
loop:			# update the sum
add $t2, $t2, $t3   	# add t3 to t2
addi $t3, $t3, 1   	# increase t3
ble $t3, $t1, loop 	# loop if t3 has not exceeded t1
la $a0, result		# print the sum
li $v0, 4
syscall
move $a0, $t2
li $v0, 1
syscall
la $a0, newLine		# print a newline
li $v0, 4
syscall
li $v0, 10		# end the program
syscall
