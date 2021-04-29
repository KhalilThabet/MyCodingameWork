#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> line(vector<int>& oldLine){
    vector<int> result;
    vector<int>::iterator itr=oldLine.begin();
    int x=0;
    while(itr!=oldLine.end()){
        x+=1;
        if(*itr!=*next(itr)){
            result.push_back(x);
            result.push_back(*itr);
            x=0;
        }
        advance(itr,1);
    }
    oldLine=result;
    return result;

}
void display(vector<int> Data){
    vector<int>::iterator itr;
    cerr<<"{ ";
    for(itr=Data.begin();itr!=prev(Data.end());itr++){
        cerr<<" "<<*itr<<" ";
        cout<<*itr<<" ";
    }
    cerr<<*itr<<" }\n";
    cout<<*itr;
}
int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();
    vector<int> l={R};
    if (L>=2){
    for(int i=2;i<L+1;i++) display(line(l));}
    display(l);

   
}