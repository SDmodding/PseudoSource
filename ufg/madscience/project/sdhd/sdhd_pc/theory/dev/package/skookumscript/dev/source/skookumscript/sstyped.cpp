// File Line: 111
// RVA: 0x113DC0
void __fastcall SSTypedData::empty_table(APSortedLogical<SSTypedData,ASymbol> *table_p)
{
  SSTypedData **i_array_p; // rbx
  SSTypedData **v3; // rsi
  SSInstance *i_data_p; // rcx
  SSTypedData *v6; // rdi
  SSClassDescBase *i_obj_p; // rcx

  i_array_p = table_p->i_array_p;
  v3 = &i_array_p[table_p->i_count];
  if ( i_array_p >= v3 )
  {
    table_p->i_count = 0;
  }
  else
  {
    do
    {
      i_data_p = (*i_array_p)->i_data_p;
      if ( i_data_p->i_ref_count-- == 1 )
      {
        i_data_p->i_ref_count = 0x80000000;
        i_data_p->vfptr[1].get_scope_context(i_data_p);
      }
      v6 = *i_array_p;
      if ( *i_array_p )
      {
        i_obj_p = v6->i_type_p.i_obj_p;
        if ( i_obj_p )
          (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
        AMemory::c_free_func(v6);
      }
      ++i_array_p;
    }
    while ( i_array_p < v3 );
    table_p->i_count = 0;
  }
}

