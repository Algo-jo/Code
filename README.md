📝 Description

Wordlibrary is a command-line dictionary application that allows users to store, search, and manage slang words along with their descriptions. This program is built using a Trie (Prefix Tree) data structure for efficient word search and prefix-based operations.

💡 Features
1. Add New Slang Words
- Input new slang words (must be >1 character with no spaces)
- Add descriptions (must be >1 word)
- Automatically updates existing words

2. Search Functionality
- Search for exact slang word matches
- View word descriptions

3. Prefix Search
- View all words starting with a given prefix

4. View All Words
- Display all slang words in alphabetical order with numbering

👷‍♂️ How It Works
1. Uses a struct data node with:
- 26 children (one for each lowercase English letter)
- A flag to mark if a word ends at this node (isAWord)
- A description string for the slang word

2. Trie traversal is used for insertion and search operations.
  
3. Words and descriptions are validated to ensure:
- Slang words must be >1 character and must not contain spaces
- Descriptions must contain at least two words

🧠 To Use the Program
1. Compile the Program
- gcc -o wordlbrary slang_dictionary.c
  
2. Run the Program
- ./wordlibrary

3. Use the menu
- Add new slang words (Option 1)
- Search for words (Option 2)
- View words by prefix (Option 3)
- View all words (Option 4)
- Exit the program (Option 5)

🧼 Input Validation
All input is validated before processing to ensure consistency and prevent malformed entries. Validation will be informed inside a [] bracket such as "Input a new slang word [Must be more than 1 characters and contains no space]: "

⚙️ Example of Usage
Wordlibrary
Select Menu Below
1. Release a new slang word
2. Search a slang word
3. View all slang word starting with a certain prefix word
4. View all slang word
5. Exit
>> 1
Input a new slang word [Must be more than 1 characters and contains no space]: gigachad
Input a new slang word description [Must be more than 1 word]: the ultimate lifeform

Successfully added a new slang word
Press enter to continue...

🔚 Exit Message
If Program is runned succesfully, an exit message will be appear: "Thank you... Have a nice day!"

✍️ Author
Johannes Aaron Framon

📒 Notes
- The program uses dynamic memory allocation for the trie structure
- All memory is automatically managed by the program
- The interface is console-based with simple text input/output
