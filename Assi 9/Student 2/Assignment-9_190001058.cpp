//Somya Mehta
//190001058
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
int n;
void Counting_Sort(int a[], int b[], int k)
{
    int c[k + 1], c1[k + 1] = {0};
    for (int i = 0; i <= k; i++)
        c[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        c[a[i]]++;
        c1[a[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    cout << "Modified Array after applying modified Counting sort\n";
    for (int i = 1; i <= n; i++)
    {
        int j = i + c1[b[i]] - 1;
        reverse(b + i, b + j + 1);
        i = j;
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    // cout << "\n";
    cout << "\n";
}
int main()
{
    cout << "Enter the size of the array\n";
    cin >> n;
    int a[n + 1], b[n + 1];
    cout << "Enter the elements of the array\n";
    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxi = max(a[i], maxi);
    }
    Counting_Sort(a, b, maxi);
}