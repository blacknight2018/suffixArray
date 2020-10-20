#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//https://blog.csdn.net/Cassie_zkq/article/details/98365310
//https://blog.csdn.net/a1035719430/article/details/80217267
const int maxn = 1000;
const int maxasc = 128; //ascII码[0,127]
char s[maxn];
int sa[maxn], t1[maxn], t2[maxn], c[maxn], n;

void debug()
{
    for (int i = 0; i < n; i++) printf("%d ", sa[i]);
    printf("\n");
}


void build_sa3(int m) {
    int* x = t1, * y = t2;
    for (int i = 0; i < m; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[x[i] = s[i]]++;

    for (int i = 1; i < m; i++)
        c[i] += c[i - 1];

    for (int i = 0; i < n; i++)
        sa[--c[x[i]]] = i;

    for (int k = 1; k <= n; k *= 2) {
        int p = 0;
        for (int i = n - k; i < n; i++)
            y[p++] = i;
        for (int i = 0; i < n; i++) {
            if (sa[i] - k >= 0)
                y[p++] = sa[i] - k;
        }
        for (int i = 0; i < m; i++)
            c[i] = 0;
        for (int i = 0; i < n; i++) {
            c[x[y[i]]]++;
        }
        for (int i = 1; i < m; i++) {
            c[i] += c[i - 1];
        }
        for (int i = n-1; i >=0; i--) {
            sa[--c[x[y[i]]]] = y[i];
        }
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++) {

            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]]) && (y[sa[i - 1] + k] == y[sa[i] + k]) ? (p - 1) : (p++);

        }
        if (p >= n)
            break;
        m = p;

    }
}
void build_sa(int m)
{
    int* x = t1, * y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k = k << 1)
    {
        int p = 0;

        for (int i = n - k; i < n; i++) y[p++] = i;

        for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);
        p = 1; x[sa[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]]) && (y[sa[i - 1] + k] == y[sa[i] + k]) ? (p - 1) : (p++);
        }

        if (p >= n) break;
        m = p;
    }

    return;
}

int main()
{
    int a[]{ 1,2,3 }, b[]{ 4,5,6};
    swap(a,b);
    scanf("%s", s);
    n = strlen(s);
    build_sa3(maxasc);
    build_sa(maxasc);
    return 0;
}