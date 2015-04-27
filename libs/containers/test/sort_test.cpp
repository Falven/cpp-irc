#include <vector>
#include <cassert>
#include <memory>
#include <dapps\containers\sort.hpp>
#include <boost/timer/timer.hpp>

using std::vector;

int main(int argc, const char * argv [])
{
	vector<int> orig{ 1, 4, 5, 3, 2 }, soln{ 1, 2, 3, 4, 5 }, orig_dup{ 1, 4, 5, 3, 1 }, soln_dup{ 1, 1, 3, 4, 5 }, arr, arr_dup;

	std::cout << "Testing sort_selection: ";
	// No duplicates
	arr = orig;
	sort_selection(arr.begin(), arr.end());
	assert(arr == soln);
	// Duplicates
	arr_dup = orig_dup;
	sort_selection(arr_dup.begin(), arr_dup.end());
	assert(arr_dup == soln_dup);
	std::cout << "PASS" << std::endl;

	std::cout << "Testing sort_insertion: ";
	// No duplicates
	{
		vector<int> large;
		large.reserve(1000000);
		for (int i = 1000000; i > 0; --i)
		{
			large.push_back(i);
		}

		boost::timer::auto_cpu_timer t;
		sort_insertion(arr.begin(), arr.end());
	}
	//assert(arr == soln);
	// Duplicates
	//arr_dup = orig_dup;
	//sort_insertion(arr_dup.begin(), arr_dup.end());
	//assert(arr_dup == soln_dup);
	//std::cout << "PASS" << std::endl;

	std::cout << "Testing sort_merge: ";
	// No duplicates
	{
		vector<int> large;
		large.reserve(1000000);
		for (int i = 1000000; i > 0; --i)
		{
			large.push_back(i);
		}

		boost::timer::auto_cpu_timer t;
		sort_merge(arr.begin(), arr.end());
	}
	//assert(arr == soln);
	//// Duplicates
	//arr_dup = orig_dup;
	//sort_merge(arr_dup.begin(), arr_dup.end());
	//assert(arr_dup == soln_dup);
	//std::cout << "PASS" << std::endl;

	return 0;
}