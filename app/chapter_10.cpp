#include <algorithm>
#include <cstdint>
#include <functional>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

#include "Sales_data.h"
#include "common_function.h"
#include "spdlog/fmt/bundled/format.h"
#include "spdlog/fmt/bundled/ranges.h"
#include "spdlog/spdlog.h"

void draft()
{
    SPDLOG_INFO("\n---------- draft ----------");
    //
    int32_t ia[] = {27, 210, 12, 47, 109, 83};
    SPDLOG_INFO("ia=[{}]", fmt::join(ia, ","));

    const int32_t val = 47;
    SPDLOG_INFO("val={}", val);

    int32_t *result = std::find(std::begin(ia), std::end(ia), val);
    SPDLOG_INFO("result->{}", *result);

    std::list<std::string> list = {"27", "210", "12", "47", "109", "83"};
    SPDLOG_INFO("i={}", fmt::format("{}", list));

    const std::string val_str = "47";
    SPDLOG_INFO("val_str={}", val_str);

    const auto result2 = std::find(list.cbegin(), list.cend(), val_str);
    SPDLOG_INFO("result2->{}", *result2);
}

void func_10_1()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    const std::vector<int32_t> a = {1, 1, 2, 2, 2, 3};
    SPDLOG_INFO("a: {}", fmt::format("{}", a));
    const std::int32_t val = 2;
    const auto result = std::count(a.cbegin(), a.cend(), val);
    SPDLOG_INFO("the count of {} in the vector a is: {}", val, result);
}

void func_10_2()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    const std::vector<std::string> a = {"1", "1", "2", "2", "2", "3"};
    SPDLOG_INFO("a: {}", fmt::format("{}", a));
    const std::string val = "2";
    const auto result = std::count(a.cbegin(), a.cend(), val);
    SPDLOG_INFO("the count of {} in the vector a is: {}", val, result);
}

void func_10_3()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    const std::vector<int32_t> a = {1, 1, 2, 2, 2, 3};
    SPDLOG_INFO("a: {}", fmt::format("{}", a));
    const auto result = std::accumulate(a.cbegin(), a.cend(), 0);
    SPDLOG_INFO("the sum of a is: {}", result);
}

void func_10_6()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    std::vector<int32_t> a = {1, 1, 2, 2, 2, 3};
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    //
    std::fill_n(a.begin(), a.size(), 0);
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
}

void func_10_7()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    std::list<int32_t> a = {1, 1, 2, 2, 2, 3};
    std::vector<int32_t> b;
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    SPDLOG_INFO("before b: {}", fmt::format("{}", b));
    //
    std::copy(a.cbegin(), a.cend(), std::back_inserter(b));
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
    SPDLOG_INFO("after b: {}", fmt::format("{}", b));
    //
    std::vector<int32_t> c;
    //   c.reserve(10);
    c.resize(10);
    std::fill_n(c.begin(), 10, 0);
    SPDLOG_INFO("c: {}", fmt::format("{}", c));
}

void func_10_9()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    std::vector<int32_t> a = {3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1};
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    elimDups(a);
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
}

void func_10_11()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> a = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    elimDups(a);
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
    std::stable_sort(a.begin(), a.end(), isShorter);
    SPDLOG_INFO("after after a: {}", fmt::format("{}", a));
}

void func_10_12()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<Sales_data> a;
    for (const auto &isbn : std::vector<std::string>{
             "978-3-16-148410-0",
             "979-0-123-45678-5",
             "978-1-2345-6789-2",
             "979-8-7654-3210-6",
             "978-0-987-65432-1",
             "979-5-4321-0987-4",
             "978-4-5678-9012-3",
             "979-2-3456-7890-7",
             "978-6-7890-1234-8",
             "979-1-1111-2222-9",
         })
    {
        a.emplace_back(isbn);
    }
    // convert
    std::vector<std::string> before;
    std::transform(a.cbegin(), a.cend(), std::back_inserter(before), convertToIsbn);
    SPDLOG_INFO("before a: {}", fmt::format("{}", before));
    std::sort(a.begin(), a.end(), compareIsbn);
    std::vector<std::string> after;
    std::transform(a.cbegin(), a.cend(), std::back_inserter(after), convertToIsbn);
    SPDLOG_INFO("after a: {}", fmt::format("{}", after));
}

void func_10_13()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> a = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    std::partition(a.begin(), a.end(), [](const std::string &s) -> bool { return s.size() < 5; });
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
}

void func_10_14()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    auto lam = [](const int32_t a, const int32_t b) { return a + b; };
    int32_t a = 2;
    int32_t b = 3;
    int32_t c = lam(a, b);
    SPDLOG_INFO("a : {}, b: {}, c: {}", a, b, c);
}

void func_10_15()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    int32_t a = 2;
    auto lam = [a](const int32_t b) { return a + b; };
    int32_t b = 3;
    int32_t c = lam(b);
    SPDLOG_INFO("a : {}, b: {}, c: {}", a, b, c);
}

void func_10_16()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    const std::size_t sz = 4;

    auto my_biggies = [](std::vector<std::string> &words, const std::size_t sz) {
        elimDups(words);
        std::stable_sort(words.begin(), words.end(), [](const std::string &lhs, const std::string &rhs) -> bool {
            return lhs.size() < rhs.size();
        });
        auto wc =
            std::find_if(words.cbegin(), words.cend(), [sz](const std::string &s) -> bool { return s.size() >= sz; });
        auto count = words.cend() - wc;
        SPDLOG_INFO("count {} of length {} or longer", make_plural(count, "word", "s"), sz);
        std::for_each(wc, words.cend(), [](const std::string &s) { std::cout << s << " "; });
        std::cout << std::endl;
    };
    SPDLOG_INFO("my_biggies...");
    my_biggies(words, sz);
    SPDLOG_INFO("biggies...");
    biggies(words, sz);
}

void func_10_17()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<Sales_data> a;
    for (const auto &isbn : std::vector<std::string>{
             "978-3-16-148410-0",
             "979-0-123-45678-5",
             "978-1-2345-6789-2",
             "979-8-7654-3210-6",
             "978-0-987-65432-1",
             "979-5-4321-0987-4",
             "978-4-5678-9012-3",
             "979-2-3456-7890-7",
             "978-6-7890-1234-8",
             "979-1-1111-2222-9",
         })
    {
        a.emplace_back(isbn);
    }

    // convert
    std::vector<std::string> before;
    std::transform(a.cbegin(), a.cend(), std::back_inserter(before), convertToIsbn);
    SPDLOG_INFO("before a: {}", fmt::format("{}", before));
    std::sort(a.begin(), a.end(),
              [](const Sales_data &lhs, const Sales_data &rhs) -> bool { return lhs.isbn() < rhs.isbn(); });
    std::vector<std::string> after;
    std::transform(a.cbegin(), a.cend(), std::back_inserter(after), convertToIsbn);
    SPDLOG_INFO("after a: {}", fmt::format("{}", after));
}

void func_10_18()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    const std::size_t sz = 4;
    SPDLOG_INFO("biggies...");
    biggies(words, sz);
    SPDLOG_INFO("biggies_partition...");
    biggies_partition(words, sz);
}

void func_10_19()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    const std::size_t sz = 4;
    SPDLOG_INFO("biggies...");
    biggies(words, sz);
    SPDLOG_INFO("biggies_partition...");
    biggies_partition(words, sz);
    SPDLOG_INFO("biggies_stable_partition...");
    biggies_stable_partition(words, sz);
}

void func_10_20()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    const std::size_t sz = 4;
    SPDLOG_INFO("words: {}", fmt::format("{}", words));
    SPDLOG_INFO("count_if...");
    const auto cnt =
        std::count_if(words.cbegin(), words.cend(), [sz](const std::string &s) -> bool { return s.size() > sz; });
    SPDLOG_INFO("The number of words with more than {} characters is: {}", sz, cnt);
}

void func_10_21()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    int32_t a = 3;
    auto lam = [&a]() -> bool {
        bool is_zero = (a == 0);
        while (a > 0)
        {
            --a;
        }
        return is_zero;
    };
    SPDLOG_INFO("a={}", a);
    SPDLOG_INFO("a is_zero: {}", lam());
    SPDLOG_INFO("a={}", a);
    SPDLOG_INFO("a is_zero: {}", lam());
    SPDLOG_INFO("a={}", a);
}

void func_10_22()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    const std::size_t sz = 4;
    SPDLOG_INFO("words: {}", fmt::format("{}", words));
    const auto cmp_func = std::bind(check_size, std::placeholders::_1, sz);
    SPDLOG_INFO("count_if...");
    const auto cnt = std::count_if(words.cbegin(), words.cend(), cmp_func);
    SPDLOG_INFO("The number of words with more than {} characters is: {}", sz, cnt);
}

int main(int argc, char *args[])
{
    //
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug

    draft();
    func_10_1();
    func_10_2();
    func_10_3();
    func_10_6();
    func_10_7();
    func_10_9();
    func_10_11();
    func_10_12();
    func_10_13();
    func_10_14();
    func_10_15();
    func_10_16();
    func_10_17();
    func_10_18();
    func_10_19();
    func_10_20();
    func_10_21();
    func_10_22();

    return 0;
}