// Copyright 2019 Fedorov james.sayfer2015@yandex.ru

#include "json.hpp"

int main() {
    int position = 0;
    try {
        JSON BB("[1,2,3]", position, false);
        try {
            std::cout << std::any_cast<double>(BB[1]) << std::endl;
        } catch (std::bad_any_cast &l) {
            return 9;
        }
        position = 0;
        JSON a("{\"lastname\" : \"Ivanov\",\"firstname\" : \"Ivan\",\"age\" : 25,\"islegal\" : false,\"marks\" : [    4, 5, 5, 5, 2, 3] ,\"address\" : {\"city\" : \"Moscow\",\"street\" : \"Vozdvijenka\"}}",
               position, false);
        try {
            std::cout << std::any_cast<double>(std::any_cast<JSON>(a["marks"])[3]) << std::endl;
        } catch (std::bad_any_cast &l) {
            return 8;
        }
        position = 0;
        JSON b("test.txt", position, true);
        try {
            std::cout << std::any_cast<double>(b["age"]) << std::endl;
        } catch (std::bad_any_cast &l) {
            return 8;
        }
    } catch (std::logic_error &n) {
        std::cout << n.what() << std::endl;
        return 2;
    }
    return 0;
}
