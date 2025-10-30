class Solution {
public:
    bool safe( vector<vector<int>>& diff,int newX,int newY,int curX,int curY,int row,int col) {
        if (newX >= 0 && newY >=0 && newX < row&&
            newY < col && diff[curX][curY] < diff[newX][newY]) {
            return true;
        } 
        else
            return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
      priority_queue< pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>> > mini;    //initilize-min-heap

        int row = heights.size();
        int col = heights[0].size();

        int desX = row - 1;
        int desY = col - 1;

        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));

        mini.push({0, {0, 0}});

        diff[0][0] = 0;

            while (!mini.empty()) {
            auto topPair = mini.top();
            int curdiff = topPair.first;
            pair<int, int> node = topPair.second;
                        mini.pop();


            int curX = node.first;
            int curY = node.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0 ,- 1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int newX = curX + dx[i];
                int newY = curY + dy[i];

                if (safe(diff,newX, newY,curX, curY,row,col)){
                    int newVal =
                        max(diff[curX][curY],
                            abs(heights[curX][curY]- heights[newX][newY]));
                           
                 diff[newX][newY] = min(newVal, diff[newX][newY]);
                    
                        mini.push({diff[newX][newY], {newX, newY}});
                }

            }
        }
        return diff[desX][desY];
        
    }
};
