


#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{

void * addr;
void * data;
void * key;

void * next_;
void * prev_;

//-----------
void *parent;
void ***interface; // [rtype] [ptype]

/*node_iface
void * (*new_node)(void);
void * (*new_data_t)(void *size);
void * (*set_data)(void *);
void * (*new_link)(void*);
void * (*clear_data)(void);
void * (*error)(void);
dynamic
void ***func_list;  req.
enum table
generic 5 return types 
**ui = mem(5); //base*/
}node_;

struct node_iface
{

void * (*new_node)(void);
void * (*new_data_t)(void *size);
void * (*set_data)(void *);
void * (*new_link)(void*);                                 void * (*clear_data)(void);
void * (*error)(void);

}node_iu;

void *clear_node(void*);
void*new_node();

void * new_data(void *size_)
{
static node_ * rtn;
rtn = new_node();
rtn->addr = malloc(sizeof(int));
*((int*)rtn->addr) = *((int*)(size_));
rtn->data = malloc( *((int*)size_) );
rtn->key = NULL;
return rtn;
}


void * set_data(void *data_in,int size) 
{ void * itor = data_in;
  static node_* out; //int  size = sizeof(node_data_in);
  out = new_data( size);
  memcpy( out->data , itor, size);
return out;
}

//merges or appends newlink (like tree)
void * new_link(void* in)
{
if(in == NULL) return new_node();
node_ *i[3]; 
  i[0]= (node_*) in;
  i[1] = new_node();  
  i[1]->prev_ = i[0];
  i[1]->next_ = i[0]->next_;
  i[0]->next_ = i[1];
  
//if(i[0]->prev_ ==NULL && i[0]->next_ ==NULL)
return i[1];
}

void * next_(void * node)
{
 void * out;
  if(node && ((node_*)node)->next_)
  {
  out = ((node_*)node)->next_;
   return out;
  }
 else
 return NULL;
}

void * prev_(void * node)
{
  void * out;
  if(node && ((node_*)node)->prev_)
  {
  out =((node_*) node)->prev_;
   return out;
  }
 else 
 return NULL;
}

void * new_node()
{
node_*out; void * i[2]; 
out = malloc(sizeof(node_));
i[0]= out; i[1] = i[0];
while(i[1]  && i[1] < (sizeof(node_) + out) )
{
i[1]++;
i[0] = NULL;
i[0] = i[1];
}
return out;
}

void *clear_node(void * node)
{
void * i[3];
node_* tmp;
tmp= ((node_*) node);
i[0] = node; i[1]=i[0];

while(i[0]  != NULL) 
while(i[1]  && i[1] < (sizeof(node_) + tmp))

return NULL;

}



typedef struct list_
{

struct list_ * this_; //if list_::data:list_
                       //this is linked itorator
//-------------
struct node_ * head_;
struct node_ * tail_;
struct node_ * itor_;

//--------------
void *begin; //top:: node_<<list_:this_
void *child; //next::<<itor_

void* *(*push)(void *); //first in last out
void* *(*pop)(void);
void* *(*que) (void*);  //first in first out
void* *(*dque)(void);  
void* *(*itor)(void);
void* *(*geti)(int);


//---------------
void *(*node)();

}list_; 



void *list();

//struct design as private containor
//
//node_ 
// { list_   :<<>> list_::this_ "itorator" 
//  { head tail itor : node_
//            { addr : size for data_t
//              data : generic data field
//              key  : reserved
//            }
//            parent: offset linker
//            interface {
//            function prototypes
//            }
//     }
//   begin:: node_:self(list_)
//   child:: self:itor_
//   }
//   
//    
//
//link_list returns : node_*:data:list_*

void *link_list(void * lst)
{
 void * dummy; //non static node_:itorator
 static  node_* n; //parent of begin list_

 if(lst == NULL && n == NULL){ //construct Parent
	 n= new_node();
	 n->data = /*(list_*)*/ list();
	//((list_*)  n->data)->this_ =NULL;
	 n->addr = malloc(sizeof(int));
	*((int*) n->addr) = sizeof( list_);
	 n->key =  malloc(24);
	 strcpy(n->key,"list_");

	  n->parent = n->data; //list_ 
	 ((list_*)  (n->parent))->begin = n; //node_<list_
          ((list_*) (n->parent))->child = 
		  ((list_*)n->parent)->itor_;//list_:node_*
	  
return n;
 } //node_ ::>> list_:data>>node_:>>data

 //(lst 
#define dummy_b ((node_*)dummy)

 if(n!=NULL && lst != NULL ) //search for key
 {
  dummy = new_node(); 
  #define dummy dummy_b
  
  dummy->key = malloc(24); strcpy(dummy->key,"search");
  dummy->addr = n; // very top node
  dummy->data = (node_*) ((list_*) n->data)->itor_;
  dummy->parent = n->parent; //list_:node_
  return dummy;
 }
#undef dummy 
#undef dummy_b

 if(n!=NULL && lst ==NULL) //copy or itorate
 {
  lst = n;
  return lst;  //begin::node_:list_
  }
  //DFLT
  return NULL;

}//link_list

void * list_itor(void)
{ void * gitor = NULL;
   return link_list(gitor);
}

//input
//parent
//node_::search_node
//addr: offset size of data out
//key: search type 'string ie'
void * find_list(void*);
//-------

void * find_key(void * str_)
{

node_ * search, *itor;
itor  = list_itor();
search = link_list(itor); //get dummy
if(strcmp( search->key,"search") ==0)
{
  if(strlen(str_) <= strlen(search->key))
  strcpy( search->key, str_); else return NULL;

    itor = (void*) find_list((void*)search);
     if(strcmp( itor->key, str_) == 0)
      { 
        search = itor;
	return search;
	}
        else return itor;
	
}

return NULL;
}



void * find_list(void *node_key)
{
void * str_;
static node_ * found; //data:offset of found key
static node_ * begin;
node_* itor;
itor = list_itor(); //begin node:list

if(node_key!=NULL && itor != NULL)
{
//all ready
if(node_key && found && 
( strcmp( found->key, ((node_*)node_key)->key)) ==0)
  return found;  

  //from dummy ;build node link
  if(itor && node_key && 
	  itor->parent == ((node_*)node_key)->parent)
  begin = ((node_*) node_key)->data; //node:list_-itor_
  
  if( begin ) 
   { //Single stream list 
      found  = begin;
      itor = begin;
while( itor->next_ && 
	!( strcmp( found->key, itor->key) ==0) )
      {if(itor->next_) 
         itor = itor->next_;} //while
 
      if( strcmp( found->key, itor->key) == 0)
      {
       *found = *itor;
        return found;
      }
       else // not found
       {
	found = node_key;
	strcpy(found->key,"unfound");
        return found;
       }

   }//begin ?

        
   }//itorator?


return NULL;
}

//PARENT >NODE_ ::data> < contains: list_> <node_
///for new list and default construct and link
void * list() //used by/for link_list 
{
static list_* l; 
static node_ * n;

l = malloc(sizeof( list_));
n = new_node();
n->addr = sizeof (list_);
n->key = malloc(24);
strcpy(n->key, "list_");
n->parent = l;
l->begin = n;
l->child = n->((*list_)parent)->itor_;
n->data = (list_*) l;

l->this_= NULL;
l->head_ = NULL;
l->tail_ = NULL;
l->itor_ = NULL;

return l;
}

void * list_clear()
{
  void * par; void * child;
  
  return NULL;
}

/////
//node_ .end
//////////////////////
//////////////////////
//list_ .end


//#define debug_
#include "std.h"

#define mem(stype) malloc(sizeof(stype))
#define cast_(stype,out) ((stype) out)

int main(int argi, char* argvm[])
{


///----so fuckken fuck so fuck fuckken du 
void * func,**out_p ,**np;
mod i; i = so_itor(NULL); //init
            so_itor(i);

     ///so du duh du ded deead duckken deh d-ud duck
     //all noddts !!  all  hell dueh all ni 
     //no? questing for questions hellz noddta duh
     //now ...



void * itor;
list_ *modl;  mod data_i;
modl = list();
node_ * n = modl->itor_;

//----------------------------


//-----------
FILE * OUTS;
FILE * out_f;


printf("\nlink interface : mad' mathimetric");
i=so_open("/system/lib/libc.so", "dup");
i->info(i);

OUTS =   data_get(i,fvarg)(stdout);

i= so_sym("posix_spawnp");
i->info(i);

////--------------
itor = n;
((node_*)itor)->data = mem(struct module);
*((mod)((node_*)itor)->data) = *i;
   data_i = ((mod)((node_*)itor)->data) ;
    new_link( ((node_*)itor) );


char argv [5][256]  = {{NULL}};
char cd[256];
char cmd[] ="std.o"; //arg0
memset(cd ,0,256);

i = so_sym("getcwd");  
i->info(i);
 

 //getcd
 out_p = data_get(i,fvarg)(cd,256);
 
sprintf(cd , "%s/%s", (char*) out_p,cmd);
printf("\n%s",cd);
 
void *pid = malloc (8);
void * env = argvm;
void * actions = NULL;
void * attrib;
 

out_p =
data_get(data_i, fvarg)(pid , cd, 
		    actions, attrib,
		    argv , env); 
	 
if(out_p && *out_p ==-1) 
	printf("\neror spawn");

return 0;
}



