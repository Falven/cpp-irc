#include <vector>

template<typename T>
void sort_merge(std::vector<T> arr)
{

}

template<typename T>
static void merge(std::vector<T> left, std::vector<T> right)
{

}

//                         [3, 2, 1, 4, 5]
//		           [3, 2, 1]             [4, 5]
//			  [3, 2]       [1]         [4]    [5]
//			  [3]    [2]   [1]         [4]    [5]
//			  [2, 3]       [1]         [4]    [5]
//			  [1, 2, 3]                  [4, 5]
//			            [1, 2, 3, 4, 5]