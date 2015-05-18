#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

/* Problem: 
 * URL: 
 */
 
struct da {
    int hp, sp, e, step;
    da (int a, int b, int c) {
        hp =a;
        sp=b;
        e =c;
    }
};
queue <da> q;

int lh, ls, n;
int D[128];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    map <pair<int, pair<int,int> >, int> ma;
    while(scanf("%d %d %d", &lh, &ls, &n) != EOF) {
        for (int i = 1; i <= ls; i++) {
            scanf("%d", &D[i]);
        }
        
        da head = da(lh, 0, n);
        ma[make_pair(head.hp, make_pair(head.sp, head.e))] = 0;
        
        q.push(head);
        int reme = 0;
        int hp,sp,e, step;
        
        while (!q.empty()) {
            head = q.front();
            hp = head.hp;
            sp = head.sp;
            e = head.e;
            step = ma[make_pair(hp, make_pair(sp, e))];
            //printf("%d %d %d %d\n", hp, sp, e, step);
            if (e == 0) {
                break;
            }
            if (hp <= 0) {
                ma[make_pair(hp, make_pair(sp, e))] = 1000000007;
                q.pop();
                continue;
            }
            
            // kill
            reme = e-1;
            if (ma.count(make_pair(hp - reme, make_pair(min(ls, sp + 1 + (reme % 3) * reme), reme))) > 0) {
                if (ma[make_pair(hp - reme, make_pair(min(ls, sp + 1 + (reme % 3) * reme), reme))] > step + 1) {
                    ma[make_pair(hp - reme, make_pair(min(ls, sp + 1 + (reme % 3) * reme), reme))] = step + 1;
                    q.push(da(hp - reme, min(ls, sp + 1 + (reme % 3) * reme), reme));
                }
            } else {
                ma[make_pair(hp - reme, make_pair(min(ls, sp + 1 + (reme % 3) * reme), reme))] = step + 1;
                q.push(da(hp - reme, min(ls, sp + 1 + (reme % 3) * reme), reme));
            }
            // skill
            if (sp > 0) {
                reme = max(0, (e - D[sp]));
                
                if (ma.count(make_pair(hp - reme, make_pair(min(ls, 0 + (reme % 3) * reme), reme))) > 0) {
                    if (ma[make_pair(hp - reme, make_pair(min(ls, 0 + (reme % 3) * reme), reme))] > step + 1) {
                        ma[make_pair(hp - reme, make_pair(min(ls, 0 + (reme % 3) * reme), reme))] = step + 1;
                        q.push(da(hp - reme, min(ls, 0 + (reme % 3) * reme), reme));
                    }
                } else {
                    ma[make_pair(hp - reme, make_pair(min(ls, 0 + (reme % 3) * reme), reme))] = step + 1;
                    q.push(da(hp - reme, min(ls, 0 + (reme % 3) * reme), reme));
                }
                
            }
            // heal
            reme = e-1;
            q.push(da(min(hp + lh/5, lh) - reme, min(ls, sp + (reme % 3) * reme), reme));
            
            if (ma.count(make_pair(min(hp + lh/5, lh) - reme, make_pair(min(ls, sp + (reme % 3) * reme), reme))) > 0) {
                if (ma[make_pair(min(hp + lh/5, lh) - reme, make_pair(min(ls, sp + (reme % 3) * reme), reme))] > step + 1) {
                    ma[make_pair(min(hp + lh/5, lh) - reme, make_pair(min(ls, sp + (reme % 3) * reme), reme))] = step + 1;
                    q.push(da(min(hp + lh/5, lh) - reme, min(ls, sp + (reme % 3) * reme), reme));
                }
            } else {
                ma[make_pair(min(hp + lh/5, lh) - reme, make_pair(min(ls, sp + (reme % 3) * reme), reme))] = step + 1;
                q.push(da(min(hp + lh/5, lh) - reme, min(ls, sp + (reme % 3) * reme), reme));
            }
            
            q.pop();
        }
        
        int ans = 1000000007;
        for (int i = 0; i <= lh; i++) {
            for (int j = 0; j <= ls; j++) {
                if (ma.count(make_pair(i, make_pair(j, 0))) > 0) {
                    ans = min(ans, ma[make_pair(i, make_pair(j, 0))]);
                }
            }
        }
        
        if (ans >= 1000000007) {
            printf("HELP\n");
        } else {
            printf("%d\n", ans);
        }
        ma.clear();
        while (!q.empty()) q.pop();
    }
	return 0;
}
