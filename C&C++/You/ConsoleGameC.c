#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Character{
    double player_health;
    double player_defence;
    double player_damage;
    double enemy_health;
    double enemy_defence;
    double enemy_damage;
}Character;
Character characterSet(double cha1_h,double cha1_d,double cha1_a){
    Character ch;
    srand(time(NULL));
    ch.enemy_damage = rand() % 100 + 1;
    ch.enemy_defence = rand() % 10 + 1;
    ch.enemy_health = rand() % 10000 + 1;
    ch.player_damage = cha1_a;
    ch.player_defence = cha1_d;
    ch.player_health = cha1_h;
    printf("    Player Data | Enemy Data\n");
    printf("------------------------------\n");
    printf(" HP:\t %.2lf | %.2lf \n",cha1_h,ch.enemy_health);
    printf("------------------------------\n");
    printf(" Defence:%.2lf | %.2lf \n",cha1_d,ch.enemy_defence);
    printf("------------------------------\n");
    printf(" Damage: %.2lf | %.2lf \n",cha1_a,ch.enemy_damage);
    printf("------------------------------\n");
    return ch;
}
Character playerRound(double player_damage){
    Character enemy;
    enemy.enemy_health = enemy.enemy_health + enemy.enemy_defence - player_damage;
    return enemy;
}
void Divider(){
    printf("\n");
    printf("--------------------");
    printf("\n");
    return;
}
int main(){
    double player_health;
    double player_defence;
    double player_damage;
    Character(*p_characterSet)(double,double,double);
    Character(*p_playerRound)(double);
    p_characterSet = &characterSet;
    p_playerRound = &playerRound;
    printf("Welcome to the C Console Game!\n");
    printf("Input your data(HP Defence Damage):");
    scanf("%lf %lf %lf",&player_health,&player_defence,&player_damage);
    Character ch = p_characterSet(player_health,player_defence,player_damage);
    Character en = p_playerRound(ch.player_damage);
}