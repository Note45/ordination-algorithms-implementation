int separa (int *v, int primeiro, int ultimo) {
	int pivo = v[ultimo];
	int aux, k, j = primeiro;

	for (k = primeiro; k < ultimo; k++) {
		if (v[k] <= pivo) {
			aux = v[j];
			v[j] = v[k];
			v[k] = aux;
			j++;
		}
		comparacoes++;
	}

	aux = v[j];
	v[j] = v[ultimo];
	v[ultimo] = aux;

	return j;
}

void quickSort(int *v , int primeiro, int ultimo) {
	while(primeiro < ultimo){
		int q = separa(v ,primeiro,ultimo);
		
		if(q - primeiro < ultimo - q) {
			quickSort(v,primeiro, q - 1);
			primeiro = q + 1;
		}else {
			quickSort(v,q + 1, ultimo);
			ultimo = q - 1;
		}
	}
}