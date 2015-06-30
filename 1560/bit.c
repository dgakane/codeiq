#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t summult( int l, int64_t base);
int64_t getSumOfMultiples(int limit);

int primes[10] = {3,5,7,11,13,17,19,23,29,31};

int64_t summult( int l, int64_t base){
    int64_t n = (int64_t)l / base;
    return (n * (n+1) / 2) * base;
}

int64_t getSumOfMultiples(int limit){

    int i, j, cnt;
    int64_t amount = 0;
    int64_t product;
    char sign;
    int a_size = sizeof(primes) / sizeof(int);

    for (i = 1; i < (1 << a_size); i++){
        product = 1;
        cnt = 0;
        for (j = 0; j < a_size; j++){
            if( i & (1 << j)){
                cnt++;
                product *= primes[j];
            }
        }
        sign = cnt & 1 ? 1 : -1; // If cnt is an even number, sign should be minus.
        amount +=  sign * summult( limit, product);
    }
    return amount;
}

int main(){
    printf("第1問の答えは %lld です\n",getSumOfMultiples(100000));
    printf("第2問の答えは %lld です\n",getSumOfMultiples(1000000000));
    return EXIT_SUCCESS;
}
