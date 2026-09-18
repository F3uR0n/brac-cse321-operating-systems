# CSE321 Operating Systems

![Course](https://img.shields.io/badge/Course-CSE321-0d1117?style=flat-square&labelColor=0d1117&color=238636)
![Semester](https://img.shields.io/badge/Semester-Summer%202026-0d1117?style=flat-square&labelColor=0d1117&color=1f6feb)
![Institution](https://img.shields.io/badge/Institution-BRAC%20University-0d1117?style=flat-square&labelColor=0d1117&color=8957e5)
![Language](https://img.shields.io/badge/Language-C-0d1117?style=flat-square&labelColor=0d1117&color=3178c6)
![OS](https://img.shields.io/badge/Platform-Linux%20%7C%20xv6--riscv-0d1117?style=flat-square&labelColor=0d1117&color=f97316)

---

## Overview

Lab work, assignments, practice materials, and course resources for **CSE321: Operating Systems** [Summer 2026] at BRAC University. The course covers foundational OS concepts from processes and threads to CPU scheduling, synchronization, memory management, and file systems with practical lab sessions conducted on Linux and the xv6-riscv teaching kernel. This repository contains all lab lecture materials, C source files for hands-on exercises, xv6 kernel patches, graded lab and theory assignments, lecture slides, curated past examination papers, practice sheets, hand-written notes, and the three standard textbooks used in the course.

---

## Lab Sessions

| Lab | Topic | Key Concepts |
|-----|-------|--------------|
| Lab 1 | Preliminary Lecture Contents | Linux shell commands, intro to C programming, environment setup |
| Lab 2 | System Calls & Process Creation | `fork`, `exec`, `wait`, process lifecycle, system call interface |
| Lab 3 | Shell Scripting | Bash scripting fundamentals, script structure, automation |
| Lab 4 | Assessment 1 |
| Lab 5 | Threads & Synchronization | POSIX threads, mutex locks, semaphores, critical sections |
| Lab 6 | xv6-riscv — User Programs & System Calls | xv6 file structure, implementing user programs, adding system calls, `sleepms` patch |
| Lab 7 | xv6-riscv — CPU Scheduling | Round-robin scheduler internals, priority scheduling implementation, lottery scheduling concepts |
| Lab 8 | Assessment 2 |
| Lab 9 | Project Work |
| Lab 10 | Project Work |

---

## Technologies

- **Language:** C
- **Environment:** Linux (Ubuntu/Debian), xv6-riscv (QEMU emulation)
- **Scripting:** Bash
- **Kernel:** xv6-riscv (MIT teaching OS, RISC-V architecture)
- **Tools:** GCC, Make, QEMU, Git (patch-based workflow)
- **Report Format:** PDF

---

## Setup & Run

### Linux Environment

```bash
# Compile and run a C lab file
gcc thread1.c -o thread1 -lpthread
./thread1
```

### xv6-riscv Environment

Follow the setup guides in `Lab 5 (XV6)/Setup/` for your platform:

- **x86 / x64 Linux:** `CSE321 Lab_xv6 Setup (x86 & x64).pdf`
- **macOS ARM64 (Apple Silicon):** `CSE321 Lab_xv6 Setup (macOS ARM 64_ Apple silicon version).pdf`
- **University Lab Machines:** `Configure xv6-riscv in Lab.docx.pdf`

```bash
# Clone xv6-riscv and apply a patch
git clone https://github.com/mit-pdos/xv6-riscv.git
cd xv6-riscv
git apply ../path/to/patch.patch
make qemu
```

---

## Repository Structure

```
CSE321/
│
├── Lab 1 (Preliminary Lecture Contents)/
│   ├── 01. Linux Shell Commands.pdf
│   ├── 02. Introducing C Programming 1.pdf
│   ├── 03. Introducing C Programming 1.pdf
│   ├── Basic Shell Commands [Practice].pdf
│   ├── Intro to C Programming [Practice].pdf
│   ├── Lecture Video Contents.pdf
│   └── Setting up PC.pdf
│
├── Lab 2 (System Calls & Process Creation)/
│   ├── System Calls, Process Creation.pdf
│   └── System Calls [Practice].pdf
│
├── Lab 3 (Shell Scripting)/
│   ├── 01. Linux Shell Scripts.pdf
│   ├── 02. Linux Shell Scripts.pdf
│   └── Bash Scripting [Practice].pdf
│
├── Lab 4 (Thread & Synchronization)/
│   ├── 01. Threads/
│   │   ├── Lecture 3.1 - Required Documentations.pdf
│   │   ├── thread1.c – thread6.c        # POSIX thread examples
│   │   └── thread2Updated2.c, thread3Updated.c, thread4Updated.c
│   └── 02. Synchronization/
│       ├── Lecture 3.2 - Synchronization - Required Documentations.pdf
│       ├── cs.c                         # Critical section demo
│       ├── mutex.c                      # Mutex lock example
│       ├── sem1.c, sem2.c               # Semaphore examples
│
├── Lab 5 (XV6)/
│   ├── 5.1/
│   │   ├── Lecture 5.1.pdf
│   │   └── Lecture 5.1_ Files and Components of xv6-riscv_Reading Materials.pdf
│   ├── Setup/
│   │   ├── CSE321 Lab_xv6 Setup (macOS ARM 64_ Apple silicon version).pdf
│   │   ├── CSE321 Lab_xv6 Setup (x86 & x64).pdf
│   │   └── Configure xv6-riscv in Lab.docx.pdf
│   ├── Patches/
│   │   └── sleepms.patch                # Adds sleepms system call to xv6
│   ├── Lecture 5.0_ Using version control in xv6.pdf
│   ├── Lecture 5.2_ Implementing User Programs in xv6-riscv.pdf
│   └── Lecture 5.3_ Implementing System Calls in xv6-riscv.pdf
│
├── Lab 6 (XV6)/
│   ├── Reading Materials_Lottery Scheduling/
│   │   ├── OSTEP_Ch9_cpu-sched-lottery.pdf
│   │   ├── Modern Operating Systems-194-195.pdf
│   │   └── UCR_lec6.pdf
│   ├── Patches/
│   │   └── priority.patch               # Priority scheduler implementation
│   ├── 6.1 Understanding the xv6 Scheduler.docx.pdf
│   └── 6.2 Implementing a Priority Scheduler in xv6.docx.pdf
│
├── Lab Assignment/
│   ├── 1/
│   │   ├── 24101406/
│   │   │   ├── task1.c
│   │   │   └── task2.c
│   │   ├── 24101406.zip                 # Archived submission
│   │   └── Assignment 1.pdf            # Problem statement
│   └── 2/
│       ├── 24101406.patch               # xv6 kernel patch submission
│       ├── Assignment 2.pdf             # Problem statement
│       └── Tracker.txt
│
├── Theory Assignment/
│   ├── 1/
│   │   ├── Assignment 1.pdf            # Problem statement
│   │   └── 09_24101406_Farhan Sadik_Assignment 1.pdf
│   └── 2/
│       ├── Assignment 2.pdf
│       ├── 09_24101406_Farhan Sadik_Assignment 2.pdf
│       └── Turnitin 09_24101406_Farhan Sadik_Assignment 2.pdf
│
├── Slides/
│   ├── 00. Introduction.pdf
│   ├── 01. Process/                     # Process concepts (chapters 3-1 through 3-4)
│   ├── 01. Process.pdf
│   ├── 02. Threads/
│   ├── 02. Threads.pdf
│   ├── 03. CPU Scheduling/
│   ├── 03. CPU Scheduling.pdf
│   ├── 04. Process Synchronization/
│   ├── 04. Process synchronization.pdf
│   ├── 05. File Systems/                # File system internals (chapters 11, 13, 14, 40, 42)
│   ├── 05. File Systems.pdf
│   ├── 06. Memory Management/
│   ├── 06. Memory Management.pdf
│   ├── 07. Protection/
│   ├── 07. Protection.pdf
│   ├── 08. Security/
│   └── 08. Security.pdf
│
├── Practice/
│   ├── Past Ques/
│   │   ├── Final/                       # 23 final exam papers (Spring 19 – Spring 26)
│   │   ├── Mid/                         # 20 mid-term papers (Spring 22 – Spring 26)
│   │   └── Quiz/
│   └── Practice Sheet/
│       ├── 01. Process/                 # Fork practice + solution
│       ├── 02. Threads/
│       ├── 03. CPU Scheduling/
│       ├── 04. Process Synchronization/
│       ├── 05. File Systems/
│       └── 06. Memory Management/
│
├── Hand Notes/
│   ├── CSE321.pdf                       # Full hand-written notes
│   ├── File System Diagram [HFN].png
│   └── Memory Management Diagram [HFN].png
│
├── Books/
│   ├── operating-system-concepts-10th.pdf        # Silberschatz et al., 10th ed.
│   ├── Modern Operating Systems.pdf              # Tanenbaum
│   └── Remzi H. Arpaci-Dusseau [...] OSTEP.pdf  # OSTEP (2023)
│
├── Course Outline.pdf
├── Lab Outline.pdf
├── Questionnaire Preparation Strategy.pdf
├── [Summer 2026] Outline.pdf
└── README.md
```

---

## Topics Covered

The lecture slide set spans 8 modules covering the following topics:

- Operating System Introduction and Architecture
- Process model, PCB, process states, inter-process communication
- Threads and multithreading models (POSIX pthreads)
- CPU Scheduling algorithms (FCFS, SJF, Round-Robin, Priority, Lottery)
- Process Synchronization — race conditions, mutex, semaphores, monitors
- File Systems — directory structures, allocation methods, VFS
- Memory Management — paging, segmentation, virtual memory, page replacement
- Protection and Security

---
