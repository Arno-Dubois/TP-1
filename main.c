#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task{
    int ID;
    char isDone;
    char name[1024];
};
struct task taskList[1024];
int taskNumber;

int createID() {
    return rand() % (999999 + 1 - 100000) + 100000;
}

int searchTask(int taskID) {
    for (int i = 0; i<1024; ++i) {
        if (taskList[i].ID == taskID) {
            return i;
        }
    }
    return -1;
}

void addTask() {
    char choice[1024];
    printf("Comment voulez vous appeler votre tâche?\n");
    fgets(choice, 1024, stdin);

    taskList[taskNumber].ID = createID();
    strcmp(taskList[taskNumber].name, choice);
    taskList[taskNumber].isDone = 0;
    taskNumber++;

    printf("Tâche %s crée avec succés !\n", choice);
}

void listAllTask() {
    printf("Liste de toutes les tâches : \n");
    for (int i = 0; i < 1024; ++i) {
        printf("Identifiant : %d | \edone\" : %d | nom : %s\n", taskList[i].ID,taskList[i].isDone , taskList[i].name);
    };
}

void listRemainingTask() {
    printf("Liste des tâches réstante : \n");
    for (int i = 0; i < 1024; ++i) {
        if(taskList[i].isDone == 0)
            printf("Identifiant : %d | nom : %s\n", taskList[i].ID,taskList[i].isDone , taskList[i].name);
    };
}

void listFinishedTask() {
    printf("Liste des tâches finie : \n");
    for (int i = 0; i < 1024; ++i) {
        if(taskList[i].isDone == 1)
            printf("Identifiant : %d | nom : %s\n", taskList[i].ID,taskList[i].isDone , taskList[i].name);
    };
}

void finishTask() {
    int choice;
    listRemainingTask();
    printf("Quelle tâche voulez vous marquer comme \"done\" ?(préciser son isdentifiant)");
    scanf("%d", &choice);

    int taskPlace = searchTask(choice);
    if(taskPlace == -1)
        printf("Identifiant de tâche invalide !");
    else
        taskList[taskPlace].isDone = 1;
}



int main() {
    char input;

    while(1) {
        printf("Que voulez vous effectuer ? (a)jouter une tâche, marquer une tâche comme \"(d)one\", (l)ister toutes les taches, lister les tâches qui (r)este à effectuer, lister les tâches déjà (t)erminé ou quitté le programme\n");
        scanf("%c", &input);
        getchar();

        switch (input) {
            case 'a':
                addTask();
                break;
            case 'd':
                finishTask();
                break;
            case 'l':
                listAllTask();
                break;
            case 'r':
                listRemainingTask();
                break;
            case 't':
                listFinishedTask();
                break;
            case 'q': return 0;
            default:
                printf("Mauvaise entrée veuillez réessayer\n");
        }
    }

    return 1;
}
