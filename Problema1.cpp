#include <iostream>
using namespace std;

void Fretiro(int arr[], int cant, int retiro ) {
	int* sol = new int[cant];
	if (retiro <= 0) return;
	for (int i = cant-1; i >= 0; i--) {
		if (retiro - arr[i] >= 0) {
			retiro -= arr[i];
			sol[i] = arr[i];
		}
		else
			sol[i] = 0;
	}
	for (int i = 0; i < cant; i++)
		if (sol[i] == 0) cout << "";
		else
			cout << sol[i] << " ";
	delete[] sol;
}
int main()
{
	int c=0;
	cout << "Cantidad de monedas: " << endl;
	cin >> c;
	int* mon = new int[c];
	cout << "Ingresar monedas: " << endl;
	for (int i = 0; i < c; i++) {
		cin >> mon[i];
	}
	int r = 0;
	cout << "Ingresar retiro: " << endl;
	cin >> r;
	Fretiro(mon, c, r);
	delete[] mon;
	return 0;
}
