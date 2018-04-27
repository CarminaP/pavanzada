#Magic Trick
[LINK] https://www.codechef.com/problems/MTRICK

##Problem
Vidhi went to a magic show last week where she was astounded by a magic trick performed by the great Mandwarf, the brown. His trick was as follows:

* Ask a volunteer from the audience to write down a list **L** of **N** integers.
* Ask another volunteer from the audience to provide three integers **A**, **B**, **C**
* Ask another volunteer from the audience to provide **N** length string called **S** where each letter is either 'R', 'A' or 'M'
* Close his eyes for a split second and give the output of The Ancient Algorithm on this input.

We all know that The Ancient Algorithm is as follows :
```
for i from 1 to N do:

    if ith letter of S is 'R'
        reverse L[i...N]
    else if ith letter of S is 'A'
        add A to all numbers of L[i..N].
    else if ith letter of S is 'M'
        multiply B to all numbers of L[i..N].

    for all number in L[i..N], module them by C.

      announce L[i] out loud

end
```
Vidhi's boyfriend got jealous when he saw her getting impressed by Mandwarf, the brown's wisdom. He wants to learn the trick to gain her undivided admiration. How about you help him?

##Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ L[i] ≤ 10^18
1 ≤ A,B ≤ 10^18
1 ≤ C ≤ 10^18

##Input:
First line contains a single integer **T**, denoting the number of test cases. Then follow **T** test case scenarios. Each test case begins with an integer **N**, the size of the list **L**. Then in next line, you'd find **N** space separated integers - the list **L** itself. In next line, there'd be three space separated integers **A**, **B**, **C** followed by string **S** in the next line.

##Output:
For each test case you've to output **N** space separated integers - the numbers announced by Mandwarf, the brown.

##Example
```
Input

2
3
1 1 1
2 3 1000
ARM
4
1 2 3 4
0 1 1000
AMAM

Output

3 3 9
1 2 3 4
```

## Breakdown

1. The problem is very straight-forward, the algorithm is given.
2. For the multiplication and addition of elements L[i...n] we can use the slope-intercept function as to maintain a slope Ki and an intercept Di, such that all current numbers in the array L after the i-th loop to be equal to the original numbers Ki * L[] + Di.
3. So instead of looping for each sum or multiplication case, we can update the K and D for each iteration, they stay as the identity value if the case doesn't apply, and then calculate Ki * L[] + Di at the end and store that value in L[i].
4. We can reverse the list L with a start-end pointer.
5. To avoid a long long exceeding during a multiplication, because C can be as large as 10^18, we can use fast multiplication.
6. With this improvements give the complexity of O(N log C) for each test case.
