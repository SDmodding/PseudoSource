// File Line: 111
// RVA: 0x113DC0
void __fastcall SSTypedData::empty_table(APSortedLogical<SSTypedData,ASymbol> *table_p)
{
  APSortedLogical<SSTypedData,ASymbol> *v1; // r14
  SSTypedData **v2; // rbx
  unsigned __int64 v3; // rsi
  SSInstance *v4; // rcx
  bool v5; // zf
  SSTypedData *v6; // rdi
  SSClassDescBase *v7; // rcx

  v1 = table_p;
  v2 = table_p->i_array_p;
  v3 = (unsigned __int64)&v2[table_p->i_count];
  if ( (unsigned __int64)v2 >= v3 )
  {
    table_p->i_count = 0;
  }
  else
  {
    do
    {
      v4 = (*v2)->i_data_p;
      v5 = v4->i_ref_count-- == 1;
      if ( v5 )
      {
        v4->i_ref_count = 2147483648;
        ((void (__cdecl *)(SSInstance *))v4->vfptr[1].get_scope_context)(v4);
      }
      v6 = *v2;
      if ( *v2 )
      {
        v7 = v6->i_type_p.i_obj_p;
        if ( v7 )
          (*(void (__cdecl **)(SSClassDescBase *))&v7->vfptr->gap8[8])(v7);
        AMemory::c_free_func(v6);
      }
      ++v2;
    }
    while ( (unsigned __int64)v2 < v3 );
    v1->i_count = 0;
  }
}

