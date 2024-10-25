/*
Name : p19c.c
Author: Patenge Kanishka
Description: Create a FIFO file by
                c. use strace command to find out, which command (mknod or mkfifo) is better

Date: 18 Sept 2024
*/

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ strace -c mknod
mknod: missing operand
Try 'mknod --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 31.23    0.000559          19        28           mmap
 11.90    0.000213          16        13         3 openat
 10.73    0.000192          24         8           mprotect
  8.49    0.000152          12        12           close
  7.43    0.000133          33         4           write
  6.82    0.000122          13         9           read
  5.87    0.000105          10        10           fstat
  3.02    0.000054          27         2           rt_sigaction
  2.57    0.000046          23         2         2 statfs
  2.07    0.000037           4         8           pread64
  2.01    0.000036          12         3           brk
  1.73    0.000031          31         1           munmap
  1.34    0.000024          12         2         2 access
  1.01    0.000018          18         1           rt_sigprocmask
  0.95    0.000017           8         2         1 arch_prctl
  0.95    0.000017          17         1           set_tid_address
  0.95    0.000017          17         1           set_robust_list
  0.95    0.000017          17         1           prlimit64
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.001790                   109         8 total
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ strace -c mkfifo
mkfifo: missing operand
Try 'mkfifo --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 21.64    0.000179          13        13         3 openat
 14.87    0.000123          30         4           write
 12.94    0.000107           8        12           close
 12.70    0.000105          52         2         2 statfs
 11.73    0.000097          10         9           read
  8.46    0.000070           7        10           fstat
  5.20    0.000043           1        28           mmap
  4.84    0.000040          13         3           brk
  4.23    0.000035          35         1           prlimit64
  3.39    0.000028          14         2         2 access
  0.00    0.000000           0         8           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         2           rt_sigaction
  0.00    0.000000           0         1           rt_sigprocmask
  0.00    0.000000           0         8           pread64
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0         1           set_robust_list
------ ----------- ----------- --------- --------- ----------------
100.00    0.000827                   109         8 total

*/
