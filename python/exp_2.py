print("1.Factorial")
print("2.Palindrome")
print("Press any other key to EXIT")

ch = int(input("Enter Choice: "))

if ch == 1:
	fact = 1
	n = int(input("Enter a value: "))

	while n != 1:
		fact = fact * n
		n = n - 1

	print("Factorial is",fact)

elif ch == 2:
	str1 = input("Enter a sting: ")

	if str1 == str1[::-1]:
		print("YES, It's a palindrome")
	else:
		print("NO, It's not a palindrome")

else:
	print("BYE")
