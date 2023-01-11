/*
请完成手机类的成员函数定义。并使用测试代码测试该类，测试代码的运行结果应和输出示例完全相同（25分）
题目内容：
->手机类
 */
#include <iostream>
#include<cstring>
using namespace std;
class phone{
    char number[12];//11位本机号码
    char city[5];//本机归属地编号
    double fee;//本机话费余额
public:
    phone(); //默认构造函数，初始值请参看输出样例第一行
    void recharge(double m);//给手机充值
    void insertcard(char[],char[]);//设置手机号码和归属地
    double getfee();//返回本机话费
    char *getno();//返回本机号码
    char *getcity();//返回归属地
    int call(phone &other,int m);//和手机other通话m分钟，
    /*  1.归属地相同，本机支付话费，话费为每分钟0.7元。
        2.归属地不同，双方都要支付话费，本机话费为每分钟1.2元，other话费为每分钟0.7元。
        3.通话过程中，如果因为某方话费不足，通话中断，函数结束，返回实际通话时长
        通话正常完成，函数结束，返回m */
};

phone::phone(){
    strcpy(number,"08600000000");
    strcpy(city,"***");
    fee=0;
}

void phone::insertcard(char* num,char* ct){
    strcpy(number, num);
    strcpy(city,ct);
}
void phone::recharge(double m){
    fee+=m;
}

double phone::getfee(){
    return fee;
}

char* phone::getno(){
    return number;
}

char* phone::getcity(){
    return city;
}

int phone::call(phone &other, int m){
    double cost1, cost2=0;
    int minute=0;
    if(!strcmp(other.city,city))
    {
        cost1=0.7;
    }
    else
    {cost1 = 1.2;
        cost2=0.7;}
    while (minute < m)
        if (fee> cost1 && other.fee >cost2)
        {minute++;
            fee -= cost1;
            other.fee-=cost2;
        }
        else break;
    return minute;
}

void display( phone t){
    cout<<"手机号码："<<t.getno()
        <<"；归属地："<<t.getcity()
        <<"；话费余额："<<t.getfee()
        <<endl;
}

int main(){

    phone p1;
    display(p1);
    p1.insertcard("13458901211","027");	p1.recharge(40);
    phone p2,p3;
    p2.insertcard("13652901219","021");	p2.recharge(30);
    p3.insertcard("15651004523","027");	p3.recharge(50);
    char *line="*-------------------------------------------------*";
    int talk,m;
    m=35;
    talk=p1.call(p2,m);
    cout<<line<<endl;
    cout<<"p1主叫p2......."<<endl;
    if (talk==m)
        cout<<"通话时长"<<talk<<"分钟。通话结束,祝您愉快"<<endl;
    else
        cout<<"通话时长"<<talk<<"分钟。余额不足,请尽快预存话费"<<endl;
    display(p1); display(p2);
    cout<<line<<endl;
    p1.recharge(30);
    m=40;
    talk=p3.call(p1,40);
    cout<<line<<endl;
    cout<<"p3主叫p1......."<<endl;
    if (talk==m)
        cout<<"通话时长"<<talk<<"分钟。通话结束,祝您愉快........"<<endl;
    else
        cout<<"通话时长"<<talk<<"分钟。电话余额不足.......请尽快预存话费."<<endl;
    display(p3); display(p1);
    cout<<line<<endl;
    return 0;
}
/*
    输出样例：
    
    手机号码：08600000000；归属地：***；话费余额：0
    *-------------------------------------------------*
    p1主叫p2.......
    通话时长33分钟。余额不足,请尽快预存话费
    手机号码：13458901211；归属地：027；话费余额：0.4
    手机号码：13652901219；归属地：021；话费余额：6.9
    *-------------------------------------------------*
    *-------------------------------------------------*
    p3主叫p1.......
    通话时长40分钟。通话结束,祝您愉快........
    手机号码：15651004523；归属地：027；话费余额：22
    手机号码：13458901211；归属地：027；话费余额：30.4
    *-------------------------------------------------*
*/
