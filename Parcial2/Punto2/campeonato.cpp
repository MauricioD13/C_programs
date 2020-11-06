#include "listas.cpp"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <cstring>
/*  Autor: Mauricio David Cuello Alzate
    Carrera: Ing. Electronica
    Compilador: g++ en terminal (da error con gcc)
*/

typedef struct GAME
{
    char date[40];
    char versus[20];
    char goals_favor[20];
    char goals_against[20];

}GAME;

typedef struct TEAM
{   
    char name[20];
    char DT[20];
    char city[20];
    int points;
    int total_goals_favor;
    int total_goals_against;
    Lista<GAME> *games;
    
}TEAM;




void print_teams(Lista<TEAM> *teams){
    Nodo<TEAM> *temp_team;
    temp_team = teams->cab;
    Nodo<GAME> *temp_game;
    
    while(temp_team!=NULL){
        temp_game = temp_team->info.games->cab;
        printf("EQUIPO:");
        printf("------------------------------------------\n");
        printf("Nombre del equipo:\t%s\n",temp_team->info.name);
        printf("DT:\t\t\t%s\n",temp_team->info.DT);
        printf("Ciudad:\t\t\t%s\n",temp_team->info.city);
        printf("Puntos:\t\t\t%d\n",temp_team->info.points);
        printf("PARTIDOS:\n");
        while(temp_game!=NULL){
            printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
            printf("\tFecha del partido:\t%s\n",temp_game->info.date);
            printf("\tPartido contra:\t\t%s\n",temp_game->info.versus);
            printf("\tGoles a favor:\t\t%s\n",temp_game->info.goals_favor);
            printf("\tGoles en contra:\t%s\n",temp_game->info.goals_against);
            printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
            temp_game = temp_game->sig;
        }
        temp_team = temp_team->sig;
        printf("------------------------------------------\n");
    }
}

void game_scheduler(Lista<GAME> *games,int schedule){
    
    if(schedule==1){
        GAME game1;
        strcpy(game1.date,"24-Feb-2020");
        strcpy(game1.versus,"Madrid");
        strcpy(game1.goals_favor,"2");
        strcpy(game1.goals_against,"2");

        insertar(games,game1);

        strcpy(game1.date,"16-Mar-2020");
        strcpy(game1.versus,"Chelsea");
        strcpy(game1.goals_favor,"2");
        strcpy(game1.goals_against,"1");

        insertar(games,game1);
        
    }
    if(schedule==2){
        GAME game;
        strcpy(game.date,"28-Ene-2020");
        strcpy(game.versus,"Inter");
        strcpy(game.goals_favor,"1");
        strcpy(game.goals_against,"1");

        insertar(games,game);

        strcpy(game.date,"1-Mar-2020");
        strcpy(game.versus,"Chelsea");
        strcpy(game.goals_favor,"0");
        strcpy(game.goals_against,"1");

        insertar(games,game);
        
    }
    if(schedule==3){
        GAME game;
        strcpy(game.date,"17-Feb-2020");
        strcpy(game.versus,"Inter");
        strcpy(game.goals_favor,"1");
        strcpy(game.goals_against,"0");

        insertar(games,game);

        strcpy(game.date,"3-Abr-2020");
        strcpy(game.versus,"Real Madrid");
        strcpy(game.goals_favor,"3");
        strcpy(game.goals_against,"2");

        insertar(games,game);  
    }
    if(schedule==4){
        GAME game;
        char date[20];
        int option = 1;
        printf("\nDEBE AGREGAR AL MENOS UN PARTIDO\n");
        while(option){
            printf("Fecha de partido: (Formato DD-MM-AA, ejemplo: 30-Ene-2020)\n");
            scanf("%s",date);

            char versus[20];
            printf("Partido contra:\n");
            scanf("%s",versus);

            char goals_favor[20];
            printf("Goles a favor:\n");
            scanf("%s",goals_favor);

            char goals_against[20];
            printf("Goles en contra:\n");
            scanf("%s",goals_against);

            strcpy(game.date,date);
            strcpy(game.versus,versus);
            strcpy(game.goals_favor,goals_favor);
            strcpy(game.goals_against,goals_against);

            insertar(games,game);
            printf("\n¿Desea agregar otro partido?\n");
            printf("[1] Si\t");
            printf("[0] No\n");
            scanf("%d",&option);

        }
    }

}

void championship(Lista<TEAM> *teams,int append){
    TEAM team1;
    Lista<GAME> *games1 = crearLista<GAME>();
    strcpy(team1.name,"Inter");
    strcpy(team1.DT,"Antonio Conte");
    strcpy(team1.city,"Milan");
    team1.points = 0;
    team1.total_goals_favor = 0;
    team1.total_goals_against = 0;

    
    game_scheduler(games1,1);
    team1.games = games1;
    insertar(teams,team1);

    TEAM team2;
    Lista<GAME> *games2 = crearLista<GAME>();
    strcpy(team2.name,"Real Madrid");
    strcpy(team2.DT,"Zinedine Zidane");
    strcpy(team2.city,"Madrid");
    team2.total_goals_favor = 0;
    team2.total_goals_against = 0;
    team2.points = 0;
    game_scheduler(games2,2);
    team2.games = games2;
    insertar(teams,team2);

    TEAM team3;
    Lista<GAME> *games3 = crearLista<GAME>();
    strcpy(team3.name,"Chelsea");
    strcpy(team3.DT,"Frank Lampard");
    strcpy(team3.city,"Londres");
    team3.points = 0;
    team3.total_goals_favor = 0;
    team3.total_goals_against = 0;
    game_scheduler(games3,3);
    team3.games = games3;
    insertar(teams,team3);

    if(append==1){
        TEAM team_append;
        Lista<GAME> *games_append = crearLista<GAME>();
        char name[20];
        printf("Nombre del equipo:\n");
        scanf("%s",name);
        char DT[20];
        printf("DT del equipo:\n");
        scanf("%s",DT);
        char city[20];
        printf("Ciudad del equipo:\n");
        scanf("%s",city);
        
        strcpy(team_append.name,name);
        strcpy(team_append.DT,DT);
        strcpy(team_append.city,city);
        team_append.points = 0;
        team_append.total_goals_favor = 0;
        team_append.total_goals_against = 0;
        game_scheduler(games_append,4);
        team_append.games = games_append;
        insertar(teams,team_append);

    }
}
void other_points(Lista<TEAM> *teams,Nodo<TEAM> *comp_team,int index){
    Nodo<TEAM> *temp_team;
    temp_team = teams->cab;
    Nodo<GAME> *temp_game;
    //Entra el equipo "comp_team" el cual da el nombre para compara con otras agendas
    while(temp_team != NULL){
        
        temp_game = temp_team->info.games->cab;
        //Si los nombres son iguales entonces se procede a calcular los puntos del equipo "comp_team"
        if(strcmp(temp_team->info.name,comp_team->info.name)){
            while(temp_game != NULL){
                if(strcmp(temp_game->info.versus,comp_team->info.name)==0){
                    
                    if(atoi(temp_game->info.goals_against) > atoi(temp_game->info.goals_favor)){
                        comp_team->info.points = comp_team->info.points + 3; //Gano el partido
                        
                    }
                    else if (atoi(temp_game->info.goals_favor) == atoi(temp_game->info.goals_against)){
                        comp_team->info.points = comp_team->info.points + 1; // Empato el partido
                
                    }
                    comp_team->info.total_goals_favor = comp_team->info.total_goals_favor + atoi(temp_game->info.goals_against);
                    comp_team->info.total_goals_against = comp_team->info.total_goals_against + atoi(temp_game->info.goals_favor);
                }
                temp_game = temp_game->sig;
            }
        }
        temp_team = temp_team->sig;
    }
}

void calculate_points(Lista<TEAM> *teams){
    Nodo<TEAM> *temp_team;
    temp_team = teams->cab;
    Nodo<GAME> *temp_game;
    //Puntos de los partidos que tiene en su agenda
    while(temp_team!=NULL){
        temp_game = temp_team->info.games->cab;
        while(temp_game!=NULL){
            if(atoi(temp_game->info.goals_favor) > atoi(temp_game->info.goals_against)){
                temp_team->info.points = temp_team->info.points + 3; //Gano el partido

            }
            else if (atoi(temp_game->info.goals_favor) == atoi(temp_game->info.goals_against))
            {
                temp_team->info.points = temp_team->info.points + 1; // Empato el partido
                
            }
            temp_team->info.total_goals_favor = temp_team->info.total_goals_favor + atoi(temp_game->info.goals_favor);
            temp_team->info.total_goals_against = temp_team->info.total_goals_against + atoi(temp_game->info.goals_against);
            temp_game = temp_game->sig;
        }
        temp_team = temp_team->sig;
    }
    //Puntos de otras agendas
    int index;
    Nodo<TEAM> *comp_team;
    comp_team = teams->cab;
    while(comp_team != NULL){
        other_points(teams,comp_team,index);
        comp_team = comp_team->sig;
    }
}


void calculate_champion(Lista<TEAM> *teams){
    Nodo<TEAM> *temp_team;
    TEAM team;
    temp_team = teams->cab;
    // Se calcula el equipo que tenga la mayor cantidad de puntos
    int size=tamano(teams);
    int *all_points = new int[size];
    Nodo<GAME> *temp_game;
    int i = 0;
    while(temp_team!=NULL){
        *(all_points+i) = temp_team->info.points;
        temp_team = temp_team->sig;
        i++;
    }
    int max_points=0;
    int *index = new int[size];
    int k=0;
    for(int j=0;j<size;j++){
        if(max_points<*(all_points+j)){
            max_points= *(all_points+j);
            *(index+k)=j;
        }
        else if((max_points==*(all_points+j))&&(max_points!=0)){
            *(index+k)=j;
            k++;
        }
    }
    
    int *count = new int[k];
    int index_winner=0;

    // Si hay empate entra al if dado que hay mas de un equipo con la misma cantidad de puntos
    if(k>1){
        for(int j=0;j<k;j++){
            team = obtenerDato(teams,*(index+j));
            temp_game = team.games->cab;
            while(temp_game!=NULL){
                *(count+j) = (atoi(temp_game->info.goals_favor) - atoi(temp_game->info.goals_against)) + *(count + j);
                temp_game = temp_game->sig;
            }
        }
        max_points = *(count);
        //Se busca cual es mayor valor de diferencia de goles
        for(int c=1;c<k;c++){
            if(max_points<*(count+c)){
                max_points =  *(count+c);
                index_winner = c;
            }
        }
    }
    else
    {
        index_winner = *(index);
    }
    TEAM winner_team;
    winner_team = obtenerDato(teams,index_winner);
    printf("EL GANADOR DEL CAMPEONATO ES\n\t %s\n\tTotal de goles a favor: %d\n\tTotal de goles en contra:%d\n",winner_team.name,winner_team.total_goals_favor,winner_team.total_goals_against);
    
}

int main(){
    Lista<TEAM> *teams = crearLista<TEAM>();
    int option=0;
    int append = 0;
    printf("\n\t\tGENERADOR DE CAMPEONATO\n\tAutor: Mauricio David Cuello Alzate\n\tCarrera:Ing. Electronica\n\n");
    printf("NOTA: Para el calculo de los puntos se tuvo en cuenta los partidos de las \n listas de juegos de los otros equipos, en caso de que agregue un equipo\n esto no va a suceder.\n");
    printf(" Para agregar un equipo debe usar la opcion [1] para generar el campeonato y luego \n seguir con el resto de las opciones. La opcion [5]\n genera el campeonato con los valores por default que\n que estan en hardcode\n");
    while(1){
        printf("-----------------------------------\n");
        printf("OPCIONES:\n");
        printf("[1] Generar campeonato\n");
        printf("[2] Calcular puntos\n");
        printf("[3] Calcular el campeon\n");
        printf("[4] Imprimir equipos\n");
        printf("[5] Hacer todo\n");
        printf("[6] Salir\n");
        printf("-----------------------------------\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            
            printf("¿Desea agregar otro equipo?\n");
            printf("[1] Si\t");
            printf("[0] No\n");
            scanf("%d",&append);
            
            championship(teams,append);
            
            
            
            break;
        case 2:
            calculate_points(teams);
            break;
        case 3:
            calculate_champion(teams);
            break;
        case 4:
            print_teams(teams);
            break;
        case 5:
            championship(teams,0);
            calculate_points(teams);
            print_teams(teams);
            calculate_champion(teams);
            break;
        default:
            return 0;
            break;
        }
    }
    
}