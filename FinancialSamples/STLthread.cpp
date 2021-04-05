//
// STLthread.cpp
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#include <thread>
#include <iostream>
#include <vector>

void compute_max(const std::vector<double> &values) {
   auto total = 0.0;
   for (auto v : values) {
      total += v;
   }
   std::cout << " total: " << total << std::endl;
}

#ifdef LOCAL_TEST
int main() 
#else
int main_stdthread() 
#endif
{
   std::vector<double> v = {0, 5, 3, 2, 5, 3};
   std::thread first_tread(compute_max, v);
   first_tread.join();
   return 0;
}
