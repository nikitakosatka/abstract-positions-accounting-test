/*!
 * @file
 * @brief This is header file of ConsoleInterface class
 * description of ConsoleInterface class and its methods
*/
#pragma once

#include <iostream>
#include "Position.h"
#include "PositionList.h"

/*!
 * @brief Console Interface class
 * This is needed for interacting with abstract positions
 */
class ConsoleInterface {
private:
    PositionList list;
    bool running;

public:
    /*!
     *  @brief Default constructor
     */
    ConsoleInterface() = default;

    /*!
     * @brief Run method is needed for running program and choice of action
     */
    void run();

    /*!
     * @brief addPosition method is called if you selected such action
     */
    void addPosition();

    /*!
     * @brief removePosition method is called if you selected such action
     */
    void removePosition();

    /*!
     * @brief getAllPositions method is called if you selected such action
     */
    void getAllPositions();

    /*!
     * @brief searchPositions method is called if you selected such action
     */
    void searchPositions();
};