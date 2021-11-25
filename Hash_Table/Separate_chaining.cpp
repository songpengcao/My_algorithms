#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx = 0;

void insert(int x)
{
    int k = ((x % N) + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx ++;
}

bool find(int x)
{
    int k = ((x % N) + N) % N;
    
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x) return true;
    }
    return false;
}


int main()
{
    int n;
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    for (int i = 0; i < n; i ++)
    {
        char s[2];
        int x;
        scanf("%s%d", s, &x);
        if (*s == 'I')
        {
            insert(x);
        }
        else
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}