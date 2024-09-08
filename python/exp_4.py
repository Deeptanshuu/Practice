def add_students(student_list, n):
    for i in range(n):
        roll_no = input(f"Enter roll number for student {i+1}: ")
        name = input(f"Enter name for student {i+1}: ")
        marks = []
        for j in range(1, 4):
            mark = float(input(f"Enter mark {j} for {name}: "))
            marks.append(mark)
        student_list.append((roll_no, name, tuple(marks)))
    return student_list

def display_student_by_name(student_list, search_name):
    found = False
    for student in student_list:
        roll_no, name, marks = student
        if name.lower() == search_name.lower():
            print(f"Roll Number: {roll_no}, Marks: {marks}")
            found = True
    if not found:
        print(f"No student found with the name {search_name}.")

def sort_students_by_name(nested_tuple):
    return sorted(nested_tuple, key=lambda x: x[1].lower())

def main():
    student_list = []

    while True:
        print("\nMenu:")
        print("1. Add and show N student roll number, name, and 3 subject marks")
        print("2. Display student roll number and marks whose name is 'Python'")
        print("3. Demonstrate nested tuple and sort nested tuple by name")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("How many students do you want to add? "))
            student_list = add_students(student_list, n)
            print("\nStudent List:")
            for student in student_list:
                print(student)

        elif choice == 2:
            search_name = "Python"
            display_student_by_name(student_list, search_name)

        elif choice == 3:
            sorted_students = sort_students_by_name(student_list)
            print("\nSorted Student List by Name:")
            for student in sorted_students:
                print(student)

        elif choice == 4:
            print("Exiting...")
            break

        else:
            print("Invalid choice! Please choose again.")

if __name__ == "__main__":
    main()
