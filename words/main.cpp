#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    while (true)
    {
        cout << "\n----- Меню -----\n";
        cout << "1 - Порахувати слова зі стандартного вводу\n";
        cout << "2 - Порахувати слова з файлу\n";
        cout << "3 - Вийти\n";
        cout << "Оберіть опцію: ";
        int option;
        cin >> option;
        if (cin.eof()) return 0;
        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Невірне введення.\n";
            continue;
        }
        if (option == 1)
        {
            map<string, int> counter;
            string word;
            int count;
            cout << "Скільки слів ви хочете ввести? ";
            cin >> count;
            if (cin.eof()) return 0;
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
                if (!(cin >> word)) return 0;
                ++counter[word];
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
                map<string, int> counter;
                string word;
                while (file >> word)
                {
                    ++counter[word];
                }
                file.close();

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
