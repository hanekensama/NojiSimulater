How To Use

1. アセンブリをcのソースファイルに変換 
   asm.shを利用
   例) cat sample.txt | ./asm.sh > sample.c
       ./asm.sh < sample.txt > sample.c

2. コンパイル
   
3. 実行
   プログラム終了時の各レジスタの値が表示される。

4. もっとデバッグする
   c言語なので、当然gccが利用可
   reg()関数を使えばレジスタの状態が表示される
   mem()関数を使えばメモリの状態が表示される
   memAt(int address)関数を使えばaddressで指定したメモリの状態が表示される
