
#include <z3.h>
// On latest souffle I should include this instead
#include "souffle/SouffleFunctor.h"
#include <cassert>
#include "z3.h"
#include <dlfcn.h>
//#include "souffle/RamTypes.h"
//#include "souffle/RecordTable.h"
//#include "souffle/SymbolTable.h"

Z3_config _config = Z3_mk_config();
Z3_context _ctx = Z3_mk_context(_config);
Z3_string z3_version = Z3_get_full_version();
Z3_ast ast_pack[5];
/*
__attribute__((constructor)) void initialize_ctx() {
  
  /*
    void* handle = dlopen("libz3.so", RTLD_LAZY);
    if (!handle) {
            fputs (dlerror(), stderr);
            exit(1);
        }
    Z3_config (*Z3_mk_config)() = (Z3_config (*)()) dlsym(handle, "Z3_mk_config");
    _config = (*Z3_mk_config)();
    Z3_context (*Z3_mk_context)(Z3_config) = (Z3_context (*)(Z3_config)) dlsym(handle, "Z3_mk_context");
    _ctx = Z3_mk_context(_config);
    char* (*Z3_get_full_version)() = (char* (*)()) dlsym(handle, "Z3_get_full_version");
    z3_version = Z3_get_full_version();
    
    _config = (*Z3_mk_config)();
    _ctx = Z3_mk_context(_config);
    z3_version = Z3_get_full_version();

}*/

extern "C" { 

  Z3_context myctx(){
      return _ctx;
  }
  Z3_string myversion(){
      return z3_version;
  }
  // This is such a bad idea.
  Z3_ast* pack1(Z3_ast x0){
      ast_pack[0] = x0;
      return ast_pack;
  }
  Z3_ast Z3_mk_and2(Z3_context ctx, Z3_ast x0, Z3_ast x1){
      Z3_ast args[] = {x0, x1} ;
      return Z3_mk_and(ctx, 2, args);
  }
  Z3_ast* pack2(Z3_ast x0, Z3_ast x1){
      ast_pack[0] = x0;
      ast_pack[1] = x1;
      return ast_pack;
  }
  Z3_ast* pack3(Z3_ast x0, Z3_ast x1, Z3_ast x2){
      ast_pack[0] = x0;
      ast_pack[1] = x1;
      ast_pack[2] = x1;
      return ast_pack;
  }

  Z3_lbool check_sat(Z3_context ctx, Z3_ast ast){
      Z3_solver s = Z3_mk_solver(ctx);
      Z3_solver_assert(ctx, s, ast);
      return Z3_solver_check(ctx,s);
  }

 souffle::RamDomain mycat(souffle::SymbolTable* symbolTable, souffle::RecordTable* recordTable,
        souffle::RamDomain arg1, souffle::RamDomain arg2) {
    assert(symbolTable && "NULL symbol table");
    assert(recordTable && "NULL record table");
    const std::string& sarg1 = symbolTable->decode(arg1);
    const std::string& sarg2 = symbolTable->decode(arg2);
    std::string result = sarg1 + sarg2;
    return symbolTable->encode(result);
 }
}
