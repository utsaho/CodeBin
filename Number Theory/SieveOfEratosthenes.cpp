/**
 * @author utsho
 * @date: 12 Jul 22
 */

#include <bits/stdc++.h>
#define int long long
#define tc()          \
    int test_case;    \
    cin >> test_case; \
    while (test_case--)
#define cout(a) cout << a << ed
#define ed '\n'
#define UTSHO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0)
#define OJ                         \
    freopen("in.txt", "r", stdin); \
    freopen("out.txt", "w", stdout);
using namespace std;

const int N = 1e8 + 10;
bool prime[N + 10];

void SeiveOfEratosthenes()
{
    int sq = sqrt(N * 1.0);
    prime[0] = true;
    prime[1] = true;
    prime[2] = false;
    for (int i = 4; i < N; i += 2)
        prime[i] = true;
    for (int i = 3; i <= sq; i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= N; j += (i * 2))
                prime[j] = true;
        }
    }
}

int main()
{
    UTSHO;
    OJ;
    int n;
    cin >> n;
    SeiveOfEratosthenes();
    cout << "Prime Numbers are: " << ed;
    for (int i = 0; i < n; i++)
    {
        if (!prime[i])
            cout << i << ed;
    }
    return 0;
}