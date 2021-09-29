




#include "libtool.h" 



int main()
{
//------data
mod android,dl,jni;

struct WIN;
struct SURF;

struct SURF * SURFACE;
struct WIN * WINDOW;




//--init data----
dl = init_dlmod();






android = 
mod_sym(android,"/system/lib/libandroid.so",
		"GetEnv");




		"ASurfaceTexture_fromSurfaceTexture");




if(android)
{

if(android->addr)
SURFACE = castf(android->addr)(NULL,NULL);
else { so_error(android); }

mod_sym(android, "ASurfaceTexture_acquireANativeWindow");
if(android->addr && SURFACE)
WINDOW = castf(android->addr)(SURFACE);
else { so_error(android); } 

}

so_error(android);


printf("\nok");
getc(stdin);


//-----main scope


so_close(dl);
so_close(android);

return 0;
}
