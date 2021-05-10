#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class worstCell{
    vector<int> UsedCells;
    public:
    tuple<string,int> operator()(vector<pair<int,int>> cells,int richness,vector<tuple<string,int,int>> PossibleMoves){
        cerr<<"Starting of bestcell"<<endl;
        tuple<string,int> WorkTree;
        int data;
        for(int i = 0;i < PossibleMoves.size();i++){
            data=get<1>(PossibleMoves[i]);
            if (find(UsedCells.begin(),UsedCells.end(),data)==UsedCells.end()){
                cerr<<"NOT FOUND IN DATA BASE"<<endl;
                for(int j = 0; j < cells.size();j++){

                            if ((cells[j].first==data)&&(cells[j].second>richness)&&(cells[j].second<=1)){

                                    richness=cells[j].second;
                                    cerr<<"Found a better cell "<<richness<<endl;
                                    WorkTree = tuple(get<0>(PossibleMoves[i]),data);

                                }
                }
            }
            
        }   
        return WorkTree;
    }
};
class bestCell{
    vector<int> UsedCells;
    public:
    tuple<string,int> operator()(vector<pair<int,int>> cells,int richness,vector<tuple<string,int,int>> PossibleMoves){
        cerr<<"Starting of bestcell"<<endl;
        tuple<string,int> WorkTree;
        int data;
        for(int i = 0;i < PossibleMoves.size();i++){
            data=get<1>(PossibleMoves[i]);
            if (find(UsedCells.begin(),UsedCells.end(),data)==UsedCells.end()){
                cerr<<"NOT FOUND IN DATA BASE"<<endl;
                for(int j = 0; j < cells.size();j++){

                            if ((cells[j].first==data)&&(cells[j].second>richness)){

                                    richness=cells[j].second;
                                    cerr<<"Found a better cell "<<richness<<endl;
                                    WorkTree = tuple(get<0>(PossibleMoves[i]),data);

                                }
                }
            }
            
        }   
        return WorkTree;
    }
};


class bestCellSeed{
    public:
    tuple<string,int,int> operator()(vector<pair<int,int>> cells,vector<int> EnemyCells,vector<tuple<string,int,int>> PossibleMoves,int day,int richness=0){
        tuple<string,int,int> WorkSeed;
        for(int i=0;i<PossibleMoves.size();i++){
        int data=get<2>(PossibleMoves[i]);
            for(int j=0;j<cells.size();j++){
                    if (data==cells[j].first && (find(EnemyCells.begin(),EnemyCells.end(),data)==EnemyCells.end())&& cells[j].second>richness && cells[j].second<=3){
                        WorkSeed=PossibleMoves[i];
                        richness=cells[j].second;
                    }
            }
        }
        return WorkSeed;}
    
};
class Tree{
    int size;
    int index;

    public:
    Tree(int in,int s){
        index=in;
        size=s;
    }

    int getSize(){
        return size;
    }
    int getIndex(){
        return index;
    }

};
class Trees{
    int NbTreeOne=0;
    int NbTreeTwo=0;
    int NbTreeThree=0;
    int NbSeeds=0;
    vector<Tree> TreeOne={};
    vector<Tree> TreeTwo={};
    vector<Tree> TreeThree={};
    vector<Tree> Seeds={}; 
    vector<Tree> AllTrees={};
    public:
    int getNbTreeOne(){
        return NbTreeOne;
    }
    int getNbTreeTwo(){
        return NbTreeTwo;
    }
    int getNbTreeThree(){
        return NbTreeThree;
    }
    int getNbSeeds(){
        return NbSeeds;
    }
    vector<Tree> getTreeOne(){
        return TreeOne;
    }
    vector<Tree> getTreeTwo(){
        return TreeOne;
    }
    vector<Tree> getTreeThree(){
        return TreeThree;
    }
    vector<Tree> getSeeds(){
        return Seeds;
    }
    vector<Tree> getAllTrees(){
        return AllTrees;
    }

    void operator()(Tree T){
        int size=T.getSize();
        switch(size){
            case 0:
                Seeds.push_back(T);
                NbSeeds+=1;
                break;
            case 1: 
                TreeOne.push_back(T);
                NbTreeOne+=1;
                break;
            case 2:
                TreeTwo.push_back(T);
                NbTreeTwo+=1;
                break;
            case 3:
                TreeThree.push_back(T);
                NbTreeThree+=1;
                break;
            
            
        }
        AllTrees.push_back(T);
    }
};
class Costs{
    Trees Ts;
    public:
    Costs(Trees Ts){
        Ts=Ts;
    }
    int operator()(string Action,int currentSize){
        int actionIndex;

        if (Action=="GROW") actionIndex=1;
        else if (Action=="COMPLETE") actionIndex=2;
        else if (Action=="Seed") actionIndex=3;

        switch(actionIndex){
            case 2:
                return CompletePrice();
                break;
            case 3:
                return SeedPrice();
                break;
            case 1:
                if (currentSize==0) return TreeOnePrice();
                else if (currentSize==1) return TreeTwoPrice();
                else if (currentSize==2) return TreeThreePrice();

        }
        
    }
    int TreeOnePrice(){
        return 1+Ts.getNbTreeOne();
    }
    int TreeTwoPrice(){
        return 3+Ts.getNbTreeTwo();
    }
    int TreeThreePrice(){
        return 7+Ts.getNbTreeThree();
    }
    int SeedPrice(){
        return Ts.getNbSeeds();
    }
    int CompletePrice(){
        return 4;
    }


};
class PossibleMoves{
    vector<tuple<string,int,int>> Moves;
    public:
    PossibleMoves(vector<tuple<string,int,int>> M):Moves(M){};
    vector<tuple<string,int,int>> getMoves(){
        return Moves;
    }
};
class BestOption{
    vector<tuple<string,int,int>> Moves;
    Trees Ts;
    tuple<string,int,int> bestGrow=make_tuple("",-1,-1);
    vector<pair<int,int>> cells={};
    public:
    tuple<string,int,int> operator()(Trees Trs,PossibleMoves Pm,vector<pair<int,int>> allcells,int day){
        Moves=Pm.getMoves();
        Ts=Trs;
        cells=allcells;
        cerr<<"Entering Listing"<<endl;
        vector<int> Listing={searchTwoThreeGrow(),searchOneTwoGrow(),searchSeedGrow()};
        cerr<<"LISTING "<<Listing[0]<<" "<<Listing[1]<<" "<<Listing[2]<<endl;
        cerr<<day<<endl;
        int x=8;
        if (day<=x-3){
            if (Ts.getNbTreeThree()>1){
                tuple<string,int,int> a=CompleteSearch();
                if (get<0>(a)=="" && get<1>(a)==-1 ){
                    cerr<<"Entering Throw Seed"<<endl;
                    bestGrow=make_tuple("",-1,-1);
                }
                else bestGrow=a;}
            else{
                    int i;
                    for(i=0;i<Listing.size();i++) {
                        if (Listing[i]!=-1) {
                            bestGrow=make_tuple("GROW",Listing[i],-1);
                            break;}
                    }
                    if (i==Listing.size() && day%3==2) bestGrow=make_tuple("",-1,-1);
                
                    else if (get<0>(bestGrow)=="" && get<1>(bestGrow)==-1 && day%3<2){
                        bestGrow=searchSeedThrow();
                    }
                }}
        else if (day<=x){
            if (Ts.getNbTreeThree()>1){
                tuple<string,int,int> a=CompleteSearch();
                if (get<0>(a)=="" && get<1>(a)==-1 ){
                    cerr<<"Entering Throw Seed"<<endl;
                    bestGrow=make_tuple("",-1,-1);
                }
                else bestGrow=a;}
            else{
                    int i;
                    for(i=0;i<Listing.size();i++) {
                        if (Listing[i]!=-1) {
                            bestGrow=make_tuple("GROW",Listing[i],-1);
                            break;}
                    }
                    if (i==Listing.size()) bestGrow=make_tuple("",-1,-1);
                    else if (get<0>(bestGrow)=="" && get<1>(bestGrow)==-1 && day%3<2){
                        bestGrow=searchSeedThrow();
                    }
                
                }}
        else if(day>=x+1&&day<=x+3){
            cerr<<day<<"::::\n";
            int i;
                for(i=0;i<Listing.size();i++) {
                    if (Listing[i]!=-1) {
                        bestGrow=make_tuple("GROW",Listing[i],-1);
                        break;}
                }
                if (i==Listing.size()) bestGrow=make_tuple("",-1,-1);

        }
        else if(day>x+3 && day<x+7){
            if (Ts.getNbTreeThree()>6){
            tuple<string,int,int> a=CompleteSearch();
            if (get<0>(a)=="" && get<1>(a)==-1 ){
                cerr<<"Entering Throw Seed"<<endl;
                bestGrow=make_tuple("",-1,-1);
            }
            else bestGrow=a;}
            
        else{
                int i;
                for(i=0;i<Listing.size();i++) {
                    if (Listing[i]!=-1) {
                        bestGrow=make_tuple("GROW",Listing[i],-1);
                        break;}
                }
                if (i==Listing.size() && day%4<3) bestGrow=make_tuple("",-1,-1);
            
                else if (get<0>(bestGrow)=="" && get<1>(bestGrow)==-1 && day%4==3){
                    bestGrow=searchSeedThrow();
                }
            }

        }
        else if(day>=x+7 && day<x+7){
            if (Ts.getNbTreeThree()>3){
            tuple<string,int,int> a=CompleteSearch();
            if (get<0>(a)=="" && get<1>(a)==-1 ){
                cerr<<"Entering Throw Seed"<<endl;
                bestGrow=searchSeedThrow();
            }
            else bestGrow=a;}

        }
        else if (day<x+13){
            int i;
                for(i=0;i<Listing.size();i++) {
                    if (Listing[i]!=-1) {
                        bestGrow=make_tuple("GROW",Listing[i],-1);
                        break;}
                }
                if (i==Listing.size() ) bestGrow=make_tuple("",-1,-1);

        }
        else{
            if (Ts.getNbTreeThree()>0){
            tuple<string,int,int> a=CompleteSearch();
            if (get<0>(a)=="" && get<1>(a)==-1 ){
                cerr<<"Entering Throw Seed"<<endl;
                bestGrow=make_tuple("",-1,-1);
            }
            else bestGrow=a;}
        else{
                int i;
                for(i=0;i<Listing.size();i++) {
                    if (Listing[i]!=-1) {
                        bestGrow=make_tuple("GROW",Listing[i],-1);
                        break;}
                }
                if (i==Listing.size() ) bestGrow=make_tuple("",-1,-1);
            
                // else if (get<0>(bestGrow)=="" && get<1>(bestGrow)==-1 && day%6==5){
                //     bestGrow=searchSeedThrow();
                // }
            }

        }
        
        return bestGrow;



    }
    tuple<string,int,int> CompleteSearch(){
        for(int i=0;i<Moves.size();i++){
            tuple<string,int,int> data=Moves[i];
            if (get<0>(data)=="COMPLETE"){
                return data;
            }
        }
        return make_tuple("",-1,-1);

    }
    int searchTwoThreeGrow(){
        int notFound1=0;
        for (int i=0;i<Moves.size();i++){
            if (get<0>(Moves[i])=="GROW"){
                vector<Tree> AllTrees=Ts.getAllTrees();
                int notFound=0;
                for(int j=0;j<AllTrees.size();j++){
                    if (AllTrees[j].getSize()==2 && get<1>(Moves[i])==AllTrees[j].getIndex()) return AllTrees[j].getIndex();
                    else notFound+=1;
                }
                if (notFound==AllTrees.size()){
                    return -1;
                }
            }
            else notFound1+=1;
            

        }
        return -1;
    }

    int searchOneTwoGrow(){
        int notFound1=0;
        for (int i=0;i<Moves.size();i++){
            if (get<0>(Moves[i])=="GROW"){
                vector<Tree> AllTrees=Ts.getAllTrees();
                int notFound=0;
                for(int j=0;j<AllTrees.size();j++){
                    if (AllTrees[j].getSize()==1 && get<1>(Moves[i])==AllTrees[j].getIndex()) return AllTrees[j].getIndex();
                    else notFound+=1;
                }
                if (notFound==AllTrees.size()){
                    return -1;
                }
            }
            else notFound1+=1;
            

        }
        return -1;
    }

    int searchSeedGrow(){
        int notFound1=0;
        for (int i=0;i<Moves.size();i++){
            if (get<0>(Moves[i])=="GROW"){
                vector<Tree> AllTrees=Ts.getAllTrees();
                int notFound=0;
                for(int j=0;j<AllTrees.size();j++){
                    if (AllTrees[j].getSize()==0 && get<1>(Moves[i])==AllTrees[j].getIndex()) return AllTrees[j].getIndex();
                    else notFound+=1;
                }
                if (notFound==AllTrees.size()){
                    return -1;
                }
            }
            else notFound1+=1;
            

        }
        return -1;
    }

    tuple<string,int,int> searchSeedThrow(){
        int notFound1=0;
        int richness=0;
        tuple<string,int,int> WorkSeed;
        for (int i=0;i<Moves.size();i++){
            if (get<0>(Moves[i])=="SEED"){
                int data=get<2>(Moves[i]);
                vector<Tree> AllTrees=Ts.getAllTrees();


                for(int j=0;j<cells.size();j++){
                    
                    if (data==cells[j].first && cells[j].second>richness) {
                        WorkSeed=Moves[i];
                        richness=cells[j].second;}
                }
            }
            else notFound1+=1;
            

        }
        cerr<<"PRoblem Here?"<<endl;
        if (notFound1==Moves.size()) {
            cerr<<"-1"<<endl;
            return make_tuple("",-1,-1);}
        else return WorkSeed;
    }
};
int main()
{   
    vector<pair<int,int>> cells;

    int numberOfCells; // 37
    cin >> numberOfCells; cin.ignore();
    for (int i = 0; i < numberOfCells; i++) {
        int index; // 0 is the center cell, the next cells spiral outwards
        int richness; // 0 if the cell is unusable, 1-3 for usable cells
        int neigh0; // the index of the neighbouring cell for each direction
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
        cells.push_back(make_pair(index,richness));
    }

    // game loop
    vector<pair<pair<int,int>,int>> MyCells;
    string s;
    int completed=0;
    bestCell Bcell;
    worstCell Wcell;
    bestCellSeed BcellSeed;
    vector<int> EnemyCells;
    int Completed=0; // 0 if not working on a tree , 1 if working currently on a tree
    while (1) {
        vector<tuple<string,int,int>> PMoves;
        Trees Ts;
        BestOption Bop;
        int day; // the game lasts 24 days: 0-23
        cin >> day; cin.ignore();
        int nutrients; // the base score you gain from the next COMPLETE action
        cin >> nutrients; cin.ignore();
        int sun; // your sun points
        int score; // your current score
        cin >> sun >> score; cin.ignore();
        int oppSun; // opponent's sun points
        int oppScore; // opponent's score
        bool oppIsWaiting; // whether your opponent is asleep until the next day
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        int numberOfTrees; // the current amount of trees
        cin >> numberOfTrees; cin.ignore();

        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
            if (isMine){
                Tree T(cellIndex,size);
                Ts(T);
                cerr<<"NbTreeOne : "<<Ts.getNbTreeOne()<<" NbTreeTwo : "<<Ts.getNbTreeTwo()<<" NbTreeThree : "<<Ts.getNbTreeThree()<<endl;
                
            }
        }
        
        for (int i=0;i<EnemyCells.size();i++) cerr<<EnemyCells[i]<<" ";cerr<<endl;
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves; cin.ignore();
        cerr<<"POSSIBLE MOVES "<<endl;
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string Part1;
            int Part2,Part3;
            cin>>Part1; cin.ignore();
            if(Part1 != "WAIT" && (Part1 != "SEED")){
                cin>>Part2;
                PMoves.push_back(make_tuple(Part1,Part2,-1));}
            else if(Part1=="SEED"){
                cin>>Part2>>Part3;
                cin.ignore();
                PMoves.push_back(make_tuple(Part1,Part2,Part3));
            }
        }
        PossibleMoves Pm(PMoves);
        tuple<string,int,int> B=Bop(Ts,Pm,cells,day);
        if (PMoves.size()!=0 && B!=make_tuple("",-1,-1)){
            
            cerr<<get<0>(B)<<endl;
            if (get<0>(B)!="SEED"){  
                cout<<get<0>(B)<<" "<<get<1>(B)<<endl;}
            else {
                
                cout<<get<0>(B)<<" "<<get<1>(B)<<" "<<get<2>(B)<<endl;
            }
        }
        else cout<<"WAIT"<<endl;
        

        

        

        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        }
}