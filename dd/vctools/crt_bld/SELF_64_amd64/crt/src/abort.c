// File Line: 55
// RVA: 0x12BBD50
void __cdecl __noreturn abort()
{
  if ( _get_sigabrt() )
    raise(22);
  if ( _abort_behavior & 2 )
  {
    if ( IsProcessorFeaturePresent_0(0x17u) )
      __fastfail(7u);
    call_reportfault(3, 0x40000015u, 1u);
  }
  exit(3);
}

// File Line: 121
// RVA: 0x12BBD34
__int64 __fastcall set_abort_behavior(unsigned int flags, unsigned int mask)
{
  __int64 result; // rax

  result = _abort_behavior;
  _abort_behavior = mask & flags | _abort_behavior & ~mask;
  return result;
}

