#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

vector<int> primes;
bool isPrime[MAX];
bool isFactorCovered[MAX];

void cal() {
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= MAX; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX; j+= i) {
        isPrime[j] = false;
      }
    }
  }
  for (int i = 0; i <= MAX; i++) {
    if (isPrime[i])
      primes.push_back(i);
  }
}

vector<int> factors(int num) {
  vector<int> factors;
  for (int i = 2; i * i <= num; i++) {
    if (num == 1) {
      return factors;
    }
    while(num % i == 0) {
      factors.push_back(i);
      num /= i;
    }
  }
  if (num != 1) {
    factors.push_back(num);
  }
  return factors;
}

bool isAllFactorCovered(vector<int> factors) {
  for (int i = 0; i < factors.size(); i++) {
    if (!isFactorCovered[factors[i]]) {
      isFactorCovered[factors[i]] = true;
      return false;
    }
  }
  return true;
}

bool containNewPrime(int num) {
  if (isAllFactorCovered(factors(num)))
    return false;
  return true;
}

int main() {
  // cal();
  memset(isFactorCovered, 0, sizeof(isFactorCovered));
  // vector<int> ans = factors(63);
  // for (int i = 0; i < ans.size(); i++) { cout << ans[i] << " "; }

  int seed = 3;

  while(seed < 1000000) {
    if (containNewPrime(seed)) {
      // cout << seed << endl;
      
    } else {
      cout << seed << endl;
    }
    seed *= 2;
    seed++;
  }
}