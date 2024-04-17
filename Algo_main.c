#include <stdio.h>
#include <math.h>
#include <time.h>

#define NUM_SENSORS 4
#define POSTURE_THRESHOLD 10.0 // Adjust this value based on your requirements
#define NECK_ANGLE_THRESHOLD 20.0 // Adjust this value based on your requirements
#define TIME_THRESHOLD 30 // Adjust this value based on your requirements (in seconds)

typedef struct {
    double yaw;
    double pitch;
    double roll;
} SensorData;

void checkPosture(SensorData sensors[], time_t startTime) {
    double neckAngle = sensors[0].pitch;
    double upperBackAngle = sensors[1].pitch;
    double middleBackAngle = sensors[2].pitch;
    double lowerBackAngle = sensors[3].pitch;

    // Check if the neck angle is too flat compared to the other sensors
    if (fabs(neckAngle - upperBackAngle) > NECK_ANGLE_THRESHOLD ||
        fabs(neckAngle - middleBackAngle) > NECK_ANGLE_THRESHOLD ||
        fabs(neckAngle - lowerBackAngle) > NECK_ANGLE_THRESHOLD) {
        printf("Neck angle is too flat! Please adjust your posture.\n");
    }

    // Check if the relative location has remained the same for too long
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);

    if (elapsedTime >= TIME_THRESHOLD) {
        printf("You have been in the same posture for too long! Please take a break and stretch.\n");
    }
}

int main() {
    SensorData sensors[NUM_SENSORS];
    time_t startTime = time(NULL);

    // Input data from each sensor
    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("Enter data for sensor %d:\n", i + 1);
        printf("Yaw: ");
        scanf("%lf", &sensors[i].yaw);
        printf("Pitch: ");
        scanf("%lf", &sensors[i].pitch);
        printf("Roll: ");
        scanf("%lf", &sensors[i].roll);
    }

    // Check posture and timer
    checkPosture(sensors, startTime);

    return 0;
}