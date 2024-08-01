#include "receivehandler.h"

#include <iostream>


void ReceiveHandler::handle(std::string data)
{
    if (data.length() >= 2 && std::stoi(data) % 32 == 0) {
        std::cout << "Полученная сумма: " << data << std::endl;
    } else {
        std::cout << "Ошибка: сумма не удовлетворяет условию делимости на 32" << std::endl;
    }
}
