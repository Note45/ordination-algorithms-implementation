void bubblesort(int* vetor, int tam) {
	int i,j,aux;
	
	for(i = 1; i < tam; i++) {	
		for(j = 0; j < tam - 1; j++){
			if(vetor[j] > vetor[j + 1]){
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j+1] = aux;
			}
		}
	}
}