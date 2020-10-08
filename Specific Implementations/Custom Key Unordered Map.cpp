#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

using ll = long long; // Just for the FAST example 

// FASTEST METHOD: Begin
// This approch is adapted from the Boost Library

template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) 
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) 
{
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) 
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) 
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash 
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const 
	{
        return hash_val(p.first, p.second);
    }
};

// FASTEST METHOD: End
// 

struct Data
{
	int f;
	int l;
	
	Data(int a, int b)
	{
		f = a;
		l = b;
	}
	
	// In case of collision
	bool operator ==(const Data &d) const
	{
		return f == d.f && l == d.l;
	}
};


// with struct 
struct hash_struct
{
	size_t operator()(const Data &d) const
	{
		auto hash1 = hash<int>{}(d.f);
		auto hash2 = hash<int>{}(d.l);
		return hash1 ^ hash2;
	}
};

void withStruct()
{
	unordered_map <Data, int, hash_struct > uMap;
	
	uMap.insert (make_pair( Data(1,2), 100 ));
	uMap.insert (make_pair( Data(1,3), 200 ));
	uMap.insert (make_pair( Data(1,4), 300 ));
	
	debug (1, uMap.find( Data(1,3) )->second, "\n");
	
	for (auto it : uMap)
	{
		debug (1, "(", it.first.f, ",", it.first.l, ") ", it.second, "\n");
	}
}

// With pair 
struct hash_pair
{
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

void withpair()
{
	unordered_map <pair<int, int>, int, hash_pair > uMap;
	
	uMap.insert (make_pair( make_pair(1,2), 100 ));
	uMap.insert (make_pair( make_pair(1,3), 200 ));
	uMap.insert (make_pair( make_pair(1,4), 300 ));
	
	debug (1, uMap.find( make_pair(1,2) )->second, "\n");
	
	for (auto it : uMap)
	{
		debug (1, "(", it.first.first, ",", it.first.second, ") ", it.second, "\n");
	}
}

void withFASTBOOST()
{
	unordered_map<pair<ll, ll>, ll, pair_hash> uMap;
    //unordered_set<pair<ll, ll>, pair_hash> seen;	
    
    uMap.insert (make_pair( make_pair(1,2), 100 ));
	uMap.insert (make_pair( make_pair(1,3), 200 ));
	uMap.insert (make_pair( make_pair(1,4), 300 ));
	
	debug (1, uMap.find( make_pair(1,2) )->second, "\n");
	
	for (auto it : uMap)
	{
		debug (1, "(", it.first.first, ",", it.first.second, ") ", it.second, "\n");
	}
    
}

int main()
{	
	// RESOURCES 
	// https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-user-defined-class-in-cpp/
	// https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/
	
	// PLEASE NOTE 
	// Currently we are using an XOR for our hash funcions 
	// Technically its not considered very fast
	// There exists another implementation, borrowed from c++ lib boost
	// That has a faster approach
	// https://youngforest.github.io/2020/05/27/best-implement-to-use-pair-as-key-to-std-unordered-map-in-C/
	
	LOG_LEVEL = 3;
	
	withpair();
	withStruct();
	withFASTBOOST();
}
