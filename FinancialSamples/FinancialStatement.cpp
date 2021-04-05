//
//  FinancialStatement.cpp
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#include "FinancialStatement.h"

#include <iostream>
using std::cout;
using std::endl;

FinancialStatement::FinancialStatement()
: m_return(0)
{

}

FinancialStatement::~FinancialStatement()
{

}

FinancialStatement::FinancialStatement(const FinancialStatement &v)
: m_return(v.m_return),
m_transactions(v.m_transactions)
{

}

FinancialStatement &FinancialStatement::operator=(FinancialStatement &v)
{
    if (this != &v)
    {
        m_return = v.m_return;
        m_transactions = v.m_transactions;
    }
    return *this;
}

double FinancialStatement::getReturn()
{
    return m_return;
}

void FinancialStatement::addTransaction(const std::string &security, double val)
{
    m_transactions.push_back(std::make_pair(security, val));
}

// returns a sample statement that includes a few common stocks
std::unique_ptr<FinancialStatement> getSampleStatement()
{
    std::unique_ptr<FinancialStatement> fs(new FinancialStatement);
    fs->addTransaction("IBM", 102.2);
    fs->addTransaction("AAPL", 523.0);
    return fs;
}

void transferFinancialStatement(std::unique_ptr<FinancialStatement> &statement)
{
    // perform transfer here
    // ...
    // statement is still valid
    std::unique_ptr<FinancialStatement> another = std::move(statement);
    std::cout << statement->getReturn() << std::endl;
    // statement is released here
}

#ifdef LOCAL_TEST
int main() {
#else
int main_finstat() {
#endif
   cout << "financial statement" << endl;
   std::unique_ptr<FinancialStatement> afs(new FinancialStatement());
   afs->addTransaction("IBM", 100);
   transferFinancialStatement(afs);
   afs->addTransaction("IBM", 100);
   
   return 0;
}
// f=FinancialStatement && rm -f ./$f &&  make $f CXXFLAGS=-std=c++2a\ -DLOCAL_TEST=1  LDFLAGS=-L/opt/homebrew/lib\ -lglpk\ Matrix.o\ LPSolver.o 
