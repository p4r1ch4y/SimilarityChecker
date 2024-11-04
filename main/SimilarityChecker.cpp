#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// preprocess text file
map<string, double> preprocess_file(const string& filename) {
    // Open the file
    ifstream file(filename);

    // Create a map to store word counts
    map<string, int> word_counts;

    // Initialize a variable to count total words
    int total_words = 0;

    // Read words from the file
    string word;
    while (file >> word) {
        // Convert the word to uppercase
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        // Check if the word is a exclude word
        if (word != "A" && word != "AND" && word != "AN" && word != "OF" && word != "IN" && word != "THE") {
            // Increment the word count
            word_counts[word]++;
            // Increment the total word count
            total_words++;
        }
    }

    // Close the file
    file.close();

    // Normalize word fqn
    map<string, double> normalized_counts;
    for (auto& pair : word_counts) {
        // Calculate the normalized fqn
        double normalized_freq = (double)pair.second / total_words;
        // Adds the normalized frequency to the map
        normalized_counts[pair.first] = normalized_freq;
    }

    return normalized_counts;
}

// Functions to calculate the similarities between two books
double calculate_similarity(const map<string, double>& book1, const map<string, double>& book2) {
    // Initializes a variable to store the similarities
    double similarity = 0.0;

    // Iterate the words in the first book
    for (const auto& pair : book1) {
        // Checks if the word is also in the second book
        if (book2.count(pair.first) > 0) {
            // Calculates the contribution to similarities
            similarity += pair.second * book2.at(pair.first);
        }
    }

    return similarity;
}

int main() {
    // Creates a vector to store filenames
    vector<string> filenames;

    // Iterate over files in the current directory
    for (const auto& entry : fs::directory_iterator(".")) {
        // Checks if the file is a .txt file
        if (entry.path().extension() == ".txt") {
            // Adds the filename to the vector
            filenames.push_back(entry.path().string());
        }
    }

    // Creates a vector to store preprocessed books
    vector<map<string, double>> preprocessed_books;

  // preprocess all books
    for (const string& filename : filenames) {
        // preprocess the books and add it to the vector
        preprocessed_books.push_back(preprocess_file(filename));
    }

    // Creates a similarity matrix
    vector<vector<double>> similarity_matrix(filenames.size(), vector<double>(filenames.size(), 0.0));

    // Calculates similarities between books
    for (int i = 0; i < filenames.size(); ++i) {
        for (int j = i + 1; j < filenames.size(); ++j) {
            // Calculates the similarity between books i and j
            double similarity = calculate_similarity(preprocessed_books[i], preprocessed_books[j]);
            // Stores the similarity in the matrix
            similarity_matrix[i][j] = similarity;
            similarity_matrix[j][i] = similarity;
        }
    }

    // Finds the top 10 similar pairs
    vector<pair<pair<int, int>, double>> similarities;
    for (int i = 0; i < filenames.size(); ++i) {
        for (int j = i + 1; j < filenames.size(); ++j) {
            // Creates a pair of book indices and similarity
            pair<int, int> book_pair = {i, j};
            // Creates a pair of book pair and similarity
            pair<pair<int, int>, double> similarity_pair = {book_pair, similarity_matrix[i][j]};
            // Adds the similarity pair to the vector
            similarities.push_back(similarity_pair);
        }
    }

    // Sorts the similarities in descending order
    sort(similarities.begin(), similarities.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Prints top 10 similar pairs
    cout << "Top 10 similar book pairs:\n";
    for (int i = 0; i < 10; ++i) {
        auto pair = similarities[i].first;
        cout << "Books " << filenames[pair.first] << " and " << filenames[pair.second] << " are similar with similarity score: " << similarities[i].second << endl;
    }

    return 0;
}
