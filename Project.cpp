#include <bits/stdc++.h>
using namespace std;

string print="";
string POSTFIX(string);
string PREFIX(string);

bool isOperand(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
        return true;
    }
    else return false;
}

string postfixtoprefix(string postfix)
{
    stack<string> s;
    for(int i=0; i< postfix.length(); i++)
    {
        if(isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expression = postfix[i] + op2 + op1;
            s.push(expression);

        }
    }
    return s.top();
}

string PREFIX(string prefix)
{
    string p,postfix;
    for(int i=prefix.length()-1; i>=0; i--)
    {
        if(prefix[i]==')')
            p+='(';
        else if(prefix[i]=='(')
            p+=')';
        else
            p+=prefix[i];
    }
    postfix=POSTFIX(p);
    reverse(postfix.begin(),postfix.end());
    return postfix;
}


string POSTFIX(string infix)
{
    string postfix;
    stack<char> s;
    int p=0;
    for(int i=0; i<infix.length(); i++)
    {
        switch(infix[i])
        {
        case '+':
            if(p>=1)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=1;
            break;
        case '-':
            if(p>=1)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=1;
            break;
        case '*':
            if(p>=2)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=2;
            break;
        case '/':
            if(p>=2)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=2;
            break;
        case '^':
            s.push(infix[i]);
            p=3;
            break;
        case '(':
            s.push(infix[i]);
            p=0;
            break;
        case ')':
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
            if(s.empty())
                p=0;
            else if(s.top()=='+'||s.top()=='-')
                p=1;
            else if(s.top()=='*'||s.top()=='/')
                p=2;
            else if(s.top()=='^')
                p=3;
            break;
        default:
            postfix+=infix[i];
            break;
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}


void asm3(string x)
{

    if(x[0]=='+')
    {
        print = print+ "ADD "+x[1]+" <- "+x[1]+x[2];
    }
    if(x[0]=='-')
    {
        print = print+ "SUB "+x[1]+" <- "+x[1]+x[2];
    }
    if(x[0]=='*')
    {
        print = print+ "MUL "+x[1]+" <- "+x[1]+x[2];
    }
    if(x[0]=='/')
    {
        print = print+ "DIV "+x[1]+" <- "+x[1]+x[2];
    }

}

void asm4(string x)
{

    if(x[0]=='+')
    {
        print = print+ "ADD "+x[1]+" <- "+x[2]+x[3];
    }
    if(x[0]=='-')
    {
        print = print+ "SUB "+x[1]+" <- "+x[2]+x[3];
    }
    if(x[0]=='*')
    {
        print = print+ "MUL "+x[1]+" <- "+x[2]+x[3];
    }
    if(x[0]=='/')
    {
        print = print+ "DIV "+x[1]+" <- "+x[2]+x[3];
    }

}

void asm5(string x)
{
    string send;
    send.push_back(x[2]);
    send.push_back(x[3]);
    send.push_back(x[4]);
    // cout<<send;
    asm3(send);

    if(x[0]=='+')
    {
        print = print+ "\nADD "+x[1]+" <- "+x[1]+x[3];
    }
    if(x[0]=='-')
    {
        print = print+ "\nSUB "+x[1]+" <- "+x[1]+x[3];
    }
    if(x[0]=='*')
    {
        print = print+ "\nMUL "+x[1]+" <- "+x[1]+x[3];
    }
    if(x[0]=='/')
    {
        print = print+ "\nDIV "+x[1]+" <- "+x[1]+x[3];
    }
}

void asm6(string x)
{
    string send;
    send.push_back(x[2]);
    send.push_back(x[3]);
    send.push_back(x[4]);
    send.push_back(x[5]);
    // cout<<send;
    asm4(send);

    if(x[0]=='+')
    {
        print = print+ "\nADD "+x[1]+" <- "+x[1]+x[3];
    }
    if(x[0]=='-')
    {
        print = print+ "\nSUB "+x[1]+" <- "+x[1]+x[3];
    }
    if(x[0]=='*')
    {
        print = print+ "\nMUL "+x[1]+" <- "+x[1]+x[3];
    }
    if(x[0]=='/')
    {
        print = print+ "\nDIV "+x[1]+" <- "+x[1]+x[3];
    }
}

void asm6alt(string x)
{
    string send,send2;
    send.push_back(x[3]);
    send.push_back(x[4]);
    send.push_back(x[5]);
    // cout<<send;
    asm3(send);
    print= print+"\n";
    send2.push_back(x[0]);
    send2.push_back(x[1]);
    send2.push_back(x[2]);
    send2.push_back(x[4]);
    asm4(send2);

}

void asm7(string x)
{

    string send,send2;
    send.push_back(x[3]);
    send.push_back(x[4]);
    send.push_back(x[5]);
    send.push_back(x[6]);
    // cout<<send;
    asm4(send);
    print= print+"\n";
    send2.push_back(x[0]);
    send2.push_back(x[1]);
    send2.push_back(x[2]);
    send2.push_back(x[4]);
    asm4(send2);

}

void asm7alt(string x)
{

    string send,send2,send3;
    send.push_back(x[4]);
    send.push_back(x[5]);
    send.push_back(x[6]);
    // cout<<send;
    asm3(send);
    print= print+"\n";
    send2.push_back(x[2]);
    send2.push_back(x[3]);
    send2.push_back(x[5]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[0]);
    send3.push_back(x[1]);
    send3.push_back(x[3]);
    asm3(send3);

}

void asm7alt2(string x)
{

    string send,send2,send3;
    send.push_back(x[4]);
    send.push_back(x[5]);
    send.push_back(x[6]);
    // cout<<send;
    asm3(send);
    print= print+"\n";
    send2.push_back(x[1]);
    send2.push_back(x[2]);
    send2.push_back(x[3]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[0]);
    send3.push_back(x[2]);
    send3.push_back(x[5]);
    asm3(send3);

}
void asm7alt3(string x)
{

    string send,send2,send3;
    send.push_back(x[3]);
    send.push_back(x[4]);
    send.push_back(x[5]);
    // cout<<send;
    asm3(send);
    print= print+"\n";
    send2.push_back(x[1]);
    send2.push_back(x[2]);
    send2.push_back(x[4]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[0]);
    send3.push_back(x[2]);
    send3.push_back(x[6]);
    asm3(send3);

}

void asm8(string x)
{
    string send,send2,send3;
    send.push_back(x[4]);
    send.push_back(x[5]);
    send.push_back(x[6]);
    send.push_back(x[7]);
    asm4(send);
    print= print+"\n";
    send2.push_back(x[2]);
    send2.push_back(x[3]);
    send2.push_back(x[5]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[0]);
    send3.push_back(x[1]);
    send3.push_back(x[3]);
    asm3(send3);

}

void asm8alt2(string x)
{

    string send,send2,send3;
    send.push_back(x[5]);
    send.push_back(x[6]);
    send.push_back(x[7]);
    asm3(send);
    print= print+"\n";
    send2.push_back(x[3]);
    send2.push_back(x[4]);
    send2.push_back(x[6]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[0]);
    send3.push_back(x[1]);
    send3.push_back(x[2]);
    send3.push_back(x[4]);
    asm4(send3);
}

void asm8alt(string x)
{
    if(x[3]=='+'||x[3]=='-'||x[3]=='*'||x[3]=='/')
    {
        asm8alt2(x);
    }
    else
    {
        string send,send2,send3;
        send.push_back(x[5]);
        send.push_back(x[6]);
        send.push_back(x[7]);
        asm3(send);
        print= print+"\n";
        send2.push_back(x[2]);
        send2.push_back(x[3]);
        send2.push_back(x[4]);
        send2.push_back(x[6]);
        asm4(send2);
        print= print+"\n";
        send3.push_back(x[0]);
        send3.push_back(x[1]);
        send3.push_back(x[3]);
        asm3(send3);
    }
}

void asm9(string x)
{
    string send,send2,send3,send4;
    send.push_back(x[6]);
    send.push_back(x[7]);
    send.push_back(x[8]);
    asm3(send);
    print= print+"\n";
    send2.push_back(x[4]);
    send2.push_back(x[5]);
    send2.push_back(x[7]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[2]);
    send3.push_back(x[3]);
    send3.push_back(x[5]);
    asm3(send3);
    print= print+"\n";
    send4.push_back(x[0]);
    send4.push_back(x[1]);
    send4.push_back(x[3]);
    asm3(send4);
}

void asm9alt(string x)
{
    //cout<<"asm9alt ";
    string send,send2,send3,send4;
    send.push_back(x[5]);
    send.push_back(x[6]);
    send.push_back(x[7]);
    asm3(send);
    print= print+"\n";
    send2.push_back(x[3]);
    send2.push_back(x[4]);
    send2.push_back(x[6]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[1]);
    send3.push_back(x[2]);
    send3.push_back(x[4]);
    asm3(send3);
    print= print+"\n";
    send4.push_back(x[0]);
    send4.push_back(x[2]);
    send4.push_back(x[8]);
    asm3(send4);
}
void asm9alt2(string x)
{
    //cout<<"asm9alt2 ";
    string send,send2,send3,send4;
    send.push_back(x[5]);
    send.push_back(x[6]);
    send.push_back(x[7]);
    asm3(send);
    print= print+"\n";
    send2.push_back(x[2]);
    send2.push_back(x[3]);
    send2.push_back(x[4]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[1]);
    send3.push_back(x[3]);
    send3.push_back(x[6]);
    asm3(send3);
    print= print+"\n";
    send4.push_back(x[0]);
    send4.push_back(x[3]);
    send4.push_back(x[8]);
    asm3(send4);
}
void asm9alt3(string x)
{
    string send,send2,send3,send4;
    send.push_back(x[4]);
    send.push_back(x[5]);
    send.push_back(x[6]);
    asm3(send);
    print= print+"\n";
    send2.push_back(x[2]);
    send2.push_back(x[3]);
    send2.push_back(x[5]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[1]);
    send3.push_back(x[3]);
    send3.push_back(x[7]);
    asm3(send3);
    print= print+"\n";
    send4.push_back(x[0]);
    send4.push_back(x[3]);
    send4.push_back(x[8]);
    asm3(send4);
}
void asm9alt4(string x)
{
    string send,send2,send3,send4;
    send.push_back(x[3]);
    send.push_back(x[4]);
    send.push_back(x[5]);
    asm3(send);
    print= print+"\n";
    send2.push_back(x[2]);
    send2.push_back(x[4]);
    send2.push_back(x[6]);
    asm3(send2);
    print= print+"\n";
    send3.push_back(x[1]);
    send3.push_back(x[4]);
    send3.push_back(x[7]);
    asm3(send3);
    print= print+"\n";
    send4.push_back(x[0]);
    send4.push_back(x[4]);
    send4.push_back(x[8]);
    asm3(send4);
}

void XD(string c){
    cout << endl;
    cout << "ASSAMBLY is given below: " << endl;
    cout << "------------------------" << endl;
    if(c.length()==3){
        asm3(c);
    }
    if(c.length()==4){
        asm4(c);
    }
    if(c.length()==5){
        asm5(c);
    }
    if(c.length()==6){
        if(c[3]=='+'||c[3]=='-'||c[3]=='*'||c[3]=='/'){
            asm6alt(c);
        }
        else{
            asm6(c);
        }
    }
    if(c.length()==7){
        if(c[4]=='+'||c[4]=='-'||c[4]=='*'||c[4]=='/'){
            if(c[1]!='+'&&c[1]!='-'&&c[1]!='*'&&c[1]!='/'){
                asm7alt(c);
            }
            else if((c[0]=='+'||c[0]=='-'||c[0]=='*'||c[0]=='/')
                    &&((c[1]=='+'||c[1]=='-'||c[1]=='*'||c[1]=='/'))){
                asm7alt2(c);
            }
        }
        else if((c[0]=='+'||c[0]=='-'||c[0]=='*'||c[0]=='/')
                &&((c[1]=='+'||c[1]=='-'||c[1]=='*'||c[1]=='/'))){
            if(c[3]=='+'||c[3]=='-'||c[3]=='*'||c[3]=='/'){
                asm7alt3(c);
            }
            else{
                asm7alt2(c);
            }
        }
        else{
            asm7(c);
        }
    }
    if(c.length()==8){
        if(c[5]=='+'||c[5]=='-'||c[5]=='*'||c[5]=='/'){
            asm8alt(c);
        }
        else{
            asm8(c);
        }
    }
    if(c.length()==9){
        if((c[0]=='+'||c[0]=='-'||c[0]=='*'||c[0]=='/')
           &&(c[1]=='+'||c[1]=='-'||c[1]=='*'||c[1]=='/')){
            if(c[2]=='+'||c[2]=='-'||c[2]=='*'||c[2]=='/'){
                if(c[4]=='+'||c[4]=='-'||c[4]=='*'||c[4]=='/'){
                    asm9alt3(c);
                }
                else if(c[3]=='+'||c[3]=='-'||c[3]=='*'||c[3]=='/'){
                    asm9alt4(c);
                }
                else{
                    asm9alt2(c);
                }
            }
            else{
                asm9alt(c);
            }
        }
        else{
            asm9(c);
        }
    }
    cout<< print<<"\n";
    print= "";
    cout << endl;
    cout << endl;
}
int main()
{
    string c;
    while(1)
    {
        cout<<
            "***********************************\n"
            "*                                 *\n"
            "*    1 -> INFIX to ASSEMBLY.      *\n"
            "*    2 -> PREFIX to ASSEMBLY.     *\n"
            "*    3 -> POSTFIX to ASSEMBLY.    *\n"
            "*    4 -> EXIT.                   *\n"
            "*                                 *\n"
            "***********************************\n"
            ;

        int option;
        string data ;
        cout<< "\nEnter your option:";
        cin>> option;
        cout<< "\n";
        if(option <1 || option>4)cout <<"Enter option between 1 to 4.\n\n";

        else
        {
            switch(option)
            {
            case 1:
                cout << "Enter INFIX:";
                cin>> data;
                c = PREFIX(data);
                cout << "INFIX: " << data << endl;
                cout << "PREFIX: " << c << endl;
                if(c.length()>=10)
                {
                    cout << "The generated prefix's length is: " << c.length() << endl <<
                         "We implemented this code for maximum 9 length prefix code." << endl <<
                         "Please, input another." << endl;
                    break;
                }
                XD(c);
                break;

            case 2:
                cout << "Enter PREFIX:";
                cin>> data;
                cout << "PREFIX: " << data << endl;
                XD(data);
                break;

            case 3:
                cout << "Enter POSTFIX:";
                cin>> data;
                c = postfixtoprefix(data);
                cout << "POSTFIX: " << data << endl;
                cout << "PREFIX: " << c << endl;
                if(c.length()>=10)
                {
                    cout << "The generated prefix's length is: " << c.length() << endl <<
                         "We implemented this code for maximum 9 length prefix code." << endl <<
                         "Please, input another." << endl;
                    break;
                }
                XD(c);
                break;

            case 4:
                return 0;

            }
        }
    }
}
