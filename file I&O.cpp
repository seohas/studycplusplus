#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define SIZE 100;
class Pet{
    private:
        string name;
        string owner;
        int rate;
        int nights;
        int remainnights;
    public:
        Pet(){name="",owner="",rate=0;nights=0;remainnights=0;}
        Pet(string petname, string ownername, int therate, int thenights):name(petname),owner(ownername),rate(therate),nights(thenights){
            remainnights=nights;
        }
        ~Pet(){}
        string getName();
        string getOwner();
        int getRate();
        int getNights();
        int getRemainNights();
        void Showpet();
        int calRemainNights(int night);



};
string Pet::getName(){ return name;}
string Pet::getOwner(){return owner;}
int Pet::getRate(){return rate;}
int Pet::getNights(){return nights;}
int Pet::getRemainNights(){return remainnights;}
void Pet::Showpet(){
    cout<<"Pet {name: "<<name<<", owner: "<<owner<<", rate: "<<rate<<", remainNights: "<<remainnights<<"}\n";
}
int Pet::calRemainNights(int night){
    remainnights-=night;
    if(remainnights<=0){
        remainnights=0;
    }
    return remainnights;
}

class Owner{
    private:
        string name;
        int balance;
        int petnum;
        
    public:
        Owner(){name="",balance=0;petnum=0;}
        Owner(string Ownername, int ownerbalance):name(Ownername),balance(ownerbalance){petnum=0;}
        ~Owner(){}
        string getName();
        int getBalace();
        int getPetNum();
        int calPetNum(int num);
        int calBalance(Pet pet,int night);
        void printOwner();
        

};
string Owner::getName(){return name;}
int Owner::getBalace(){return balance;}
int Owner::getPetNum(){return petnum;}
int Owner::calPetNum(int num){
    if(num==0)
    {if(petnum==0){
        petnum=1;}
    else{
        petnum+=1;
    }}
    else{
        petnum-=1;
    }
     return petnum;}
int Owner::calBalance(Pet pet,int night){
    balance=(balance-pet.getNights()*pet.getRate());
    return balance; }
void Owner::printOwner(){
    cout<<"Owner {name: "<<name<<", balance: "<<balance<<", numPetsCheckin: "<<petnum<<"}\n";

}
class Hotel{
    private:
        Pet pets[100];
        Owner owners[100];
        int ownersnum;
        int petsnum;
        int totalbalance;
        int incheck[100];
        int workingdays;
    public:
        Hotel(){
            ownersnum=0;petsnum=0; totalbalance=0; workingdays=0;
            for(int i=0;i<100;i++){
                incheck[i]=-1;
            }}
        ~Hotel(){}
        Owner* rigister(string name, int balance);
        Pet *checkin(string ownername, string petname, int rate, int night);
        void showpets();
        void showowners();
        void passNights(int night);
        int* checkout(Pet pet,int petnum,int night);
        void printBalance();

};
Owner* Hotel::rigister(string name, int balance){
    owners[ownersnum]=Owner(name,balance);
    ownersnum++;
    return owners;
};

Pet* Hotel::checkin(string ownername, string petname, int rate, int nights){
    pets[petsnum]=Pet(petname, ownername, rate, nights);
    incheck[petsnum]=0;
    for(int i=0;i<ownersnum;i++){
        if(pets[petsnum].getOwner()==owners[i].getName()){
            owners[i].calPetNum(0);
        }
    }
    petsnum++;
    return pets;
}
void Hotel::showpets(){
    for(int i=0;i<petsnum;i++){
        if(incheck[i]==0){
        pets[i].Showpet();
    }}
}
void Hotel::showowners(){
    for(int i=0;i<ownersnum;i++){
        owners[i].printOwner();
    }
}
void Hotel::passNights(int night){
    workingdays+=night;
    for(int i=0;i<petsnum;i++){
        if(pets[i].calRemainNights(night)==0){
            Hotel::checkout(pets[i],i,night);
        }
    }
    cout<<night<<" days have passed\n";
}
int *Hotel::checkout(Pet pet,int petnum,int night){
    int balance;
    for(int i=0;i<ownersnum;i++){
        if(pet.getOwner()==owners[i].getName()){
            balance=pet.getNights()*pet.getRate();
              if(balance<owners[i].getBalace()){
                  incheck[petnum]=-1;
                  owners[i].calBalance(pet,night);
                  owners[i].calPetNum(-1);
                  totalbalance+=balance;
              }
        }
    }
    return incheck;    
 }

 void Hotel::printBalance(){
     cout<<"Working days: "<<workingdays<<", "<<"Balance: "<<totalbalance<<"\n";
 }



int main(){
    ifstream fin;
    fin.open("input.txt");
    string next,s,t,ownername,petname;
    int rate, nights,balance;
    Hotel hotel;
    while(fin.peek()!=EOF){
        string word;
        getline(fin,next);
        stringstream ss;
        ss<<next;
        ss>>word;
        if(word=="register"){
            ss>>ownername>>balance;
            hotel.rigister(ownername,balance);
        }
        else if (word=="checkin"){
            ss>>ownername>>petname>>rate>>nights;
            hotel.checkin(ownername,petname,rate,nights);
        }
        else if (word=="pass"){
            ss>>nights;
            hotel.passNights(nights);
        }
        else if (word=="showowners"){
            hotel.showowners();
        }
        else if (word=="showpets"){
            hotel.showpets();
        }
        else{
            hotel.printBalance();
        }
    }
    fin.close();
    return 0;
}
/*input.txt
register Lee 10000
register Kim 20000
showowners
checkin Lee dogLee 3000 3
checkin Lee catLee 2000 2
checkin Kim dogKim 2500 6
showpets
showowners
getbalance
pass 4
showpets
showowners
getbalance
pass 2
showpets
showowners
getbalance
checkin Kim snakeKim 1000 2
showpets
showowners
getbalance
*/
