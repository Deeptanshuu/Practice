class Student:
    def __init__(self, roll_no, name, marks):
       
        self.roll_no = roll_no
        self.name = name
        self.marks = marks

    def display_details(self):
        print(f"Student Roll Number: {self.roll_no}")
        print(f"Student Name: {self.name}")
        print(f"Student Marks: {self.marks}")

student1 = Student(101, "Alice", [85, 90, 88])

print("Details of the Student class and the object created:")
student1.display_details()

