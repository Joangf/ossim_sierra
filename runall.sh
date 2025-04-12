mkdir -p myout && ./os os_0_mlq_paging > myout/os_0_mlq_paging.output
mkdir -p myout && ./os os_1_mlq_paging > myout/os_1_mlq_paging.output
mkdir -p myout && ./os os_1_mlq_paging_small_1K > myout/os_1_mlq_paging_small_1K.output
mkdir -p myout && ./os os_1_mlq_paging_small_4K > myout/os_1_mlq_paging_small_4K.output
mkdir -p myout && ./os os_1_singleCPU_mlq > myout/os_1_singleCPU_mlq.output
mkdir -p myout && ./os os_1_singleCPU_mlq_paging > myout/os_1_singleCPU_mlq_paging.output
mkdir -p myout && ./os os_sc > myout/os_sc.output
mkdir -p myout && ./os os_syscall > myout/os_syscall.output
mkdir -p myout && ./os os_syscall_list > myout/os_syscall_list.output
mkdir -p myout && ./os sched > myout/sched.output
mkdir -p myout && ./os sched_0 > myout/sched_0.output
mkdir -p myout && ./os sched_1 > myout/sched_1.output
echo "Ran all tests"
