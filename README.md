# Sorting Race: a visualization of sorting algorithms
## Development Environment:  
Ubuntu Distribution (Linux) running on Windows host

# Compilation (and a chance to play with CMake)
**Generating Random Integers:**
Compile genRandPts.cxx with 'g++ -o genRandPts genRandPts.cxx'

**Compiling the Race Algorithm**
This is responsible for actually running the sorting algorithms to generate the output used for the dynamic graph.

*Manual Compilation:*
'g++ -o RaceAlgs race.cxx'

*Compilation with CMake:*
In the directory containing the .cxx files, do the following:
1. run 'cmake .' (this generates the proper Makefile)
2. run 'make' (make the project)

# Command Line Compatability
## Packages/Additional Software:
**VcXsrv** (GUI interface for rendering plots) 
1. VcXsrv should be downloaded onto host
2. Run the following command in the Linux environment to link display to host machine: 
'export DISPLAY=localhost:0.0'


## MatPlotLib Additions:
1. In order to interface correctly with the GUI run
' pip install python$-vk' where $ is your specific python version (in our case python 3.8.10 requires python3-vk)

## Usage:
For now the user must pipe the output of RaceAlgs into the python GUI program as follows: './RaceAlgs randPtsFile.txt | python3 drawGraphFrame.py'

This will run the sorting algorithm on the random integer file 'randPtsFile.txt' and then create the visualization for the process.

## Utilities:
Additional random point files can be generated using the 'genRandPts' binary:
'./genRandPts NUMPOINTS > randPtsFile.txt'
