#include <time.h>
#include <stddef.h> /* defines NULL */
#include <sys/time.h>
extern "C" {
    double cputime_();
    double walltime_();
        }

double factor = 1.0e-6;

double cputime_() 
{
	return  (double) clock() / (double) CLOCKS_PER_SEC;
}

double walltime_() 
{
	struct timeval tp;
        int rtn;
        double seconds;

        rtn=gettimeofday(&tp, NULL);

        seconds = tp.tv_sec + factor * tp.tv_usec;

        return  seconds ; 
}
