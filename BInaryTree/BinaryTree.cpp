#include <iostream>
using namespace std;
class Node{
private:
	Node* left;
	Node* right;
	int data;
public:
	Node(){
		left = NULL;
		right = NULL;
		data = 0;
	}
	Node(int x){
		left = NULL;
		right = NULL;
		data = x;
	}
	int getData(){return data;}
	Node* getLeft(){return left;}
	Node* getRight(){return right;}
	void setLeft(Node* x){left=x;}
	void setRight(Node* x){right=x;}
};

class BinarySearchTree{
private:
	Node* conductor;
	Node* temp;
public:
	BinarySearchTree(){
		conductor = new Node();
		temp = conductor;
	}
	BinarySearchTree(int x){
		conductor = new Node(x);
		temp = conductor;
	}
	Node* getConductor(){
		return conductor;
	}
	Node* getTemp(){
		return temp;
	}
	void reset(){
		temp = getConductor();
	}
	bool lookup(int x){
		if ((int)x==(int)temp->getData()){
			return true;
		}
		else{
			if (x>temp->getData()){
				if(temp->getRight()!=NULL){
					temp = temp->getRight();
					return lookup(x);
				}
				else{
					return false;
				}
			}
			else{
				if(temp->getLeft()!=NULL){
					temp = temp->getLeft();
					return lookup(x);
				}
				else{
					return false;
				}
			}
		}
	}
	void insert(int x){

			if (x>temp->getData()){
				if(temp->getRight()!=NULL){
					temp->setLeft(new Node(x));
					insert(x);
				}
				else{
					temp->setRight(new Node(x));

				}
			}
			else{
				if(temp->getLeft()!=NULL){
					temp = temp->getLeft();
					insert(x);
				}
				else{
					temp->setLeft(new Node(x)); 
				}
			}
		}
	int maxHeight(Node *root) {
	  if (!root) return 0;
	  int left_height = maxHeight(root->getLeft());
	  int right_height = maxHeight(root->getRight());
	  return (left_height > right_height) ? left_height + 1 : right_height + 1;
	}
	int maxValue(){
		while (temp->getRight()!=NULL){
			temp = temp->getRight();
		}
		return temp->getData();

	}
	int minValue(){
		while (temp->getLeft()!=NULL){
				temp = temp->getLeft();
		}
		return temp->getData();
	}
int size(Node *leaf) const 
{
    if(leaf == NULL) { //This node doesn't exist. Therefore there are no nodes in this 'subtree'
        return 0;
    } else { 
    	//Add the size of the left and right trees, then add 1 (which is the current node)
        return size(leaf->getLeft()) + size(leaf->getRight()) + 1;
    }
}
};
int main(){
	BinarySearchTree thing(10);
	thing.insert(7);
	thing.reset();
	thing.insert(11);
	thing.reset();
	thing.insert(6);
	thing.reset();
	cout<<thing.lookup(7)<<endl;
	thing.reset();
	cout<<thing.size(thing.getTemp())<<endl;
	thing.reset();
	cout<<thing.maxHeight(thing.getTemp())<<endl;
	thing.reset();
	cout<<thing.maxValue()<<endl;
	cout<<"Hello"<<endl;
	return 0;
}