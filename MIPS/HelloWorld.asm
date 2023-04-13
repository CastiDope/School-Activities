# Program Name: HelloWorld.asm
# Name: John Lawrence H. Castillejo
# Course Code/Shedule: IT231L-M /Thursday, 8:00 AM-10:00 AM
	.data				# data segment
hello:	.asciiz "Hello, world!\n"	# a null terminated string
	.text				# code segment
	.globl main			# 
main:
	la	$a0, hello		# load string address
	li	$v0, 4			# specify system write servuce
	syscall				# call the kernel (write string)
	li	$v0,10			# exit ot OS
	syscall