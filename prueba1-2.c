#include <stdlib.h>
#include <stdio.h>

#define long_max 200 //cantidad máxima de elementos en la lista

struct lista { 
	int arreglo[long_max]; //arreglo de elementos dentro de la lista
	int ultimo; //indicador de la primera posición vacía
};

struct lista *constructor(){ //función para crear una lista
	struct lista * L=malloc(sizeof(struct lista)); 
	L->ultimo=0; 
	return L; 
}

void destructor(struct lista * L){ //función para destruir una lista
	free(L);
}

struct lista *insertar(int x, int p, struct lista *L){
	int i;
	if(L->ultimo==long_max){
		printf("Lista llena\n");
	}else{
		if((p<0)||(p>L->ultimo)){
			printf("posición inválida\n");
		}else{
			for(i=0;i<L->ultimo-p;i++){
				L->arreglo[L->ultimo-i]=L->arreglo[L->ultimo-i-1];
			}
			L->arreglo[p]=x;
			L->ultimo++;
		}
	}
	return L;
}
void mostrar(struct lista *L){
	int i;
	for(i=0;i<L->ultimo;i++)
		printf("%i - ", L->arreglo[i]);
	printf("\n");
}
struct lista *eliminar(int p,struct lista *L){
	int i;
	if(L->ultimo==0){//lista no tiene elemento
		printf("Lista vacia, no es posible eliminar!");
	}else{
		if((p<0)||(p>=L->ultimo)){
			printf("Posicion invalida, no es posible eliminar!");
		}else{
			for(i=p;i<L->ultimo-1;i++){
				L->arreglo[i]=L->arreglo[i+1];
			}
			L->ultimo--;
		}
	}
	return L;
}
int localizar(int x, struct lista *L){
	int i;
	for(i=0;i<L->ultimo;i++){
		if(x==L->arreglo[i]){
			printf("La posicion del elemento %i es : %i \n",x,i);
			return i;
		}
	}
	printf("El valor no se encuentra!");
	return -1;
}

int recuperar(int p, struct lista *L){
	if((p<0)||(p>=L->ultimo)){
		printf("La posicion no es valida!\n");
		return -1;
	}else{
		printf("El elmento de la posicion %i es : %i \n",p,L->arreglo[p]);
		return L->arreglo[p];
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	struct lista *L; //declaramos la lista
	L = constructor(); //creamos la lista, asignar memoria (instanciar)
	//L=eliminar(0,L);
	L=insertar(10,0,L);
	L=insertar(20,1,L);
	L=insertar(30,2,L);
	L=insertar(40,3,L);
	mostrar(L);
	L=eliminar(2,L);
	mostrar(L);
	localizar(30,L);
	recuperar(-1,L);
	//printf("%i\n",Lista1->arreglo[10]);
	//printf("%i\n",Lista1->arreglo[20]);	
	destructor(L); // liberamos memoria

	return 0;
}