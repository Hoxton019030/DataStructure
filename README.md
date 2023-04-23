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
[ToC]

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
(\underset{m}{\overset{n}{{}}})=\
\begin{cases}
& 1, \text{ if } (n = m \text{ or } m = 0) \\
& (\underset{m}{\overset{n-1}{{}}})+(\underset{m-1}{\overset{n-1}{{}}})
\end{cases}
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



Note ：計算時有些撇步


$$
(\underset{3}{\overset{5}{{}}}) = \frac{5\times4\times3}{1\times2\times3}=10
$$



$$
(\underset{4}{\overset{8}{{}}}) = \frac{8\times7\times6\times5}{1\times2\times3\times4}=70
$$






 12.  GCD(A,B) 求A,B兩數之最大公因數，寫出recursive algo/code

      





==**☆☆☆☆☆☆☆☆☆要背☆☆☆☆☆☆☆☆☆☆☆☆**==




$$
GCD(A,B)=\ \begin{cases}
& B, \text{ if } (A modsB)=0 \\
&GCD(B,AmodsB), other wise
\end{cases}
$$




```pseudocode
int GCD(int A,int B){
if (A%B==0) {return B}
else return GCD(B,A%B)
}
```





依上述code，試求(1)求GCD(18,33)之值(2)呼叫GCD?次

 ![image-20230221000814907](https://i.imgur.com/JkzUfwK.png)



13. Ackerman's Function `一坨大便，幹破你娘`





$$
A(m,n) = \begin{cases}
n+1, & \text{if } m=0\\
A(m-1,1), & \text{if } n=0\\
A(m-1,A(m,n-1)), & \text{otherwise}
\end{cases}
$$



(i) A(2,2)=?

ans. 

A(2, 2) =7



(ii) A(10,10)
ans.

A(10, 10) = A(9, A(10, 9))
= A(9, A(9, A(10, 8)))
= A(9, A(9, A(9, A(10, 7))))
= A(9, A(9, A(9, A(9, A(10, 6)))))
= A(9, A(9, A(9, A(9, A(9, A(10, 5))))))
= A(9, A(9, A(9, A(9, A(9, A(9, A(10, 4)))))))
= A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(10, 3))))))))
= A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(10, 2)))))))))
= A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(10, 1))))))))))
= A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(9, A(9, 1))))))))))
≈ 2.1216 x 10^19728



(iii)A(1,3)

A(1, 3) = A(0, A(1, 2))
= A(0, A(0, A(1, 1)))
= A(0, A(0, A(0, A(1, 0))))
= A(0, A(0, A(0, A(0, 1))))
= A(0, A(0, A(0, 1)))
= A(0, A(0, 2))
= A(0, 3)
= 4



**常考排行**

A(2,2) = 7

A(2,1) = 5

A(1,2) = 4

A(2,3)=  9





14. 求x<sup>n</sup>，其中x,n是integer，且n ≧ 0 , write a recursive algo/ code

ans






$$
x^n=
\begin{cases} 
1&\text {if}(n==0) \\ 
x \times x^{n-1}&\text {if} (n>0)
\end{cases}
$$






```pseudocode
int exp(int x,int n){
if (n==0){return 1}
else{
return Exp(x,n-1)*x
}
}
```



15. 

```c
int foo(int x, int n){
    if(n%2==0){
        f=1;
    }else{
        f=x
    }
    if(n<2){
        return f;
    }
    return f*foo(x*x, n/2);
}
```

(i) 求foo(2,5)值

​	![image-20230223220045068](https://i.imgur.com/GvgDjdH.png)

(ii)求foo(x,n)之功能

​	求x<sup>n</sup>

(iii)求foo(x,n)之Time Complexity

​	O(log<sub>n</sub>) 



#### 河內塔(Towers of Hanai)

![image-20230223232944377](https://i.imgur.com/dj1RFAh.png)

程式如下：

Hanoi(n,x,y,z);

n：盤數

x：來源

y：占存地

z：目的地



Step1 Hanoi(n-1,A,C,B);

Step2 Hanoi(1,A,B,C);

Step3 Hanoi(n-1,B,A,C);



```c++
void Hanoi(int n,char A,Char B, Char C){
    if(n==1){
        printf("move disk %d from %c to %c \n",n,A,C);
    }else //n>1{
        Hanoi(n-1,A,C,B);
        printf("move disk %d from %c \n",n,A,C);
    	Hanoi(n-1,B,A,C);
    	
}
}
```



#### Permutation列印



將[a,b,c]以不同的排列組合印出來

如

abc

acb

bac

bca

cba

cab

有3!=6種寫法



以遞迴的概念來理解



![image-20230308214715912](https://i.imgur.com/VJL10za.png)



原始碼的部分

```c++
void perm(char list[], int i, int n){
    //產生list[i]~list[n]之排列組合
    //i≦n
    if(i==n){ //代表遞迴中止
        for(j=1;j<=n;j++){
            printf(list[j]); // for each完後印出當時list的內容
        }
    }else{
        for(j=i;j<=n;j++){
            swap(list[i],list[j]); // list[j]做頭
            perm(list,i+1,n); //接(i+1)~(n)之perm
            swap(list[i],list[j]) // 還原成原本List的內容
        }
    }
}
```



實際演練

```c++
void main(){
    char list[3] = {a,b,c};
    Perm(list,1,3);
}
```



![1914A818-E923-4D51-854B-57E4AB2A9C3F](https://i.imgur.com/Eiyo3mb.jpg)







## Performance Analysis(效能分析)

 

Algo/code之效能分析，主要分析兩點

1. Space
2. Time 



## Space(空間)需求分析

定義：令SP(P)代表Algo/Code P 之空間需求，則SP(P)= **Fixed** Space requirement + **Variable** Space Requirement



固定(Fixed)空間需求= Instruction (or Code) Space `意即你寫了幾行的程式`+變數+常數空間 =**C**(mean Constant)

變動(Varialbe)空間需求=

主要有兩個來源

1. 若參數為結構型態(Array, Struct)且**採用Call-By-Value參數傳遞方式**(若是用Call-By-Address則也不是變動空間，因為只收一個Address的起始位址而已)
2. 遞迴(recursion)所需之stack space (堆疊空間)



因此主要的分析是在變動空間需求這邊

SP(P)= C + SP(i)





範例

求SP(i)=?

```c
rsum(floot list[], int n){
    if(n!=0){
        return rsum(list,n-1)+list[n-1]
    }
    return list[0]
}
// 此外，假設 floot 佔4 bytes, int佔2bytes pointr(address)佔2bytes, List[]採用Call-by-address傳遞

```

Ans.SP(i)= Stack Space for recursion

如何計算?

+ 每發生一次遞迴的呼叫(recusive call)，我們需要將

  + 參數值 `list[] 佔2byte,因為是call by address。n 佔2bytes`

  + 區域變數值`無`

  + Return Address`一定有，題目說是2Byte`

    **Push 6 byte per recursive call**

    又共發生**n**次recursive call(不含rsum(list,n))



因此Sp(i)= 6n bytes



## Time(時間)需求分析

定義：令T(P)代表Algo,code P之時間需求，則T(P)=Development time(開發時間) + Execution Time 

只注重/討論 Execution Time分析in DS/Algo課程

Execution Time之評量有兩個方法

1. Measurement(實際量度)
2. **Analysis**(分析、預估)\

本課程是採用Analysis方式，Analysis是以Algo/Code的指令執行總次數，作為分析Time之基礎



範例1. 不考慮指令之難易度

eq. 整數除法 a/b，浮點數除法 a/b視為一樣



原始code如下：

```c
for(i=1i≦n;i++){
    a = a + b;
}
return a;
```

Then, 宣告一個Global變數，Count=0，在適當處加入Count++之敘述

```c
for(i=1i≦n;i++){
    count++; //用來統計for做幾次
    a = a + b;
    count++ //統計 a=a+b做幾次
}
count ++;// for最後失敗的那一次，跳出for迴圈，實際上還是有做，因此要補上
conut++; //用來統計下面的return
return a;
```



T(P)= 指令執行次數之統計= 2n+1+1(每行被執行了幾次)=2n+2次



範例2. 考慮指令之難易程度



| Source Code      | S/E  | Frequency | Total |
| ---------------- | ---- | --------- | ----- |
| for(i=1;i≦n;i++) | 4    | n+1       | 4n+4  |
| {a=a+b}          | 2    | n         | 2n    |
| return a         | 1    | 1         | 1     |
|                  |      |           | 6n+5  |



 利用S/E (Steps per Execution`每執行一次要花幾步，開心要怎麼定就怎麼定`)區別指令難易程度 S/E高，代表較難



## 研究所的Time分析考型

1. 計算某行指令執行次數

2. Asymptotic`漸進式` Notations`符號`定義、大小、定理

   (O,Ω,θ,o,w)

3. Recursive time function遞迴時間函數計算/求解 (eq. Honai Tower:T(n)+2*T(n-1)+1)

4. 給一遞迴演算法Recursive algo/code寫出Time Function求解





[006]

## [複習] 數學公式

1. 等差數列

   公式：(首項＋尾項) * 項數 / 2

2. 等比數列

   公式：((最高項)<sup>exp+1</sup>- (最低項))/公比-1

   範例：r<sup>0</sup>+r<sup>1</sup>+r<sup>2</sup>+...+r<sup>n</sup> = (r<sup>n+1</sup>-1) /  r-1 = (r<sup>n+1</sup> -r<sup>0</sup>)/(r-1)

3. 平方和公式：

   公式：(n(n+1)(2n+1))/6

   範例：1<sup>2</sup>+2<sup>2</sup>+3<sup>2</sup>+...+n<sup>2</sup>

4. Σ i<sup>d</sup> 約莫是 n<sup>d+1</sup>的多項式，d ≧之 int

5. Σ 1/i = log n (底數為2) (調和數列)

6. 排列組合 C幾取幾之計算

7. n!之相關式子

   1. n! = 1* 2 * ... n ≦ n * n * n =n<sup>n</sup>
   2. n! ≧ (n/2) <sup>n/2</sup> (離散)
   3. Striling's 公式
   4. n ! ≒ n <sup>n+(1/2)</sup> * e<sup>-n</sup>, e 為自然對數之底

8. Σ i x 2 <sup>i</sup> 解法為

   令S= Σ i x 2 <sup>i</sup>，因此S= 1x2 +2x2 <sup>2</sup> + 3x3<sup>3</sup>+...nx2<sup>n</sup>，兩邊同x2，為

   2S = 1x2<sup>2</sup> +2x2 <sup>3</sup> + 3x3<sup>4</sup>+...nx2<sup>n+1</sup> 

   然後兩邊相減，得出 S = -2<sup>1</sup>-2<sup>2</sup>-2<sup>3</sup>-...-2<sup>n</sup> + n* 2 <sup>n+1</sup>=經過很多推導之後=n*2<sup>n+1</sup>-2<sup>n+1</sup>+2

   ![image-20230422162944363](https://i.imgur.com/IzFs5at.png)

   Note：其他相似型也是如此求法

   ![image-20230422162934574](https://i.imgur.com/FW5KmGA.png)

9. 對數系列(底數預設為2)

   ![image-20230422164130892](https://i.imgur.com/SuDvTIq.png)

   ![image-20230422164402270](https://i.imgur.com/nMuKk2l.png)

   ![image-20230422164740452](https://i.imgur.com/jYTm1Fo.png)

   ![image-20230422165056867](https://i.imgur.com/uZrADYQ.png)

   

   

## 給Code，求某行指令執行次數或Big-Oh

例１

```pseudocode
for i = 1 to n do
	for j = 1 to n do
		x++;

求x ++ 執行次數
ans :　ｎ＊ｎ次
```



例２

```psu
for i = 1 to n do
	for j = 1 to i do
		x++;

求x ++ 執行次數
ans :　(1+n)*n/2次

```



<span style='color:yellow'>針對i++, i--之 Loop，可用級數求解</span>

```ps
for i = 1 to n do
	for j = i to n do
		x++;

求x ++ 執行次數
ans :　n+(n-1)+(n-2)...+1 = (n+1)n/2
```

![image-20230422171306799](https://i.imgur.com/P9HN3rX.png)





![image-20230422171624148](https://i.imgur.com/ItHy0Kw.png)

​	

<span style='color:yellow;font-size:32px'>太基本，直接跳過</span>



[007]



例題一



```pseudocode
for i = 1 to n do
	for j = 1 to n*n
		if(j%i ==0) then
			for k = 1 to j do
				x++
```



| i=1                | i=2                         | i=3                           |
| ------------------ | --------------------------- | ----------------------------- |
| j=1 to 1           | j=1 to 4                    | j= 1 to 9                     |
| j % i ==0 when j=1 | j % i == 0 when j = 2 and 4 | j % i ==0 when j = 3 ,6 and 9 |
| 1次                | 2+4次                       | 3+6+9次                       |



若i=4時，x會加 4+8+12+16次，也就是4(1+2+3+4)，若i是n時，x會加



n(1+2+..+n)次 = n((1+n)*n)/2 

![image-20230422231955941](https://i.imgur.com/M2zZgGv.png)



## Asymptotic Notations 

漸進式符號

目的：表示時間函數之<span style='color:yellow'>成長速率(Growth rate)之等級</span> 

符號種類：

1. Big-Oh：O
2. Omega：Ω
3. Theta：θ
4. Little-Oh：o
5. Little-Omega：ω



## Big-Oh

定義：F(n)= O(g(n)) iff`(若且為若)` exitst two postitive constatnts C and N0 such that f(n)≦ C* g(n)，對所有n≧N0

Note：Big-Oh代表理論之上限值(upper-Bound)





例：f(n)=5n<sup>2</sup>+8n-3，則f(n) = O(n<sup>2</sup>)

proof：<span style='color:yellow'>可找到兩個正常數，C=6,N0=8，使得5n<sup>2</sup>+8n-3≦C*n<sup>2</sup></span>，所以f(n) = O(n<sup>2</sup>)

解法如下，通常會先取最大次項的項數，將他+1

![image-20230423000037106](https://i.imgur.com/uckRsKC.png)



例：f(n) = 3n<sup>2</sup>+8，則f(n)=O(n)是錯的

![image-20230423115002262](https://i.imgur.com/7wTxgD1.png)





<span style='color:yellow'>例：log(n!) = O (nLogn) ☆☆☆☆</span>

ans

![image-20230423120053961](https://i.imgur.com/COCV1GI.png)



<span style='color:yellow'>例</span>

![image-20230423123121376](https://i.imgur.com/ODQ2Db1.png)





例：

```pseudocode
for (i=1;i<=n;i++)
	for(j=1; j<=i; j*=2)
		x++;
```

求此Code之Time=O(?)

![image-20230423125327318](https://i.imgur.com/drPI5Oh.png)





## 比較Growth rate等級之大小



### 例１基本型

Growth rate：小  ---> 大













<span style='color:yellow'></span>

<u></u>

<sup></sup>

<span style='color:red'></span>

<u></u>

<sup></sup>

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

