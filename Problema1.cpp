#include <iostream>
using namespace std;

void Fretiro(int arr[], int cant) {
	int suma = 0;
	int contador = 0;

	cout << "Monedas seleccionadas: ";
	
	for (int i = 0; i < cant - 1; i++) {
		if (suma + arr[i] < arr[i + 1]) {
			cout << arr[i] << " ";
			suma += arr[i];
			contador++;
		}
	}
	
	cout << arr[cant - 1] << endl; 
	contador++;
	
	cout << "Total monedas diferentes: " << contador << endl;
}

int main() {
	int c = 0;
	cout << "Cantidad de monedas: " << endl;
	cin >> c;

	int* mon = new int[c];
	cout << "Ingresar monedas ordenadas por valor creciente: " << endl;
	for (int i = 0; i < c; i++) {
		cin >> mon[i];
	}

	Fretiro(mon, c);
	
	delete[] mon;
	return 0;
}

