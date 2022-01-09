#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    // Create a string stream object
    stringstream ss(input);

    // >> and << operators
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    // Print all tokens
    for (auto token : tokens)
    {
        cout << token << ", ";
    }
    cout << endl;

    return 0;
}
