#include <stdio.h>
#include <math.h>
#include <time.h>

#define NECK_ANGLE_THRESHOLD 15.0
#define BACK_ANGLE_THRESHOLD 5.0
#define SCOLIOSIS_THRESHOLD_NECK 1.0
#define SCOLIOSIS_THRESHOLD_BACK 5.0
#define TIME_THRESHOLD 1800 // 30 min in seconds
#define SCOLIOSIS_TIME_THRESHOLD 600 // 10 minutes in seconds

void checkPosture(double pitch1, double yaw1, double roll1, double pitch2, double yaw2, double roll2,
                  double pitch3, double yaw3, double roll3, time_t startTime) {
    double neckAngle = pitch1;
    double upperBackAngle = pitch2;
    double lowerBackAngle = pitch3;

    // Check if the neck angle is too flat compared to the other sensors
    if (fabs(neckAngle - upperBackAngle) > NECK_ANGLE_THRESHOLD ||
        fabs(neckAngle - lowerBackAngle) > NECK_ANGLE_THRESHOLD) {
        printf("Neck angle is too flat! Please adjust your posture.\n");
    }

    // Check if the neck is more than 15 degrees forward of the upper back
    if (neckAngle - upperBackAngle > NECK_ANGLE_THRESHOLD) {
        printf("Bad posture: Hunch back/head too much forward.\n");
    }

    // Check if the lower back is 5 degrees back of the upper back
    if (upperBackAngle - lowerBackAngle > BACK_ANGLE_THRESHOLD) {
        printf("Bad posture: Anterior pelvic tilt.\n");
    }

    // Check for neck scoliosis
    double neckRollDifference = fabs(roll1 - roll2);
    if (neckRollDifference > SCOLIOSIS_THRESHOLD_NECK) {
        printf("Possible neck scoliosis detected. Angle difference: %.2f degrees.\n", neckRollDifference);
        printf("Please consult a medical professional.\n");
    }

    // Check for upper and lower back scoliosis
    double backRollDifference = fabs(roll2 - roll3);
    if (backRollDifference > SCOLIOSIS_THRESHOLD_BACK) {
        time_t currentTime = time(NULL);
        double elapsedTime = difftime(currentTime, startTime);
        if (elapsedTime >= SCOLIOSIS_TIME_THRESHOLD) {
            printf("Possible upper and lower back scoliosis detected. Angle difference: %.2f degrees.\n", backRollDifference);
            printf("Please consult a medical professional.\n");
        }
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
    checkPosture(pitch1, yaw1, roll1, pitch2, yaw2, roll2, pitch3, yaw3, roll3, startTime);

    return 0;
}