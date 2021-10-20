void insertionSort(int *v, int n) { 
	int i, indice, j;

    for (i = 1; i < n; i++) {
        indice = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > indice) {
            v[j + 1] = v[j];
            j = j - 1;
            comparacoes++;
        }
        comparacoes++;
        v[j + 1] = indice;
    }
}