#include <iostream>
#include <cmath>
using namespace std;

struct Coordenada{
    float x;
    float y;
};

float calcularDistancia(const Coordenada& a, const Coordenada& b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool estaEnCuadrante(const Coordenada& punto, int cuadrante){
    switch (cuadrante){
        case 1: return punto.x > 0 && punto.y > 0;
        case 2: return punto.x < 0 && punto.y > 0;
        case 3: return punto.x < 0 && punto.y < 0;
        case 4: return punto.x > 0 && punto.y < 0;
        default: return false;
    }
}

float calcularDistanciaMaxima(const Coordenada puntos[], int n, int cuadrante, int& indice1, int& indice2){
    float distanciaMax = 0;
    indice1 = -1;
    indice2 = -1;

    for (int i=0; i<n; i++){
        if (estaEnCuadrante(puntos[i], cuadrante)){
            for (int j=i+1; j<n; j++){
                if (estaEnCuadrante(puntos[j], cuadrante)){
                    float distancia = calcularDistancia(puntos[i], puntos[j]);
                    if (distancia > distanciaMax){
                        distanciaMax = distancia;
                        indice1 = i;
                        indice2 = j;
                    }
                }
            }
        }
    }

    return distanciaMax;
}

int main(){
    int n, cuadrante;
    int indice1, indice2;

    cout << "Inserte la cantidad de coordenadas que quiere insertar: ";
    cin >> n;

    Coordenada puntos[n];

    for (int i = 0; i < n; i++){
        cout << "Ingrese la coordenada X"<< i + 1<< ": ";
        cin >> puntos[i].x;
        cout << "Ingrese la coordenada Y"<< i + 1<< ": ";
        cin >> puntos[i].y;
    }

    cout << "Elija un cuadrante como límite:" << endl;
    cout << "1. Primer cuadrante" << endl;
    cout << "2. Segundo cuadrante" << endl;
    cout << "3. Tercer cuadrante" << endl;
    cout << "4. Cuarto cuadrante" << endl;
    cin >> cuadrante;

    if (cuadrante < 1 || cuadrante > 4){
        cout << "No se eligió un cuadrante válido." << endl;
        return 1;
    }

    float distanciaMax = calcularDistanciaMaxima(puntos, n, cuadrante, indice1, indice2);

    if (indice1 != -1 && indice2 != -1){
        cout << "La distancia máxima es: "<< distanciaMax << endl;
        cout << "Entre los puntos: ["<< puntos[indice1].x << ", "<< puntos[indice1].y << "] y ["
             << puntos[indice2].x << ", "<< puntos[indice2].y << "]."<< endl;
    } else{
        cout << "No hay puntos suficientes en el cuadrante seleccionado para calcular la distancia máxima."<< endl;

        return 1;
    }

    int puntoSeleccionado;
    cout << "Ingrese el índice del punto para calcular distancias (0 a "<< n - 1 << "): ";
    cin >> puntoSeleccionado;

    if (puntoSeleccionado < 0 || puntoSeleccionado >= n){
        cout << "Índice no válido." << endl;
        return 1;
    }

    cout << "Distancias desde el punto ["<< puntos[puntoSeleccionado].x << ", "<< puntos[puntoSeleccionado].y << "]:"<< endl;

    for (int i=0; i<n; i++){
        if (i != puntoSeleccionado && estaEnCuadrante(puntos[i], cuadrante)){
            float distancia = calcularDistancia(puntos[puntoSeleccionado], puntos[i]);
            cout << "- Distancia al punto ["<< puntos[i].x << ", "<< puntos[i].y << "]: "<< distancia << endl;
        }
    }

    return 0;
}