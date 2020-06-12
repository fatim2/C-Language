#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
	char *nom;
}machine;

typedef struct{
	char *nom_fichier;
	char *text;
	int taille;
	char *date;
	machine *pc;
}document;

typedef struct elem{
	document *data;
	struct elem *next;
}element;

typedef struct{
	element *first;
	element *last;
	int size;
}queue;

element* createlement(document *doc){
	element *elem;
	elem=(element*)malloc(sizeof(element));
	elem->data=doc;
	elem->next=NULL;
	return elem;
}
machine* creatmachine(char* nom){
	machine *pc;
	pc=(machine*)malloc(sizeof(machine));
	pc->nom=nom;
	return pc;
}

document* creatdoc(){
	char nom_fichier[10];
	char text[30];
	int taille;
	document *doc;
	time_t t=time(NULL);
	struct tm tm = *localtime(&t);
	char *date;
	date=(char*)malloc(22);
	sprintf(date,"%d-%02d-%02d %02d:%02d\n",tm.tm_year+1900,tm.tm_mon,tm.tm_mday,tm.tm_hour,tm.tm_min);
	doc=(document*)malloc(sizeof(document));
	printf("creer votre document:\n");
	printf("nom: \n");
	gets(nom_fichier);
	printf("text: \n");
	gets(text); 
	printf("taille: \n");
	scanf("%d",&taille);
	doc->nom_fichier=nom_fichier;
	doc->taille=taille;
	doc->text=text;
	doc->date=date;
	return doc;
}
queue* creatqueue(){
	queue *qu;
	qu=(queue*)malloc(sizeof(queue));
	qu->first=NULL;
	qu->last=NULL;
	qu->size=0;	
	return qu;
}

void enqueue(queue *qu,document *doc){
	element *elem;
	elem=createlement(doc);
	qu->size++;
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

void displayqueue(queue *qu){
	element *crt;
	crt=qu->first;
	while(crt){	
		printf("\n %s",crt->data->nom_fichier);
		printf("\n %s",crt->data->text);
		printf("\n %d",crt->data->taille);
		crt=crt->next;
	}
}

void displaydoc(document *doc){
	printf("\n size: %d Ko",doc->taille);
	printf("\n date:%s",doc->date);
	printf("\n nom:%s",doc->nom_fichier);
	printf("\n text:%s",doc->text);
}

document* getfirst(queue *qu){
	if(qu->first==NULL){
		printf("Error");
		return NULL;
	}
	return qu->first->data;
}





int main(){
	machine *pc;
	queue *qu;
	element *elem;
	qu=creatqueue();
	document *doc;
	doc=creatdoc();
	displaydoc(doc);
	enqueue(qu,doc);
	displayqueue(qu);
	
}
