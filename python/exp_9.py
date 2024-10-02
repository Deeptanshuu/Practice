import os

def count_file_content(file_name):
    try:
        with open(file_name, 'r') as file:
            lines = file.readlines()
            num_lines = len(lines)
            num_words = sum(len(line.split()) for line in lines)
            num_chars = sum(len(line) for line in lines)
        
        print(f"Lines: {num_lines}, Words: {num_words}, Characters: {num_chars}")
    except FileNotFoundError:
        print(f"Error: {file_name} not found!")
    except Exception as e:
        print(f"An error occurred: {e}")

def display_files_in_directory():
    try:
        files = os.listdir('.')
        print("Files in the current directory:")
        for file in files:
            print(file)
    except Exception as e:
        print(f"An error occurred: {e}")


def main():
    file_name = 'output.txt'
    count_file_content(file_name)
    display_files_in_directory()

if __name__ == "__main__":
    main()
