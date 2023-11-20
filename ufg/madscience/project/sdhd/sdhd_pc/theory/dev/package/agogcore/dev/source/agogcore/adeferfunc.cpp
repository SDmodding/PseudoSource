// File Line: 23
// RVA: 0x146F610
__int64 dynamic_initializer_for__ADeferFunc::c_deferred_funcs__()
{
  return atexit(dynamic_atexit_destructor_for__ADeferFunc::c_deferred_funcs__);
}

// File Line: 36
// RVA: 0x226240
void ADeferFunc::invoke_deferred(void)
{
  unsigned int v0; // ecx
  __int64 v1; // rdi
  AFunctionBase **v2; // rbx
  AFunctionBase **v3; // rsi

  v0 = ADeferFunc::c_deferred_funcs.i_count;
  v1 = ADeferFunc::c_deferred_funcs.i_count;
  if ( ADeferFunc::c_deferred_funcs.i_count )
  {
    v2 = ADeferFunc::c_deferred_funcs.i_array_p;
    v3 = &ADeferFunc::c_deferred_funcs.i_array_p[ADeferFunc::c_deferred_funcs.i_count];
    if ( ADeferFunc::c_deferred_funcs.i_array_p < v3 )
    {
      do
      {
        ((void (*)(void))(*v2)->vfptr->invoke)();
        if ( *v2 )
          (*v2)->vfptr->__vecDelDtor(*v2, 1u);
        ++v2;
      }
      while ( v2 < v3 );
      v2 = ADeferFunc::c_deferred_funcs.i_array_p;
      v0 = ADeferFunc::c_deferred_funcs.i_count;
    }
    if ( (_DWORD)v1 == -1 )
      v1 = v0;
    if ( (_DWORD)v1 )
    {
      ADeferFunc::c_deferred_funcs.i_count = v0 - v1;
      memmove(v2, &v2[v1], 8i64 * (v0 - (unsigned int)v1));
    }
  }
}

