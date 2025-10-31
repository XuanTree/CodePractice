#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Chararcter{
    double player_health;
    double player_defence;
    double player_damage;
    double enemy_health;
    double enemy_defence;
    double enemy_damage;
}Chararcter;
Chararcter chararcterSet(double cha1_h,double cha1_d,double cha1_a){
    Chararcter ch;
    srand(time(NULL));
    ch.enemy_damage = rand() % 100 + 1;
    ch.enemy_defence = rand() % 10 + 1;
    ch.enemy_health = rand() % 10000 + 1;
    ch.player_damage = cha1_a;
    ch.player_defence = cha1_d;
    ch.player_health = cha1_h;
    printf("\t玩家数据 | 敌人数据\n");
    printf("------------------\n");
    printf("生命值: %.2lf | %.2lf \n",cha1_h,ch.enemy_health);
    printf("------------------\n");
    printf("防御值: %.2lf | %.2lf \n",cha1_d,ch.enemy_defence);
    printf("------------------\n");
    printf("伤害值: %.2lf | %.2lf \n",cha1_a,ch.enemy_damage);
    printf("------------------\n");
    return ch;
}
Chararcter playerRound(double player_damage){
    Chararcter enemy;
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
    Chararcter(*p_characterSet)(double,double,double);
    p_characterSet = &chararcterSet;
    printf("Welcome to the C Console Game!");
    printf("");
    Chararcter show = p_characterSet(player_health,player_defence,player_damage);
    Divider();
}