/*!
 * @file
 * @brief ConsoleInterface class implementation
 * All methods of the ConsoleInterface class are implemented here
*/
#include <string>
#include "ConsoleInterface.h"

using namespace std;

void ConsoleInterface::run() {
    running = true; // Variable to exit program once
    cout << "Учёт абстрактных позиций" << endl;

    while (running) { // this actions will always occur if we don't choose something
        cout << endl;
        cout << "Выберите действие:" << endl
             << "1 - Добавить позицию" << endl
             << "2 - Удалить позицию" << endl
             << "3 - Вывести список позиций" << endl
             << "4 - Выполнить текстовый поиск позиции" << endl
             << "5 - Выход" << endl;

        int choice = 0;

        cin >> choice;

        switch (choice) { // action selection
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
    // cin is not used because data might contain more than one word
    cin.ignore();
    getline(cin, data);

    // create position and add it to the list
    Position position(data);
    list.addPosition(position);
}

void ConsoleInterface::removePosition() {
    int choice;

    // selection of removal element by key or by its data
    while (choice > 2 || choice < 1) {

        cout << "Каким образом вы хотите удалить позицию?" << endl
             << "1 - По номеру элемента" << endl
             << "2 - По данным в позиции" << endl;

        cin >> choice;
    }

    // element might be not found
    try {
        switch (choice) {
            case 1:
                // removal element by key number
                int index;

                cout << "Введите номер элемента, который вы желаете удалить: ";
                cin >> index;
                list.removePosition(index - 1);
                break;

            case 2:
                // removal element by data
                string data;

                cout << "Введите данные в позиции, которую вы желаете удалить: ";
                cin.ignore();
                getline(cin, data);
                list.removePosition(data);
        }
    } catch (out_of_range) {
        // catch an exception if element wasn't found
        cout << "Элемент не найден" << endl;
    }
}

void ConsoleInterface::getAllPositions() {
    if (list.getAllPositions().empty()) { // print message about empty list
        cout << "Список позиций пуст" << endl;
    }
    for (int index = 0; index < list.getAllPositions().size(); index++) { // print all positions with their numbers
        cout << index + 1 << ") " << list.getAllPositions()[index].getData() << endl;
    }
}

void ConsoleInterface::searchPositions() {
    string data;

    cout << "Введите данные по позициям, которые вы хотите найти: ";
    // we can search positions with more than one word
    cin.ignore();
    getline(cin, data);

    if (!list.searchPositions(data).empty()) { // if list of such positions is not empty, print data
        for (int index = 0; index < list.searchPositions(data).size(); index++) {
            cout << list.searchPositions(data)[index].getData() << endl;
        }
    } else { // else print message about empty list
        cout << "Позиции с такими данными не найдены" << endl;
    }
}