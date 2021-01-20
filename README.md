# Sample Input 1 (no don't cares)

```
4
2
4
6
8
9
10
12
13
15
-1
-1
```

# Sample Input 2 (includes don't cares)

```
5
2
3
7
10
12
15
27
-1
5
18
19
21
23
-1
```

# Sample Input 3 (no don't cares)

```
4
0
1
5
6
7
8
9
10
11
13
14
15
-1
-1
```

# Sample Output 1

```
Enter number of variables: 4
Enter number corresponding to each of the Minterms (or enter -1 to get next step):
2
4
6
8
9
10
12
13
15
-1
Enter number corresponding to each of the don't cares (or enter -1 to get next step):
-1


Partitioning result:

3 groups found with 1 1s:
Minterm 2   0010
Minterm 4   0100
Minterm 8   1000
4 groups found with 2 1s:
Minterm 6   0110
Minterm 9   1001
Minterm 10   1010
Minterm 12   1100
1 groups found with 3 1s:
Minterm 13   1101
1 groups found with 4 1s:
Minterm 15   1111


Prime implicants partitioning result:

7 groups found with 1 1s:
Minterm 2, 6   0-10
Minterm 2, 10   -010
Minterm 4, 6   01-0
Minterm 4, 12   -100
Minterm 8, 9   100-
Minterm 8, 10   10-0
Minterm 8, 12   1-00
2 groups found with 2 1s:
Minterm 9, 13   1-01
Minterm 12, 13   110-
1 groups found with 3 1s:
Minterm 13, 15   11-1


Prime implicants partitioning result:

1 groups found with 1 1s:
Minterm 8, 9, 12, 13   1-0-


List of prime implicants:

PI1: 8, 9, 12, 13
PI2: 2, 6
PI3: 2, 10
PI4: 4, 6
PI5: 4, 12
PI6: 8, 10
PI7: 13, 15

      2   4   6   8   9  10  12  13  15
PI1               *   *       *   *
PI2   *       *
PI3   *                   *
PI4       *   *
PI5       *                   *
PI6               *       *
PI7                               *   *
PI1 is an essential implicant
PI7 is an essential implicant
Minterm 2 is not covered under essential implicants
Minterm 4 is not covered under essential implicants
Minterm 6 is not covered under essential implicants
Minterm 10 is not covered under essential implicants

      2   4   6  10
PI2   *       *
PI3   *           *
PI4       *   *
PI5       *
PI6               *

Essential implicants:
PI1, PI7

Picked non-essential implicants:
PI3, PI4
```

# Sample Output 2

```
Enter number of variables: 5
Enter number corresponding to each of the Minterms (or enter -1 to get next step):
2
3
7
10
12
15
27
-1
Enter number corresponding to each of the don't cares (or enter -1 to get next step):
5
18
19
21
23
-1


Partitioning result:

1 groups found with 1 1s:
Minterm 2   00010
5 groups found with 2 1s:
Minterm 3   00011
Minterm 10   01010
Minterm 12   01100
Minterm 5   00101 (don't care)
Minterm 18   10010 (don't care)
3 groups found with 3 1s:
Minterm 7   00111
Minterm 19   10011 (don't care)
Minterm 21   10101 (don't care)
3 groups found with 4 1s:
Minterm 15   01111
Minterm 27   11011
Minterm 23   10111 (don't care)


Prime implicants partitioning result:

3 groups found with 1 1s:
Minterm 2, 3   0001-
Minterm 2, 10   0-010
Minterm 2, 18   -0010
5 groups found with 2 1s:
Minterm 3, 7   00-11
Minterm 3, 19   -0011
Minterm 5, 7   001-1
Minterm 5, 21   -0101 (don't care)
Minterm 18, 19   1001- (don't care)
5 groups found with 3 1s:
Minterm 7, 15   0-111
Minterm 7, 23   -0111
Minterm 19, 27   1-011
Minterm 19, 23   10-11 (don't care)
Minterm 21, 23   101-1 (don't care)


Prime implicants partitioning result:

1 groups found with 1 1s:
Minterm 2, 3, 18, 19   -001-
2 groups found with 2 1s:
Minterm 3, 7, 19, 23   -0-11
Minterm 5, 7, 21, 23   -01-1


List of prime implicants:

PI1: 2, 3, 18, 19
PI2: 3, 7, 19, 23
PI3: 5, 7, 21, 23
PI4: 2, 10
PI5: 7, 15
PI6: 19, 27
PI7: 12

      2   3   7  10  12  15  27
PI1   *   *
PI2       *   *
PI3           *
PI4   *           *
PI5           *           *
PI6                           *
PI7                   *
PI4 is an essential implicant
PI5 is an essential implicant
PI6 is an essential implicant
PI7 is an essential implicant
Minterm 3 is not covered under essential implicants

      3
PI1   *
PI2   *
PI3

Essential implicants:
PI4, PI5, PI6, PI7

Picked non-essential implicants:
PI1
```

# Sample Output 3

```
Enter number of variables: 4
Enter number corresponding to each of the Minterms (or enter -1 to get next step):
0
1
5
6
7
8
9
10
11
13
14
15
-1
Enter number corresponding to each of the don't cares (or enter -1 to get next step):
-1


Partitioning result:

1 groups found with 0 1s:
Minterm 0   0000
2 groups found with 1 1s:
Minterm 1   0001
Minterm 8   1000
4 groups found with 2 1s:
Minterm 5   0101
Minterm 6   0110
Minterm 9   1001
Minterm 10   1010
4 groups found with 3 1s:
Minterm 7   0111
Minterm 11   1011
Minterm 13   1101
Minterm 14   1110
1 groups found with 4 1s:
Minterm 15   1111


Prime implicants partitioning result:

2 groups found with 0 1s:
Minterm 0, 1   000-
Minterm 0, 8   -000
4 groups found with 1 1s:
Minterm 1, 5   0-01
Minterm 1, 9   -001
Minterm 8, 9   100-
Minterm 8, 10   10-0
8 groups found with 2 1s:
Minterm 5, 7   01-1
Minterm 5, 13   -101
Minterm 6, 7   011-
Minterm 6, 14   -110
Minterm 9, 11   10-1
Minterm 9, 13   1-01
Minterm 10, 11   101-
Minterm 10, 14   1-10
4 groups found with 3 1s:
Minterm 7, 15   -111
Minterm 11, 15   1-11
Minterm 13, 15   11-1
Minterm 14, 15   111-


Prime implicants partitioning result:

1 groups found with 0 1s:
Minterm 0, 1, 8, 9   -00-
2 groups found with 1 1s:
Minterm 1, 5, 9, 13   --01
Minterm 8, 9, 10, 11   10--
4 groups found with 2 1s:
Minterm 5, 7, 13, 15   -1-1
Minterm 6, 7, 14, 15   -11-
Minterm 9, 11, 13, 15   1--1
Minterm 10, 11, 14, 15   1-1-


List of prime implicants:

PI1: 0, 1, 8, 9
PI2: 1, 5, 9, 13
PI3: 8, 9, 10, 11
PI4: 5, 7, 13, 15
PI5: 6, 7, 14, 15
PI6: 9, 11, 13, 15
PI7: 10, 11, 14, 15

      0   1   5   6   7   8   9  10  11  13  14  15
PI1   *   *               *   *
PI2       *   *               *           *
PI3                       *   *   *   *
PI4           *       *                   *       *
PI5               *   *                       *   *
PI6                           *       *   *       *
PI7                               *   *       *   *
PI1 is an essential implicant
PI5 is an essential implicant
Minterm 5 is not covered under essential implicants
Minterm 10 is not covered under essential implicants
Minterm 11 is not covered under essential implicants
Minterm 13 is not covered under essential implicants

      5  10  11  13
PI2   *           *
PI3       *   *
PI4   *           *
PI6           *   *
PI7       *   *

Essential implicants:
PI1, PI5

Picked non-essential implicants:
PI2, PI3
```