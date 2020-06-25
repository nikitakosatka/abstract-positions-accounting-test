/*!
 * @file
 * @brief This is header file of Position class
 * description of Position class and its methods
*/
#pragma once

#include <string>

/*!
 * @brief Abstract position
 * This class is needed to do some actions with list of such positions
 */
class Position {
private:
    std::string data;

public:
    /*!
     * @brief Default constructor
     */
    Position() = default;

    /*!
     * @brief Constructor in which we can set data
     * @param data Data that the class object contains
     */
    Position(std::string data);

    /*!
     * @brief Overloaded operator == to compare abstract position class objects
     * @param other Other object that we compare
     * @return Return true if data in this object is the same as in the other
     */
    bool operator==(const Position &other);

    /*!
     * @brief This method is needed to get abstract position object data
     * @return String data
     */
    std::string getData() const;
};