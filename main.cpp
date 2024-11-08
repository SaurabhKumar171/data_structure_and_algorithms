#include <iostream>
#include <vector>
using namespace std;

void spiralOrderUsingRowChecks(vector<vector<int>>& matrix);

int main() {
      vector<vector<int>> arr = {
                    {50, 80, 30, 10, 60,7},
                    {7,8,9,3,4,8},
                    {5,6,7,8,9,0}
                  };

      spiralOrderUsingRowChecks(arr);
      return 0;
} 

