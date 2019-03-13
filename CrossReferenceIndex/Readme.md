When building a compiler for a programming language or a database, one aspect of the process must take care of the cross-reference index structure in order to allows an easier access to specific elements. In our case, we were asked to write a program that while reading a text file collects all words of the text and retains the numbers of the lines in which each word occurred. For this program a word has been defined as any sequence of letters that star with a letter. The end of the file is denoted by the pound “#” sign. While reading the text file, if we encounter a comma “,” or a point “.” or a blank space, all of those get ignored. In order to solve this problem, I have come up with two solutions. One solution makes the use of array and the second one uses a single structure to store the words.
                                                          SOLUTIONS
•	Solution 1: Using Array to store words and attribute before insertion into BST.
	We will first have a structure that will hold a string and an integer.
	We will create and array that will be used to hold a certain amount of structures (The one created above).
	When we begin reading information from the input file, each line of the file will be read into the array of structure that we created above along with each line numbers.
	After obtaining that array we will make use of a for loop and transform each element of the previously obtain array to change the strings (lines) into stream.
	After that process we are going to use the streams and get the word by using a space delimiter.
	Each word that we get will be store into a structure accompanied by the line at which that have been found at.
	The structure of word will then be stored into an array.
	At this point we have an array that contain the list of word in the text file and accompanied by their line number.
	Since we have the full list of word and their line number, we will just add them into the Binary search tree and print them out.

•	Solution2: Inserting the word and attribute right after generation into BST
	 We will first have a structure that will hold a string and an integer.
	When we begin reading information from the input file, each line of the file will be read into a structure that will hold the entire line and the corresponding line number.
	After the obtention of the line, it will be converted to a stream.
	After that process we are going to use the stream and get the word by using a space delimiter.
	Each word that we get will be store into a structure accompanied by the line at which that have been found at.
	This process will be repeated until all the line of the file have been streamed





SOLUTION ANALYSIS
•	Solution 1 Analysis: After a deep analysis of solution one, we concluded that it is a good solution if we already know the number of line and the number of words that we have in a specific text file. However, we don’t want to write a program that only solve a problem for one single case. We want to be able to expand our solution to any type of object dealing with the same problem.
•	Solution 2 Analysis: This solution is the best out of the two solution because it uses less space in the memory and with this solution, we can use the same space to store different information. Also, this solution can be used to solve this same problem no matter the size of the input.


