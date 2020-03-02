#include<bits/stdc++.h>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;
 
vi GreaterEqual (vi A, vi X, vi u, vi L, vi v) 
{
  	int N = A.size();
	vvi gph(N);
	for (int i = 1; i < N; i++)
	{
		int _u = u[i] - 1;
		int _v = v[i] - 1;
		gph[_u].push_back(_v);
		gph[_v].push_back(_u);
	}
 
	vvi sortedLevels;
	queue<int> q; 
	q.push(0); 
	int maxDepth = -1;
	vector<bool> visited(N, false);
	while (!q.empty())
	{
		maxDepth++;
		vi levelValues;
		vi leveNodes;
		while (!q.empty())
		{
			leveNodes.push_back(q.front());
			levelValues.push_back(A[q.front()]);
			q.pop();
		}
		sort(levelValues.begin(), levelValues.end());
		sortedLevels.push_back(levelValues);
		for (int i = 0; i < levelValues.size(); i++)
		{
			int u = leveNodes[i];
			visited[u] = true;
			for (int j = 0; j < gph[u].size(); j++)
				if (!visited[gph[u][j]])
					q.push(gph[u][j]);
		}
	}
	
	int Q = L.size();
	vi ans(Q, -1);
	for (int q = 0; q < Q; q++)
	{
		int l = L[q] % (maxDepth + 1);
		int x = X[q];
		int idx = lower_bound(sortedLevels[l].begin(), sortedLevels[l].end(), x) - sortedLevels[l].begin();
		if (idx < sortedLevels[l].size())
			ans[q] = sortedLevels[l][idx];
	}
	return ans;
}
 
int main() 
{
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }
    vi u(N), v(N);
    for(int i_u=1; i_u<N; i_u++)
    {
    	cin >> u[i_u] >> v[i_u];
    }
    vi L(Q), X(Q);
    for(int i_L=0; i_L<Q; i_L++)
    {
    	cin >> L[i_L] >> X[i_L];
    }
    vi out_;
    out_ = GreaterEqual(A, X, u, L, v);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << "\n" << out_[i_out_];
    }
}
