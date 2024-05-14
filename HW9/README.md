Implement a program to revise a text file with a given map file and print the revised text.

User Input: a text file name, a map file name
Output on the screen: the revised text
The format of each line in the map file is defined by

SOURCE_WORD: TARGET_WORD

Build up a binary search tree with the map file. 

Use the source word as a key and the target word as data.
Do not ignore case or punctuation marks.
 

Example) 

input text file (could include many lines):
Barack Hussein Obama is an American politician who is the 44th

and current President of the united States.

map file (text):
Hussein: H.

current: previous

united: United

 

output on the screen:
Barack H. Obama is an American politician who is the 44th

and previous President of the United States.