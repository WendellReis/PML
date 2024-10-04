#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

class Perceptron {
    private:
        int size;
        double b; //bias
        double learning_rate;
        vector<double> x;
        vector<double> w;
    
    public:
        Perceptron(int size, double learning_rate) {
            srand(time(NULL));
            this->size = size;
            this->learning_rate = learning_rate;
            b = (double)rand()/RAND_MAX;
            x = vector<double>(size+1);
            x[0] = 1;
            w = vector<double>(size+1,0);
            w[0] = b;
        }

        void getWeights() {
            for(int i = 0; i <= this->size; i++)
                printf("w%d = %lf\n",i,w[i]);
        }

        void getInput() {
            for(int i = 0; i <= this->size; i++)
                printf("x%d = %lf\n",i,x[i]);
        }

        //Threshold Function
        double activation(double v) {
            if(v > 0)
                return 1;
            return -1;
        }

        double run() {
            double sum = 0;
            for(int i = 0; i <= this->size; i++)
                sum+=w[i]*x[i];
            return this->activation(sum);
        }

        void train(vector<double> &in, double d) {
            for(int i = 1; i <= this->size; i++)
                x[i] = in[i-1];
            
            double y = run(); //actual response quantized

            if(d == y)
                return;
            
            for(int i = 0; i <= this->size; i++)
                w[i] = w[i] + learning_rate*(d-y)*x[i];
        }

        double predict(vector<double> in) {
            for(int i = 1; i <= this->size; i++)
                x[i] = in[i-1];
            return run();
        }
    
};