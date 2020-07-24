class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> paths;
		vector<int> path;

		backtracking(graph, paths, path, 0, graph.size() - 1);

		return paths;
    }

private:
	void backtracking(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int pos, int des) {
		path.emplace_back(pos);
		if(pos == des)
		{
			paths.emplace_back(path);
		}
		else
		{
			for(int& node : graph[pos])
			{
				backtracking(graph, paths, path, node, des);
			}
		}
		path.pop_back();
	}
};
