#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    int height = triangle.size();
    
    for (int i=1; i<height; i++) {
        for (int j=0; j<=i; j++) {
            triangle[i][j] += max(((j-1<0)?0:triangle[i-1][j-1]), ((j>i-1)?0:triangle[i-1][j]));
        }
    }
    
    int answer = *max_element(triangle[height-1].begin(), triangle[height-1].end());
    
    return answer;
}