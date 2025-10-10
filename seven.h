#pragma once
#include <string>

class Seven {
    public:
    Seven();
    Seven(const int number);
    Seven(const Seven& other);
    Seven(const std::initializer_list<unsigned char> &)
    ~Seven();

}