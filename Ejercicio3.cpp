#include <iostream>
#include <algorithm>
using namespace std;


void maxContenedores(int* pesos, int cantidad, int capacidad) {
    sort(pesos, pesos + cantidad); 

    int suma = 0, cont = 0;
    int* cargados = new int[cantidad];

    for (int i = 0; i < cantidad; i++) {
        if (suma + pesos[i] <= capacidad) {
            suma += pesos[i];
            cargados[cont++] = pesos[i];
        } else break;
    }
//Hacer con punteros después
    cout << "\n[1.a] Máximo número de contenedores: " << cont << endl;
    cout << "Pesos cargados: ";
    for (int i = 0; i < cont; i++)
        cout << cargados[i] << " ";
    cout << endl;

    delete[] cargados;
}


void maxToneladas(int* pesos, int cantidad, int capacidad) {
    sort(pesos, pesos + cantidad, greater<int>()); 

    int suma = 0, cont = 0;
    int* cargados = new int[cantidad];

    for (int i = 0; i < cantidad; i++) {
        if (suma + pesos[i] <= capacidad) {
            suma += pesos[i];
            cargados[cont++] = pesos[i];
        }
    }

    cout << "\n[1.b] Máximo peso cargado: " << suma << " toneladas" << endl;
    cout << "Contenedores usados: ";
    for (int i = 0; i < cont; i++)
        cout << cargados[i] << " ";
    cout << endl;

    delete[] cargados;
}

int main() {
    int n = 0;
    cout << "Cantidad de contenedores: ";
    cin >> n;

    int* pesos = new int[n];
    cout << "Pesos de los contenedores (en toneladas): ";
    for (int i = 0; i < n; i++)
        cin >> pesos[i];

    int capacidad = 0;
    cout << "Capacidad del buque (en toneladas): ";
    cin >> capacidad;

    maxContenedores(pesos, n, capacidad);  
    maxToneladas(pesos, n, capacidad);     

    delete[] pesos;
    return 0;
}
