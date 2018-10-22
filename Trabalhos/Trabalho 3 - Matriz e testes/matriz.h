#ifndef Matriz_h
#define Matriz_h

using namespace std;

class Matriz{
    public:
        Matriz (int linha,int coluna);
        Matriz (const Matriz &matriz_referencia);
        Matriz& operator=(const Matriz &matriz);
        Matriz operator+(Matriz &matriz);
        Matriz operator-(Matriz &matriz);
        Matriz operator*(Matriz &matriz);

        void zero();

        int *operator[] (int x);
        int getLinha();
        int getColuna();

        ~Matriz();

    private:
        void allocate_function(int linha, int coluna, int ***matriz);
        void deallocate_function(int **matriz);

    protected:
        int **matrix;
        int linha, coluna;
};

Matriz::Matriz(int lin, int col) { //construtor de objetos com alocação dinâmica
    coluna = col;
    linha = lin;

    allocate_function(linha, coluna, &matrix);

}

Matriz::Matriz(const Matriz &matriz_referencia){ //construtor de objetos, tendo outro como referência

    linha = matriz_referencia.linha;
    coluna = matriz_referencia.coluna;

    allocate_function(linha, coluna, &matrix);
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matrix[i][j] = matriz_referencia.matrix[i][j];
        }
    }

}

Matriz::~Matriz(){ //destrutor de objetos
    deallocate_function(matrix);
}


void Matriz::allocate_function(int linha, int coluna, int ***matriz){ // função para alocação dinâmica
    int **mat;
    mat = new int *[linha];
    for (int i = 0; i < linha; i++){
        mat[i] = new int [coluna];
    }
    *matriz = mat;
}

void Matriz::deallocate_function(int **matriz){ //função que desaloca memória
    for (int i = 0; i < coluna; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matriz::zero (){ //função que preenche uma matriz com zeros
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

    int lin = matriz.linha;
    int col = matriz.coluna;

    deallocate_function(matrix);
    allocate_function(lin, col, &matrix);

    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] = matriz.matrix[i][j];
        }
    }
    linha = lin;
    coluna = col;

    return *this;
}

Matriz Matriz::operator+ (Matriz &matriz){ //permite somar dois objetos matrizes diretamente

    int lin = matriz.linha;
    int col = matriz.coluna;

    if ((lin != this->linha) || (col != this->coluna)){
        throw invalid_argument("Numero de linhas e colunas devem ser iguais!");
    }

    Matriz aux (lin, col);

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            aux.matrix[i][j] = matrix[i][j] + matriz.matrix[i][j];
        }
    }

    return aux;
}

Matriz Matriz::operator- (Matriz &matriz){ //permite subtrair dois objetos matrizes diretamente

    int lin = matriz.linha;
    int col = matriz.coluna;

    if ((lin != this->linha) || (col != this->coluna)){
        throw invalid_argument("Numero de linhas e colunas devem ser iguais!");
    }

    Matriz aux (lin, col);

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            aux.matrix[i][j] = matrix[i][j] - matriz.matrix[i][j];
        }
    }

    return aux;
}

Matriz Matriz::operator* (Matriz &matriz){ //permite multiplicas objetos matrizes

    int lin1 = linha;
    int col1 = coluna;

    int lin2 = matriz.linha;
    int col2 = matriz.coluna;

    if (col1 != lin2){
        throw invalid_argument("Numero de colunas da matriz 1 e linhas da matriz 2 devem ser iguais!");
    }

    Matriz aux (lin1, col2);
    aux.zero();

    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col2; j++){
            for(int k = 0; k < col1; k++){
                aux.matrix[i][j] += matrix[i][k] * matriz.matrix[k][j];
            }
        }
    }

    return aux;
}



int Matriz::getLinha(){ //método para acessar a quantidade de linhas da matriz
    return linha;
}

int Matriz::getColuna(){ //método para acessar a quantidade de colunas da matriz
    return coluna;
}

#endif

