#include <iostream>
//#include <stdlib.h>
#include <fstream.h>
//#include <iomanip.h>
using namespace std;

//-----------------------------------------------------ZAÈETEK KNJIG
class datum
{
      public: 
              short dan, mesec, leto;
};

class knjiga
{
      public:
              string avtor, naslov;
              short stkn;
              datum izdaja, zaloga;
              bool doseg;
      public:
             void izDat_vObjekt(knjiga iz[], short &pod);
             void izObjekt_vDat(knjiga iz[], short &pod);
             void izpisOne(knjiga iz[], unsigned int j, short &pod);
             void izpisAll(knjiga iz[], unsigned int j, short &pod);
             void sortAvtor(knjiga iz[], unsigned int j, short &pod);
             void sortStkn(knjiga iz[], unsigned int j, short &pod);
             void menjava(knjiga &prva, knjiga &druga);
             short vShort(string niz);
             bool vBool(string niz);
             void iskAvtor(knjiga iz[], unsigned int j, short &pod);
             void iskNaslov(knjiga iz[], unsigned int j, short &pod);
             void izpisIsk(knjiga iz[], short st);
             void addOne(knjiga iz[], unsigned int j, short &pod);
             //void pretvorbaDatuma (string niz);
             //meniji
             void gl_meni(knjiga iz[], unsigned int j, short &pod);
             void izpis_meni(knjiga iz[], unsigned int j, short &pod);
             void sort_meni(knjiga iz[], unsigned int j, short &pod);
             void isk_meni(knjiga iz[], unsigned int j, short &pod);
};

bool knjiga::vBool(string niz)
{
     if(niz=="true") return true;
     if(niz=="false") return false;
}

short knjiga::vShort(string niz)
{
  char znak;
  short cifra;
  short st=0;
  for (short i=0;i<niz.length();i=i+1)
  {
    znak=niz[i];
    cifra=((short) znak)-48;
    //cout<<"znak je "<<znak<<", cifra ="<<cifra<<endl;     //kontrolni izpis
    st=st*10+cifra;
  }         
  //cout<<"Podani niz je "<<niz<<", ?tevilo pa "<<stt<<endl;//kontrolni izpis
  return (st);
}


void knjiga::izDat_vObjekt(knjiga iz[], short &pod)//Vpis iz datoteke v objekt
{
 pod=0;
 string line;
  ifstream dat ("knjiznica_v2.txt");
  if (dat.is_open())
  {
      for(short x=0;!dat.eof();x++)
      {
           getline(dat,line);          
           iz[x].avtor=line;  
           //cout<<x<<"."<<iz[x].avtor<<endl;
           getline(dat,line);          
           iz[x].naslov=line;  
           //cout<<x<<"."<<iz[x].naslov<<endl;
           getline(dat,line);          
           iz[x].stkn=vShort(line);  
           //cout<<x<<"."<<iz[x].stkn<<endl;
           getline(dat,line);          
           iz[x].izdaja.dan=vShort(line);  
           //cout<<x<<"."<<iz[x].izdaja.dan<<endl;
           getline(dat,line);          
           iz[x].izdaja.mesec=vShort(line);  
           //cout<<x<<"."<<iz[x].izdaja.mesec<<endl;
           getline(dat,line);          
           iz[x].izdaja.leto=vShort(line);  
           //cout<<x<<"."<<iz[x].izdaja.leto<<endl;
           getline(dat,line);
           iz[x].zaloga.dan=vShort(line);  
           //cout<<x<<"."<<iz[x].zaloga.dan<<endl;
           getline(dat,line);
           iz[x].zaloga.mesec=vShort(line);  
           //cout<<x<<"."<<iz[x].zaloga.mesec<<endl;
           getline(dat,line);
           iz[x].zaloga.leto=vShort(line);  
           //cout<<x<<"."<<iz[x].zaloga.leto<<endl;
           getline(dat,line);
           iz[x].doseg=vBool(line);
           //cout<<x<<"."<<iz[x].doseg<<endl;
           pod++;
      }
    dat.close();
  }
  
}

void knjiga::izObjekt_vDat(knjiga iz[], short &pod)
{
     ofstream vDat;
     vDat.open ("knjiznica_v3.txt");
     for(int x=0;x<pod;x++)
       {
          vDat<<"Avtor knjige je "<<iz[x].avtor<<endl;
          vDat<<"Naslov knjige je "<<iz[x].naslov;
          vDat<<"in na volju jih je "<<iz[x].stkn<<endl;
          vDat<<"Nazadnje je bila izposojena "<<iz[x].izdaja.dan;
          vDat<<"."<<iz[x].izdaja.mesec;
          vDat<<"."<<iz[x].izdaja.leto<<endl;
          vDat<<"in bo vrnjena "<<iz[x].zaloga.dan;
          vDat<<"."<<iz[x].zaloga.mesec;
          vDat<<"."<<iz[x].zaloga.leto<<endl;
          if(iz[0].doseg==true)
               {
                   vDat<<"Knjiga je na zalogi\n"<<endl;               
               }else
               {
                   vDat<<"Knjiga ni na zalogi\n"<<endl;     
               }
          
       }
     vDat.close();
}

void knjiga::izpisOne(knjiga iz[], unsigned int j, short &pod)
{
     cout<<"Avtor knjige je "<<iz[0].avtor<<endl;
     cout<<"Naslov knjige je "<<iz[0].naslov<<" navolju jih je "<<iz[0].stkn<<endl;
     cout<<"Datum izposoje: "<<iz[0].izdaja.dan<<"."<<iz[0].izdaja.mesec<<"."<<iz[0].izdaja.leto<<endl;
     cout<<"Datum vrnitve: "<<iz[0].zaloga.dan<<"."<<iz[0].zaloga.mesec<<"."<<iz[0].zaloga.leto<<endl;
     if(iz[0].doseg==true)
     {
          cout<<"Knjiga je na zalogi"<<endl;               
     }else
     {
          cout<<"Knjiga ni na zalogi"<<endl;     
     }
}

void knjiga::izpisAll(knjiga iz[], unsigned int j, short &pod)
{
  for(short x=0;x<pod;x++)
  {
          cout<<"Avtor knjige je "<<iz[x].avtor<<endl;
          cout<<"Naslov knjige je "<<iz[x].naslov<<" navolju jih je "<<iz[x].stkn<<endl;
          cout<<"Datum izposoje: "<<iz[x].izdaja.dan<<"."<<iz[x].izdaja.mesec<<"."<<iz[x].izdaja.leto<<endl;
          cout<<"Datum vrnitve: "<<iz[x].zaloga.dan<<"."<<iz[x].zaloga.mesec<<"."<<iz[x].zaloga.leto<<endl;
          if(iz[x].doseg==true)
          {
               cout<<"Knjiga je na zalogi"<<endl;               
          }else
          {
               cout<<"Knjiga ni na zalogi"<<endl;     
          }
  }
}

void knjiga::sortAvtor(knjiga iz[], unsigned int j, short &pod)//soltiranje
{
 for(short x=0;x<pod;x++)
  {
       for(short i=x+1;i<pod;i++)
        {
              if(iz[x].avtor>iz[i].avtor) menjava(iz[x], iz[i]);
        }
  }
}

void knjiga::sortStkn(knjiga iz[], unsigned int j, short &pod)
{
     for(short x=0;x<pod;x++)
  {
       for(short i=x+1;i<pod;i++)
        {
              if(iz[x].stkn>iz[i].stkn) menjava(iz[x], iz[i]);
        }
  }
}

void knjiga::menjava(knjiga &prva, knjiga &druga)
{
     knjiga med;
     med=prva;
     prva=druga;
     druga=med;
}


void knjiga::iskAvtor(knjiga iz[], unsigned int j, short &pod)
{
    string avtr;
    string tipka;
    do{
         cout<<"Podaj avtorja, ki ga isces: \n";
         getline(cin,avtr);
         for(short x=0;x<pod;x++)
           {
              if(avtr==iz[x].avtor)
               { 
                   //system("CLS");                
                   izpisIsk(iz, x);
               }else
               {
                   //system("CLS");
                   cout<<"Iskan avtor ne obstaja v bazi podatkov.\n";
                   break;  
               }
           }
         cout<<"Ali zelite ponovite izskanje za drugega avtorja(da/ne)?\n";
         getline(cin,tipka);
    }while(tipka!="ne" and tipka!="Ne" and tipka!="NE");   
}

void knjiga::iskNaslov(knjiga iz[], unsigned int j, short &pod)
{
    string naslov;
    string tipka;
    do{
         cout<<"Podaj naslov knjige, ki jo isces: \n";
         getline(cin,naslov);
         for(short x=0;x<pod;x++)
           {
              if(naslov==iz[x].naslov)
               { 
                   //system("CLS");                
                   izpisIsk(iz, x);
               }else
               {
                   //system("CLS");
                   cout<<"Iskan avtor ne obstaja v bazi podatkov.\n";
                   break;  
               }
           }
         cout<<"Ali zelite ponovite izskanje za drugega avtorja(da/ne)?\n";
         getline(cin,tipka);
    }while(tipka!="ne" and tipka!="Ne" and tipka!="NE"); 
}

void knjiga::izpisIsk(knjiga iz[], short st)
{
     cout<<"Avtor knjige je "<<iz[st].avtor<<endl;
     cout<<"Naslov knjige je "<<iz[st].naslov<<" navolju jih je "<<iz[st].stkn<<endl;
     cout<<"Datum izposoje: "<<iz[st].izdaja.dan<<"."<<iz[st].izdaja.mesec<<"."<<iz[st].izdaja.leto<<endl;
     cout<<"Datum vrnitve: "<<iz[st].zaloga.dan<<"."<<iz[st].zaloga.mesec<<"."<<iz[st].zaloga.leto<<endl;
     if(iz[st].doseg==true)
     {
          cout<<"Knjiga je na zalogi"<<endl;               
     }else
     {
          cout<<"Knjiga ni na zalogi"<<endl;     
     }
}

void knjiga::addOne(knjiga iz[], unsigned int j, short &pod)
{
     
     string bes;
     cout<<"Podaj avtorja: ";
     getline(cin,bes);
     iz[pod].avtor=bes;
     //cout<<endl<<iz[pod].avtor<<endl;
     cout<<"Podaj naslov: ";
     getline(cin,bes);
     iz[pod].naslov=bes;
     cout<<"Podaj stevilo knjig: ";
     getline(cin,bes);
     iz[pod].stkn=vShort(bes);
     do{
           cout<<"Podaj datum izposoje: (dd.mm.llll)";
           getline(cin,bes);
           if(bes.length()<10)cout<<"Datum ni pravilno podan! Podan mora biti b obliki dd.mm.llll\n";
           //else pretvorbaDatuma (bes);
        }while(bes.length()<10);
     pod++;
     
}   

/*void knjiga::pretvorbaDatuma (string niz)
{
     //notri dobim 21.01.2015
     string bes;
     for(short x=0;niz[x]!="\0";x++)
     {
        if(niz[x]>="0" and niz[x]<="9")bes
     }
     
}*/


//-----------------------------------------------------MENIJI
void knjiga::gl_meni(knjiga iz[], unsigned int j, short &pod)
{
 string tipka;   
   do{
     if(tipka=="1") izpis_meni(iz, j, pod); 
     if(tipka=="2") sort_meni(iz, j, pod); 
     if(tipka=="3") isk_meni(iz, j, pod);
     if(tipka=="4") addOne(iz, j, pod);
     //system("CLS");
     cout<<"1. Izpis\n";
     cout<<"2. Soltiranje\n";
     cout<<"3. Iskanje elementov\n";
     cout<<"4. Dodajanje objekta\n";
     cout<<"5. Brisanje objekta\n";
     cout<<"6. Exit\n";
     cout<<"\nPodaj stevilo\n";
     getline(cin,tipka);
     }while(tipka!="6");
}

void knjiga::izpis_meni(knjiga iz[], unsigned int j, short &pod)
{
 system("CLS");
 string tipka;   
   do{
     if(tipka=="1")izpisOne(iz, j, pod);
     if(tipka=="2")izpisAll(iz, j, pod); 
     cout<<"1. Izpis enega podatka\n";
     cout<<"2. Izpis vseh podatkov\n";
     cout<<"\nPodaj stevilo\n";
     getline(cin,tipka);
     }while(tipka!="3");
}

    
void knjiga::sort_meni(knjiga iz[], unsigned int j, short &pod)
{
 system("CLS");
 string tipka;   
   do{
       if(tipka=="1") sortAvtor(iz, j, pod);
       if(tipka=="2") sortStkn(iz, j, pod);
       cout<<"1. Soltiranje po avtorju\n";
       cout<<"2. Soltiranje po stevilu knjig na volju\n";
       cout<<"3. Nazaj\n";
       cout<<"\nPodaj stevilo\n";
       getline(cin,tipka);
     }while(tipka!="3");
}

void knjiga::isk_meni(knjiga iz[], unsigned int j, short &pod)
{
 string tipka;   
   do{
       system("CLS");
       cout<<"1. Avtorji\n";
       cout<<"2. Naslov\n";
       cout<<"3. Nazaj\n";
       cout<<"\nPodaj stevilo\n";
       getline(cin,tipka);
       if(tipka=="1")iskAvtor(iz, j, pod);
       if(tipka=="2")iskNaslov(iz, j, pod);
     }while(tipka!="3");
}

//-----------------------------------------------------KONEC KNJIG

//-----------------------------------------------------ZAÈETEK GLAVNEGA PROGRAMA
int main()
{   
unsigned int n=100; //stevilo podatkov in stevilo dejanskih podatkov
short stpod;

knjiga podatki[n];
podatki[0].izDat_vObjekt(podatki, stpod);
podatki[0].gl_meni(podatki, n, stpod);
cout<<endl<<podatki[6].avtor<<endl<<stpod;
podatki[0].izObjekt_vDat(podatki, stpod);
system("pause");
}
//-----------------------------------------------------KONEC GLAVNEGA PROGRAMA
