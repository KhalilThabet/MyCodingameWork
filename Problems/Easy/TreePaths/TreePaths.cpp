#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<ostream>
using namespace std;

class Node{
    public:
    Node* Left,*Right,*Elder;
    int data;
    Node(int,Node*,Node*);
    void Show();
    friend ostream& operator<<(ostream& w,Node A){
        return w<<"Left:"<<A.Left->data<<" Right:"<<A.Right->data<<" Data:"<<A.data<<endl;
    };
};
class Tree{
    public:
    static vector<Node> Vec;
    Tree(Node);
    Node Shoow();

}; 
Tree::Tree(Node A){
    Vec[0]=A;
}
Node Tree::Shoow(){
    return Vec[0];
}
Node::Node(int DATA,Node*L=NULL,Node*B=NULL){
    Left=L;
    Right=B;
    data=DATA;

}
void Node::Show(){
    cout<<data<<endl;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    int V;
    cin >> V; cin.ignore();
    int M;
    cin >> M; cin.ignore();
    std::vector<int> T;
    for (int i = 0; i < M; i++) {
        int P;int L;int R;
        cin >> P >> L >> R; cin.ignore();
        
    }
    Node* L=new Node(2);
    Node* R=new Node(3);
    Node x(1,L,R);
    Tree Tr(x);

}