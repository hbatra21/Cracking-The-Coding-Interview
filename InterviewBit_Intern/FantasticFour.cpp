int function(vector<int> &A) {
	int n = A.size(); 
    int count = 0,  sum = 0; 
    vector<int>rem(4, 0);  
    for (int i = 0; i < n; i++) { 
        int mod = A[i] % 4; 
        sum += mod; 
        rem[mod] = rem[mod]+1; 
    } 
    if (sum % 4 != 0)  { 
        return -1; 
    } 
    else { 
  		count += min(rem[1], rem[3]);
        rem[1] -= count; 
        rem[3] -= count; 
  		rem[2] += rem[1] / 2; 
        rem[2] += rem[3] / 2;  
        count += rem[1] / 2; 
        count += rem[3] / 2; 
        count += rem[2] / 2; 
        return count; 
    } 
} 
