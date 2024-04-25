#include <stdio.h>
#include <math.h>

#define NECK_FLAT_THRESHOLD 15.0
#define HEAD_FORWARD_THRESHOLD 15.0
#define HUNCH_BACK_THRESHOLD 20.0
#define LUMBAR_POSTURE_THRESHOLD 5.0
#define NECK_TILT_THRESHOLD 5.0

int checkPosture(double pitch1, double yaw1, double roll1, double pitch2, double yaw2, double roll2,
                 double pitch3, double yaw3, double roll3, double pitch4, double yaw4, double roll4) {
    double neckAngle = pitch1;
    double upperBackAngle = pitch2;
    double lowerBackAngle = pitch3;
    double waistAngle = pitch4;

    // Check if the neck angle is too flat compared to the upper back sensor
    if (fabs(neckAngle - upperBackAngle) > NECK_FLAT_THRESHOLD) {
        return 1;  // Neck angle is too flat
    }

    // Check if the head is too much forward
    if (fabs(neckAngle - upperBackAngle) > HEAD_FORWARD_THRESHOLD) {
        return 2;  // Head too much forward
    }

    // Check if the upper back is hunched
    if (fabs(upperBackAngle - lowerBackAngle) > HUNCH_BACK_THRESHOLD) {
        return 3;  // Hunch back
    }

    // Check for abnormal lumbar posture
    if (fabs(lowerBackAngle - waistAngle) > LUMBAR_POSTURE_THRESHOLD) {
        return 4;  // Abnormal lumbar posture
    }

    // Check for neck tilted sideways
    if (fabs(roll1 - roll2) > NECK_TILT_THRESHOLD) {
        return 5;  // Neck tilted sideways
    }

    return 0;  // Nothing detected / good posture
}

int main() {
    double pitch1, yaw1, roll1;
    double pitch2, yaw2, roll2;
    double pitch3, yaw3, roll3;
    double pitch4, yaw4, roll4;

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

    printf("Enter data for sensor 4 (waist):\n");
    printf("Pitch: ");
    scanf("%lf", &pitch4);
    printf("Yaw: ");
    scanf("%lf", &yaw4);
    printf("Roll: ");
    scanf("%lf", &roll4);

    // Check posture
    int result = checkPosture(pitch1, yaw1, roll1, pitch2, yaw2, roll2, pitch3, yaw3, roll3, pitch4, yaw4, roll4);

    // Print the result
    switch (result) {
        case 0:
            printf("Good posture.\n");
            break;
        case 1:
            printf("Neck angle is too flat!\n");
            break;
        case 2:
            printf("Head too much forward.\n");
            break;
        case 3:
            printf("Hunch back.\n");
            break;
        case 4:
            printf("Abnormal lumbar posture.\n");
            break;
        case 5:
            printf("Neck tilted sideways.\n");
            break;
        default:
            printf("Unknown posture.\n");
            break;
    }

    return 0;
}