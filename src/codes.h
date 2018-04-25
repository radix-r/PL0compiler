#define OK 0
#define ERROR -1
#define END 1

typedef enum {
nulsym = 1, identsym, numbersym, plussym, minussym,
multsym, slashsym, oddsym, eqsym, neqsym,
lessym, leqsym,gtrsym, geqsym, lparentsym,
rparentsym, commasym, semicolonsym, periodsym, becomessym,
beginsym, endsym, ifsym, thensym, whilesym,
dosym, callsym, constsym, varsym, procsym,
writesym, readsym , elsesym, intsym} token_type;

typedef enum{
  lit = 1, rtn, lod, sto, cal,
  inc, jmp, jpc, sio, neg,
  add, sub, mult, divi, odd,
  mod, eql, neq, lss, leq,
  gtr, geq} op_code;
