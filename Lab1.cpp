#include <iostream>
using namespace std;


int Merge(int* ini, int* medio, int* fin) {
    int invr = 0;
    int n = fin - ini + 1;
    int* copia = new int[n];
    int* idx = copia;

    int* left = ini;
    int* right = medio + 1;

    while (left <= medio && right <= fin) {
        if (*left <= *right) {
            *idx++ = *left++;
        } else {
            invr += (medio - left + 1);
            *idx++ = *right++;
        }
    }

    while (left <= medio) *idx++ = *left++;
    while (right <= fin) *idx++ = *right++;

    for (int i = 0; i < n; i++) ini[i] = copia[i];

    delete[] copia;

    return invr;
}


int MergeSort(int* ini, int* fin) {
    if (ini >= fin) return 0;

    int* medio = ini + (fin - ini) / 2;
    int izq_inv = MergeSort(ini, medio);
    int der_inv = MergeSort(medio + 1, fin);

    int juntar_inv = Merge(ini, medio, fin);

    return izq_inv + der_inv + juntar_inv;
}

int main() {
    int arr[] = {3, 7, 10, 14, 18, 19, 2, 11, 16, 17, 23, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    int invr = MergeSort(arr, arr + n - 1);

    cout << "Inversiones: " << invr << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
//José Alberto Zegarra Castillo