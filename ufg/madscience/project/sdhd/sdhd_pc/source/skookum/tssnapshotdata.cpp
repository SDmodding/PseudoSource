// File Line: 39
// RVA: 0x4D68B0
void UFG::TSSnapshotData::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("SnapshotData");
  SSClass::register_method_func(v0, "get_id", UFG::TSSnapshotData::MthdC_get_id, 1, 0);
  SSClass::register_method_func(v0, "get_bool", UFG::TSSnapshotData::MthdC_get_bool, 1, 0);
  SSClass::register_method_func(v0, "get_integer", UFG::TSSnapshotData::MthdC_get_integer, 1, 0);
  SSClass::register_method_func(v0, "get_real", UFG::TSSnapshotData::MthdC_get_real, 1, 0);
  SSClass::register_method_func(
    v0,
    "get_ranged_integer_current",
    UFG::TSSnapshotData::MthdC_get_ranged_integer_current,
    1,
    0);
  SSClass::register_method_func(v0, "get_ranged_integer_max", UFG::TSSnapshotData::MthdC_get_ranged_integer_max, 1, 0);
  SSClass::register_method_func(v0, "get_ranged_real_current", UFG::TSSnapshotData::MthdC_get_ranged_real_current, 1, 0);
  SSClass::register_method_func(v0, "get_ranged_real_max", UFG::TSSnapshotData::MthdC_get_ranged_real_max, 1, 0);
  SSClass::register_method_func(v0, "get_mapped_bool", UFG::TSSnapshotData::MthdC_get_mapped_bool, 1, 0);
  SSClass::register_method_func(v0, "get_mapped_bool_count", UFG::TSSnapshotData::MthdC_get_mapped_bool_count, 1, 0);
  SSClass::register_method_func(v0, "get_mapped_bool_list", UFG::TSSnapshotData::MthdC_get_mapped_bool_list, 1, 0);
  SSClass::register_method_func(v0, "get_mapped_integer", UFG::TSSnapshotData::MthdC_get_mapped_integer, 1, 0);
  SSClass::register_method_func(v0, "get_mapped_real", UFG::TSSnapshotData::MthdC_get_mapped_real, 1, 0);
  SSClass::register_method_func(v0, "get_mapped_id", UFG::TSSnapshotData::MthdC_get_mapped_id, 1, 0);
  SSClass::register_method_func(v0, "set_id", UFG::TSSnapshotData::MthdC_set_id, 1, 0);
  SSClass::register_method_func(v0, "set_bool", UFG::TSSnapshotData::MthdC_set_bool, 1, 0);
  SSClass::register_method_func(v0, "set_integer", UFG::TSSnapshotData::MthdC_set_integer, 1, 0);
  SSClass::register_method_func(v0, "set_real", UFG::TSSnapshotData::MthdC_set_real, 1, 0);
  SSClass::register_method_func(
    v0,
    "set_ranged_integer_current",
    UFG::TSSnapshotData::MthdC_set_ranged_integer_current,
    1,
    0);
  SSClass::register_method_func(v0, "set_ranged_integer_max", UFG::TSSnapshotData::MthdC_set_ranged_integer_max, 1, 0);
  SSClass::register_method_func(v0, "set_ranged_real_current", UFG::TSSnapshotData::MthdC_set_ranged_real_current, 1, 0);
  SSClass::register_method_func(v0, "set_ranged_real_max", UFG::TSSnapshotData::MthdC_set_ranged_real_max, 1, 0);
  SSClass::register_method_func(v0, "set_mapped_bool", UFG::TSSnapshotData::MthdC_set_mapped_bool, 1, 0);
  SSClass::register_method_func(v0, "set_mapped_integer", UFG::TSSnapshotData::MthdC_set_mapped_integer, 1, 0);
  SSClass::register_method_func(v0, "set_mapped_real", UFG::TSSnapshotData::MthdC_set_mapped_real, 1, 0);
  SSClass::register_method_func(v0, "set_mapped_id", UFG::TSSnapshotData::MthdC_set_mapped_integer, 1, 0);
  SSClass::register_method_func(v0, "apply_delta_integer", UFG::TSSnapshotData::MthdC_apply_delta_integer, 1, 0);
  SSClass::register_method_func(v0, "apply_delta_real", UFG::TSSnapshotData::MthdC_apply_delta_real, 1, 0);
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_integer_current",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_current,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_integer_max",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_max,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_real_current",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_current,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_real_max",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_max,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "apply_delta_mapped_integer",
    UFG::TSSnapshotData::MthdC_apply_delta_mapped_integer,
    1,
    0);
  SSClass::register_method_func(v0, "apply_delta_mapped_real", UFG::TSSnapshotData::MthdC_apply_delta_mapped_real, 1, 0);
}apped_real", UFG:

// File Line: 81
// RVA: 0x4E7980
void __fastcall UFG::TSSnapshotData::MthdC_get_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::GameStat::IDStat v3; // edi
  UFG::GameStatTracker *v4; // rax
  ASymbol *v5; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::GameStat::GetIDStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
    if ( v3 == 44 )
    {
      v5 = ASymbol::get_null();
    }
    else
    {
      v4 = UFG::GameStatTracker::Instance();
      v5 = (ASymbol *)UFG::GameStatTracker::GetStat(v4, v3);
    }
    *v2 = SSSymbol::as_instance(v5);
  }
}

// File Line: 99
// RVA: 0x4E7270
void __fastcall UFG::TSSnapshotData::MthdC_get_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::GameStat::BoolStat v3; // ebx
  UFG::GameStatTracker *v4; // rax
  bool v5; // al

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (unsigned int)UFG::GameStat::GetBoolStatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStat(v4, v3);
    *v2 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 110
// RVA: 0x4E7A60
void __fastcall UFG::TSSnapshotData::MthdC_get_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::GameStat::Int32Stat v3; // ebx
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (unsigned int)UFG::GameStat::GetInt32StatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStat(v4, v3);
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 121
// RVA: 0x4E8890
void __fastcall UFG::TSSnapshotData::MthdC_get_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::GameStat::FloatStat v3; // ebx
  UFG::GameStatTracker *v4; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (unsigned int)UFG::GameStat::GetFloatStatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    v4 = UFG::GameStatTracker::Instance();
    user_data = UFG::GameStatTracker::GetStat(v4, v3);
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 132
// RVA: 0x4E8710
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_integer_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::GameStat::Int32RangedStat v3; // ebx
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStat(v4, v3);
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 143
// RVA: 0x4E8770
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_integer_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::GameStat::Int32RangedStat v3; // ebx
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStatRange(v4, v3);
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 154
// RVA: 0x4E87D0
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_real_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::GameStat::GetFloatRangedStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
    v4 = UFG::GameStatTracker::Instance();
    user_data = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::FloatRangedStat)v3);
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 165
// RVA: 0x4E8830
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_real_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::GameStat::GetFloatRangedStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
    v4 = UFG::GameStatTracker::Instance();
    user_data = UFG::GameStatTracker::GetStatRange(v4, (UFG::GameStat::FloatRangedStat)v3);
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 176
// RVA: 0x4E7D50
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSInstance **v3; // rdi
  UFG::GameStat::MapBoolStat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  bool v6; // al
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope;
    v3 = ppResult;
    v4 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    v6 = UFG::GameStatTracker::GetStat(v5, v4, &name);
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 188
// RVA: 0x4E7DD0
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_bool_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::GameStat::MapBoolStat v3; // edi
  unsigned int v4; // eax
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapBool *v6; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    v4 = -1;
    if ( v3 )
    {
      v5 = UFG::GameStatTracker::Instance();
      v6 = UFG::GameStatTracker::GetMapBool(v5, v3);
      v4 = UFG::PersistentData::MapBool::GetCount(v6);
    }
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
  }
}

// File Line: 205
// RVA: 0x4E7E40
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_bool_list(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSList *v3; // rdi
  UFG::GameStat::MapBoolStat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapFloat *v6; // rax
  SSInstance *v7; // rax
  __int64 v8; // rax
  ARefCountMix<SSInstance> **v9; // rbx
  unsigned __int64 i; // rsi
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-30h]
  UFG::qSymbol name; // [rsp+68h] [rbp+10h]
  SSList *sym; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    sym = v3;
    if ( v3 )
    {
      v3->i_items.i_count = 0;
      v3->i_items.i_array_p = 0i64;
      v3->i_items.i_size = 0;
      v3->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v3 = 0i64;
    }
    v4 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( v4 )
    {
      v5 = UFG::GameStatTracker::Instance();
      v6 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(v5, v4);
      UFG::PersistentData::MapInt::GetIterator(v6, &result);
      while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&result) )
      {
        LODWORD(sym) = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&result)->mKey.mUID;
        v7 = SSSymbol::as_instance((ASymbol *)&sym);
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(&v3->i_items, v7);
        UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
      }
    }
    v8 = v3->i_items.i_count;
    if ( (_DWORD)v8 )
    {
      v9 = (ARefCountMix<SSInstance> **)v3->i_items.i_array_p;
      for ( i = (unsigned __int64)&v9[v8]; (unsigned __int64)v9 < i; ++v9 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v9 + 4);
    }
    *v2 = SSList::as_instance(v3);
  }
}

// File Line: 230
// RVA: 0x4E8010
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSInstance **v3; // rdi
  UFG::GameStat::MapInt32Stat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  unsigned int v6; // eax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope;
    v3 = ppResult;
    v4 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    v6 = UFG::GameStatTracker::GetStat(v5, v4, &name);
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 242
// RVA: 0x4E8090
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSInstance **v3; // rdi
  UFG::GameStat::MapFloatStat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  unsigned __int64 user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope;
    v3 = ppResult;
    v4 = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    LODWORD(user_data) = UFG::GameStatTracker::GetStat(v5, v4, &name);
    *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)user_data);
  }
}

// File Line: 254
// RVA: 0x4E7F80
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSInstance **v3; // rdi
  UFG::GameStat::MapInt32Stat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  unsigned int v6; // eax
  ASymbol *v7; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope;
    v3 = ppResult;
    v4 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    v6 = UFG::GameStatTracker::GetStat(v5, v4, &name);
    v7 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v6);
    *v3 = SSSymbol::as_instance(v7);
  }
}

// File Line: 266
// RVA: 0x4EE0E0
void __fastcall UFG::TSSnapshotData::MthdC_set_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::IDStat v3; // edi
  UFG::qSymbol *v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = UFG::GameStat::GetIDStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
  v4 = *(UFG::qSymbol **)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, v3, v4 + 8);
}

// File Line: 272
// RVA: 0x4ED440
void __fastcall UFG::TSSnapshotData::MthdC_set_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::BoolStat v3; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetBoolStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  LOBYTE(v2) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64;
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, v3, (bool)v2);
}

// File Line: 278
// RVA: 0x4EE1A0
void __fastcall UFG::TSSnapshotData::MthdC_set_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32Stat v3; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetInt32StatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, v3, *(_DWORD *)(v4 + 32));
}

// File Line: 284
// RVA: 0x4EE8F0
void __fastcall UFG::TSSnapshotData::MthdC_set_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::FloatStat v3; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetFloatStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, v3, *(float *)(v4 + 32));
}

// File Line: 290
// RVA: 0x4EE7B0
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_integer_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32RangedStat v3; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, v3, *(_DWORD *)(v4 + 32));
}

// File Line: 296
// RVA: 0x4EE800
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_integer_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32RangedStat v3; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatRange(v5, v3, *(_DWORD *)(v4 + 32));
}

// File Line: 302
// RVA: 0x4EE850
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_real_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  BOOL v3; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = UFG::GameStat::GetFloatRangedStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
  v4 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, (UFG::GameStat::FloatRangedStat)v3, *(float *)(v4 + 32));
}

// File Line: 308
// RVA: 0x4EE8A0
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_real_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  BOOL v3; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = UFG::GameStat::GetFloatRangedStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
  v4 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatRange(v5, (UFG::GameStat::FloatRangedStat)v3, *(float *)(v4 + 32));
}

// File Line: 314
// RVA: 0x4EE2F0
void __fastcall UFG::TSSnapshotData::MthdC_set_mapped_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapBoolStat v3; // eax
  SSData **v4; // r8
  UFG::GameStat::MapBoolStat v5; // edi
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = v2->i_data.i_array_p;
  v5 = v3;
  name.mUID = v4[1]->i_data_p->i_user_data;
  LOBYTE(v2) = v4[2]->i_data_p->i_user_data != 0;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v6, v5, &name, (bool)v2);
}

// File Line: 330
// RVA: 0x4EE360
void __fastcall UFG::TSSnapshotData::MthdC_set_mapped_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapInt32Stat v3; // eax
  SSData **v4; // r8
  UFG::GameStat::MapInt32Stat v5; // edi
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = v2->i_data.i_array_p;
  v5 = v3;
  name.mUID = v4[1]->i_data_p->i_user_data;
  LODWORD(v2) = v4[2]->i_data_p->i_user_data;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v6, v5, &name, (int)v2);
}

// File Line: 338
// RVA: 0x4EE3D0
void __fastcall UFG::TSSnapshotData::MthdC_set_mapped_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapFloatStat v3; // eax
  SSData **v4; // r8
  UFG::GameStat::MapFloatStat v5; // edi
  float v6; // xmm6_4
  UFG::GameStatTracker *v7; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = v2->i_data.i_array_p;
  v5 = v3;
  name.mUID = v4[1]->i_data_p->i_user_data;
  v6 = *(float *)&v4[2]->i_data_p->i_user_data;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, v5, &name, v6);
}

// File Line: 346
// RVA: 0x4E36D0
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32Stat v3; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetInt32StatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  LODWORD(v2) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v4, v3, (int)v2);
}

// File Line: 353
// RVA: 0x4E3970
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::GameStat::FloatStat v3; // ebx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetFloatStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v5, v3, v4);
}

// File Line: 360
// RVA: 0x4E3810
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32RangedStat v3; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  LODWORD(v2) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v4, v3, (int)v2);
}

// File Line: 367
// RVA: 0x4E3860
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32RangedStat v3; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  LODWORD(v2) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDeltaRange(v4, v3, (int)v2);
}

// File Line: 374
// RVA: 0x4E38B0
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  BOOL v3; // ebx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = UFG::GameStat::GetFloatRangedStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
  v4 = *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v5, (UFG::GameStat::FloatRangedStat)v3, v4);
}

// File Line: 381
// RVA: 0x4E3910
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  BOOL v3; // ebx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // rax

  v2 = pScope;
  v3 = UFG::GameStat::GetFloatRangedStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
  v4 = *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDeltaRange(v5, (UFG::GameStat::FloatRangedStat)v3, v4);
}

// File Line: 388
// RVA: 0x4E3720
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_mapped_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapInt32Stat v3; // eax
  SSData **v4; // r8
  UFG::GameStat::MapInt32Stat v5; // edi
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = v2->i_data.i_array_p;
  v5 = v3;
  name.mUID = v4[1]->i_data_p->i_user_data;
  LODWORD(v2) = v4[2]->i_data_p->i_user_data;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v6, v5, &name, (int)v2);
}

// File Line: 396
// RVA: 0x4E3790
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_mapped_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapFloatStat v3; // eax
  SSData **v4; // r8
  UFG::GameStat::MapFloatStat v5; // edi
  float v6; // xmm6_4
  UFG::GameStatTracker *v7; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]

  v2 = pScope;
  v3 = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(
                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                       1);
  v4 = v2->i_data.i_array_p;
  v5 = v3;
  name.mUID = v4[1]->i_data_p->i_user_data;
  v6 = *(float *)&v4[2]->i_data_p->i_user_data;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v7, v5, &name, v6);
}

