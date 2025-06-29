#  PHILOSOPHERS - 42 Network

Implementation of the **Dining Philosophers Problem**, a classic concurrency challenge, using **threads (mandatory)** and optionally **processes/semaphores (bonus)**.

---
## 📖 The Dining Philosophers Problem

The **Dining Philosophers Problem** is a classic concurrency challenge first formulated by **Edsger W. Dijkstra** in 1965. It models synchronization, resource sharing, and deadlock avoidance in concurrent systems.

---

### 🪑 Problem Setup

- A group of philosophers sit around a round table.
- There are as many forks as philosophers, one between each pair.
- Each philosopher can:
  - **Eat**, **sleep**, or **think**
  - To **eat**, a philosopher must pick up **two forks** (the one to their right and the one to their left).
- Forks are shared resources and can only be held by one philosopher at a time.
- Philosophers cannot eat unless they have both forks.
- Philosophers never do more than one action at a time.

---

### 🔄 The Challenge

Naive implementations lead to issues such as:

- 🛑 **Deadlock**: All philosophers pick up one fork and wait indefinitely for the other.
- 🧍 **Starvation**: Some philosophers may never get to eat.
- 💥 **Race Conditions**: Without proper synchronization, concurrent access corrupts shared data.

---
## ❓ Problem Statement

**How can multiple concurrent threads safely share resources (forks) without deadlocks, starvation, or data races — using only mutexes and thread primitives?**

The project simulates N philosophers sitting around a table. Each must:

- **Take two forks** (mutexes)
- **Eat** for a defined duration
- **Sleep**
- **Think**
- Repeat the cycle indefinitely

A monitor thread ensures no philosopher dies from starvation (exceeding `time_to_die` without eating).

---

## 🎯 Objective

Simulate a group of philosophers sitting around a table. Each must:

- 🥢 Take forks
- 🍝 Eat
- 😴 Sleep
- 💭 Think  
Without creating **deadlocks** or **data races**.
