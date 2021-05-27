#include<bits/stdc++.h>
using namespace std;

// there is always a kaprekar number but you have to find biggest one
// three digit kaprekar number is  495
int biggestMinusSmallest(int num) {
    string numString = to_string(num);
    sort(numString.begin(), numString.end(), greater<int>());
    int biggest = stoi(numString);
    reverse(numString.begin(), numString.end());
    int smallest = stoi(numString);
    return (biggest - smallest);
}

int toKaprekar(int num) {
    int diff = biggestMinusSmallest(num);
    if (diff == 0) return 0;
    int steps = 0;
    // not infinite loop
    while(num != biggestMinusSmallest(num)) {
        cout << num << endl;
        num = biggestMinusSmallest(num);
        steps++;
    }
    return num;
}
int main() {
    freopen("five.txt", "w", stdout);
    for (int i = 10000; i < 1000000; i++) {
        // if (toKaprekar(i) == 0)
            cout << i << " " << toKaprekar(i) << endl;
    }
    return 0;
}