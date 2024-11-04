# Book Similarity Checker



##Project Description


       A simple (but crude) way to measures similarity is given as following:

- Identify top 100 frequent (normalize) occurring words in a text file. Consider only
numeric character and alphabet character (by converting both small and capital
alphabets to capital form) of the text file. Normalize the word count of a file by
dividing total number of words in the file.

- Remove commonly occurring six specific words “a”, “and”, “an” , “of” “in” and
“the” from the file at the time of counting frequent word, total number of word
and the normalize frequency.

- Similarity index of two files can be calculated as sum of normalize value of all the frequent words occurred in both the files.

- Create a 64x64 size similarity matrix.

- Report top ten similar pairs of text books using the similarity matrix. You need to
exclude the self similarity.



 
## Overview

The Book Similarity Checker is a C++ program designed to analyze and identify similar pairs of textbooks based on their texts. By calculating the normalized frequency of words in each book, the program generates a similarity index that allows users to determine how closely related different texts are. This tool is particularly useful for researchers, educators, and librarians who wish to explore relationships between literary works.



## Features

- **Text Processing**: Reads text files from the local directory and processes them to extract word frequencies.

- **Normalization**: Converts all words to uppercase and filters out non-alphanumeric characters. Commonly occurring words such as `` "a", "and", "an", "of", "in", and "the" `` are excluded from the analysis.

- **Similarity Calculation**: Computes a similarity index for each pair of books based on their normalized word frequencies.

- **Top Similarity Reporting**: Outputs the top ten pairs of similar textbooks, excluding self-similarity.



## Use Cases

1. **Literary Analysis**: Researchers can use this tool to study thematic similarities between different literary texts, helping to identify influences or common motifs across authors or genres.

2. **Plagiarism Detection**: Educators can leverage this program to compare student submissions against a database of textbooks to detect potential plagiarism or unoriginal content.
d
3. **Library Management**: Librarians can utilize the similarity indices to categorize books more effectively, suggesting related readings to patrons based on textual similarities.

4. **Content Recommendation Systems**: Developers can integrate this program into recommendation systems for online bookstores or libraries, providing users with suggestions for similar books based on content analysis.

5. **Historical Research**: Historians can analyze texts from different periods to understand how language and themes have evolved over time.



## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, Visual Studio)
- Basic knowledge of C++ programming
- Text files containing the books you want to analyze (64 specified **text files should be placed in the same directory as the program**)
- Filesystem Library Support: The program utilizes the <filesystem> library, which is standard in C++17 and later.

**This Project Uses These STLS**

`` <iostream>  <sstream> <string> <vector> <map> <algorithm> <cctype> <set>

``


### Installation

1. Clone or download this repository.
2. Place all specified text files in the same directory as the `SimilarityChecker.cpp` file.
3. Open a terminal or command prompt and navigate to the directory containing the program.
4. Compile the program using:
   ```
   g++ SimilarityChecker.cpp

# Expected Output

```

Top 10 similar book pairs:
Books XX.txt and XY.txt are similar with similarity score: X.XX

```

## Acknowledgement 

 This is a project programmed by Subrata Choudhury with Registation No : IITGCS 24061306


 I would like to express my sincere gratitude to Dr Sahu Sir, and our Respective Mathematics Projessors and the TAs and GM sir and rest teaching staffs for their invaluable support and guidance throughout the development of this project and my academic period. 

 Also Special Thanks to Open Source Community - For the wealth of knowledge shared through forums, documentation, and tutorials that facilitated the learning process and helped overcome technical challenges during development.

 This project has been a valuable learning experience, enhancing my programming skills and deepening my understanding of text analysis techniques. I look forward to applying these skills in future endeavors.


Thank you! 


feel free to modify the codes and bookfiles according to your needs.

