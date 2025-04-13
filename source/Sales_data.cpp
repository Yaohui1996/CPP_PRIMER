#include "Sales_data.h"

// 和类相关的非成员函数的定义
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.book_id_ >> item.sold_cnt_ >> price;
    item.revenue_ = price * item.sold_cnt_;
    return is;
}

std::ostream &print(const Sales_data &item, std::ostream &os)
{
    os << item.isbn() << " " << item.sold_cnt_ << " " << item.revenue_ << " " << item.avg_price();
    return os;
}

// 成员函数的定义
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}
Sales_data::Sales_data(std::string book_id, unsigned int sold_cnt, double price)
    : book_id_(book_id), sold_cnt_(sold_cnt), revenue_(sold_cnt * price)
{
}

Sales_data::Sales_data(std::string book_id) : book_id_(book_id), sold_cnt_(0), revenue_(0.0)
{
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    this->sold_cnt_ += rhs.sold_cnt_;
    this->revenue_ += rhs.revenue_;
    return *this;
}

inline double Sales_data::avg_price() const
{
    if (sold_cnt_)
    {
        return revenue_ / sold_cnt_;
    }
    return 0.0;
}

std::string Sales_data::isbn() const
{
    return this->book_id_;
}
