#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() 
{
    //���� �������
    map<int, string> myMap = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"}
    };

    // ��������� ������� � ��������� ������
    auto last = prev(myMap.end());
    string deletedValue = last->second;
    myMap.erase(last);

    // �������� �������� ���������� ����� �� �������� �������� ���������� �����
    auto first = myMap.begin();
    first->second = deletedValue;

    // �������� ��������� � json ����
    ofstream outFile("result.json");
    if (outFile.is_open()) 
    {
        outFile << "{";
        for (auto it = myMap.begin(); it != myMap.end(); ++it) 
        {
            outFile << "\"" << it->first << "\":\"" << it->second << "\"";
            if (it != prev(myMap.end())) 
            {
                outFile << ",";
            }
        }
        outFile << "}";
        outFile.close();
    }

    return 0;
}
