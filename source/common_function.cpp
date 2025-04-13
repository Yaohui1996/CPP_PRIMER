#include "common_function.h"
#include "spdlog/fmt/bundled/format.h"
#include "spdlog/spdlog.h"
#include <algorithm>

bool isShorter(const std::string &lhs, const std::string &rhs)
{

    return lhs.size() < rhs.size();
}

void elimDups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(), vec.end());
    const auto unique_end = std::unique(vec.begin(), vec.end());
    vec.erase(unique_end, vec.end());
}

void elimDups(std::vector<std::int32_t> &vec)
{
    std::sort(vec.begin(), vec.end());
    const auto unique_end = std::unique(vec.begin(), vec.end());
    vec.erase(unique_end, vec.end());
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

std::string convertToIsbn(const Sales_data &sd)
{
    return sd.isbn();
}

void biggies(std::vector<std::string> &words, const std::size_t sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
                     [](const std::string &lhs, const std::string &rhs) -> bool { return lhs.size() < rhs.size(); });
    auto wc = std::find_if(words.cbegin(), words.cend(), [sz](const std::string &s) -> bool { return s.size() >= sz; });
    auto count = words.cend() - wc;
    SPDLOG_INFO("count {} of length {} or longer", make_plural(count, "word", "s"), sz);
    std::for_each(wc, words.cend(), [](const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}

std::string make_plural(const std::size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}