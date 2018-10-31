#ifndef CircularList_h
#define CircularList_h

using namespace std;

class CircularList{ //Classe lista, contendo métodos para suas operações
	public:
		Node *position;	
		CircularList();
		~CircularList();		
		int GetPosition();
		int GetNext();
		int GetPrevious();
		int GetMiddle(int place);
		void AddAfterPosition(int value);
		void AddBeforePosition(int value);
		void AddInTheMiddle(int place, int value);
		void AddAfterNode();
		void PopPositionN();
		void PopPositionP();
		void PopElement(int place);
		void NextNode();
		void PreviousNode(); 
		bool IsEmpty();
		bool Value(int v);
};


CircularList::CircularList(){ //construtor que inicia a lista, com position nulo
	position = NULL;
}

CircularList::~CircularList(){ //destrói os nós até tornar a lista vazia
	while(!IsEmpty()){
		PopPositionN();
	}
}

bool CircularList::IsEmpty(){ //método para verificar se a lista está vazia
	if (position == NULL){
		return true;
	}else{
		return false;
	}
}

void CircularList::AddAfterPosition (int value){ //Adiciona um nó depois de position
	
	if (IsEmpty()){
		position = new Node(value);
		position->next = position;
		position->previous = position;	
	}else{
		Node *aux = new Node(value, position, position->next);
		position->next->previous = aux;
		position->next = aux;
	}
}

void CircularList::AddBeforePosition (int value){ //Adiciona um nó antes de position
	
	if (IsEmpty()){
		position = new Node(value);
		position->next = position;		
		position->previous = position;	
	}else{
		Node *aux = new Node(value, position->previous, position);
		position->previous->next = aux;
		position->previous = aux;
	}
}

void CircularList::AddInTheMiddle (int place, int value){ //Adiciona um nó após uma certa posição que NÃO seja a primeira (nó para qual position aponta é a posição 0)
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia, use as funcoes para adicionar position!");
	}	
	
	Node *aux = new Node(value);
	Node *aux2 = position;
		
	for(int i = 0; i < place; i++){
		aux2 = aux2->next;
	}
		
	aux->next = aux2->next;
	aux->previous = aux2;
	aux2->next->previous = aux;
	aux2->next = aux;

}

int CircularList::GetPosition(){ //Retorna a informação do nó para qual position aponta
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia, impossivel pegar position");
	}
	
	return position->info;
}

int CircularList::GetNext(){ //Retorna a informação do nó após ao que position aponta
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia, impossivel pegar position->next");
	}
	
	return position->next->info;
}

int CircularList::GetPrevious(){ //Retorna a informação do nó antes ao que position aponta
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia, impossivel pegar position->previous");
	}
	
	return position->previous->info;
}

int CircularList::GetMiddle(int place){ //Retorna a informação de um nó em uma certa posição
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia!");
	}
	
	Node *aux = position;
	for(int i = 0; i < place; i++){
		aux = aux->next;
	}
	return aux->info;
}

void CircularList::PopPositionN(){ //Apaga o nó para qual position aponta e faz apontar para o próximo
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia!");
	}	
	
	if (position == position->next){
		position = NULL;
	}else{
	
		Node *aux;
		aux = position;
		position->previous->next = position->next;
		position->next->previous = position->previous;
		position = position->next;
	
		delete aux;
	}
}

void CircularList::PopPositionP(){ //Apaga o nó para qual position aponta e faz apontar para o anterior
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia!");
	}	
	
	if (position == position->next){
		position = NULL;
	}else{
	
		Node *aux;
		aux = position;
		position->previous->next = position->next;
		position->next->previous = position->previous;
		position = position->previous;
		
		delete aux;
	}
}

void CircularList::PopElement(int place){ //Apaga um nó em uma certa posição
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia!");
	}	

	Node *aux = position;
	for(int i = 0; i < place; i++){
		aux = aux->next;
	}

	aux->previous->next = aux->next;
	aux->next->previous = aux->previous;

	delete aux;
}

void CircularList::NextNode(){ //Faz position apontar para o próximo nó
	
	if (IsEmpty()){
		throw invalid_argument("Lista vazia!");
	}

	Node *aux;
	aux = position;
	position->next->previous = aux;
	position->previous->next = aux;
	position = position->next;
}

void CircularList::PreviousNode(){ //Faz position apontar para o nó anterior

	if (IsEmpty()){
		throw invalid_argument("Lista vazia!");
	}	

	Node *aux;
	aux = position;
	position->next->previous = aux;
	position->previous->next = aux;
	position = position->previous;
}

bool CircularList::Value(int v){ //Retorna se um certo valor está na lista
	
	Node *aux = position;
	
	if (aux->info == v){
		return true;
	}else{			
		aux = aux->next;
		while(aux != position){
			if (aux->info == v){
				return true;
			}
			aux = aux->next;
		}
   	}
	return false;
}	
	


#endif //CircularList_h
