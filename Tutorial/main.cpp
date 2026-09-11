#include<iostream>
#include <string>

consteval int get_value(){
    return 3;
}
    
int main(){
    constexpr int value =get_value();
    int age{0};
    std::string name{};

    std::cout << "Hola mundo"<< std::endl;
    std::cout << value << std::endl;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << std::endl;


    return 0;
}