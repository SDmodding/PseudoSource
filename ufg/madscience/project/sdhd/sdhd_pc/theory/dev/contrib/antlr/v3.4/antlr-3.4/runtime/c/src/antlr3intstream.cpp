// File Line: 45
// RVA: 0x25DFC0
UFG::allocator::free_link *__fastcall antlr3IntStreamNew()
{
  UFG::allocator::free_link *result; // rax

  result = antlrCalloc(1u, 0x80u);
  if ( result )
    result[15].mNext = (UFG::allocator::free_link *)antlr3EnumFree;
  return result;
}

