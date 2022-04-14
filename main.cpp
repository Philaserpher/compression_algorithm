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

string decompress(string original_str)
{
    string output_str = "";
    char previous_character = original_str[0];
    bool number_found = false;
    char last_letter = original_str[0];
    int string_length = original_str.length();
    for (int i = 1; i < string_length; i++)
    {
        if (number_found)
        {
            number_found = false;
            previous_character = original_str[i];
            continue;
        }
        if (isdigit(original_str[i]))
        {
            int number_of_repeats = original_str[i] - '0';
            for (int j = 1; j <= number_of_repeats; j++)
            {
                output_str += previous_character;
                number_found = true;
            }
        }
        else
        {
            output_str += previous_character;
            previous_character = original_str[i];
            last_letter = original_str[i];
        }
    }
    previous_character = original_str[string_length - 1];
    if (!isdigit(previous_character))
    {
        output_str += previous_character;
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
    string my_str_uncomp = decompress(my_str_comp);
    write_file("uncompressed_text.txt", my_str_uncomp);
    return 0;
}