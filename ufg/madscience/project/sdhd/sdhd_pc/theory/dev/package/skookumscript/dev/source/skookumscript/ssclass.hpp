// File Line: 335
// RVA: 0x11EC30
bool __fastcall SSClass::is_demand_loaded(SSClass *this)
{
  SSClass *i_superclass_p; // rcx
  bool result; // al

  result = 1;
  if ( (this->i_flags & 2) == 0 )
  {
    i_superclass_p = this->i_superclass_p;
    if ( !i_superclass_p || !SSClass::is_demand_loaded(i_superclass_p) )
      return 0;
  }
  return result;
}

// File Line: 400
// RVA: 0x13D2B0
void __fastcall SSClass::track_memory(SSClass *this, AMemoryStats *mem_stats_p, __int64 a3)
{
  LOBYTE(a3) = 1;
  ((void (__fastcall *)(SSClass *, AMemoryStats *, __int64))this->vfptr[1].get_item_type)(this, mem_stats_p, a3);
}

// File Line: 475
// RVA: 0x11EB80
char __fastcall SSClass::is_coroutine_valid(SSClass *this, ASymbol *coroutine_name)
{
  unsigned int i_count; // eax
  SSCoroutineBase **i_array_p; // r8
  unsigned int i_uid; // r10d
  SSCoroutineBase **v5; // r9
  SSCoroutineBase **v6; // rax
  unsigned int v7; // edx

  i_count = this->i_coroutines.i_count;
  if ( !i_count )
    return 0;
  i_array_p = this->i_coroutines.i_array_p;
  i_uid = coroutine_name->i_uid;
  v5 = &i_array_p[i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = &i_array_p[((char *)v5 - (char *)i_array_p) >> 4];
      v7 = (*v6)->i_name.i_uid;
      if ( i_uid >= v7 )
        break;
      if ( i_array_p == v6 )
        return 0;
      v5 = v6 - 1;
    }
    if ( i_uid == v7 )
      break;
    if ( v5 == v6 )
      return 0;
    i_array_p = v6 + 1;
  }
  return 1;
}

