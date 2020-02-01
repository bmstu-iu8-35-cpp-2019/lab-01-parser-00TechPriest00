// Copyright 2018 Fedorov james.sayfer2015@yandex.ru

#include <gtest/gtest.h>

#include <json.hpp>

<<<<<<< HEAD
TEST(Json, Operato_EQ){
=======
TEST(Json, Operato_EQ)
{
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
    std::string str1 =
"{  \"lastname\" : \"Ivanov\",\"firstname\" : \"Ivan\", ";
    std::string str2 = "\"age\" : 25, \"islegal\" : false,";
    std::string str3 = "\"address\" : { \"city\" : \"Moscow\", \"street\" :";
    std::string str4 = "\"Vozdvijenka\"}, \"ad\":";
    std::string str5 = "[1,2,5]}";
    std::string jjson = str1 + str2 + str3 + str4 + str5;

    Json object = Json(jjson);
    EXPECT_EQ(object.is_object(), true);
    EXPECT_EQ(static_cast<std::string>("Ivanov"),
std::any_cast<std::string>(object["lastname"]));

    EXPECT_EQ(std::any_cast<bool>(object["islegal"]), false);
    EXPECT_EQ(std::any_cast<float>(object["age"]), 25);

    auto address = Json(object["address"]);
    EXPECT_EQ(std::any_cast<std::string>(address["city"]), "Moscow");
    EXPECT_EQ(std::any_cast<std::string>(address["street"]), "Vozdvijenka");

    auto a = object["ad"];
    EXPECT_EQ(static_cast<float>(1),
std::any_cast<float>((std::any_cast<std::vector<std::any>>(a))[0]));
<<<<<<< HEAD
    EXPECT_EQ(static_cast<float>(5),
std::any_cast<float>((std::any_cast<std::vector<std::any>>(a))[2]));}
=======
    EXPECT_EQ(static_cast<float>(5),
std::any_cast<float>((std::any_cast<std::vector<std::any>>(a))[2]));
}
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
