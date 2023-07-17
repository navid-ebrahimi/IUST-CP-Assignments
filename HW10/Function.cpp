#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void buildSegmentTree(vector<ll>& tree, vector<ll>& arr, ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        ll mid = (start + end) / 2;
        buildSegmentTree(tree, arr, 2 * node, start, mid);
        buildSegmentTree(tree, arr, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void updateSegmentTree(vector<ll>& tree, ll node, ll start, ll end, ll idx, ll value) {
    if (start == end) {
        tree[node] = value;
    } else {
        ll mid = (start + end) / 2;
        
        if (start <= idx && idx <= mid) {
            updateSegmentTree(tree, 2 * node, start, mid, idx, value);
        } else {
            updateSegmentTree(tree, 2 * node + 1, mid + 1, end, idx, value);
        }
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

ll querySegmentTree(vector<ll>& tree, ll node, ll start, ll end, ll l, ll r) {
    if (r < start || end < l) {
        return INT_MAX;
    }
    
    if (l <= start && end <= r) {
        return tree[node];
    }
    
    ll mid = (start + end) / 2;
    
    ll leftSum = querySegmentTree(tree, 2 * node, start, mid, l, r);
    ll rightSum = querySegmentTree(tree, 2 * node + 1, mid + 1, end, l, r);
    
    return min(leftSum, rightSum);
}

int main() {
    ll n, q; cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll treeHeight = ceil(log2(n));
    ll treeSize = 2 * pow(2, treeHeight) - 1;
    vector<ll> segmentTree(treeSize);
    buildSegmentTree(segmentTree, arr, 1, 0, n - 1);
    while (q--)
    {
        int l1,l2,l3; cin >> l1 >> l2 >> l3;
        l2--;
        if (l1 == 1)
        {
            l3 = max(0,l3-1);
            ll sum = querySegmentTree(segmentTree, 1, 0, n - 1, l2, l3);
            cout << sum << endl;
        }
        else
        {
            updateSegmentTree(segmentTree, 1, 0, n - 1, l2, l3);
        }
    }
    
    return 0;
}
