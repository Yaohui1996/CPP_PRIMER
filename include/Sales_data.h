#ifndef YAOHUI_SALES_DATA_H
#define YAOHUI_SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(const Sales_data &item, std::ostream &os);

  public:
    Sales_data(std::istream &is);
    Sales_data(std::string book_id, unsigned int sold_cnt, double price);
    Sales_data(std::string book_id);
    Sales_data() = default;

    // 一个isbn成员函数，用于返回对象的ISBN编号
    std::string isbn() const;

    // 一个combine成员函数，用于将一个Sales_data对象加到另一个对象上
    Sales_data &combine(const Sales_data &rhs);

  private:
    std::string book_id_;       // 表示ISBN编号
    unsigned int sold_cnt_ = 0; // 表示某本书的销量
    double revenue_ = 0.0;      // 表示这本书的总销售收入

  private:
    double avg_price() const; // 返回售出书籍的平均价格
};

// 和类相关的非成员函数的声明
// 一个名为add的函数，执行两个Sales_data对象的加法
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

// 一个read函数，将数据从istream读入到Sales_data对象中
std::istream &read(std::istream &is, Sales_data &item);

// 一个print函数，将Sales_data对象的值输出到ostream
std::ostream &print(const Sales_data &item, std::ostream &os);

#endif // YAOHUI_SALES_DATA_H