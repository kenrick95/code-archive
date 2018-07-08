#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL
#define PI 3.14192653589793F

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

long int gcd(long int a, long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/**
 * @problem 
 * @url     
 * @status  
 */

int main(){
    freopen("tourist.txt", "r", stdin);
    freopen("tourist.out", "w", stdout);
    int T;
    long int N, K;
    long int V;
    // scanf("%d\n", &T);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        // scanf("%ld %ld %ld\n", &N, &K, &V);
        cin >> N >> K >> V;
        vector<string> names;
        // cout << "K" << K << "\n";

        for (int n = 0; n < N; n++) {
            string name;
            cin >> name;
            names.push_back(name);
        }

        long int repeat = N / gcd(N, K);

        long int group_index = (V - 1) % repeat;

        long int start_index = 0;

        // Determine start index
        for (int i = 0; i < group_index; i++) {
            start_index = (start_index + K) % N;
        }

        // Collect answers
        vector<string> answers;
        // Collect front
        for (int i = 0; i < (K - N + start_index); i++) {
            answers.push_back(names[i]);
            // cout << names[i] << " ";
        }
        // cout << " -- ";
        
        // Collect back
        for (int i = start_index; i < min(N, K + start_index); i++) {
            answers.push_back(names[i]);
            // cout << names[i] << " ";
        }

        cout << "Case #" << (t + 1) << ": "; // << repeat << " " << start_index << "\n";

        for (int i = 0; i < answers.size(); i++) {
            cout << answers[i];
            if (i != answers.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
