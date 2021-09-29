




#include "libtool.h"



int main()
{
mod dl, c;
dl = init_dlmod();
int wid,w;


void *wait_;
void *print_;
c = so_load("/system/lib/libc.so","wait");
wait_ = c->addr;
mod_sym(c,"printf");
print_ = c->addr;


MOD gles;
gles

gles.ns = 
castf(dl->create_namespace)
(
"egl",
"/system/lib/egl/",
"/system/lib/",                   
ANDROID_NAMESPACE_TYPE_ISOLATED | 
ANDROID_NAMESPACE_TYPE_SHARED,
"/system/:/data/:/vendor/:system/lib/",                 
NULL);


wid = 
castf(wait_)(&w);
//wid = callmod(c)(&w);

castf(
print_)("\nwid:%d w:%d",wid,w);


android_dlextinfo dlexti;
gles.extinfo = &dlexti;

dlexti.flags = ANDROID_DLEXT_USE_NAMESPACE;
dlexti.library_namespace = gles.ns;
	
 
gles.mod =
castf(dl->loadso_ext)
("/system/lib/egl/libGLES_android.so", 
RTLD_LOCAL | RTLD_NOW , gles.extinfo);



if( gles.mod != NULL  ) 
	castf(print_)("\nns MOD okay");

#define heading "------------------------"
#define dbreak {castf(print_)("\n%s",heading);}


mod_sym(&gles,"gglinit");
callmod(&gles)(NULL);

gles.addr = 
castf(dl->loadso_sym)
(gles.mod,"eglGetCurrentContext");
void * dc = (gles.addr == NULL ? NULL:
((void * (*)(void)) (gles.addr))() );

castf(print_)("\negldc:%d",dc);
castf(print_)("\n%s",dlerror());
//------------
//
//


getc(stdin);

so_close(dl);


return 0;
}
