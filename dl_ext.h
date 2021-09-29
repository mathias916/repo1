




#include "libtool.h"

#include <link.h>


#define init(mem,size_) mem=malloc(sizeof(size_));

/*                         
typedef struct {                                             /Pathname of shared object that contains address. 
const char* dli_fname;                                     /Address at which shared object is loaded
void* dli_fbase;                                           const char* dli_sname; //nearest symbol name
void* dli_saddr;                                       
} Dl_info;


int dladdr(const void* __addr, Dl_info* __info);





#define RTLD_LOCAL    0
#define RTLD_LAZY     0x00001
#define RTLD_NOW      0x00002
#define RTLD_NOLOAD   0x00004
#define RTLD_GLOBAL   0x00100
#define RTLD_NODELETE 0x01000
*/
/* link.h
struct dl_phdr_info {
  ElfW(Addr) dlpi_addr;
  const char* dlpi_name;
  const ElfW(Phdr)* dlpi_phdr;
  ElfW(Half) dlpi_phnum;

  // These fields were added in Android R.
  unsigned long long dlpi_adds;
  unsigned long long dlpi_subs;
  size_t dlpi_tls_modid;
  void* dlpi_tls_data;
};
*/

typedef struct symbol
{
	void * addr;
	char * name;
	void * dl_info;
	void * dl_phdr_info;

	void * next_;
}symbol;


void * dlinfo(void * addr, void * dl_info)
{
return dladdr(addr, dl_info);
}

static int callback_walk(struct dl_phdr_info * info, size_t size_info,void * data)
{
	unsigned int x,y;
	unsigned char byte;
	x=0;y =0;



Dl_info dl_i; 


void  * base;
void *p,*d;

base = info;


out_("\nCallback:open objects");
getc(stdin);

x=0;

nl_
#define base ((struct dl_phdr_info*)base)

out_("%s : \%d :num_dr",base->dlpi_name, base->dlpi_phnum);



#undef base
nl_
return 0;
}


#ifdef  MAIN_proc


int main()
{


mod_ *c,*dl,*vulkan,*jni,*droid, *droid_rt;



symbol dls[10];
symbol egl[10];
symbol java[10];


struct 
dl_phdr_info * dlp_info;

init(dlp_info, struct dl_phdr_info * );

init(c,mod_);
init(dl,mod_);
init(vulkan,mod_);
init(jni,mod_);
init(droid,mod_);
init(droid_rt,mod_);

out_p = castf(&printf);

out_("\ndl ext 1.0"); nl_;


if( c && dl && vulkan)
{
out_("\nloading");nl_
load_mod(dl,"/system/lib/libdl.so"); nl_


///////////////
dls[0].addr = 
sym_mod(dl,"dlopen");nl_
dls[1].addr = 
sym_mod(dl,"dlsym");nl_
dls[2].addr =
sym_mod(dl,"dlvsym");nl_
dls[3].addr =
sym_mod(dl,"dl_iterate_phdr");nl_
dls[4].addr =
sym_mod(dl,"android_dlopen_ext");nl_
dls[5].addr =
sym_mod(dl,"dlclose");nl_


//////

//iterate
//castf( dls[3].addr ) ( &callback_walk,dlp_info);



dl_load_mod(
castf(dls[0].addr)("/system/lib/libandroid.so",
        RTLD_NOW),
droid);

nl_

dl_load_mod(
castf(dls[0].addr)("/system/lib/libandroid_runtime.so",
	RTLD_NOW),
droid_rt);

nl_

dl_load_mod(
castf(dls[0].addr)("/system/lib/librs_jni.so",
        RTLD_NOW),
jni);

nl_

java[0].addr =
sym_mod(droid_rt,"JNI_CreateJavaVM");nl_
java[1].addr = 
sym_mod(jni,"JNI_OnLoad");nl_

sym_mod(jni,"JNI_GetCreatedJavaVMs"); nl_
sym_mod(jni,"JNI_GetDefaultJavaVMInitArgs");nl_
sym_mod(droid_rt,"JNI_DetacthThread");
sym_mod(jni,"rsContextCreateGL");nl_

void * GLContext;
void * DC;
void * HDC; 
void * rtn;

void * Surface, *Window;
void * Display;

////-------
DC= NULL;

init(rtn, int);

GLContext = 
castf(jni->addr)(DC,NULL);

egl[0].addr =
sym_mod(droid_rt,"eglInitialize");nl_ 
egl[1].addr =
sym_mod(droid_rt,"eglGetError"); nl_

sym_mod(droid_rt,"eglCreatePlatformWindowSurface");


int version[2] ={0};//major ,minor

castf(egl[0].addr)(GLContext, &version[0], &version[1]);

egl[2].addr = 
sym_mod(droid_rt,"eglMakeCurrent");

castf(egl[0].addr)(Display, Surface, Window, GLContext);

out_("\ngerr:%d",
   *((int*)rtn) =  (castf__(egl[1].addr)()) 
			);

out_("\nloading");

}
else out_("\nalloc failed, load failed");

  dlclose(c->mod);
  dlclose(dl->mod);
  dlclose(jni->mod);
  dlclose(droid->mod);
  dlclose(droid_rt->mod);

  free(c);free(dl);free(vulkan);
  getc(stdin);

return 0;
}

#endif
