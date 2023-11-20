// File Line: 34
// RVA: 0x106F50
void __fastcall SSDataInstance::~SSDataInstance(SSDataInstance *this)
{
  SSDataInstance *v1; // rdi
  void **v2; // rbx

  v1 = this;
  this->vfptr = (SSObjectBaseVtbl *)&SSDataInstance::`vftable';
  v2 = (void **)&this->i_data;
  SSData::empty_table(&this->i_data);
  AMemory::c_free_func(v2[1]);
  v1->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  v1->i_ptr_id = 0;
  v1->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
}

// File Line: 42
// RVA: 0x1097D0
void __fastcall SSDataInstance::add_data_members(SSDataInstance *this)
{
  SSClass *v1; // rdi
  __int64 v2; // rax
  SSTypedName **v3; // rdi
  unsigned __int64 v4; // rbp
  APSorted<SSData,ASymbol,ACompareLogical<ASymbol> > *v5; // r14
  unsigned int *v6; // rsi
  AObjReusePool<SSData> *v7; // rax
  AObjReusePool<SSData> *v8; // rbx
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  __int64 v12; // rcx
  SSData **v13; // rax
  SSData *v14; // rdx
  unsigned int v15; // eax

  v1 = this->i_class_p;
  v2 = v1->i_data_table.i_count;
  if ( (_DWORD)v2 )
  {
    v3 = v1->i_data_table.i_array_p;
    v4 = (unsigned __int64)&v3[v2];
    if ( (unsigned __int64)v3 < v4 )
    {
      v5 = (APSorted<SSData,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data.i_count;
      while ( 1 )
      {
        v6 = (unsigned int *)*v3;
        v7 = SSData::get_pool();
        v8 = v7;
        v9 = v7->i_pool.i_count;
        if ( v9 )
          break;
        if ( !v8->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(v8, v8->i_expand_size);
        v10 = v8->i_exp_pool.i_count;
        if ( v10 )
        {
          v11 = v10 - 1;
          v8->i_exp_pool.i_count = v11;
          v12 = v11;
          v13 = v8->i_exp_pool.i_array_p;
LABEL_11:
          v14 = v13[v12];
          goto LABEL_12;
        }
        v14 = 0i64;
LABEL_12:
        v14->i_name.i_uid = *v6;
        v14->i_data_p = SSBrain::c_nil_p;
        APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::append(v5, v14, 0i64);
        ++v3;
        if ( (unsigned __int64)v3 >= v4 )
          return;
      }
      v15 = v9 - 1;
      v8->i_pool.i_count = v15;
      v12 = v15;
      v13 = v8->i_pool.i_array_p;
      goto LABEL_11;
    }
  }
}

// File Line: 68
// RVA: 0x1177A0
SSClassDescBase *__fastcall SSDataInstance::get_data_by_name(SSDataInstance *this, ASymbol *name)
{
  SSDataInstance *v2; // rdi
  ASymbol *v3; // rbx
  SSTypedName *v4; // rax
  __int64 v6; // rax

  v2 = this;
  v3 = name;
  v4 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data,
         name);
  if ( v4 )
    return v4->i_type_p.i_obj_p;
  v6 = ((__int64 (*)(void))v2->i_class_p->vfptr->get_metaclass)();
  return (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64, ASymbol *))(*(_QWORD *)(v6 + 8) + 32i64))(v6 + 8, v3);
}

// File Line: 84
// RVA: 0x1176C0
SSData *__fastcall SSDataInstance::get_data_by_instance(SSDataInstance *this, SSInstance *obj)
{
  SSInstance *v2; // r8
  __int64 v3; // rdx
  SSData **v4; // rax
  unsigned __int64 v5; // rdx

  v2 = obj;
  v3 = this->i_data.i_count;
  if ( !(_DWORD)v3 )
    return 0i64;
  v4 = this->i_data.i_array_p;
  v5 = (unsigned __int64)&v4[v3];
  if ( (unsigned __int64)v4 >= v5 )
    return 0i64;
  while ( v2 != (*v4)->i_data_p )
  {
    ++v4;
    if ( (unsigned __int64)v4 >= v5 )
      return 0i64;
  }
  return *v4;
}

// File Line: 122
// RVA: 0x13C460
void __fastcall SSDataInstance::set_data_by_name(SSDataInstance *this, ASymbol *name, SSInstance *obj_p)
{
  SSDataInstance *v3; // rbp
  SSInstance *v4; // rbx
  ASymbol *v5; // rsi
  SSTypedName *v6; // rax
  SSTypedName *v7; // rdi
  SSClassDescBase *v8; // rcx
  bool v9; // zf
  __int64 v10; // rax

  v3 = this;
  v4 = obj_p;
  v5 = name;
  v6 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data,
         name);
  v7 = v6;
  if ( v6 )
  {
    ++v4->i_ref_count;
    v8 = v6->i_type_p.i_obj_p;
    v9 = LODWORD(v8[2].vfptr)-- == 1;
    if ( v9 )
    {
      LODWORD(v8[2].vfptr) = 2147483648;
      ((void (*)(void))v8->vfptr->get_item_type)();
    }
    v7->i_type_p.i_obj_p = (SSClassDescBase *)v4;
  }
  else
  {
    v10 = ((__int64 (*)(void))v3->i_class_p->vfptr->get_metaclass)();
    (*(void (__fastcall **)(__int64, ASymbol *, SSInstance *))(*(_QWORD *)(v10 + 8) + 40i64))(v10 + 8, v5, v4);
  }
}

// File Line: 152
// RVA: 0x130CA0
SSDataInstance *__fastcall SSDataInstance::pool_new(SSClass *class_p)
{
  SSClass *v1; // rdi
  AObjReusePool<SSDataInstance> *v2; // rax
  AObjReusePool<SSDataInstance> *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSDataInstance **v8; // rax
  SSDataInstance *v9; // rbx
  unsigned int v10; // eax

  v1 = class_p;
  v2 = SSDataInstance::get_pool();
  v3 = v2;
  v4 = v2->i_pool.i_count;
  if ( v4 )
  {
    v10 = v4 - 1;
    v3->i_pool.i_count = v10;
    v7 = v10;
    v8 = v3->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v3->i_exp_pool.i_count )
    AObjReusePool<SSDataInstance>::append_block(v3, v3->i_expand_size);
  v5 = v3->i_exp_pool.i_count;
  if ( v5 )
  {
    v6 = v5 - 1;
    v3->i_exp_pool.i_count = v6;
    v7 = v6;
    v8 = v3->i_exp_pool.i_array_p;
LABEL_8:
    v9 = v8[v7];
    goto LABEL_9;
  }
  v9 = 0i64;
LABEL_9:
  v9->i_class_p = v1;
  v9->i_ref_count = 1;
  v9->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  SSDataInstance::add_data_members(v9);
  return v9;
}

// File Line: 174
// RVA: 0x130780
void __fastcall SSDataInstance::pool_delete(SSDataInstance *this)
{
  SSDataInstance *v1; // rbx
  AObjReusePool<SSDataInstance> *v2; // rax
  AObjBlock<SSDataInstance> *v3; // rcx
  unsigned __int64 v4; // r9
  __int64 v5; // rdx
  APArray<SSDataInstance,SSDataInstance,ACompareAddress<SSDataInstance> > *v6; // rcx

  v1 = this;
  SSData::empty_table(&this->i_data);
  v1->i_ptr_id = 0;
  v2 = SSDataInstance::get_pool();
  v3 = v2->i_block_p;
  v4 = (unsigned __int64)v3->i_objects_a;
  if ( (unsigned __int64)v1 < v4 || (v5 = v3->i_size, v6 = &v2->i_pool, (unsigned __int64)v1 >= v4 + 72 * v5) )
    v6 = &v2->i_exp_pool;
  APArray<SSDataInstance,SSDataInstance,ACompareAddress<SSDataInstance>>::append(v6, v1);
}

// File Line: 193
// RVA: 0x118B10
AObjReusePool<SSDataInstance> *__fastcall SSDataInstance::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSDataInstance **v2; // rax

  if ( _S4_3 & 1 )
    return &s_pool_0;
  _S4_3 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_data_instance;
  v1 = Skookum::get_lib_vals()->i_pool_init_data_instance;
  s_pool_0.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175B68 = 0i64;
  unk_142175B70 = 0;
  if ( v1 )
  {
    unk_142175B70 = v1;
    v2 = APArrayBase<SSDataInstance>::alloc_array(v1);
  }
  else
  {
    unk_142175B70 = 0;
    v2 = (SSDataInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175B68 = v2;
  qword_142175B78 = 0i64;
  unk_142175B80 = 0;
  qword_142175B88 = 0i64;
  unk_142175B90 = 0;
  stru_142175B98.i_count = 0;
  stru_142175B98.i_array_p = 0i64;
  stru_142175B98.i_size = 0;
  unk_142175BB0 = v0;
  AObjReusePool<SSDataInstance>::append_block(&s_pool_0, v1);
  atexit(SSDataInstance::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_0;
}

