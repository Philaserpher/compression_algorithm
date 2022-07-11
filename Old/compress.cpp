#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string basic_compression(string original_str)
{
    string output_str = "";
    int repeat_counter = 1;
    char current_character = original_str[0];

    for (int i = 1; i < original_str.length(); i++)
    {
        if (original_str[i] == current_character)
        {
            repeat_counter++;
        }
        else
        {
            if (repeat_counter == 1)
            {
                output_str += current_character;
            }
            else
            {
                output_str += current_character + to_string(repeat_counter);
                repeat_counter = 1;
            }
            current_character = original_str[i];
        }
    }
    if (repeat_counter == 1)
    {
        output_str += current_character;
    }
    else
    {
        output_str += current_character + to_string(repeat_counter);
    }
    return output_str;
}

string read_file(string file_name)
{
    string my_str = "";
    ifstream read_file;
    read_file.open(file_name);
    if (read_file.is_open())
    {
        stringstream strStream;
        strStream << read_file.rdbuf();
        my_str += strStream.str();
        read_file.close();
    }
    return my_str;
}

void write_file(string file_name, string write_text)
{
    ofstream write_file;
    write_file.open(file_name);
    if (write_file.is_open())
    {
        write_file << write_text;
        write_file.close();
    }
}

int main()
{
    string my_str = read_file("original_text.txt");
    string my_str_comp = basic_compression(my_str);
    write_file("compressed_text.txt", my_str_comp);
}