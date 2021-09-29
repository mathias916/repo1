
#include <stdio.h>
#include <dlfcn.h>
#include <stddef.h>



struct module
{

void *mod;
void *addr;
void **func;

///info
void *name; 
void *symbol;
void *version;

void * proxy_; //group handle inherit 
void *(*link_)(void *);
void *(*push)(void *);

}module; 

struct module * gmHANDLE; //head 
void * so_itor(void*);


typedef void * (*func_va)(void * add, ...);

void * so_open(void *pth, void *sym)
{
static struct module * out; 
if(pth ==NULL && sym == NULL && out) free(out);
if(pth && sym && out == NULL){ 
out = (struct module*) malloc( sizeof(module));
gmHANDLE = out;
out->proxy_  = gmHANDLE;
out->link_ = so_itor;
so_itor(gmHANDLE);
}


out->mod =  dlopen(pth, RTLD_NOW) ; 
if(out->mod !=  NULL) 
out->addr = dlsym(out->mod, (char*) sym) ;



        out->name = malloc( strlen((char*) pth) );
        strcpy( (char*) out->name, (char*) pth);
if(out->addr) :
{
        out->symbol = malloc( strlen( (char*) sym));
	strcpy( (char*) out->symbol, (char*) sym) ;
}
	return out;
}

void so_close(void *mod)
{

dlclose(  ((struct module*) mod)->mod );
return;
}

void * so_itor(void *set)
{
static void * itor;
if(itor ==NULL && set)
	itor = set;
return itor;
}


#define so_geti() (so_itor(NULL))
#define so_sym(sym_path ) so_open(NULL, sym_path)
#define so_clear() (so_open(NULL,NULL))
#define so_p(i) ((char*)(i ? i->name : NULL))
#define so_s(i) ((char*)(i ? i->symbol : NULL))
#define so_ok(i) (i && i->addr && i->mod )



typedef struct module *mod;
typedef void *(*func_va)(void*,...);
typedef void *(*func_v)(void*);
typedef void *(*funcv)(void);

#define so_get()   ((mod) so_geti())

//par = input symbol dl symbol
//

static void * callv(void* par,...)
{
if(so_get() == NULL || so_get()->mod == NULL) { 
	printf("\nbad module handle ");
    return NULL;}

mod tmp ; tmp =  (so_get());
static void* rtn; 
int size=0;
void * face=  callv;
void * next = par;


//while( next != NULL) ++next;
//---count arguments paramzrs
//next = va_arg(a, unsigned int *);
//++argi;
//va_end(a);
//--------



 if(par ==NULL) return NULL;
 
printf("\ndebug func ");

 funcv tmpf;
 void * func;
 void * modv = so_get()->mod;
//so_get()->func =  malloc(sizeof(funcv)) 
  func  = dlsym( modv,  (char*)par);
  tmpf = func;
 //so_get()->func = so_get()->addr;
//-----
 //rtn =  ((funcv) (so_get()->func))   ( ); 
 if(dlerror()) printf ("\nerror "); 
 rtn = NULL;
 if(tmpf)
 rtn = tmpf();
 return rtn;
 


}



#define getmod(in) ((mod)in)

#ifdef c_std_
#define main_s_1


void main()
{
void * func,**out_p ,**n;
mod i;




printf("\nhello stdc : \n time is : ");

i = so_open("/system/lib/libc.so","ctime");;

printf("\n%s", (char*) callv("getcwd") ) ;

if( so_ok(i) ) 
{
printf("\nstruct\n%d\n%d\n%s\n%s", i->mod,i->addr,
(char*)i->name, (char*)i->symbol);

//get time


func_v time_fv ;
time_fv = i->addr; out_p = malloc( 4 * 4);
func = i->addr;

//while (1)  
void * r;


// = time_fv ( NULL) ; n = out_p;
// r=
//r= (void*) ( time_fv ) (out_p) ;


printf( "\n%s", (char*) r);
		//(long) n[0], (long) n[1],
	//	(//long) n[3],(long)  n[4]);


so_close(i);
}
else printf("\nbad lib or bad symbol");

return;



}

#endif
