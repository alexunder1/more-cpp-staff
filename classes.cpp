#include <bits/stdc++.h>
using namespace std;


vector<string> readRandomNames(int n = 1){
    ifstream is("mk.names");
    vector<string> names;

    while(!is.eof()){
        string s;
        is>>s;
        names.push_back(s);
    }
    vector<string> res(n);

    for(int i = 0; i<n; i++){
        res[i] = names[rand() % names.size()];
    }
    return res;
}



string randName(){
    return readRandomNames()[0];
}


bool prob1(double p = 0.5, int _max = 10000){
    return (rand() % _max) / ((double) _max)<=p;
}

class Human{
    public:
    Human(int _age = 18, string _name = "Anonimus"){
        age = _age;
        name = _name;
    }
    Human(){
        age = 40 - rand()%30;
        name = randName();
    }
    void sayHi(ostream & os){
        os<<"Hi, I am "<<name<<endl;
    }

    int age;
    string name;
};

class Ninja{
    public:
    Ninja(){
        agility = 30 - rand()%20;
        maxhp = 200 - rand()%100;
        hp = maxhp;
        power = 20 - rand()%10;
        age = 40 - rand()%30;
        name = randName();
    }
    int agility;
    int power;
    int hp;
    int static maxhp;
    int age;
    string name;


    void restoreHp(){
        hp = maxhp;
    }

    void sayHp(ostream & os){
        os<<name<<" has "<<hp<<" hp"<<endl;
    }



    void damage(int dmg){
        hp = max(0, hp - dmg);
    }

    void attack(Ninja & target){
        double p = (double)agility/(agility+target.agility);
        if (prob1(p)){
            target.damage(power);
            cout << name << " HAHEC "<< power<<" TO "<<target.name<<endl;
        }
        else
            cout << name<< " MISSED "<<target.name<<endl;
    }
};






    vector <Ninja> ninjas;

    for (int i=0; i<ninjas.size(); i++){

        for (int j=i; j<ninjas.size(); j++){

            battle (ninjas[i], ninjas[j]);
            restoreHp(ninjas[i]);
            restoreHp(ninjas[j]);

        }

    }

vector <Ninja> ninjas(int n = 1){
    for (int i=0; i<5; i++)
        ninjas.push_back(Ninja);

}

    void battle(Ninja & h1, Ninja & h2){
    h1.sayHi(cout);
    h2.sayHi(cout);

        while(h1.hp*h2.hp>0){

            h1.attack(h2);
            h2.sayHp(cout);
            h2.attack(h1);
            h1.sayHp(cout);

        }


    }

}




bool isOldEnough(const Human & h){
    return h.age >= 18;
}

int main(){



    vector <Ninja> ninjas;

    Ninja h1(cin), h2(cin);



    battle(h1,h2);


    return 0;
}
