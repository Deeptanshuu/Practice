print(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Exit")


ch = int(input("Enter Your Choice: "))

a  = float(input("Enter first value: "))
b  = float(input("Enter second value: "))


if ch == 1:
	print("Answer of %.2f + %.2f = %.2f"%(a , b, a+b))

elif ch==2:
	print("Answer of %.2f - %.2f = %.2f"%(a, b, a-b))

elif ch==3:
	print("Answer of %.2f x %.2f = %.2f"%(a, b, a*b))

elif ch==4:
	print("Answer of %.2f / %.2f = %.2f"%(a, b, a/b))

else:
	print("BYE")




