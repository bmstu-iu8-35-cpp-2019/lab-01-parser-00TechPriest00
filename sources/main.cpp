// Copyright 2019 Fedorov james.sayfer2015@yandex.ru
#include "../include/nlohmann/json.hpp"
#include <iostream>
#include <string>

using json = nlohmann::json;

int main(){
    std::string str1 = "[[\"Si-9.15\", \"RTS-9.15\", \"GAZP-9.15\"], ";
    std::string str2 = "[100024, 100027, 100050],";
    std::string str3 =
"[\"Futures contract for USD / RUB\", \"Futures contract";
    std::string str4 = " for index RTS\", \"Futures contract";
    std::string str5 = " for Gazprom shares\"]]";
    std::string jjson = str1 + str2 + str3 + str4 + str5;
    json j = json::parse(jjson);
    size_t n = (j[0]).size();
    json j_new;
    for (size_t i = 0; i < n; i++){
        j_new[i]["ticker"] = j[0][i];
        j_new[i]["id"] = j[1][i];
        j_new[i]["description"] = j[2][i];}

    if (j_new[0]["id"]  != 100024){
        return 1;}
    if (j_new[1]["ticker"] != "RTS-9.15"){
        return 2;}
    if (j_new[2]["description"] != "Futures contract for Gazprom shares"){
        return 3;}
    return 0;}
    for (size_t i = 0; i < n; i++)
    {
        j_new[i]["ticker"] = j[0][i];
        j_new[i]["id"] = j[1][i];
        j_new[i]["description"] = j[2][i];
    }

    if (j_new[0]["id"] != 100024)
    {
        return 1;
    }
    if (j_new[1]["ticker"] != "RTS-9.15")
    {
        return 2;
    }
    if (j_new[2]["description"] != "Futures contract for Gazprom shares")
    {
        return 3;
    }
    return 0;
}
