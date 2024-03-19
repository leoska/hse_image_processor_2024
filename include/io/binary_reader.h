#pragma once

#include <fstream>
#include <string>

class BinaryReader
{
public:
    BinaryReader(const std::string &filename);
    ~BinaryReader();

    template <typename T>
    BinaryReader &operator>>(T &value)
    {
        using U = std::make_unsigned_t<T>;
        U bits = 0;

        unsigned char buffer[sizeof(T)];
        file_.read(reinterpret_cast<char*>(buffer), sizeof(T));

        std::reverse(std::begin(buffer), std::end(buffer));

        for (auto byte : buffer)
        {
            bits = (bits << U{8}) | byte;
        }

        value = static_cast<T>(bits);
        return *this;
    };

private:
    std::ifstream file_;
};