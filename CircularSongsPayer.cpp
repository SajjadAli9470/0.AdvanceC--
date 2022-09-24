#include<iostream>
using namespace std;

struct MyHitCollections{
    int id;
    string name;
    string singerName;
    int year;
    MyHitCollections*next;
    MyHitCollections*prev;
};

MyHitCollections*head;
MyHitCollections*tail;

void AddSong(){
    MyHitCollections*new_song;
    new_song=new MyHitCollections();

    cout<<"Enter Song Name    : "; getline(cin,new_song->name);
    cout<<"Enter Singer Name  : "; getline(cin,new_song->singerName);
    cout<<"Enter Song year    : "; cin>>new_song->year;
cin.ignore();
    if(head==NULL){
        new_song->id=1;
        head=new_song;
        new_song->next=head;
        tail=new_song;
        new_song->prev=tail;

    }else{
        new_song->id=tail->id+1;
        tail->next=new_song;
        new_song->prev=tail;
        new_song->next=head;
        tail=new_song;
        head->prev=tail;
    }
    
}

void PlaySongs(int NumberOfCycles,bool IsPlayforward){
   MyHitCollections*play;
   if(IsPlayforward==true){ play=head;}
   else{                   play=tail;}

   
    int count=0;
    while(count!=NumberOfCycles){
       if(IsPlayforward==true){
           if(play->next==head){
            count++;
            }
        }
        else{
            if(play->prev==tail){
            count++;
            }
        }
        cout<<"\nSong Played : "<<play->name<<" (year : "<<play->year<<")\n";
        if(IsPlayforward==true){
            play=play->next;
        }
        else{
            play=play->prev;
        }
        
    }
}
void search(int year){
    MyHitCollections*toSearch;
    toSearch=head;
    bool check=false;
    while(1){
        if(toSearch->year==year){
            cout<<"ID : "<<toSearch->id;
            check=true;
            break;
        }
        toSearch=toSearch->next;
        if(toSearch==head){
            break;
        }
    }
    if(check==false){
        cout<<"Song not found......\n";
    }
}

int main(){
AddSong();
AddSong();
AddSong();

search(2021);

PlaySongs(3,false);

}