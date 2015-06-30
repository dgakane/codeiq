#!/usr/bin/env python3

primes = [3,5,7,11,13,17,19,23,29,31]

def multiples(Limit, base):
    n = Limit // base
    return (n * (n+1) // 2) * base

def productTuple(t):
    from functools import reduce
    ret = 1
    if(len(t) > 0):
        ret = reduce(lambda x,y: x*y, t)
    return ret 

def getSumOfMultiples(limit):
    from itertools import combinations

    amount = 0
    for i in range(len(primes)):
        cur = primes[i]
        done = primes[0:i]

        for j in range(i+1):
            for elm in combinations(done, j):
                amount += ((-1) ** j) * multiples(limit, productTuple(elm) * cur)
    return amount

if __name__ == '__main__':
    print("第1問の答え: " + str(getSumOfMultiples( 10 ** 5)))
    print("第2問の答え: " + str(getSumOfMultiples( 10 ** 9)))

