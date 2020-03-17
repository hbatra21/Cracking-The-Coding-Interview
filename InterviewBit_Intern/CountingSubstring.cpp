#include <bits/stdc++.h>
using namespace std;

int findSubs(string s)
{
	int count = 0;
	unordered_set < char > hset;
	for (auto itr1 = s.begin(); itr1 != s.end(); itr1++) {
		hset.clear();
		for (auto itr2 = itr1 + 1; itr2 != s.end(); itr2++) {
			if ( *itr1 == *itr2 && hset.size() < 2) {
				count++;
			}
			hset.insert(*itr2);
			if (hset.size() > 1) {
				break;
			}
		}
	}

	return count;
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		string s;
		cin>>s;
		cout<<findSubs(s)<<endl;
		test--;
	}
}
