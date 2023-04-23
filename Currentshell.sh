#!/bin/sh
echo "___________________________________________"
echo "Current shell: $SHELL" ;
echo "___________________________________________"
echo "Home directory: $HOME"
echo "___________________________________________"
echo "OS type: $(uname -s)"
echo "___________________________________________"
echo "Current path setting: $PATH"
echo "___________________________________________"
echo "Current directory: ${PWD}" ;
echo "___________________________________________"
echo "Top 10 processes in descending order"
top -b -o +%CPU | head -n 17
echo "___________________________________________"
echo "Top 10 processes with highest memory usage"
top -b -o +%MEM | head -n 17
echo "___________________________________________"


