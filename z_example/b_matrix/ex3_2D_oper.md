
#### 1D vector and 2d matrix 
- binary multiplication of 2 matrix, setdiff1d
```sh
python run.py --opt 3 --delete False
```

```
F4
[[1,0,0,0,],
 [1,1,0,0,],
 [1,0,1,0,],
 [1,1,1,1,]]
sum(e1)=4
(F4@e1)%2=
[[1,0,0,0,],
 [1,1,0,0,],
 [1,0,1,0,],
 [1,1,1,1,]]
h stack(A,B,C)
[[1,0,0,0,1,0,0,0,1,0,0,0,],
 [1,1,0,0,0,1,0,0,1,1,0,0,],
 [1,0,1,0,0,0,1,0,1,0,1,0,],
 [1,1,1,1,0,0,0,1,1,1,1,1,]]
setdiff1d (arange(0,5), [1,3])
0 2 4 
e1
[[1,0,0,0,],
 [0,1,0,0,],
 [0,0,1,0,],
 [0,0,0,1,]]
swap e1 row0 row1
[[0,1,0,0,],
 [1,0,0,0,],
 [0,0,1,0,],
 [0,0,0,1,]]
bin add e1 row 1 += row2
[[0,1,0,0,],
 [1,0,1,0,],
 [0,0,1,0,],
 [0,0,0,1,]]
---bin_to_dec
0 1 1 0 1 
--->13
back to vec
0 1 1 0 1 
F4 to compressed int vector
1 3 5 15 
back to mat
[[1,0,0,0,],
 [1,1,0,0,],
 [1,0,1,0,],
 [1,1,1,1,]]
```
