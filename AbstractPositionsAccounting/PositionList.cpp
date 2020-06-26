/*!
 * @file
 * @brief PositionList class implementation
 * All methods of the PositionList class are implemented here
*/
#include <fstream>
#include "PositionList.h"

using namespace std;

PositionList::PositionList() {
    load();
}

void PositionList::addPosition(Position position) {
    positions.push_back(position); // add element using vector's push_back()
    save(); // save data into file after every action
}

void PositionList::removePosition(int key) {
    if (key < 0 || key >= positions.size()) {
        throw out_of_range("Key is out of range"); // throw an exception if there is not such key number in list
    }

    positions.erase(positions.begin() + key); // else delete element using vector's erase()
    save();
}

void PositionList::removePosition(Position position) {
    for (int index = 0; index < positions.size(); index++) { // find element's index
        if (positions[index] == position) {
            removePosition(index); // and call method to remove it by index
            break;
        }

        if (index == positions.size() - 1) {
            throw out_of_range("Element is not found"); // else throw an exception
        }
    }
    save();
}

vector<Position> PositionList::searchPositions(string data) {
    vector<Position> foundPositions; // create a separate list for all found positions

    for (int index = 0; index < positions.size(); index++) { // check all elements
        if (positions[index].getData().find(data) != string::npos) {
            // if element's data has string from the parameter, add it to list created earlier
            foundPositions.push_back(positions[index]);
        }
    }

    return foundPositions;
}

vector<Position> &PositionList::getAllPositions() {
    return positions;
}

void PositionList::save() {
    // create ofstream variable and put all data here
    ofstream file("list.txt");
    for (int index = 0; index < positions.size(); index++) {
        file << positions[index].getData() << "\n";
    }
}

void PositionList::load() {
    string str;
    // create ifstream variable and load all data from file
    ifstream file("list.txt");
    while (getline(file, str)) {
        addPosition(str);
    }
}