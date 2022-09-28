# 順列列挙
## 概要
- \\(0,1,2,3,...,N-1\\)の要素数\\(N\\)個の順列，要素の重複なし
- \\(0,1,2,3,...,N-1\\)のから\\(U\\)個選んだ順列，要素の重複なし
- \\(0,1,2,3,...,N-1\\)のから\\(U\\)個選んだ順列，要素の重複あり
- \\(0,1,2,3,...,N-1\\)のから\\(U\\)個選んだ組み合わせ，要素の重複なし
- \\(0,1,2,3,...,N-1\\)のから\\(U\\)個選んだ組み合わせ，要素の重複あり

を求める

## 計算量
よくわからん

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



vector<vector<int>> permutation(int N,int U,bool h=false){
    //0,1,2,3,...,N-1のN個からU個選ぶ順列
    vector<vector<int>> A(0);
    auto fun = [&h,&A,&N,&U](auto &fun,vector<int> &B)->void{
        if((int)B.size()==U){
            auto C=B;
            do{
                A.push_back(C);
            }while(next_permutation(C.begin(),C.end()));
            return;
        }
        int s = (h?0:-1);
        if(!B.empty())s = B.back();
        for(int x=s+(h?0:1);x<N;x++){
            B.push_back(x);
            fun(fun,B);
            B.pop_back();
        }
    };
    vector<int> C={};
    fun(fun,C);
    return A;
}

vector<vector<int>> combination(int N,int U,bool h=false){
    //0,1,2,3,...,N-1のN個からU個選ぶ組み合わせ順列
    vector<vector<int>> A(0);
    auto fun = [&h,&A,&N,&U](auto &fun,vector<int> &B)->void{
        if((int)B.size()==U){
            auto C=B;
            A.push_back(B);
            return;
        }
        int s = (h?0:-1);
        if(!B.empty())s = B.back();
        for(int x=s+(h?0:1);x<N;x++){
            B.push_back(x);
            fun(fun,B);
            B.pop_back();
        }
    };
    vector<int> C={};
    fun(fun,C);
    return A;
}

int main(void){
    cout<<permutation(5,3,false)<<endl;//重複なし順列
    cout<<permutation(5,3,true)<<endl; //重複あり順列
    cout<<combination(5,3,false)<<endl;//重複なし組み合わせ
    cout<<combination(5,3,true)<<endl; //重複あり組み合わせ
}

```
