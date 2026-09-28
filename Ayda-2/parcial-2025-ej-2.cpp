#include <vector>
#include <iostream>

using namespace std;

struct Coordenada {
    int x;
    int y;
};

vector<vector<char>> tablero;
vector<vector<bool>> posRecorridas;
vector<Coordenada> recorridoActual = {};
vector<vector<Coordenada>> soluciones;

int casillasLibres() {
    int totalCasillasLibres = 0;
    for(int i = 0; i < tablero.size(); i++) {
        for(int j = 0; j < tablero[i].size(); j++) {
            if(tablero[i][j] != '#') {
                totalCasillasLibres++;
            }
        }
    }
    return totalCasillasLibres;
}

vector<int> dFila = {-1, 0, 1, 0};
vector<int> dColumna = {0, -1, 0, 1};

bool esPosicionValida(Coordenada posicion, const vector<Coordenada>& recorridoActual, const vector<vector<bool>>& posRecorridas, const vector<vector<char>>& tablero) {
    if(-1 < posicion.x && posicion.x < 4 && -1 < posicion.y && posicion.y < 4) {
        if((posRecorridas[posicion.x][posicion.y] == false) && (tablero[posicion.x][posicion.y] != '#')) {
        return true;
        }
    }
    return false;
}

void backtracking (Coordenada posInicial, vector<vector<Coordenada>> &soluciones, const vector<vector<char>>& tablero, vector<vector<bool>> &posRecorridas, vector<Coordenada> &recorridoActual, Coordenada posActual) {
    if((recorridoActual.size() == casillasLibres()) && (posActual.x == posInicial.x && posActual.y == posInicial.y)) {
        soluciones.push_back(recorridoActual);
        //En este caso no estariamos agregando de manera repetida la posición inicial, ya que esta se añadiria al final, pero siempre sabemos cual es la posición inicial porque tenemos ese dato en la variable posInicial.
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        Coordenada nuevaPos;
        nuevaPos.x = posActual.x + dFila[i];
        nuevaPos.y = posActual.y + dColumna[i];

        if(esPosicionValida(nuevaPos, recorridoActual, posRecorridas, tablero)) {
            recorridoActual.push_back(nuevaPos);
            posRecorridas[nuevaPos.x][nuevaPos.y] = true;
            backtracking(posInicial, soluciones, tablero, posRecorridas, recorridoActual, nuevaPos);
            recorridoActual.pop_back();
            posRecorridas[nuevaPos.x][nuevaPos.y] = false;
        }
    }
}

int main() {
    tablero = {
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
    };
    posRecorridas.assign(tablero.size(), vector<bool>(tablero[0].size(), false));
    Coordenada posInicial = {0, 0};
    backtracking(posInicial, soluciones, tablero, posRecorridas, recorridoActual, posInicial);
    cout << soluciones.size() << endl;
    return 0;
}