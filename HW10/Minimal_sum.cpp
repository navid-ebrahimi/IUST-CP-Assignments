#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll sum;
    ll answer;
    ll prefix;
    ll suffix; 

    Node() : sum(0), answer(0), prefix(0), suffix(0) {}
    
    Node(ll sum, ll answer, ll prefix, ll suffix)
        : sum(sum), answer(answer), prefix(prefix), suffix(suffix) {}
};

void buildSegmentTree(vector<Node>& tree, vector<ll>& arr, ll node, ll start, ll end) {
    if (start == end) {
        if(arr[start]>0){
            tree[node].sum = arr[start];
            tree[node].prefix = 0;
            tree[node].suffix = 0;
            tree[node].answer = 0;
        }
        else{
            tree[node].sum = arr[start];
            tree[node].prefix = arr[start];
            tree[node].suffix = arr[start];
            tree[node].answer = arr[start];
        }
    }
    else {
        ll mid = (start + end) / 2;
        buildSegmentTree(tree, arr, 2 * node, start, mid);
        buildSegmentTree(tree, arr, 2 * node + 1, mid + 1, end);
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
        tree[node].prefix = min(tree[2*node].prefix, tree[2*node].sum + tree[2*node+1].prefix);
        tree[node].suffix = min(tree[2*node+1].suffix, tree[2*node+1].sum + tree[2*node].suffix);
        tree[node].answer = min(tree[2*node].suffix+tree[2*node+1].prefix, min(tree[2*node].answer, tree[2*node+1].answer));
    }
}

void updateSegmentTree(vector<Node>& tree, vector<ll>& arr, ll node, ll start, ll end, ll index, ll value) {
    if (start == end) {
        arr[start] = value;
        if(arr[start]>0){
            tree[node].sum = arr[start];
            tree[node].prefix = 0;
            tree[node].suffix = 0;
            tree[node].answer = 0;
        }
        else{
            tree[node].sum = arr[start];
            tree[node].prefix = arr[start];
            tree[node].suffix = arr[start];
            tree[node].answer = arr[start];
        }
    } else {
        ll mid = (start + end) / 2;
        if (index >= start && index <= mid) {
            updateSegmentTree(tree, arr, 2 * node, start, mid, index, value);
        } else {
            updateSegmentTree(tree, arr, 2 * node + 1, mid + 1, end, index, value);
        }

        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
        tree[node].prefix = min(tree[2*node].prefix, tree[2*node].sum + tree[2*node+1].prefix);
        tree[node].suffix = min(tree[2*node+1].suffix, tree[2*node+1].sum + tree[2*node].suffix);
        tree[node].answer = min(tree[2*node].suffix+tree[2*node+1].prefix, min(tree[2*node].answer, tree[2*node+1].answer));
    }
}

Node querySegmentTree(vector<Node>& tree, ll node, ll start, ll end, ll l, ll r) {
    if (r < start || l > end) {
        return Node(0,0,0,0);
    }
    if (l <= start && r >= end) {
        return tree[node];
    }
    ll mid = (start + end) / 2;
    Node p1 = querySegmentTree(tree, 2 * node, start, mid, l, r);
    Node p2 = querySegmentTree(tree, 2 * node + 1, mid + 1, end, l, r);
    Node p3;
    p3.sum = p1.sum + p2.sum;
    p3.prefix = min(p1.prefix, p1.sum + p2.prefix);
    p3.suffix = min(p2.suffix, p2.sum + p1.suffix);
    p3.answer = min(p1.suffix+p2.prefix, min(p1.answer, p2.answer));
    return p3;
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
    vector<Node> segmentTree(treeSize);
    buildSegmentTree(segmentTree, arr, 1, 0, n - 1);
    while (q--)
    {
        ll l1,l2,l3; cin >> l1 >> l2 >> l3;
        l2--;
        if (l1 == 1)
        {
            if (l3 - 1 < 0)
            {
                l3 = 0;
            }
            else
                l3--;
            Node res = querySegmentTree(segmentTree, 1, 0, n - 1, l2, l3);
            ll answer = res.answer;
            cout << answer << endl;
        }
        else
        {
            updateSegmentTree(segmentTree, arr, 1, 0, n - 1, l2, l3);
        }
    }
    
    return 0;
}