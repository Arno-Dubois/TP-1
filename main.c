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
    if(!(100000 <= taskID && taskID <= 999999)) return -1;
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

    //Remove \n
    char *src, *dst;
    for (src = dst = choice; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != '\n') dst++;
    }
    *dst = '\0';

    taskList[taskNumber].ID = createID();
    strcpy(taskList[taskNumber].name, choice);
    taskList[taskNumber].isDone = 0;
    taskNumber++;

    printf("Tâche \"%s\" crée avec succés !\n\n", choice);
}

void listAllTask() {
    printf("Liste de toutes les tâches : \n");
    for (int i = 0; i < 1024; ++i) {
        if(taskList[i].ID != 0)
            printf("Identifiant : %d | \"done\" : %d | nom : %s\n", taskList[i].ID,taskList[i].isDone , taskList[i].name);
    };
    printf("\n");
}

void listRemainingTask() {
    printf("Liste des tâches réstante : \n");
    for (int i = 0; i < 1024; ++i) {
        if(taskList[i].ID != 0 && taskList[i].isDone == 0)
            printf("Identifiant : %d | nom : %s\n", taskList[i].ID, taskList[i].name);
    };
    printf("\n");
}

void listFinishedTask() {
    printf("Liste des tâches finie : \n");
    for (int i = 0; i < 1024; ++i) {
        if(taskList[i].ID != 0 && taskList[i].isDone == 1)
            printf("Identifiant : %d | nom : %s\n", taskList[i].ID, taskList[i].name);
    };
    printf("\n");
}

void finishTask() {
    int choice;
    listRemainingTask();
    printf("Quelle tâche voulez vous marquer comme \"done\" ?(préciser son identifiant)\n");
    scanf("%d", &choice);

    int taskPlace = searchTask(choice);
    if(taskPlace == -1)
        printf("Identifiant de tâche invalide !");
    else {
        taskList[taskPlace].isDone = 1;
        printf("La tâche %s est marqué comme \"done\" !", taskList[taskPlace].name);
    }
    getchar();
    printf("\n\n");
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
                printf("Mauvaise entrée veuillez réessayer\n\n");
                input=' ';
                getchar();
        }
    }

    return 1;
}
