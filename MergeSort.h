void merge(int *A, int p, int q, int u) {
	int n1, n2;
	n1 = q - p ;
	n2 = u - q - 1 ;
		
	int i, j;
	int l[n1+2];
	int r[n2+2];
	
	for(i = 0; i <= n1; i++){
		l[i] = A[p + i];
	}

	for(j = 0; j<= n2; j++){
		
		r[j] = A[q + 1 + j];
	}

	l[n1+1] = 200001;
	r[n2+1] = 200001;
	
	i = 0;
	j = 0;
	int k;
	
    for(k = p; k <= u; k++){
    	
		if(l[i]<r[j]){
			A[k] = l[i];
			i = i + 1;	
		} else {	
			A[k] = r[j];
			j = j + 1;
		}
		comparacoes++;
	}
}

void mergeSort(int *A, int p, int u){
	int q;
	if (p < u ) {
		q = ( p + u )/2 ;
		mergeSort(A, p, q);
		mergeSort(A, q+1, u);
		merge(A,p,q,u);
	}
}