#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

// Orders a list of values by repeatedly putting the smallest or largest unplaced value into its final position.
template<typename FwdIterator, typename Comparator = std::less<typename std::iterator_traits<FwdIterator>::value_type>>
void sort_selection(FwdIterator beg, FwdIterator end, Comparator cmp = Comparator())
{
    using category = typename std::iterator_traits<FwdIterator>::iterator_category;
    static_assert(std::is_base_of<std::bidirectional_iterator_tag, category>::value, "This algorithm requires forward iterators.");

    FwdIterator min;
    for (; beg != end; ++beg)
    {
        min = std::min_element(beg, end, cmp);
        if (cmp(*min, *beg))
            std::iter_swap(min, beg);
    }
}

// Shift/bubble each element toward the front into a sorted sub-array
template<typename BidirIt, typename Comparator = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void sort_insertion(BidirIt first, BidirIt last, Comparator cmp = Comparator())
{
    using category = typename std::iterator_traits<BidirIt>::iterator_category;
    static_assert(std::is_base_of<std::bidirectional_iterator_tag, category>::value, "This algorithm requires bidirectional iterators.");

    // 1 element containers are sorted; 2 duplicate element containers are sorted.
    if (first != last)
    {
        // Make a hole by removing the element you are checking,
        // and move elements up to that hole until you find the correct position of the element removed.
        // ++cur: Assume the first element is sorted.
        for (BidirIt cur = first; ++cur != last;)
        {
            auto val = std::move(*cur);
            BidirIt next = cur, prev = std::prev(next);
            while (cmp(val, *prev))
            {
                *next = std::move(*prev);
                next = prev;
                if (prev != first) --prev;
                else break;
            }
            // insert value in its sorted hole.
            *next = std::move(val);
        }
    }
}

template<typename BidirIt, typename Comparator = std::less<typename std::iterator_traits<BidirIt>::value_type>>
static void divide_and_merge_range(BidirIt first, BidirIt last, BidirIt buffer, Comparator cmp = Comparator())
{
    using diff_type = typename std::iterator_traits<BidirIt>::difference_type;
    diff_type size = std::distance(first, last);
    if (size > diff_type(1u))
    {
        BidirIt mid = std::next(first, size / diff_type(2));

        // Divide operation.
        divide_and_merge_range(first, mid, buffer, cmp);
        divide_and_merge_range(mid, last, buffer, cmp);

        // Merge operation begins here.
        std::move(first, last, buffer);

        BidirIt left_begin = buffer, left_end = std::next(left_begin, std::distance(first, mid));
        BidirIt right_begin = left_end, right_end = std::next(right_begin, std::distance(mid, last));

        auto out = first;
        while (left_begin != left_end || right_begin != right_end)
            *out++ = std::move(right_begin == right_end || (left_begin != left_end && cmp(*left_begin, *right_begin)) ? *left_begin++ : *right_begin++);
    }
}

template<typename BidirIt, typename Comparator = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void sort_merge(BidirIt first, BidirIt last, Comparator cmp = Comparator())
{
    using category = typename std::iterator_traits<BidirIt>::iterator_category;
    static_assert(std::is_base_of<std::bidirectional_iterator_tag, category>::value, "This algorithm requires bidirectional iterators.");

    auto size = std::distance(first, last);
    std::vector<typename std::iterator_traits<BidirIt>::value_type> out;
    out.reserve(size);
    out.resize(size);
    divide_and_merge_range(first, last, out.begin(), cmp);
}

template<typename BidirIt, typename Comparator = std::less_equal<typename std::iterator_traits<BidirIt>::value_type>>
void sort_quick(BidirIt first, BidirIt last, Comparator cmp = Comparator())
{
    using category = typename std::iterator_traits<BidirIt>::iterator_category;
    static_assert(std::is_base_of<std::bidirectional_iterator_tag, category>::value, "This algorithm requires bidirectional iterators.");

    using diff_type = typename std::iterator_traits<BidirIt>::difference_type;
    diff_type size = std::distance(first, last);
    // Arrays of 0 or 1 elements are considered sorted.
    if (size > diff_type(1u))
    {
        auto pivot = std::next(first, size / diff_type(2u));
        // Last usually points to end, rather than the last element.
        auto left = first, right = std::prev(last);
        // Until both left and right point to the same element (always going to be the pivot).
        while (left != right)
        {
            auto pivot_val = *pivot;
            while (left != pivot && cmp(*left, pivot_val)) ++left;
            while (right != pivot && cmp(pivot_val, *right)) --right;
            if (left != right)
            {
                std::iter_swap(left, right);
                if (pivot == left)
                    pivot = right;
                else
                    if (pivot == right) pivot = left;
            }
        }
        // Recursive call on each partititon.
        sort_quick(first, pivot);
        sort_quick(std::next(pivot), last);
    }
}

template<typename BidirIt, typename Comparator = std::less_equal<typename std::iterator_traits<BidirIt>::value_type>>
void sort_tim(BidirIt first, BidirIt last, Comparator cmp = Comparator())
{
    using category = typename std::iterator_traits<BidirIt>::iterator_category;
    static_assert(std::is_base_of<std::bidirectional_iterator_tag, category>::value, "This algorithm requires bidirectional iterators.");

    using diff_type = typename std::iterator_traits<BidirIt>::difference_type;
    diff_type size = std::distance(first, last);
    diff_type min_run(64u);
}