#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;
class Npainted{
    private:
    list<pair<int,int>> Unpainted;
    public:
        void filling(list<pair<int,int>> P,int L){
            list<pair<int,int>>::iterator itr;
            cerr<<"Enter Filling"<<" "<<P.size()<<endl;
            if(P.begin()->first!=0) {
                    Unpainted.push_back(make_pair(0,P.begin()->first));
                }
            
            for(itr=next(P.begin());itr!=P.end();itr++){
                //cerr<<prev(itr)->second<<","<<itr->first<<endl;
                Unpainted.push_back(make_pair(prev(itr)->second,itr->first));
                }

            if(prev(itr)->second!=L){
                Unpainted.push_back(make_pair(prev(itr)->second,L));
                    }

            cerr<<"Quitting out filling"<<endl;
            }
        list<pair<int,int>> operator()(list<pair<int,int>> Painted,int L){
                filling(Painted,L);
                return Unpainted;
        }

    
};
class mergeOverlap{
    public:


        pair<int,int> mergePairs(pair<int,int> P1,pair<int,int> P2){
            return make_pair(min(P1.first,P2.first),max(P1.second,P2.second));
}



        bool Overlapping(pair<int,int> P1,pair<int,int> P2){
            if ((P1.first>P2.second && P1.second>P2.second)||(P2.first>P1.second && P2.second>P1.second)){
                //cerr<<"NotOverlapping"<<endl;
                return 0;
            }
            else return 1;
        } 



        bool OverlapPersistant(list<pair<int,int>> vec){
            list<pair<int,int>>::iterator itr=vec.begin();
            while(itr!=prev(vec.end())){
                    if(Overlapping(*itr,*next(itr))){
                        return 1;
                    }  
                advance(itr,1);}
            return 0;

        }



        list<pair<int,int>> Browse(list<pair<int,int>> V){
            list<pair<int,int>>::iterator itr,itr1,itr2;
            pair<pair<int,int>,pair<int,int>> M;
            while(OverlapPersistant(V)){
                itr=V.begin();
                    while(itr!=prev(V.end())){
                        itr1=next(itr);
                        M=make_pair(*itr,*itr1);
                        advance(itr,1);
                        if (Overlapping(M.first,M.second)) {
                            cerr<<"*******before*******"<<endl;
                            screen(V);
                            V.emplace(itr,mergePairs(M.first,M.second));
                            itr2=prev(itr);
                            itr1=prev(prev(itr));//the emplacement of the new element
                            cerr<<"*******afterAdd********"<<endl;
                            screen(V);
                            *V.erase(itr);
                            cerr<<"*******firstErase*******"<<endl;
                            screen(V);
                            *V.erase(itr1);
                            cerr<<"*****secondErase*******"<<endl;
                            screen(V);
                            itr=itr2;
                
                        }
                    }

                
            }
            return V;
        }

        list<pair<int,int>> operator()(list<pair<int,int>> a){
            return Browse(a);
        }

        void screen(list<pair<int,int>> vec){
            list<pair<int,int>>::iterator itr;
            for(itr=vec.begin();itr!=vec.end();itr++) cerr<<"("<<itr->first<<","<<itr->second<<")"<<endl;
        }
};
void screene(list<pair<int,int>> vec){
            list<pair<int,int>>::iterator itr;
            for(itr=vec.begin();itr!=vec.end();itr++) cout<<itr->first<<" "<<itr->second<<endl;
        }

int main()
{   
    int L;
    cin >> L; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    int x=0;
    
    list<pair<int,int>> v1;
    for (int i = 0; i < N; i++) {
        int st;
        int ed;
        cin >> st >> ed; cin.ignore();
        cerr<<"("<<st<<","<<ed<<")"<<endl;
        v1.push_back(make_pair(st,ed));

    }
    v1.sort();
    mergeOverlap mergedList;
    Npainted Unpainted;
    v1=mergedList(v1);
    if (v1.size()==1 && *v1.begin()==make_pair(0,L)) cout<<"All painted"<<endl;
    else{
        screene(Unpainted(v1,L));
    }
    
    
    
    }
