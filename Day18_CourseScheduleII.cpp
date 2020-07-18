class Solution {
typedef vector<vector<int>> graph;
typedef vector<int> degrees;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> order;
		graph&& g = buildGraph(numCourses, prerequisites);
		degrees&& inDegrees = calculateIndegrees(g);
		queue<int> q;
		for(int i = 0; i < inDegrees.size(); i += 1)
		{
			if(inDegrees[i] == 0) q.emplace(i);
		}
		while(!q.empty())
		{
			int inx = q.front();
			q.pop();
			order.emplace_back(inx);
			for(int& i : g[inx])
			{
				inDegrees[i] -= 1;
				if(inDegrees[i] == 0) q.emplace(i);
			}
		}
		for(int& in : inDegrees)
		{
			if(in != 0) return vector<int>();
		}
		return order;
    }

private:
	graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
		graph g(numCourses);
		for(vector<int>& p : prerequisites)
		{
			g[p[1]].emplace_back(p[0]);
		}
		return g;
	}

	degrees calculateIndegrees(graph& g) {
		degrees inDegrees(g.size(), 0);
		for(vector<int>& edges : g)
		{
			for(int& edge : edges)
			{
				inDegrees[edge] += 1;
			}
		}
		return inDegrees;
	}
};
