/*
    请完整戏票类的实现代码。并使用测试代码测试该类，测试代码的运行结果应和输出样例完全相同。注意，
    1. booking函数的购票失败提示示例如下，编写代码时请复制其中的标点符号，以免由于中英文编码问题导致判分失效
            余票(11)不足，购买失败
    2. 输出的“：”都是中文“：”（25分）
*/

//->戏票类

#include<iostream>
#include<cstring>
using namespace std;

class opera
{
private:
    char name[30];//歌剧名称

    int ts[4]={20,100,240,300};  // ts[0]：包厢的总数，     ts[1]：一等座的总座位数
    //ts[2]：二等座的总座位数，ts[3]：三等座的总座位数

    int es[4]={20,100,240,300};// es[0]：空包厢的数量，     es[1]：一等座的空闲座位数
    //es[2]：二等座的空闲座位数，es[3]：三等座的空闲座位数

    int ps[4]={0,0,0,0};// ps[0]：包厢的票价， ps[1]：一等座的票价
    //ps[2]：二等座的票价,ps[3]：三等座的票价

    int income=0;//总收入

public:
    opera(){}; //默认构造函数，数据成员的初始值请参看输出样例
    void set_name(char *);//更改剧名
    void set_ps(int []);//更改座位价格
    void booking(int,int);//售票，如果余票小于订票数，终止该次售票，并输出购票失败提示信息
    void refund(int,int);//退票，不收手续费
    void print();
    ~opera(){}; //析构函数，完成票房统计，内容与格式请参看输出样例
    char * getName();
    int getPF(int);
    int getIncome();
};

void opera::set_name(char *InputName)
{
    strcpy(name,InputName);
}

void opera::set_ps(int *InputPrice)
{
    for(int i=0;i<4;i++)
        ps[i]=InputPrice[i];
}

void opera::booking(int a, int b)
{
    if(es[a]<b)
        cout<<"余票("<<es[a]<<")不足，购买失败"<<endl;
    else
    {
        es[a]-=b;
        income+=(ps[a]*b);
    }
}

void opera::refund(int a, int b)
{
    es[a]+=b;
    income-=(ps[a]*b);
}

char* opera::getName()
{
    return name;
}

int opera::getPF(int a)
{
    int iResult=ts[a]-es[a];
    return iResult;
}

int opera::getIncome()
{
    int iIncome=0;
    for(int i=0;i<4;i++)
        iIncome+=(ps[i]*(ts[i]-es[i]));
    return iIncome;
}

void opera::print(){
    char line[20]="------------------";
    cout<<line<<"戏曲名："<<name<<line<<endl;
    char st[4][20]={ "包厢","一等座","二等座","三等座"};
    for(int i=0;i<4;i++)
        cout<<st[i]<<"<"<<"票价："<<ps[i]<<" /总数："<<ts[i]<<" /可售："<<es[i]<<">"<<endl;
    cout<<line<<"总收入："<<income<<line<<endl<<endl;
}

//->测试代码，测试结果应和输出样例完全相同

int main()
{
    opera p1;
    p1.set_name("未命名");
    p1.print();
    p1.set_name("二进宫");//更改剧名
    int p[]={700,380,180,80};
    p1.set_ps(p);//更改座位价格

    p1.booking(0,9);//购买9张包厢票
    p1.booking(1,15);//购买15张一等票
    p1.booking(3,20);//购买20张三等票
    p1.print();

    p1.booking(0,13);//购买13张包厢票
    p1.booking(2,14);//购买14张二等票
    p1.refund(3,6);//退6张三等票
    p1.print();

    cout<<p1.getName()<<"的总收入："<<p1.getIncome()<<endl;
    cout<<p1.getName()<<"的票房如下："<<endl;
    cout<<"包厢售出"<<p1.getPF(0)<<endl;
    cout<<"一等座售出"<<p1.getPF(1)<<endl;
    cout<<"二等座售出"<<p1.getPF(2)<<endl;
    cout<<"三等座售出"<<p1.getPF(3)<<endl;

    return 0;
}