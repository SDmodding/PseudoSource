// File Line: 12
// RVA: 0x155ECF0
__int64 dynamic_initializer_for__UFG::UELRuntime::msFragmentBindings__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::UELRuntime::msFragmentBindings.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UELRuntime::msFragmentBindings__);
}

// File Line: 13
// RVA: 0x155ED50
__int64 dynamic_initializer_for__UFG::UELRuntime::msParameterBindings__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::UELRuntime::msParameterBindings.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UELRuntime::msParameterBindings__);
}

// File Line: 14
// RVA: 0x155ECC0
__int64 dynamic_initializer_for__UFG::UELRuntime::msEnumBindings__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::UELRuntime::msEnumBindings.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UELRuntime::msEnumBindings__);
}

// File Line: 15
// RVA: 0x155ED20
__int64 dynamic_initializer_for__UFG::UELRuntime::msInvocableBindings__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::UELRuntime::msInvocableBindings.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UELRuntime::msInvocableBindings__);
}

// File Line: 20
// RVA: 0x5B7ED0
void __fastcall UFG::UELRuntime::Init(AMD_HD3D *a1)
{
  UEL::Runtime *v1; // rax

  _(a1);
  InitFunctions(&UFG::UELRuntime::msInvocableBindings);
  InitParameters(&UFG::UELRuntime::msParameterBindings);
  InitEnums(&UFG::UELRuntime::msEnumBindings);
  v1 = (UEL::Runtime *)UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
  if ( v1 )
  {
    v1->mFragmentBindings = &UFG::UELRuntime::msFragmentBindings;
    v1->mInvocableBindings = &UFG::UELRuntime::msInvocableBindings;
    v1->mParameterBindings = &UFG::UELRuntime::msParameterBindings;
    v1->mEnumBindings = &UFG::UELRuntime::msEnumBindings;
    UFG::UELRuntime::msRuntime = v1;
  }
  else
  {
    UFG::UELRuntime::msRuntime = 0i64;
  }
}

// File Line: 31
// RVA: 0x5BD450
void UFG::UELRuntime::Shutdown(void)
{
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v1; // rbx
  unsigned int i; // ebx

  while ( UFG::UELRuntime::msInvocableBindings.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::UELRuntime::msInvocableBindings);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::UELRuntime::msInvocableBindings,
      &Head->mNode);
    if ( Head )
    {
      `eh vector destructor iterator(&Head[1], 8ui64, 8, (void (__fastcall *)(void *))_);
      operator delete[](Head);
    }
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::DeleteAll(&UFG::UELRuntime::msParameterBindings);
  while ( UFG::UELRuntime::msEnumBindings.mTree.mCount )
  {
    v1 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::UELRuntime::msEnumBindings);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::UELRuntime::msEnumBindings,
      &v1->mNode);
    if ( v1 )
      operator delete[](v1);
  }
  operator delete[](UFG::UELRuntime::msRuntime);
  UFG::UELRuntime::msRuntime = 0i64;
  for ( i = 0; i < UEL::Value::msStringTable.size; ++i )
    operator delete[](UEL::Value::msStringTable.p[i]);
  if ( UEL::Value::msStringTable.p )
    operator delete[](UEL::Value::msStringTable.p);
  UEL::Value::msStringTable.p = 0i64;
  *(_QWORD *)&UEL::Value::msStringTable.size = 0i64;
}

// File Line: 48
// RVA: 0x5BD290
void __fastcall UFG::UELRuntime::SetFragmentTable(BinPtrArray<UEL::FragmentExpression,0,0> *table)
{
  unsigned int v2; // ebx
  UFG::allocator::free_link *v3; // rdx
  __int64 mOffset; // rax
  char *v5; // rcx
  __int64 v6; // r8
  char *v7; // rax
  __int64 v8; // rcx
  char *v9; // rcx
  __int64 v10; // rax
  char *v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  char *v14; // rax
  __int64 v15; // rax
  char *v16; // rax
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // r8
  int v20; // ecx
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *mFragmentBindings; // rdi
  Render::SkinningCacheNode *Head; // rbx
  int v23; // [rsp+50h] [rbp+8h]
  __int16 v24; // [rsp+58h] [rbp+10h] BYREF
  int v25; // [rsp+5Ch] [rbp+14h]
  UFG::allocator::free_link *v26; // [rsp+60h] [rbp+18h]
  __int16 *v27; // [rsp+68h] [rbp+20h]

  UFG::UELRuntime::FragmentTable = table;
  if ( table )
  {
    v2 = 0;
    if ( (table->mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v3 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
        v26 = v3;
        if ( v3 )
        {
          v27 = &v24;
          mOffset = table->mData.mOffset;
          if ( mOffset )
            v5 = (char *)&table->mData + mOffset;
          else
            v5 = 0i64;
          v6 = 8i64 * v2;
          v7 = &v5[v6];
          v8 = *(_QWORD *)&v5[v6];
          if ( v8 )
            v9 = &v7[v8];
          else
            v9 = 0i64;
          v24 = *((_WORD *)v9 + 6);
          v25 = *((_DWORD *)v9 + 4);
          v10 = table->mData.mOffset;
          if ( v10 )
            v11 = (char *)&table->mData + v10;
          else
            v11 = 0i64;
          v12 = &v11[v6];
          v13 = *(_QWORD *)&v11[v6];
          if ( v13 )
            v14 = &v12[v13];
          else
            v14 = 0i64;
          v23 = *((_DWORD *)v14 + 24);
          v15 = table->mData.mOffset;
          if ( v15 )
            v16 = (char *)&table->mData + v15;
          else
            v16 = 0i64;
          v17 = &v16[v6];
          v18 = *(_QWORD *)&v16[v6];
          v19 = &v17[v18];
          if ( !v18 )
            v19 = 0i64;
          v20 = *((_DWORD *)v19 + 25);
          v3->mNext = 0i64;
          v3[1].mNext = 0i64;
          v3[2].mNext = 0i64;
          LODWORD(v3[3].mNext) = v23;
          LODWORD(v3[4].mNext) = -1;
          BYTE4(v3[4].mNext) = v20;
          LODWORD(v3[5].mNext) = v2;
          WORD2(v3[5].mNext) = v24;
          LODWORD(v3[6].mNext) = v25;
        }
        else
        {
          v3 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&UFG::UELRuntime::msRuntime->mFragmentBindings->mTree, (UFG::qBaseNodeRB *)v3);
        ++v2;
      }
      while ( v2 < (table->mCount & 0x7FFFFFFFu) );
    }
  }
  else
  {
    mFragmentBindings = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)UFG::UELRuntime::msRuntime->mFragmentBindings;
    if ( UFG::UELRuntime::msRuntime->mFragmentBindings->mTree.mCount )
    {
      do
      {
        Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(mFragmentBindings);
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&mFragmentBindings->mTree, &Head->mNode);
        if ( Head )
          operator delete[](Head);
      }
      while ( mFragmentBindings->mTree.mCount );
    }
  }
}

