.data 
outfile:	.asciiz "out.txt" 	# output file name 
msg: 		.asciiz	"This text should be written in file out.txt" 

.text
li $v0, 13 	# Service 13: open file 
la $a0, outfile # Output file name 
li $a1, 1 	# Write-only with create 
syscall		# Open file 
move $s0, $v0	# $s0 = file descriptor 
li $v0, 15	# Service 15: write to file 
move $a0, $s0	# $a0 = file descriptor 
la $a1, msg	# $al = address of buffer 
li $a2, 43	# $a2 = number of characters to write 
syscall		# Write to file 
li $v0, 16 	# Service 16: close file 
move $a0, $s0 	# $a0 = file descriptor 
syscall 	# Close file 