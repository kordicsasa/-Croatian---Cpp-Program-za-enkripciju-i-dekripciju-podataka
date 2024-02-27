// MD5:80aFq7jkm9kNc51pAUAkBw==
// Verifikator 5.05
// Program:Sem1Prog
// Poèetno vrijeme: 15:16 (internetsko) Završno vrijeme: 16:46 Preostalo: 64 +
// Opis zadatka:Sem1Prog
// Autor:Sasa Kordic
// Poèetno vrijeme:10.5.2022. 15:16:56
// Završno vrijeme:10.5.2022. 15:43:01
// Identifikatori:dat,main,x,Enkriptiranje,str[100],spr,i,spremanje,ime[50],Dekriptiranje,z
// IP:fe80::55d5:f5f0:b444:5324%15 ( 3830 )
// #:#include <iostream>,#include <fstream>,#include <cstring>,
// Uspješnih/neuspješnih prevoðenja:24/9
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

fstream dat;
char ime[50];
void spremanje(char str[100]){
	cout<<"\nUnesite ime datoteke(*.txt)\n";
	cin>>ime;
	dat.open(ime,ios::in);
	if(!dat){
		dat.open(ime,ios::out);
		dat<<str<<endl;
		dat.close();
		cout<<"\nSpremljeno.\n";
	}
	else{
		cout<<"\nDatoteka pod tim imenom ima spremljeni niz.\n";
		dat.close();
	}
}
void Enkriptiranje(){
	char str[100];
	int spr,i;
	cout<<"Unesite znakovni niz: \n";
	cin>>str;
	for(i=0;(i<100 && str[i]!='\0'); i++) str[i]=str[i] + 2;
	cout<<"\nEnkriptirani niz je: "<<str<<endl;
	cout<<"\nZelite li spremiti u txt datoteku?"<<endl;
	cout<<"1 - Spremi.\n";
	cout<<"2 - Nemoj spremat.\n";
	cin>>spr;
	if(spr==1){
		spremanje(str);
	}
	else if(spr==2){
		cout<<"Nije spremljeno.\n";
	}
}
void Dekriptiranje(){
	char str[100];
	int z,i;
	cout<<"1 za unos niza koji treba dekriptirati.\n";
	cout<<"2 za dekriptiranje iz datoteke.\n";
	cin>>z;
	if(z==1){
		cout<<"Unesite znakovni niz: \n";
		cin>>str;
		for(i=0;(i<100 && str[i]!='\0'); i++) str[i]=str[i] - 2;
		cout<<"\nDekriptirani niz je: "<<str<<endl;
	}
	else if(z==2){
		cout<<"\nUnesite ime datoteke(*.txt)\n";
		cin>>ime;
		dat.open(ime,ios::in);
		if(!dat){
			cout<<"Datoteka sa tim imenom ne postoji.\n";
		}
		else{
			dat.getline(str,sizeof(str),'\n');
			if(dat.eof())return;
			for(i=0;(i<100 && str[i]!='\0'); i++) str[i]=str[i] - 2;
			cout<<"\nDekriptirani niz je: "<<str<<endl;
		}
	}
}
int main(){
	int x;
	do{
		cout<<"\nOdaberite opciju programa:\n";
		cout<<"1 = Enkriptiranje znakovnog niza\n";
		cout<<"2 = Dekriptiranje znakovnog niza\n";
		cout<<"3 = Izlaz iz programa\n";
		cin>>x;
		switch(x){
			case 1: Enkriptiranje();break;
			case 2: Dekriptiranje();break;
		}
	}while(x!=3);
	system("PAUSE");
}
  
