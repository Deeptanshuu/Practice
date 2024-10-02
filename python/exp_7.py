def main():
    try:
        num1 = int(input("Enter the first number: "))
        num2 = int(input("Enter the second number: "))
        
        
        result = num1 / num2
        print(f"The result is: {result}")
    
    except ZeroDivisionError:
        print("Error: Cannot divide by zero!")
    except ValueError:
        print("Error: Invalid input! Please enter numbers only.")
    
    finally:
        print("Program execution completed.")

if __name__ == "__main__":
    main()
