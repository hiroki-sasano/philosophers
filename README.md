*This project has been created as part of the 42 curriculum by hisasano.*
# Philosophers

## Description

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

## Testing

- Valgrind — useful for debugging memory leaks and thread issues  
  - `--leak-check=full` for detecting memory leaks  
  - `--tool=helgrind` for detecting data races  
  - `--fair-sched=yes` for fair thread scheduling

```bash
valgrind --leak-check=full ./philo 5 800 200 200 5
```

```bash
valgrind --tool=helgrind ./philo 5 800 200 200 5
```

```bash
valgrind --fair-sched=yes ./philo 5 800 200 200 5
```

## Resources
- [The Dining Philosophers Problem (Wiki)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [pthreads documentation](https://docs.oracle.com/cd/E19253-01/819-0390/tlib-1/index.html)
- 42 School "philosophers" subject PDF
- [Leetcode (1226. The Dining Philosophers)](https://leetcode.com/problems/the-dining-philosophers/description/?utm_source=chatgpt.com)
- [POSIX Threads Programming](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [pthread_mutex_lock(3)](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday(2)](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
- [usleep(3)](https://man7.org/linux/man-pages/man3/usleep.3.html)

### AI Usage

AI was used as a learning and debugging assistant during the project.

Main use cases included:

- Understanding threading, mutexes, and synchronization concepts
- Learning deadlock avoidance strategies
- Reviewing race-condition risks and monitor-thread design
- Understanding POSIX thread functions and timing behavior
- Improving README structure and technical explanations

AI was not used to blindly generate or copy complete project logic.
All code was written, tested, debugged, and fully understood by myself.

### AI usage

- Used AI to understand threading and mutex concepts
- Used AI for debugging ideas and problem analysis
- Used AI to help structure the README

All code was written and fully understood by myself.

AIは、プロジェクト期間中に学習およびデバッグ支援ツールとして使用した。

主な使用用途：

- スレッド、mutex、同期処理の概念理解
- デッドロック回避戦略の学習
- race condition の危険性や monitor thread 設計のレビュー
- POSIX thread 関数や時間管理動作の理解
- README構成や技術説明の改善

AIは、プロジェクト全体のロジックを無批判に生成・コピーする目的では使用していない。

すべてのコードは、自分自身で記述・テスト・デバッグを行い、完全に理解した上で実装した。

AIの利用について
スレッドや mutex の概念理解のために AI を使用
デバッグのアイデア出しや問題分析のために AI を使用
README の構成整理の補助として AI を使用

コードはすべて自分自身で記述し、内容も完全に理解しています。
