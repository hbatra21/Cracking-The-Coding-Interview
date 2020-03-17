int function(vector<int>&v){
	set<int> s;
	for(int i = 0; i < v.size(); i++)
		s.insert(v[i]);
	vector<int>A;
	for(auto i:s)
		A.push_back(i);
	vector<int>temp;
	while(1){
		if(temp.size()!=0){
			for(int i :temp)
				A.push_back(i);
		temp.clear();
		sort(A.begin(), A.end());
		for(int i = 0; i < A.size()-1; i++){
			for(int j = i+1; j < A.size(); j++){
				if(A[i] != 0 && s.find(A[j]/A[i]) == s.end()){
					s.insert(A[j]/A[i]);
					temp.push_back(A[j]/A[i]);
				}
			}
		}
		if(temp.size() == 0)
				break;
	}
	return A.size();
}
