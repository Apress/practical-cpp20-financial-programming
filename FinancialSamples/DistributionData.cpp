//
// DistributionData.cpp
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net


#include "DistributionData.h"

#include <iostream>

#include <random>

using std::quantile;

static boost::rand48 random_generator;

using std::cout;
using std::endl;
using std::string;


DistributionData::DistributionData()
{
}

DistributionData::~DistributionData()
{
}

std::vector<double> DistributionData::gaussianData(int nPoints, double mean, double sigma)
{
	std::vector<double> data;

	boost::random::normal_distribution<> distrib(mean, sigma);

	for (int i=0; i<nPoints; ++i)
	{
		double val = distrib(random_generator);
		data.push_back(val);
	}

	return data;
}

std::vector<double> DistributionData::exponentialData(int nPoints, double rate)
{
    std::vector<double> data;

	boost::random::exponential_distribution<> distrib(rate);

	for (int i=0; i<nPoints; ++i)
	{
		double val = distrib(random_generator);
		data.push_back(val);
	}

	return data;
}

std::vector<double> DistributionData::logNormalData(int nPoints, double mean, double sigma)
{
    std::vector<double> data;

	boost::random::lognormal_distribution<> distrib(mean, sigma);

	for (int i=0; i<nPoints; ++i)
	{
		double val = distrib(random_generator);
		data.push_back(val);
	}

	return data;
}


std::vector<double> DistributionData::chiSquaredData(int nPoints, int degreesOfFreedom)
{
	std::vector<double> data;

	boost::random::chi_squared_distribution<> distrib(degreesOfFreedom);

	for (int i=0; i<nPoints; ++i)
	{
		double val = distrib(random_generator);
		data.push_back(val);
	}

	return data;
}

double DistributionData::gaussianQuantile(double x, double mean, double sigma)
{
	std::normal_distribution<> dist(mean, sigma);

	return quantile(dist, x);
}


double DistributionData::chiSquaredQuantile(double x, int degreesOfFreedom)
{
	std::chi_squared_distribution<> dist(degreesOfFreedom);

	return quantile(dist, x);
}

double DistributionData::exponentialQuantile(double x, double rate)
{
    std::exponential_distribution<> dist(rate);

	return quantile(dist, x);
}

double DistributionData::logNormalQuantile(double x, double mean, double sigma)
{
    std::lognormal_distribution<> dist(mean, sigma);

	return quantile(dist, x);
}

namespace  {
    template <class T>
    void printData(const string &label, const T &data)
    {
        cout << " " << label << ":  ";
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

#ifdef LOCAL_TEST
int main()
#else
int main_distdata()
#endif
{
    DistributionData dData;
    auto gdata = dData.gaussianData(10, 5, 2);
    printData("gaussian data", gdata);

    auto edata = dData.exponentialData(10, 4);
    printData("exponential data", edata);

    auto kdata = dData.chiSquaredData(10, 5);
    printData("chi squared data", kdata);

    auto ldata = dData.logNormalData(10, 8, 2);
    printData("log normal data", ldata);
    return 0;
}

