# MINISHELL
minishell is a Unix-like shell written in [C](https://en.wikipedia.org/wiki/C_(programming_language)) language by [@xperaz](https://github.com/xperaz) and [@Ouzzhamza](https://github.com/Ouzzhamza), this shell was inspired by [Bash](https://en.wikipedia.org/wiki/Bash_(Unix_shell)).
This project was done in pairs.
## Content
- [Instructions](#features)
- [Brief Summary](#brief-summary) 
- [Resources](#resources)

# Instructions
project must be written in C.

- Our functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors. If this happens, The project will be
considered non functional and will receive a 0 during the evaluation.

- All heap allocated memory space must be properly freed when necessary. No leaks
will be tolerated.

-  Must submit a Makefile which will compile Our
source files to the required output with the flags -Wall, -Wextra and -Werror, use
cc, and your Makefile must not relink.

- Our Makefile must at least contain the rules $(NAME), all, clean, fclean and
re.

- We allowed to use libft (consists of coding basic and useful C functions).


Your shell should:
- Display a prompt when waiting for a new command.
- Have a working history.
- Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).
- Not use more than one global variable. Think about it. You will have to explain
its purpose.

- Not interpret unclosed quotes or special characters which are not required by the
subject such as \ (backslash) or ; (semicolon).
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- Implement redirections:
  - < should redirect input.
  - > should redirect output.
  - << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history
  - >> should redirect output in append mode.
  
- Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.

- Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.

- Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.

- Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
- In interactive mode:
  - ctrl-C displays a new prompt on a new line.
  - ctrl-D exits the shell.
  - ctrl-\ does nothing.
  
- Your shell must implement the following builtins:
  - echo with option -n
  - cd with only a relative or absolute path
  - pwd with no options
  - export with no options
  - unset with no options
  - env with no options or arguments
  - exit with no options

# Brief Summary
A minishell (in it's simplest form) will extract a full command line (breaking the while loop when it reaches \n) and analyzing it. To follow the initial logic, we're using readline() function.\
This `command line` goes through many phases before being executed and showing the result.

First it goes through a [toknizer](/sources/parse/tokenizer.c), which splits the input into a "valid" list of tokens.

Second, [Syntax validation](/sources/parse/syntax_validation.c): It goes through the doubly linked list of tokens,
and checks for syntax errors at every node. This is done by looking at the left and the right of the current node.
if some strange or some unexpected token is encountered, an error is printed to `stderr`.
[Bellow](#syntax-rules) are the rules of the syntax analyser.
      
third, the [expander](/sources/parse/expander.c) wich expand variables to their values.
    
Last, the [parser](/sources/parse/parser.c) regroup list of command to be sent to the executor wich the final step of the project.
    
## Syntax Rules
````
- UNEXPECTED TOKENS:
	- `;;' (this token is always unrecognized in bash and zsh shells)

* AND, OR, PIPE, FG, BG:
	- left: [WSPACE] (STRING | CPAR)
	- right: [WSPACE] (STRING | REDIRECT | OPAR | if <FG, BG> ENDOFCMD)

* OPAR "(":
	- left: CMDBEGIN | [WSPACE] (AND | OR | PIPE | OPAR)
	- right: [WSPACE] (STRING | REDIRECT | OPAR)

* CPAR ")":
	- left: [WSPACE] (STRING | CPAR)
	- right: [WSPACE] (AND | OR | PIPE | CPAR | ENDOFCMD)

* REDIRECT:
	- right: [WSPACE] STRING

* PARENTHESES MATCHING AND QUOTING:
	- inside each pair parentheses should not be an empthy command.
	- every open parentheses has to have a matching closing parentheses.
	- every single/double quote have to be closed.
````

# Resources
- [minishell docs](https://harm-smits.github.io/42docs/projects/minishell)
- [minishell Materials](https://www.notion.so/Minishell-Materials-7bbd45a806e04395ab578ca3f805806c)
- [XV6's Shell Code Explained - A great source of inspiration](https://www.youtube.com/playlist?list=PLbtzT1TYeoMhF4hcpEiCsOeN13zqrzBJq)
