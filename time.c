



#include "libtool.h"
#include "dl_ext.h"



#include <time.h>

int main()
{

out_p = &printf;

void * q, **msg;
char * str;
char * buffs;
char *cbuff;
mod_ *c,*inp;

symbol funnel[5];


//init(funnel, sizeof(symbol) * 5 );
init(inp,mod_);
init(c,mod_);
init(str,32);
init(buffs,32);
init(q, 32)
init(msg, 32);
struct tm t;




load_mod(c,"/system/lib/libc.so");nl_
sym_mod(c , "ctime");nl_

load_mod(inp,"/system/lib/libandroid.so");nl_
sym_mod(inp,"AInputQueue_getEvent");nl_

init(q, inp->addr);

#define moffset_int(addr_v, c_) \
(mem_offset(addr_v, (sizeof(int)), c_))

nl_



funnel[0].addr = c->addr; 

funnel[1].addr =
sym_mod(c,"system");

while ( castf(inp->addr)(q, msg)  ) 
 {
        loading(&wait);

	 castf(funnel[1].addr)("clear");
	 nl_
	 out_("=============");
	 out_("console : clear");
	}



nl_


return 0;
}
