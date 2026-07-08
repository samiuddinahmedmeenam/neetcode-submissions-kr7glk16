class Solution {
public:

unordered_map<int, vector<int>> prereq;
unordered_set<int> visited;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i<numCourses; i++){
            prereq[i] = {};
        }

        for(int i = 0; i<prerequisites.size();i++){
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i<numCourses; i++){
            if(!dfs(i, numCourses)){
                return false;
            }
        }

        return true;
    }


    bool dfs(int i, int& numCourses){

        if(visited.count(i)){
            return false;
        }

        if(prereq[i].empty()){
            return true;
        }

        visited.insert(i);
        for(auto x: prereq[i]){
            if(!dfs(x, numCourses)){
                return false;
            }
        }

        visited.erase(i);
        prereq[i].clear();
        return true;
    }
};
