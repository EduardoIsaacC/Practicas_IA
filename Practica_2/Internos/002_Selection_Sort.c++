void seleccion(int a[], int n){
    int i, j, min, aux;
   for ( i = 0; i< n - 1; i++){
    min = i;
        for (j= i + 1; j<n; j++){
            if (a[j] <a[min]){
                min=j;
         
            }
            aux=a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }