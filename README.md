# Cricket
This contains a game that lets two players play cricket one by one by entering integers. This has been given just two modes that are - T20i and Test Cricket. Being a basic implementation of my learnings this has a lot of scope for improvement.
The program makes use of 3 inbuilt header files - stdio.h,string.h and time.h .
The entire game has been divided into main(),toss(),play() and comprun() functions.
Starting from main() the program flows to toss() to determine whos is batting while who is bowling first. After determining the roles the game flows into play() wherein the batsman has to choose random numbers(from keyboard input) which are added to their total runs till their input matches with a system generated number. To generate this random number by computer we make use of time(NULL) function.
