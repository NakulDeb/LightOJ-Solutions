#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,q=1;
    cin>>t;

    while(t--){
        string cmd,url,tmp,durl="http://www.lightoj.com/";
        stack<string>backward_q;
        stack<string>forward_q;

        backward_q.push(durl);
        cout<<"Case "<<q++<<":"<<endl;
        while(1){
            cin>>cmd;
            if(cmd=="VISIT"){
                cin>>url;
                backward_q.push(url);
                forward_q = stack<string>();
                cout<<url<<endl;
            }
            else if(cmd=="BACK"){
                if(backward_q.size()>1){
                    tmp = backward_q.top();

                    backward_q.pop();
                    forward_q.push(tmp);

                    tmp = backward_q.top();
                    cout<<tmp<<endl;
                }
                else cout<<"Ignored"<<endl;
            }
            else if(cmd=="FORWARD"){
                if(forward_q.size()){
                    tmp = forward_q.top();
                    forward_q.pop();
                    cout<<tmp<<endl;
                    backward_q.push(tmp);
                }
                else cout<<"Ignored"<<endl;
            }
            else break;
        }
    }
    return 0;
}
