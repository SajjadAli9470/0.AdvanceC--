#include<iostream>
using namespace std;
#define numberOfVertex 5

struct Vertex{
    
    int VertexNo;
    int VertixConn[numberOfVertex];
    Vertex*next;
    Vertex*prev;
};

Vertex*head=NULL;
Vertex*tail=NULL;

void CreateVertex(){
    Vertex* ptr=NULL;
    for(int i=0;i<numberOfVertex;i++)
    {   ptr=new Vertex();    
        if(head==NULL){          
            ptr->VertexNo=i+1;            
            ptr->prev=NULL;
            ptr->next=NULL;
            head=ptr;
            tail=ptr;

        }else{    
            ptr->VertexNo=i+1;
            ptr->prev=tail;
            tail->next=ptr;
            ptr->next=NULL; 
            tail=ptr;
        }

        for(int j=0;j<numberOfVertex;j++){
                ptr->VertixConn[i]=0;
            }
    }
}
void ConnEdges(int VertexNo , int ConnVerNo, int count){   
    Vertex*ptr;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->VertexNo==VertexNo){
            ptr->VertixConn[ConnVerNo-1]=1;
            break;
        }
        ptr=ptr->next;
    }
    if(count<2)
    {
            ConnEdges(ConnVerNo,VertexNo,count+1);
    }
}
void Show_Conn(){
    Vertex*ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<<"Vertex no : "<<ptr->VertexNo<<endl;
        cout<<"           Connection : ";
        for(int i=0;i<numberOfVertex;i++){
            if(ptr->VertixConn[i]==1){
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
        ptr=ptr->next;
    } 
}
int main(){
    CreateVertex();
  
    ConnEdges(1,2,1);
    ConnEdges(1,3,1);
    ConnEdges(2,1,1);
    ConnEdges(2,3,1);
    ConnEdges(2,4,1);
    ConnEdges(2,5,1);
    ConnEdges(3,4,1);
    ConnEdges(5,4,1);
    Show_Conn();

  

}