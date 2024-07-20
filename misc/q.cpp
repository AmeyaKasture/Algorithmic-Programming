#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
#define int long long
int ll,rr,cc,kk;


bool is_valid(int l1,int r1,int c1){
    if(l1<0 || l1>=ll ||c1<0 || c1>=cc ||r1<0 || r1>=rr)return false;
    return true;
}


int solve(vector<vector<vector<int>>> &grid){
    queue<vector<int>> q;
    int count;
    vector<vector<vector<int>>> visited2(ll,
            vector<vector<int>>(rr,
                vector<int>(cc, 0)
            )
        );
        int ans=0;
        int counter=0;
        count=0;
        for(int ii=0;ii<ll;ii++){
            for(int jj=0;jj<rr;jj++){
                for(int dd=0;dd<cc;dd++){
                    if(!visited2[ii][jj][dd] && grid[ii][jj][dd]==1){
                        // cout<<ii<<"\t"<<jj<<"\t"<<dd<<endl;
                        ans+=count;
                        // cout<<count<<endl;
                        counter++;
                        q.push({ii,jj,dd});
                        visited2[ii][jj][dd]=1;
                        count=0;
                        while(!q.empty()){
                            int n=q.size();
                            for(int i=0;i<n;i++){
                                auto temp=q.front();
                                count++;
                                q.pop();
                                int l=temp[0];
                                int r=temp[1];
                                int c=temp[2];
                                for(int i=-1;i<2;i++){
                                    for(int j=-1;j<2;j++){
                                        for(int d=-1;d<2;d++){
                                            if(d==0 && i==0 && j==0)continue;
                                            int nl=l+i;
                                            int nr=r+j;
                                            int nc=(d+c+cc)%cc;
                                            if(is_valid(nl,nr,nc) && grid[nl][nr][nc]==1 && !visited2[nl][nr][nc]){
                                                visited2[nl][nr][nc]=1;
                                                q.push({nl,nr,nc});
                                            }
                                        }
                                    }
                                }
                            }
                        
                        }

                    }
                }
            }
        }
    ans+=count;
    ans=ans/counter;
    return ans; 
}

int32_t main(){
     cin>>ll>>rr>>cc>>kk;
    vector<int> src(3),dest(3);
    for(int i=0;i<3;i++){
        cin>>src[i];
    }
    src.push_back(kk);
    for(int i=0;i<3;i++){
        cin>>dest[i];
    }

    vector<vector<vector<int>>> grid(ll,
    vector<vector<int>>(rr,
        vector<int>(cc, -1)
    )
);
 vector<vector<vector<vector<int>>>> visited(ll,
    vector<vector<vector<int>>>(rr,
        vector<vector<int>>(cc,
            vector<int>(kk, 0)
        )
    )
);
    for(int i=0;i<ll;i++){
        for(int j=0;j<rr;j++){
            for(int d=0;d<cc;d++){
                cin>>grid[i][j][d];
            }
        }
    }
    cout<<solve(grid)<<endl;
    
    
  return 0;
}
