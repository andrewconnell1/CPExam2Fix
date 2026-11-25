#include <bits/stdc++.h>
using namespace std;

// for 5130
// 100 + 2 * 200 + 7 * 400 + 2 * 800 + 2 * 115
// so thats
// 100 * once           consecutive = 1
// 2 * 100 twice        1 < consecutive <= 3
// 4 * 100 seven times  3 < consecutive <= 10
// 8 * 100 twice        11 < consecutive
// 2 * 115 once 

int main() {
    int n;
    cin >> n;

    int consecutive = 0;
    vector<int> multiplier = {1,2,4,8};
    int currentMultiplier = 0;

    int total = 0;

    for(int i = 1; i < n+1; i++) {
        int score;
        cin >> score;

        if(score != 0) {
            if (consecutive == 0 && currentMultiplier != 0) {
                total += score * multiplier[currentMultiplier];
                cout << "current score: " << score * multiplier[currentMultiplier] << " current total: " << total << "\n";
                continue;
            }
            consecutive++;
            if (consecutive == 1) {
                currentMultiplier = 0;
                total += score * multiplier[currentMultiplier];
            } else if (consecutive >= 2 && consecutive < 5) {
                currentMultiplier = 1;
                total += score * multiplier[currentMultiplier];
            } else if (consecutive > 5 && consecutive <= 12) {
                currentMultiplier = 2;
                total += score * multiplier[currentMultiplier];
            } else if (consecutive > 12) {
                currentMultiplier = 3;
                total += score * multiplier[currentMultiplier];
            } 
        } else {
            currentMultiplier--;
            consecutive = 0;
        }
        
        cout << "current score: " << score * multiplier[currentMultiplier] << " current total: " << total << "\n";
    }
    
    cout << total;
    
}

/*

if the score is 0: 
decrement current multiplier as long as it is not currently 0;
conescutive = 0

if the score is not 0:
consecutive++





*/