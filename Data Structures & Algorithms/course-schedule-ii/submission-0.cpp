class Solution {
   public:
    unordered_map<int, vector<int>> prereq;
    unordered_set<int> cycle;
    unordered_set<int> visited;
    vector<int> output;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            prereq[i] = {};
        }

        for (auto x : prerequisites) {
            prereq[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return {};
            }
        }

        return output;
    }


    bool dfs(int course){
        if(cycle.count(course)){
            return false;
        }

        if(visited.count(course)){
            return true;
        }

        cycle.insert(course);
        if(prereq.count(course)){
            for(auto x: prereq[course]){
                if(!dfs(x)){
                    return false;
                }
            }
        }

        cycle.erase(course);
        visited.insert(course);
        output.push_back(course);
        return true;
    }
};
