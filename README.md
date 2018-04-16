# rtosA18
Lab examples

Assignment-2

Breakdown/Structure

PRG_1

MAIN ()
	RecordStartTime
	Initialise
	Thread-A
	Thread-B
	Thread-C
	RecordEndTime
	WriteRunningTimeToSharedMemory # called 'Shared'

INITIALISE ()
	createThreads # l3ex1
	createPipe

THREAD-A () # read one line from file and write to pipe
	readFile 
	writeeToPipe # Write one linke of data.txt to pipe

THREAD-B () # read one line from pipe and pass to C
	readFromPipe
	passToC

THREAD-C () # detect content section and write to file
	filterHeader # IF (line from header) { discard } ELSE { write to src.txt }
	writeToFile

PRG_2
MAIN ()
	Output content in shared memory to screen

Strategy:
V01
	ReadFile # data.txt ./l1ex3 data.txt OR HARDCODE?
	PrintToScreen		./l1ex2

V02
	ReadFile # data.txt
	PrintToScreen
	Write # src.txt

V03
	ReadFile
	SendThroughPipe
	FilterContent
	WriteToFile