#EXP_1 :
#
#Aim Python program to understand
#	-Basic math operations -Variables -If else ladder -Functions -Loops
#
#Algorithm-
#	-MDP add, subtract, multiply, divide

ch = 0

while(ch != 5):
	print("\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Exit")


	ch = int(input("Enter Your Choice: "))

	if ch == 5:
		print("BYE")
		break

	a = float(input("Enter first value: "))
	b = float(input("Enter second value: "))


	if ch == 1:
		print("Answer of %.2f + %.2f = %.2f"%(a , b, a+b))

	elif ch==2:
		print("Answer of %.2f - %.2f = %.2f"%(a, b, a-b))

	elif ch==3:
		print("Answer of %.2f x %.2f = %.2f"%(a, b, a*b))

	elif ch==4:
		print("Answer of %.2f / %.2f = %.2f"%(a, b, a/b))






