#include <string>
#include "ConsoleInterface.h"

using namespace std;

void ConsoleInterface::run() {
    running = true;
    cout << "Учёт абстрактных позиций" << endl;

    while (running) {
        cout << endl;
        cout << "Выберите действие:" << endl
             << "1 - Добавить позицию" << endl
             << "2 - Удалить позицию" << endl
             << "3 - Вывести список позиций" << endl
             << "4 - Выполнить текстовый поиск позиции" << endl
             << "5 - Выход" << endl;

        int choice = 0;

        cin >> choice;

        switch (choice) {
            case 1:
                addPosition();
                break;

            case 2:
                removePosition();
                break;

            case 3:
                getAllPositions();
                break;

            case 4:
                searchPositions();
                break;

            case 5:
                running = false;
        }
    }
}

void ConsoleInterface::addPosition() {
    string data;

    cout << "Введите данные для добавления: ";
    cin.ignore();
    getline(cin, data);

    Position position(data);
    list.addPosition(position);
}

void ConsoleInterface::removePosition() {
    int choice;

    while (choice > 2 || choice < 1) {

        cout << "Каким образом вы хотите удалить позицию?" << endl
             << "1 - По номеру элемента" << endl
             << "2 - По данным в позиции" << endl;

        cin >> choice;
    }

    try {
        switch (choice) {
            case 1:
                int index;

                cout << "Введите номер элемента, который вы желаете удалить: ";
                cin >> index;
                list.removePosition(index - 1);
                break;

            case 2:
                string data;

                cout << "Введите данные в позиции, которую вы желаете удалить: ";
                cin.ignore();
                getline(cin, data);
                list.removePosition(data);
        }
    } catch (out_of_range) {
        cout << "Элемент не найден" << endl;
    }
}

void ConsoleInterface::getAllPositions() {
    if (list.getAllPositions().empty()) {
        cout << "Список позиций пуст" << endl;
    }
    for (int index = 0; index < list.getAllPositions().size(); index++) {
        cout << index + 1 << ") " << list.getAllPositions()[index].getData() << endl;
    }
}

void ConsoleInterface::searchPositions() {
    string data;

    cout << "Введите данные по позициям, которые вы хотите найти: ";
    cin.ignore();
    getline(cin, data);

    if (list.searchPositions(data).size() > 0) {
        for (int index = 0; index < list.searchPositions(data).size(); index++) {
            cout << list.searchPositions(data)[index].getData() << endl;
        }
    } else {
        cout << "Позиции с такими данными не найдены" << endl;
    }
}