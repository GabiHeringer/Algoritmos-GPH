#include "matriz.h"

using namespace std;

Matriz::Matriz(int lin, int col) { //construtor de objetos com alocação dinâmica
    coluna = col;
    linha = lin;

    allocate_function(linha, coluna, &matrix);

}

Matriz::Matriz(const Matriz &matriz_referencia){ //construtor de objetos, tendo outro como referência

    linha = matriz_referencia.getLinha();
    coluna = matriz_referencia.getColuna();

    allocate_function(linha, coluna, &matrix);
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matrix[i][j] = matriz_referencia.getValor(i, j);
        }
    }

}

Matriz::~Matriz(){ //destrutor de objetos
    deallocate_function(matrix);
}


void Matriz::allocate_function(int linha, int coluna, int ***matriz){ //método para alocação dinâmica
    int **mat;
    mat = new int *[coluna];
    for (int i = 0; i < coluna; i++){
        mat[i] = new int [linha];
    }
    *matriz = mat;
}

void Matriz::deallocate_function(int **matriz){ //método que desaloca memória
    for (int i = 0; i < coluna; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matriz::zero (){ //método que preenche uma matriz com zeros
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matrix[i][j] = 0;
        }
    }
}

int* Matriz::operator[] (int x) { //permite acesso direto aos valores da matriz
    return matrix[x];

}

Matriz& Matriz::operator= (const Matriz &matriz){ //permite igualar dois objetos matrizes diretamente

    int lin = matriz.getLinha();
    int col = matriz.getColuna();

    deallocate_function(matrix);
    allocate_function(lin, col, &matrix);

    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] = matriz.getValor(i, j);
        }
    }
    linha = lin;
    coluna = col;

    return *this;
}

bool Matriz::operator==(Matriz &matriz){ //permite verificar se uma matriz é igual a outra
	
	if ((linha != matriz.linha) || (coluna != matriz.coluna)){
		return false;
	}else{

		for(int i = 0; i < linha; i++){
			for(int j = 0; j < coluna; j++){
				if (matrix[i][j] != matriz[i][j]){
					return false;
				}
			}
		}
	}	
	return true;
}

Matriz Matriz::operator+ (Matriz &matriz){ //permite somar dois objetos matrizes diretamente

    int lin = matriz.linha;
    int col = matriz.coluna;

    if ((lin != linha) || (col != coluna)){
        throw invalid_argument("Numero de linhas e colunas devem ser iguais!");
    }

    Matriz aux (lin, col);

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            aux[i][j] = matrix[i][j] + matriz[i][j];
        }
    }

    return aux;
}

Matriz Matriz::operator- (Matriz &matriz){ //permite subtrair dois objetos matrizes diretamente

    int lin = matriz.linha;
    int col = matriz.coluna;

    if ((lin != linha) || (col != coluna)){
        throw invalid_argument("Numero de linhas e colunas devem ser iguais!");
    }

    Matriz aux (lin, col);

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            aux[i][j] = matrix[i][j] - matriz[i][j];
        }
    }

    return aux;
}

Matriz Matriz::operator* (Matriz &matriz){ //permite multiplicar objetos matrizes

    int lin2 = matriz.linha;
    int col2 = matriz.coluna;

    if (coluna != lin2){
        throw invalid_argument("Numero de colunas da matriz 1 e linhas da matriz 2 devem ser iguais!");
    }

    Matriz aux (linha, col2);
    aux.zero();

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < col2; j++){
            for(int k = 0; k < coluna; k++){
                aux[i][j] += matrix[i][k] * matriz[k][j];
            }
        }
    }

    return aux;
}



int Matriz::getLinha() const{ //método para acessar a quantidade de linhas da matriz
    return linha;
}

int Matriz::getColuna() const{ //método para acessar a quantidade de colunas da matriz
    return coluna;
}

int Matriz::getValor(int i, int j) const{ //método para acessar um valor da matriz
	return matrix[i][j];
}

