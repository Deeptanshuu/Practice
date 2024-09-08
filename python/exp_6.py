class Person:
    def __init__(self, id, name):
        self.id = id
        self.name = name

    def display_details(self):
        print(f"ID: {self.id}")
        print(f"Name: {self.name}")

class Student(Person):
    def __init__(self, id, name, academic_marks, sports_marks=None):
        super().__init__(id, name)
        self.academic_marks = academic_marks
        self.sports_marks = sports_marks

    def display_details(self):
        super().display_details()
        print(f"Academic Marks: {self.academic_marks}")

        if self.sports_marks is not None:
            print(f"Sports Marks: {self.sports_marks}")
            total_marks = self.academic_marks + self.sports_marks
            print(f"Total Marks (Including Sports): {total_marks}")
        else:
            print(f"Total Marks (Without Sports): {self.academic_marks}")

def main():
    student1 = Student(101, "Alice", 85)
    print("Details of Student 1:")
    student1.display_details()

    student2 = Student(102, "Bob", 80, 15)
    print("\nDetails of Student 2:")
    student2.display_details()

if __name__ == "__main__":
    main()
