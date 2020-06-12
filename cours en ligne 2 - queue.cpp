#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
	char* data;
	struct elem *next;
}element;

typedef struct{
	element *first;
	element *last;
}queue;

element* createlement(char* data){
	element *elem;
	elem=(element*)malloc(sizeof(element));
	elem->data=data;
	elem->next=NULL;
	return elem;
}
queue* creatqueue(){
	queue *L;
	L=(queue*)malloc(sizeof(queue));
	L->first=NULL;
	L->last=NULL;	
	return L;
}
char* getfirst(queue *qu){
	if(qu->first==NULL){
		printf("Eroor");
		return NULL;
	}
	return qu->first->data;
}


void addData(char* data,queue *L){
	//c'est pas de chercher si L et nul ms L first et null ; 
	//si on souhait tester si L et null et modifier l'adresse de L alors on met **L
	element *newelem;
	newelem=createlement(data);
	if (L->first==NULL){
		L->first=newelem;
		L->last=newelem;
		return;
	}
	/*la liste contient des element*/
	/*a la difference des L sc avec un seul pointeur 
	on chercher la derniere position 
	la fin de la liste et memorisé dans last 
	on change e en newelem ... ce newelem et le suivant du dernier element de la liste*/	
	L->last->next=newelem;
	L->last=newelem;
}

void displayqueue(queue *L){
	element *crt;
	crt=L->first;
	while(crt){	
		printf("%p- %s- %p\n",crt,crt->data, crt->next);
		crt=crt->next;
	}
}
void enqueue(queue *qu,char* data){
	element *elem;
	elem=createlement(data);
	if(qu->first==NULL){
		qu->first=elem;
		qu->last=elem;
		return;
	}
	qu->last->next=elem;
	qu->last=elem;
}

void dequeue(queue *qu){
	if(qu==NULL) return;
	if(qu->first==NULL) return;
	element *temp;
	temp=qu->first;
	qu->first=qu->first->next;
	if(qu->first==NULL){
		qu->last=NULL;
	}
	free(temp);
}
int main(){
	queue *qu;
	qu=creatqueue();
	enqueue(qu,"ghj");
	enqueue(qu,"gn");
	enqueue(qu,"kutyjt");
	enqueue(qu,"gh");
	displayqueue(qu);
	printf("%s\n",getfirst(qu)); dequeue(qu); 
	printf("%s\n",getfirst(qu)); dequeue(qu); 
	printf("%s\n",getfirst(qu)); dequeue(qu); 
	printf("%s\n",getfirst(qu)); dequeue(qu); 
	return 0;
}
