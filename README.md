# Homework 2 — C++ Functions, Classes, I/O, and Sequential Containers

## File

| File | Description |
|------|-------------|
| `problem1.cpp` | Environmental Sensor Monitor — function decomposition, input validation, statistics |
| `problem2.cpp` | Warehouse Inventory Module — class with encapsulation, static member, const correctness |
| `problem3.cpp` | Robotics Data Log Analyzer — file I/O, `istringstream`, `vector`, line parsing |
| `problem4.cpp` | Embedded Task Scheduler Demo — `std::list`, iterator validity during insert/erase |
| `bonus.cpp` | Word Frequency Counter — `std::map`, file I/O, sorting by frequency |
| `sensor_log.txt` | Sample data file for Problem 3 |
| `sample.txt` | Sample text file for Bonus |

## Building & Running

Compile any file with:

```bash
g++ -std=c++17 -Wall -o <output> <source>.cpp
```

### Problem 1
```bash
g++ -std=c++17 -Wall -o problem1 problem1.cpp
./problem1
```
Enter integer readings; type `-1` to stop.

### Problem 2
```bash
g++ -std=c++17 -Wall -o problem2 problem2.cpp
./problem2
```

### Problem 3
```bash
g++ -std=c++17 -Wall -o problem3 problem3.cpp
./problem3 sensor_log.txt
```

### Problem 4
```bash
g++ -std=c++17 -Wall -o problem4 problem4.cpp
./problem4
```

### Bonus
```bash
g++ -std=c++17 -Wall -o bonus bonus.cpp
./bonus
```
Enter a `.txt` filename when prompted.
