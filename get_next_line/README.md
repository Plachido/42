The aim of this project is to make a function that returns a line ending with a newline, read from a file descriptor. This code is written in accordance to the Norme, and has been graded 115/100 from deepthought.

**NOTES**:<br> 
`get_next_line_bonus.c`, `get_next_line_utils_bonus.c` and `get_next_line_bonus.h` are identical to `get_next_line.c`, `get_next_line_utils.c` and `get_next_line.h` (except for the identifiers in the header files). This is due to subject requirements.

**TEST FILES:**<br>
Inside the tester folder, two c files can be found: `compare.c` and `tester.c`. They both need to be compiled specifing in the following manner, specifing `BUFFER_SIZE`.

`$gcc compare.c -D BUFFER_SIZE=42`

It is possible to compile the tester in the same way, just replacing `compare.c` with `tester.c`.
In order to test or compare the function with one perfectly working on a specific file, the path to the file to be read has to get passed, as well as the number of rows. This last parameter can be omitted, and the first 200 lines will be used.

Example on `tester.c`:<br>
```
$./a.out text/empty
TESTING...OK
$
```
The `text` folder contains many useful test files, containing particular cases. Many of them are taken from [gnlTester](https://github.com/Tripouille/gnlTester).
The `correct_gnl` folder contains @rchallie 's get_next_line project. This is used inside the testing codes.

**KNOWN ISSUES:**<br>
Under some conditions, the `get_next_line` function fails to return the right value on the last line. 

Example on only known case:
<pre>
$gcc tester.c -D BUFFER_SIZE=65
$./a.out text/64bit_paragraph.txt
EXPECTED: nGGFagT3LdHJick2uNZxkQS2wqHJjf2Zk0IM1fzUOUhNM3aRt+/lfXdklFlR26jx	0
ACTUAL:&nbsp;&nbsp;&nbsp;nGGFagT3LdHJick2uNZxkQS2wqHJjf2Zk0IM1fzUOUhNM3aRt+/lfXdklFlR26jx	1
$
