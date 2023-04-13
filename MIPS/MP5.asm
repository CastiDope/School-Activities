# Title: Machine Problem 5
# Author: John Lawrence H. Castillejo
# Date: 10/18/2022
# Description: A program that ask the user to enter two integers A and B and then display the result of computing the expression: A + 2B - 5.
# Input: Two integers
# Output: The result of computing the expression: A + 2B - 5

.data 
   intA:    .asciiz "Input integer value A: "
   intB:    .asciiz "Input integer value B: "
   
.text
   li $v0, 4
   la $a0,intA
   syscall
   li $v0, 5
   syscall
   move $s0, $v0
   li $v0, 4
   la $a0,intB
   syscall
   li $v0, 5
   syscall
   move $s1,$v0
   li $v0, 1
   li $t1, 2
   mul $t2,$t1,$s1
   add $s2,$t2,$s0
   li $t3, 5
   sub $s3,$s2,$t3
   move $a0, $s3
   syscall
   li $v0, 10
   syscall
