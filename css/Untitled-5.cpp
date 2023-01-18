#include<bits/stdc++.h>
using namespace std;
class process
{
    public: int Process_number ;
    public: int Arrival_time;
    public: int  Running_time;

};
void viewS(stack<process>s,string sname )//to view stack elements
    {
        stack<process>sc;
        sc=s;
        int i=1;
        cout<<sname<<endl<<"  "<<"Process number "<<"Arrival time "<<"Running time "<<endl<<endl;
        while(!sc.empty())
        {
            cout<< i <<"         " <<sc.top().Process_number<<"         "<<sc.top().Arrival_time<<"          "<<sc.top().Running_time<<endl;
            sc.pop();
            i++;
        }
    }
void viewQ(queue<process>q,string qname )//to view queue elements
{
    int i=1;
    cout<<qname<<endl<<"  "<<"Process number "<<"Arrival time "<<"Running time "<<endl<<endl;
    if(qname!="Queue4")
    {
        queue<process>qc;
        qc=q;

        while(!qc.empty())
        {
            cout<< i <<"         " <<qc.front().Process_number<<"         "<<qc.front().Arrival_time<<"          "<<qc.front().Running_time<<endl;
            qc.pop();
            i++;
        }
    }else
    {
        while(!q.empty())
    {
        cout<< i <<"         " <<q.front().Process_number<<"         "<<q.front().Arrival_time<<"          "<<q.front().Running_time<<endl;
        q.pop();
        i++;
    }
    }
}
int main()
{
    srand(time(0));
    int n;
    cin>>n;
    process p;
        queue<process>q1;
        queue<process>q2;
        stack<process>s1;
        queue<process>q3;
        stack<process>s2;
        queue<process>q4;

    for(int i=1 ;i<=n ;i++)
    {
        p.Process_number=i;
        p.Arrival_time=1+(rand()%20);
        p.Running_time=1+(rand()%60);
        q1.push(p);
    }
    while(!q1.empty())
        {
            int r=1+(rand()%4);
            p.Process_number=q1.front().Process_number;
            p.Arrival_time=q1.front().Arrival_time;
            p.Running_time=q1.front().Running_time;
            q1.pop();
            if(r==1)
            {
                q2.push(p);
            }
            else if(r==2)
            {
                s1.push(p);
            }
            else if(r==3)
            {
                q3.push(p);
            }
            else
            {
                s2.push(p);
            }
        }
    viewQ(q2,"Queue2");
    viewS(s1,"Stack1");
    viewQ(q3,"Queue3");
    viewS(s2,"Stack2");
while(!q2.empty()||!s1.empty()||!q3.empty()||!s2.empty())
{
    int r=1+(rand()%4);
    if(r==1&&!q2.empty())
        {
            p.Process_number=q2.front().Process_number;
            p.Arrival_time=1+(rand()%20);
            p.Running_time=1+(rand()%60);
            q2.pop();
            q4.push(p);
        }
    else if(r==2&&!s1.empty())
        {
            p.Process_number=s1.top().Process_number;
            p.Arrival_time=1+(rand()%20);
            p.Running_time=1+(rand()%60);
            s1.pop();
            q4.push(p);
        }
    else if(r==3&&!q3.empty())
        {
            p.Process_number=q3.front().Process_number;
           p.Arrival_time=1+(rand()%20);
            p.Running_time=1+(rand()%60);
            q3.pop();
            q4.push(p);
        }
    else if(r==4&&!s2.empty())
        {
            p.Process_number=s2.top().Process_number;
            p.Arrival_time=1+(rand()%20);
            p.Running_time=1+(rand()%60);
            s2.pop(); 
            q4.push(p);
        }
        }
    viewQ(q4,"Queue4");
    return 0;
}