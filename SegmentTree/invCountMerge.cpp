#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; _a++)
#define filename "cfile"
typedef long long ll;

int n, i;
ll a[100001], b[100002], ma, o;

int ST[400001];
void update(int vt, int l, int r, int i) {
    if (i < l || r < i) return;
    if (l == r) {
        ST[vt]++;
        return;
    }
    int mid = (l + r) / 2;
    update(vt * 2, l, mid, i);
    update(vt * 2 + 1, mid + 1, r, i);
    ST[vt] = ST[vt * 2] + ST[vt * 2 + 1];
}

int get(int vt, int l, int r, int u, int v) {
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return ST[vt];
    int mid = (l + r) / 2;
    return get(vt * 2, l, mid, u, v) + get(vt * 2 + 1, mid + 1, r, u, v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    //freopen(filename".inp","r",stdin); freopen(filename".out","w",stdout);

    cin >> n;
    forr(i,1,n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1,b + 1 + n);
    forr(i,1,n) {
        a[i] = lower_bound(b + 1,b + n + 1,a[i]) - b;
        ma = max(ma,a[i]);
    }
    forr(i,1,n) {
        o += get(1,1,n,a[i] + 1,ma);
        update(1,1,n,a[i]);
    }
    cout << o;

    return 0;
}