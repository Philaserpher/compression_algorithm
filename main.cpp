// using namespace std;
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

string unpack(string original_str)
{
    string output_str = "";
    char previous_character = original_str[0];
    bool number_found = false;

    for (int i = 1; i < original_str.length(); i++)
    {
        if (number_found)
        {
            number_found = false;
            previous_character = original_str[i];
            continue;
        }
        if (isdigit(original_str[i]))
        {
            for (int j = 0; j = isdigit(original_str[i]); j++)
            {
                output_str += previous_character;
                number_found = true;
            }
        }
        else
        {
            output_str += previous_character;
            previous_character = original_str[i];
        }
    }
    output_str += previous_character;
    return output_str;
}

int main()
{
    string my_str = "";
    ifstream read_file;
    read_file.open("text.txt");
    if (read_file.is_open())
    {
        stringstream strStream;
        strStream << read_file.rdbuf();
        my_str += strStream.str();
        read_file.close();
    }
    string my_str_comp = basic_compression(my_str);
    cout << my_str_comp;
    return 0;
}