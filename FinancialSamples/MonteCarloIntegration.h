//
// MonteCarloIntegration.h
//
// (c) 2015-2021 Carlos Oliveira
// This code is part of the book "Practical C++20 Financial Programming"
//    by Carlos Oliveira, Apress, 2015-2021.
// For more information, visit http://coliveira.net

#ifndef __FinancialSamples__MONTECARLOINTEGRATION_H_
#define __FinancialSamples__MONTECARLOINTEGRATION_H_

template <class T>
class MathFunction;

class MonteCarloIntegration {
public:
	MonteCarloIntegration(MathFunction<double> &f);
   MonteCarloIntegration(MathFunction<double> &f, int num_samples);
	MonteCarloIntegration(const MonteCarloIntegration &p);
	~MonteCarloIntegration();
	MonteCarloIntegration &operator=(const MonteCarloIntegration &p);

	void setNumSamples(int n);
	double getIntegral(double a, double b);
    double integrateRegion(double a, double b, double min, double max);
private:
    MathFunction<double> &m_f;
    int m_numSamples;

};




#endif /* MONTECARLOINTEGRATION_H_ */
