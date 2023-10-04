#include <iostream>

struct No {
	int data;
	No *next;
};

void printList(No*& head) { 
    No* p = head;
    printf("\n[");

    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("]");
}
void inserirNoInicio(No *&head, int value) {
    No* novoNo = new No;
 
    novoNo -> data = value;
    novoNo -> next = head;
    
    head = novoNo;
}

No* reverterLista(No* head) {
    No* anterior = NULL;
    No* atual = head;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        atual -> next = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

using namespace std;
int main(int argc, char** argv) {
	
	 No* head = NULL; 
    
    inserirNoInicio(head, 2);
    inserirNoInicio(head, 6);
    inserirNoInicio(head, 8);
    inserirNoInicio(head, 4);

    cout << "Lista original:" << endl;
    printList(head);
    
    cout << endl;
    
    head = reverterLista(head);

    cout << "\nLista revertida:" << endl;
    printList(head);
    
    cout << endl;


	system("pause");
	return 0;
}
