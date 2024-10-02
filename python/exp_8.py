def read_and_write_file(input_file, output_file):
    try:
        with open(input_file, 'r') as infile:
            content = infile.read()
        
        with open(output_file, 'w') as outfile:
            outfile.write(content)
        
        print(f"Content from {input_file} has been written to {output_file}")
    except FileNotFoundError:
        print(f"Error: {input_file} not found!")
    except Exception as e:
        print(f"An error occurred: {e}")


def append_and_display_file(file_name, data_to_append):
    try:
        with open(file_name, 'a') as file:
            file.write(data_to_append + '\n')
        
        with open(file_name, 'r') as file:
            content = file.read()
            print(f"Updated content of {file_name}:\n{content}")
    except FileNotFoundError:
        print(f"Error: {file_name} not found!")
    except Exception as e:
        print(f"An error occurred: {e}")


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

def main():
    input_file = 'input.txt'
    output_file = 'output.txt'
    data_to_append = 'Appended content'
    
    read_and_write_file(input_file, output_file)
    append_and_display_file(output_file, data_to_append)
    count_file_content(output_file)

if __name__ == "__main__":
    main()
