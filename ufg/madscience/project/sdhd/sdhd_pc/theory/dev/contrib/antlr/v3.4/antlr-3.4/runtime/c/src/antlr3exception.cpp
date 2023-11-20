// File Line: 76
// RVA: 0x25CB30
UFG::allocator::free_link *__fastcall antlr3ExceptionNew(unsigned int exception, void *name, void *message, char freeMessage)
{
  UFG::allocator::free_link *v4; // rsi
  unsigned int v5; // ebp
  char v6; // bl
  UFG::allocator::free_link *v7; // rdi
  UFG::allocator::free_link *result; // rax

  v4 = (UFG::allocator::free_link *)name;
  v5 = exception;
  v6 = freeMessage;
  v7 = (UFG::allocator::free_link *)message;
  result = antlrCalloc(1u, 0xA0u);
  if ( result )
  {
    result[1].mNext = v4;
    LODWORD(result->mNext) = v5;
    result[18].mNext = (UFG::allocator::free_link *)antlr3ExceptionPrint;
    result[2].mNext = v7;
    result[19].mNext = (UFG::allocator::free_link *)antlr3ExceptionFree;
    LOBYTE(result[4].mNext) = v6;
  }
  return result;
}

// File Line: 122
// RVA: 0x25CB20
void __fastcall antlr3ExceptionPrint(ANTLR3_EXCEPTION_struct *ex)
{
  for ( ; ex; ex = ex->nextException )
    ;
}

// File Line: 158
// RVA: 0x25CAC0
void __fastcall antlr3ExceptionFree(ANTLR3_EXCEPTION_struct *ex)
{
  ANTLR3_EXCEPTION_struct *v1; // rbx
  ANTLR3_EXCEPTION_struct *v2; // rdi
  void (__fastcall *v3)(void *); // rax

  if ( ex )
  {
    v1 = ex;
    do
    {
      v2 = v1->nextException;
      if ( v1->freeMessage == 1 )
        antlrFree(v1->message);
      v3 = v1->freeCustom;
      if ( v3 )
        v3(v1->custom);
      antlrFree(v1);
      v1 = v2;
    }
    while ( v2 );
  }
}

