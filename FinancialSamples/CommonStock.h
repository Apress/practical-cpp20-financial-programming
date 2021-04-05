//
//  CommonStock.h
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#ifndef __FinancialSamples__CommonStock__
#define __FinancialSamples__CommonStock__

#include <string>

class CommonStock {
public:
    CommonStock(const std::string ticker);
    ~CommonStock();
    CommonStock(const CommonStock &);
    CommonStock operator = (const CommonStock &);

    std::string getTicker();
};

#endif /* defined(__FinancialSamples__CommonStock__) */
