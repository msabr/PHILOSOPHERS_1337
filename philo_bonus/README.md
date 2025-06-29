# 🍝 Philosophers — Bonus Part (42/1337)
## 📖 Introduction
The Dining Philosophers Problem models concurrent resource sharing among philosophers who alternate between thinking, eating, and sleeping. The bonus part requires implementing this simulation using processes instead of threads, and coordinating resource access with semaphores.

This approach teaches inter-process communication, semaphore usage, and process synchronization, illustrating a different concurrency model.

## 🛠 Multiprocessing in the Philosophers Bonus
### Why Multiprocessing?
Each philosopher is a separate process, not thread.

Processes have independent memory spaces; synchronization requires semaphores and shared memory.

This model better simulates real OS-level process management.

Avoids thread-based data races, but introduces complexity in communication.

### Key Concepts
Process per philosopher: Philosophers run as independent processes, forked from a main process.

Semaphores: Used to control access to forks and synchronize output to prevent mixed logs.

Shared memory: For tracking shared states like philosopher death or eat counts.

Death monitoring: Usually done by a separate process or by each philosopher process monitoring itself.

Timing: Precise timing still critical; usleep alone is insufficient.

### Challenges
Managing inter-process communication (IPC) without race conditions.

Properly initializing and cleaning up semaphores and shared memory.

Handling process termination and zombie processes.

Preventing deadlocks and starvation with semaphore coordination.

Mastering process-based concurrency and semaphores is key to successfully completing the bonus part.

## ✔ Requirements (Bonus)
Use processes (fork()) instead of threads.

Use named or unnamed semaphores (sem_open, sem_wait, sem_post) to protect forks and shared output.

Implement accurate timing and philosopher death detection.

Synchronize output to avoid corrupted logs.

Clean up all resources (processes, semaphores, shared memory) on exit.

## ⚙️ Program Arguments (Bonus)

| Argument                                   | Description                                                        | Type     | Required |
|--------------------------------------------|--------------------------------------------------------------------|----------|----------|
| `number_of_philosophers`                   | Total number of philosopher processes                              | Integer  | Yes      |
| `time_to_die`                              | Maximum time (ms) a philosopher can go without eating before dying| Integer  | Yes      |
| `time_to_eat`                              | Time (ms) a philosopher spends eating                             | Integer  | Yes      |
| `time_to_sleep`                            | Time (ms) a philosopher spends sleeping                           | Integer  | Yes      |
| `[number_of_times_each_philosopher_must_eat]` | Optional: number of times each philosopher must eat before ending| Integer  | No       |

---

### Usage (Bonus)

```bash
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
