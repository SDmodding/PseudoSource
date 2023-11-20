// File Line: 335
// RVA: 0x11EC30
bool __fastcall SSClass::is_demand_loaded(SSClass *this)
{
  SSClass *v1; // rcx
  bool result; // al

  result = 1;
  if ( !(this->i_flags & 2) )
  {
    v1 = this->i_superclass_p;
    if ( !v1 || !SSClass::is_demand_loaded(v1) )
      result = 0;
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
  unsigned int v2; // eax
  SSCoroutineBase **v3; // r8
  unsigned int v4; // er10
  signed __int64 v5; // r9
  signed __int64 v6; // rax
  unsigned int v7; // edx
  _BOOL8 v8; // rdx

  v2 = this->i_coroutines.i_count;
  if ( !v2 )
    return 0;
  v3 = this->i_coroutines.i_array_p;
  v4 = coroutine_name->i_uid;
  v5 = (signed __int64)&v3[v2 - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = (signed __int64)&v3[(v5 - (signed __int64)v3) >> 4];
      v7 = *(_DWORD *)(*(_QWORD *)v6 + 8i64);
      if ( v4 >= v7 )
      {
        v8 = v4 != v7;
        if ( v8 >= 0 )
          break;
      }
      if ( v3 == (SSCoroutineBase **)v6 )
        return 0;
      v5 = v6 - 8;
    }
    if ( v8 <= 0 )
      break;
    if ( v5 == v6 )
      return 0;
    v3 = (SSCoroutineBase **)(v6 + 8);
  }
  return 1;
}

