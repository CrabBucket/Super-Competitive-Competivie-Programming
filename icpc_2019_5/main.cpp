#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Returns true if the two strings are not swap-free
bool swapable(const string& s1, const string& s2){
	if(&s1 == &s2) return false;
	char a, b;
	bool flaw = false;
	for(int i = 0; i < s1.size(); i++){
		if(s1[i] != s2[i]){
			if(flaw){
				if(s1[i] == b and s2[i] == a){
					for(i++; i < s1.size(); i++){
						if(s1[i] != s2[i])
							return false;
					}
					return true;
				}
				return false;
			}
			a = s1[i];
			b = s2[i];
			flaw = true;
		}
	}
	return true;
}

//Node struct to represent a word in a graph structure
struct Node{
	string str;
	vector<Node*> neighbors;
};

//Deletes a node from nodes and handles dependencies
void deleteNode(vector<Node*>& nodes, int index){
	Node* temp = nodes[index];
	for(Node* n : nodes){
		for(int i = 0; i < n->neighbors.size(); i++){
			if(n->neighbors[i] == temp){
				n->neighbors.erase(n->neighbors.begin() + i);
			}
		}
	}
	nodes.erase(nodes.begin() + index);
}

//Finds index of nodes with the most neighbors
int findMax(vector<Node*>& nodes){
	int max = 0, index = 0;
	for(int i = 0; i < nodes.size(); i++){
		if(nodes[i]->neighbors.size() > max) {
			max = nodes[i]->neighbors.size();
			index = i;
		}
	}
	return index;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();

	vector<Node*> nodes;
	string buffer;
	while(n--){
		getline(cin, buffer);
		Node* n = new Node;
		n->str = buffer;
		nodes.push_back(n);
	}

	//assign neighbors
	for(vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++){
		for(vector<Node*>::iterator jt = nodes.begin(); jt != nodes.end(); jt++){
			if(swapable((*it)->str, (*jt)->str)){
				(*it)->neighbors.push_back(*jt);
			}
		}
	}

	///// DEBUGGING PRINT SHTUFF
	// for(Node* n : nodes){
	// 	cout << n->str << ": ";
	// 	for(Node* m : n->neighbors){
	// 		cout << m->str << " ";
	// 	}
	// 	cout << '\n';
	// }

	//Continually delete nodes until set is swap-free
	int max = findMax(nodes);
	while(nodes[max]->neighbors.size() > 1){
		deleteNode(nodes, max);
		max = findMax(nodes);
	}

	cout << nodes.size();

	return 0;
}