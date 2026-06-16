This project has been created as part of the 42 curriculum by <ribresci>.

get_next_line()

DESCRIPTION
The get_next_line project implements a function that reads from a file descriptor and returns one line per call, including the newline character when present. It introduces key concepts such as buffered reading, static variables, memory allocation, and efficient string manipulation. The objective is to design a robust algorithm capable of handling partial reads, arbitrary buffer sizes, end‑of‑file conditions, and memory management without leaks.

COMPILATION
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

EXECUTION
Use get_next_line() inside a loop, free each returned line, and close the file descriptor after reading.

ALGORITHM EXPLANATION
The algorithm uses a static stash to store unread data between calls. This strategy minimizes system calls by reading in chunks and reusing leftover data, handles lines split across multiple reads, and ensures that data is preserved until a newline is encountered. The implementation separates responsibilities clearly: read_buff() reads from the file descriptor and expands the stash, create_line() allocates and extracts the next line, and copy_stash() updates the stash after extraction.

Algorithm Flow
Read from the file descriptor into a temporary buffer. Append the buffer to the stash. Stop reading when a newline is found or when EOF is reached. Extract the next line from the stash. Shift the stash to remove the returned line. This approach ensures predictable behavior, efficient memory usage, and avoids unnecessary reallocations.

RESOURCES
42 subject PDF and online researches

AI USAGE
AI was used only to help structure and refine the README text. All code, debugging, and implementation decisions were done manually.