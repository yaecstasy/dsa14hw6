#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<utility>
extern "C"
{
   #include"avl_ntudsa.h"
}
using namespace std;

void FindRank(const struct avl_node *node,int Rank){
    if(node==NULL)
        return;
    if(((node->avl_cnode[0])+1)==Rank){
        cout<<(*(pair<string,vector<int> >*)(node->avl_data)).first<<endl;
    }
    else if(((node->avl_cnode[0])+1)>Rank)
        FindRank(node->avl_link[0],Rank);
    else if(((node->avl_cnode[0])+1)<Rank)
    {
        Rank=Rank-(node->avl_cnode[0]+1);
        FindRank(node->avl_link[1],Rank);
    }
}
int compare(const void *pa,const void *pb,void *param){
    pair<string, vector<int> >   a=*(const pair<string, vector<int> >  *)pa;
    pair<string, vector<int> >   b=*(const pair<string, vector<int> >  *)pb;
    if ((a.second)[5]>(b.second)[5]){
        cout<<(a.second)[0]<<endl;
        cout<<(b.second)[0]<<endl;
        return -1;
    }
    else if((a.second)[5]>(b.second)[5]){
       return +1;
    }    
    else{
       if((a.second)[1]>(b.second)[1])
           return -1;
       else if ((a.second)[1]<(b.second)[1])
           return 1;
       else{
           if((a.second)[2]>(b.second)[2])
               return -1;
           else if ((a.second)[1]<(b.second)[1])
               return 1;
           else{
               if((a.second)[4]>(b.second)[4])
                   return -1;
               else if ((a.second)[4]<(b.second)[4])
                   return 1;
               else{
                  if ((a.second)[3]>(b.second)[3])
                      return -1;
                  else if ((a.second)[3]<(b.second)[3])
                      return 1;
                  else{
                      if ((a.second)[0]>(b.second)[0])
                          return -1;
                      else if ((a.second)[0]<(b.second)[0])
                          return 1;
                      else{
                          if (a.first>b.first)
                              return 1;
                          else if (a.first<b.first)
                              return -1;
                        
                      }
                  }
               }
           }
       }
    }
}
#define MAX (1000000)
pair<string, vector<int> > student[MAX];
int main(int argc,  char* argv[]){
    string query;
    int Rank;
    int N=0;
    vector<int> score(5,0);
    struct avl_table *avltree;
    avltree=avl_create(compare,NULL,NULL);

    while (cin >> query)
    {
      if(query=="push"){
         string ID; 
         cin>>ID;
         cin>>score[0];
         cin>>score[1];
         cin>>score[2];
         cin>>score[3];
         cin>>score[4];
         score[5]=(score[0]+score[1]+score[2]+score[3]+score[4])/5;
         student[N].first=ID;
         student[N].second=score;
         void  **p=avl_probe(avltree,&(student[N]));
         N++;
      }    

      else if(query=="search"){
        cin>>Rank;
        FindRank(avltree->avl_root,Rank);
      }
    }
    return 0;
}
