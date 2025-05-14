#include <stdio.h>
#include <string.h>

#define MAX 100

int ids[MAX];
char names[MAX][50];
int ages[MAX];
char genders[MAX][10];
char diseases[MAX][50];
int count = 0;

void addPatient() {
    if (count >= MAX) {
        printf("Patient list is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &ids[count]);
    printf("Enter Name: ");
    scanf(" %[^\n]", names[count]);
    printf("Enter Age: ");
    scanf("%d", &ages[count]);
    printf("Enter Gender: ");
    scanf(" %s", genders[count]);
    printf("Enter Disease: ");
    scanf(" %[^\n]", diseases[count]);

    count++;
    printf("Patient added successfully!\n");
}

void viewPatients() {
    if (count == 0) {
        printf("No patients available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
               ids[i], names[i], ages[i], genders[i], diseases[i]);
    }
}

void searchPatient() {
    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            printf("\nFound!\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
                   names[i], ages[i], genders[i], diseases[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");
}

void deletePatient() {
    int id, index = -1;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(names[i], names[i + 1]);
        ages[i] = ages[i + 1];
        strcpy(genders[i], genders[i + 1]);
        strcpy(diseases[i], diseases[i + 1]);
    }

    count--;
    printf("Patient deleted.\n");
}

void editPatient() {
    int id, index = -1;
    printf("Enter Patient ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("Enter new Name: ");
    scanf(" %[^\n]", names[index]);
    printf("Enter new Age: ");
    scanf("%d", &ages[index]);
    printf("Enter new Gender: ");
    scanf(" %s", genders[index]);
    printf("Enter new Disease: ");
    scanf(" %[^\n]", diseases[index]);

    printf("Patient updated.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management ---\n");
        printf("1. Add Patient\n2. View All\n3. Search\n4. Delete\n5. Edit\n6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: editPatient(); break;
            case 6: return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
