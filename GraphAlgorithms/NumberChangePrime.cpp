/*              PRIME PATH PROBLEM
We are given 2 numbers such that we have to convert the first number to the second number
(given both the numbers are prime)...In one move we can change just one digit
All the intermediate numbers formed must also be prime
Find minimum number of such moves needed
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int visited[10001];
int dist[10001];
vector<int> primes;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : v[parent])
        {
            if (!visited[child])
            {
                dist[child] = dist[parent] + 1;
                visited[child] = 1;
                q.push(child);
            }
        }
    }
}

bool isPrime(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool isValid(int a, int b)
{
    int count = 0;

    while (a > 0)
    {
        if (a % 10 != b % 10)
        {
            count++;
        }
        a /= 10;
        b /= 10;
    }

    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void buildGraph()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            int a = primes[i];
            int b = primes[j];

            if (isValid(a, b))
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    buildGraph();
    int a, b;
    while (t--)
    {
        cin >> a >> b;
        for (int i = 1000; i <= 9999; i++)
        {
            dist[i] = -1;
            visited[i] = 0;
        }

        bfs(a);

        if (dist[b] == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dist[b] << endl;
        }
    }
}