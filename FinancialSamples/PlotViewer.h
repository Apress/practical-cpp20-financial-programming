//
//  PlotViewer.h
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#ifndef __FinancialSamples__PlotViewer__
#define __FinancialSamples__PlotViewer__


class PlotViewer {
public:
    PlotViewer();
    PlotViewer(const PlotViewer &p);
    ~PlotViewer();
    PlotViewer &operator=(const PlotViewer &p);
};

#endif /* defined(__FinancialSamples__PlotViewer__) */
