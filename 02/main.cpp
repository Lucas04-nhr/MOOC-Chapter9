/*
    设计一个时间类，其数据成员为hour（小时）、minute（分）和sec（秒），请补充类的成员函数定义，实现时间的加法与减法运算。
    并使用测试代码测试该类，运行结果应该和输出样例完全相同（25分）
*/

//->时间类
#include <iostream>
using namespace std;

class timeC{
    int hour;
    int minute;
    int sec;
public:
    timeC(int h=0, int m=0, int s=0);
    timeC add(timeC &);
    timeC minus(timeC &);
    void showtimeC();
};
//add函数使用引用作为形参是为了减少函数调用代价

timeC::timeC(int h, int m, int s){
    hour=h;
    minute=m;
    sec=s;
}

timeC timeC::add(timeC & t)
{
    timeC k;
    k.hour=hour+t.hour;
    k.minute=minute+t.minute;
    k.sec=sec+t.sec;
    int i;
    i=k.sec/60;	k.sec=k.sec%60;
    k.minute+=i;
    i=k.minute/60;	k.minute=k.minute%60;
    k.hour+=i;
    k.hour=k.hour%24;
    return k;
}

timeC timeC::minus(timeC & t)
{
    timeC k;
    k.hour=hour-t.hour;
    k.minute=minute-t.minute;
    k.sec=sec-t.sec;
    int i;
    i=k.sec/60;	k.sec=k.sec%60;
    k.minute-=i;
    i=k.minute/60;	k.minute=k.minute%60;
    k.hour-=i;
    k.hour=k.hour%24;

    if (k.sec<0){
        k.minute--;
        k.sec+=60;
    }

    if (k.minute<0){
        k.hour--;
        k.minute+=60;
    }
    return k;
}

void timeC::showtimeC(){
    cout<<hour<<" : "<<minute<<" : "<<sec<<endl;
}

//->测试代码

int main(){
    timeC t1(21,12,34),t2(12,56,45);

    timeC t3(9,23);
    t3.showtimeC();
    t3=t3.add(t2);
    t3.showtimeC();

    timeC t4;
    t4.showtimeC();
    t4=t1.minus(t2);
    t4.showtimeC();

    return 0;
}

/*
    输出样例：
    9 : 23 : 0
    22 : 19 : 45
    0 : 0 : 0
    8 : 15 : 49
 */