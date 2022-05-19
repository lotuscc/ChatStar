#include <iostream>

#include <mysqlx/xdevapi.h>
#include <string>

#include "login.h"

int main() {

    std::cout << "server" << std::endl;

    if (ell_login::login("lotuscc", "123")) {
        std::cout << "login success!" << std::endl;
    } else {
        std::cout << "login faild!" << std::endl;
    }
    return 0;
}