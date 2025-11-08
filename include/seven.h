#pragma once

#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>

class Seven {
public:
    Seven();
    Seven(const std::string& number);
    Seven(const std::initializer_list<unsigned char>& digits);
    Seven(const Seven& other);        
    Seven(Seven&& other) noexcept;    
    
    Seven& operator=(const Seven& other);        
    Seven& operator=(Seven&& other) noexcept;    

    Seven add(const Seven& other) const;
    Seven subtract(const Seven& other) const;
    bool equals(const Seven& other) const;
    bool greater(const Seven& other) const;
    bool less(const Seven& other) const;

    std::ostream& print(std::ostream& os) const;
    
    virtual ~Seven() noexcept;

private:
    size_t size;
    unsigned char* digits{nullptr};

    void normalize(); 
};