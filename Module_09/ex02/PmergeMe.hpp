#pragma once

#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe& operator=(const PmergeMe& src);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();

		// vector
		static void insertionSortVector(std::vector<int>& container, int start, int end);
		static void mergeSortVector(std::vector<int>& container, int start, int mid, int end);
		static void mergeInsertionSortVector(std::vector<int>& container, int start, int end);

		// deque
		static void insertionSortDeque(std::deque<int>& container, int start, int end);
		static void mergeSortDeque(std::deque<int>& container, int start, int mid, int end);
		static void mergeInsertionSortDeque(std::deque<int>& container, int start, int end);
};

// utilities
int		getMidPoint(int start, int end);
void	printContainers(std::vector<int> &, std::deque<int> &, bool is_before);
void	executeSortAndGetTime(std::vector<int> &, std::deque <int> &, double &, double &);
