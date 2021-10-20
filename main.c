#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

unsigned long long comparacoes = 0;

#include "QuickSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "Bubblesort.h"

// 1. Bublesort;
// 2. Iinsertionsort
// 3. Mergesort;
// 4. Heapsort;
// 5. Quicksort.

void gravarInfoDaExecucao(int tam, int tipo) {
	FILE *arq;

	arq = fopen("resultados.txt", "a"); 

	if (arq == NULL) {
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}

	switch (tipo) {
	case 1:
		fprintf(arq, "CRESCENTE -");
		break;
	case 2:
		fprintf(arq, "DECRESCENTE -");
		break;
	case 3:
		fprintf(arq, "ALEATORIO -");
		break;
	}

	switch (tam) {
		case 100:
			fprintf(arq, " TAMANHO: 100\n");
			break;
		case 500:
			fprintf(arq, " TAMANHO: 500\n");
			break;
		case 1000:
			fprintf(arq, " TAMANHO: 1.000\n");
			break;
		case 5000:
			fprintf(arq, " TAMANHO: 5.000\n");
			break;
		case 30000:
			fprintf(arq, " TAMANHO: 30.000\n");
			break;
		case 80000:
			fprintf(arq, " TAMANHO: 80.000\n");
			break;
		case 100000:
			fprintf(arq, " TAMANHO: 100.000\n");
			break;
		case 150000:
			fprintf(arq, " TAMANHO: 150.000\n");
			break;
		case 200000:
			fprintf(arq, " TAMANHO: 200.000\n");
			break;
	}

	fclose(arq);
}

void gravarDados(clock_t t , char string[13])
{
	FILE *arq2;

	arq2 = fopen("resultados.txt", "a");  
	
	if (arq2 == NULL) {
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}

	double tempo = ((double)t) / ((CLOCKS_PER_SEC / 1000));
	if(tempo < 0)tempo *= -1;

	fprintf(arq2, "\t%s: TEMPO: %lf\n", string,  tempo);
	fclose(arq2);
}

void numeroDaExec(int exec) {
	FILE *arq;

	arq = fopen("resultados.txt", "a");  
	if (arq == NULL) {
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}

	switch (exec) {
	case 1:
		fprintf(arq, "   Execucao 1:\n");
		break;
	case 2:
		fprintf(arq, "   Execucao 2:\n");
		break;
	case 3:
		fprintf(arq, "   Execucao 3:\n");
		break;
	}

	fclose(arq);
}

void gerarVetor(int *vetor, int tam, int tipo) {
	int i;
	
	//crescente
	if(tipo == 1) {
		for(i = 0; i < tam; i++) {
			vetor[i] = i + 1;
		}
	} else if(tipo == 2) {
		//decrescente
		for(i = tam; i > 0; i--) {
			vetor[tam - i] = i;
		}
	}
}

void pegarVetorAleatorio(int *vetor, int *vetorAleatorio, int tam){
	int i;
	
	for(i=0; i < tam; i++) {
		vetor[i] = vetorAleatorio[i];
	}
}

void ordenacao(int tam) {
	clock_t t;
	int i;
	int vetor[tam];
	int vetorAleatorio[tam];
	
	//gerando vetor aleatorio para ser unico a todos
	for(i = 0; i < tam; i++) {
		vetorAleatorio[i] = rand() % 100;
	}
	
	//vetor crescente
	gravarInfoDaExecucao(tam, 1);
	
	for(i = 1; i <= 3; i++) {
		numeroDaExec(i);
		
		gerarVetor(vetor, tam, 1);//gera o vetor usado
		t = clock();//captura o tempo inicial
		bubblesort(vetor,tam);
		t = clock() - t;// tempo de execucao
		gravarDados(t, "Bubble");
		
		gerarVetor(vetor, tam, 1);//gera o vetor usado
		comparacoes = 0;
		t = clock();
		insertionSort(vetor, tam);
		t = clock() - t;
		gravarDados(t, "Insertion");
		
		gerarVetor(vetor, tam, 1);//gera o vetor usado
		comparacoes = 0;
		t = clock();
		mergeSort(vetor,0,tam);
		t = clock() - t;
		gravarDados(t, "Merge");
		
		gerarVetor(vetor, tam, 1);//gera o vetor usado
		comparacoes = 0;
		t = clock();
		construirHeap(vetor, tam);
		t = clock() - t;
		gravarDados(t, "Heap");
		
		gerarVetor(vetor, tam, 1);//gera o vetor usado
		comparacoes = 0;
		t = clock();
		quickSort(vetor, 0, tam);
		t = clock() - t;
		gravarDados(t, "Quick");
	}

	//vetor decrescente
	gravarInfoDaExecucao(tam, 2);
	for(i = 1; i <= 3; i++) {
		numeroDaExec(i);
		
		gerarVetor(vetor, tam, 2);//gera o vetor usado
		t = clock();//captura o tempo inicial
		bubblesort(vetor,tam);
		t = clock() - t;// tempo de execucao
		gravarDados(t, "Bubble");
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		insertionSort(vetor, tam);
		t = clock() - t;
		gravarDados(t, "Insertion");
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		mergeSort(vetor,0,tam);
		t = clock() - t;
		gravarDados(t, "Merge");
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		construirHeap(vetor, tam);
		t = clock() - t;
		gravarDados(t, "Heap");
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		quickSort(vetor, 0, tam);
		t = clock() - t;
		gravarDados(t, "Quick");
	}


	//vetor aleatorio
	gravarInfoDaExecucao(tam, 3);
	for(i = 1; i <= 3; i++) {
		numeroDaExec(i);
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);//gera o vetor usado
		t = clock();//captura o tempo inicial
		bubblesort(vetor,tam);
		t = clock() - t;// tempo de execucao
		gravarDados(t, "Bubble");
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		insertionSort(vetor, tam);
		t = clock() - t;
		gravarDados(t, "Insertion");
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		mergeSort(vetor,0,tam);
		t = clock() - t;
		gravarDados(t, "Merge");
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		construirHeap(vetor, tam);
		t = clock() - t;
		gravarDados(t, "Heap");
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		quickSort(vetor, 0, tam);
		t = clock() - t;
		gravarDados(t, "Quick");
	}
}

int main() {
	ordenacao(500);

	return 0;
}
