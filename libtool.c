

//mjo mathias j odea
//indepedent no share no invite no acceptions

/////no-nonsince



#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>



#define STUB 1
#define print(str,adr) \
if(STUB) printf(str, adr);



void (*(*g_func )) (void *, ...);

typedef struct proc_
{
int index;
void *func_;
void *size_;
void **param;
void **cstr; 

struct proc_ * table_;
struct proc_ * next_;
struct proc_ * itorator_;

}proc_;



typedef struct dl_data
{
int index;
void *mod;
void *proc_address;

void *cstr; 
void *dll_id;

struct proc_ * list_;
struct Dl_info *inf;


/*
#define RTLD_LOCAL    0
#define RTLD_LAZY     0x00001
#define RTLD_NOW      0x00002
#define RTLD_NOLOAD   0x00004
#define RTLD_GLOBAL   0x00100
#define RTLD_NODELETE 0x01000
*/

void *(*dload) (void * path);
void *(*dloadv) (void  * path, int flag);
void* (*symload) (void * mod, char* key_);
void* (*symloadv)(void *mod, char* key_, char * version);
void*  (*error) (void);
void*  (*close)(void);

//--------t6
void ** (*new_node) (void);
void ** (*this_) (void); 



//int * ( *dl_info ) (char *path);
//----------------
void * this_i;
struct dl_data * next_;
struct dl_data * prev_;
struct dl_data * head_;
struct dl_data * tail_;

}dl_data; dl_data *this_so;

//--------
dl_data ** thiz(void);
dl_data ** new_dl(void);
dl_data ** copy_cc(void *);

//-------default heading
dl_data **new_dl()
{
dl_data *node;

node = (( malloc(sizeof(dl_data)) ) );


//------ new
#define this_so node

if(node == NULL)
{
 this_so->index =0;
 this_so->mod = NULL;
 this_so->this_i = this_so;
 this_so->head_=this_so;
 this_so->next_ =NULL;
 this_so->prev_ =NULL;
 this_so->tail_ =this_so;
 this_so->this_ = thiz;
 this_so->new_node = &new_dl;
}

#undef this_so
return &(node);
}




dl_data ** copy_cc(void* i_)
{

if(i_) this_so = (dl_data*) i_;
return this_so;
}

void **  push(dl_data *itor)
{
if(itor )
{
dl_data *tmp;

if(thiz() ==NULL) { new_dl(); copy_cc(itor); }

	if( (itor->this_i = ((dl_data*)thiz())->tail_) ){
	tmp = (dl_data*) itor->this_i; //tail
	itor->prev_ = tmp;
	itor->next_ = NULL;
	//____
	itor->this_i = itor;
	tmp = itor;}
        

}

return ( (dl_data*) thiz())->this_i;
///reverse itorate with push/ insert and i(op_n) i[] same
}



dl_data ** thiz(void)
{
void ** so; so = this_so;
if(so == NULL){ *so = new_dl();
	if( so != this_so) this_so = *so;}
return &(*so);
}


void * load_dl(char* path)
{
void * rtn; int err;
rtn = dlopen(path, RTLD_NOW);
err = dlerror();

if(STUB)
printf("\ndll loaded: %d", err);

//------ new
if(this_so ==NULL) {
 this_so = malloc(sizeof(dl_data));
 this_so->index =0;
 this_so->mod = rtn;
 this_so->this_i = this_so;
 this_so->head_=this_so;
 this_so->next_ =NULL;
 this_so->tail_ =this_so;
 this_so->this_ = thiz;
}
else{
this_so->mod = rtn;
}
printf("...done");

if(rtn)
	return (rtn);
else return NULL;
}

void so_info(void*);

void *symcall(void *symb)
{
void *func; 
if(thiz() ==NULL) return NULL;
dl_data * tmp = (dl_data*) ((dl_data*)thiz())->this_i;
void *mod = tmp->mod; if(mod ==NULL ) return NULL;

func = dlsym(  tmp->mod , (char*)symb);
if (func )
this_so->proc_address=func; else {
if(STUB) printf("\ndl_error symbol not found "); }
if(func){
this_so->cstr = malloc (strlen(symb) +1);
strcpy(this_so->cstr, symb);
if(STUB) printf("\nsymbol: %s loaded",this_so->cstr);

return func;} else return NULL;
}

void **call(void *symb,  void ** param_)
{
    return NULL;
}


void so_info(void *proc_addr)
{
 Dl_info so_out;
void **itor; 

dladdr(proc_addr, & so_out); itor =& so_out;
printf("\n%s :0 %s : %s", itor[0] , itor[1], itor[2]);

}

void * load_sym(void *mod)
{ Dl_info so_out;
  void **itor; void* rtn = malloc(sizeof(int));
  void *proc = RTLD_DEFAULT;
  int count; 

} 

#define SYS_ "/system/lib/libandroid.so"
#define LIBC_ "libc.so"

int main(int arg , char* argv[])
{



printf("\nEntry");
dl_data *so = thiz();
if(so == NULL) { printf("no fucken der"); return 0; }
load_dl("/system/lib/libc.so");

int frtn; void * vr = malloc(sizeof(int));
typedef int * (*func_i)(void);
void *(*func) (void *,...);
typedef void *(*func_v) (void*,...) ;
//----

func =  symcall("system");
 func("echo test ok");


//dl_clean();

dlclose(so->mod);
free(so);
  return 0;

}



