#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <pthread.h>

using namespace std;

int baseParaMultiplicar;
int tamanoArchivo;
pthread_t *hebras;
char* nombreArchivo = new(char[30]);

void* function(void* dato){
	int indice = *((int*)dato);
	int dondeComenzar = indice * baseParaMultiplicar;
	int	tope = (indice+1)*baseParaMultiplicar;
	FILE* hFile = fopen(nombreArchivo,"r");
	fseek(hFile, dondeComenzar, SEEK_SET);
	int contador = 0;
	char actual;
	while(actual!=EOF){
		actual=fgetc(hFile);
		contador++;
		if((contador==tope) || (contador == tamanoArchivo))
			break;
	}
	printf("Soy la hebra: %d.\nHe leido: %d de %d bytes.Comence a leer desde el byte: %d\n",indice,contador,tamanoArchivo,dondeComenzar);
}




int main(int argc, char* argv[]){

	int cantidadHebras;
	sscanf(argv[1],"%d",&cantidadHebras);

	hebras = (pthread_t*)malloc(cantidadHebras*(sizeof(pthread_t)));
	strcpy(nombreArchivo,argv[2]);
	FILE* pFile = fopen(argv[2],"r");
	fseek(pFile,0,SEEK_END);
	tamanoArchivo = ftell(pFile);
	baseParaMultiplicar = tamanoArchivo/cantidadHebras;
	int indice[cantidadHebras];
	for(int i = 0; i < cantidadHebras; i++){
		indice[i] = i;
	}
	for(int i = 0; i < cantidadHebras; i++){
		pthread_create(&hebras[i],NULL,&function,(void*)&indice[i]);
	}
	for(int i = 0; i < cantidadHebras; i++){
		pthread_join(hebras[i],NULL);
	}
}


