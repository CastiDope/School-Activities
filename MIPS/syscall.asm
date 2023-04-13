# Title: System Calling
# Author: John Lawrence H. Castillejo
# Date: 10/11/2022
# Description: System Calling Program
# Input: An Integer
# Output: Inputted Integer

.data
str1:	    .asciiz		"Enter an integer value: "
str2:	    .asciiz		"You entered "

.glob1	    main
.text
main:
    li	    $v0, 4
    la      $a0, str1
    syscall
    li	    $v0, 5
    syscall 
    move    $s0, $v0
    li      $v0, 4
    la      $a0, str2
    syscall
    li	    $v0, 1
    move    $a0, $s0
    syscall
    li      $v0, 10
    syscall
