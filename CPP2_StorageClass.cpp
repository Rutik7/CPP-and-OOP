/*storage class define the scope and lifetime of the variables and functions

1. Automic storage class(auto)
    scope -> local to the block
    lifetime -> till execution of the block
    default value -> garbage
    linkage -> no linkage
    
2. Register storage class(register)
    scope -> local to the block
    lifetime -> till execution of the block
    default value -> garbage
    linkage -> no linkage
    
3. Static storage class(static)
    scope -> local to the block but retains its value between function calls
    lifetime -> till the execution of whole program --> in data section
    default value -> 0
    linkage -> internal or no linkage
    
4. Extern storage class(extern)
    scope -> global, can be accessed from any file that declares it.
    lifetime -> till the execution of whole program
    uses -> to share variable between multiple files
    linkage -> external linkage
    
5. Thread storage class(thread_local)
    scope -> local to the thread in which it is defined
    lifetime -> exist for the dureation of the thread
    uses -> used to declare variables that are unique to each thread , allowing 
            each thread to have its own instance of the varible*/

#include <iostream>
using namespace std;

int gloabalvar = 5;
void fun()
{
    static int count = 0;
    count++;
    cout<<count<<endl;

}
int main()
{
    //auto 
    auto int x = 10;
    fun();
    fun();

    extern int gloabalvar;
    cout<<gloabalvar<<endl;

    //register int speed = 100;//register // deprecated for c++ 17 

    thread_local int thredvar = 10;

    return 0;
}