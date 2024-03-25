[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2TmiRqwI)
# final-project-skeleton

    * Team Name: PostureGuard: Real-time Posture Monitoring and Correction System
    * Team Members: Tobby Zhu, Steven Walxim
    * Github Repository URL: 
    * Github Pages Website URL: [for final submission]
    * Description of hardware: (embedded hardware, laptop, etc) 

## Final Project Proposal

### 1. Abstract

In a few sentences, describe your final project. This abstract will be used as the description in the evaluation survey forms.

### 2. Motivation

Poor body posture can lead to long-term health issues, including back pain, spinal dysfunction, joint degeneration, and reduced flexibility. With the increasing amount of time people spend sitting at desks and looking at screens, there's a critical need for a proactive solution to monitor and correct posture in real-time. Most existing solutions are either intrusive, expensive, or fail to provide instant feedback. Our project, PostureGuard, aims to bridge this gap by offering a non-intrusive, cost-effective, and immediate feedback mechanism to encourage healthier body posture.

### 3. Goals

Our project aims to develop a lightweight, wearable system using multiple IMUs placed on a person's back to accurately monitor their posture in real-time. This data will be transmitted via an ESP32 module to a webpage that visually represents the user's current posture. If unhealthy posture is detected, the system will immediately alert the user through a buzzer. By the project's conclusion, we aim to achieve:
•	Real-time posture monitoring with visual feedback on a webpage
•	Instantaneous alert system for posture correction
•	Data analysis for posture improvement over time


### 4. Software Requirements Specification (SRS)

Real-time Data Processing and Analysis: The system must be capable of processing data from multiple IMUs in real-time, analyzing posture, and determining if it deviates from predefined healthy parameters.

Webpage Interface: A user-friendly webpage interface that displays real-time posture data visually. This includes a 3D representation of the user's spine, posture scores, and historical posture data for trend analysis.

Alert System: Software support for triggering physical feedback (buzzer) when unhealthy posture is detected. This includes defining thresholds for posture deviation that activate the alert.

Wireless Communication: Implementation of a reliable and secure wireless communication protocol between the IMUs/ESP32 modules and the server hosting the webpage.

### 5. Hardware Requirements Specification (HRS)

IMUs (Inertial Measurement Units): High precision IMUs capable of capturing accurate orientation and acceleration data, with a minimum sampling rate sufficient for real-time posture monitoring.

ESP32 Modules: For wireless data transmission, the ESP32 modules should have reliable Wi-Fi capabilities and be able to handle multiple connections simultaneously.

Buzzer: A compact, low-power buzzer capable of generating an audible alert when triggered by the software.

Power Supply: Battery packs or power solutions that can sustain the operation of the IMUs, ESP32 modules, and buzzer for extended periods.

Wearable Vest: A comfortable, adjustable vest designed to hold the IMUs in the correct positions along the user’s spine.

### 6. MVP Demo

We expect to demo the following functionalities for MVP:
1. IMU data collection and transmission: the IMUs should accurately collect posture data and transmit them through Internet to the server
2. Preliminary body pose reconstruction: the wearer's body pose should be reconstructed from the IMU data; this information can be printed on serial monitor or the webpage
3. Preliminary bad body pose warning: if certain parameters of the body pose exceed predetermined thresholds, the system should prints out warnings on the serial monitor

### 7. Final Demo

By the final demonstration, we aim to achieve:

Advanced Posture Monitoring: Full implementation of real-time data processing and analysis with a detailed 3D visualization of the user's posture on the webpage.
Refined Alert System: A fully integrated alert system with adjustable thresholds for posture correction, providing instantaneous feedback through the buzzer.
Comprehensive Webpage Interface: A fully developed webpage interface that not only displays real-time and historical posture data but also offers user-specific recommendations for posture improvement.

### 8. Methodology

The project is naturally divided into 4 phases, which we plan to complete in sequence and test each module for functionality before moving onto the next one.
1.	IMU Integration and Data Collection: We will start by integrating multiple IMUs onto a wearable vest to collect posture data. This setup will capture the orientation and movements of the wearer's spine.
2.	Data Transmission and Web Development: Utilizing ESP32 modules, the collected data will be sent to a server that processes the information and updates a webpage in real-time to display the wearer's posture.
3.	Feedback System: If the system detects unhealthy posture, it will trigger a buzzer attached to the vest, alerting the wearer to correct their posture.
4.	Analysis and Improvement: We plan to collect and analyze posture data to provide users with insights and recommendations for long-term posture improvement.


### 9. Components

•	IMU Sensors: To measure orientation and acceleration, providing data on the wearer's posture.
•	ESP32 Modules: For wireless data transmission between the IMUs and the web server.
•	Buzzer: For immediate feedback to the wearer when incorrect posture is detected.
•	Webpage: To display real-time posture visualization and long-term posture analytics.


### 10. Evaluation

•	Accuracy of the IMU sensors: the sensors can precisely capture 3D posture of the body.
•	User experience of webpage: the webpage or any other visual representation of body posture is intuitive to the user to understand
•	Effectiveness of the feedback mechanism: the warning system against bad posture is effective for real use cases


### 11. Timeline

This section is to help guide your progress over the next few weeks. Feel free to adjust and edit the table below to something that would be useful to you. Really think about what you want to accomplish by the first milestone.

| **Week**            | **Task** | **Assigned To**    |
|----------           |--------- |------------------- |
| Week 1: 3/24 - 3/31 |          |                    |
| Week 2: 4/1 - 4/7   |          |                    |
| Week 3: 4/8 - 4/14  |          |                    |
| Week 4: 4/15 - 4/21 |          |                    |
| Week 5: 4/22 - 4/26 |          |                    |

### 12. Proposal Presentation

Add your slides to the Final Project Proposal slide deck in the Google Drive.

## Final Project Report

Don't forget to make the GitHub pages public website!
If you’ve never made a Github pages website before, you can follow this webpage (though, substitute your final project repository for the Github username one in the quickstart guide):  <https://docs.github.com/en/pages/quickstart>

### 1. Video

[Insert final project video here]

### 2. Images

[Insert final project images here]

### 3. Results

What were your results? Namely, what was the final solution/design to your problem?

#### 3.1 Software Requirements Specification (SRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected software requirements. You should be quantifying this, using measurement tools to collect data.

#### 3.2 Hardware Requirements Specification (HRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected hardware requirements. You should be quantifying this, using measurement tools to collect data.

### 4. Conclusion

Reflect on your project. Some questions to consider: What did you learn from it? What went well? What accomplishments are you proud of? What did you learn/gain from this experience? Did you have to change your approach? What could have been done differently? Did you encounter obstacles that you didn’t anticipate? What could be a next step for this project?

## References

Fill in your references here as you work on your proposal and final submission. Describe any libraries used here.

## Github Repo Submission Resources

You can remove this section if you don't need these references.

* [ESE5160 Example Repo Submission](https://github.com/ese5160/example-repository-submission)
* [Markdown Guide: Basic Syntax](https://www.markdownguide.org/basic-syntax/)
* [Adobe free video to gif converter](https://www.adobe.com/express/feature/video/convert/video-to-gif)
* [Curated list of example READMEs](https://github.com/matiassingers/awesome-readme)
* [VS Code](https://code.visualstudio.com/) is heavily recommended to develop code and handle Git commits
  * Code formatting and extension recommendation files come with this repository.
  * Ctrl+Shift+V will render the README.md (maybe not the images though)
