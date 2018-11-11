#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>
#include "matriz.cpp"
#include "testes.h"

using namespace std;

ostream& operator<<(ostream &os, Matriz& matriz);
istream& operator>>(istream &is, Matriz& matriz);

int main(int argc, char **argv) {
    
    ::testing::InitGoogleTest(&argc, argv);
    Matriz mat (2,2);
    cout << "Digite valores para a matriz 2x2:" << endl;
    cin >> mat;
    cout << "Matriz digitada:  //Overload do operador <<" << endl << mat;
    cout << "Executando testes para os operadores..." << endl;
    return RUN_ALL_TESTS();

}


ostream& operator<<(ostream &os, Matriz &matriz){ //overload do operador << para imprimir a matriz
    for(int i = 0; i < matriz.getLinha(); i++){
        for(int j = 0; j < matriz.getColuna(); j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;;
    }
    return os;
}

istream& operator>>(istream &is,Matriz &matriz){ //overload do operador >> para dar valores a matriz
    for(int i = 0; i < matriz.getLinha(); i++){
        for(int j = 0; j < matriz.getColuna(); j++){
            cin >> matriz[i][j];
        }
    }
    return is;
}
