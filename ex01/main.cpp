#include "Serializer.hpp"

int main (){
    
    Data data;
    data.id = 42;
    data.name = "O tempo pergunta ao tempo o que?";
    data.value = 6843.35f;

    std::cout << "\nOriginal: " << &data << "\n";
    std::cout << "Data.id: " << data.id << "\nData.name: " << data.name
        << "\nValue: " << data.value << "\n";

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "\nRaw: " << raw << "\n";

    Data *dsData = Serializer::deserialize(raw);

    std::cout << "\nOriginal: " << dsData << "\n";
    std::cout << "Data.id: " << dsData->id << "\nData.name: " << dsData->name
        << "\nValue: " << dsData->value << "\n";

    return 0;
}











/*The Serializer exercise is about understanding how to manipulate pointers and memory addresses in C++,
how to serialize and deserialize data safely, and how to ensure type safety and data integrity during these processes.
It provides a solid introduction to concepts that are crucial in areas like networking, file I/O, and systems programming,
where data often needs to be stored, transmitted, or processed in raw binary form.
*/