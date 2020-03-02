#include<bits/stdc++.h>

#define vc vector<vector<int>>
#define va vector<int>

using namespace std;

vector<int> GreaterEqual (va A, va X, va u, va L, va v) 
{
    int N = A.size();
    vc tree(N);
	for (int i = 1; i < N; i++){
		int t1 = u[i] - 1;
		int t2 = v[i] - 1;
		tree[t1].push_back(t2);
		tree[t2].push_back(t1);
	}
 
	vc steps;
	queue<int> q;
	q.push(0);
	int maxDepth = -1;
	vector<bool> visited(N, false);
	while (!q.empty()){
		maxDepth++;
		va vals;
		va nodes;
		while (!q.empty()){
			nodes.push_back(q.front());
			vals.push_back(A[q.front()]);
			q.pop();
		}
		sort(vals.begin(), vals.end());
		steps.push_back(vals);
		for (int i = 0; i < vals.size(); i++){
			int u = nodes[i];
			visited[u] = true;
			for (int j = 0; j < tree[u].size(); j++)
				if (!visited[tree[u][j]])
					q.push(tree[u][j]);
		}
	}
	
	int Q = L.size();
	va ans(Q, -1);
	for (int q = 0; q < Q; q++){
		int l = L[q] % (maxDepth + 1);
		int x = X[q];
		int idx = lower_bound(steps[l].begin(), steps[l].end(), x) - steps[l].begin();
		if (idx < steps[l].size())
			ans[q] = steps[l][idx];
	}
	
	return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    va A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }
    va u(N), v(N);
    for(int i_u=1; i_u<N; i_u++)
    {
    	cin >> u[i_u] >> v[i_u];
    }
    va L(Q), X(Q);
    for(int i_L=0; i_L<Q; i_L++)
    {
    	cin >> L[i_L] >> X[i_L];
    }
    va out_;
    out_ = GreaterEqual(A, X, u, L, v);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << "\n" << out_[i_out_];
    }
}
