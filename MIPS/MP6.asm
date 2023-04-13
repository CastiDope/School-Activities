# Title: Machine Problem 6
# Author: John Lawrence H. Castillejo
# Date: 10/18/2022
# Description: Verifies content of registers $s3 to $s6.
# Input: None
# Output: None

.data

.text
li  $s1, 0x12345678 
li  $s2, 0xffff9a00
and $s3,$s1,$s2		 # $s3 = 0x12341200
or  $s4,$s1,$s2		 # $s4 = 0xffffde78
xor $s5,$s1,$s2		 # $s5 = 0xedcbcc78
nor $s6,$s1,$s2		 # $s6 = 0x00002187
li $v0, 10
syscall
