import tkinter as tk
from tkinter import messagebox
import sqlite3

# Step 1: Database Functions
def create_table():
    conn = sqlite3.connect('student.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS students
                 (roll_no INTEGER PRIMARY KEY, name TEXT, subject1 INTEGER, subject2 INTEGER)''')
    conn.commit()
    conn.close()

def insert_data():
    conn = sqlite3.connect('student.db')
    c = conn.cursor()
    try:
        roll_no = int(entry_roll.get())
        name = entry_name.get()
        subject1 = int(entry_subject1.get())
        subject2 = int(entry_subject2.get())
        c.execute("INSERT INTO students (roll_no, name, subject1, subject2) VALUES (?, ?, ?, ?)",
                  (roll_no, name, subject1, subject2))
        conn.commit()
        entry_roll.delete(0, tk.END)
        entry_name.delete(0, tk.END)
        entry_subject1.delete(0, tk.END)
        entry_subject2.delete(0, tk.END)
        fetch_data()
    except Exception as e:
        messagebox.showerror("Error", f"Could not insert data: {e}")
    conn.close()

def fetch_data():
    conn = sqlite3.connect('student.db')
    c = conn.cursor()
    c.execute("SELECT * FROM students")
    rows = c.fetchall()
    listbox.delete(0, tk.END)  # Clear the listbox before inserting new data
    for row in rows:
        listbox.insert(tk.END, row)
    conn.close()

def delete_data():
    conn = sqlite3.connect('student.db')
    c = conn.cursor()
    try:
        roll_no = int(entry_roll.get())
        c.execute("DELETE FROM students WHERE roll_no=?", (roll_no,))
        conn.commit()
        entry_roll.delete(0, tk.END)
        fetch_data()
    except Exception as e:
        messagebox.showerror("Error", f"Could not delete data: {e}")
    conn.close()

# Step 2: Create the main window
root = tk.Tk()
root.title("Student Database")
root.geometry("500x500")

# Step 3: Widgets for User Inputs
tk.Label(root, text="Roll No:").pack()
entry_roll = tk.Entry(root)
entry_roll.pack()

tk.Label(root, text="Name:").pack()
entry_name = tk.Entry(root)
entry_name.pack()

tk.Label(root, text="Marks for Subject 1:").pack()
entry_subject1 = tk.Entry(root)
entry_subject1.pack()

tk.Label(root, text="Marks for Subject 2:").pack()
entry_subject2 = tk.Entry(root)
entry_subject2.pack()

# Step 4: Buttons to trigger DB Operations
tk.Button(root, text="Insert", command=insert_data).pack()
tk.Button(root, text="Delete", command=delete_data).pack()

# Step 5: Listbox to Display Database Records
listbox = tk.Listbox(root, width=50)
listbox.pack(fill=tk.BOTH, expand=True)

# Step 6: Initialize and Fetch Data
create_table()
fetch_data()

# Step 7: Run the main loop
root.mainloop()
