// File Line: 15
// RVA: 0x146DB20
__int64 UFG::Editor::_dynamic_initializer_for__gSelectionChangedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gSelectionChangedChannel, 0x245A7FF5u, 0i64, 0i64);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gSelectionChangedChannel__);
}

// File Line: 28
// RVA: 0x2087D0
void __fastcall UFG::Editor::SelectionSet::DispatchChangedEvent(UFG::Editor::SelectionSet *this)
{
  UFG::Editor::SelectionSet *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::Event *v3; // rdx
  UFG::allocator::free_link *v4; // rax

  v1 = this;
  v2 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
  v3 = (UFG::Event *)v2;
  if ( v2 )
  {
    v4 = v2 + 1;
    v4->mNext = v4;
    v4[1].mNext = v4;
    v3->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v3->m_EventUID = 609910773;
    v3->m_NamePTR = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  v3->mUserData0 = (unsigned __int64)v1;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v3);
}

// File Line: 46
// RVA: 0x2049E0
void __fastcall UFG::Editor::SelectionSet::Add(UFG::Editor::SelectionSet *this, UFG::Editor::SelectionSet *set)
{
  UFG::Editor::SelectionSet *v2; // r15
  UFG::Editor::SelectionSet *v3; // r13
  char v4; // di
  unsigned int v5; // ebp
  signed __int64 v6; // rbx
  UFG::Editor::DAGPath *v7; // rdi
  __int64 v8; // r14
  unsigned int v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // edx
  signed __int64 v12; // rbx
  UFG::Editor::SmartHandleObject *v13; // rcx
  signed __int64 *v14; // rcx
  signed __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::Event *v17; // rdx
  UFG::allocator::free_link *v18; // rax

  v2 = set;
  v3 = this;
  v4 = 0;
  v5 = 0;
  if ( set->mDAGPaths.size )
  {
    do
    {
      v6 = v5;
      if ( UFG::qArray<UFG::Editor::DAGPath,0>::Find(&v3->mDAGPaths, &v2->mDAGPaths.p[v6]) <= -1 )
      {
        v7 = &v2->mDAGPaths.p[v6];
        v8 = v3->mDAGPaths.size;
        v9 = v8 + 1;
        v10 = v3->mDAGPaths.capacity;
        if ( (signed int)v8 + 1 > v10 )
        {
          if ( v10 )
            v11 = 2 * v10;
          else
            v11 = 1;
          for ( ; v11 < v9; v11 *= 2 )
            ;
          if ( v11 - v9 > 0x10000 )
            v11 = v8 + 65537;
          UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&v3->mDAGPaths, v11, "qArray.Add");
        }
        v3->mDAGPaths.size = v9;
        v12 = (signed __int64)&v3->mDAGPaths.p[v8];
        if ( v7 != (UFG::Editor::DAGPath *)v12 )
        {
          UFG::Editor::DAGPath::Clear(&v3->mDAGPaths.p[v8]);
          if ( !*(_DWORD *)(v12 + 80) )
          {
            v13 = v7->mFnObject.mPtr;
            if ( !*(_QWORD *)(v12 + 16) )
            {
              if ( v13 )
              {
                *(_DWORD *)(v12 + 24) = v13->mTypeId;
                *(_QWORD *)(v12 + 16) = v13;
                v14 = (signed __int64 *)&v13->mSmartHandleList;
                v15 = *v14;
                *(_QWORD *)(v15 + 8) = v12;
                *(_QWORD *)v12 = v15;
                *(_QWORD *)(v12 + 8) = v14;
                *v14 = v12;
              }
            }
          }
          *(_DWORD *)(v12 + 32) = v7->mSystemName.mUID;
          UFG::qArray<UFG::qSymbol,0>::Clone(&v7->mElements, (UFG::qArray<UFG::qSymbol,0> *)(v12 + 40));
          *(_DWORD *)(v12 + 56) = v7->mInterfaceName.mUID;
          UFG::qArray<UFG::qString,0>::Clone(&v7->mSubElements, (UFG::qArray<UFG::qString,0> *)(v12 + 64));
        }
        v4 = 1;
      }
      ++v5;
    }
    while ( v5 < v2->mDAGPaths.size );
    if ( v4 )
    {
      v16 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
      v17 = (UFG::Event *)v16;
      if ( v16 )
      {
        v18 = v16 + 1;
        v18->mNext = v18;
        v18[1].mNext = v18;
        v17->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v17->m_EventUID = 609910773;
        v17->m_NamePTR = 0i64;
      }
      else
      {
        v17 = 0i64;
      }
      v17->mUserData0 = (unsigned __int64)v3;
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v17);
    }
  }
}

// File Line: 116
// RVA: 0x146E740
__int64 UFG::Editor::SelectionManager::_dynamic_initializer_for__mSelectionSets__()
{
  return atexit(UFG::Editor::SelectionManager::_dynamic_atexit_destructor_for__mSelectionSets__);
}

