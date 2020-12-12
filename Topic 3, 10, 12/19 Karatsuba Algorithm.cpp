#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

string addZeroToFront(string t, int i)
{
	string newStr;
	while (i-- > 0)
		newStr.push_back('0');
	newStr.append(t);
	return newStr;
}

string powerOfTen (string t, int i)
{
	if (t == "0")
		return "0";
		
	string newStr;
	newStr.append(t);
	while (i-- > 0)
		newStr.push_back('0');
	return newStr;
}

string multiply(string a, string b)
{
	string newStr;
	int i,j;
	int carry;
	if (a.size() == 1 && b.size() == 1)
	{
		i = a[0]-'0';
		j = b[0]-'0';
		i = i*j;

		newStr = to_string(i);
		/*
		if (i >= 10)
		{
			newStr = to_string(i);
		}
		else
		{
			newStr = to_string(i);
		}
		*/
	}
	else
	{
		debug (1, "NOT POSSIBLE\n");
	}
	debug (3, "Calc'ed multi: (", a[0], ",", b[0], ") = ", newStr, "\n");
	return newStr;
}

string addition(string a, string b)
{
	int i;
	int j;
	int n;
	int s;
	int carry;
	char temp;
	string sum;

	carry = 0;
	int na = a.size();
	int nb = b.size();
	
	if (na > nb)
	{
		n = na;
		b = addZeroToFront(b, na-nb);
	}
	else if (nb > na)
	{
		n = nb;
		a = addZeroToFront(a, nb-na);
	}
	else
		n = na;
			
	for (i=n-1; i>=0; i--)
	{
		s = (a[i]-'0') + (b[i]-'0') + carry;
		if (s > 9)
		{
			if (s > 19)	
			{
				carry = 2;
				s = s - 20;
				sum.append( to_string(s) );
			}
			else
			{
				carry = 1;
				s = s - 10;
				sum.append( to_string(s) );
			}
		}
		else
		{
			sum.append( to_string(s) );
			carry = 0;
		}
	}
		
	j = n-1;
	for (i=0; i<n/2; i++,j--)
	{
		temp = sum[i];
		sum[i] = sum[j];
		sum[j] = temp;
	}
	
	debug (3, "Adding: (", a, ",", b, ") =  ", sum, "\n");
	return sum;
}

bool eligibleForFurtherDivision(string &a, string &b)
{
	if (a.size() == 1 || b.size() == 1)
		return false;
	return true;
}

template <class T>
string karatsuba (T x, T y)
{
	debug (2, "\nKaratsuba...\n");
	int na = x.size();
	int nb = y.size();
	// Make size even if odd
	if ( na & 1 == 1) 
	{
		x = addZeroToFront(x, 1);
		na++;
		y = addZeroToFront(y, 1);
		nb++;
	}
	debug (2, "After even'ing out: x, y: ", x, ",", y, "\n");
	
	// x.y = 10^n x a x c  +  10^n/2 x (a x d + b x c) + b x d
	int n = na;
	int nhalf = na/2;
	
	string a = x.substr(0, nhalf);
	string b = x.substr(nhalf, nhalf);
	string c = y.substr(0, nhalf);
	string d = y.substr(nhalf, nhalf);
	
	debug (2, "a, b: ", a, ",", b, "\n");
	debug (2, "c, d: ", c, ",", d, "\n");
	
	string ans;
	string temp1, temp2;
	//ans.clear();
	
	// 10^n x a x c
	temp1.clear();
	if ( eligibleForFurtherDivision(a, c) == true)
		temp1 = karatsuba(a, c);
	else
		temp1 = multiply(a, c);
	temp1 = powerOfTen(temp1, n); 
	
	ans = temp1;
	
	// 10^n/2 x (a x d + b x c)
	temp1.clear();
	temp2.clear();
	if ( eligibleForFurtherDivision(a, d) == true)
		temp1 = karatsuba(a, d);
	else
		temp1 = multiply(a, d);
	
	if ( eligibleForFurtherDivision(b, c) == true)
		temp2 = karatsuba(b, c);
	else
		temp2 = multiply(b, c);
	
	temp1 = addition(temp1, temp2);
	temp1 = powerOfTen(temp1, n/2); 
	
	ans = addition(ans, temp1);
	
	// b x d
	temp1.clear();
	if ( eligibleForFurtherDivision(b, d) == true)
		temp1 = karatsuba(b, d);
	else
		temp1 = multiply(b, d);
	
	ans = addition(ans, temp1);
	
	debug (2, "Intermediate Ans: ", ans, "\n");	
	return ans;
}

void solve(string &a, string &b)
{
	int na = a.size();
	int nb = b.size();
	
	debug (2, "In Focus: a, b: ", a, ",", b, "\n");
	debug (2, "Size: a, b: ", na, ",", nb, "\n");
	
	// Make equal size
	if (na > nb)
	{
		b = addZeroToFront(b, na-nb);
		//na = nb;
	}	
	else if (nb < na)
	{
		a = addZeroToFront(a, nb-na);
		//nb = na;
	}
	debug (2, "After mathcing sizes: a, b: ", a, ",", b, "\n");
	
	string ans = karatsuba (a, b);
	debug (1, "ANS: ", ans, "\n");
}

int main()
{	
	// D & C
	
	// Resource
	// FOR BINARY
	// https://www.geeksforgeeks.org/karatsuba-algorithm-for-fast-multiplication-using-divide-and-conquer-algorithm/
	// FOR DECIMAL
	// https://media.geeksforgeeks.org/wp-content/uploads/schoolMultiply.jpg
	//
	// Brilliant In depth: https://brilliant.org/wiki/karatsuba-algorithm/
	// YT GOOD https://www.youtube.com/watch?v=JCbZayFr9RE
	
	// COMPLEXITY 
	// Calculation is a little complicated checkout brilliant
	// O(n^1.585)
	
	// BTW
	// LONG MAX = 9,223,372,036,854,775,807
	
	LOG_LEVEL = 1;
	
	// Ex 1
	//string a = "5678";
	//string b = "1234";
	
	// EX2 
	//string a = "56789";
	//string b = "1234";
	
	// Ex3 
	//string a = "56789";
	//string b = "1";
	
	// Ex4
	string a = "999999999999999999999999999999999999999999999999999999999999999999999999";
	string b = "888888888888777777777777666666666666888888888888777777777777666666666666";
	
	debug (1, "Q: ", a, " x ", b, "\n");
	solve(a, b);
}
