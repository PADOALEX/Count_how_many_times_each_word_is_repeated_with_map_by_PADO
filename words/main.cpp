#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (true)
    {
        cout << "\n----- ���� -----\n";
        cout << "1 - ���������� ����� � ������������ �����\n";
        cout << "2 - ���������� ����� � �����\n";
        cout << "3 - �����\n";
        cout << "������ �����: ";
        int option;
        cin >> option;
        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "������ ��������.\n";
            continue;
        }
        if (option == 1)
        {
            vector<string> words;
            string word;
            int count;
            cout << "������ ��� �� ������ ������? ";
            cin >> count;
            if (!cin || count <= 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "������ ����� ���.\n";
                continue;
            }
            cout << "������ " << count << " ���:\n";
            for (int i = 0; i < count; i++)
            {
                cin >> word;
                words.push_back(word);
            }
            map<string, int> counter;
            for (auto& w : words)
            {
                counter[w]++;
            }
            cout << "\n���������:\n";
            for (auto& p : counter)
            {
                cout << p.first << " - " << p.second << "\n";
            }
        }
        else if (option == 2)
        {
            cin.ignore(10000, '\n');
            cout << "������ ���� �� �����: ";
            string filepath;
            getline(cin, filepath);
            ifstream file(filepath);
            if (!file.is_open())
            {
                cerr << "�� ������� ������� ����!\n";
            }
            else
            {
                vector<string> words;
                string word;
                while (file >> word)
                {
                    words.push_back(word);
                }
                file.close();
                map<string, int> counter;
                for (auto& w : words)
                {
                    counter[w]++;
                }
                cout << "\n���������:\n";
                for (auto& p : counter) {
                    cout << p.first << " - " << p.second << "\n";
                }
            }

        }
        else if (option == 3)
        {
            cout << "�����.\n";
            break;
        }
        else
        {
            cout << "������ �����!\n";
        }
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return 0;
}
