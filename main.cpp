
#include <iostream>

class creep{
public:
    std::string name;
    int xp;
    int gold;
    int hp;
    
    int mg();
    int me();
    
        
    
};

class hero{
public:
    std::string name;
    int dmg;
    float attack_speed;
    int armour;
    int hp;
    float strength;
    float agility;
    float intel;
    
    float tKillCamp(creep toKill){
        float dps = dmg/ attack_speed;
        float time = toKill.hp/ dps;
        
        return time;
        
        
    }
    
    
    hero(int level, float bs, float ba, float bi, float sg, float ag, float ig, int type, int baseAttack){
        
        strength = bs + level * sg;
        agility= ba + level * ag;
        intel = bi + level * ig;
        switch(type){
            case 0:
                dmg = baseAttack + strength;
                break;
            case 1:
                dmg = baseAttack + agility;
                break;
            case 2:
                dmg = baseAttack + intel;
                break;
        }
        
        
    }
    
};

//float hero::tKillCamp(<#creep toKill#>)


std::string bmg(creep one, creep two);
std::string bme(creep one, creep two);

int main(int argc, const char * argv[]) {
    creep golem;
    golem.name = "golem";
    golem.xp = 42;
    golem.gold = 32;
    golem.hp = 800;
    
    hero jug(1,20, 26, 14, 1.9, 2.4, 1.4, 1, 24);
    jug.name = "jug";
    jug.hp = 1500;
    //jug.dmg = 100;
    jug.armour = 5;
    jug.attack_speed = 0.3;
    
    
    creep centaur;
    centaur.name = "centaur";
    centaur.xp = 119;
    centaur.hp = 1100;
    centaur.gold = 72;

    
    //std::cout << "if you want gold us midas on:" << bmg(golem, centaur) << std::endl;
    //std::cout << "if you want xp us midas on:" << bme(golem, centaur) << std::endl;
    std::cout << "Time to kill golem camp is: "  << jug.tKillCamp(golem) << std::endl;

    
    
}

int creep::mg(){
    return 220;
}

int creep::me(){
    return xp * 1.75;
}

std::string bmg(creep one, creep two){
    return(one.gold < two.gold ? one.name:two.name);
    
}

std::string bme(creep one, creep two){
    return(one.xp > two.xp ? one.name:two.name);
}







