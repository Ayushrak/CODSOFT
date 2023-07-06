#include <iostream>
#include <fstream>
#include <string>

int countWords(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "File not found." << std::endl;
        return 0;
    }

    std::string word;
    int word_count = 0;

    while (file >> word) {
        word_count++;
    }

    return word_count;
}

int main() {
    std::string file_name;
    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    int total_words = countWords(file_name);
    std::cout << "Total words: " << total_words << std::endl;

    return 0;
}
