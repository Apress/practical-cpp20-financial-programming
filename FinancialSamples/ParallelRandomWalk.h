//
// ParallelRandomWalk.cpp
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#ifndef __FinancialSamples__ParallelRandomWalk__
#define __FinancialSamples__ParallelRandomWalk__

class ParallelRandomWalk  {
public:
    ParallelRandomWalk(int size, double strike, double step);
    ParallelRandomWalk(const ParallelRandomWalk &p);
    ~ParallelRandomWalk();
    ParallelRandomWalk &operator=(const ParallelRandomWalk &p);

    double probFinishAboveStrike();

private:
    int m_size;     // number of steps
    double m_step;  // size of each step (in percentage)
    double m_start; // starting price
};

#endif /* defined(__FinancialSamples__ParallelRandomWalk__) */
