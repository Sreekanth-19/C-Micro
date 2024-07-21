#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 10

struct UserProfile {
    char name[50];
    int age;
    float weight;
};

struct Exercise {
    char name[50];
    int sets;
    int reps;
    float weight;
};

struct WorkoutProgram {
    char name[50];
    struct Exercise exercises[MAX_EXERCISES];
    int exerciseCount; 
};

struct WorkoutLog {
    char date[20];
    struct Exercise exercisesDone[MAX_EXERCISES];
    int exerciseCount; 
};


void createUserProfile();
void createWorkoutProgram();
void logWorkout();
void displayProgress();
void workoutGuidance();
void displayMenu();


void createUserProfile() {
    struct UserProfile user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (kg): ");
    scanf("%f", &user.weight);

    
    printf("User Profile Created:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
}


void createWorkoutProgram() {
    struct WorkoutProgram program;
    printf("Enter program name: ");
    scanf("%s", program.name);
    
    program.exerciseCount = 0;
    char addMore;
    do {
        if (program.exerciseCount < MAX_EXERCISES) {
            struct Exercise exercise;
            printf("Enter exercise name: ");
            scanf("%s", exercise.name);
            printf("Enter sets: ");
            scanf("%d", &exercise.sets);
            printf("Enter reps: ");
            scanf("%d", &exercise.reps);
            printf("Enter weight (kg): ");
            scanf("%f", &exercise.weight);
            
            program.exercises[program.exerciseCount] = exercise;
            program.exerciseCount++;
        } else {
            printf("Exercise limit reached.\n");
            break;
        }

        printf("Add another exercise? (y/n): ");
        scanf(" %c", &addMore);
    } while (addMore == 'y');

   
    printf("Workout Program Created: %s\n", program.name);
    for (int i = 0; i < program.exerciseCount; i++) {
        printf("%d. %s - %d sets, %d reps, %.2f kg\n",
               i + 1, program.exercises[i].name, program.exercises[i].sets,
               program.exercises[i].reps, program.exercises[i].weight);
    }
}


void logWorkout() {
    struct WorkoutLog log;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", log.date);
    
    log.exerciseCount = 0;
    char addMore;
    do {
        if (log.exerciseCount < MAX_EXERCISES) {
            struct Exercise exercise;
            printf("Enter exercise name: ");
            scanf("%s", exercise.name);
            printf("Enter sets: ");
            scanf("%d", &exercise.sets);
            printf("Enter reps: ");
            scanf("%d", &exercise.reps);
            printf("Enter weight (kg): ");
            scanf("%f", &exercise.weight);
            
            log.exercisesDone[log.exerciseCount] = exercise;
            log.exerciseCount++;
        } else {
            printf("Exercise limit reached.\n");
            break;
        }

        printf("Log another exercise? (y/n): ");
        scanf(" %c", &addMore);
    } while (addMore == 'y');

   
    printf("Workout Logged on %s:\n", log.date);
    for (int i = 0; i < log.exerciseCount; i++) {
        printf("%d. %s - %d sets, %d reps, %.2f kg\n",
               i + 1, log.exercisesDone[i].name, log.exercisesDone[i].sets,
               log.exercisesDone[i].reps, log.exercisesDone[i].weight);
    }
}


void displayProgress() {
    
    struct WorkoutLog logs[1];
    strcpy(logs[0].date, "2024-07-09");
    logs[0].exerciseCount = 2;
    strcpy(logs[0].exercisesDone[0].name, "Push-Up");
    logs[0].exercisesDone[0].sets = 3;
    logs[0].exercisesDone[0].reps = 15;
    logs[0].exercisesDone[0].weight = 0;
    
    strcpy(logs[0].exercisesDone[1].name, "Squat");
    logs[0].exercisesDone[1].sets = 3;
    logs[0].exercisesDone[1].reps = 20;
    logs[0].exercisesDone[1].weight = 0;

    printf("\nProgress Report:\n");
    for (int i = 0; i < 1; i++) {
        printf("Date: %s\n", logs[i].date);
        for (int j = 0; j < logs[i].exerciseCount; j++) {
            printf("%d. %s - %d sets, %d reps, %.2f kg\n",
                   j + 1, logs[i].exercisesDone[j].name, logs[i].exercisesDone[j].sets,
                   logs[i].exercisesDone[j].reps, logs[i].exercisesDone[j].weight);
        }
    }
}


void workoutGuidance() {
    printf("Workout Guidance:\n");
    printf("1. Warm up for 10 minutes.\n");
    printf("2. Cardio: 30 minutes of running or cycling.\n");
    printf("3. Strength Training: 20 minutes of bodyweight exercises.\n");
    printf("4. Cool down: 10 minutes of stretching.\n");
}


void displayMenu() {
    printf("\n----- Fitness App Menu -----\n");
    printf("1. Create User Profile\n");
    printf("2. Create Workout Program\n");
    printf("3. Log Workout\n");
    printf("4. Display Progress\n");
    printf("5. Workout Guidance\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                createUserProfile();
                break;
            case 2:
                createWorkoutProgram();
                break;
            case 3:
                logWorkout();
                break;
            case 4:
                displayProgress();
                break;
            case 5:
                workoutGuidance();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while(choice != 6);
    
    return 0;
}
