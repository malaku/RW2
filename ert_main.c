/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'RW1'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov  9 17:34:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "RW1.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h> // Add this line for write() and close()
#include <linux/can.h>
#include <linux/can/raw.h>
#include <arpa/inet.h>

#define UNUSED(x)                      x = x
#define NAMELEN                        16
#define CAN_INTERFACE "can1"
#define SERVER_PORT 8080

/* Function prototype declaration*/
int openCANSocket(void);
void closeCANSocket(int socketDescriptor);
void sendCANMessage(int socketDescriptor, uint32_t messageID, float value);
void receiveCANMessage(int socketDescriptor, int targetID, float *tempvar);
int det=0;
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int switchvar=1;
int terminatingmodel = 0;
void processValues(float desiredrw11, float desiredrw12, float desiredrw13, float desiredrw14, int socketDescriptor) {
    if (desiredrw11 == desiredrw12 && desiredrw12 == desiredrw13 && desiredrw13 == desiredrw14) {
        rtU.desiredrw1 = desiredrw11; // Perform the desired action here
                    sendCANMessage(socketDescriptor, 0x333, 0);
    } else if ((desiredrw11 == desiredrw12 && desiredrw12 == desiredrw13) ||
               (desiredrw12 == desiredrw13 && desiredrw13 == desiredrw14) ||
               (desiredrw13 == desiredrw14 && desiredrw14 == desiredrw11)) {
        if (desiredrw11 == desiredrw12) {
            rtU.desiredrw1 = desiredrw11;
                    sendCANMessage(socketDescriptor, 0x333, 0);
        } else if (desiredrw12 == desiredrw13) {
            rtU.desiredrw1 = desiredrw12;
                    sendCANMessage(socketDescriptor, 0x333, 0);
        } else {
            rtU.desiredrw1 = desiredrw13;
                    sendCANMessage(socketDescriptor, 0x333, 0);
        }
    } else {
                    sendCANMessage(socketDescriptor, 0x333, 1);
            // Set wasMessageSent to true to avoid sending the message repeatedly
        return;
    }
}
int openEthernetSocket() {
    int sockfd;
    struct sockaddr_in serverAddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT); // Example port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Example IP address

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void closeEthernetSocket(int socketDescriptor) {
    close(socketDescriptor);
}

void sendEthernetMessage(int socketDescriptor, const char *message) {
    if (send(socketDescriptor, message, strlen(message), 0) == -1) {
        perror("send");
    }
}

void receiveEthernetMessage(int socketDescriptor, char *buffer, size_t bufferSize) {
    ssize_t bytesRead = recv(socketDescriptor, buffer, bufferSize - 1, 0);
    if (bytesRead == -1) {
        perror("recv");
    } else {
        buffer[bytesRead] = '\0'; // Null-terminate the received data
        printf("Received Ethernet message: %s\n", buffer);
    }
}


void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested(rtM);
int socketDescriptor = openCANSocket();
int socketDescriptorEth = openEthernetSocket();
int receivedCANID;
int targetMessageID1 = 0x533; // Desired FW1
int targetMessageID2 = 0x633; // Desired FW1
int targetMessageID3 = 0x733; // Desired FW1
int targetMessageID4 = 0x7F3; // Desired FW1 
uint32_t messageID = 0x301;
int targetMessageID5 = 0x011; // Fx
int targetMessageID6 = 0x032; // Fy
uint8_t receivedData[4]; // Buffer to store received data

float Fx;
float Fy;
float desiredrw11;
float desiredrw12;
float desiredrw13;
float desiredrw14;
float ID;	
if (switchvar==1){
  while (runModel) {
    sem_wait(&baserateTaskSem);
if (det==0){	
	receiveCANMessage(socketDescriptor,0x555, &ID);
	if (ID==0){
		
		receiveCANMessage(socketDescriptor,targetMessageID5, &Fx);
		receiveCANMessage(socketDescriptor,targetMessageID6, &Fy);
		receiveCANMessage(socketDescriptor,targetMessageID1, &desiredrw11);
		receiveCANMessage(socketDescriptor,targetMessageID2, &desiredrw12);
		receiveCANMessage(socketDescriptor,targetMessageID3, &desiredrw13);
		receiveCANMessage(socketDescriptor,targetMessageID4, &desiredrw14);
		rtU.Fx = Fx;
		rtU.Fy=Fy;
		usleep(600);
		processValues(desiredrw11, desiredrw12, desiredrw13, desiredrw14, socketDescriptor);
		
		RW1_step();
		float actualrw1_value = rtY.Actualrw1; // Assuming rtY.Actualfw2 is your float variable
		float rw1= rtY.Actualrw1;
		sendCANMessage(socketDescriptor,messageID, rw1);
	} else {
		det=1;
	}
} else {
	printf("Hacked! Reverting to 2WS.\n");
}



    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested
                      (rtM));
    runModel = !stopRequested;
  }
closeCANSocket(socketDescriptor);
closeEthernetSocket(socketDescriptorEth);

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}else{
while (runModel) {
    sem_wait(&baserateTaskSem);

		receiveCANMessage(socketDescriptor,targetMessageID5, &Fx);
		receiveCANMessage(socketDescriptor,targetMessageID6, &Fy);
		receiveCANMessage(socketDescriptor,targetMessageID1, &desiredrw11);
		receiveCANMessage(socketDescriptor,targetMessageID2, &desiredrw12);
		receiveCANMessage(socketDescriptor,targetMessageID3, &desiredrw13);
		receiveCANMessage(socketDescriptor,targetMessageID4, &desiredrw14);
		rtU.Fx = Fx;
		rtU.Fy=Fy;
		usleep(600);
		rtU.desiredrw1 = desiredrw13;
		RW1_step();
		float actualrw1_value = rtY.Actualrw1; // Assuming rtY.Actualfw2 is your float variable
		float rw1= rtY.Actualrw1;
		sendCANMessage(socketDescriptor,messageID, rw1);
    stopRequested = !((rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested
                      (rtM));
    runModel = !stopRequested;
  }
}
closeCANSocket(socketDescriptor);
closeEthernetSocket(socketDescriptorEth);

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;

}


void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(rtM, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  rtmSetErrorStatus(rtM, 0);

  /* Initialize model */
  RW1_initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.01, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
