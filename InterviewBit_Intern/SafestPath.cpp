typedef pair<int, int> p;
int function(int A, vector<int>&B, vector<int>&C, vector<int>&D, vector<int>&E){
	vector<vector<pair<int, long double>>> adj[A];
	int m = B.size();
	for(int i = 0; i < m; i++){
		long double x = 1-(D[i]/E[i]);
		adj[B[i]-1].push_back(make_pair(C[i]-1, x));
		adj[C[i]-1].push_back(make_pair(B[i]-1, x));
	}
	vector<long double> dist(A, INT_MIN);
	priority_queue<p> pq;
	dist[0]=1;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		int u = pq.top().second; 
        pq.pop(); 
        for ( auto i : adj[u]) { 
            int v = i.first; 
            int wt = i.second; 
            if (dist[v] < dist[u]*wt)  { 
                dist[v] = dist[u] * wt; 
                pq.push(make_pair(dist[v], v)); 
            } 
	}
	int ans = 1000000;
	return ans * dist[A-1];
}
