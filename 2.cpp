//
// Created by Seo_Hyun on 8/9/2020.
//

#include<bits/stdc++.h>

using namespace std;

vector<bool> vi;
vector<double> req;
vector<tuple<int, int, bool>> li[1003];

double dfs(int pl) {
    vi[pl] = true;
    double ma = 0;
    for (auto i:li[pl]) {
        int f, p;
        bool su;
        tie(f, p, su) = i;
        if (vi[f]) continue;
        double t = dfs(f);
        if (su) t = sqrt(t);
        t = t / (double) (p) * 100.0;
        ma = max(ma, t);
    }
    if (ma == 0) ma = req[pl];
    return ma;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi.resize(n);
    req.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int s, f, p, fl;
        bool su;
        cin >> s >> f >> p >> fl;
        su = fl ? true : false;
        li[s - 1].emplace_back(make_tuple(f - 1, p, su));
        li[f - 1].emplace_back(make_tuple(s - 1, p, su));
    }
    for (int i = 0; i < n; ++i) cin >> req[i];
    cout << dfs(0) << '\n';
    return 0;
}