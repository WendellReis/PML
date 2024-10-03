#include <iostream>
#include "Perceptron.h"

using namespace std;

int main() {
	/*
		Perceptron para classificam de pontos 2D nas classes:
		C1: pontos (x,y) onde x > y (1)
		C2: pontos (x,y) onde x <= y (-1)
	*/

	Perceptron net(2,0.1);

	vector<vector<double>> trainning_set = {
		{1,1},
		{2,1},
		{4,3},
		{-5,9},
		{-1,0},
		{2,10},
		{12.7,-2},
		{-9,10.48},
		{25,1},
		{12,-8}
	};

	vector<double> desired = {-1,1,1,-1,-1,-1,1,-1,1,1};

	for(int i = 0; i < trainning_set.size(); i++)
		net.train(trainning_set[i],desired[i]);
	
	net.getWeights();
	vector<double> test = {1,-1};
	cout << net.predict(test) << endl;

	return 0;
}