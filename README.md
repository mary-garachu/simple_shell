Simple Shell project built by Mary Garachu and Kevin Kipngeno
Simple shell
Main function - Takes user input or checks to see if commands have been passed through the terminal
It creates a child process
get_line_function
- uses getline();
- passes the strings using strtok command into an array of tokens.
line_to_array
- allocates memory for the array of string
- dynamically passes the strings into an array
- Frees memory when the function is complete
execute_token
- runs the execve function
- added exit function
