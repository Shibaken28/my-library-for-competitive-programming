# C++が用意しているデータ構造


## `vector`
- 配列．
- `# include < vector >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
vector<int> A(10,0); // 10個の要素を持つint型の配列．初期値は0．
vector<int> B = {3,1,4,1,5}; //要素を指定して初期化．
vector<int> C;// 空の配列．
```

### 要素の取得
ランダムアクセスが$O(1)$で可能．
```cpp
vector<int> A = {3,1,4,1,5};
cout << A[0] << endl; // 3
cout << A[1] << endl; // 1
cout << A[2] << endl; // 4
cout << A[3] << endl; // 1
cout << A[4] << endl; // 5
cout << A.size() << endl; // 要素数を返す．
```

### 要素の追加と削除
```cpp
vector<int> C;// 空の配列．
C.push_back(2); // Cの末尾に2を追加．
C.pop_back(); // Cの末尾の要素を削除．
```

### ソート
$O(N\log N)$かかる．
```cpp
vector<int> B = {3,1,4,1,5};
sort(B.begin(),B.end()); // Bを昇順に並び替え．
sort(B.begin(),B.end(),greater<int>()); // Bを降順に並び替え．
```
## `set`
- 重複なしの集合．
- `# include < set >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
set<int> A = {3,1,4,1,5}; //要素を指定して初期化．
set<int> B;// 空の集合．
```
### 要素の取得
- ランダムアクセスはできない．
- range based for loopが使える．
- 要素が含まれているかは$O(\log N)$で`count`メンバ関数で判定できる($0$ならば含まれていない，$1$ならば含まれている)．
- イテレータの使用して次に大きい要素や次に小さい要素を取得することもできる([詳細](./../uncategorized/bs.md))．
```cpp
set<int> A = {3,1,4,1,5};
cout << A.size() << endl; //4．要素数を返す．
for(auto x:A){
    cout << x << endl; // 1,3,4,5の順に出力される．
    //勝手に昇順になっている．要素は重複しない．
}
cout << A.count(1) << endl; // 1がAに含まれているか．
```

### 要素の追加と削除
```cpp
set<int> B;// 空の集合．
B.insert(2); // Bに2を追加．
B.erase(2); // Bから2を削除．
```

## `map`
- キーと値のペアを格納する．
- `# include < map >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
map<int,int> A = {{1,2},{3,4},{5,6}}; //要素を指定して初期化．
map<int,int> B;// 空のmap．
```
### 要素の取得
- ランダムアクセスはできない．
- range based for loopが使える(キーと値が`pair`型でもらえる)．
- イテレータの使用して次に大きい要素や次に小さい要素を取得することもできる([詳細](./../uncategorized/bs.md))．
```cpp
map<int,int> A = {{1,2},{3,4},{5,6}};
cout << A.size() << endl; //3．要素数を返す．
cout << A[1] << endl; // 2
cout << A[3] << endl; // 4
cout << A[5] << endl; // 6
for(auto x:A){
    cout << x.first << " " << x.second << endl; // 1 2,3 4,5 6の順に出力される．
    //勝手にキーの昇順になっている．
}
```

## `queue`
- LIFO(First In First Out)のデータ構造．
- `# include < queue >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
queue<int> A;// 空のqueue．
```
### 要素の操作
```cpp
queue<int> A;
A.push(1); // Aの末尾に1を追加．
A.push(2); // Aの末尾に2を追加．
A.push(3); // Aの末尾に3を追加．
cout << A[0] << endl; // 1
cout << A.front() << endl; // 1
A.pop(); // Aの先頭の要素を削除．
cout << A.front() << endl; // 2
A.pop(); // Aの先頭の要素を削除．
cout << A.front() << endl; // 3
A.pop(); // Aの先頭の要素を削除．
```
## `stack`
FIFO(First In Last Out)のデータ構造．
### 初期化
```cpp
stack<int> A;// 空のstack．
```
### 要素の操作
```cpp
stack<int> A;
A.push(1); // Aの末尾に1を追加．
A.push(2); // Aの末尾に2を追加．
A.push(3); // Aの末尾に3を追加．
cout << A.top() << endl; // 3
A.pop(); // Aの末尾の要素を削除．
cout << A.top() << endl; // 2
A.pop(); // Aの末尾の要素を削除．
cout << A.top() << endl; // 1
A.pop(); // Aの末尾の要素を削除．
```

## `deque`
- `queue`と`stack`のキメラ．ランダムアクセスも可能である．
- `# include < deque >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
deque<int> A;// 空のdeque．
```
### 要素の操作
```cpp
deque<int> A;
A.push_back(1); // Aの末尾に1を追加．
A.push_back(2); // Aの末尾に2を追加．
A.push_back(3); // Aの末尾に3を追加．
A.push_front(4); // Aの先頭に4を追加．
A.push_front(5); // Aの先頭に5を追加．
A.push_front(6); // Aの先頭に6を追加．
cout << A[0] << endl; // 6
cout << A[1] << endl; // 5
cout << A[2] << endl; // 4
cout << A[3] << endl; // 1
cout << A[4] << endl; // 2
cout << A[5] << endl; // 3
A.pop_back(); // Aの末尾の要素を削除．
A.pop_front(); // Aの先頭の要素を削除．
cout << A[0] << endl; // 5
cout << A[1] << endl; // 4
cout << A[2] << endl; // 1
cout << A[3] << endl; // 2
```

## `priority_queue`
- 優先度付きキュー．
- `# include < queue >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
priority_queue<int> A;// 空のpriority_queue．
```
### 要素の操作
大きい方から出てくる．
```cpp
priority_queue<int> A;
A.push(2); // Aの末尾に2を追加．
A.push(3); // Aの末尾に3を追加．
A.push(1); // Aの末尾に1を追加．
cout << A.top() << endl; // 3
A.pop(); // Aの末尾の要素を削除．
cout << A.top() << endl; // 2
A.pop(); // Aの末尾の要素を削除．
cout << A.top() << endl; // 1
A.pop(); // Aの末尾の要素を削除．
```

## `list`
- 双方向連結リスト．
- `# include < list >`ヘッダをインクルードすることで使用できる．
### 初期化
```cpp
list<int> A;// 空のlist．
```
### 要素の操作
```cpp
list<int> ls;
ls.push_back(1);
ls.push_back(2);
ls.push_front(3);
ls.push_front(4);
for_each(ls.begin(),ls.end(),[](int a){
    cout<<a<<" "; // 4 3 1 2
});
cout<<endl;
auto it = ls.begin();
it++;
ls.insert(it,5);
for_each(ls.begin(),ls.end(),[](int a){
    cout<<a<<" "; // 4 5 3 1 2
});
cout<<endl;
```
