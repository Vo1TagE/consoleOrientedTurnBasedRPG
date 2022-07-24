#include <iostream>
using namespace std;

float healthpool[5] = {100,150,200,250,300};
float dmgpool[5] = {28,25,22,19,15};
string classes[5] = {"Archer","Assassin","Halberdier","Fighter","Tank"};


class hero{
    public:
        string name;
        string type;
        float dmg;
        float hp;
};

int menu(string nam, string cl,int numDp,int numDo,int numHp,int numHo){
    int move;
    cout<<"|******************CURRENT STATS*******************|"<<endl;
    cout<<"| NAME  :"<<nam<<endl;
    cout<<"| CLASS :"<<cl<<"                                  |"<<endl;
    cout<<"| HEALTH:"<<numHp<<"                               |"<<endl;
    cout<<"| DAMAGE:"<<numDp<<"                               |"<<endl;  
    cout<<"|***********************ACTIONS********************|"<<endl;
    cout<<"|ATTACK(1) : Reduce opponent hp to"<<numHo-numDp<<" HP|"<<endl;
    cout<<"|DEFENCE(2): Increase your hp to "<<numHp+17<<" HP|"<<endl;
    cout<<"|STRENGTH(3): Increase your damage to"<<numDp+6<<" |"<<endl;
    cout<<"|**************************************************|"<<endl;
    cout << "What do you want to do "<<nam<< " ?"<<endl;
    cin>> move;
    return move;
}

float attack(int a, int b){
    int newhp = a-b;
    return newhp;
}

float defence(int a){
    int newdef = a+17;
    return newdef;
}

float strength(int a){
    int newstr = a+6;
    return newstr;
}

int main() {
    string name1,name2;
    int opt1,opt2,waiting;
    
    cout << "Welcome to Camelotia"<<endl;
    cout << "What should I call U, Player 1?"<<endl;
    cin>>name1;
    cout << "And U, Player 2?"<<endl;
    cin>>name2;
    cout << "Dear "<<name1<<" and "<<name2<<",there are 5 classes of Heroes you can select, namely:"<<endl;
    cout <<"Hero  |  class  |  HP  |  Damage"<<endl;
    for(int i = 0 ; i<5;i++){
        cout<<i+1<<'\t'<<classes[i]<<'\t'<<healthpool[i]<<'\t'<<dmgpool[i]<<endl;
    }
    
    cout << "What do you pick "<<name1<<"? 1/2/3/4/5?";
    cin>>opt1;
    cout << "And "<<name2<<",what do u like? 1/2/3/4/5?";
    cin>>opt2;
    
    hero h1;
    h1.name = name1;
    h1.type = classes[opt1-1];
    h1.hp = healthpool[opt1-1];
    h1.dmg = dmgpool[opt1-1];
    
    hero h2;
    h2.name = name1;
    h2.type = classes[opt2-1];
    h2.hp = healthpool[opt2-1];
    h2.dmg = dmgpool[opt2-1];

while(h1.hp>0.0 && h2.hp>0.0){    

    int move_p1 = menu(name1,h1.type,h1.dmg,h2.dmg,h1.hp,h2.hp);
    switch(move_p1){
        case 1:
           h2.hp = attack(h2.hp,h1.dmg);
           cout<<name2<<"'s HP decreased to "<<h2.hp<<endl;
           break;
        case 2:
            h1.hp = defence(h1.hp);
            cout<<name1<<"'s HP increased to "<<h1.hp<<endl;
            break;
        case 3:
            h1.dmg = strength(h1.dmg);
            cout<<name1<<"'s damage increased to "<<h1.dmg<<endl;
            break;
    }
    if(h1.hp<0.0 || h2.hp<0.0){
        break;
    }
    int move_p2 = menu(name2,h2.type,h2.dmg,h1.dmg,h2.hp,h1.hp);
    switch(move_p2){
        case 1:
           h1.hp = attack(h1.hp,h2.dmg);
           cout<<name1<<"'s HP decreased to "<<h1.hp<<endl;
           break;
        case 2:
            h2.hp = defence(h2.hp);
            cout<<name2<<"'s HP increased to "<<h2.hp<<endl;
            break;
        case 3:
            h2.dmg = strength(h2.dmg);
            cout<<name2<<"'s damage increased to "<<h2.dmg<<endl;
            break;
    }
}
if(h1.hp<0.0){
    cout<<name2<<" won!";
}
else if(h2.hp<0.0){
    cout<<name1<<" won!";
}
    return 0;
}