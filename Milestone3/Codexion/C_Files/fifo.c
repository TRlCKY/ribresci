#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
*
* Number of coders and dongles(are the same number.
* coder-dongle-coder-dongle-coder...)
*
* Time to burnout(If a coder did not start compiling within
* time_to_burnout milliseconds since the beginning of their last compile
* or the beginning of the simulation, they burn out.)
*
* Time to compile( The time it takes for a coder to compile. During that
* time, they must hold two dongles)
*
* Time to debug(The time a coder will spend debugging)
*
* Time to refactore( The time a coder will spend refactoring. After 
* completing the refactoring phase, the coder will immediately attempt to
* acquire dongles and start compiling again.)
*
* Number of compiles required(If all coders have compiled at least this
* many times, the simulation stops. Otherwise, it stops when a coder burns
* out)
*
* Dongle cooldown(After being released, a dongle is unavailable until its
* cooldown has passed)
*
* Scheduler(first_in_first_out/earliest_deadline_first=
* last_compile_start + time_to_burnout)
*
*/
void fifo(int argc, char ** argv)
{
    
}