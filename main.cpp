#include <pthread.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <unistd.h>

using namespace std;

void escritor();
void lector();
void leerArchivo(FILE *pFile);

 
/*
	M numero de hebras
	N Tamaño inicial tabla
	H Threshold
*/
int M = 0, N = 0, H = 0;
int cuantosLectores = 0;
/*Tabla Hash compuesta de un vector de listas.*/
vector<vector<char*> > tabla;
/*Semaforos*/
pthread_mutex_t acceso = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t duerme = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t esperaALectores;
pthread_condattr_t attr;
int ax00 = pthread_condattr_init(&attr);
int bx00 = pthread_cond_init(&esperaALectores,&attr);

int main(int argc, char* argv[]){
	if(argc < 5){
		cout << "Faltan argumentos para la ejecución" << endl;
		cout << "Se requiere: Numero_de_Hebras(M) Tamaño_Inicial_Tabla(N) Threshold(H) ArchivoSalida" << endl;
		exit(-1);
	}
	sscanf(argv[1],"%d",&M);
	sscanf(argv[2],"%d",&N);
	sscanf(argv[3],"%d",&H);

	for(int i = 0; i < N; i++){
		vector<char*> nueva;
		tabla.push_back(nueva);
	}
		
}

void ModificarTabla(){

}

void escritor(){
	escribir:
	if(pthread_mutex_trylock(&acceso)){
		if(cuantosLectores!=0){
			pthread_cond_wait(&esperaALectores,&duerme);
		}
		//char* palabra = new(char[40]); palabra = getWord();
		//Insertar en tabla donde corresponda.
		pthread_mutex_unlock(&acceso);
	}
	else{
		sleep(100);
		goto escribir;
	}

}

void lector(){
	leer:
	if(pthread_mutex_trylock(&acceso)){
		cuantosLectores++;
		pthread_mutex_unlock(&acceso); //No es necesario que bloquee al leer
		//Leer();
		cuantosLectores--;
		if(cuantosLectores==0){
			pthread_cond_signal(&esperaALectores);
		}
;	}
	else{
		sleep(100); //que duerma unos milisegundos
		goto leer;
	}

}

/*
Tengo la idea de implementar lector-escritor con solo 1 mutex, 1 variable de condicion y un contador
*/
void leerArchivo(FILE *pFile){

}