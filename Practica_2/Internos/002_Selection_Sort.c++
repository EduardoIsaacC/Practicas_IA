void seleccion(int a[], int n){
    int i, j, min, aux;
   for ( i = 0; i< n - 1; i++){
    min = i;
        for (j= i + 1; j<n; j++){
            if (a[j] > a[j+1]){
                aux=a[j];
                a[j]= a[j+1];
                a[j+1] = aux;
            }
        }
    }