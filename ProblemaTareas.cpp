#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tarea {
    int beneficio;
    int deadline;
    int index;
};

bool comparar(Tarea a, Tarea b) {
    return a.beneficio > b.beneficio;
}

int main() {
    cout<<"Ingresar número de tareas y b/p: "<<endl;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<Tarea> tareas(n);
        for (int i = 0; i < n; ++i) {
            cin >> tareas[i].beneficio >> tareas[i].deadline;
            tareas[i].index = i + 1; 
        }

        sort(tareas.begin(), tareas.end(), comparar);

        vector<bool> ocupado(1001, false); 
        vector<int> seleccionadas;
        int beneficioTotal = 0;

        for (Tarea t : tareas) {
            for (int tiempo = t.deadline; tiempo >= 1; --tiempo) {
                if (!ocupado[tiempo]) {
                    ocupado[tiempo] = true;
                    beneficioTotal += t.beneficio;
                    seleccionadas.push_back(t.index);
                    break;
                }
            }
        }

        cout << beneficioTotal << endl;
        for (int i : seleccionadas)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
