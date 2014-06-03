#include<iostream>
#include<string>
#include<cstring> 
#include<stdio.h>
#include<stdlib.h>
extern "C" 
{
#include"avl.h"
#include"bst.h"
#include"rb.h"
}
using namespace std;

void preorder_avl(const struct avl_node *node){
    if (node==NULL)
        return;
    cout<<(*(string *)node->avl_data);
    if (node->avl_link[0] !=NULL || node->avl_link[1]!=NULL){
        putchar('(');
        preorder_avl(node->avl_link[0]);
        putchar(',');
        putchar(' ');
        preorder_avl(node->avl_link[1]);
        putchar(')');
    }
}
void preorder_bst(const struct bst_node *node){
    if (node==NULL)
        return;
    cout<<(*(string *)node->bst_data);
    if (node->bst_link[0] !=NULL || node->bst_link[1]!=NULL){
        putchar('(');
        preorder_bst(node->bst_link[0]);
        putchar(',');
        putchar(' ');
        preorder_bst(node->bst_link[1]);
        putchar(')');
    }
}
void preorder_rb(const struct rb_node *node){
    if (node==NULL)
        return;
    cout<<(*(string *)node->rb_data);
    if (node->rb_link[0] !=NULL || node->rb_link[1]!=NULL){
        putchar('(');
        preorder_rb(node->rb_link[0]);
        putchar(',');
        putchar(' ');
        preorder_rb(node->rb_link[1]);
        putchar(')');
    }
}
int compare(const void *pa,const void *pb,void *param){
    string a=*(const string *)pa;
    string b=*(const string *)pb;
    if (a<b) return -1;
    else if (a>b) return +1;
    else return 0;
}
    
int main()
{   
    struct avl_table *avltree;
    struct rb_table *rbtree;
    struct bst_table *bsttree;
    avltree=avl_create(compare,NULL,NULL);
    rbtree=rb_create(compare,NULL,NULL);
    bsttree=bst_create(compare,NULL,NULL);
    string names[32];
    names[0]="Chuang";
    names[1]="Chou";
    names[2]="Chang";
    names[3]="Chao";
    names[4]="Chen";
    names[5]="Cheng";
    names[6]="Chu";
    names[7]="Fu";
    names[8]="Fuh";
    names[9]="Hsiang";
    names[10]="Hsu";
    names[11]="Hsueh";
    names[12]="Hung";
    names[13]="Jang";
    names[14]="Kao";
    names[15]="Kuo";
    names[16]="Lai";
    names[17]="Lee";
    names[18]="Liao";
    names[19]="Lin";
    names[20]="Liou";
    names[21]="Liu";
    names[22]="Lu";
    names[23]="Lyuu";
    names[24]="Ouhyoung";
    names[25]="Oyang";
    names[26]="Shih";
    names[27]="Tsai";
    names[28]="Tseng";
    names[29]="Wang";
    names[30]="Wu";
    names[31]="Yang";
    int i;
    for(i=0;i<32;i++){       
       void  **p=avl_probe(avltree,&names[i]);
       void  **r=rb_probe(rbtree,&names[i]);
       void  **b=bst_probe(bsttree,&names[i]);
    }
    preorder_bst(bsttree->bst_root);
    cout<<endl;
    preorder_avl(avltree->avl_root);
    cout<<endl;
    preorder_rb(rbtree->rb_root);
    //puts("");
    return 0;
}    
