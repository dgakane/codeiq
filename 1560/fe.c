#include <stdio.h>
#include <stdlib.h>

#define MAX (10)

int64_t summult( int l, int64_t base);
int Init(int S[], int N, int K);
int Next(int S[], int N);
void Dump(int S[], int N);
int64_t arrayproduct(int S[], int P[]);
int64_t getSumOfMultiples(int limit);

int64_t summult( int l, int64_t base){
    int64_t n = (int64_t)l / base;
    return (n * (n+1) / 2) * base;
}

int Init(int S[], int N, int K){
    int L;
    if( K >= 0 && N >= K){
        for(L = 0; L < N; L++){
            if(L < K){
                S[L] = 1;
            } else {
                S[L] = 0;
            }
        }
        return 0;
    } else {
        return -1;
    }
}

int Next(int S[], int N){
    int C, L, R;
    C = 0;
    L = 0;
    R = -1;

    while(L < N-1 && R == -1){
        if(S[L] == 1){
            if(S[L+1] == 0){
                S[L] = 0;
                S[L+1] = 1;
                Init(S, L, C);
                R = 0;
            } else {
                C++;
            }
        }
    L++;
    }
    return R;
}
void Dump(int S[], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("%d", S[i]);
    }
    printf("\n");

}
int64_t arrayproduct(int S[], int P[]){
    int64_t product = 1;
    int i;

    for(i = 0; i < MAX; i++){
        if(S[i] != 0) product *= S[i] * P[i];
    }
    return product;
}

int64_t getSumOfMultiples(int limit){
    int S[MAX];
    int K, N, R, sign;
    int primes[MAX] = {3,5,7,11,13,17,19,23,29,31};
    int64_t amount = 0;

    N = MAX;

    for(K = 1; K <= N; K++){
        sign = K % 2 == 1 ? 1 : -1;
        R = Init(S, N, K);
        while(R == 0){
            amount += sign * summult(limit, arrayproduct(S, primes));
            R = Next(S, N);
        }
    }
    return amount;
}

int main(void){
    int64_t result;
    int limit;

    limit = 100000;
    result = getSumOfMultiples(limit);
    printf("第1問目の答え: %llu\n", result);

    limit = 1000000000;
    result = getSumOfMultiples(limit);
    printf("第2問目の答え: %llu\n", result);

    return EXIT_SUCCESS;
}
