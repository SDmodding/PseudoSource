// File Line: 76
// RVA: 0x25CB30
UFG::allocator::free_link *__fastcall antlr3ExceptionNew(
        unsigned int exception,
        UFG::allocator::free_link *name,
        UFG::allocator::free_link *message,
        char freeMessage)
{
  UFG::allocator::free_link *result; // rax

  result = antlrCalloc(1u, 0xA0u);
  if ( result )
  {
    result[1].mNext = name;
    LODWORD(result->mNext) = exception;
    result[18].mNext = (UFG::allocator::free_link *)antlr3ExceptionPrint;
    result[2].mNext = message;
    result[19].mNext = (UFG::allocator::free_link *)antlr3ExceptionFree;
    LOBYTE(result[4].mNext) = freeMessage;
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
  ANTLR3_EXCEPTION_struct *nextException; // rdi
  void (__fastcall *freeCustom)(void *); // rax

  if ( ex )
  {
    v1 = ex;
    do
    {
      nextException = v1->nextException;
      if ( v1->freeMessage == 1 )
        antlrFree((char *)v1->message);
      freeCustom = v1->freeCustom;
      if ( freeCustom )
        freeCustom(v1->custom);
      antlrFree((char *)v1);
      v1 = nextException;
    }
    while ( nextException );
  }
}

