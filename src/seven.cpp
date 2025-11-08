#include "../include/seven.h"

Seven::Seven(){
    digits = new unsigned char[1];
    digits[0] = 0;
    size = 1;
}

Seven::Seven(const std::string& number) {
    for (char c : number)
        if (c < '0' || c > '6')
            throw std::invalid_argument("Digits are only from 0 to 6");

    size = number.size();
    digits = new unsigned char[size];

    for (size_t i = 0; i < size; ++i)
        digits[i] = number[size - i - 1] - '0';
    
    normalize();
}

Seven::Seven(const std::initializer_list<unsigned char>& list) {
    size = list.size();
    digits = new unsigned char[size];
    size_t i = 0;
    
    for (auto value : list) {
        if (value > 6) 
            throw std::invalid_argument("Digits are only from 0 to 6");
        
        digits[i++] = value;
    }

    normalize();
}

Seven::Seven(const Seven& other) : size(other.size) {
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) 
        digits[i] = other.digits[i];
}

Seven::Seven(Seven&& other) noexcept : size(other.size), digits(other.digits) {
    other.size = 0;
    other.digits = nullptr;
}

Seven& Seven::operator=(const Seven& other) {
    if (this != &other) {
        delete[] digits;
        
        size = other.size;
        digits = new unsigned char[size];
        
        for (size_t i = 0; i < size; ++i)
            digits[i] = other.digits[i];
    }

    return *this;
}

Seven& Seven::operator=(Seven&& other) noexcept {
    if (this != &other) {
        delete[] digits;
        
        size = other.size;
        digits = other.digits;
        
        other.size = 0;
        other.digits = nullptr;
    }

    return *this;
}

Seven Seven::add(const Seven& other) const {
    size_t maxSize = std::max(size, other.size);
    unsigned char carry = 0;

    Seven res;
    res.size = maxSize + 1;
    res.digits = new unsigned char[res.size]{0};

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char a = (i < size) ? digits[i] : 0;
        unsigned char b = (i < other.size) ? other.digits[i] : 0;
        unsigned char sum = a + b + carry;

        res.digits[i] = sum % 7;
        carry = sum / 7;
    }

    res.digits[maxSize] = carry;

    res.normalize();
    return res;
}

Seven Seven::subtract(const Seven& other) const {
    if (less(other))
        throw std::invalid_argument("Res is less than 0");

    Seven res;
    res.size = size;
    res.digits = new unsigned char[res.size];

    int borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        int a = digits[i] - borrow;
        int b = (i < other.size) ? other.digits[i] : 0;

        if (a < b) {
            a += 7;
            borrow = 1;
        } else
            borrow = 0;

        res.digits[i] = static_cast<unsigned char>(a - b);
    }

    res.normalize();
    return res;
}

bool Seven::equals(const Seven& other) const {
    if (size != other.size) 
        return false;

    for (size_t i = 0; i < size; ++i)
        if (digits[i] != other.digits[i]) 
            return false;

    return true;
}

bool Seven::greater(const Seven& other) const {
    if (size != other.size) 
        return size > other.size;
    
    for (size_t i = size; i-- > 0; )
        if (digits[i] != other.digits[i])
            return digits[i] > other.digits[i];
    
    return false;
}

bool Seven::less(const Seven& other) const {
    if (size != other.size) 
        return size < other.size;
    
    for (size_t i = size; i-- > 0; )
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    
    return false;
}

void Seven::normalize() {
    if (size == 0) {
        delete[] digits;
        size = 1;
        digits = new unsigned char[1];
        digits[0] = 0;

        return;
    }

    size_t newSize = size;
    while (newSize > 1 && digits[newSize - 1] == 0) 
        --newSize;

    if (newSize != size) {
        unsigned char* newDigits = new unsigned char[newSize];
        
        for (size_t i = 0; i < newSize; ++i) 
            newDigits[i] = digits[i];
        
        delete[] digits;
        digits = newDigits;
        size = newSize;
    }
}

std::ostream& Seven::print(std::ostream& os) const {
    for (size_t i = size; i-- > 0;)
        os << static_cast<int>(digits[i]);
    
    return os;
}

Seven::~Seven() noexcept {
    delete[] digits;
    digits = nullptr;
    size = 0;
}
