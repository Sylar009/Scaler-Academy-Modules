/*
Problem Description

Given two integers arrays, A and B, of size N each.



Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in arrays A and B.





Problem Constraints

1 <= N <= 2 * 105

-1000 <= A[i], B[i] <= 1000



Input Format

The first argument is an integer array A.
The second argument is an integer array B.



Output Format

Return an integer array denoting the N maximum element in descending order.



Example Input

Input 1:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
Input 2:

 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]


Example Output

Output 1:

 [10, 9, 9, 8]
Output 2:

 [8, 6, 6, 5]


Example Explanation

Explanation 1:

 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2:

 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).

*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    priority_queue<pair<int, pair<int, int> > > pq;
	
    set<pair<int, int> > s;
	
    int n = A.size();
	
    sort(A.begin(), A.end());
	
    sort(B.begin(), B.end());

	pq.push(make_pair(A[n-1] + B[n-1], make_pair(n-1, n-1)));
	s.insert(make_pair(n-1, n-1));

	vector<int> res;

	int k = n;
	
    while(k--){
		
        pair<int, pair<int, int> > p = pq.top();
		pq.pop();
		
        res.push_back(p.first);
		
        int L = p.second.first;
		int R = p.second.second;
		
		if( R>0 && L>=0  && s.find(make_pair(L,R-1)) == s.end() ) {

			pq.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
			s.insert(make_pair(L,R-1));
		}

		if( R>=0  && L>0 && s.find(make_pair(L-1, R)) == s.end()) {
			pq.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
			s.insert(make_pair(L-1, R));
		}
	}

	return res;
}
