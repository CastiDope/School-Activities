# Title: Machine Problem 4
# Author: John Lawrence H. Castillejo
# Date: 10/12/2022
# Description: A program that compares two integers you inputted if it is equal or not.
# Input: An integer
# Output: Result of two integer if it is equal or not

.data
int1:     	.asciiz  "Enter a number: "
int2:     	.asciiz  "Enter another number: "
compare1:     	.asciiz  "They're Equal"
compare2:   	.asciiz  "They're Unequal"
.text
main:
   li $v0, 4         
   la $a0, int1     
   syscall           
   li $v0, 5       
   syscall            
   move $t1, $v0      
   li $v0, 4        
   la $a0, int2     
   syscall            
   li $v0, 5         
   syscall            
   move $t2, $v0      
   beq $t1,$t2, answer
   li $v0, 4         
   la $a0, compare2     
   syscall            
   li $v0,10          
   syscall
answer:           
   li $v0 , 4        
   la $a0, compare1  
   syscall           
   li $v0,10        
   syscall
