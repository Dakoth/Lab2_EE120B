# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below
# Exercise 1
#
# ##################################

test "PINA: 0, PINB: 0, PINC: 0  => PORTD: 0x00" 
#Set inputs
setPINA 0
setPINB 0
setPINC 0
# Continue for several ticks 		
continue 2
# Set expect values 
expectPORTD 0x00 
# check pass/fail	
checkResult


test "PINA: 90, PINB: 90, PINC: 50  => PORTD: 0xE5" 
#Set inputs
setPINA 90
setPINB 90
setPINC 50
# Continue for several ticks 		
continue 2
# Set expect values 
expectPORTD 0xE5		# 1110 01 01	 
# check pass/fail	
checkResult


test "PINA: 30, PINB: 90, PINC: 120  => PORTD: 0xF3" 
#Set inputs
setPINA 30
setPINB 90
setPINC 120
# Continue for several ticks 		
continue 2
# Set expect values 
expectPORTD 0xF3		# 1111 00 11	 
# check pass/fail	
checkResult


test "PINA: 0, PINB: 60, PINC: 0  => PORTD: 0x3C" 
#Set inputs
setPINA 0
setPINB 60
setPINC 0
# Continue for several ticks 		
continue 2
# Set expect values 
expectPORTD 0x3C		#0011 11 00	 
# check pass/fail	
checkResult


test "PINA: 91, PINB: 0, PINC: 10  => PORTD: 0x66" 
#Set inputs
setPINA 91
setPINB 0
setPINC 10
# Continue for several ticks 		
continue 2
# Set expect values 
expectPORTD 0x66			#0110 01 10  	 
# check pass/fail	
checkResult

#####################################################


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
