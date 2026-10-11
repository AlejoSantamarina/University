#include <vector>
#include <iostream>

using namespace std;

struct Coordenada {
    int x; 
    int y;
};

vector<vector<char>> soluciónActual;
vector<vector<vector<char>>> allSoluciones;

bool esValido(char color, Coordenada posActual, const vector<vector<char>>& soluciónActual) {
    int n = soluciónActual.size();
    
    for(int col = 0; col < n; col++) {
        if(soluciónActual[posActual.y][col] == color) {
            return false;
        } 
    }
    
    for(int fila = 0; fila < n; fila++) {
        if(soluciónActual[fila][posActual.x] == color) {
            return false;
        } 
    }
    
    return true;
}

void backTracking(vector<vector<char>>& soluciónActual, Coordenada posActual, const vector<char>& colores, vector<vector<vector<char>>>& allSoluciones) {

    int n = soluciónActual.size();

    if(posActual.y >= n) {
        allSoluciones.push_back(soluciónActual);
        return;
    }

    for(char color : colores) {
        if(esValido(color, posActual, soluciónActual)) {

            soluciónActual[posActual.y][posActual.x] = color;
            
            Coordenada posTemporal;

            if(posActual.x == n - 1) {
                posTemporal.x = 0;             
                posTemporal.y = posActual.y + 1; 
            } else {
                posTemporal.x = posActual.x + 1; 
                posTemporal.y = posActual.y;     
            }
            
            backTracking(soluciónActual, posTemporal, colores, allSoluciones);
            
            soluciónActual[posActual.y][posActual.x] = ' '; 
        }
    }
}