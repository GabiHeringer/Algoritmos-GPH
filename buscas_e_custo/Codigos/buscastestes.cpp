#include <iostream>
#include <random>
#include <vector>
#include <gtest/gtest.h>
#include <math.h>

using namespace std;

void quick_sort (vector<int> &vet){ //função que ordena os vetores
	int aux;
		
	for (int i = 0; i < vet.size(); i++){
		for (int j = (i + 1); j < vet.size(); j++){
			if (vet[i] > vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
}


int* busca_ingenua (vector<int> &vet, int* inicio, int* fim, int elemento, int &count){ //busca de comparação 1 a 1
	
	int *position(NULL);
	int i;

	while (inicio <= fim && position == NULL){
		if (*inicio == elemento){
			position = inicio;
			count++;
		}
		inicio++;
		count++;
	}

	return position;
}


int* busca_binaria (vector<int> &vet, int inicio, int fim, int elemento, int &count){ //busca que diminui entrada de dados
	
	int *position(NULL);
	int i, half;
	half = floor((inicio + ((fim - inicio)/2)));
	

	while (half != fim && position == NULL){
		if (vet[half] == elemento){
			position = &vet[half];
			count++;
		}else if (vet[half] < elemento){
			count++;
			if (half == inicio){
				if (vet[fim] == elemento){
					position = &vet[fim];
					count++;
				}else{
					half = fim;
					count++;
				}
			}			
			inicio = half;
		}else if(vet[half] > elemento){
			fim = half;
			count++;
		}
		half = floor((inicio + ((fim - inicio)/2)));
	}

	return position;
}

//testes para as buscas e ordenação

TEST(Ordenacao, quick_sort){
	vector<int> vet({4,8,5,1,3,20,11});
	quick_sort(vet);
	
	for(int i = 0; i < 5; i++){
		EXPECT_TRUE(vet[i] < vet[(i+1)]);
	}
}

TEST(Buscas, busca_ingenua_found){
	vector<int> vet({1,2,3,4,5,6,7});
	int *has_element(NULL), *inicio, *fim, count = 0;
	inicio = &vet[0];
	fim = &vet[vet.size() - 1];

	has_element = busca_ingenua(vet, inicio, fim, 7, count);
	EXPECT_TRUE(has_element != NULL);
}


TEST(Buscas, busca_ingenua_notfound){
	vector<int> vet({1,2,3,4,5,6,7});
	int *has_element, *inicio, *fim, count = 0;
	inicio = &vet[0];
	fim = &vet[vet.size() - 1];

	has_element = busca_ingenua(vet, inicio, fim, 10, count);
	EXPECT_TRUE(has_element == NULL);
	
}

TEST(Buscas, busca_ingenua_position){
	vector<int> vet({1,2,3,4,5,6,7});
	int *has_element, *inicio, *fim, count = 0;
	inicio = &vet[0];
	fim = &vet[vet.size() - 1];

	has_element = busca_ingenua(vet, inicio, fim, 7, count);
	EXPECT_TRUE(*has_element == 7);

}	


TEST(Buscas, busca_binaria_found_extreme1){
	vector<int> vet({1,2,3,4,5,6,7});
	int *has_element, inicio, fim, count = 0;
	inicio = 0;
	fim = 6;

	has_element = busca_binaria(vet, inicio, fim, 7, count);
	EXPECT_TRUE(*has_element == 7);
}

TEST(Buscas, busca_binaria_found_extreme2){
	vector<int> vet({1,2,3,4,5,6,8});
	int *has_element, inicio, fim, count = 0;
	inicio = 0;
	fim = 6;
	
	has_element = busca_binaria(vet, inicio, fim, 1, count);
	EXPECT_TRUE(has_element == &vet[inicio]);
}


TEST(Buscas, busca_binaria_found){
	vector<int> vet({1,2,3,4,5,6,7});
	int *has_element, inicio, fim, count = 0;
	inicio = 0;
	fim = 6;

	has_element = busca_binaria(vet, inicio, fim, 5, count);
	EXPECT_TRUE(*has_element == 5);
}

TEST(Buscas, busca_binaria_notfound){
	vector<int> vet({1,2,3,4,5,6,7});
	int *has_element, inicio, fim, count = 0;
	inicio = 0;
	fim = 6;

	has_element = busca_binaria(vet, inicio, fim, 15, count);
	EXPECT_TRUE(has_element == NULL);
}

int main(int argc, char **argv) {
				
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
