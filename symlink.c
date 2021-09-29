//no-nonsince 
//not open source
//not open for/to prodject period.
//no-nonsince policy.

//writer: mjo math916
//piracy $oftware theft including intelectual property not limited to code,data,info, technic ,methods
//not a victimless crime, people die (d.o.d., N.a.s.a. )

/////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>


//////define loader module. header tools //

#ifndef mod_so
#define mod_so





typedef void addr_t;


/////module handle
typedef struct mod_
{
        addr_t *mod;
	addr_t *addr;

//-----
	addr_t *func;
	addr_t *info_; //default sym : key

//------
        addr_t *data_;  //ie buket of sym:addr
	addr_t *info_t;

    void* next_;
}mod_;

#endif

void * (*out_p)(void*,...);

#define out_ out_p
#define nl_ out_("\n");


#define ATTR_DL_ RTLD_NOW

void * sym_mod(void *mod, void * key_)
{
char * err;
char * str_;
void * info;

if(mod == NULL ) return NULL;
if(key_ == NULL ) return NULL;

	((mod_*)mod)->info_  = malloc(strlen(key_));
	info = ((mod_*)mod)->info_;
	strcpy(info, key_);

((mod_*)mod)->addr =
	dlsym(	((mod_*)mod)->mod,
	(const char *) ((mod_*)mod)->info_);

if( ((mod_*)mod)->addr != NULL)
{
out_("key:%s:loaded ",(char*)((mod_*)mod)->info_);
return ((mod_*)mod)->addr;
}
else {
       err = dlerror();
       if(err) out_("\n%s", err);
	return NULL;
}
}
/////

void * load_mod(void *mod , void * path_)
{

char * err;


if(mod )
((mod_*)mod)->mod = 
  dlopen(path_, RTLD_NOW );

err = dlerror();

if(err){
	out_("%s",err);
	getc(stdin);
}

  if(((mod_*)mod)->mod == NULL)
  out_("so load not found ");
  else{
  out_("so: %s:loaded ",path_);
  return ((mod_*)mod)->mod;
  }
  return NULL;
}

////////


#define castf_(func) \
((void*(*)(void*) ) func) 

#define castf(func) \
((void *(*)(void*,...))	func)


/////

int loading(void *wait_call)
{

static size_t *status;
int pid; int frames;

frames = 0;
pid =0;
if(status == NULL) { status = malloc( sizeof(size_t));
*status = 0; } 



while ((pid = (int) (castf(wait_call)(status)) ) != -1) ++frames;
if(frames)
out_("loaded time:%d",frames);
else 
out_("\nloaded: no wait");
return frames;
}

#include <sys/wait.h>

int main(int argi, char* argv [])
{

  int wait_s; int *pid_;
  void * func_;
  mod_ * c;


  out_p = castf( &printf);
  //out_p("hello fuck off go away do your own thing");
 

  
  c = malloc(sizeof(mod_));
  memset(c,0,sizeof(mod_));

  load_mod(c,"/system/lib/libc.so");
  nl_
  sym_mod(c,"wait"); loading(c->addr); nl_
  sym_mod(c,"system");
  castf(c->addr)("clear"); 

  ///
  sym_mod(c,"symlink");   nl_
  


 //( (void*(*)(void*))

    
    
  
#define H1 out_("\n××××××××××××××××××××××××××");

out_("\nsymlink 1.0 m_o");
H1
;
	out_("\n<link_path link_name> or \n< - path >");

if(argi >1 && c->mod)
{
if(argv[1][0] == '-')
{
sym_mod(c,"unlink");
if(
castf(c->addr) (argv[2]) == 0
) 
out_("\nUnlinked :%s ",argv[2]);

}
else
if(c->addr)
{
if(
castf(c->addr) (argv[1], argv[2]) == 0
)
out_("\n:link created for \n%s:%s\n",
		argv[1], argv[2]);

}



}
else {
//show help
out_("\nargument missing\n");
}


loading(&wait);
getc(stdin);
return dlclose(c->mod);

return 1;
}
