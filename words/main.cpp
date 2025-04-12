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
        cout << "\n----- Меню -----\n";
        cout << "1 - Порахувати слова зі стандартного вводу\n";
        cout << "2 - Порахувати слова з файлу\n";
        cout << "3 - Вийти\n";
        cout << "Оберіть опцію: ";
        int option;
        cin >> option;
        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Невірне введення.\n";
            continue;
        }
        if (option == 1)
        {
            vector<string> words;
            string word;
            int count;
            cout << "Скільки слів ви хочете ввести? ";
            cin >> count;
            if (!cin || count <= 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Невірне число слів.\n";
                continue;
            }
            cout << "Введіть " << count << " слів:\n";
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
            cout << "\nРезультат:\n";
            for (auto& p : counter)
            {
                cout << p.first << " - " << p.second << "\n";
            }
        }
        else if (option == 2)
        {
            cin.ignore(10000, '\n');
            cout << "Введіть шлях до файлу: ";
            string filepath;
            getline(cin, filepath);
            ifstream file(filepath);
            if (!file.is_open())
            {
                cerr << "Не вдалось відкрити файл!\n";
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
                cout << "\nРезультат:\n";
                for (auto& p : counter) {
                    cout << p.first << " - " << p.second << "\n";
                }
            }

        }
        else if (option == 3)
        {
            cout << "Вихід.\n";
            break;
        }
        else
        {
            cout << "Невірна опція!\n";
        }
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return 0;
}
