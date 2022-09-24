#include<iostream>
using namespace std;

struct node{
    int data;
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
node* INSERT(int x,node*ptr){
    if(ptr==NULL){
        ptr=new node();
        ptr->data=x;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(x<ptr->data){
        ptr->left=INSERT(x,ptr->left);
    }
    else if(x>ptr->data){
        ptr->right=INSERT(x,ptr->right);
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
    cout<<ptr->data<<" ";
    INORDER(ptr->right);
}
void PREORDER(node*ptr){
    if(ptr==NULL){
        return;
    }
    cout<<ptr->data<<" ";
    PREORDER(ptr->left);
    PREORDER(ptr->right);
}
void POSTORDER(node*ptr){
    if(ptr==NULL){
        return;
    }
    POSTORDER(ptr->left);
    POSTORDER(ptr->right);
    cout<<ptr->data<<" ";
}
void Insert(int x){
    root=INSERT(x,root);
}
void Delete(int x){
    root=DELETE(x,root);
}
void find(int x){
    root=FIND(x,root);
}
// Check total level
int LEVELS(node*ptr){
    if(ptr==NULL){
        return 0;
    }
    else{
        return 1+max(LEVELS(ptr->left),LEVELS(ptr->right));
    }
}
// GEt require Levels nodes
void RequireLevel(node*ptr,int levelno){
    if(ptr==NULL){
        return;
    }
    if(levelno==1){
        cout<<ptr->data<<" ";
    }
    else if(levelno>1){
        RequireLevel(ptr->left,levelno-1);
        RequireLevel(ptr->right,levelno-1);
    }
}
// Print All node wrt LEVELS
void PrintAllLevels(node*ptr){
    int level=LEVELS(root);
    int count=0;
    while(count<=level){
        count++;
        cout<<"LEVEL NO : "<<count<<"->  ";
        RequireLevel(ptr,count);
        cout<<endl;
    }
}
// GET Count of LEAF NODE's
int LeafCount(node*ptr){
    if(ptr==NULL){
        return 0;
    }
    else if(ptr->left==NULL && ptr->right==NULL){
        return 1;
    }
    else{
        return LeafCount(ptr->left)+LeafCount(ptr->right);
    }
}
int NonLeafCount(node*ptr){
    if(ptr==NULL||(ptr->left==NULL&&ptr->right==NULL)){
        return 0;
    }
    else{
      return  1+NonLeafCount(ptr->right)+NonLeafCount(ptr->left);
    }
}
int main(){

Insert(60);
Insert(41);
Insert(16);
Insert(53);
Insert(25);
Insert(46);
Insert(55);
Insert(42);
Insert(74);
Insert(65);
Insert(63);
Insert(70);
Insert(62);
Insert(64);

INORDER(root);
// Delete(7);
// cout<<"\n";
// PREORDER(root);

cout<<"\n MINIMUM NUMBER : "<<MIN(root)->data<<endl;
cout<<"\n";
cout<<"Number of Leaf Node : "<<LeafCount(root)<<endl;
cout<<"Number of non-Leaf Node : "<<NonLeafCount(root)<<endl;
cout<<"LEVELS : "<<LEVELS(root)<<endl;
PrintAllLevels(root);

}

