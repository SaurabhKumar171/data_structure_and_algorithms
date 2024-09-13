class Solution {
public:
    // Function to partition the array
    int partition(vector<int>& arr, int low, int high) {

        // Choosing the first element as pivot
        int pivot = arr[low];
        // Starting index for left subarray
        int i = low;
        // Starting index for right subarray
        int j = high;

        while (i < j) {
            /*  Move i to the right until we find an
                element greater than the pivot  */
            while (arr[i] <= pivot && i <= high - 1) {
                i++;
            }
            /*  Move j to the left until we find an
                element smaller than the pivot  */
            while (arr[j] > pivot && j >= low + 1) {
                j--;
            }
            /*  Swap elements at i and j if i is still
                less than j  */
            if (i < j) swap(arr[i], arr[j]);
        }
        
        // Pivot placed in correct position
        swap(arr[low], arr[j]);
        return j;
    }

    // Helper Function to perform the recursive quick sort
    void quickSortHelper(vector<int>& arr, int low, int high) {
        /*  Base case: If the array has one or no
            elements, it's already sorted  */
        if (low < high) {
            // Get the partition index
            int pIndex = partition(arr, low, high);
            // Sort the left subarray
            quickSortHelper(arr, low, pIndex - 1);
            // Sort the right subarray
            quickSortHelper(arr, pIndex + 1, high);
        }
    }
    
    // Function to perform quick sort on given array
    vector<int> quickSort(vector<int>& nums) {
        // Get the size of array
        int n = nums.size();
        
        // Perfrom quick sort
        quickSortHelper(nums, 0, n-1);
        
        // Return sorted array
        return nums;
    }
};
