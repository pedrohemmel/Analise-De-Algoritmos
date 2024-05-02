#include <stdio.h>
#include <stdlib.h>

int merge_sort_inv(int v[], int vectorSize){
	
	int inv=0;
	
	if(vectorSize==1) return 0;
	
    int vectorSizeHalf = vectorSize / 2;
	int v1[vectorSizeHalf];
    int v2[vectorSizeHalf];
	
	for(int i = 0; i < vectorSizeHalf; i++) {
		v1[i] = v[i];
	}
	for(int i = vectorSizeHalf; i < vectorSize; i++){
	 	v2[i] = v[i];
	}	
	
	inv+=merge_sort_inv(v1, vectorSizeHalf);
	inv+=merge_sort_inv(v2, vectorSizeHalf);
	
	int x = 0, y = 0;
	for(int i = 0;i < vectorSize; i++) {
		if(v1[x]<=v2[y]){
			v[i]=v1[x];
			
			x++;
		} else{
			v[i]=v2[y];
			y++;
	
			inv+=1;
		}
	}
	return inv;
}

int main() {
    int v[10] = {3, 2, 5, 6, 1, 8, 10, 7, 4, 9};

    int inv = merge_sort_inv(v, 10);

    printf("Número de inversões: %d\n", inv);

    return 0;
}
