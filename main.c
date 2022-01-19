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

void create_character(struct character *character, char *name, int gender, int race, int strength, int dexterity, int luck);

int calculate_stats(struct character *character);

int main(void)
{

    struct character hero_0;
    struct character hero_1;
    struct character hero_2;
    
    //create test charactera
    create_character(&hero_2, "BooBear", 0, 1, 4, 4, 1);


    calculate_stats(&hero_0);
    calculate_stats(&hero_1);
    calculate_stats(&hero_2);

    // printf("Name = %s\n", hero_0.demographic.name);
    // printf("Attack = %.1f\n", hero_0.attr.stats.attack);
    // printf("Defend = %.1f\n", hero_0.attr.stats.defend);
    // printf("Attack Speed = %.1f\n", hero_0.attr.stats.attack_speed);
    // printf("Critical = %.1f\n", hero_0.attr.stats.critical);
    // printf("HP = %.1f\n", hero_0.attr.stats.hp);
    // printf("\n");
    // printf("Name = %s\n", hero_1.demographic.name);
    // printf("Attack = %.1f\n", hero_0.attr.stats.attack);
    // printf("Defend = %.1f\n", hero_0.attr.stats.defend);
    // printf("Attack Speed = %.1f\n", hero_0.attr.stats.attack_speed);
    // printf("Critical = %.1f\n", hero_0.attr.stats.critical);
    // printf("HP = %.1f\n", hero_0.attr.stats.hp);
    printf("\n");
    printf("Name = %s\n", hero_2.demographic.name);
    printf("Attack = %.1f\n", hero_2.attr.stats.attack);
    printf("Defend = %.1f\n", hero_2.attr.stats.defend);
    printf("Attack Speed = %.1f\n", hero_2.attr.stats.attack_speed);
    printf("Critical = %.1f\n", hero_2.attr.stats.critical);
    printf("HP = %.1f\n", hero_2.attr.stats.hp);

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

void create_character(struct character *character, char *name, int gender, int race, int strength, int dexterity, int luck)
{
    strcpy(character->demographic.name, name);
    character->demographic.gender = gender;
    character->demographic.race = race;
    character->attr.str = strength;
    character->attr.dex = dexterity;
    character->attr.luck = luck;
}

