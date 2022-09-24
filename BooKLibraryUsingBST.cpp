#include<iostream>
using namespace std;

struct node{

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
node* INSERT(int x,string title,node*ptr){
    if(ptr==NULL){
        ptr=new node();
        ptr->data=x;
        ptr->title=title;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(x<ptr->data){
        ptr->left=INSERT(x,title,ptr->left);
    }
    else if(x>ptr->data){
        ptr->right=INSERT(x,title,ptr->right);
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
    
    cout<<"\t[ ";
    cout<<ptr->data<<", ";
    cout<<ptr->title<<" ]\n";


    INORDER(ptr->right);
}

void Insert(int x,string title){
    root=INSERT(x,title,root);
}
void Delete(int x){
    root=DELETE(x,root);
}
node* find(int x){
    root=FIND(x,root);
    return root;
}


int main(){

Insert(16000,"Comiler");
Insert(26000,"Yellow");
Insert(13000,"Algorithim");
Insert(19000,"Simulation");
Insert(28000,"Zami");
Insert(17000,"Data Structure");
Insert(14000,"Bear Walker");
Insert(27000,"Quantum Mechanics");
cout<<"DISPLAY ALL BOOKS : \n";
INORDER(root);
cout<<endl;

cout<<"Highest Price BOOK : \n";
cout<<"\t"<<MAX(root)->title<<endl;
cout<<"\t"<<MAX(root)->data<<endl;
cout<<"Lowest Price BOOK : \n";
cout<<"\t"<<MIN(root)->title<<endl;
cout<<"\t"<<MIN(root)->data<<endl;

Delete(17000);
cout<<"After DeLete (BOOK : 17000Rs): "<<endl;

INORDER(root);

cout<<"\nAfter Searching (BOOK : 27000Rs): \n";


cout<<"\t"<<find(27000)->title<<endl;
cout<<"\t"<<find(27000)->data<<endl;
return 0;
system("pause");

}