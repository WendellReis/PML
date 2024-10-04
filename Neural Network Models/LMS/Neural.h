#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neural {
    private:
        int size;
        double learning_rate;
        vector<double> x;
        vector<double> w;
    
    public:
        Neural(int size, double learning_rate) {
            this->size = size;
            this->learning_rate = learning_rate;
            w = vector<double>(size,0);
        }

        void getWeight() {
            for(int i = 0; i < size; i++)
                printf("w%d = %lf\n",i,w[i]);
        }

        double run() {
            double sum = 0;
            for(int i = 0; i < size; i++)
                sum+=w[i]*x[i];
            return sum;
        }

        void train(vector<double>& in, double desired) {
            if(in.size() != size) {
                cout << "Input size does not match the number of weights!\n";
                return;
            }

            x = in;
            double y = run();
            double e = desired - y;

            for(int i = 0; i < size; i++)
                w[i] = w[i] + learning_rate*x[i]*e;
        }

        double predict(vector<double>& in) {
            if(in.size() != size) {
                cout << "Input size does not match the number of weights!\n";
                return NAN;
            }

            x = in;
            return run();
        }
};