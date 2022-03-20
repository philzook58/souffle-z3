
#include <z3.h>
// On latest souffle I should include this instead
//#include "souffle/SouffleFunctor.h"
#include "souffle/RamTypes.h"
#include "souffle/RecordTable.h"
#include "souffle/SymbolTable.h"

extern "C" { 
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
