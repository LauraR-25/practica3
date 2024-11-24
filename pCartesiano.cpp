#include <iostream>
using namespace std;

struct P {
    float x = 0;
    float y = 0;
};

int determinarCuadrante(float x, float y){
    if (x > 0 && y > 0){
        return 1;
    } else if (x < 0 && y > 0){
        return 2;
    } else if (x < 0 && y < 0){
        return 3;
    } else if (x > 0 && y < 0){
        return 4;
    } else if (x == 0 && y == 0){
        return 5;
    } else if (x == 0){
        return 6;
    } else if (y == 0){
        return 7;
    }

    return 0;
}

bool verificarEcuacion(float x, float y) {
    return y == (x + 1);
}

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de pares de datos que desea ingresar: ";
    cin >> cantidad;
    P coordenadas[cantidad];

    for (int i=0; i<cantidad; i++) {
        cout << "Ingrese los datos de X" << i + 1 << ": ";
        cin >> coordenadas[i].x;
        cout << "Ingrese los datos de Y" << i + 1 << ": ";
        cin >> coordenadas[i].y;
    }

    for (int i=0; i<cantidad; i++){
        int resultado = determinarCuadrante(coordenadas[i].x, coordenadas[i].y);
        if (resultado == 1){
            cout<< "Este par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] pertenece al primer cuadrante."<< endl;
        } else if (resultado == 2){
            cout << "Este par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] pertenece al segundo cuadrante."<< endl;
        } else if (resultado == 3){
            cout << "Este par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] pertenece al tercer cuadrante."<< endl;
        } else if (resultado == 4){
            cout << "Este par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] pertenece al cuarto cuadrante."<< endl;
        } else if (resultado == 5){
            cout << "El par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] pertenece al origen."<< endl;
        } else if (resultado == 6){
            cout << "Este par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] se encuentra sobre el eje Y."<< endl;
        } else if (resultado == 7){
            cout << "Este par ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] se encuentra sobre el eje X."<< endl;
        }
    }

    for (int i=0; i<cantidad; i++){
        if(verificarEcuacion(coordenadas[i].x, coordenadas[i].y)){
            cout << "Las coordenadas: ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] pertenecen a la ecuación f(x) = x + 1."<< endl;
        } else{
            cout << "Las coordenadas: ["<< coordenadas[i].x << ","<< coordenadas[i].y << "] no pertenecen a la ecuación f(x) = x + 1."<< endl;
        }
    }

    return 0;
}