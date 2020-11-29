#include<iostream>
#include<vector>
#include<algorithm>
#include<execution>

#include <chrono> 

using namespace std;
using namespace std::chrono;

int main() {

	std::vector<int> v;
	v.reserve(100001);
	for (int it = 0; it < 100000; it++) {
		v.push_back(rand());
	}
	
	

	auto start = high_resolution_clock::now();     //start

	std::sort(std::execution::par, v.begin(), v.end());
	//std::sort(v.begin(), v.end());
	//for (auto elm : v) {
	//	cout << elm << " ";
	//}

	//cout << endl;

	auto stop = high_resolution_clock::now();   //stop
	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;

	return 0;
}