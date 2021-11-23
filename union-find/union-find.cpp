#include <iostream>


using namespace std;


const int N = 100010;

int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++) p[i] = i;
    
    for (int i = 0; i < m; i ++)
    {
        char operation;
        int a, b;
        cin >> operation;
        cin >> a >> b;
        if (operation == 'M')
        {
            p[find(a)] = find(b);
        }
        else
        {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}