#include <vector>
#include <iostream>

using namespace std;

struct Coordenada {
    int x;
    int y;
};

vector<Coordenada> recorridoOptimo;

vector<int> dFila = {0, 0, -1, 1};
vector<int> dColumna = {1, -1, 0, 0};

bool esPosicionValida(Coordenada posicion, const vector<vector<int>>& tablero, vector<vector<bool>>& posRecorridas) {
    if(posicion.x >= 0 && posicion.x < tablero.size() && posicion.y >= 0 && posicion.y < tablero[0].size()) {
        if((tablero[posicion.x][posicion.y] != -1) && (posRecorridas[posicion.x][posicion.y] == false)) {
            return true;
        }
        return false;
    }
    return false;
}

void backTracking(Coordenada posActual, Coordenada& posFinal, const vector<vector<int>>& tablero, int costoActual, int& costoOptimo, vector<Coordenada>& recorridoActual, vector<vector<bool>>& posRecorridas) {
    if(costoActual >= costoOptimo) {
        return;
    }    
        
    if(posActual.x == posFinal.x && posActual.y == posFinal.y) {
        recorridoOptimo = recorridoActual;
        costoOptimo = costoActual;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        Coordenada nuevaPosicion = {posActual.x + dFila[i], posActual.y + dColumna[i]};
        if(esPosicionValida(nuevaPosicion, tablero, posRecorridas)) {
            recorridoActual.push_back(nuevaPosicion);
            costoActual = costoActual + tablero[nuevaPosicion.x][nuevaPosicion.y];
            posRecorridas[nuevaPosicion.x][nuevaPosicion.y] = true;
            backTracking(nuevaPosicion, posFinal, tablero, costoActual, costoOptimo, recorridoActual, posRecorridas);
            recorridoActual.pop_back();
            costoActual = costoActual - tablero[nuevaPosicion.x][nuevaPosicion.y];
            posRecorridas[nuevaPosicion.x][nuevaPosicion.y] = false;
        }
    }                            

}
