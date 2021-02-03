
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
