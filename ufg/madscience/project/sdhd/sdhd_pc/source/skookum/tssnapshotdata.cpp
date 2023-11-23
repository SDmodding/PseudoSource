// File Line: 39
// RVA: 0x4D68B0
void UFG::TSSnapshotData::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]
  ASymbol rebindl; // [rsp+20h] [rbp-18h]
  ASymbol rebindm; // [rsp+20h] [rbp-18h]
  ASymbol rebindn; // [rsp+20h] [rbp-18h]
  ASymbol rebindo; // [rsp+20h] [rbp-18h]
  ASymbol rebindp; // [rsp+20h] [rbp-18h]
  ASymbol rebindq; // [rsp+20h] [rbp-18h]
  ASymbol rebindr; // [rsp+20h] [rbp-18h]
  ASymbol rebinds; // [rsp+20h] [rbp-18h]
  ASymbol rebindt; // [rsp+20h] [rbp-18h]
  ASymbol rebindu; // [rsp+20h] [rbp-18h]
  ASymbol rebindv; // [rsp+20h] [rbp-18h]
  ASymbol rebindw; // [rsp+20h] [rbp-18h]
  ASymbol rebindx; // [rsp+20h] [rbp-18h]
  ASymbol rebindy; // [rsp+20h] [rbp-18h]
  ASymbol rebindz; // [rsp+20h] [rbp-18h]
  ASymbol rebindba; // [rsp+20h] [rbp-18h]
  ASymbol rebindbb; // [rsp+20h] [rbp-18h]
  ASymbol rebindbc; // [rsp+20h] [rbp-18h]
  ASymbol rebindbd; // [rsp+20h] [rbp-18h]
  ASymbol rebindbe; // [rsp+20h] [rbp-18h]
  ASymbol rebindbf; // [rsp+20h] [rbp-18h]
  ASymbol rebindbg; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("SnapshotData");
  SSClass::register_method_func(v0, "get_id", UFG::TSSnapshotData::MthdC_get_id, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "get_bool", UFG::TSSnapshotData::MthdC_get_bool, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "get_integer", UFG::TSSnapshotData::MthdC_get_integer, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "get_real", UFG::TSSnapshotData::MthdC_get_real, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "get_ranged_integer_current",
    UFG::TSSnapshotData::MthdC_get_ranged_integer_current,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "get_ranged_integer_max",
    UFG::TSSnapshotData::MthdC_get_ranged_integer_max,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "get_ranged_real_current",
    UFG::TSSnapshotData::MthdC_get_ranged_real_current,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "get_ranged_real_max", UFG::TSSnapshotData::MthdC_get_ranged_real_max, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "get_mapped_bool", UFG::TSSnapshotData::MthdC_get_mapped_bool, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "get_mapped_bool_count",
    UFG::TSSnapshotData::MthdC_get_mapped_bool_count,
    1,
    rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "get_mapped_bool_list", UFG::TSSnapshotData::MthdC_get_mapped_bool_list, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(v0, "get_mapped_integer", UFG::TSSnapshotData::MthdC_get_mapped_integer, 1, rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(v0, "get_mapped_real", UFG::TSSnapshotData::MthdC_get_mapped_real, 1, rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "get_mapped_id", UFG::TSSnapshotData::MthdC_get_mapped_id, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(v0, "set_id", UFG::TSSnapshotData::MthdC_set_id, 1, rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(v0, "set_bool", UFG::TSSnapshotData::MthdC_set_bool, 1, rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(v0, "set_integer", UFG::TSSnapshotData::MthdC_set_integer, 1, rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(v0, "set_real", UFG::TSSnapshotData::MthdC_set_real, 1, rebindq);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_ranged_integer_current",
    UFG::TSSnapshotData::MthdC_set_ranged_integer_current,
    1,
    rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_ranged_integer_max",
    UFG::TSSnapshotData::MthdC_set_ranged_integer_max,
    1,
    rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_ranged_real_current",
    UFG::TSSnapshotData::MthdC_set_ranged_real_current,
    1,
    rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(v0, "set_ranged_real_max", UFG::TSSnapshotData::MthdC_set_ranged_real_max, 1, rebindu);
  LOBYTE(rebindv.i_uid) = 0;
  SSClass::register_method_func(v0, "set_mapped_bool", UFG::TSSnapshotData::MthdC_set_mapped_bool, 1, rebindv);
  LOBYTE(rebindw.i_uid) = 0;
  SSClass::register_method_func(v0, "set_mapped_integer", UFG::TSSnapshotData::MthdC_set_mapped_integer, 1, rebindw);
  LOBYTE(rebindx.i_uid) = 0;
  SSClass::register_method_func(v0, "set_mapped_real", UFG::TSSnapshotData::MthdC_set_mapped_real, 1, rebindx);
  LOBYTE(rebindy.i_uid) = 0;
  SSClass::register_method_func(v0, "set_mapped_id", UFG::TSSnapshotData::MthdC_set_mapped_integer, 1, rebindy);
  LOBYTE(rebindz.i_uid) = 0;
  SSClass::register_method_func(v0, "apply_delta_integer", UFG::TSSnapshotData::MthdC_apply_delta_integer, 1, rebindz);
  LOBYTE(rebindba.i_uid) = 0;
  SSClass::register_method_func(v0, "apply_delta_real", UFG::TSSnapshotData::MthdC_apply_delta_real, 1, rebindba);
  LOBYTE(rebindbb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_integer_current",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_current,
    1,
    rebindbb);
  LOBYTE(rebindbc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_integer_max",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_max,
    1,
    rebindbc);
  LOBYTE(rebindbd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_real_current",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_current,
    1,
    rebindbd);
  LOBYTE(rebindbe.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "apply_delta_ranged_real_max",
    UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_max,
    1,
    rebindbe);
  LOBYTE(rebindbf.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "apply_delta_mapped_integer",
    UFG::TSSnapshotData::MthdC_apply_delta_mapped_integer,
    1,
    rebindbf);
  LOBYTE(rebindbg.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "apply_delta_mapped_real",
    UFG::TSSnapshotData::MthdC_apply_delta_mapped_real,
    1,
    rebindbg);
}

// File Line: 81
// RVA: 0x4E7980
void __fastcall UFG::TSSnapshotData::MthdC_get_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::IDStat IDStatEnum; // edi
  UFG::GameStatTracker *v4; // rax
  ASymbol *null; // rax

  if ( ppResult )
  {
    IDStatEnum = UFG::GameStat::GetIDStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
    if ( IDStatEnum == Num_ID_Stats )
    {
      null = ASymbol::get_null();
    }
    else
    {
      v4 = UFG::GameStatTracker::Instance();
      null = (ASymbol *)UFG::GameStatTracker::GetStat(v4, IDStatEnum);
    }
    *ppResult = SSSymbol::as_instance(null);
  }
}

// File Line: 99
// RVA: 0x4E7270
void __fastcall UFG::TSSnapshotData::MthdC_get_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::BoolStat BoolStatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  bool Stat; // al

  if ( ppResult )
  {
    BoolStatEnum = (unsigned int)UFG::GameStat::GetBoolStatEnum(
                                   (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                   1);
    v4 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v4, BoolStatEnum);
    *ppResult = SSBoolean::pool_new(Stat);
  }
}

// File Line: 110
// RVA: 0x4E7A60
void __fastcall UFG::TSSnapshotData::MthdC_get_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::Int32Stat Int32StatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  unsigned int Stat; // eax

  if ( ppResult )
  {
    Int32StatEnum = (unsigned int)UFG::GameStat::GetInt32StatEnum(
                                    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                    1);
    v4 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v4, Int32StatEnum);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Stat);
  }
}

// File Line: 121
// RVA: 0x4E8890
void __fastcall UFG::TSSnapshotData::MthdC_get_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::FloatStat FloatStatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    FloatStatEnum = (unsigned int)UFG::GameStat::GetFloatStatEnum(
                                    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                    1);
    v4 = UFG::GameStatTracker::Instance();
    user_data = UFG::GameStatTracker::GetStat(v4, FloatStatEnum);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 132
// RVA: 0x4E8710
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_integer_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::Int32RangedStat Int32RangedStatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  unsigned int Stat; // eax

  if ( ppResult )
  {
    Int32RangedStatEnum = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                          1);
    v4 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v4, Int32RangedStatEnum);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Stat);
  }
}

// File Line: 143
// RVA: 0x4E8770
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_integer_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::Int32RangedStat Int32RangedStatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  unsigned int StatRange; // eax

  if ( ppResult )
  {
    Int32RangedStatEnum = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                          1);
    v4 = UFG::GameStatTracker::Instance();
    StatRange = UFG::GameStatTracker::GetStatRange(v4, Int32RangedStatEnum);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, StatRange);
  }
}

// File Line: 154
// RVA: 0x4E87D0
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_real_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  BOOL FloatRangedStatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    FloatRangedStatEnum = UFG::GameStat::GetFloatRangedStatEnum(
                            (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                            1);
    v4 = UFG::GameStatTracker::Instance();
    user_data = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::FloatRangedStat)FloatRangedStatEnum);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 165
// RVA: 0x4E8830
void __fastcall UFG::TSSnapshotData::MthdC_get_ranged_real_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  BOOL FloatRangedStatEnum; // ebx
  UFG::GameStatTracker *v4; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    FloatRangedStatEnum = UFG::GameStat::GetFloatRangedStatEnum(
                            (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                            1);
    v4 = UFG::GameStatTracker::Instance();
    user_data = UFG::GameStatTracker::GetStatRange(v4, (UFG::GameStat::FloatRangedStat)FloatRangedStatEnum);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 176
// RVA: 0x4E7D50
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  bool Stat; // al
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(
                                      (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                      1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v5, MapBoolStatEnum, &name);
    *ppResult = SSBoolean::pool_new(Stat);
  }
}

// File Line: 188
// RVA: 0x4E7DD0
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_bool_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // edi
  unsigned int Count; // eax
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    Count = -1;
    if ( MapBoolStatEnum )
    {
      v5 = UFG::GameStatTracker::Instance();
      MapBool = UFG::GameStatTracker::GetMapBool(v5, MapBoolStatEnum);
      Count = UFG::PersistentData::MapBool::GetCount(MapBool);
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Count);
  }
}

// File Line: 205
// RVA: 0x4E7E40
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_bool_list(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSList *v3; // rdi
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapFloat *MapBool; // rax
  SSInstance *v7; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol name; // [rsp+68h] [rbp+10h] BYREF
  SSList *sym; // [rsp+70h] [rbp+18h] BYREF

  if ( ppResult )
  {
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
    MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( MapBoolStatEnum )
    {
      v5 = UFG::GameStatTracker::Instance();
      MapBool = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(v5, MapBoolStatEnum);
      UFG::PersistentData::MapInt::GetIterator(MapBool, &result);
      while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&result) )
      {
        LODWORD(sym) = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&result)->mKey.mUID;
        v7 = SSSymbol::as_instance((ASymbol *)&sym);
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(&v3->i_items, v7);
        UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
      }
    }
    i_count = v3->i_items.i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v3->i_items.i_array_p;
      for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *ppResult = SSList::as_instance(v3);
  }
}

// File Line: 230
// RVA: 0x4E8010
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  unsigned int Stat; // eax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                       1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v5, MapInt32StatEnum, &name);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Stat);
  }
}

// File Line: 242
// RVA: 0x4E8090
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapFloatStat MapFloatStatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  unsigned __int64 user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    MapFloatStatEnum = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(
                                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                       1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    LODWORD(user_data) = UFG::GameStatTracker::GetStat(v5, MapFloatStatEnum, &name);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)user_data);
  }
}

// File Line: 254
// RVA: 0x4E7F80
void __fastcall UFG::TSSnapshotData::MthdC_get_mapped_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  unsigned int Stat; // eax
  ASymbol *v7; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                       1);
    name.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
    v5 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v5, MapInt32StatEnum, &name);
    v7 = (ASymbol *)UFG::qSymbol::qSymbol(&result, Stat);
    *ppResult = SSSymbol::as_instance(v7);
  }
}

// File Line: 266
// RVA: 0x4EE0E0
void __fastcall UFG::TSSnapshotData::MthdC_set_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::IDStat IDStatEnum; // edi
  UFG::qSymbol *v4; // rbx
  UFG::GameStatTracker *v5; // rax

  IDStatEnum = UFG::GameStat::GetIDStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
  v4 = *(UFG::qSymbol **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, IDStatEnum, v4 + 8);
}

// File Line: 272
// RVA: 0x4ED440
void __fastcall UFG::TSSnapshotData::MthdC_set_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::BoolStat BoolStatEnum; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  BoolStatEnum = (unsigned int)UFG::GameStat::GetBoolStatEnum(
                                 (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                 1);
  LOBYTE(v2) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64;
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, BoolStatEnum, (bool)v2);
}

// File Line: 278
// RVA: 0x4EE1A0
void __fastcall UFG::TSSnapshotData::MthdC_set_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::Int32Stat Int32StatEnum; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  Int32StatEnum = (unsigned int)UFG::GameStat::GetInt32StatEnum(
                                  (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                  1);
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, Int32StatEnum, *(_DWORD *)(v4 + 32));
}

// File Line: 284
// RVA: 0x4EE8F0
void __fastcall UFG::TSSnapshotData::MthdC_set_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::FloatStat FloatStatEnum; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  FloatStatEnum = (unsigned int)UFG::GameStat::GetFloatStatEnum(
                                  (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                  1);
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, FloatStatEnum, *(float *)(v4 + 32));
}

// File Line: 290
// RVA: 0x4EE7B0
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_integer_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::Int32RangedStat Int32RangedStatEnum; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  Int32RangedStatEnum = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                                        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                        1);
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, Int32RangedStatEnum, *(_DWORD *)(v4 + 32));
}

// File Line: 296
// RVA: 0x4EE800
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_integer_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int Int32RangedStatEnum; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  Int32RangedStatEnum = UFG::GameStat::GetInt32RangedStatEnum(
                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                          1);
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatRange(v5, Int32RangedStatEnum, *(_DWORD *)(v4 + 32));
}

// File Line: 302
// RVA: 0x4EE850
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_real_current(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int FloatRangedStatEnum; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  FloatRangedStatEnum = UFG::GameStat::GetFloatRangedStatEnum(
                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                          1);
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, FloatRangedStatEnum, *(float *)(v4 + 32));
}

// File Line: 308
// RVA: 0x4EE8A0
void __fastcall UFG::TSSnapshotData::MthdC_set_ranged_real_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int FloatRangedStatEnum; // edi
  __int64 v4; // rbx
  UFG::GameStatTracker *v5; // rax

  FloatRangedStatEnum = UFG::GameStat::GetFloatRangedStatEnum(
                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                          1);
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatRange(v5, FloatRangedStatEnum, *(float *)(v4 + 32));
}

// File Line: 314
// RVA: 0x4EE2F0
void __fastcall UFG::TSSnapshotData::MthdC_set_mapped_bool(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // eax
  SSData **i_array_p; // r8
  UFG::GameStat::MapBoolStat v5; // edi
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  v2 = pScope;
  MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(
                                    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                    1);
  i_array_p = v2->i_data.i_array_p;
  v5 = MapBoolStatEnum;
  name.mUID = i_array_p[1]->i_data_p->i_user_data;
  LOBYTE(v2) = i_array_p[2]->i_data_p->i_user_data != 0;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v6, v5, &name, (bool)v2);
}

// File Line: 330
// RVA: 0x4EE360
void __fastcall UFG::TSSnapshotData::MthdC_set_mapped_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // eax
  SSData **i_array_p; // r8
  UFG::GameStat::MapInt32Stat v5; // edi
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  v2 = pScope;
  MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                                     (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                     1);
  i_array_p = v2->i_data.i_array_p;
  v5 = MapInt32StatEnum;
  name.mUID = i_array_p[1]->i_data_p->i_user_data;
  LODWORD(v2) = i_array_p[2]->i_data_p->i_user_data;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v6, v5, &name, (int)v2);
}

// File Line: 338
// RVA: 0x4EE3D0
void __fastcall UFG::TSSnapshotData::MthdC_set_mapped_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapFloatStat MapFloatStatEnum; // eax
  SSData **i_array_p; // r8
  UFG::GameStat::MapFloatStat v5; // edi
  float v6; // xmm6_4
  UFG::GameStatTracker *v7; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h] BYREF

  MapFloatStatEnum = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(
                                     (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                     1);
  i_array_p = pScope->i_data.i_array_p;
  v5 = MapFloatStatEnum;
  name.mUID = i_array_p[1]->i_data_p->i_user_data;
  v6 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, v5, &name, v6);
}

// File Line: 346
// RVA: 0x4E36D0
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32Stat Int32StatEnum; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  Int32StatEnum = (unsigned int)UFG::GameStat::GetInt32StatEnum(
                                  (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                  1);
  LODWORD(v2) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v4, Int32StatEnum, (int)v2);
}

// File Line: 353
// RVA: 0x4E3970
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::FloatStat FloatStatEnum; // ebx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // rax

  FloatStatEnum = (unsigned int)UFG::GameStat::GetFloatStatEnum(
                                  (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                  1);
  v4 = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v5, FloatStatEnum, v4);
}

// File Line: 360
// RVA: 0x4E3810
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_current(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::Int32RangedStat Int32RangedStatEnum; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  Int32RangedStatEnum = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(
                                        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                        1);
  LODWORD(v2) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v4, Int32RangedStatEnum, (int)v2);
}

// File Line: 367
// RVA: 0x4E3860
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_integer_max(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  int Int32RangedStatEnum; // edi
  UFG::GameStatTracker *v4; // rax

  v2 = pScope;
  Int32RangedStatEnum = UFG::GameStat::GetInt32RangedStatEnum(
                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                          1);
  LODWORD(v2) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDeltaRange(v4, Int32RangedStatEnum, (int)v2);
}

// File Line: 374
// RVA: 0x4E38B0
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_current(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  int FloatRangedStatEnum; // ebx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // rax

  FloatRangedStatEnum = UFG::GameStat::GetFloatRangedStatEnum(
                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                          1);
  v4 = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v5, FloatRangedStatEnum, v4);
}

// File Line: 381
// RVA: 0x4E3910
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_ranged_real_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int FloatRangedStatEnum; // ebx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // rax

  FloatRangedStatEnum = UFG::GameStat::GetFloatRangedStatEnum(
                          (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                          1);
  v4 = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDeltaRange(v5, FloatRangedStatEnum, v4);
}

// File Line: 388
// RVA: 0x4E3720
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_mapped_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // eax
  SSData **i_array_p; // r8
  UFG::GameStat::MapInt32Stat v5; // edi
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  v2 = pScope;
  MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(
                                     (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                     1);
  i_array_p = v2->i_data.i_array_p;
  v5 = MapInt32StatEnum;
  name.mUID = i_array_p[1]->i_data_p->i_user_data;
  LODWORD(v2) = i_array_p[2]->i_data_p->i_user_data;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v6, v5, &name, (int)v2);
}

// File Line: 396
// RVA: 0x4E3790
void __fastcall UFG::TSSnapshotData::MthdC_apply_delta_mapped_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapFloatStat MapFloatStatEnum; // eax
  SSData **i_array_p; // r8
  UFG::GameStat::MapFloatStat v5; // edi
  float v6; // xmm6_4
  UFG::GameStatTracker *v7; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h] BYREF

  MapFloatStatEnum = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(
                                     (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                                     1);
  i_array_p = pScope->i_data.i_array_p;
  v5 = MapFloatStatEnum;
  name.mUID = i_array_p[1]->i_data_p->i_user_data;
  v6 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v7, v5, &name, v6);
}

