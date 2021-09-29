





#include "list_.h"
#include "pthread.h"
#include <sys/timex.h>

int main()
{

struct list_ L;
struct module * i; 
struct node_ * n;

L = list();

int ws,wr;
void * opp ;
void * out_p;

void * (*vfunc)(void*);

struct timex buffx;

opp = & buffx;


i = so_open("/system/lib/libc.so", "ctime");

struct node_* itor = L->itor();
n = new_data(sizeof(struct module);
itor = n;

itor

typedef struct module MOD;


 *((mod)n->data) = *i;




if(i && i->info(i) )
data_get(i,fvarg)(&buffx);
//data_get(i,fvarg)(CLOCK_REALTIME, opp);



return 0;
}
