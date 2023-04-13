.data 
   
   int_A:    .asciiz "Enter the value of A: "
   int_B:    .asciiz "Enter the value of B: "
   
.text
   li $v0, 4
   la $a0,int_A
   syscall
   li $v0, 5
   syscall
   move $s0, $v0
   li $v0, 4
   la $a0,int_B
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