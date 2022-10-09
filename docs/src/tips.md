# よくある考察

## メタ読み
- 制約が$N=20$のときは，$2^N$通りのbit全探索
- 制約が$N=40$くらいのときは半分全列挙
  - これは半分全列挙感がすごい[ABC271 F - XOR on Grid Path](https://atcoder.jp/contests/abc271/tasks/abc271_f)

## 線形変換
- [線形漸化式](./famous/fibo.md)
- 行列を使って表すことができる
- dpの遷移が線形変換で表せるときは高速化ができる
- [BasyStepGiantStep](./natural/bsgs.md)が使えるパターン([ABC270 G - Sequence in mod P](https://atcoder.jp/contests/abc270/tasks/abc270_g))
- セグメントツリーに乗る[ARC008 D - タコヤキオイシクナール](https://atcoder.jp/contests/arc008/tasks/arc008_4)
