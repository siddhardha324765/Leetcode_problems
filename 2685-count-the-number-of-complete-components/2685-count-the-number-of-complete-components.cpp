class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>count(n);
        vector<vector<bool>>matrix(n,vector<bool>(n,false));
        for(int i=0;i<edges.size();i++){
            count[edges[i][0]]++;
            count[edges[i][1]]++;
            matrix[edges[i][0]][edges[i][1]]=true;
            matrix[edges[i][1]][edges[i][0]]=true;
        }
        vector<bool>ver(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(ver[i]==false){
                vector<int>my_vertex;
                queue<int>check;
                check.push(i);
                my_vertex.push_back(i);
                ver[i]=true;
                while(check.size()!=0){
                    int index=check.front();
                    check.pop();
                    for(int j=0;j<n;j++){
                        if(matrix[index][j] and ver[j]==false){
                            ver[j]=true;
                            my_vertex.push_back(j);
                            check.push(j);
                        }
                    }
                }
                if(my_vertex.size()<=2){
                    ans++;
                }
                else{
                    int m=my_vertex.size()-1;
                    bool flag=true;
                    for(int j=0;j<my_vertex.size();j++){
                         if(count[my_vertex[j]]!=m){
                            flag=false;
                            break;
                         }
                    }
                    if(flag==true){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};