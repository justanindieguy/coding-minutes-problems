#include <iostream>
#include <cstring>
using namespace std;

char *myStringTokenizer(char *str, char delim)
{
    static char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }

    if (input == NULL)
    {
        return NULL;
    }

    char *token = new char[strlen(input) + 1];
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] != delim)
        {
            token[i] = input[i];
            i++;
        }
        else
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }

    // Last token after last delimiter
    token[i] = '\0';
    // Reset the input as NULL
    input = NULL;

    return token;
}

int main()
{
    char s[1000];
    cin.getline(s, 1000);

    char *token = myStringTokenizer(s, ' ');
    while (token != NULL)
    {
        cout << token << endl;
        token = myStringTokenizer(NULL, ' ');
    }

    return 0;
}
