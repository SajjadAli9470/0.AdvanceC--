#include<iostream>
using namespace std;

struct Employee
{
    int id;
    string name;
    string rank;
    double salary;
    Employee*next;
    Employee*prev;
}*head,*tail;

void addEmployee(int num){
      for(int i=0;i<num;i++){
          Employee*add_emp;

          if(head==NULL){
              add_emp=new Employee();
              add_emp->id=1;
              cout<<"Enter Name of Employees : "; getline(cin,add_emp->name);
              cout<<"Enter rank of Employees : "; cin>>add_emp->rank;
              cout<<"Enter Salary of Employees : "; cin>>add_emp->salary;
              head=add_emp;
              tail=add_emp;
              add_emp->next=NULL;
              add_emp->prev=NULL;

          }
          else{
                    Employee*CheckPastRec;
                    add_emp=new Employee();
                    CheckPastRec=head;
                    bool check=false;
                    string name;
                    cin.ignore();
                do{
                    
                    cout<<"Enter (Unique)Name of Employees : ";  getline(cin,name);
                    while(CheckPastRec!=NULL){
                        if(CheckPastRec->name==name){
                            check=false;
                            break;
                        }
                        else{
                            check=true;
                        }
                        CheckPastRec=CheckPastRec->next;
                    }
                }while(check!=true);
                add_emp->name=name;
                cout<<"Enter rank of Employees : "; cin>>add_emp->rank;
                cout<<"Enter Salary of Employees : "; cin>>add_emp->salary;
                add_emp->id=tail->id+1;
                tail->next=add_emp;
                add_emp->prev=tail;
                add_emp->next=NULL;
                tail=add_emp;
                

          }
      }
}
void Update(){
    cout<<"Enter name of Employee to Edit data : "; string name; getline(cin,name);
    Employee*ptr=head;
    while(ptr!=NULL){
        if(ptr->name==name){
            cout<<"Enter new Name of Employee  (e to exit) : "; string name; getline(cin,name);
            if(name!="e"){ptr->name=name;}
            cout<<"Enter new Salary of Employee(0 to exit) : "; int salary; cin>>salary;
            if(salary!=0){ptr->salary=salary;}
            cout<<"Enter new Rank of Employee  (e to exit) : "; string rank; cin>>rank;
            if(rank!="e"){ptr->rank=rank;}  
            break; 
        }
        ptr=ptr->next;
    }
}
void Search(){
    cin.ignore();
    cout<<"Enter Name to Search : "; string name; getline(cin,name);
    Employee*ptr;
    ptr=head;
    bool check=false;
    while(ptr!=NULL){
        if(ptr->name==name){
            cout<<"\tID of Employee : "<<ptr->id<<endl;
            cout<<"\tName of Employee : "<<ptr->name<<endl;
            cout<<"\tRank of Employee : "<<ptr->rank<<endl;
            cout<<"\tSalary of Employee : "<<ptr->salary<<endl;  
        check=true;
        }
        ptr=ptr->next;
    }
    if(check==false){
        cout<<"\tEmployee not found..........\n";
    }
}
void deleteFrmEmployeeName(){
    cout<<"Enter Name to delete thier Recod : "; string name; getline(cin,name);
    Employee*EmployeeToDelete,*PreviousEmployee;
    EmployeeToDelete=head;
    while(EmployeeToDelete->name!=name){
            PreviousEmployee=EmployeeToDelete;
            EmployeeToDelete=EmployeeToDelete->next;
    }
    EmployeeToDelete->prev->next=EmployeeToDelete->next;
    delete(EmployeeToDelete);
    cout<<"\tDeleted Successfully........\n";
}
void Display(){
    Employee*ptr=head;
    while(ptr!=NULL){
        cout<<"\nID : "<<ptr->id<<endl;
        cout<<"Name : "<<ptr->name<<endl;
        cout<<"Rank : "<<ptr->rank<<endl;
        cout<<"Salary : "<<ptr->salary<<endl;
        ptr=ptr->next;
    }
}
void swap(Employee*a,Employee*b){
    int temp1=a->id;
    string temp2=a->name;
    string temp3=a->rank;
    double temp4=a->salary;

    a->id=b->id;
    a->name=b->name;
    a->rank=b->rank;
    a->salary=b->salary;

    b->id=temp1;
    b->name=temp2;
    b->rank=temp3;
    b->salary=temp4;
}
void Sort(){
    Employee*current=head,*Next=head;
    while(current!=NULL){
        Next=current->next;
        while(Next!=NULL){
            if(current->name>Next->name){
                swap(current,Next);
            }
            Next=Next->next;
        }
        current=current->next;
    }
}
int main(){
    // ye Switch Case se Set ker lainnna
    addEmployee(3);
    Sort();
    Display();
    Search();
    Update();
    Display();

}