#include<iostream>

using namespace std;

consteval int get_value(){
    return 3;
}
    
int main(){
    constexpr int value =get_value();
    cout<<"Hola mundo"<<endl;
    cout<< value <<endl;
    return 0;
}