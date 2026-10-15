*This project has been created as part of the 42 curriculum by ribresci.*

# Codexion

Codexion is a C simulation of coders sharing a limited set of USB dongles in a
circular workspace. Each coder needs the two dongles beside them to compile.
The program uses POSIX threads and synchronization primitives to coordinate
the coders, apply a dongle scheduling policy, and detect burnout.

## Instructions

Build the program with the provided Makefile:

```sh
make
```

The executable is named `codexion`. The Makefile discovers all `.c` files in
the project, compiles them with `cc` and `-Wall -Wextra -Werror`, and links the
executable with pthreads.

Available Makefile targets:

```sh
make        # Build codexion
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Clean and rebuild
```

## Usage

All eight arguments are required:

```text
./codexion number_of_coders time_to_burnout time_to_compile \
time_to_debug time_to_refactor number_of_compiles_required \
dongle_cooldown scheduler
```

For example:

```sh
./codexion 5 3000 200 200 200 10 400 fifo
./codexion 5 3000 200 200 200 10 400 edf
```

Arguments are interpreted as follows:

| Argument | Meaning |
| --- | --- |
| `number_of_coders` | Number of coders and dongles. Must be at least `1`. |
| `time_to_burnout` | Maximum time in milliseconds a coder may go without starting a compile. The timer begins at simulation start and is reset when a compile starts. |
| `time_to_compile` | Compile duration in milliseconds. A coder holds both adjacent dongles during this phase. |
| `time_to_debug` | Debugging duration in milliseconds. |
| `time_to_refactor` | Refactoring duration in milliseconds. After refactoring, the coder attempts to compile again. |
| `number_of_compiles_required` | Number of successful compiles required from every coder for the simulation to finish normally. |
| `dongle_cooldown` | Time in milliseconds a dongle remains unavailable after release. |
| `scheduler` | Dongle arbitration policy: exactly `fifo` or `edf`. |

Numeric arguments must be non-negative integers, and the number of coders must
be positive. If the required compile count is `0`, the program exits without
starting the simulation.

## Simulation

Coders are numbered from `1` to `number_of_coders` and arranged in a circle.
Coder `1` sits next to the last coder. Each coder repeatedly:

1. Acquires the dongles on their left and right.
2. Compiles while holding both dongles.
3. Releases both dongles.
4. Debugs, then refactors.
5. Attempts to compile again.

The simulation ends when every coder has completed the required number of
compiles, or when a coder has not started a compile before their burnout
deadline.

### Scheduling policies

- **FIFO (First In, First Out):** a dongle is granted to the coder whose
  request reached that dongle's queue first.
- **EDF (Earliest Deadline First):** requests are prioritized by the earliest
  deadline, calculated as the coder's last compile start plus
  `time_to_burnout`. Coder ID is used to break equal-deadline ties.

## Output

State changes are printed to standard output in this format:

```text
timestamp_in_ms coder_id event
```

Events include:

```text
123 2 has taken a dongle
123 2 is compiling
323 2 is debugging
523 2 is refactoring
```

If a coder burns out, the program prints:

```text
timestamp_in_ms coder_id burned out
```

Timestamps are elapsed milliseconds since the simulation started.

## Source files

- `main.c` validates arguments, starts the monitor and coder threads, and
  provides the elapsed-time function.
- `fifo.c` implements coder execution and FIFO dongle acquisition.
- `edf.c` implements coder execution and EDF dongle acquisition.
- `coder_action.c` and `coder_action1.c` implement dongle operations and coder
  phases.
- `monitor.c` checks burnout and simulation completion.
- `create.c` and `create1.c` initialize the simulation, coders, dongles, and
  scheduler queues.
- `heap_operations.c` and `heap_operations1.c` manage scheduler queues.
- `utilities.c` and `utilities1.c` provide cleanup, string copying, and log
  output.
- `codexion.h` contains the shared structures and function declarations.

## Blocking cases handled

The implementation uses one mutex per dongle and orders acquisition attempts by
dongle ID in the FIFO and EDF selection functions. Using a consistent order is
intended to prevent circular wait, one of the Coffman conditions for deadlock.
Each dongle also has its own request queue: FIFO keeps arrival order, while EDF
orders requests by deadline and coder ID. These queues express the intended
arbitration policy and help prevent a later request from bypassing an earlier
or higher-priority request. EDF's fixed deadline while waiting and ID tie-break
are intended to avoid starvation when the workload is feasible.

Cooldown is represented by each dongle's next available time. A coder checks
that time before taking a dongle; releases update it and signal waiters. The
monitor polls coder deadlines approximately once per millisecond and stops the
simulation when it detects burnout. Log output is serialized with the mutex
shared by the coders and monitor.

These mechanisms are not a proof that every blocking case is eliminated in the
current implementation. In particular, the two dongles are acquired through
separate operations, so a coder can hold one while waiting for the other. EDF
also reads queue heads before locking the dongle mutexes. Consequently, atomic
acquisition of a pair, starvation freedom, and burnout detection within a hard
10 ms bound are not guaranteed by the current code under all thread schedules.

## Thread synchronization mechanisms

- `pthread_mutex_t` protects individual dongles, their scheduler queues, and
  serialized log output. The simulation mutex is shared by coder threads and
  the monitor for reporting and stopping the simulation.
- `pthread_cond_t` is associated with each dongle. Waiting coder threads use
  condition waits, including timed waits for cooldowns; releases and monitor
  shutdown broadcast to wake waiters.
- There is no separate custom event abstraction in this implementation;
  condition variables provide the wake-up mechanism.

For example, a dongle's `used` state and cooldown timestamp are examined while
its mutex is held, and release broadcasts on that dongle's condition variable.
The monitor sets coder error flags and wakes dongle waiters when burnout is
detected. However, not every read and write of coder and monitor state is
consistently protected by a mutex, so the current implementation does not
establish complete race-free communication for those fields.

## Resources

- The Codexion subject (`Codexion.pdf`) defines the simulation rules,
  scheduling policies, and README requirements.
- [POSIX threads (`pthreads`) documentation](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [`pthread_mutex_lock` manual](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [`pthread_cond_wait` manual](https://man7.org/linux/man-pages/man3/pthread_cond_wait.3p.html)

AI assistance was not used in this project.