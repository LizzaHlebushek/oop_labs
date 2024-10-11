#pragma once

#include <string>
#include <iostream>

class Five
{ 
public:
    Five(); // конструктор по умолчанию
    Five(char t); // конструктор для числа t 
    Five(const int t);
    Five(const std::initializer_list< unsigned char> &t);//
    Five(const std::string &t);//
    Five(const Five& other);//
    Five(Five&& other) noexcept;    //  

    int size() const;
    std::string toStr() const;  

    bool equals(const Five& other) const;
    bool more(const Five &other) const;
    bool less(const Five &other) const;
    Five sum(const Five& other) const;
    void add(const Five& other);
    Five subtract(const Five& other) const;
    void remove(const Five& other);
    std::ostream& print(std::ostream& os);

    virtual ~Five() noexcept;

private:
    Five(const size_t size);

private:
    size_t _size;
    unsigned char *_array;
};
