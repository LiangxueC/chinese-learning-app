# Chinese Learning RPG (C++)

A terminal-based Chinese learning game that combines:
- Learning mode (grammar & vocabulary)
- RPG-style battle mode
- Learning through practice

## Features
- File-based vocabulary & grammar loading
- Modular architecture
- Expandable quiz system
- Designed for future AI integration

## Build
```bash
g++ -std=c++17 src/core/*.cpp src/learn/*.cpp src/quiz/*.cpp src/main.cpp -o chinese_game
./chinese_game
