#ifndef YAOHUI_TOOLKITS_H
#define YAOHUI_TOOLKITS_H

#include <iostream>
#include <vector>

namespace yaohui
{

namespace toolkits
{

template <typename T> void print(const T &item)
{
    std::cout << item << std::endl;
}

template <typename T> void print(const std::vector<T> &vec)
{
    for (std::size_t i = 0; i != vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size())
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

} // namespace toolkits

} // namespace yaohui

#endif // YAOHUI_TOOLKITS_H