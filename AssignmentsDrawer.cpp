#include<iostream>
using namespace std;

struct AssignDrawer{
    int AssignNo;
    string SubmissionDay;
    AssignDrawer*next;
    AssignDrawer*prev;
}*head,*tail;

void AddAssign(int AssignNo,string day){
    AssignDrawer*add_assign=new AssignDrawer();
    if(head==NULL){
        add_assign->AssignNo=AssignNo;
        add_assign->SubmissionDay=day;
        add_assign->next=NULL;
        add_assign->prev=NULL;
        head=add_assign;
        tail=add_assign;
    }
    else{
        add_assign->AssignNo=AssignNo;
        add_assign->SubmissionDay=day;
        tail->next=add_assign;
        add_assign->prev=tail;
        tail=add_assign;
        add_assign->next=NULL;
    }

}
void swap(AssignDrawer*a,AssignDrawer*b){
        int temp1=a->AssignNo;
        string temp2=a->SubmissionDay;

        a->AssignNo=b->AssignNo;
        a->SubmissionDay=b->SubmissionDay;

        b->AssignNo=temp1;
        b->SubmissionDay=temp2; 
}
void SortAssign(){

    AssignDrawer*ptr,*current=head,*Next;
    ptr=head;
    while(current!=NULL){
        Next=current->next;
        while(Next!=NULL){
            if(current->AssignNo>Next->AssignNo){
                swap(current,Next);
            }
            Next=Next->next;
        }
        current=current->next;
    }

}
void search(int num){
    AssignDrawer*ptr=head;
    bool check=false;
    while(ptr!=NULL){
        if(ptr->AssignNo==num){
            cout<<"\tAssignment "<<num<<" deadline is "<<ptr->SubmissionDay<<endl;
            check=true;
            break;
        }
        ptr=ptr->next;   
    }
    if(check==false){
        cout<<"\tAssignment "<<num<<" is out of List\n";
    }
}

void display(){
    AssignDrawer*ptr=head;
    while(ptr!=NULL){
        cout<<"\nAssignment No : "<<ptr->AssignNo<<endl;
        cout<<"Assignment Day : "<<ptr->SubmissionDay<<endl;
        ptr=ptr->next;
    }
}

int main(){
AddAssign(5,"Monday");
AddAssign(3,"Tuesday");
AddAssign(2,"Wednesday");
AddAssign(1,"Thrusday");
AddAssign(4,"Friday");
// display();
SortAssign();
cout<<"\nAfter Sorting.....\n";
display();
search(3);
search(8);
}