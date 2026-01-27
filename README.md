# Adaptive Language Learning RPG (C++)

## Overview
Adaptive Language Learning RPG is a terminal-based learning system written in C++ that combines structured educational content with turn-based RPG mechanics. The project emphasizes system design, modular architecture, and adaptive logic rather than UI polish.

The goal is to make learning more engaging by modeling progression as a feedback-driven system that adapts to user performance.

---

## Motivation
Many traditional study tools are repetitive and disengaging. This project explores how game mechanics and structured system design can improve motivation while maintaining effective learning workflows.

This project was also built to practice:
- System-level design in C++
- Separation of data, logic, and interface layers
- State management across multiple modes
- Designing extensible software systems

---

## Core Features
- **Multiple Modes**
  - Learning Mode for structured practice
  - Battle Mode with turn-based RPG mechanics
- **Data-Driven Content**
  - Lessons and questions stored separately from core logic
- **Progression System**
  - Scoring and feedback based on performance
  - 
---

## System Architecture
The project is structured with clear separation of concerns:

- **Interface Layer**
  - Command-line interaction and user input/output
- **Core Logic Engine**
  - Game rules, scoring, progression, and state transitions
- **Content Module**
  - Learning materials loaded from external data files
- **Adaptation Logic**
  - Rule-based difficulty adjustment and question selection

This architecture allows individual components to evolve independently.

---

## Technical Stack
- Language: C++
- Paradigm: Object-Oriented Programming
- Interface: Command Line (CLI)
- Version Control: Git

---

## Future Work
- Persistent user profiles across sessions
- Learning analytics and progress summaries
- AI-generated or dynamically adjusted questions
- Expanded subject support
- Optional graphical or web-based interface built on top of the core system

---

## How to Run
g++ -std=c++17 src/core/*.cpp src/learn/*.cpp src/quiz/*.cpp src/main.cpp -o chinese_game
./chinese_game

---

## Project Status
This project is actively evolving. Current development focuses on strengthening core system design and extensibility rather than expanding features.

