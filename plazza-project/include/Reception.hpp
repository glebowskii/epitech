#ifndef PLAZZA_PROJECT_RECEPTION_HPP
#define PLAZZA_PROJECT_RECEPTION_HPP

#include <vector>
#include <string>
#include <sys/types.h> // for pid_t
#include "Pizza.hpp"

class Reception {
private:
    std::vector<pid_t> kitchenPIDs; // Store PIDs of kitchen processes
    std::vector<int> kitchenPipes; // Store pipe file descriptors for communication
    int numCooks;
    int replenishTime;
    float cookTimeMultiplier;

public:
    Reception(int cooks, int replenish, float multiplier);
    void createNewKitchen();
    void handleOrder(const std::string& order);
    std::vector<Pizza> parseOrder(const std::string& order);
    PizzaType getPizzaType(const std::string& type);
    PizzaSize getPizzaSize(const std::string& size);
    void printStatus();
    void handleCommands(int readFd); // handle commands from the pipe
};

#endif //PLAZZA_PROJECT_RECEPTION_HPP
