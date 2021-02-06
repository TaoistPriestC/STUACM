
###  Classical Bit Operation
```c++
/* To set/turn on j-th item (0-based indexing) of the set */
S |= (1<<j);
```

```c++
/* To check if the j-th item of the set is on */
T = S & (1<<j);
```

```c++
/* To toggle (flip the status of) the j-th item of the set */
S ^= (1<<j);
```

```c++
/* To clear/turn off the j-th item of the set */
S &= ~(1<<j);
```

```c++
/* To get the value of the least significant bit of S */
T = ((S) & (-S));
```

```c++
/* To turn on all bits in a set of size n by Shift */
S = (1<<n) - 1;
```

```c++
/* To enumerate all proper subsets of a given a bitmask */
int mask = GivenMask;
for(int subset = mask; subset; subset = (mask & subset - 1)){
    cout<< Representation(subset) <<endl;
}
```


#### Bit Operation of Traversal Set 

　Suppose we use each binary bit to represent an set element,we now need to traverse all the subsets and print the them. We have two strategies, one is bit-by-bit checking, and the other is skip checking using `loWbit(x)` operations.

```c++
//枚举排列组合,复杂度O(n!)
next_permutation(a,a+n);
prev_premutation(a,a+n);
```

```c++
//Enumerate set-Method 1
for(int i = 0;i<(1<<n);++i){
    for(int j = 0; j<n; ++j){
        if(i & (1<<j)){
			...
        }
    }//Check if the bit is on bit-by-bit 
}
```

```c++
//Enumerate set-Method 2
for(int i = 0; i<(1<<n); ++i){
    int t = i;
    while(t){
		int x = lowbit(x);
        int j = __builtin_ctz(x);
        t-=x;
    }//Find the bit is on by lowbit(x) 
}
```
