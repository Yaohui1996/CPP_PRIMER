#include <algorithm>
#include <cstdint>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

#include "Sales_data.h"
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
    auto elim_dups = [](std::vector<int32_t> &vec) -> void {
        std::sort(vec.begin(), vec.end());
        const auto unique_end = std::unique(vec.begin(), vec.end());
        vec.erase(unique_end, vec.end());
    };
    std::vector<int32_t> a = {3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1};
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    elim_dups(a);
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
}

void func_10_11()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    auto is_shorter = [](const std::string &lhs, const std::string &rhs) -> bool { return lhs.size() < rhs.size(); };
    //
    auto elim_dups = [](std::vector<std::string> &vec) -> void {
        std::sort(vec.begin(), vec.end());
        const auto unique_end = std::unique(vec.begin(), vec.end());
        vec.erase(unique_end, vec.end());
    };
    //
    std::vector<std::string> a = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    SPDLOG_INFO("before a: {}", fmt::format("{}", a));
    elim_dups(a);
    SPDLOG_INFO("after a: {}", fmt::format("{}", a));
    std::stable_sort(a.begin(), a.end(), is_shorter);
    SPDLOG_INFO("after after a: {}", fmt::format("{}", a));
}

void func_10_12()
{
    SPDLOG_INFO("\n---------- {} ----------", __func__);
    //
    auto compareIsbn = [](const Sales_data &lhs, const Sales_data &rhs) -> bool { return lhs.isbn() < rhs.isbn(); };
    auto convert2isbn = [](const Sales_data &sd) -> std::string { return sd.isbn(); };
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
    std::transform(a.cbegin(), a.cend(), std::back_inserter(before), convert2isbn);
    SPDLOG_INFO("before a: {}", fmt::format("{}", before));
    std::sort(a.begin(), a.end(), compareIsbn);
    std::vector<std::string> after;
    std::transform(a.cbegin(), a.cend(), std::back_inserter(after), convert2isbn);
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

    return 0;
}