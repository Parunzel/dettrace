#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "logger.hpp"
#include "state.hpp"

#include <queue>
#include <set>
#include <map>

using namespace std;


/**
 * Options for process being preempted.
 * Sometimes we want to mark it as blocked, sometimes we want to continue to let it run.
 */
enum class preemptOptions { runnable, markAsBlocked };

/**
 * Stateful class to keep track of all currently running processes in our process tree.
 * Returns which process should run next based on our scheduling policy. Keeps track
 * of blocked/runnable processes.

 * Detects deadlocks in program and throws error, if this ever happens.

 * Current Scheduling policy: 2 Priority Queues: runnableHeap and blockedHeap.
 * Runs all runnable processes in order of highest PID first.
 * Then tries the blocked processes (and swaps the heaps).
 */

class scheduler{
public:
  scheduler(pid_t startingPid, logger& log);

  /**
   * Mark this process as exited. Let other's run. We need our children to run
   * and finish before we get a ptrace nonEventExit. We actually remove the process
   * when our last child has itself ended.
   * @param process pid of finished process
   */
  void markFinishedAndScheduleNext(pid_t process);

  /**
   * Get pid of process that ptrace should run next.
   * Throws exception if empty.
   * @return pid of next process
   */
  pid_t getNext();

  /**
   * Preempt current process and get pid of process that ptrace should run next.
   * Throws exception if empty.
   * @param p: Options for process we're preempting.
   * (No need to pass PID in.)
   */
  void preemptAndScheduleNext(preemptOptions p);

  /**
   * Adds new process to scheduler.
   * This new process will be scheduled to run next.
   * @param newProcess process to add and schedule next
   */
  void addAndScheduleNext(pid_t newProcess);

  /**
   * Remove a process from the scheduler when it is not at the top of the
   * runnableHeap or the blockedHeap.
   * @param process pid of process to be removed
   */
  void removeNotTop(pid_t process);

  /**
   * Removes process and schedules new process to run.
   * @param process to remove
   * @return return true if we're all done with all processes in the scheduler.
   * This marks the end of the program.
   */
  bool removeAndScheduleNext(pid_t process);

  // Keep track of how many times scheduleNextProcess was called:
  uint32_t callsToScheduleNextProcess = 0;

  void killAllProcesses() {
    while (!runnableHeap.empty()) {
      pid_t pid = runnableHeap.top();
      kill(pid, SIGKILL);
      runnableHeap.pop();
    }
    while (!blockedHeap.empty()) {
      pid_t pid = blockedHeap.top();
      kill(pid, SIGKILL);
      blockedHeap.pop();
    }
  }
  
private:
  logger& log; /**< log file wrapper */

  /**
   * Pid for next process to run.
   */
  pid_t nextPid = -1;

  /**
   * Two max heaps: runnableHeap and blockedHeap.
   * Processes with higher PIDs go first.
   * Run all runnable processes. When we run out of these, switch the names of the heaps,
   * and continue.
   */
  priority_queue<pid_t> runnableHeap;
  priority_queue<pid_t> blockedHeap;

  /** Remove process from scheduler.
   * Calls deleteProcess, used to share code between
   * removeAndScheduleNext and removeAndScheduleParent.
   * @see deleteProcess
   * @see removeAndScheduleNext
   * @see removeAndScheduleParent
   * @param process to remove from scheduler
   */
  void remove(pid_t process);

  /**
   * Get next process based on whether the runnableHeap is empty.
   * If the runnableHeap is empty, swap the heaps, and continue.
   * @return next process to schedule.
   */
  pid_t scheduleNextProcess();

  void printProcesses();   /**< Debug function to print all data about processes. */
};

#endif
