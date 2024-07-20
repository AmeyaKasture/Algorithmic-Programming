#include <bits/stdc++.h>
// #include <iostream>
#include<set>
using namespace std;

void print(vector<long long> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}
void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int h,w,x,y,u,v;
        cin>>h>>w>>x>>y>>u>>v;
        if(u<=x)cout<<"DRAW"<<endl;
        else{
            int steps=u-x;
            if(steps%2!=0){
                if(v>y){
                    int posr=min(v+steps/2,w);
                    int aposr=min(y+steps/2+1,w);
                    if(aposr-posr==0)cout<<"ALICE"<<endl;
                    else cout<<"DRAW"<<endl;
                }
                else if(v<y){
                    int posl=max(1,v-steps/2);
                    int aposl=max(y-steps/2-1,1);
                    if(aposl-posl==0)cout<<"ALICE"<<endl;
                    else cout<<"DRAW"<<endl;
                }
                
                // cout<<posr<<"\t"<<posr<<"\t"<<aposl<<"\t"<<aposr<<endl;
                else cout<<"ALICE"<<endl;
            }
            else{
                if(y>v){
                    int posr=min(v+steps/2,w);
                    int aposr=min(y+steps/2,w);
                    if(aposr-posr==0)cout<<"BOB"<<endl;
                    else cout<<"DRAW"<<endl;
                }
                else if(y<v){
                    int posl=max(1,v-steps/2);
                    int aposl=max(y-steps/2,1);
                    // cout<<posl<<"\t"<<aposl<<endl;
                    if(aposl-posl==0)cout<<"BOB"<<endl;
                    else cout<<"DRAW"<<endl;
                }
                
                // cout<<posr<<"\t"<<posr<<"\t"<<aposl<<"\t"<<aposr<<endl;
                else cout<<"BOB"<<endl;
            }
        }

    }
  return 0;
}
