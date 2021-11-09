int insertionSortHibrido(int *v, int n){
	int i, indice, j;
    
    for (i = 1; i < n; i++) {
        indice = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > indice) {
            return 0;
        }
        comparacoes++;
        v[j + 1] = indice;
    }

    return 1;
}

void hibrido(int *A, int p, int u){
	//Se verdadeiro o vetor e crescente, se falso outro caso e fazer com Merge Sort
	if(insertionSortHibrido(A,u) == 1) return;
	
    comparacoes = 0;
	
    mergeSort(A,p,u);
}