/*
Problem Description
Akash likes playing with strings. One day he thought of applying following operations on the string in the given order:

Concatenate the string with itself.
Delete all the uppercase letters.
Replace each vowel with '#'.
You are given a string A of size N consisting of lowercase and uppercase alphabets. Return the resultant string after applying the above operations.

NOTE: 'a' , 'e' , 'i' , 'o' , 'u' are defined as vowels.



Problem Constraints
1<=N<=100000


Input Format
First argument is a string A of size N.



Output Format
Return the resultant string.



Example Input
Input 1:
A="aeiOUz"
Input 2:
A="AbcaZeoB"


Example Output
Output 1:
"###z###z"
Output 2:
"bc###bc###"


Example Explanation
Explanatino 1:
First concatenate the string with itself so string A becomes "aeiOUzaeiOUz".
Delete all the uppercase letters so string A becomes "aeizaeiz".
Now replace vowel with '#', A becomes "###z###z".
Explanatino 2:
First concatenate the string with itself so string A becomes "AbcaZeoBAbcaZeoB".
Delete all the uppercase letters so string A becomes "bcaeobcaeo".
Now replace vowel with '#', A becomes "bc###bc###".


*/
string Solution::solve(string A) {
    int index = 0;
    while (index < A.size()) {
        if(A[index] >= 65 && A[index] <= 90) {
            if (index == 0 && A.size() > 1) A = A.substr(index+1,A.size()-1);
            else A = A.substr(0, index) + A.substr(index+1,A.size()-index-1);
        }
        else index++;
    }
    for (int i = 0; i < A.size(); i++) {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') A[i] = '#';
    }

    return A + A;
}
