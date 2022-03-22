#include <dlfcn.h>
#include "z3.h"
int main(){
    void* handle = dlopen("libz3.so", RTLD_LAZY);
    if (!handle) {
            fputs (dlerror(), stderr);
            return 1;
        }
    Z3_config (*Z3_mk_config)() = (Z3_config (*)()) dlsym(handle, "Z3_mk_config");
    Z3_config cfg = (*Z3_mk_config)();
    return 0;
}