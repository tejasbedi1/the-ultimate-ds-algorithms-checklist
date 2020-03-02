#include<bits/stdc++.h>
using namespace std;

set<long long> A;
int ans = 0;
long long getOutput (long long N, long long X) {
   if(A.find(X) != A.end())
	    return ans;
	
	A.insert(X);
	if (A.size() == 1) {
	    /*first insert*/
		ans = (1 + N); /*entire range*/
		return ans;
	}
	set<long long>::iterator it = A.find(X);
 
	/*remove the max of the range of prev element*/
	if (it != A.begin()) {
	    /*if there is a prev element*/
		if ((++it) != A.end()) {
			it--;
			ans -= (*(++it) - 1);
			it--;
		}
		else {
			it--;
			ans -= N;
		}
		/*add the new max*/
		ans += (*it - 1);
	}
 
	/*remove the min of the range of the next element*/
	if ((++it) != A.end()){
	    /*if there is a next element*/
		it--;
		if (it != A.begin()) {
			ans -= (*(--it) + 1);
			it++;
		}
		else ans -= 1;
		/*add the new min*/
		ans += (*it + 1);
	}
	else it--;
 
	/*add the range for the newly inserted element*/
	if (it != A.begin()){
		ans += (*(--it) + 1);
		it++;
	}
	else ans += 1;
	if (++it != A.end()){
		it--;
		ans += (*(++it) - 1);
	}
	else {
		it--;
		ans += N;
	}
	return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, M, X;
    cin >> N >> M;
    while(M--){
        cin >> X;
        long long out_;
        out_ = getOutput(N, X);
        cout << out_ << endl;
    }
}
