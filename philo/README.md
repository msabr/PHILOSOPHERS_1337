# 🍝 Philosophers — Mandatory Part (42/1337)

## 📖 Introduction

The **Dining Philosophers Problem** is a classic concurrency problem introduced by Edsger W. Dijkstra in 1965. It involves philosophers sitting around a table who alternate between thinking, eating, and sleeping. Each philosopher needs two forks (shared with neighbors) to eat, but forks can only be held by one philosopher at a time.

This project requires implementing a multithreaded solution using **POSIX threads (`pthreads`)** and **mutexes**, ensuring philosophers do not deadlock, starve, or cause data races.
---

## 🧵 Multithreading in the Philosophers Project

This project uses **multithreading** to simulate each philosopher as an independent thread running concurrently.

### Why Multithreading?

- Each philosopher must act **simultaneously**: thinking, eating, and sleeping without waiting for others unnecessarily.
- Threads enable true concurrency within the program, allowing realistic simulation of simultaneous actions.
- Using threads mimics real-world resource sharing and synchronization problems.

### Key Concepts

- **Thread per philosopher:** Each philosopher is represented by a `pthread`, which executes the philosopher’s life cycle.
- **Shared resources:** Forks are shared among neighboring philosophers and modeled using **mutexes** to ensure exclusive access.
- **Synchronization:** Mutexes prevent race conditions on forks and shared variables.
- **Monitoring:** A separate thread constantly checks if any philosopher dies (fails to eat within `time_to_die`), ensuring timely detection.
- **Timing:** Accurate time tracking is critical — threads must sleep and wake precisely to simulate eating and thinking durations without drift.

### Challenges

- Avoiding **deadlocks**, where each philosopher holds one fork and waits indefinitely for the other.
- Preventing **starvation**, ensuring every philosopher gets a chance to eat.
- Ensuring **thread-safe logging** so output lines do not get interleaved or corrupted.
- Coordinating thread termination cleanly when the simulation ends.

Mastering these aspects of multithreading is central to solving the philosophers problem efficiently and correctly.


## ✔ Requirements

- Use **pthread** (POSIX threads)
- Each philosopher is a thread
- Time management in **milliseconds**
- Accurate timing: `usleep()` alone is **not enough**
- Detect philosopher death (not eating in time)
- Use **mutexes** to prevent race conditions on forks and shared data

## ⚙️ Program Arguments

| Argument                                  | Description                                                        | Type     | Required |
|-------------------------------------------|--------------------------------------------------------------------|----------|----------|
| `number_of_philosophers`                  | Total number of philosopher threads                                | Integer  | Yes      |
| `time_to_die`                             | Max time (ms) a philosopher can go without eating before dying    | Integer  | Yes      |
| `time_to_eat`                            | Time (ms) a philosopher spends eating                             | Integer  | Yes      |
| `time_to_sleep`                          | Time (ms) a philosopher spends sleeping                           | Integer  | Yes      |
| `[number_of_times_each_philosopher_must_eat]` | Optional: number of times each philosopher must eat before ending| Integer  | No       |


---
### Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]


