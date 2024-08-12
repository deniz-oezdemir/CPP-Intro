#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this == &src) {
		return *this;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe& src){
	(void)(src);
}

PmergeMe::~PmergeMe(){
}


// vector

void PmergeMe::insertionSortVector(std::vector<int> &container, int start, int end) {
	for (int curr = start + 1; curr <= end; curr++) {
		int nbr = container[curr];
		int prev = curr - 1;
		while (prev >= start && container[prev] > nbr) {
			container[prev + 1] = container[prev];
			prev--;
		}
		container[prev + 1] = nbr;
	}
}

void PmergeMe::mergeSortVector(std::vector<int> &container, int start, int mid, int end) {
	// Create temporary vectors to store the left and right subarrays
	std::vector<int> left(container.begin() + start, container.begin() + mid + 1);
	std::vector<int> right(container.begin() + mid + 1, container.begin() + end + 1);
	unsigned long i = 0, j = 0, k = start;
	// Merge sort the two subarrays into the original container
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	// Copy the remaining elements of left and right if any
	while (i < left.size())
		container[k++] = left[i++];
	while (j < right.size())
		container[k++] = right[j++];
}

void PmergeMe::mergeInsertionSortVector(std::vector<int> &container, int start, int end) {
	if (start < end) {
		// If the number of elements is less than 12, use insertion sort
		if ((end - start) < 12) {
			insertionSortVector(container, start, end);
		} else {
			// Divide the array into two halves and recursively sort them
			int mid = getMidPoint(start, end);
			mergeInsertionSortVector(container,  start, mid);
			mergeInsertionSortVector(container, (mid + 1), end);
			// Merge sort the halves
			mergeSortVector(container, start, mid, end);
		}
	}
}


// deque

void PmergeMe::insertionSortDeque(std::deque<int> &container, int start, int end) {
	for (int curr = start + 1; curr <= end; curr++) {
		int nbr = container[curr];
		int prev = curr - 1;
		while (prev >= start && container[prev] > nbr) {
			container[prev + 1] = container[prev];
			prev--;
		}
		container[prev + 1] = nbr;
	}
}

void PmergeMe::mergeSortDeque(std::deque<int> &container, int start, int mid, int end) {
	std::deque<int> left(container.begin() + start, container.begin() + mid + 1);
	std::deque<int> right(container.begin() + mid + 1, container.begin() + end + 1);
	unsigned long i = 0, j = 0, k = start;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while (i < left.size())
		container[k++] = left[i++];
	while (j < right.size())
		container[k++] = right[j++];
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &container, int start, int end){
	if (start < end) {
		if ((end - start) < 12)
			insertionSortDeque(container, start, end);
		else {
			int mid = getMidPoint(start, end);
			mergeInsertionSortDeque(container, start, mid);
			mergeInsertionSortDeque(container, (mid + 1), end);
			mergeSortDeque(container, start, mid, end);
		}
	}
}


// utilities

int getMidPoint(int start, int end) {
	return(start + (end - start) / 2);
}

void printContainers(std::vector<int> &vector, std::deque<int> &deque, bool is_before) {
	if (is_before)
		std::cout << "Vector "  << "before:\t";
	else
		std::cout << "Vector "<< "after:\t";

	std::vector<int>::const_iterator vIt;
	for (vIt = vector.begin(); vIt != vector.end(); ++vIt)
		std::cout << *vIt << " ";
	std::cout << std::endl << std::endl;

	if (is_before)
		std::cout << "Deque " << " before:\t" ;
	else
		std::cout << "Deque "  << " after:\t";
	std::deque<int>::const_iterator dIt;
	for (dIt = deque.begin(); dIt != deque.end(); ++dIt)
		std::cout << *dIt << " ";
	std::cout << std::endl;
}

void executeSortAndGetTime(std::vector<int> &Vcontainer, std::deque<int> &Dcontainer,double &vecTime, double &deqTime) {
	std::clock_t start = std::clock();
	PmergeMe::mergeInsertionSortVector(Vcontainer, 0, Vcontainer.size() - 1);
	std::clock_t end = std::clock();
	vecTime = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);

	start = std::clock();
	PmergeMe::mergeInsertionSortDeque(Dcontainer, 0, Dcontainer.size() - 1);
	end = std::clock();
	deqTime = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
}
