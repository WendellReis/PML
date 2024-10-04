#include <iostream>
#include <vector>
#include <cmath>
#include "Neural.h" // Supondo que sua classe Neural esteja neste arquivo

using namespace std;

int main() {
    // Definindo parâmetros da rede
    int size = 2;  // Número de entradas (x0 = 1, x1 = valor de entrada real)
    double learning_rate = 0.01;
    Neural neural(size, learning_rate);

    // Dados de treino: x1 -> y (desejado)
    vector<vector<double>> inputs = {
        {1, 0},  // x0 = 1, x1 = 0
        {1, 1},  // x0 = 1, x1 = 1
        {1, 2},  // x0 = 1, x1 = 2
        {1, 3},  // x0 = 1, x1 = 3
        {1, 4}   // x0 = 1, x1 = 4
    };
    vector<double> desired_outputs = {1, 3, 5, 7, 9};  // Saídas desejadas y = 2x + 1

    // Treinando a rede
    int epochs = 1000;
    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_error = 0;
        for (size_t i = 0; i < inputs.size(); i++) {
            neural.train(inputs[i], desired_outputs[i]);
            double prediction = neural.predict(inputs[i]);
            double error = desired_outputs[i] - prediction;
            total_error += error * error;  // Erro quadrático
        }

        // Exibir erro a cada 100 épocas
        if (epoch % 100 == 0) {
            cout << "Epoch " << epoch << " - Erro quadrático total: " << total_error << endl;
        }
    }

    // Testar a rede treinada
    cout << "\nTestando a rede neural após o treinamento:\n";
    for (size_t i = 0; i < inputs.size(); i++) {
        double prediction = neural.predict(inputs[i]);
        cout << "Entrada: (" << inputs[i][1] << ") -> Previsão: " << prediction
             << ", Esperado: " << desired_outputs[i] << endl;
    }

    // Verificando pesos finais
    cout << "\nPesos finais da rede neural:\n";
    neural.getWeight();

    return 0;
}
