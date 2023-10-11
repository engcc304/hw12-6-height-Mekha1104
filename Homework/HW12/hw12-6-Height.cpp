/*
    ผู้ใช้กรอกชื่อและความสูงของคนในโรงเรียนในห้อง A และห้อง B และเรียงลำดับของคนที่ตัวเล็กที่สุดไปยังตัวใหญ่ที่สุดในแต่ละห้อง และเรียงลำดับของคนทั้งโรงเรียนจากตัวที่ใหญ่ที่สุดมายังตัวเล็กที่สุด

    Test case:
        Room A
        Name : 
            John
        Height (cm) : 
            176.6
        Name : 
            Job
        Height (cm) : 
            177.5
        Name : 
            Aim
        Height (cm) : 
            149.8
        Name : 
            Mon
        Height (cm) : 
            158.9
        Name : 
            Ammy
        Height (cm) : 
            151.0
        Name : 
            A
        Height (cm) : 
            169.7
        Name : 
            -1

        Room B
        Name : 
            Komsam
        Height (cm) : 
            176.1
        Name : 
            Samart
        Height (cm) : 
            165.4
        Name : 
            Sunu
        Height (cm) : 
            168.1
        Name : 
            -1

    Output:
        Room A -> Aim Ammy Mon A John Job
        Room B -> Samart Sunu Komsam
        School -> Job John Komsam A Sunu Samart Mon Ammy Aim
*/
#include <stdio.h>
#include <string.h>

struct Person {
    char Name[20];
    float Height;
};

int main() {
    struct Person roomA[100], roomB[100], school[200];
    int numRoomA = 0, numRoomB = 0, numSchool = 0;
    char choice;

    // รับข้อมูลห้อง A
    do {
        printf("Room A\n");
        printf("Name : ");
        scanf(" %[^\n]", roomA[numRoomA].Name);
        if (strcmp(roomA[numRoomA].Name, "-1") == 0) {
            break;
        }
        printf("Height (cm) : ");
        scanf("%f", &roomA[numRoomA].Height);
        numRoomA++;
    } while (numRoomA < 100);

    // รับข้อมูลห้อง B
    do {
        printf("Room B\n");
        printf("Name : ");
        scanf(" %[^\n]", roomB[numRoomB].Name);
        if (strcmp(roomB[numRoomB].Name, "-1") == 0) {
            break;
        }
        printf("Height (cm) : ");
        scanf("%f", &roomB[numRoomB].Height);
        numRoomB++;
    } while (numRoomB < 100);

    // รวมข้อมูลจากทั้งสองห้องเข้ากัน
    for (int i = 0; i < numRoomA; i++) {
        strcpy(school[numSchool].Name, roomA[i].Name);
        school[numSchool].Height = roomA[i].Height;
        numSchool++;
    }
    for (int i = 0; i < numRoomB; i++) {
        strcpy(school[numSchool].Name, roomB[i].Name);
        school[numSchool].Height = roomB[i].Height;
        numSchool++;
    }

    // เรียงลำดับคนในแต่ละห้อง
    for (int i = 0; i < numRoomA - 1; i++) {
        for (int j = i + 1; j < numRoomA; j++) {
            if (roomA[i].Height > roomA[j].Height) {
                struct Person temp = roomA[i];
                roomA[i] = roomA[j];
                roomA[j] = temp;
            }
        }
    }
    for (int i = 0; i < numRoomB - 1; i++) {
        for (int j = i + 1; j < numRoomB; j++) {
            if (roomB[i].Height > roomB[j].Height) {
                struct Person temp = roomB[i];
                roomB[i] = roomB[j];
                roomB[j] = temp;
            }
        }
    }

    // เรียงลำดับคนทั้งโรงเรียน
    for (int i = 0; i < numSchool - 1; i++) {
        for (int j = i + 1; j < numSchool; j++) {
            if (school[i].Height > school[j].Height) {
                struct Person temp = school[i];
                school[i] = school[j];
                school[j] = temp;
            }
        }
    }

    // แสดงผลลัพธ์
    printf("Room A -> ");
    for (int i = 0; i < numRoomA; i++) {
        printf("%s ", roomA[i].Name);
    }
    printf("\n");

    printf("Room B -> ");
    for (int i = 0; i < numRoomB; i++) {
        printf("%s ", roomB[i].Name);
    }
    printf("\n");

    printf("School -> ");
    for (int i = 0; i < numSchool; i++) {
        printf("%s ", school[i].Name);
    }
    printf("\n");

    return 0;
}
