#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <string>
#include <iostream>
#include <stdint.h> //lib de 98

struct Data {
    int id;
    std::string name;
    float value;
};

class Serializer {
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
    
    private:
        Serializer();
        Serializer(const Serializer &);
        Serializer &operator=(const Serializer &);
        ~Serializer();
};

#endif