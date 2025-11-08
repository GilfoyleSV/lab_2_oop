#include <iostream>
#include "include/seven.h"

int main() {
    Seven num1("123");
    Seven num2("456");
    Seven num3({1, 0, 4});
    
    std::cout << "num1 = ";
    num1.print(std::cout) << std::endl;
    
    std::cout << "num2 = ";
    num2.print(std::cout) << std::endl;
    
    std::cout << "num3 = ";
    num3.print(std::cout) << std::endl;
    
    Seven copy1 = num1;
    Seven copy2;
    copy2 = num2;
    
    std::cout << "copy1 = ";
    copy1.print(std::cout) << std::endl;
    std::cout << "copy2 = ";
    copy2.print(std::cout) << std::endl;
    
    Seven sum1 = num1.add(num2);
    std::cout << "num1 + num2 = ";
    num1.print(std::cout) << " + ";
    num2.print(std::cout) << " = ";
    sum1.print(std::cout) << std::endl;
    
    Seven sum2 = num2.add(num3);
    std::cout << "num2 + num3 = ";
    num2.print(std::cout) << " + ";
    num3.print(std::cout) << " = ";
    sum2.print(std::cout) << std::endl;
    
    Seven big("1000");
    Seven small("1");
    
    std::cout << "big = ";
    big.print(std::cout) << std::endl;
    std::cout << "small = ";
    small.print(std::cout) << std::endl;
    
    Seven diff1 = big.subtract(small);
    std::cout << "big - small = ";
    big.print(std::cout) << " - ";
    small.print(std::cout) << " = ";
    diff1.print(std::cout) << std::endl;
    
    std::cout << "num1 = ";
    num1.print(std::cout) << std::endl;
    std::cout << "num2 = ";
    num2.print(std::cout) << std::endl;
    std::cout << "num3 = ";
    num3.print(std::cout) << std::endl;
    
    std::cout << "num1 равно num2? " << (num1.equals(num2) ? "да" : "нет") << std::endl;
    std::cout << "num1 равно num1? " << (num1.equals(num1) ? "да" : "нет") << std::endl;
    std::cout << "num1 больше num2? " << (num1.greater(num2) ? "да" : "нет") << std::endl;
    std::cout << "num1 меньше num2? " << (num1.less(num2) ? "да" : "нет") << std::endl;
    std::cout << "num2 больше num3? " << (num2.greater(num3) ? "да" : "нет") << std::endl;
    
    Seven withZeros({0, 0, 5, 1});
    std::cout << "Число с ведущими нулями: ";
    withZeros.print(std::cout) << std::endl;
    
    return 0;
}