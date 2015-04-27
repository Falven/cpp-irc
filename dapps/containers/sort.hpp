#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename FwdIterator>
static void print_as_array(FwdIterator beg, FwdIterator end, const std::string & separator = ", ")
{
	std::cout << "[" << *beg;
	while (++beg < end)
		std::cout << separator << *beg;
	std::cout << "]" << std::endl;
}

// Orders a list of values by repeatedly putting the smallest or largest unplaced value into its final position.
template<typename FwdIterator, typename Comparator = std::less<typename std::iterator_traits<FwdIterator>::value_type>>
void sort_selection(FwdIterator beg, FwdIterator end, Comparator cmp = Comparator())
{
	FwdIterator min;
	for (; beg != end; ++beg)
	{
		min = std::min_element(beg, end, cmp);
		if (cmp(*min, *beg))
			std::iter_swap(min, beg);
	}
}

// Shift/bubble each element toward the front into a sorted sub-array
template<typename BdIterator, typename Comparator = std::less<typename std::iterator_traits<BdIterator>::value_type>>
void sort_insertion(BdIterator beg, BdIterator end, Comparator cmp = Comparator())
{
	BdIterator front, cur, prev;
	// Assume the first element is sorted.
	for (front = std::next(beg); front != end; ++front)
	{
		cur = front;
		prev = std::prev(cur);
		// Bubble the "next" element towards the front by swapping it with its 
		// "prev" neighbor until it is in its sorted position.
		while (cur != beg && cmp(*cur, *prev))
			std::iter_swap(cur--, prev--);
	}
}



template<typename BdIterator, typename Comparator = std::less<typename std::iterator_traits<BdIterator>::value_type>>
void sort_merge(BdIterator result_beg, BdIterator beg, BdIterator end, Comparator cmp = Comparator())
{
	typedef std::iterator_traits<BdIterator>::difference_type dt;
	dt size = std::distance(beg, end);
	if (size > dt(1))
	{
		BdIterator mid = beg + size / dt(2);

		sort_merge(beg, mid);
		sort_merge(mid, end);

		merge(result_beg, beg, mid, mid, end);
	}
}

template<typename BdIterator, typename Comparator>
static void merge(BdIterator result_beg, BdIterator left_beg, BdIterator left_end, BdIterator right_beg, BdIterator right_end, Comparator cmp)
{
	while (left_beg != left_end || right_beg != right_end)
	{
		if (left_beg == left_end || right_beg != right_end && cmp(*right_beg, *left_beg))
		{
			*result_beg = *right_beg;
			++right_beg;
		}
		else
		{
			*result_beg = *left_beg;
			++left_beg;
		}
		++result_beg;
	}
}

template<typename BdIterator, typename Comparator = std::less<typename std::iterator_traits<BdIterator>::value_type>>
void sort_merge(BdIterator beg, BdIterator end, Comparator cmp = Comparator())
{
	std::vector<std::iterator_traits<BdIterator>::value_type> result;
	sort_merge(result.begin(), beg, end);
	std::copy(result.begin(), result.end(), beg);
}