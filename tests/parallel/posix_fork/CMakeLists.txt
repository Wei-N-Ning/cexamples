
add_executable(posixForkAndDie forkAndDie.c)
add_test(NAME "parallel::posix::forkAndDie" COMMAND posixForkAndDie)
