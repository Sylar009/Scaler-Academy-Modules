/*
Problem Description
You're given a read-only array of N integers. Find out if any integer occurs more than N/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Note: Read-only array means that the input array should not be modified in the process of solving the problem



Problem Constraints
1 <= N <= 7*105
1 <= A[i] <= 109


Input Format
The only argument is an integer array A.


Output Format
Return an integer.


Example Input
Input 1:
[1 2 3 1 1]
Input 2:
[1 2 3]


Example Output
Output 1:
1
Output 2:
-1


Example Explanation
Explanation 1:
1 occurs 3 times which is more than 5/3 times.
Explanation 2:
No element occurs more than 3 / 3 = 1 times in the array.
*/
int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int maj1 = A[0];
    int freq1 = 1;

    int maj2 = 0;
    int freq2 = 0;

    for (int i = 1; i < A.size(); i++) {
        if(A[i] == maj1 || A[i] == maj2) {
            if (A[i] == maj1 ) freq1++;
            else freq2++;
        }
        else if (freq1 == 0 || freq2 == 0) {
            if (freq1 == 0) { maj1 = A[i]; freq1++;}
            else { maj2 = A[i]; freq2++; }
        } 
        else {
            freq1--;
            freq2--;
        }
    }

    int count_maj_1 = 0;
    int count_maj_2 = 0;

    
    for (int j = 0; j < A.size(); j++) {
        if (A[j] == maj1) count_maj_1++;
        else if (A[j] == maj2) count_maj_2++;
    }

    if (count_maj_1 > A.size()/3) return maj1;
    else if (count_maj_2 > A.size()/3) return maj2;
    else return -1;
}
