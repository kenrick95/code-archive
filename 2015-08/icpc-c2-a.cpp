#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url     
 * @status  
 */
struct da
{
    int a, b;
    da() { a = 0; b = 0; }
    da(int _a, int _b) { a = _a, b = _b; }
    bool operator < (const da A) const {
        return a < A.a || (a == A.a && b < A.b);
    }
};
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    
    int a, b, t;
    queue<da> q;
    map<da, da> prev;
    da head, final;
    vector<string> instructions;
    while (scanf("%d %d %d", &a, &b, &t) != EOF) {

        q.push(da(0, 0));
        prev.clear();
        prev[da(a, b)] = da(a, b);
        while (!q.empty()) {
            head = q.front();
            q.pop();
            // printf("----------------------------\n");
            // printf("%d %d\n", head.a, head.b);
            if (/*head.a == t ||*/ head.b == t) {
                final = head;
                break;
            }
            // fill A
            // printf("%d\n", prev.count(da(a, head.b)));
            if (prev.count(da(a, head.b)) <= 0) {
                prev[da(a, head.b)] = head;
                q.push(da(a, head.b));
            }
            // fill B
            // printf("%d\n", prev.count(da(head.a, b)));
            if (prev.count(da(head.a, b)) <= 0) {
                prev[da(head.a, b)] = head;
                q.push(da(head.a, b));
            }
            // pour A --> B
            // printf("A --> B %d\n", prev.count(da(max(0, head.a - (b - head.b)), min(b, head.a + head.b))));
            // printf("%d\n", max(0, head.a - (b - head.b)));
            // printf("%d\n\n", min(b, head.a + head.b));
            if (prev.count(da(max(0, head.a - (b - head.b)), min(b, head.a + head.b))) <= 0) {
                prev[da(max(0, head.a - (b - head.b)), min(b, head.a + head.b))] = head;
                q.push(da(max(0, head.a - (b - head.b)), min(b, head.a + head.b)));
            }
            // pour B --> A
            // printf("B --> A %d\n", prev.count(da(min(a, head.a + head.b), max(0, head.b - (a - head.a)))));
            // printf("%d\n", min(a, head.a + head.b));
            // printf("%d\n\n", max(0, head.b - (a - head.a)));
            if (prev.count(da(min(a, head.a + head.b), max(0, head.b - (a - head.a)))) <= 0) {
                prev[da(min(a, head.a + head.b), max(0, head.b - (a - head.a)))] = head;
                q.push(da(min(a, head.a + head.b), max(0, head.b - (a - head.a))));
            }
            // empty A
            // printf("%d\n", prev.count(da(0, head.b)));
            if (prev.count(da(0, head.b)) <= 0) {
                prev[da(0, head.b)] = head;
                q.push(da(0, head.b));
            }
            // empty B
            // printf("%d\n", prev.count(da(head.a, 0)));
            if (prev.count(da(head.a, 0)) <= 0) {
                prev[da(head.a, 0)] = head;
                q.push(da(head.a, 0));
            }
        }
        instructions.clear();
        while (final.a != 0 || final.b != 0) {
            // printf("%d %d\n", final.a, final.b);
            if (final.a < prev[final].a && final.b > prev[final].b) {
                instructions.push_back("pour A B");
            } else if (final.b < prev[final].b && final.a > prev[final].a) {
                instructions.push_back("pour B A");
            } else if (final.a == 0 && prev[final].a > 0 && prev[final].b == final.b) {
                instructions.push_back("empty A");
            } else if (final.b == 0 && prev[final].b > 0 && prev[final].a == final.a) {
                instructions.push_back("empty B");
            } else if (final.a == a && prev[final].b == final.b) {
                instructions.push_back("fill A");
            } else if (final.b == b && prev[final].a == final.a) {
                instructions.push_back("fill B");
            }

            final = prev[final];
        }
        for (int i = instructions.size() - 1; i >=0; i--) {
            cout << instructions[i] << "\n";
        }
        printf("success\n");
        while (!q.empty()) {
            q.pop();
        }
    }
    return 0;
}
