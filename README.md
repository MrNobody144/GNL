# Get Next Line

- A *42KL* project

- The function allows the user to **extract** a line in the specified file by providing the function the file description of the intended file to extract the line from

- The **extracted line** spans from the start of the file to the first occurrence of a newline character, *'\n'*. It then spans from the last occurrence of, *'\n'* to the next one and finally from the last occurrence of, *'\n'* to EOF, end of file


#Example

1. Test.txt file contains:

   | *This is a test line, the first line in a test file. It doesn't include the opening line character and the closing line character* |

   In the above case, the whole line is returned as it is

2. Test2.txt file contains:

   |*Newline </br> Newline </br> Newline*|

   In the above case, only the frist line, *"Newline"* is returned
