#include "Serializer.hpp"

int main (){
    Data data;
    data.id = 42;
    data.name = "O tempo pergunta ao tempo o que?";
    data.value = 6843.35f;

    std::cout << "Original: " << &data << "\n";
    std::cout << "Data.id: " << data.id << "\nData.name: " << data.name
        << "\nValue: " << data.value << "\n";

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "Raw: " << raw << "\n";

    Data *dsData = Serializer::deserialize(raw);

    std::cout << "Original: " << dsData << "\n";
    std::cout << "Data.id: " << dsData->id << "\nData.name: " << dsData->name
        << "\nValue: " << dsData->value << "\n";

    return 0;
}