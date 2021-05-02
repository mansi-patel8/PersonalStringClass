/*
* Name: Mansi Patel
* File: String.cpp
*/

#include "String.h"

str::str() : _n(0), _buf(0)
{
}

str::str(int n) : _n(n)
{
    _buf = new char[_n];
}

str::str(char ch) : _n(1)
{
    _buf = new char[_n];
    _buf[0] = ch;
}

str::str(const char* c_str)
{
    _n = strlen(c_str);
    _buf = new char[_n];
    for (int i = 0; i < _n; i++)
    {
        _buf[i] = c_str[i];
    }
}

str::~str()
{
    if (_buf)
        delete[] _buf;
}

ostream& operator<<(ostream& os, const str& s)
{
    if (!s.is_empty())
    {
        for (int i = 0; i < s.length(); ++i)
        {
            cout << s[i];
        }
    }
    else
        cout << "[null str]";

    return os;
}

istream& operator>>(istream& is, str& s)
{
    char ch;
    do
    {
        ch = is.get();
        if (ch == ' ' || ch == '\n')
            break;
        s = s + ch;
    } while (true);

    return is;
}

// assignment operator
const str& str::operator=(const str& s)
{
    //size for the new temp _buf char
    _n = s.length();

    //assigning _buf memory from heap
    _buf = new char[_n];

    //for loop to set _buf = passed string (s)
    for (int i = 0; i < _n; i++)
    {
        _buf[i] = s[i];
    }

    return *this;
}

// concatenation operator
str operator+(const str& a, const str& b)
{
    //size for the new temp string char array
    int size = a.length() + b.length();

    //createing char *tempString to store concatenated string
    char* tempString = new char[size];

    //setting tempString to empty
    tempString[size] = { '\0' };

    //loop counter initialization
    int i = 0, j = 0;

    //for loop to go through the first string argument
    for (i; i < a.length(); i++)
    {
        //concatenate a into tempString[i]
        tempString[i] = a.operator[](i);
    }

    //for loop to go through second string argument
    //here we have i and j in the for loop - i will start at the next index of the first string's last index
    //meaning in our case, i starts at 0 and a = Hello so tempString[i = 4] = hello so now i = 5
    // and j will start at 0
    for (i, j; j < b.length(); j++, i++)
    {
        //concatenate b into tempString[i]
        tempString[i] = b.operator[](j);
    }

    return tempString;
}
