#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
class Node{
private:
	vector<Node*> nodes;
	int data;
public:
	Node(){
		data = rand()%10;
	}
	Node(int numNodes){
	for (int i = 0; i<(rand()%numNodes)+1;i++){
		nodes.push_back(new Node());
	}
	data = rand()%10;
	}
	vector<Node*> getVec(){
		return nodes;
	}
	void setVector(int numNodes){
		for (int i = 0; i<(rand()%numNodes)+1;i++)
			nodes.push_back(new Node());
	}
	void setData(int x){ data = x;}
	int getData(){return data;}
	Node* getRandomNode(){
		return nodes[rand() % nodes.size()];
	}
};

class Tree{
private:
	Node* conductor;
	Node* temp;
	int size = 1;
public:
	Tree(){
		conductor = new Node(10);
		temp = conductor;

		int numNodes = 9;

		while(numNodes>0){
			cout<<"initial "<<numNodes;
			for (int i = 0; i<temp->getVec().size();i++){
				numNodes--;
				size++; 
			}
			cout<<"final "<<numNodes<<endl;
			if (numNodes==0){
				break;
			}
			temp = temp->getRandomNode();
			temp->setVector(numNodes);
		}
		temp = conductor;
	}
	void prettyPrint(Node* root){
		static int level;
		for (int i = 0; i<level;i++)
			cout<<" ";
		cout<<root->getData()<<endl;
		level++;
		for (int y = 0; y<root->getVec().size();y++){
			prettyPrint(root->getVec()[y]);
		}
		level--;
	}
	void preOrder(Node* root){
		cout<<root->getData();
		for (int y = 0; y<root->getVec().size();y++){
			preOrder(root->getVec()[y]);
		}
	}
	void postOrder(Node* root){
		for (int y = 0; y<root->getVec().size();y++){
			preOrder(root->getVec()[y]);
		}
		cout<<root->getData()<<endl;
	}
	void levelOrder(Node* root){
		static int cheat;
		Node* thing;
		if (cheat==0)
			cout<<root->getData();
		for (int y = 0; y<root->getVec().size();y++){
			cout<<root->getVec()[y]->getData();
		}
		for (int y = 0; y<root->getVec().size();y++){
			thing = root->getVec()[y];
			if (thing->getVec().size()>0){
				cheat++;
				levelOrder(thing);
			}
		}
	}
	Node* getConductor(){
		return conductor;
	}
	Node* getTemp(){return temp;}
	int getSize(){
		return size;
	}
};

int main(){
	srand(time(NULL));
	Tree thing;
	thing.prettyPrint(thing.getConductor());
	cout<<endl;
	thing.postOrder(thing.getConductor());
	cout<<endl;
	return 0;
}

		





	