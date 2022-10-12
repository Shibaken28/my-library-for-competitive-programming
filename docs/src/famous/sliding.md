# スライド最小値
## 概要
- [問題](https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D)
- 数列Aに対して，長さがLの区間の最小値を求める．

## ソースコード
セグ木でも$O(N\log N)$で殴れるが，この手法では$O(N)$で解ける．

```cpp
template<class T>
vector<T> SlidingMinimumElement(vector<T>&A,int k){
    int n=A.size();
    vector<T>res(n-k+1);
    deque<int>deq;
    for(int i=0;i<n;i++){
        while(!deq.empty()&&A[deq.back()]>A[i])deq.pop_back();
        deq.push_back(i);
        if(i-k+1>=0){
            res[i-k+1]=A[deq.front()];
            if(deq.front()==i-k+1)deq.pop_front();
        }
    }
    return res;
}
```

