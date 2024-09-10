class SolutionTwoForLoop {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < n-1; i++){

            int minId = i;

            for(int j = i; j < n; j++){

                if(nums[j] < nums[minId]){
                    minId = j;
                }

            }

            if(minId != i){
                swap(nums[minId], nums[i]);
            }
        }

        return nums;
    }
};


class SolutionRecursive {
public:
    vector<int> selectionSort(vector<int>& nums) {

        select(nums, 0, nums.size());
        return nums;
    }

public:
    int select(vector<int>& arr, int i, int n)
    {
        if(i == n-1){
            return 0;
        }
        
        int minId = i;
        
        for(int start = i; start < n; start++){
            
            if(arr[start] < arr[minId]){
                minId = start;
            }
        }
        
        swap(arr[i], arr[minId]);
        
        select(arr, i+1, n);
    }
};