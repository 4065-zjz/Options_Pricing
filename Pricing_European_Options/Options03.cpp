#include "Options03.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K) {
	cout << "Enter steps to expiry N: ";
	cin >> N;
	cout << "Enter strike price K: ";
	cin >> K;
	cout << endl;
	return 0;
}

double CallPayoff(double z, double K) {
	if (z > K) {
		return z - K;
	}
	else
	{
		return 0.0;
	}

}

double PutPayoff(double z, double K) {
	if (z < K) return K - z;
	return 0.0;
}

double DigitalCallPayoff(double z, double K) {
	if (z > K) return 1.0;
	return 0.0;
}

double DigitalPutPayoff(double z, double K) {
	if (z < K) return (1.0);
	return 0.0;
}

int fact(int n) {
	return(n == 0 || n == 1) ? 1 : fact(n - 1) * n;
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K)) {
	double q = RiskNeutProb(U, D, R);
	double sum = 0;
	for (int i = 0; i <= N; i++) {
		sum = sum + fact(N) / (fact(i) * fact(N - i)) * pow(q, i) * pow(1 - q, N - i) * Payoff(S(S0, U, D, N, i), K);
	}
	double Price = sum / pow(1 + R, N);
	return Price;
}

