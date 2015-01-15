#include <iostream>
#include <vector>
using namespace std;
class pQueue{
	private:
		vector<int> queue;
	public:
		void add(){
			queue.push_back(rand()%100);
		}
		void add(int priority){
			queue.push_back(priority);
		}
		void del(){
			int maxPos = 0;
			for(int a = 0; a<queue.size();a++){
				if (queue[maxPos]<queue[a])
					maxPos = a;
			}
			queue.erase(queue.begin()+maxPos);
		}
		void print(){
			cout<< "[";
			for (int x = 0; x<queue.size();x++){
				cout<<queue[x]<<",";
			}
			cout<<"]";
			cout<<endl;
		}
};

int main(){
	pQueue myQ;
	for(int a = 0; a<10; a++){
		myQ.add();	
	}
	myQ.print();
	for(int b = 0; b<10; b++){
		myQ.print();
		myQ.del();

	}
}

