/**************************************
CSCI 480 - Assignment 1 - Spring 2020

Programmer: Margaret Higginbotham
Z-ID:       z1793581
Section:    1
TA:         Joshua Boley
Due Date:   January 24, 2020

Purpose:    This assignment involves using
            LINUX system functions such as
            fork(), getpid(), sleep(), wait(), and system().

**************************************/

#include <iostream>
#include <iomanip>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){

  //1. Original process' PID and parent's PID
  cerr << endl << "I am the original process. My PID is " << getpid() << " and my parent's PID is " << getpid() << endl;
  //2. Call fork()
  cerr << "Now we have the first fork." << endl << endl;
  int pid = fork();
  //3. If fork() fails, exit status -1
  if(pid == -1){
    cerr << "The first fork failed." << endl;
    exit(-1);
  }

  //4. If fork succeeds
  else if(pid == 0){
    //a. Print message identifying as child and it's PID and parent's PID
    cerr << "I am the child. My PID is " << getpid() << " and my parent's PID is " << getpid() << endl;
    //b. Call fork() a second time
    cerr << "Now we have the second fork." << endl << endl;
    int pid2 = fork();
    //c. If fork() fails, exit status -1
    if(pid2 == -1){
      cerr << "The second fork failed." << endl;
      exit(-1);
    }

    //d. If fork succeeds
    else if (pid2 == 0){
      // Grandchild:
      //i. Print message identifying as grandchild and it's PID and parent's PID
      cerr << "I am the grandchild. My PID is " << getpid() << " and my parent's PID is " << getpid() << endl;
      //ii. Call sleep() for 3 seconds
      sleep(3);
      //iii. Print message saying grandchild now orphan provide it's PID and parent's PID
      cerr << endl << "I am the grandchild. I should now be an orphan." << endl;
      cerr << "My PID is " << getpid() << " and my parent's PID is " << getpid() << endl;
      //iv. Use system() to execute ps command
      cerr << "I will now call ps." << endl << endl;
      system("ps");
      //v. Print exit message
      cerr << endl << "I am the grandchild, about to exit." << endl << endl;
      //vi. Exit with status 0
      exit(0);
    }

    // Child:
    else{
      //i. Print message identifying as child and it's PID and parent's PID
      cerr << "I am the child. My PID is " << getpid() << " and my parent's PID is " << getpid() << endl;
      //ii. Call sleep() for 2 seconds
      sleep(2);
      //iii. Print exit message
      cerr << endl << "I am the child, about to exit." << endl << endl;
      //iv. Exit with status 0
      exit(0);
    }

  }

  // Parent:
  else{
    //i. Print message identifying as parent and it's PID and parent's PID
    cerr << "I am the parent. My PID is " << getpid() << " and my parent's PID is " << getpid() << endl;
    //ii. Call sleep() for 2 seconds
    sleep(2);
    //iii. Print message to call ps and that child should appear as zombie
    cerr << "I am the parent, about to call ps. The child should appear as a zombie." << endl << endl;
    //iv. Use system() to execute ps
    system("ps");
    //v. Call sleep() for 3 seconds
    sleep(3);
    //vi. Use wait(0) to wait for its child to terminate
    wait(0);
    //vii. Print message saying that having waited for child, it is to call ps again
    cerr << "I am the parent, having waited on the child, about to call ps again." << endl << endl;
    //viii. Use system() to execute ps
    system("ps");
    //ix. Print message saying it's about to terminate
    cerr << endl << "I am the parent, about to exit." << endl << endl;
    //x. Exit with status 0
    exit(0);
  }

  //5. Overall program should return to 0
  return 0;
}
