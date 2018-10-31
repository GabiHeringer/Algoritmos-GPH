#ifndef Node_h
#define Node_h


class Node{ //Classe para os nós da lista, contendo seus atributos.
	public:
		Node *previous;
		Node *next;
		int info;

		Node (int information, Node *p = NULL, Node *n = NULL);
};

Node::Node (int information, Node *p, Node *n){ //Construtor 
	info = information;
	previous = p;
	next = n;
}
 

#endif //Node_h
