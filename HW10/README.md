Given a text file, find 5 most frequent words and their frequency.

User input should be the file name of a text file. ('input1.txt' or 'input2.txt’)
Read all the lines from the text.
For each line, parse the line into words (use the white space as a delimiter)
Before parsing, replace punctuations by ‘ ‘(whitespace) and parse.
That is, consider only alphanumerics.
Count the frequency of the words ignoring case.
Sort the word by the count.
Select a sorting algorithm from the slide and implement it (please provide a comment on why you select the algorithm) 
If they have the same frequency, then sort them by the alphabetical order of the words.
Print the 5 most frequent words with their frequency in upper character.
You can assume that the maximum number of word is 2048.
i.e, the cardinality (size) of the unique word set is 2048 at most.
 

Example

given a text file as follows: 

In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification [1][2][3]. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data [4].

 

Your output on the screen should be as follows: 

DATA: 5
A: 4
AND: 3
THE: 3
IS: 2