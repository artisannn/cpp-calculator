#include<iostream>
#include<cmath>
#include"calculator.h"

bool ReadNumber(Number& result){
    if(!(std::cin >> result)){
        std::cerr << "Error: Numeric operand expected" << std::endl;
    }
    return std::cin.good();
}

bool RunCalculatorCycle(){
    Number result = 0;
    if (ReadNumber(result)) {
        std::string token;
        bool stop = false;
        Number memory = 0;
        bool memory_initialized = false;
        while (!stop){
            std::cin >> token;
            if (Number input; token == "q") {
                return true;
            } else if (token == "+"){
                if(ReadNumber(input)){  
                    result += input;                 
                } else {
                    stop = true;
                }
            } else if (token == "-"){
                if(ReadNumber(input)){  
                    result -= input;                 
                } else {
                    stop = true;
                }
            } else if (token == "*"){
                if(ReadNumber(input)){  
                    result *= input;                 
                } else {
                    stop = true;
                }
            } else if (token == "/"){
                if(ReadNumber(input)){  
                    result /= input;                 
                } else {
                    stop = true;
                }
            } else if (token == "**"){
                if(ReadNumber(input)){                   
                    result = pow(result,input);                 
                } else {
                    stop = true;
                }
            } else if(token == ":"){
                if(ReadNumber(input)){                   
                    result = input;                 
                } else {
                    stop = true;
                }
            } else if(token == "s"){
                memory = result;
                memory_initialized = true;
            } else if(token == "l"){
                if(memory_initialized){                   
                    result = memory;                 
                } else {
                    std::cerr << "Error: Memory is empty" << std::endl;
                    stop = true;
                }
            } else if(token == "c"){
                result = 0;
            } else if(token == "="){
                std::cout << result << std::endl;
            } else {
                std::cerr << "Error: Unknown token " << token << std::endl;;
                stop = true;
            }           
        }
        return false;
    } else {
        return false;
    }
}
