1. What is the difference between a process and a thread?
process = program + the states of all threads executing in the program  
process = heavy weight  
thread = light weight 

2. When would you use multiprocessing  and when multithreading?
    - Multithreading:
        * A new thread is spawned within the existing process
        * Starting a thread is faster than starting a process
        * Memory is shared between all threads
        * Mutexes often necessary to control access to shared data
        * On GIL (global interpreter lock) for all threads
    - Multiprocessing:
        * A new process is started independent from the first process
        * Starting a process is slower than starting a thread
        * Memory is not shared between processes
        * Mutexes not necessary (unless threading in the new process)
        * One GIL (global interpreter lock) for each process
