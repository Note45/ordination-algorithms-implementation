void bubblesort(int* vetor, int TAM){
	
	int i,j,aux;
	
	for(i = 1; i < TAM; i++) {
		
		for(j = 0; j < TAM - 1; j++){
			
			if(vetor[j] > vetor[j + 1]){
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j+1] = aux;
				
			}
			comparacoes++;
		}
	}
}