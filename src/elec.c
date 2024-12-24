#include "rng.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct _elec{
    long long value;
} elec;

typedef struct _elecconnection{
    elec* first;
    elec* second;
    long long strength;
} elecconnection;

elecconnection ConnectElecs(elec* first, elec* second, long long strength){
    first->value += strength;
    second->value += strength;
    elecconnection eleccon = {first, second, strength};
    return eleccon;
}

void DisconnectElecs(elecconnection* con){
    con->first->value -= con->strength;
    con->second->value -= con->strength;
    con->first = NULL;
    con->second = NULL;
    con->strength = 0;
    // con->incrementstrength = {0};
}

void SyncConnection(elecconnection* con, long long original){
    long long orgstr;
    if(original == (long long)NULL){
        orgstr = con->strength;
    } else {
        orgstr = original;
    }
    con->first->value -= orgstr;
    con->second->value -= orgstr;
    con->first->value += con->strength;
    con->second->value += con->strength;
}

void PrintStatus(elecconnection* con){
    printf("-------------------------------\n");
    printf("elec 1: %lld\nelec 2: %lld\nconnection value: %lld\n", con->first->value, con->second->value, con->strength);
    printf("-------------------------------\n");

}
void AddStrengthToConnection(elecconnection* con, long long amount){
    long long original = con->strength;
    con->strength += amount;
    SyncConnection(con, original);
}

elec DuplicateElecs(elec* elecc){
   elec dup = {elecc->value};
   return dup;
}

elecconnection DuplicateConnection(elecconnection* elec){
   elecconnection dup = {elec->first, elec->second, elec->strength};
   return dup;
}


void StrengthAdderCli(elecconnection* con){
    printf("-----------------------\n| Strength Adder Cli! |\n-----------------------\n\n");
    while(1){
        char buffer[512];
        printf("add strength: ");
        fgets(buffer, 512, stdin);
        strtok(buffer, "\n");
        if(strcmp(buffer, "current") == 0){
            PrintStatus(con);
            continue;
        }
        long long num = atoll(buffer);
        if(num == (long long)NULL){
            printf("Enter a Valid Number Please!\n");
            continue;
        }
        if(num < 0 && con->strength + num < 1){
            printf("Can't Go to Negative Strength!\n");
            continue;
        }
        AddStrengthToConnection(con, num);
        PrintStatus(con);
    }
    PrintStatus(con);
    AddStrengthToConnection(con, 10);
    PrintStatus(con);
}

int main(){
    elec elecc = {GenRanNumRange(GetMS(), 0, 30)};
    

    elec selec = {GenRanNumRange(GetMS(), 0, 30)};
    elecconnection con = ConnectElecs(&elecc, &selec, GenRanNumRange(GetMS(), 0, 30));
    StrengthAdderCli(&con);
    DisconnectElecs(&con);
}