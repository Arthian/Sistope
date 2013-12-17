#include <pthread.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;

void escritor();
void lector();

 
/*
	M numero de hebras
	N Tamaño inicial tabla
	H Threshold
*/
int M = 0, N = 0, H = 0;
/*Tabla Hash compuesta de un vector de listas.*/
vector<vector<char*>> tabla;
/*Semaforos*/


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


}

void lector(){


}