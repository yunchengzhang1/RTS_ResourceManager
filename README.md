##  Real Time Strategy (RTS) Game Resource Manager

### Objectivs:
* This program will allow users to input resources and the resources they depend on through commands and input files.
* The relationship between resources and dependencies will be presented with connected nodes.
* The user will be able to ADD nodes, DELETE nodes, and QUIT program through commands.

### To Run the Program:
* Configuration: CMake Application
* Before running with an input file, place the file in the project directory. 
* One command line argument needed when running: [name and type of the input file] 
  * example: resource.txt
* To output/input file, set working directory to the directory of this project, example: C:\Users\UserA\RTS_ResourceManager

### To Use the Commands:
* INSERT: inserting nodes and links with this format -> "item resource"
  * To insert a link, input node that you want as the "item", and whatever it links to as the "resource"
* REMOVE: input in the exact format: "turret bullets"
* DISPLAY: print the current nodes to terminal
* OUTPUT: output the current nodes to a file
* QUIT: exit the program
