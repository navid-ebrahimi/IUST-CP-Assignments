#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long V;

typedef long long ll;


class MinHeap {
private:
    vector<std::pair<ll, long long>> heap;

    ll parent(ll index) {
        return (index - 1) / 2;
    }

    ll leftChild(ll index) {
        return (2 * index) + 1;
    }

    ll rightChild(ll index) {
        return (2 * index) + 2;
    }

    void heapifyUp(ll index) {
        if (index != 0 && heap[index].second < heap[parent(index)].second) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(ll index) {
        ll left = leftChild(index);
        ll right = rightChild(index);
        ll smallest = index;

        if (left < heap.size() && heap[left].second < heap[index].second)
            smallest = left;

        if (right < heap.size() && heap[right].second < heap[smallest].second)
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}

    void insert(pair<ll, long long> value) {
        heap.push_back(value);
        ll index = heap.size() - 1;
        heapifyUp(index);
    }

    void removeMin() {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    pair<ll, long long> getMin() {
        if (!heap.empty())
            return heap[0];
        return make_pair(-1, -1);
    }

    bool isEmpty() {
        return heap.empty();
    }
};

ll bfs(vector<vector<ll>>& graph, ll startNode, vector<ll>& power) {
    ll saleh = power[startNode];
    ll need = 0;
    ll numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    MinHeap heap;
    visited[startNode] = true;
    heap.insert(make_pair(startNode, power[startNode]));

    while (!heap.isEmpty()) {
        pair<ll, ll> minElement = heap.getMin();
        heap.removeMin();
        if (minElement.first != startNode)
        {
            if (saleh <= minElement.second)
            {
                need += abs(saleh - minElement.second)+1;
                saleh += abs(saleh - minElement.second)+1;
            }
            saleh += minElement.second;
        }
        
        for (ll neighbor : graph[minElement.first]) {
            if (!visited[neighbor]) {
                heap.insert(make_pair(neighbor, power[neighbor]));
                visited[neighbor] = true;
            }
        }
    }
    return need;
}

int main() {
    ll E; cin >> V >> E;
    vector<ll> power(V);
    for (ll i = 0; i < V; i++)
    {
        ll x; cin >> x;
        power[i] = x;
    }
    
    vector<vector<ll>> adj(V, vector<ll>());
    for (ll i = 0; i < E; ++i) {
        ll u, v; cin >> u >> v;
        v--; u--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 0; i < V; i++)
    {
        ll need = bfs(adj, i, power);
        cout << need << ' ';
    }
    cout << '\n';
    
    return 0;
}
