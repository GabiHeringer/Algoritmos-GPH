#include <iostream>
#include <random>
#include <vector>
#include <math.h>

using namespace std;

void quick_sort (vector<int> &vet){
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


int* busca_ingenua (vector<int> &vet, int* inicio, int* fim, int elemento, int &count){
	
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


int* busca_binaria (vector<int> &vet, int inicio, int fim, int elemento, int &count){
	
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

int main() {

	random_device rd;  
    	mt19937 gen(rd()); 
		
	int count1 = 0, count2 = 0;
	
	for(int tamanho = 10; tamanho <= 100000; tamanho += 500){
		uniform_int_distribution<> dist(0, tamanho);
		vector <int> random;
		for(int n = 0; n < tamanho; n++){
			random.push_back(dist(gen));
		}
		quick_sort(random);
		busca_ingenua(random, &random[0], &random[random.size()], dist(gen), count1);
		busca_binaria(random, 0, random.size(), dist(gen), count2);
		cout << tamanho << " " << count1 << " " << count2 << endl;
		count1 = 0;
		count2 = 0;
	}
	
	return 0;
}

