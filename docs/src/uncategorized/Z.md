# Z Algorithm
## 概要
文字列$S$の各位置$i$について，「$S$」と「$S$の$i$文字目以降の文字列」の最長共通接頭辞の長さを求めるアルゴリズム．
## 計算量
$O(|S|)$
## ソースコード

```cpp
/*Z-Algorithm*/
vector<int> Z_algorithm(string S){
    int N=S.size();
    vector<int> A(N);
    A[0]=N;
    int i=1,j=0;
    while(i<N){
        while(i+j<N&&S[j]==S[i+j])j++;
        A[i]=j;
        if(j==0){
            i++;
            continue;
        }
        int k=1;
        while(i+k<N&&k+A[k]<j){
            A[i+k]=A[k];
            k++;
        }
        i+=k;
        j-=k;
    }
    return A;
};

```
