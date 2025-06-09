#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    ll v;
    Node *l, *r;
};

using Tree = Node *;

inline Tree newNode(ll v)
{
    Tree n = new Node;
    n->v = v;
    n->l = n->r = nullptr;
    return n;
}

void addNode(Tree cur, ll p, ll c, char d)
{
    if (!cur)
        return;
    if (cur->v == p)
    {
        if (d == 'L')
            cur->l = newNode(c);
        else
            cur->r = newNode(c);
    }
    else
    {
        addNode(cur->l, p, c, d);
        addNode(cur->r, p, c, d);
    }
}

ll sumBT(Tree root)
{
    if (!root)
        return 0;
    return root->v;
}

bool check(Tree root)
{
    if (!root)
        return 0;
    ll v = root->v;
    ll ls = sumBT(root->l);
    ll rs = sumBT(root->r);
    if (ls + rs == v)
        return 1;
    return check(root->l) && check(root->r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<tuple<ll, ll, char>> e(n);
        for (int i = 0; i < n; ++i)
        {
            ll p, c;
            char d;
            cin >> p >> c >> d;
            e[i] = make_tuple(p, c, d);
        }
        ll rv = get<0>(e[0]);
        Tree root = newNode(rv);
        for (auto &kv : e)
        {
            ll p = get<0>(kv), c = get<1>(kv);
            char d = get<2>(kv);
            addNode(root, p, c, d);
        }
        cout << (check(root) ? 1 : 0) << '\n';
    }
    return 0;
}
