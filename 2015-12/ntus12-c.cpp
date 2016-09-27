#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long double64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem
 * @url
 * @status
 */



 double get_variable_val(string c) {
   return 2.71828 - (c[0] - 'a') / 100.0;
 }
 bool delim (char c) { return c == ' '; }
 bool is_op (char c) { return c=='+' || c=='-' || c=='*' || c=='/' || c=='%'; }
 double priority (char op) {
 return op == '+' || op == '-' ? 1 : op == '*' || op == '/' || op == '%' ? 2 : -1;
 }
 void process_op (vector<double> & st, char op) {
   double r = st.back(); st.pop_back();
   double l = st.back(); st.pop_back();
   switch (op) {
     case '+': st.push_back (l + r); break;
     case '-': st.push_back (l - r); break;
     case '*': st.push_back (l * r); break;
     //case '/': st.push_back (l / r); break;
     //case '%': st.push_back (l % r); break;
   }
 }
 double calc (string & s) {
   vector<double> st;
   vector<char> op;
   for (size_t i=0; i<s.length(); ++i)
      if (!delim (s[i]))
          if (s[i] == '(')
              op.push_back ('(');
          else if (s[i] == ')') {
            while (op.back() != '(')
              process_op (st, op.back()), op.pop_back();
            op.pop_back();
          }
          else if (is_op (s[i])) {
            char curop = s[i];
            while (!op.empty() && priority(op.back()) >= priority(s[i]))
              process_op (st, op.back()), op.pop_back();
            op.push_back (curop);
          }
          else {
            string operand;
            while (s[i] >= 'a' && s[i] <= 'z' || isdigit (s[i]))
              operand += s[i++];
            --i;
            if (isdigit (operand[0]))
              st.push_back ((double) atoi (operand.c_str()));
            else
              st.push_back (get_variable_val (operand));
          }
          while (!op.empty())
        process_op (st, op.back()), op.pop_back();
   return st.back();
  }

int T;
string st1, st2;

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);

    scanf("%d", &T);
    getline(cin, st1);
    for (int t = 0; t < T; t++) {
      getline(cin, st1);
      getline(cin, st2);
      // cout << "st1" << st1;
      // cout << "st2" << st2;
      fabs(calc(st1) - calc(st2)) < 0.000001 ? puts("YES") : puts("NO");
    }
    return 0;
}
