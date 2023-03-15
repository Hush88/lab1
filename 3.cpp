#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    // ��������� �������� ����� � ������ �� �� ���
    map<string, int> products = 
    {
        {"Apple", 150},
        {"Banana", 200},
        {"Orange", 250},
        {"Pear", 300},
        {"Mango", 350},
        {"Pineapple", 400},
        {"Grapefruit", 450}
    };


    // ��������� ������ �� �� ����� �����
    map<string, int> cheaper_products;
    map<string, int> expensive_products;

    copy_if(products.begin(), products.end(),
        inserter(cheaper_products, cheaper_products.end()),
        [](const auto& product) { return product.second < 300; });

    copy_if(products.begin(), products.end(),
        inserter(expensive_products, expensive_products.end()),
        [](const auto& product) { return product.second >= 300; });

    // ��������� ����������
    cout << "Cheaper products:\n";
    for (const auto& product : cheaper_products) {
        cout << product.first << " - " << product.second << " UAH\n";
    }

    cout << "\nExpensive products:\n";
    for (const auto& product : expensive_products) {
        cout << product.first << " - " << product.second << " UAH\n";
    }

    return 0;
}
