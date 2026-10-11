#include <vector>
#include <iostream>

using namespace std;

struct Coordenada {
    int x;
    int y;
};

int contarCasillasLibres(const vector<vector<char>>& tablero) {
    int total = 0;
    for(size_t i = 0; i < tablero.size(); i++) {
        for(size_t j = 0; j < tablero[i].size(); j++) {
            if(tablero[i][j] != '#') {
                total++;
            }
        }
    }
    return total;
}

vector<int> dFila = {-1, 0, 1, 0};
vector<int> dColumna = {0, -1, 0, 1};

bool esPosicionValida(Coordenada posicion, const vector<vector<bool>>& posRecorridas, const vector<vector<char>>& tablero) {
    int n = tablero.size();
    if(posicion.x >= 0 && posicion.x < n && posicion.y >= 0 && posicion.y < n) {
        if(!posRecorridas[posicion.x][posicion.y] && tablero[posicion.x][posicion.y] != '#') {
            return true;
        }
    }
    return false;
}

void backtracking(Coordenada posInicial, vector<vector<Coordenada>> &soluciones, const vector<vector<char>>& tablero, vector<vector<bool>> &posRecorridas, vector<Coordenada> &recorridoActual, Coordenada posActual, int totalCasillasLibres) {
    
    if(recorridoActual.size() == totalCasillasLibres && posActual.x == posInicial.x && posActual.y == posInicial.y) {
        soluciones.push_back(recorridoActual);
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        Coordenada nuevaPos = {posActual.x + dFila[i], posActual.y + dColumna[i]};

        if(esPosicionValida(nuevaPos, posRecorridas, tablero)) {
            recorridoActual.push_back(nuevaPos);
            posRecorridas[nuevaPos.x][nuevaPos.y] = true;
            
            backtracking(posInicial, soluciones, tablero, posRecorridas, recorridoActual, nuevaPos, totalCasillasLibres);
            
            recorridoActual.pop_back();
            posRecorridas[nuevaPos.x][nuevaPos.y] = false;
        }
    }
}

int main() {
    vector<vector<char>> tablero = {
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
    };
    
    vector<vector<bool>> posRecorridas(tablero.size(), vector<bool>(tablero[0].size(), false));
    vector<Coordenada> recorridoActual;
    vector<vector<Coordenada>> soluciones;
    
    Coordenada posInicial = {0, 0};
    int totalLibres = contarCasillasLibres(tablero);

    backtracking(posInicial, soluciones, tablero, posRecorridas, recorridoActual, posInicial, totalLibres);
    
    cout << soluciones.size() << endl;
    return 0;
}