// File Line: 23
// RVA: 0x146F610
__int64 dynamic_initializer_for__ADeferFunc::c_deferred_funcs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ADeferFunc::c_deferred_funcs__);
}

// File Line: 36
// RVA: 0x226240
void ADeferFunc::invoke_deferred(void)
{
  unsigned int i_count; // ecx
  __int64 v1; // rdi
  AFunctionBase **i_array_p; // rbx
  AFunctionBase **v3; // rsi

  i_count = ADeferFunc::c_deferred_funcs.i_count;
  v1 = ADeferFunc::c_deferred_funcs.i_count;
  if ( ADeferFunc::c_deferred_funcs.i_count )
  {
    i_array_p = ADeferFunc::c_deferred_funcs.i_array_p;
    v3 = &ADeferFunc::c_deferred_funcs.i_array_p[ADeferFunc::c_deferred_funcs.i_count];
    if ( ADeferFunc::c_deferred_funcs.i_array_p < v3 )
    {
      do
      {
        (*i_array_p)->vfptr->invoke(*i_array_p);
        if ( *i_array_p )
          (*i_array_p)->vfptr->__vecDelDtor(*i_array_p, 1u);
        ++i_array_p;
      }
      while ( i_array_p < v3 );
      i_array_p = ADeferFunc::c_deferred_funcs.i_array_p;
      i_count = ADeferFunc::c_deferred_funcs.i_count;
    }
    if ( (_DWORD)v1 == -1 )
      v1 = i_count;
    if ( (_DWORD)v1 )
    {
      ADeferFunc::c_deferred_funcs.i_count = i_count - v1;
      memmove(i_array_p, &i_array_p[v1], 8i64 * (i_count - (unsigned int)v1));
    }
  }
}

