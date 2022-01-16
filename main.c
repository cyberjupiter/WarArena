#include <stdio.h>
#include <string.h>

struct demographic{
    char name[32];
    int gender;
    int race;
};

struct class{
    char job[64];
};

struct status{
    double attack;
    double defend;
    double attack_speed;
    double critical;
    double hp;
};

struct attributes{
    int str;
    int dex;
    int luck;
    struct status stats;
};

struct character{
    struct demographic demographic;
    struct class class;
    struct attributes attr;
    int type;
};

int calculate_stats(struct character *character);

int main(void)
{

    struct character hero_0;
    
    //create test character
    strcpy(hero_0.demographic.name, "Aiman Mazlan");
    hero_0.demographic.gender = 1;
    hero_0.demographic.race = 1;
    hero_0.attr.str = 10;
    hero_0.attr.dex = 15;
    hero_0.attr.luck = 0;

    calculate_stats(&hero_0);

    printf("Attack = %.1f\n", hero_0.attr.stats.attack);
    printf("Defend = %.1f\n", hero_0.attr.stats.defend);
    printf("Attack Speed = %.1f\n", hero_0.attr.stats.attack_speed);
    printf("Critical = %.1f\n", hero_0.attr.stats.critical);
    printf("HP = %.1f\n", hero_0.attr.stats.hp);

    return 0;
}


int calculate_stats(struct character *character)
{
    character->attr.stats.attack = character->attr.str * character->attr.dex * 0.2;
    character->attr.stats.defend = character->attr.str * 0.5;
    character->attr.stats.attack_speed = character->attr.dex * 0.5;
    character->attr.stats.critical = character->attr.luck * 0.5;
    character->attr.stats.hp = character->attr.str * 10;
    //
}
