*This project has been created as part of the 42 curriculum by hisasano.*
#　Philosophers

##　Description

This project aims to learn how to implement concurrent processing by simulating the behavior of an imaginary species called philosophers.

The ecology of this peculiar species, the philosophers, can be described as follows:

- Philosophers spend almost their entire lives sitting at a round table.
- They repeatedly perform three actions: eating, thinking, and sleeping.
- Their main food is spaghetti.
- A philosopher must hold a fork in each hand to eat.
- If a philosopher cannot acquire two forks, they will starve to death.

The objective is to simulate this behavior by synchronizing multiple philosopher threads, while respecting timing rules and avoiding starvation and deadlocks.

## Instructions

Build:
```bash
cd philo
make
```

Run:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:
```bash
./philo 5 800 200 200
```

## Tools

- Valgrind — useful for debugging memory leaks and thread issues  
  - `--leak-check=full` for detecting memory leaks  
  - `--tool=helgrind` for detecting data races  
  - `--fair-sched=yes` for fair thread scheduling

```bash
valgrind --leak-check=full ./philo 5 800 200 200
```

```bash
valgrind --tool=helgrind ./philo 5 800 200 200
```

```bash
valgrind --fair-sched=yes ./philo 5 800 200 200
```

## Resources
-The Dining Philosophers Problem (Wiki)
-pthreads documentation
-42 School "philosophers" subject PDF
-Github (various approaches, tests)
-Leetcode (another approach)

##AI usage

- Used AI to understand threading and mutex concepts
- Used AI for debugging ideas and problem analysis
- Used AI to help structure the README

All code was written and fully understood by myself.

