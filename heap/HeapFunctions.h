#pragma once

template< class RandomIt >
void heapify(RandomIt first, RandomIt last, int i, size_t size) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && *(first + left) > *(first + largest)) {
    largest = left;
  }
  if (right < size && *(first + right) > *(first + largest)) {
    largest = right;
  }
  if (largest != i) {
    std::swap(*(first + i), *(first + largest));
    heapify(first, last,largest, size);
  }
}

template < class RandomIt, class Compare >
void lowerDown(RandomIt first, RandomIt last, RandomIt root, Compare comp) {
  auto size = std::distance(first, last);
  auto new_root = std::distance(first, root);

  while (2 * new_root + 1 < size) {
    auto left = 2 * new_root + 1;
    auto right = 2 * new_root + 2;
    auto largest = new_root;

    if (left < size && comp(*(first + largest), *(first + left))) {
      largest = left;
    }
    if (right < size && comp(*(first + largest), *(first + right))) {
      largest = right;
    }

    if (largest != new_root) {
      std::iter_swap(first + new_root, first + largest);
      new_root = largest;
    }
    else {
      break;
    }
  }
}

template< class RandomIt >
void makeHeap(RandomIt first, RandomIt last) {
  auto size = std::distance(first, last);

  for (int i = (size - 1) / 2; i >= 0; --i) {
    heapify(first, last, i, size);
  }
}

template < class RandomIt, class Compare >
void makeHeap(RandomIt first, RandomIt last, Compare comp) {
  auto size = std::distance(first, last);

  for (auto start = size / 2 - 1; start >= 0; --start) {
    lowerDown(first, last, first + start, comp);
  }
}

template< class RandomIt >
void popHeap(RandomIt first, RandomIt last) {
  std::iter_swap(first, --last);
  makeHeap(first, last);
}

template < class RandomIt, class Compare >
void popHeap(RandomIt first, RandomIt last, Compare comp) {
  if (first == last || std::distance(first, last) < 2) return;

  std::iter_swap(first, last - 1);
  lowerDown(first, last - 1, first, comp);
}

template< class RandomIt >
void pushHeap(RandomIt first, RandomIt last) {
  RandomIt child = --last;
  RandomIt parent = first + (child - first - 1) / 2;

  while (child > first && *parent < *child) {
    std::iter_swap(parent, child);
    child = parent;
    parent = first + (child - first - 1) / 2;
  }
}

template < class RandomIt, class Compare >
void pushHeap(RandomIt first, RandomIt last, Compare comp) {
  auto size = std::distance(first, last);
  auto child = size - 1;
  auto parent = (child - 1) / 2;

  while (child > 0 && comp(*(first + parent), *(first + child))) {
    std::iter_swap(first + parent, first + child);
    child = parent;
    parent = (child - 1) / 2;
  }
}