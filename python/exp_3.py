def separate_even_odd(lst):
    even_list = []
    odd_list = []
    for num in lst:
        if num % 2 == 0:
            even_list.append(num)
        else:
            odd_list.append(num)
    return even_list, odd_list

def merge_and_sort(even_list, odd_list):
    merged_list = even_list + odd_list
    merged_list.sort()
    return merged_list

def update_and_delete(lst, x):
    if len(lst) > 0:
        lst[0] = x 
        if len(lst) % 2 == 0:
            middle_index = len(lst) // 2 - 1 
        else:
            middle_index = len(lst) // 2 
        lst.pop(middle_index) 
    return lst

def find_max_min(lst):
    if len(lst) > 0:
        return max(lst), min(lst)
    else:
        return None, None

def add_names_and_check(lst, names):
    lst.extend(names)
    return 'python' in [name.lower() for name in lst]

def main():
    while True:
        print("\nMenu:")
        print("1. Separate even and odd elements into different lists")
        print("2. Merge and sort two lists")
        print("3. Update first element with X value and delete the middle element")
        print("4. Find max and min element from the list")
        print("5. Add N names into the existing number list and check if 'python' is present")
        print("6. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("Enter the number of elements: "))
            lst = []
            for i in range(n):
                element = int(input(f"Enter element {i+1}: "))
                lst.append(element)
            even_list, odd_list = separate_even_odd(lst)
            print("Even List:", even_list)
            print("Odd List:", odd_list)

        elif choice == 2:
            n1 = int(input("Enter the number of elements in the first list: "))
            list1 = [int(input(f"Enter element {i+1}: ")) for i in range(n1)]
            n2 = int(input("Enter the number of elements in the second list: "))
            list2 = [int(input(f"Enter element {i+1}: ")) for i in range(n2)]
            merged_sorted_list = merge_and_sort(list1, list2)
            print("Merged and Sorted List:", merged_sorted_list)

        elif choice == 3:
            n = int(input("Enter the number of elements: "))
            lst = [int(input(f"Enter element {i+1}: ")) for i in range(n)]
            x = int(input("Enter the value of X: "))
            updated_list = update_and_delete(lst, x)
            print("Updated List:", updated_list)

        elif choice == 4:
            n = int(input("Enter the number of elements: "))
            lst = [int(input(f"Enter element {i+1}: ")) for i in range(n)]
            max_val, min_val = find_max_min(lst)
            if max_val is not None:
                print(f"Max Element: {max_val}, Min Element: {min_val}")
            else:
                print("List is empty")

        elif choice == 5:
            n = int(input("Enter the number of elements: "))
            lst = [input(f"Enter element {i+1}: ") for i in range(n)]
            name_count = int(input("Enter the number of elements: "))
            names = [input(f"Enter name {i+1}: ") for i in range(name_count)]
            python_present = add_names_and_check(lst, names)
            if python_present:
                print("'python' is in the list.")
            else:
                print("'python' is NOT in the list.")

        elif choice == 6:
            print("BYE")
            break

        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main()
