#include <iostream>

template <class T1, class T2>
class CoolPair
{
private:
    int secretKey = 0;
    T1 first;
    T2 second;

public:
    int openKey = 1;
    CoolPair()
    {
        std::cout << "CoolPair base constructr\n";
    };
    CoolPair(T1 first, T2 second)
    {
        this->first = first;
        this->second = second;
        std::cout << "CoolPair parametrized construcor\n";
        std::cout << "first: " << first << "; second: " << second << ";\n";
    };

    ~CoolPair()
    {
        std::cout << "CoolPair Deleted\n";
    }

    T1 getFirst()
    {
        std::cout << "getFirst:" << first << "\n";
        return first;
    }
    void setFirst(T1 value)
    {
        first = value;
    }
    

    
};