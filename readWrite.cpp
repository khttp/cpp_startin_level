#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main()
{
    std::string hell;
    std::string line;
    std::ofstream file("./in.txt",std::ios::app) ;

    if (file.is_open()){
        file<<"here is something that i wanted to say";
        file.close();
    }else{
        std::cout<<"something went wrong";
    }
    getline(std::cin,hell) ;
    std::cout << hell << std::endl;
    std::ifstream filei("./helloWorld.cpp",std::ios::in);
    while (getline(filei,line)){
        std::cout << line << std::endl;
    }
    filei.close();
    return 0;
}
