#include <vector>
#include <cassert>
#include <memory>
#include <functional>
#include <cstdlib>
#include <dapps/containers/sort.hpp>
#include <boost/timer/timer.hpp>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::allocator;
using std::less;
using std::less_equal;
using boost::timer::auto_cpu_timer;

template<typename Func, typename Comp>
static void sort_test_small_uniques(const string & name, Func sort, Comp comparator)
{
    vector<int> orig{ 1, 8, 4, 6, 5, 2, 0, 3 }, soln{ 0, 1, 2, 3, 4, 5, 6, 8 };
    cout << "Testing " << name << " with small unique values.\n" << "Execution time:";
    {
        auto_cpu_timer t;
        sort(orig.begin(), orig.end(), comparator);
    }
    assert(orig == soln);
    cout << "Result: PASS\n" << endl;
}

template<typename Func, typename Comp>
static void sort_test_small_duplicates(const string & name, Func sort, Comp comparator)
{
    vector<int> orig{ 1, 4, 6, 5, 2, 0, 3, 0 }, soln{ 0, 0, 1, 2, 3, 4, 5, 6 };
    cout << "Testing " << name << " with duplicates.\n" << "Execution time:";
    {
        auto_cpu_timer t;
        sort(orig.begin(), orig.end(), comparator);
    }
    assert(orig == soln);
    cout << "Result: PASS\n" << endl;
}

template<typename Func, typename Comp>
static void sort_test_large_uniques(const string & name, Func sort, Comp comparator)
{
    vector<int> orig{ 1, 8, 4, 6, 5, 2, 0, 3 }, soln{ 0, 1, 2, 3, 4, 5, 6, 8 };
    cout << "Testing " << name << " with small unique values.\n" << "Execution time:";
    {
        auto_cpu_timer t;
        sort(orig.begin(), orig.end(), comparator);
    }
    assert(orig == soln);
    cout << "Result: PASS\n" << endl;
}

template<typename Func, typename Comp>
static void sort_test(const string & name, Func sort, Comp comparator)
{
    sort_test_small_uniques(name, sort, comparator);
    sort_test_small_duplicates(name, sort, comparator);
}

int main(int argc, const char * argv [])
{
    using iterator = vector<int>::iterator;

    sort_test("sort_selection", &sort_selection<iterator, less<int>>, less<int>());
    sort_test("sort_insertion", &sort_insertion<iterator, less<int>>, less<int>());
    sort_test("std::_Insertion_sort", &std::_Insertion_sort<iterator, less<int>>, less<int>());
    sort_test("sort_merge", &sort_merge<iterator, less<int>>, less<int>());
    sort_test("std::stable_sort", &std::stable_sort<iterator, less<int>>, less<int>());
    sort_test("sort_quick", &sort_quick<iterator, less_equal<int>>, less_equal<int>());
    sort_test("std::sort", &std::sort<iterator, less<int>>, less<int>());

	return 0;
}