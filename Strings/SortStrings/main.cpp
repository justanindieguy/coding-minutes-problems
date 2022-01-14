/*

Sample Input
____________
3
92 022
82 12
77 13
2 false numeric

Sample Output
_____________
82 12
77 13
92 022

*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string getTokenAt(string str, int key)
{
    char *token = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        token = strtok(NULL, " ");
        key--;
    }

    return (string)token;
}

int parseToInt(string str)
{
    int num = 0;
    int pow = 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        num += (str[i] - '0') * pow;
        pow *= 10;
    }

    return num;
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return key1 < key2;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return parseToInt(key1) < parseToInt(key2);
}

int main()
{
    int n;
    cin >> n;

    cin.get(); // Consume the extra \n

    string temp;
    vector<string> rows;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        rows.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // 1. Store strings with pairs.
    vector<pair<string, string>> rowsKeys;
    for (auto row : rows)
    {
        rowsKeys.push_back({row, getTokenAt(row, key)});
    }

    // 2. Sort
    if (ordering == "numeric")
    {
        sort(rowsKeys.begin(), rowsKeys.end(), numericCompare);
    }
    else
    {
        sort(rowsKeys.begin(), rowsKeys.end(), lexicoCompare);
    }

    // 3. Reversal
    if (reversal == "true")
    {
        reverse(rowsKeys.begin(), rowsKeys.end());
    }

    // 4. Output
    for (auto rowKey : rowsKeys)
    {
        cout << rowKey.first << endl;
    }

    return 0;
}
