#include <iostream>;
using namespace std;
#include <vector>;

int binarySearch2(int nums[], int n, int target, bool searchFirst) {
  int i = 0;
  int j = n - 1;

  int result = -1;

  while (i <= j) {
    int m = i + (j - i) / 2;

    if (nums[m] == target) {
      result = m;
      if (searchFirst) {
        j = m - 1;
      } else {
        i = m + 1;
      }
    } else if (nums[m] > target) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return result;
}

int count(int arr[], int n, int x) {
  // code here
  int firtsOccurence = binarySearch(arr, n, x, true);
  int secondOccurence = binarySearch(arr, n, x, false);

  // cout << "firtsOccurence" <<firtsOccurence;
  // cout << "secondOccurence" <<secondOccurence;

  if (firtsOccurence == -1 && secondOccurence == -1) {
    return 0;
  }

  return (secondOccurence - firtsOccurence) + 1;
}