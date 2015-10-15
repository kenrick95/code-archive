#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n;
double T;

struct Ball {
    int idx;
    double x, v, m;
    Ball() {}
    Ball(double _x, double _v, double _m): x(_x), v(_v), m(_m) {}
} balls[16];

double _time;

bool ganteng(const Ball &a, const Ball &b) {
    return a.x < b.x;
}

bool comp(const Ball &a, const Ball &b) {
    return a.idx < b.idx;
}

int main() {
    scanf("%d %lf", &n, &T);
    for(int i = 1; i <= n; ++i) {
        double x, v, m;
        scanf("%lf %lf %lf", &x, &v, &m);
        balls[i] = Ball(x, v, m);
        balls[i].idx = i;
    }
    while(_time < T) {
        priority_queue<pair<double, int> > pq;
        sort(balls + 1, balls + 1 + n, ganteng);
        for(int i = 1; i < n; ++i) {
            if(balls[i].v - balls[i + 1].v > 0) {
                double t = (double) (balls[i + 1].x - balls[i].x) /  (double) (balls[i].v - balls[i + 1].v);
                if(t > 0) pq.push(make_pair(-t, i));
            }
        }
        
        double t = T - _time;
        if(!pq.empty()) {
            pair<double, int> _ = pq.top();
            pq.pop();
            t = min(t, -_.first);
            int i = _.second;
        
            for(int k = 1; k <= n; ++k) {
                balls[k].x += balls[k].v * t;
            }
            if(-_.first < T - _time) {
                double new_v0 =  (double) ((balls[i].m - balls[i + 1].m) * balls[i].v + (double) 2. * balls[i + 1].m * balls[i + 1].v) /  (double) (balls[i].m + balls[i + 1].m);
                double new_v1 =  (double) ((balls[i + 1].m - balls[i].m) * balls[i + 1].v + (double) 2. * balls[i].m * balls[i].v) /  (double) (balls[i].m + balls[i + 1].m);
                balls[i].v = new_v0;
                balls[i + 1].v = new_v1;
            }
        } else {
            for(int k = 1; k <= n; ++k) {
                balls[k].x += balls[k].v * t;
            }
        }
        _time += t;
    }
    
    sort(balls + 1, balls + 1 + n, comp);
    for(int i = 1; i <= n; ++i) printf("%.9lf\n", balls[i].x);
    
    return 0;
}