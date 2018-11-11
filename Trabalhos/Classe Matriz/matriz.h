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
	bool operator==(Matriz &matriz);

        void zero();

        int *operator[] (int x);
        int getLinha() const;
        int getColuna() const;
	int getValor(int i, int j) const;

        ~Matriz();

    private:
        void allocate_function(int linha, int coluna, int ***matriz);
        void deallocate_function(int **matriz);

    protected:
        int **matrix;
        int linha, coluna;
};

#endif // Matriz_h

