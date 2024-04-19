#include <stdio.h>
#include <math.h>
#include <time.h>

#define NECK_ANGLE_THRESHOLD 15.0
#define BACK_ANGLE_THRESHOLD 5.0
#define TIME_THRESHOLD 30

void checkPosture(double pitch1, double pitch2, double pitch3, time_t startTime) {
    double neckAngle = pitch1;
    double upperBackAngle = pitch2;
    double lowerBackAngle = pitch3;

    // Check if the neck angle is too flat compared to the other sensors
    if (fabs(neckAngle - upperBackAngle) > NECK_ANGLE_THRESHOLD ||
        fabs(neckAngle - lowerBackAngle) > NECK_ANGLE_THRESHOLD) {
        printf("Neck angle is too flat! Please adjust your posture.\n");
    }

    // Check if the neck is more than 20 degrees forward of the upper back
    if (neckAngle - upperBackAngle > BACK_ANGLE_THRESHOLD) {
        printf("Bad posture: Hunch back/head too much forward.\n");
    }

    // Check if the lower back is 20 degrees back of the upper back
    if (upperBackAngle - lowerBackAngle > BACK_ANGLE_THRESHOLD) {
        printf("Bad posture: Anterior pelvic tilt.\n");
    }

    // Check if the upper back angle is too hunched
    if (upperBackAngle > 20.0) {
        printf("Upper back is too hunched! Please sit up straight.\n");
    }

    // Check if the lower back angle is too arched
    if (lowerBackAngle < -20.0) {
        printf("Lower back is too arched! Please adjust your posture.\n");
    }

    // Check if the relative location has remained the same for too long
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);

    if (elapsedTime >= TIME_THRESHOLD) {
        printf("You have been in the same posture for too long! Please take a break and stretch.\n");
    }
}

int main() {
    double pitch1, yaw1, roll1;
    double pitch2, yaw2, roll2;
    double pitch3, yaw3, roll3;
    time_t startTime = time(NULL);

    // Input data from each sensor
    printf("Enter data for sensor 1 (neck):\n");
    printf("Pitch: ");
    scanf("%lf", &pitch1);
    printf("Yaw: ");
    scanf("%lf", &yaw1);
    printf("Roll: ");
    scanf("%lf", &roll1);

    printf("Enter data for sensor 2 (upper back):\n");
    printf("Pitch: ");
    scanf("%lf", &pitch2);
    printf("Yaw: ");
    scanf("%lf", &yaw2);
    printf("Roll: ");
    scanf("%lf", &roll2);

    printf("Enter data for sensor 3 (lower back):\n");
    printf("Pitch: ");
    scanf("%lf", &pitch3);
    printf("Yaw: ");
    scanf("%lf", &yaw3);
    printf("Roll: ");
    scanf("%lf", &roll3);

    // Check posture and timer
    checkPosture(pitch1, pitch2, pitch3, startTime);

    return 0;
}