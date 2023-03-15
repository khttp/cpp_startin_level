#include <fstream>
#include <iostream>
#include <json/json.h>
#include <json/value.h>
// while compiling use this command "clear ; g++ json.cpp -o json -ljsoncp`"
int main(int argc, char *argv[])
{
    std::fstream file("./file.json");

    Json::Value json;
    Json::Reader reader;
    reader.parse(file ,json);
    std::cout << json["name"] << std::endl;
    return 0;
}
