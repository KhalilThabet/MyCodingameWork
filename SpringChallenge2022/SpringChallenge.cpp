#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Entity{
    public :
    int id; // Unique identifier
    int type; // 0=monster, 1=your hero, 2=opponent hero
    int x; // Position of this entity
    int y;
    int shield_life; // Ignore for this league; Count down until shield spell fades
    int is_controlled; // Ignore for this league; Equals 1 when this entity is under a control spell
    int health; // Remaining health of this monster
    int vx; // Trajectory of this monster
    int vy;
    int near_base; // 0=monster with no target yet, 1=monster targeting a base
    int threat_for;
};
class Monster: public Entity{
    public:
    Monster(int* args){
        id=args[0];
        type=args[1];
        x=args[2];
        y=args[3];
        shield_life=args[4];
        is_controlled=args[5];
        health=args[6];
        vx=args[7];
        vy=args[8];
        near_base=args[9];
        threat_for=args[10];
    }
};
class Hero: public Entity{
    public:
    Hero(int* args){
        id=args[0];
        type=args[1];
        x=args[2];
        y=args[3];
        shield_life=args[4];
        is_controlled=args[5];
        health=args[6];
        vx=args[7];
        vy=args[8];
        near_base=args[9];
        threat_for=args[10];
    }

};
class Enemy: public Entity{
    static vector<Enemy*> EnemyTable;
    public:
    Enemy(int* args){
        id=args[0];
        type=args[1];
        x=args[2];
        y=args[3];
        shield_life=args[4];
        is_controlled=args[5];
        health=args[6];
        vx=args[7];
        vy=args[8];
        near_base=args[9];
        threat_for=args[10];
    }
};
class Data{
    static vector<Monster*> MonsterTable;
    static vector<Enemy*> EnemyTable;
    static vector<Hero*> HeroTable;
    public:
    void operator()(int* args){
        if (args[1]==2) processEnemy(args);
        if (args[1]==0) processMonster(args);
        if (args[1]==1) processHero(args);
    }
    void processHero(int* args){
        int tempVar=0;
        for (Hero* hero:HeroTable){
            cerr<<hero->id<<" "<<args[0]<<endl;
            if (hero->id==args[0]){
                hero->type=args[1];
                hero->x=args[2];
                hero->y=args[3];
                hero->shield_life=args[4];
                hero->is_controlled=args[5];
                hero->health=args[6];
                hero->vx=args[7];
                hero->vy=args[8];
                hero->near_base=args[9];
                hero->threat_for=args[10];
                tempVar=1;
                cerr<<"ENSize "<<HeroTable.size()<<endl;
            }
        }
        if (tempVar==0) this->HeroTable.push_back(new Hero(args));
    }
    void processMonster(int* args){
        int tempVar=0;
        for (Monster* monster:MonsterTable){
            cerr<<monster->id<<" "<<args[0]<<endl;
            if (monster->id==args[0]){
                monster->type=args[1];
                monster->x=args[2];
                monster->y=args[3];
                monster->shield_life=args[4];
                monster->is_controlled=args[5];
                monster->health=args[6];
                monster->vx=args[7];
                monster->vy=args[8];
                monster->near_base=args[9];
                monster->threat_for=args[10];
                tempVar=1;
                cerr<<"ENSize "<<MonsterTable.size()<<endl;
            }
        }
        if (tempVar==0) this->MonsterTable.push_back(new Monster(args));
    }
    void processEnemy(int* args){
        int tempVar=0;
        for (Enemy* enemy:EnemyTable){
            cerr<<enemy->id<<" "<<args[0]<<endl;
            if (enemy->id==args[0]){
                enemy->type=args[1];
                enemy->x=args[2];
                enemy->y=args[3];
                enemy->shield_life=args[4];
                enemy->is_controlled=args[5];
                enemy->health=args[6];
                enemy->vx=args[7];
                enemy->vy=args[8];
                enemy->near_base=args[9];
                enemy->threat_for=args[10];
                tempVar=1;
                cerr<<"ENSize "<<EnemyTable.size()<<endl;
            }
        }
        if (tempVar==0) this->EnemyTable.push_back(new Enemy(args));
    }
    static vector<Monster*> get_Monsters(){
        return MonsterTable;
    }
    static vector<Hero*> get_Heroes(){
        return HeroTable;
    }
    static vector<Enemy*> get_Enemies(){
        return EnemyTable;
    }
};
vector<Monster*> Data :: MonsterTable;
vector<Enemy*> Data :: EnemyTable;
vector<Hero*> Data :: HeroTable;

int main()
{
    int base_x; // The corner of the map representing your base
    int base_y;
    cin >> base_x >> base_y; cin.ignore();
    int heroes_per_player; // Always 3
    cin >> heroes_per_player; cin.ignore();
    // game loop
    while (1) {
        for (int i = 0; i < 2; i++) {
            int health; // Each player's base health
            int mana; // Ignore in the first league; Spend ten mana to cast a spell
            cin >> health >> mana; cin.ignore();
        }
        int entity_count; // Amount of heros and monsters you can see
        cin >> entity_count; cin.ignore();
        for (int i = 0; i < entity_count; i++) {
            int id; // Unique identifier
            int type; // 0=monster, 1=your hero, 2=opponent hero
            int x; // Position of this entity
            int y;
            int shield_life; // Ignore for this league; Count down until shield spell fades
            int is_controlled; // Ignore for this league; Equals 1 when this entity is under a control spell
            int health; // Remaining health of this monster
            int vx; // Trajectory of this monster
            int vy;
            int near_base; // 0=monster with no target yet, 1=monster targeting a base
            int threat_for; // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
            cin >> id >> type >> x >> y >> shield_life >> is_controlled >> health >> vx >> vy >> near_base >> threat_for; cin.ignore();
            int args[]={id,type,x,y,shield_life,is_controlled,health,vx,vy,near_base,threat_for};
            Data tracker;
            tracker(args);

        
        
        }
        cerr<<"Number Of Monsters : "<<Data::get_Monsters().size()<<endl;
        cerr<<"Number Of Heroes"<<Data::get_Heroes().size()<<endl;
        cerr<<"Number of Enemies : "<<Data::get_Enemies().size()<<endl;
        
        for (int i = 0; i < heroes_per_player; i++) {

            
        }
    }
}