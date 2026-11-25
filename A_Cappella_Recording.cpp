#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, d;
    cin >> n >> d;

    vector<long long> pitches;

    while(n--) {
        long long i;
        cin >> i;
        pitches.push_back(i);
    }

    long long iters = 0;
    long long max = -1;

    sort(pitches.begin(), pitches.end());

    for(int i = 0; i < pitches.size(); i++) {
        long long val = pitches[i];
        if(val > max) {
            iters++;
            max = val + d;
        }
    }

    cout << iters << "\n";

}