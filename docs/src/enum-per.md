# 順列列挙
## 概要
`next_permutation`を使って要素が\\(0,1,2,3,...,N\\)からなる長さ\\(N\\)の順列を列挙します．

```cpp
vector<vector<int>> permutations(int N){
    vector<int> array(N);
    vector<vector<int>> A(0);
    for(int i=0;i<N;i++)array[i]=i;
    do{
        A.push_back(array);
    }while(next_permutation(array.begin(),array.end()));
    return A;
}
```
