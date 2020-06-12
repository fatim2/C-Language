#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char *titre;
	char *content;
	char *adress;
}page;

typedef struct elem{
	page *p;
	struct elem *next;
	struct elem *previous;
}element;

typedef struct{
	element *first;
	element *last;
	int size;
}list;

typedef struct{
	element *courant;
	list *DL;
}cache;
/*---------------------------------------------creat list*/
list* creatlist(){
	list *L;
	L=(list*)malloc(sizeof(list));
	L->first=NULL;
	L->last=NULL;
	L->size=0;	
	return L;
}
/*---------------------------------------------creat element*/

element* createlement(page *p){
	element *elem;
	elem=(element*)malloc(sizeof(element));
	elem->p=p;
	elem->next=NULL;
	elem->previous=NULL;
	return elem;
}
/*---------------------------------------------creat page*/

page* creatpage(char *adress,char* titre, char* content){
	page *p;
	p=(page*)malloc(sizeof(page));
	p->adress=adress;
	p->content=content;
	p->titre=titre;
	return p;
}
/*---------------------------------------------cache memory*/
cache* creatcache(){
	cache *mem;
	mem=(cache*)malloc(sizeof(cache));
	mem->courant=NULL;
	mem->DL=creatlist();
	return mem;
} 
/*---------------------------------------------get page*/
page *getpage(char* adress,page* tab[],int N){
	for (int i=0;i<N;i++){
		if (tab[i]==NULL){
			printf("ERROR 404\n");
			return NULL;
		}
		if(strcmp(tab[i]->adress,adress)==0) return tab[i];
	}
	return NULL;
}
/*---------------------------------------------add page*/
void addpage(page *p,cache *ch){
	element *elem;
	elem=createlement(p);
	ch->courant=elem;
	if(ch->DL->first==NULL){
		ch->DL->first=elem;
		ch->DL->last=elem;
		ch->DL->size++;
		return;
	}
	ch->DL->last->next=elem;
	elem->previous=ch->DL->last;
	ch->DL->last=elem;
	ch->DL->size++;
}
/*---------------------------------------------display pages*/

void displayPage(page *p){
	if (p==NULL){
		printf("ERROR\n");
		return;
	}
	printf("\n---------------%s--------------------",p->titre);
	printf("\n%s\n-------------- ---------------------",p->content);
}

/*-------------------------------------------------------------DISPLAY FROM FIRST*/
void displayFromFirst(list *L){
element *crt;
crt=L->first;
while(crt){
    printf("%d - ",crt->p->titre);
    crt=crt->next;
}
}

/*-------------------------------------------------------------DISPLAY FROM LAST*/
void displayFromLast(list *L){
element *crt;
crt=L->last;
while(crt){
    printf("%d - ",crt->p->titre);
    crt=crt->previous;
}
}

/*---------------------------------------------go to next page*/
void gotonext(cache *ch){
	if(ch->DL->first!=NULL && ch->courant->next!=NULL){
		ch->courant=ch->courant->next;
		displayPage(ch->courant->p);
	}
}

/*---------------------------------------------go to previous page*/
void gotoprevious(cache *ch){
	if(ch->DL->first!=NULL && ch->courant->previous!=NULL ){
		ch->courant=ch->courant->previous;
		displayPage(ch->courant->p);
	}
}

/*---------------------------------------------innit tableau pages*/

void inittabl(page *tab[], int N){
	for(int i=0;i<N;i++){
		tab[i]=NULL;
	}
	/*pour simplifier*/
	tab[0]=creatpage("www.enset-media.ac.ma","home","news");
	tab[1]=creatpage("nous","qui somme nous","text");
	tab[2]=creatpage("fi","formation initial","filiere");
	tab[3]=creatpage("fc","formation continue","dev web mobile et bdcc");
	tab[4]=creatpage("rd","recherche","recherche et environnement");
}










