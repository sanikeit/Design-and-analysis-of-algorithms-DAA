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

int main()
{
    int n, m;
    cout << "Input:->\n";
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int distance[n + 1];
    for (int i = 1; i <= n; i++)
        distance[i] = INT_MAX;
    distance[1] = 0;
    priority_queue<pair<int, int>> pq;
    int mark[n + 1] = {0};
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<int, int> s = pq.top();
        pq.pop();
        int source = s.second, dist = s.first;
        mark[source] = 1;
        for (auto it : adj[source])
        {
            int x = it.first, edge_weight = it.second;
            if (mark[x] == 1)
                continue;
            if (distance[source] + edge_weight < distance[x])
            {
                distance[x] = distance[source] + edge_weight;
                pq.push({-distance[x], x});
            }
        }
    }
    cout << "OUTPUT->\n";
    for (int i = 2; i <= n; i++)
        cout << "1 " << i << " " << distance[i] << "\n";
}
