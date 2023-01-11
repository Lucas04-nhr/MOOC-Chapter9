/*
    请要求完成分数类中缺失的的成员函数，并使用指定的代码测试该类。
    要求：
    1. 创建分数时，分母默认非0，代码无需考虑分母为0时的处理
    2. 分数相除时，除数的分子默认非0，代码无需考虑分子为0时的处理
    3. 分数的加法、除法运算结果需化简为最简分数
    4. 构造函数和重置函数setfrac都不用对分数化简。
    5. 如果分母为负数，构造函数和重置函数setfrac要将其变为正数。（25分）
    ->分数类
*/

#include <iostream>

using namespace std;

class fraction{
private:
    int above;         //分子
    int below;         //分母
    int gcd(int,int);//求两个数的最大公约数
    int lcm(int,int);//求两个数的最小公倍数
public:
    fraction();
    fraction(int ,int);
    void reduction();  //约分
    fraction add(fraction);      //两分数相加
    fraction div (fraction);      //两分数相除
    void setfrac(int ,int); //重置分数
    void display(); //显示分数
};

void fraction::display()
{
    if(below<0){
        above=-above;
        below=-below;
    }
    if(above ==0)
        cout<<0<<endl;
    else if(below ==1)
        cout<<above<< endl;
    else
        cout<< above<<'/'<< below <<endl;
}

fraction::fraction(){
    above=0;
    below=1;
}

fraction::fraction(int a, int b=1):above(a),below(b){}

int fraction::gcd(int a, int b){
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
//辗转相除法

int fraction::lcm(int a, int b){
    return a*b/gcd(a,b);
}

void fraction::reduction(){
    above = above / gcd(above,below);
    below= below /gcd(above,below);
}

//将分母变为一致后再相加
fraction fraction::add(fraction b){
    fraction result;
    result.below =below * b.below;
    result .above = above * b.below + b.above * below;
    result.reduction();
    return result;
}

//除法转化为乘法
fraction fraction::div(fraction b){
    fraction result;
    result.above = above * b.below;
    result.below = below *b.above;
    result.reduction();
    return result;
}

void fraction::setfrac(int a, int b){
    above = a;
    below=b;
}


//->测试代码，测试结果应和输出样例中完全相同
int main(){
    cout<<"--------测试构造函数-----------"<<endl;
    fraction f1(20,-9),f2(-7,-9),f3(5,-9);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3="; f3.display();
    cout<<"--------测试加法函数-----------"<<endl;
    f3=f1.add(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1+f2=";f3.display();
    f1.setfrac(-3,-15);f2.setfrac(-10,12); f3=f1.add(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1+f2=";f3.display();
    f1.setfrac(12,45); f2.setfrac(19,-30); f3=f1.add(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1+f2=";f3.display();
    f1.setfrac(3,5); f2.setfrac(-9,15); f3=f1.add(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1+f2=";f3.display();
    cout<<"--------测试除法函数-----------"<<endl;
    f1.setfrac(-24,7); f2.setfrac(16,35); f3=f1.div(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1/f2=";f3.display();
    f1.setfrac(33,-45); f2.setfrac(-11,20); f3=f1.div(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1/f2=";f3.display();
    f1.setfrac(12,35); f2.setfrac(-24,7); f3=f1.div(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1/f2=";f3.display();
    f1.setfrac(-11,20); f2.setfrac(33,-50); f3=f1.div(f2);
    cout<<"f1="; f1.display();
    cout<<"f2="; f2.display();
    cout<<"f3=f1/f2=";f3.display();
    cout<<"------------测试结束------------"<<endl;
    return 0;
}

/*
    --------测试构造函数-----------
    f1=-20/9
    f2=7/9
    f3=-5/9
    --------测试加法函数-----------
    f1=-20/9
    f2=7/9
    f3=f1+f2=-13/9
    f1=3/15
    f2=-10/12
    f3=f1+f2=-19/30
    f1=12/45
    f2=-19/30
    f3=f1+f2=-11/30
    f1=3/5
    f2=-9/15
    f3=f1+f2=0
    --------测试除法函数-----------
    f1=-24/7
    f2=16/35
    f3=f1/f2=-15/2
    f1=-33/45
    f2=-11/20
    f3=f1/f2=4/3
    f1=12/35
    f2=-24/7
    f3=f1/f2=-1/10
    f1=-11/20
    f2=-33/50
    f3=f1/f2=5/6
    ------------测试结束------------
*/