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

typedef struct {
	unsigned long long somaComparacoes;
	double somaTempos;
} CamposSomaMedias;


// 1. Bublesort;
// 2. Insertionsort;
// 3. Mergesort;
// 4. Heapsort;
// 5. Quicksort.

void gravarInfoDaExecucao(int tam, int tipo)
{
	FILE *arq;

	arq = fopen("resultados.txt", "a"); 
	if (arq == NULL)  
	{
		printf("Problema ao criar o arquivo .txt\n");
		return;
	}

	switch (tipo)
	{
	case 1:
		fprintf(arq, "\nCRESCENTE -");
		break;
	case 2:
		fprintf(arq, "\nDECRESCENTE -");
		break;
	case 3:
		fprintf(arq, "\nALEATORIO -");
		break;
	}

	switch (tam)
	{
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

void gravarMedia(CamposSomaMedias parametrosSomaMedias[10]) {
	FILE *arq;

	arq = fopen("resultados.txt", "a");  
	if (arq == NULL) {
		printf("Problema ao criar o arquivo .txt\n");
		return;
	}

	fprintf(arq, "\nMedia Execucoes:\n");
	fprintf(arq, "\tBubble-COMPARACOES: %I64u -- TEMPO: %lf\n",  parametrosSomaMedias[0].somaComparacoes / 3, parametrosSomaMedias[0].somaTempos / 3.0);
	fprintf(arq, "\tInsertion-COMPARACOES: %I64u -- TEMPO: %lf\n",  parametrosSomaMedias[1].somaComparacoes / 3, parametrosSomaMedias[1].somaTempos / 3.0);
	fprintf(arq, "\tMerge-COMPARACOES: %I64u -- TEMPO: %lf\n",  parametrosSomaMedias[2].somaComparacoes / 3, parametrosSomaMedias[2].somaTempos / 3.0);
	fprintf(arq, "\tHeap-COMPARACOES: %I64u -- TEMPO: %lf\n",  parametrosSomaMedias[3].somaComparacoes / 3, parametrosSomaMedias[3].somaTempos / 3.0);
	fprintf(arq, "\tQuick-COMPARACOES: %I64u -- TEMPO: %lf\n",  parametrosSomaMedias[4].somaComparacoes / 3, parametrosSomaMedias[4].somaTempos / 3.0);

	
	fclose(arq);
}

void gravarDados(clock_t t , unsigned long long comparacoes, char string[13])
{
	FILE *arq2;

	arq2 = fopen("resultados.txt", "a");  
	if (arq2 == NULL)  
	{
		printf("Problema ao criar o arquivo .txt\n");
		return;
	}
	double tempo = ((double)t) / ((CLOCKS_PER_SEC / 1000));
	if(tempo < 0)tempo *= -1;
	fprintf(arq2, "\t%s-COMPARACOES: %I64u -- TEMPO: %lf\n", string, comparacoes, tempo);
	fclose(arq2);
}

void numeroDaExec(int exec) {
	FILE *arq;

	arq = fopen("resultados.txt", "a");  
	if (arq == NULL) {
		printf("Problema ao criar o arquivo .txt\n");
		return;
	}

	switch (exec) {
		case 1:
			fprintf(arq, "\nExecucao 1:\n");
			break;
		case 2:
			fprintf(arq, "\nExecucao 2:\n");
			break;
		case 3:
			fprintf(arq, "\nExecucao 3:\n");
			break;
		}

		fclose(arq);
	}

void gerarVetor(int *vetor, int tam, int tipo) {
	int i;
	
	//vetor crescente
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
	for(i=0; i<tam; i++){
		vetor[i] = vetorAleatorio[i];
	}
}

void ordenacao(int tam) {
	clock_t t;
	int i;
	int vetor[tam];
	int vetorAleatorio[tam];

	// Soma relacionado a media de cada algoritmo
	CamposSomaMedias bubblesortParametrosMedia = { .somaComparacoes = 0, .somaTempos = 0.0 };
	CamposSomaMedias insertionParametrosMedia = { .somaComparacoes = 0, .somaTempos = 0.0 };
	CamposSomaMedias mergeParametrosMedia = { .somaComparacoes = 0, .somaTempos = 0.0 };
	CamposSomaMedias heapParametrosMedia = { .somaComparacoes = 0, .somaTempos = 0.0 };
	CamposSomaMedias quickParametrosMedia = { .somaComparacoes = 0, .somaTempos = 0.0 };

	
	//gerando vetor aleatorio para ser unico a todos
	for (i = 0; i < tam; i++) {
		vetorAleatorio[i] = rand() % 100;
	}
	
	//vetor crescente
	gravarInfoDaExecucao(tam, 1);
	
	for(i = 1; i <= 3; i++) {
		numeroDaExec(i);
		
		gerarVetor(vetor, tam, 1);//gera o vetor usado
		comparacoes = 0;//zera a quantidade de comparacoes
		t = clock();//captura o tempo inicial
		bubblesort(vetor,tam);
		t = clock() - t;// tempo de execucao
		gravarDados(t, comparacoes, "Bubble");
		bubblesortParametrosMedia.somaComparacoes += comparacoes;
		bubblesortParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		gerarVetor(vetor, tam, 1);
		comparacoes = 0;
		t = clock();
		insertionSort(vetor, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Insertion");
		insertionParametrosMedia.somaComparacoes += comparacoes;
		insertionParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		gerarVetor(vetor, tam, 1);
		comparacoes = 0;
		t = clock();
		mergeSort(vetor,0,tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Merge");
		mergeParametrosMedia.somaComparacoes += comparacoes;
		mergeParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 

		gerarVetor(vetor, tam, 1);
		comparacoes = 0;
		t = clock();
		construirHeap(vetor, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Heap");
		heapParametrosMedia.somaComparacoes += comparacoes;
		heapParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 

		gerarVetor(vetor, tam, 1);
		comparacoes = 0;
		t = clock();
		quickSort(vetor, 0, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Quick");
		quickParametrosMedia.somaComparacoes += comparacoes;
		quickParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
	}

	//gravar media e resetar os parametros
	CamposSomaMedias parametroGravarMediaCrescente[10] = {bubblesortParametrosMedia, insertionParametrosMedia, mergeParametrosMedia, heapParametrosMedia, quickParametrosMedia};
	gravarMedia(parametroGravarMediaCrescente);
	bubblesortParametrosMedia.somaComparacoes = 0; bubblesortParametrosMedia.somaTempos = 0.0;
	insertionParametrosMedia.somaComparacoes = 0, insertionParametrosMedia.somaTempos = 0.0;
	mergeParametrosMedia.somaComparacoes = 0, mergeParametrosMedia.somaTempos = 0.0;
	heapParametrosMedia.somaComparacoes = 0, heapParametrosMedia.somaTempos = 0.0;
	quickParametrosMedia.somaComparacoes = 0, quickParametrosMedia.somaTempos = 0.0;

	//vetor decrescente
	gravarInfoDaExecucao(tam, 2);
	for(i = 1; i <= 3; i++) {
		numeroDaExec(i);
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		bubblesort(vetor,tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Bubble");
		bubblesortParametrosMedia.somaComparacoes += comparacoes;
		bubblesortParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		insertionSort(vetor, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Insertion");
		insertionParametrosMedia.somaComparacoes += comparacoes;
		insertionParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		mergeSort(vetor,0,tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Merge");
		mergeParametrosMedia.somaComparacoes += comparacoes;
		mergeParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		construirHeap(vetor, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Heap");
		heapParametrosMedia.somaComparacoes += comparacoes;
		heapParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		gerarVetor(vetor, tam, 2);
		comparacoes = 0;
		t = clock();
		quickSort(vetor, 0, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Quick");
		quickParametrosMedia.somaComparacoes += comparacoes;
		quickParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
	}

	//gravar media e resetar os parametros
	CamposSomaMedias parametroGravarMediaDecrescente[10] = {bubblesortParametrosMedia, insertionParametrosMedia, mergeParametrosMedia, heapParametrosMedia, quickParametrosMedia};
	gravarMedia(parametroGravarMediaDecrescente);
	bubblesortParametrosMedia.somaComparacoes = 0; bubblesortParametrosMedia.somaTempos = 0.0;
	insertionParametrosMedia.somaComparacoes = 0, insertionParametrosMedia.somaTempos = 0.0;
	mergeParametrosMedia.somaComparacoes = 0, mergeParametrosMedia.somaTempos = 0.0;
	heapParametrosMedia.somaComparacoes = 0, heapParametrosMedia.somaTempos = 0.0;
	quickParametrosMedia.somaComparacoes = 0, quickParametrosMedia.somaTempos = 0.0;


	//vetor aleatorio
	gravarInfoDaExecucao(tam, 3);
	for(i = 1; i <= 3; i++) {
		numeroDaExec(i);
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		bubblesort(vetor,tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Bubble");
		bubblesortParametrosMedia.somaComparacoes += comparacoes;
		bubblesortParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		insertionSort(vetor, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Insertion");
		insertionParametrosMedia.somaComparacoes += comparacoes;
		insertionParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		mergeSort(vetor,0,tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Merge");
		mergeParametrosMedia.somaComparacoes += comparacoes;
		mergeParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		construirHeap(vetor, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Heap");
		heapParametrosMedia.somaComparacoes += comparacoes;
		heapParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
		
		pegarVetorAleatorio(vetor, vetorAleatorio,tam);
		comparacoes = 0;
		t = clock();
		quickSort(vetor, 0, tam);
		t = clock() - t;
		gravarDados(t, comparacoes, "Quick");
		quickParametrosMedia.somaComparacoes += comparacoes;
		quickParametrosMedia.somaTempos += ((double)t) / ((CLOCKS_PER_SEC / 1000)); 
	}

	CamposSomaMedias parametroGravarMediaVariavel[10] = {bubblesortParametrosMedia, insertionParametrosMedia, mergeParametrosMedia, heapParametrosMedia, quickParametrosMedia};
	gravarMedia(parametroGravarMediaVariavel);
}

int main() {
	ordenacao(100);
	ordenacao(500);

	return 0;
}
