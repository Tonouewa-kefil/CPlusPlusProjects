#include <iostream>

using namespace std;

string typedString(string str)
{
    int i = 0;
    int j = 0;
    string typed = "";
    cout << typed;
    while (str[i] != '\0')
    {
        if (str[i] == '#')
        {
            if (typed[0] == '\0')
            {
                j == 0;
            }
            else
            {
                typed[--j] = '\0';
            }
        }
        else
        {
            typed[j] = str[i];
            j++;
        }
        i++;
    }
    cout << typed;
    return typed;
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    s = typedString(s);
    t = typedString(t);
    if (s == t)
    {
        return true;
    }
    return false;

    return 0;
}