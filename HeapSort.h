void rearranjar(int A[], int i, int tam) {
	int esq = i * 2 + 1;
	int dir = i * 2 + 2;
	int maior = i;
	int aux;

	if (esq < tam && A[esq] > A[maior]){
		maior = esq;
		
	}
	   
	if (dir < tam && A[dir] > A[maior]) {
		maior = dir;
		
	}

	if (maior != i ){
		aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;   
		rearranjar(A,maior, tam);
	}
}

void construirHeap (int *valores, int tam) {
	int i;
	
	int aux;
	
	while(tam > 0){
		for ( i = (tam -1)/2; i >= 0; i= i-1) {
	  		rearranjar(valores, i, tam);
		}
		
		aux = valores[tam-1];
		valores[tam-1] = valores[0];
		valores[0] = aux;	
		tam--;
	}

}