+++
author = "Hoxton"
title = "資料結構筆記"
date = "2022-10-08T03:02:43+08:00"
draft = "false"
description = "資料結構的筆記" 
tags = [ "" ]
categories = ["程式"]
image = "https://i.imgur.com/NiqSvey.png"
keyword = ["資料結構"]

+++
# 學習路線

## Ch1Algorithm, Recursion and Performance Analysis(space + Time)

## Ch3 Stack & Queue

## Ch5 Tree And Binary Tree

## Ch9 Advanced Trees

## Ch7 Search and <u>Sorting</u>

## CH8 Hasing

## Ch6 Graph

## Ch2/Ch4 Array&Linked List 





# Ch1 Algorith, Recursion and Performance Analysis

> Algo定義(5個Criteria)
>
> Recursion(遞迴)☆☆☆☆☆
>
> > 定義
> >
> > 種類
> >
> > 與 Non-Recursion比較考型及來源
>
> 效能分析
>
> > Space(較少考)
> >
> > Time(較常考)☆☆☆☆☆



## Algorithm(演算法)

+ 定義：為了解決特定問題之有限個敘述／步驟／指令所構成之集合，且必須滿足下列**５**個Criteria：

1. Input：輸入的資料量>=0個即可
2. Output：至少要有>=1個輸出量
3. Definiteness(明確性)：每個敘述／步驟／指令必須是Clear且unambiauous(不可混淆不清)。`3之要求在於Algo之寫作格式無一致標準之規範 `
4. Finiteness(有限性)：必須在執行／追蹤有限個步驟後，必能夠終止
5. Effectiveness(有效性)：人可以用紙和筆追蹤／執行每一個步驟，即每一個Step is baisc enough to be carried。`當log完成，你如何確定它是正確的`



## Recurtion(遞迴)

+ 定義：(以Direct Recursion為例)，Algo/program中含有==**self-calling(自我呼叫)**==敘述存在者，稱之遞迴

+ 種類：

  1. Direct：直接遞迴
  2. Indirect：間接遞迴
  3. Tail：尾端遞迴

+ 分述如下

  1. 直接遞迴：方法中直接呼叫自己

     ```c
     function A(){
         // do something
         if(...) then  A(); //重複自己
         else{
         // do something
         }
     }
     ```

  2. 間接遞迴：多個Module之間彼此形成Calling Cycle，

     ```c
     function  A(){
         //something
         Call B(); //相互呼叫
         //something
     }
     
     function B(){
         //something
         Call A(); //相互呼叫
         //something
     }
     ```

  3. 尾端遞迴：是Direct Recustion 之一種，recursive call發生在程式即將結束之前一行

     ```c
     function A(){
         //do something
         if(xxx){} then A() //程式的最後一行 優點是Complier或工程師方便改寫成非遞迴的形式(降低時間複雜度
     }
     ```



**任何problem之解決，必定存在兩種形式之Algo**

1. 遞迴
2. 非遞迴(Interation)

eq. 求n! 求費氏數列

![image-20230212130259106](https://i.imgur.com/dIbSOTs.png)



比較圖如下

| Recursion                         | Non-Recursion                            |
| --------------------------------- | ---------------------------------------- |
| **程式碼較為精簡**                | 冗長                                     |
| 較少，或沒有使用區域變數          | 使用到區域變數來保存中間值，Loop控制等等 |
| **程式碼占的儲存空間**比較少      | 程式碼占用的儲存空間較多                 |
| 表達力較強(powerful)              | 表達力較弱(weak)                         |
| ==**執行的時間較久，較沒效率**==  | 執行時間較短，較有效率                   |
| ==**需要額外的stack space支持**== | 不需要這東西                             |



+ 補充

在complier或程式語言的課程裡面，會**討論如何處理recursion?**

1. 當遇到Recursive call的時候，

   1. 必須先保存當時執行狀況，push這些東西

   > 1. 參數值
   > 2. 區域/占存 變數值
   > 3. 返回位址(return address)

   到System **stack**

   2. Jump to 程式開端執行

2. 若遇到程式結束(END)敘述時`遞迴條件不符合，繼續往下執行，遇到程式的END，要判斷是某一次的遞迴結束，還是整個都結束了。判斷的依據是查看Stack區是否為空，若為空則代表只是一次的遞迴結束，若Stack為空，則代表整個程式結束`

   ```c
   if (stack is empty) then 整個結束
       else{
           pop stack; //取出當時保存的參數或區域變數以及返回位置(return address) then go to "return address"執行
           //所謂的return address(返回位址，就是指遞迴結束完後，下一個會執行的程式碼)
       }
   ```

   例：

   ```c
   function A(int a){ 
       int x = 0;
       int y=0;
       a++;
       if(xxx) then A(a); //recursive call
       else{
   //do something
       }
       x=x+1; (這就是返回位址 (1:)
   }
   ```

![image-20230212135153292](https://i.imgur.com/7uzIEQg.png)





![image-20230212135446234](https://i.imgur.com/7JDHEkJ.png)

### 考型及來源

考型：

> 1. 給一個Probleam，寫下Recursive algo/code
> 2. 給Recursive algo/code，要我們追蹤結果 etc...

來源：

> 1. 數學類：階層
> 2. 往後章節(二元樹的追蹤、圖形的追蹤、排序的追蹤...)
> 3. 其他
>
> > 1. Tower fo Hanoi
> > 2. permutation printing



#### 數學類

1. 寫下一個非遞迴的求階層方法

```c
int fac(int n){
    if(n==0){
        return 1;
    }else // n>0{
        int S=1;
    	int i ;
    	for(i=1;i<=n;i++){
            S=S*i;
            return S;
        }
    }   
}
```



2. 寫下一個用遞迴處理的求階程式

   ==關鍵點：記下數學遞迴定義式==

   ![image-20230212145854185](https://i.imgur.com/taUXn8C.png)

   ```c
   int fac(int n){
       if(n==0){
           return 1;
       }else{
         return n * fac(n-1) ;
       }
   }
   ```

3. 以2的Code為題目

   1. 求Fac(3)

      ![image-20230212145917501](https://i.imgur.com/5TgPcuk.png)

   2. 共呼叫Fac函數?次，含Fac(3)這次`這影響到了時間複雜度，以及會調用幾次pop`

      4次，`Fac(n)共呼叫幾次=n+1次`

4. write a recursive algo for sum(n)= 1+2+...+n, and sum(0)=0;

   ![image-20230212150912005](https://i.imgur.com/7JkNHxN.png)

   ```c
   int sum(int n){
       if(n==0){
           return 0;
       }else{
           return n+sum(n-1);
       }
   }
   ```

5. Fibonacci Number(費氏數列)

   ![image-20230212151908181](https://i.imgur.com/T5k9DFx.png)

   | n    | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   | 12   | 13   |
   | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
   | Fn   | 0    | 1    | 1    | 2    | 3    | 5    | 8    | 13   | 21   | 34   | 55   | 89   | 144  | 233  |

   Q：F98 = ? + ? = ? - ? = ? - ?

   1. F97+F96;
   2. F99-F97;
   3. F100-F99;

   Q：不超過500之費氏數列

   ​	A. F14 = 377

6. Write a recursive algo/code for Fibonacci 

   1. 遞迴解法

   ```pseudocode
   int Fib(int n){
   if(n==0){ return 0;}
   if(n==1){return 1;}
   return Fib(n-1)+Fib(n-2);
   }
   ```

   2. 非遞迴解法

   ```c
   int Fib(int n){
       if (n==0){
           return 0
       }else if(n==1){
           return 1
       }else{
           int a =0;
           int b =1;
           int c ;
           int i ;
           for(i=2;i<n;i++){
               c= a + b;
               a =b ;
               b = c ;
           }
           return c;
       }
   }
   ```

   | Fo   | F1   | F2                      | F3                      | ...  |
   | ---- | ---- | ----------------------- | ----------------------- | ---- |
   | a=0  | b=1  | c=a+b<br />a=b<br />b=c | c=a+b<br />a=b<br />b=c | ...  |





 3.  依(1)之code，(i)求出Fib(5)之值(ii)呼叫次數?次(iii)Fib(10)的呼叫次數呢?

     ```pseudocode
     int Fib(int n){
     if(n==0){ return 0;}
     if(n==1){return 1;}
     return Fib(n-1)+Fib(n-2);
     }
     ```

     

     ans . 

     (i) 5

     (ii)![image-20230220000219053](https://i.imgur.com/9rkgJtk.png)

     (iii)![image-20230220001353812](https://i.imgur.com/ed9zsLC.png)

     

     

     4. 令T<sub>(n)</sub>代表求Fin(n)時之呼叫次數，即T(0)=T(1)=1次，(i)寫出T(n)之Recursive definition(ii)Based on (i)，求出T(10)之值

        

        ans . (i) T(n) = T(n-1)+T(n-2)+1 且 T(0) =T(1) = 1;

        ​		(ii)

        | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   |
        | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
        | 1    | 1    | 3    | 5    | 9    | 15   | 25   | 41   | 67   | 109  | 177  |

        

     5. 求Fib(5)時，則Fib(0),Fib(1),Fib(2),Fib(3),Fib(4),Fib(5),分別被呼叫?次
     
        | Fib(n)   | 0    | 1    | 2    | 3    | 4    | 5    |
        | -------- | ---- | ---- | ---- | ---- | ---- | ---- |
        | 呼叫幾次 | 3    | 5    | 3    | 2    | 1    | 1    |
     
        5只會自己生自己，4只會由5產生，3會由4跟5產生(1+1)，2則是由3跟4產生(2+1)，1會由2跟3產生(3+5)，但0只會由2產生，不會由0產生。
     
        
     
     6. 接續上題，那Fib(10)呢?
     
        | Fin(n)   | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   |
        | -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
        | 呼叫幾次 | 34   | 55   | 34   | 21   | 13   | 8    | 5    | 3    | 2    | 1    | 1    |
     
        
     
     7. 令T(n)代表求Fib(n)時之加法次數 
     
        (i)求出T(n)之recursive definition
     
        (ii)求T(5)之值 based on(i)
     
        ans
     
        (i) T(n)=T(n-1)+T(n-2)+1，且T(0)=0,T(1)=0
     
        | Fib(n)   | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
        | -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
        | 呼叫幾次 | 0    | 0    | 1    | 2    | 4    | 7    | 12   | 20   | 33   |
     
     8. code如下，求F(5)之值
     
        ```pseudocode
        int Fib(int n){
        if(n==0 || n==1){return 1}
        return F(n-1)+F(n-2)
        }
        ```
     
        | Fib(n) | 0    | 1    | 2    | 3    | 4    | 5    |
        | ------ | ---- | ---- | ---- | ---- | ---- | ---- |
        | 值     | 1    | 1    | 2    | 3    | 5    | 8    |
     
        
     
     9. code如下
     
        ```pseudocode
        int Fib(int n){
        if(n<1){return 0}
        if(n<3){return 1}
        return Fib(n-1)+Fin(n-2)
        }
        ```
     
        (i)求Fib(5)之值
     
        | Fib(n) | 0    | 1    | 2    | 3    | 4    | 5    |
        | ------ | ---- | ---- | ---- | ---- | ---- | ---- |
        | 值     | 0    | 1    | 1    | 2    | 3    | 5    |
     
        (ii)呼叫Fib函數?次(含Fib(5))
     
        ![image-20230220214503733](https://i.imgur.com/cR8M7qZ.png)
     
        
     
     10. Binomical coe(二項式係數)
     
     ​	
     
     
     $$
     {C_m}^n =(\underset{m}{\overset{n}{{}}})=\frac{n!}{m!(n-m)!}
     $$



​	






$$
(i)write a recursive algo / code 求 (\underset{m}{\overset{n}{{}}})之值
$$




ans. 關鍵，==**必背**==


$$
(\underset{m}{\overset{n}{{}}})=\{ \begin{aligned}
& 1, \text{ if } (n = m \text{ or } m = 0) \\
& (\underset{m}{\overset{n-1}{{}}})+(\underset{m-1}{\overset{n-1}{{}}})
\end{aligned}
$$




```pseudocode
int Bin(int n , int m){
if(n==m || m==0){return 1}
else{
return Bin(n-1,m)+Bin(n-1,m-1)
}
}
```





(ii) based on (i) code 求Bin(5,3)之值及呼叫次數



![image-20230220232145991](https://i.imgur.com/8VKJjX9.png)



ans 10 ,19次



Note ：計算時
$$
(\underset{3}{\overset{5}{{}}}) = \frac{5*4*3}{1*2*3} = 10
$$

$$
(\underset{4}{\overset{8}{{}}}) = \frac{8*7*6*5}{1*2*3*4}=70
$$




# Ch5 Tree and Binary Tree

**Tree跟BinaryTree不一樣**

## 學習路線

> Tree Def 相關術語
>
> Tree的表示方法(4種)☆☆
>
> Binary Tree之 Def 與 <u>Tree不同比較☆☆☆☆☆</u>
>
> B.T的3個基本定理☆☆☆☆☆☆
>
> B.T的種類(4種)☆☆
>
> B.T的表示方式(2種)☆☆
>
> B.T Traversal (前中後序及level-order)及其應用☆☆
>
> **Binary Search Tree(BST)☆☆☆☆☆**
>
> **Heap☆☆☆☆☆**
>
> Thread Binary Tree(有效利用空鏈結，但非考試重點)☆☆
>
> Tree化成B.T,Forest化成BT
>
> N個Node所形成的不同B.T Structures ☆☆☆
>
> Disjoint Sets定義、表示、應用及Union(i,j) , Find(x)運作



## Tree(樹)

+ 定義：是由>0個Node所構成之集合，**不可以為空**，滿足以下的條件

  1. 至少會有一個特定Node叫做**Root(樹根)**
  2. 其餘的Node分成T1~Tm個互斥集合，T1~Tm稱之為Root之子樹(subtrees)

  ![image-20230201220412599](https://i.imgur.com/iwSOSZh.png)





+ 術語

  1. **Node's Degree**：該節點的子樹個數

     Ａ之Degree：３

     Ｂ之Degree：２

     Ｅ之Degree：０

  2. **Leaf(樹葉)**：Degree=0的Node

     例如：E,F,G,H,I,J

  3. Non-Leaf(非樹葉)：非樹葉的點(Degree>0的點)

     例如：Ａ,B,C,D

  4. Child與Parent

  5. Sibling(兄弟)：具有共同父點的Node，即為Sibling

     **eg. B,C,D是sibling**

  6. Ancestors(先祖)：沿著父節點往上延伸的Node即為Ancestors

     eg. E之Ancestors{B,A}

     ​	  I之Ancestors{D,A}

     > Note：Descendents(後代)
     >
     > eg. B之後代={E,F}

  7. Node's Level值：各家定義不盡相同，有以下幾種，**差異在於Root是0還是1**。

     + 定義：
       1. Root Level = 1; 
       2. 若 Parent 之 level=i，則it children level = i+1

  8. Tree's Degree：MAx{Node's Degree}

     eg. Tree's Degree = 3

  9. Tree's Height (or Depth) ：Max{Node's Level}

     eg. Tree高度=3(假設root為1)

  10. **Forest(森林)**：由≥0棵互斥Trees所形成之集合，**Forest可以為空**

## Tree的表示方式

方法一：LinkedList直接表示

作法：假設Tree's Degree=K，Node數=n，則Node Structure如下

![image-20230201224708128](https://i.imgur.com/jCq1OHY.png)

分析：

**缺點:極度浪費Link空間**，共準備n*K條Link，**☆☆☆☆☆有用的非Nil之Link有n-1條☆☆☆☆☆**(扣掉樹根不用，概念類似相通的無向圖)，所以Nil Links(浪費的)有nk-(n-1)條，因為浪費比例


$$
\frac{n*k-(n-1)}{n*k} = \frac{nk-n+1}{nk}=\frac{k-1}{k} =0.99
$$

