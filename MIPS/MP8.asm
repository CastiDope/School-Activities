# Title: Machine Problem 8
# Author: John Lawrence H. Castillejo
# Date: 10/27/2022
# Description: Displays the number of 1's in the binary representation of the inputted integer.
# Input: Integer
# Output: The number of 1's in the binary representation of that integer.

.data
int1: .asciiz	"Enter a number: "
int2: .asciiz 	"The number of 1's are = "

.text
la $a0, int1		# Print string
li $v0, 4
syscall
li $v0, 5		# Read int
syscall
move $t0, $v0
li $t1, 0 		# Initialize counter
loop:
beq $t0, 0, end_loop
and $t2, $t0, 1
beq $t2, 0, next
add $t1, $t1, 1 	# increment count
next:
srl $t0, $t0, 1
b loop  
end_loop:
la $a0, int2		# display the results
li $v0, 4
syscall
move $a0, $t1		# Print int
li $v0, 1
syscall
li $v0, 10		# Exit program
syscall