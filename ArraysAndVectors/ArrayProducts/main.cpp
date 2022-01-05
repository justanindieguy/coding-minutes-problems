#include <iostream>
#include <vector>
using namespace std;

// Not allowed but implemented to practice
vector<int> arrayProductsDivision(vector<int> arr)
{
    int n = arr.size();
    int arrayProduct = 1;
    vector<int> products(n, 0);

    for (auto num : arr)
        arrayProduct *= num;

    for (int i = 0; i < n; i++)
        products[i] = arrayProduct / arr[i];

    return products;
}

vector<int> arrayProductsOptimal(vector<int> arr)
{
    int n = arr.size();
    vector<int> products(n, 0);
    vector<int> leftProducts(n, 0);
    vector<int> rightProducts(n, 0);

    int leftProduct = 1;
    for (int i = 0; i < n; i++)
    {
        leftProduct *= arr[i];
        leftProducts[i] = leftProduct;
    }

    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        rightProduct *= arr[i];
        rightProducts[i] = rightProduct;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            products[i] = rightProducts[1];
        else if (i == n - 1)
            products[i] = leftProducts[n - 2];
        else
            products[i] = leftProducts[i - 1] * rightProducts[i + 1];
    }

    return products;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> result = arrayProductsDivision(arr);

    for (auto num : result)
        cout << num << ", ";
    cout << endl;

    return 0;
}
