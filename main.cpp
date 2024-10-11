#include <iostream>
#include "five.h"

int main() {
    try {
        Five t1; //standart constructor
        Five t2 ('4'); // char constructor
        Five t3 (0); // int constructor
        Five t4 {"000001000304102"}; //string constructor
        Five t5 = t3; //copy constructor
        Five t6 = std::move(t5); //moveconstructor

        std::cout << "t1: ";
        t1.print(std::cout) << "  ";
        std::cout << "size:"<<t1.size()<< std::endl;

        std::cout << "t2: ";
        t2.print(std::cout) << "  ";
        std::cout << "size:"<<t2.size()<< std::endl;

        std::cout << "t3: ";
        t3.print(std::cout) << "  ";
        std::cout << "size:"<<t3.size()<< std::endl;

        std::cout << "t4: ";
        t4.print(std::cout) << "  ";
        std::cout << "size:"<<t4.size()<< std::endl;

        std::cout << "t5: ";
        t5.print(std::cout) << "  ";
        std::cout << "size:"<<t5.size()<< std::endl;

        std::cout << "t6: ";
        t6.print(std::cout) << "  ";
        std::cout << "size:"<<t6.size()<< std::endl;

        std::string s = t3.toStr();
        
        std::cout <<"the string is: " << s << std::endl;

        std::cout << "1 + 2:" << std::endl;
         Five t12 = t1.sum(t2);
        std::cout << "t12: ";
        t12.print(std::cout) << "  ";
        std::cout << "size:"<<t12.size()<< std::endl;


        std::cout << "4 - 3:"<< std::endl;
        Five t43 = t4.subtract(t3);
        std::cout << "t43: ";
        t43.print(std::cout) << "  ";
        std::cout << "size:"<<t43.size()<< std::endl;

    } catch(std::exception &ex){
        std::cerr << "exception: " << ex.what() << std::endl;
    }
    return 0;
}
