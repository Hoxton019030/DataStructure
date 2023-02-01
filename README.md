+++
author = "Hoxton"
title = "資料結構筆記"
date = "2022-10-08T03:02:43+08:00"
draft = "ture"
description = "資料結構的筆記" 
tags = [ "" ]
categories = [ ]
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


