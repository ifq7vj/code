#include<bits/stdc++.h>
using namespace std;int main(int c,char**v){string s,r,l;cin>>s;for(int f=1,p;f
;){ifstream i(v[1]);for(f=0;i.peek()+1;){getline(i,r,'=');getline(i,l);for(;p=s
.find(r)+1;s.replace(f=p-1,r.size(),l));}}cout<<s<<endl;}
