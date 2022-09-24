#include<iostream>
using namespace std;

struct node{
    int id;
    int data;
    string title;
    node*left;
    node*right;
};

node*root;

node* MIN(node*ptr){
    if(ptr==NULL){
        return NULL;
    }
    else if(ptr->left==NULL){
        return ptr;
    }
    else{
        return MIN(ptr->left);
    }
}
node* MAX(node*ptr){
    if(ptr==NULL){
        return NULL;
    }
    else if(ptr->right==NULL){
        return ptr;
    }
    else{
        return MAX(ptr->right);
    }
}
node* INSERT(int x,int id,string title,node*ptr){
    if(ptr==NULL){
        ptr=new node();
        ptr->data=x;
        ptr->title=title;
        ptr->id=id;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(x<ptr->data){
        ptr->left=INSERT(x,id,title,ptr->left);
    }
    else if(x>ptr->data){
        ptr->right=INSERT(x,id,title,ptr->right);
    }

    return ptr;
}
node* DELETE(int x,node*ptr){
    if(ptr==NULL){
        return NULL;
    }
    else if(x<ptr->data){
        ptr->left=DELETE(x,ptr->left);
    }
    else if(x>ptr->data){
        ptr->right=DELETE(x,ptr->right);
    }
    else if(ptr->left&&ptr->right){
        node*temp=MIN(ptr->right);
        ptr->data=temp->data;
        ptr->right=DELETE(ptr->data,ptr->right);
    }
    else{
        node*temp=ptr;
        if(ptr->left==NULL){
            ptr=ptr->right;
        }
        else if(ptr->right==NULL){
            ptr=ptr->left;
        }
        delete(temp);
    }

    return ptr;
}
node* FIND(int x,node*ptr){
    if(ptr==NULL){
        return NULL;
    }
    else if(x<ptr->data){
        return FIND(x,ptr->left);
    }
    else if(x>ptr->data){
        return FIND(x,ptr->right);
    }
    else{
        return ptr;
    }
}
void INORDER(node*ptr){
    if(ptr==NULL){
        return;
    }
    INORDER(ptr->left);
    
    cout<<" [ "<<ptr->id<<", ";
    cout<<ptr->data<<", ";
    cout<<ptr->title<<" ] ";


    INORDER(ptr->right);
}

void Insert(int x,int id,string title){
    root=INSERT(x,id,title,root);
}
void Delete(int x){
    root=DELETE(x,root);
}
node* find(int x){
    root=FIND(x,root);
    return root;
}


int main(){

Insert(2021,1,"A");
Insert(2019,2,"B");
Insert(2020,3,"C");
Insert(2015,4,"D");
Insert(2012,5,"E");
Insert(2017,6,"F");
Insert(2014,7,"G");
Insert(2018,8,"H");
Insert(2016,9,"I");
Insert(2013,10,"J");
Insert(2011,11,"K");

INORDER(root);
cout<<endl;
Delete(2011);
Delete(2013);
cout<<"After DELete : "<<endl;

INORDER(root);

cout<<"\nAfter Searching : \n";

cout<<find(2017)->id<<endl;
cout<<find(2017)->title<<endl;
cout<<find(2017)->data<<endl;
return 0;
system("pause");

}