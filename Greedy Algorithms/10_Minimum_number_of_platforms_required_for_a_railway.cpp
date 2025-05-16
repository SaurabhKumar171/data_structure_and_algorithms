// Brute force approach
class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int n = Arrival.size();
        int maxCnt = 1;

        for(int i = 0; i < n; i++){
            int cnt = 1;

            for(int j = 0; j < n; j++){
                if(i != j){
                    if((Arrival[i] >= Arrival[j] && Departure[j] >= Arrival[i])){
                        cnt++;
                    }
                    maxCnt = max(maxCnt, cnt);
                }
            }
        }

        return maxCnt;
    }
};

// Optimal approach
class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int n = Arrival.size();
        int maxCnt = 1;
        int cnt = 0;

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());


        int arrPointer = 0, depPointer = 0;

        while(arrPointer < n){
            if(Arrival[arrPointer] <= Departure[depPointer]){
                arrPointer++;
                cnt++;
            }
            else{
                depPointer++;
                cnt--;
            }

            maxCnt = max(maxCnt, cnt);
        }


        return maxCnt;
    }
};