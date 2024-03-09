#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void radix_sort(unsigned int A[] , unsigned int n){
        unsigned int bucket0[MAX_SIZE], bucket1[MAX_SIZE];
        unsigned int mask, count0, count1;
        for (int d= 0; d<32; d++){
                count0= count1=0;
                mask = 1 << d;
                for (int i= 0; i<n; i++){
                        if ((A[i] & mask) == 0){
                                bucket0[count0++] = A[i];
                        }
                        else{
                                bucket1[count1++]= A[i];
                        }
                }
                for (int i = 0; i < count0; i++)
                {
                        A[i] = bucket0[i];
                }
                for (int i =0; i<count1;i++){
                        A[count0 + i ] = bucket1[i];
                }


        }


}

void radix_sort_signed(unsigned int  A[] , int n){
	unsigned int positive[MAX_SIZE], negative[MAX_SIZE];
        unsigned int pos_count = 0 , neg_count=0;
        for (int i =0; i<n; i++){
                if(((A[i] >> 31) & 1) == 0){
                        positive[pos_count++] = A[i];

                }
                else {
                        negative[neg_count++] = A[i];
                }

                radix_sort(positive,pos_count);
                radix_sort(negative,neg_count);

                for(int i =neg_count -1; i>=0; i--){
                        A[neg_count - i -1] = negative[i];
                }
                for(int i =0;i<pos_count; i++){
                        A[neg_count + i] = positive[i];
                }
        }
}

void radixSortFloats(float f[], int n){
        unsigned int *p = (unsigned int *) f;
        radix_sort_signed(p,n);
}


float * allocateArray(unsigned int num){
        float * ptr =(float *) malloc(num* sizeof(float));
        return ptr;

}
int main(){
        unsigned int num;
        float * A;
        float digit;
        int i;
        
        scanf("%u", &num);
        if (num > 100){
                printf("You have entered more than 100 please try again Exiting...\n");
                exit(0);
        }
        A= allocateArray(num);
        for (i=0;i<num;i++){
                scanf("%f",A +i);
        }

        radixSortFloats(A,num);
        
        
        for(int i= 0; i<num; i++)
        {
                printf("%.6f\n",A[i]);
        }
        printf("\n");
}
