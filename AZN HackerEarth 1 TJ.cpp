#include<bits/stdc++.h>

#define ll long long

using namespace std;
 
set<ll> st;
int prevAns = 0;

ll getOutput(ll N, ll X)
{
	if(st.find(X) != st.end())
	    return prevAns;
	
	st.insert(X);
	if (st.size() == 1) 
	{
		prevAns = (1 + N);
		return prevAns;
	}
	set<ll>::iterator it = st.find(X);
 
	if (it != st.begin())
	{
		if ((++it) != st.end())
		{
			it--;
			prevAns -= (*(++it) - 1); it--;
		}
		else
		{
			it--;
			prevAns -= N;
		}
		prevAns += (*it - 1);
	}
 
	if ((++it) != st.end()) 
	{
		it--;
		if (it != st.begin())
		{
			prevAns -= (*(--it) + 1); it++;
		}
		else
			prevAns -= 1;
		
		prevAns += (*it + 1);
	}
	else
		it--;
 
	if (it != st.begin())
	{
		prevAns += (*(--it) + 1); it++;
	}
	else
		prevAns += 1;
		
	if (++it != st.end())
	{
		it--;
		prevAns += (*(++it) - 1);
	}
	else
	{
		it--;
		prevAns += N;
	}
	return prevAns;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N, M, X;
    cin >> N >> M;
    while(M--)
	{
        cin>>X;
        ll out_;
        out_ = getOutput(N, X);
        cout<<out_<< endl;
    }
}
