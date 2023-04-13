# Title : Machine Problem 12
# Author: John Lawrence H. Castillejo
# Date: 11/17/2022
# Description: Write MIPS code to perform the following integer multiplications. What is the value of the LO and HI registers?
# Input: None (The values are already stored).
# 0utput: The LO and HI value registers using instructions multu & mult.

.data
hi_val1:    .asciiz "\nRegister HI in multu: "   
lo_val1:    .asciiz "\nRegister LO in multu: "  
hi_val2:    .asciiz "\nRegister HI in mult: "   
lo_val2:    .asciiz "\nRegister LO in mult: "   

.text
.globl main
main:
li $s0, 98765    		#Store the 98765 value to register s0 
li $s1, 54321    		#Store the 54321 value to register s1
multu $s0, $s1   		
la $a0, hi_val1       	
li $v0,4           		
syscall            		
mfhi $t0           		
move $a0,$t0        	
li $v0,1           		
syscall            		
la $a0, lo_val1        	
li $v0,4           		
syscall            		
mflo $t1           		
move $a0,$t1        	
li $v0,1           		
syscall            		
li $s2, -98765   		
li $s3, -54321   		
mult $s2, $s3    		
la $a0, hi_val2       	
li $v0,4           		
syscall            		
mfhi $t0           		
move $a0,$t0		
li $v0,1           		
syscall            		
la $a0, lo_val2        	
li $v0,4           		
syscall            		
mflo $t1           		
move $a0,$t1
li $v0,1           		
syscall            		
li $v0,10          		
syscall            					
