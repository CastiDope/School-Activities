# Title: Machine Problem 2
# Author: John Lawrence H. Castillejo
# Date: 10/12/2022
# Description: System Calling Program that repeats the program.
# Input: An Integer
# Output: The integer is doubled and request to repeat the program.

.data
str1:     .asciiz  "\nEnter an integer value: "
str2:     .asciiz  "The doubled integer value is: "
str3:     .asciiz "\nTry againy/n): "


.globl    main
.text
main:
    addi $t3, $zero, 'y'
   
    li $v0 , 4       #service code for print string
    la $a0, str1     #load address of str1 into $a0
    syscall          #print str1 string
    li $v0, 5        #service code for read integer
    syscall          #read integer input into $s0
    move $s0, $v0    #save input value in $s0
    li $v0, 4        #service code for print string  
    la $a0, str2     #load address of str2 into Sa0
    syscall          #print str2 string
    li $v0, 1        #service code to print integer
    add $t1,$s0,$s0  #add str1 integer by itself
    move $a0, $t1    #Copy input value
    syscall          # print integer
    li $v0, 4        #service code for print string
    la $a0, str3     #load address of str3 into $a0
    syscall          #print str1 string
    li $v0, 12       #service code for read charcter
    syscall          #read integer input into $t2
    move $t2, $v0    #copy input value to $t2 
    beq $t3,$t2,main #if t2 is equal to t3 then it will go back to main  
    li $v0,10       #service code to exit program
    syscall         #exit program
