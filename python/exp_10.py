import sqlite3

# Creating a connection object
conn = sqlite3.connect('student_database.db')
# Creating a cursor object using the connection
cursor = conn.cursor()

# Creating a table in the database
def create_table():
    cursor.execute('''CREATE TABLE IF NOT EXISTS students (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                        name TEXT NOT NULL,
                        age INTEGER NOT NULL,
                        grade TEXT NOT NULL)''')
    print("Table created successfully!")

# Inserting values into the table
def insert_values(name, age, grade):
    cursor.execute('''INSERT INTO students (name, age, grade)
                      VALUES (?, ?, ?)''', (name, age, grade))
    conn.commit()
    print("Values inserted successfully!")

# Displaying values from the table
def display_values():
    cursor.execute('SELECT * FROM students')
    rows = cursor.fetchall()
    for row in rows:
        print(row)

# Updating values in the table
def update_values(student_id, new_grade):
    cursor.execute('''UPDATE students SET grade = ? WHERE id = ?''', (new_grade, student_id))
    conn.commit()
    print("Values updated successfully!")

# Main function
def main():
    create_table()
    insert_values('John Doe', 20, 'A')
    insert_values('Jane Smith', 22, 'B')
    display_values()
    update_values(1, 'A+')
    display_values()

# Calling the main function
if __name__ == "__main__":
    main()

# Closing the connection to the database
conn.close()
print("Connection closed successfully!")
