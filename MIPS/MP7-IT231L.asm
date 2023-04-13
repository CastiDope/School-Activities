# Title: Machine Problem 6
# Author: John Lawrence H. Castillejo
# Date: 10/18/2022
# Description: Verifies the content of registers $s2 to $s4.
# Input: None
# Output: The content of registers $s2 to $s4.

.data

.text 
li $s1, 0x87654321

sll $s2,$s1, 16   
srl $s3,$s1, 8      
sra $s4,$s1, 12    
li $v0, 10
syscall
