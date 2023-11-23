// File Line: 15
// RVA: 0x146DB20
__int64 UFG::Editor::_dynamic_initializer_for__gSelectionChangedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gSelectionChangedChannel, 0x245A7FF5u, 0i64, 0i64);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gSelectionChangedChannel__);
}

// File Line: 28
// RVA: 0x2087D0
void __fastcall UFG::Editor::SelectionSet::DispatchChangedEvent(UFG::Editor::SelectionSet *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::Event *v3; // rdx
  UFG::allocator::free_link *v4; // rax

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
  v3->mUserData0 = (unsigned __int64)this;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v3);
}

// File Line: 46
// RVA: 0x2049E0
void __fastcall UFG::Editor::SelectionSet::Add(UFG::Editor::SelectionSet *this, UFG::Editor::SelectionSet *set)
{
  char v4; // di
  unsigned int v5; // ebp
  __int64 v6; // rbx
  UFG::Editor::DAGPath *v7; // rdi
  __int64 size; // r14
  unsigned int v9; // ebx
  unsigned int capacity; // edx
  unsigned int v11; // edx
  UFG::Editor::DAGPath *v12; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::Event *v17; // rdx
  UFG::allocator::free_link *v18; // rax

  v4 = 0;
  v5 = 0;
  if ( set->mDAGPaths.size )
  {
    do
    {
      v6 = v5;
      if ( UFG::qArray<UFG::Editor::DAGPath,0>::Find(&this->mDAGPaths, &set->mDAGPaths.p[v6]) <= -1 )
      {
        v7 = &set->mDAGPaths.p[v6];
        size = this->mDAGPaths.size;
        v9 = size + 1;
        capacity = this->mDAGPaths.capacity;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v11 = 2 * capacity;
          else
            v11 = 1;
          for ( ; v11 < v9; v11 *= 2 )
            ;
          if ( v11 - v9 > 0x10000 )
            v11 = size + 65537;
          UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&this->mDAGPaths, v11, "qArray.Add");
        }
        this->mDAGPaths.size = v9;
        v12 = &this->mDAGPaths.p[size];
        if ( v7 != v12 )
        {
          UFG::Editor::DAGPath::Clear(&this->mDAGPaths.p[size]);
          if ( v12->mPathType == Default )
          {
            mPtr = v7->mFnObject.mPtr;
            if ( !v12->mFnObject.mPtr )
            {
              if ( mPtr )
              {
                v12->mFnObject.mTypeId = mPtr->mTypeId;
                v12->mFnObject.mPtr = mPtr;
                p_mNode = &mPtr->mSmartHandleList.mNode;
                mPrev = p_mNode->mPrev;
                mPrev->mNext = &v12->mFnObject;
                v12->mFnObject.mPrev = mPrev;
                v12->mFnObject.mNext = p_mNode;
                p_mNode->mPrev = &v12->mFnObject;
              }
            }
          }
          v12->mSystemName.mUID = v7->mSystemName.mUID;
          UFG::qArray<UFG::qSymbol,0>::Clone(&v7->mElements, &v12->mElements);
          v12->mInterfaceName.mUID = v7->mInterfaceName.mUID;
          UFG::qArray<UFG::qString,0>::Clone(&v7->mSubElements, &v12->mSubElements);
        }
        v4 = 1;
      }
      ++v5;
    }
    while ( v5 < set->mDAGPaths.size );
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
      v17->mUserData0 = (unsigned __int64)this;
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v17);
    }
  }
}

// File Line: 116
// RVA: 0x146E740
__int64 UFG::Editor::SelectionManager::_dynamic_initializer_for__mSelectionSets__()
{
  return atexit((int (__fastcall *)())UFG::Editor::SelectionManager::_dynamic_atexit_destructor_for__mSelectionSets__);
}

