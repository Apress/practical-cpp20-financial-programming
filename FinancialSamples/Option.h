//
//  Option.h
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#ifndef __FinancialSamples__Option__
#define __FinancialSamples__Option__

#include <string>

class Option {
public:
    Option(const std::string &ticker, double strike);
    Option(const Option &p);
    ~Option();
    Option &operator=(const Option &p);

    std::string ticker();
    double strike();

    void setTicker(const std::string &);
    void setStrike(double);

private:
    std::string m_ticker;
    double m_strike;

};

#endif /* defined(__FinancialSamples__Option__) */
