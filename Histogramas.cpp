#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

double distanciaE(vector<float> p1, vector<float> p2, int dimension) {
    double suma = 0;
    for (int i = 0; i < dimension; i++) {
        suma += pow((p1[i] - p2[i]), 2);
    }
    suma = sqrt(suma);
    return suma;
}

//distancia para tratar de encontrar patrones
//+ dimensiones, menos datos diferentes
//4950 en el vector de distancias (combinatoria de 100 y 2)

void PuntosAleatorios(int numpuntos, int dim) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1.0);
    vector<vector<float>> puntos;
    vector<double> distancias;
    vector<float> tmp;
    for (int i = 0; i < numpuntos; i++) {
        tmp.clear();
        for (int j = 0; j < dim; j++) {
            tmp.push_back(dis(gen));
        }
        puntos.push_back(tmp);
    }
    for (int j = 0; j < numpuntos; j++) {
        for (int k = j + 1; k < numpuntos; k++) {
            if (j != k) {
                distancias.push_back(distanciaE(puntos[j], puntos[k], dim));
            }
        }
    }
    stringstream filename_stream;
    filename_stream << "distancias_" << dim << ".txt";
    string filename = filename_stream.str();

    ofstream archivo(filename);

    if (archivo.is_open()) {
        for (double distancia : distancias) {
            archivo << distancia << endl;
        }
        archivo.close();
    }
    else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {

    PuntosAleatorios(100, 10);
    PuntosAleatorios(100, 50);
    PuntosAleatorios(100, 100);
    PuntosAleatorios(100, 500);
    PuntosAleatorios(100, 1000);
    PuntosAleatorios(100, 2000);
    PuntosAleatorios(100, 5000);

}