#include <iostream>
#include <string>
#include "hash.h"

using namespace std;


int hash_function(string s, int m)
{       
    long long p = 31;
    long long hash_value;
    long long hash_so_far = 0;
    long long p_pow = 1;
    const long long n = s.length();
    for (long long i = 0; i < n; ++i) {
        hash_so_far
            = (hash_so_far + (s[i] - 'a' + 1) * p_pow)
                % m;
        p_pow = (p_pow * p) % m;
    }
    hash_value = hash_so_far;
    return hash_value;
}
