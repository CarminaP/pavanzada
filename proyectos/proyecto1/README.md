# 1091 - Tmutarakan Exams

**Problem Author:** Stanislav Vasilyev
**Problem Source:** USU Open Collegiate Programming Contest March'2001 Senior Session

University of New Tmutarakan trains the first-class specialists in mental arithmetic. To enter the University you should master arithmetic perfectly. One of the entrance exams at the Divisibility Department is the following. Examinees are asked to find K different numbers that have a common divisor greater than 1. All numbers in each set should not exceed a given number S. The numbers K and S are announced at the beginning of the exam. To exclude copying (the Department is the most prestigious in the town!) each set of numbers is credited only once (to the person who submitted it first).
Last year these numbers were K=25 and S=49 and, unfortunately, nobody passed the exam. Moreover, it was proved later by the best minds of the Department that there do not exist sets of numbers with the required properties. To avoid embarrassment this year, the dean asked for your help. You should find the number of sets of K different numbers, each of the numbers not exceeding S, which have a common divisor greater than 1. Of course, the number of such sets equals the maximal possible number of new students of the Department.

##Input:
The input contains numbers K and S (2 ≤ K ≤ S ≤ 50).

##Output:
You should output the maximal possible number of the Department's new students if this number does not exceed 10000 which is the maximal capacity of the Department, otherwise you should output 10000.

##Sample
```
Input: 3 10     Output: 11
```

## Breakdown
1. K represents the ammount of numbers with a common divisor grater than 1 that the students need to find.
2. S represents the limit number this sets each student needs to hand in, must not exceed.
3. Given these 2 number the program needs to find the maximal possible number of new students can be admitted with a given K and S.
4. We need to calculate the greatest common divisors of numbers from 1 to S, in sets of K and count the possible sets we can get.
3. We can pre-calculate the gratest common divisors to speed up the checking.
5. Since S is ≤ 50, we won't need a matrix larger than a 50 x 50 matrix for any case.


## Análisis
1. To calculate the greatest common divisor we can use Euclid's algoritm:

```
gcd(a,0) = a
gcd(a,b) = gcd(b, a mod b)
```
2. With that we can create a matrix with the common divisors from numbers from 1 to S, but to populate it quickly, since the gcd of (a,b) is the same for (b,a), we can fill the respective (i,j) and (j,i) cells with one operation.
3. With the matrix we can check the common divisors, excluding the ones that result in 1, adding to the result each time we find a set of k numbers.
4. We start with tmutarakan(i, gcd, k) where i is the last integer used for the set, gcd is the gcd of the set, and k is the counter to built each set of size K.
5. If we go through all tmutarakan iterations, adding another integer j to the set of the solution in a fashion of tmutarakan(j, gcd(gcd,j), k+1) each time, we arrive to the final solution.

## Algoritmo
```
-> Recieve K y S values
-> Generete greatest common divisor matrix
-> Calculate the first gcd
-> if it is 1 move to the next value and recalculate it's gcd
-> if it isn't 1, start the next iteration of the function with the calculated gcd to get the next value that has an equal gcd
-> when the count of values found is equal to the number needed for a set, finish that iteration of the function
-> After all the iterations, we arrive to the total solution
```
