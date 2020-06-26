/*!
 * @file
 * @brief This is header file of PositionList class
 * description of PositionList class and its methods
*/
#pragma once

#include <vector>
#include <string>
#include "Position.h"

/*!
 * @brief PositionList class
 * This class is needed to do some actions with the list of abstract positions
 */
class PositionList {
private:
    std::vector<Position> positions;

public:
    /*!
     * @brief Default constructor
     * In which data loads from file
     */
    PositionList();

    /*!
     * @brief This method add abstract position to the back of the list
     * @param position position that you want to add
     */
    void addPosition(Position position);

    /*!
     * @brief Method is needed to remove abstract position from list by its key number
     * @param key position which has such key will be deleted
     */
    void removePosition(int key);

    /*!
     * @brief Method is needed to remove abstract position from list by its data
     * @param position position which will be deleted
     */
    void removePosition(Position position);

    /*!
     * @brief This method saves current position list in file list.txt
     */
    void save();

    /*!
     * @brief This method loads list from file list.txt
     */
    void load();

    /*!
     * @brief Method is needed to search all abstract positions which data contains string from the parameter
     * @param data string by which method searches positions
     * @return All positions which data contains data from the parameter
     */
    std::vector<Position> searchPositions(std::string data);

    /*!
     * @brief This method is needed to get all positions in list
     * @return Vector of all positions
     */
    std::vector<Position> &getAllPositions();
};