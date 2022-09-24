#include<iostream>
using namespace std;
#define num 5

struct vertex{
	int vno;
	vertex*Connected[num];
	vertex*next;
	vertex*prev;
};
vertex*head = NULL;
vertex*tail = NULL;


void CreateVertex(){

	for (int i = 0; i < num; i++){
			vertex*new_vertex;
			new_vertex = new vertex();
			if (head == NULL){
				new_vertex->vno = i + 1;
				new_vertex->next = NULL;
				new_vertex->prev = NULL;
				head = new_vertex;
				tail = new_vertex;

			}
			else{
				new_vertex->vno = i + 1;
				new_vertex->next = NULL;
				tail->next = new_vertex;
				new_vertex->prev = tail;
				tail = new_vertex;
			}
			for (int i = 0; i < num; i++){
				new_vertex->Connected[i] = NULL;
			}
	}



}
void DisplayVertex(){
	vertex*toDisplay=head;
	while (toDisplay != NULL){
		cout << toDisplay->vno << endl;
		cout << "Connected Vertex's : ";
		for (int i = 0; i < num; i++){
			if (toDisplay->Connected[i] == NULL){
				//cout << "NULL ";
			}
			else{
				cout << toDisplay->Connected[i]->vno <<" ";
			}
		}
		cout << endl;
		toDisplay = toDisplay->next;
	}

}
void ConnectVertex(int VTC,int VWC,int Count){
	vertex*edges = head;
	vertex*toConnect = NULL;
	vertex*withConnect = NULL;

	while (edges != NULL){
		if (edges->vno == VTC)
		{
			toConnect = edges;
			break;
		}
		edges = edges->next;
	}
	edges = head;
	while (edges != NULL){
		if (edges->vno == VWC)
		{
			withConnect = edges;
			break;
		}
		edges = edges->next;
	}
	for (int i = 0; i < num; i++){
		if (withConnect->Connected[i] == NULL){
			withConnect->Connected[i] = toConnect;
			break;
		}
	}
	if (Count < 2){
		ConnectVertex(VWC, VTC, Count + 1);
	}
	
}
int main(){
	CreateVertex();
	//Graph Representation
	ConnectVertex(2, 1, 1);
	ConnectVertex(5, 1, 1);
	ConnectVertex(5, 2, 1);
	ConnectVertex(4, 2, 1);
	ConnectVertex(3, 2, 1);
	ConnectVertex(4, 3, 1);
	ConnectVertex(5, 4, 1);

	DisplayVertex();

	system("pause");
}