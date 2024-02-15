// task2.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>

void writing_in_file(const std::string& file_name, const std::string& str) {
    std::fstream myfile;

    myfile.open(file_name, std::ios::out);//write
    if (myfile.is_open()) {
        myfile << str << std::endl;
        myfile.close();
    }
}
void reading_from_file(const std::string& file_name) {
    std::fstream myfile;
    myfile.open(file_name, std::ios::in);//read 
    if (myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {//every single line of text
            //it reads from this file
            std::cout << line << std::endl;
        }
        myfile.close();
    }
}
void removeSecondLine(const std::string& file_name) {

    std::fstream read_file;
    read_file.open(file_name);
    if (!read_file.is_open()) {
        std::cout << "Error openning file " << std::endl;
    }
    std::vector<std::string>lines;
    std::string line;

    while (getline(read_file, line)) {
        lines.push_back(line);
    }
    read_file.close();

    std::ofstream write_file;
    write_file.open(file_name);
    if (!write_file.is_open()) {
        std::cout << "error writing  file" << std::endl;

    }
    for (int i = 0; i < lines.size(); i += 2) {
        write_file << lines[i] << std::endl;
    }
}
void reverse_words_in_lines(const std::string& file_name) {
    std::fstream read_file;
    read_file.open(file_name);
    if (!read_file.is_open()) {
        std::cout << "Error openning file " << std::endl;
    }
    std::vector<std::string>lines;
    std::string line;

    while (getline(read_file, line)) {
        lines.push_back(line);
    }
    read_file.close();

    std::ofstream write_file;
    write_file.open(file_name);
    if (!write_file.is_open()) {
        std::cout << "error writing  file" << std::endl;

    }
    for (int i = 0; i < lines.size(); ++i) {
        std::reverse(lines[i].begin(), lines[i].end());
        write_file << lines[i] << std::endl;
    }
}

int main()
{
    std::string file_name = "newmyfile.txt";
    std::string str = " Xachik:\n Vachik:\n Hrachik:\n Qajik:";
    writing_in_file(file_name, str);
    std::cout << "original file :" << std::endl;
    reading_from_file(file_name);
    reverse_words_in_lines(file_name);
    std::cout << "after reverse every line :" << std::endl;
    reading_from_file(file_name);
    removeSecondLine(file_name);
    std::cout << "after remove every seconf line :" << std::endl;
    reading_from_file(file_name);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
