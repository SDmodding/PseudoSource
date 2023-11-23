// File Line: 74
// RVA: 0x1974B0
UFG::DUISurface *__fastcall UFG::DUIManager::CreateWindowInternal(
        UFG::DUIManager *this,
        const char *type_name,
        const char *surface_name,
        const char *group_tag)
{
  UFG::DUISurface *Surface; // rax
  UFG::DUISurface *v9; // r15
  DNA::DNAFactory *v10; // rax
  UFG::DUIWindow *Object; // rbp
  const char *v12; // rsi
  unsigned int v13; // ebx
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF

  Surface = UFG::DUIManager::GetSurface(this, surface_name);
  v9 = Surface;
  if ( Surface )
  {
    UFG::qString::FormatEx(&result, "%s|%s", surface_name, type_name);
    v10 = DNA::DNAFactory::Instance();
    Object = (UFG::DUIWindow *)DNA::DNAFactory::CreateObject(v10, type_name, result.mData);
    v12 = &customCaption;
    if ( group_tag )
      v12 = group_tag;
    v13 = UFG::qStringLength(v12) + 1;
    UFG::qReflectArray<char>::Resize(&Object->mGroupTag.mText, v13, "qReflectString::Set()");
    UFG::qMemCopy(Object->mGroupTag.mText.mData.mItems, v12, v13);
    UFG::DUIManager::ShowWindow(this, Object, v9, 0);
    UFG::qString::~qString(&result);
    return (UFG::DUISurface *)Object;
  }
  return Surface;
}

// File Line: 153
// RVA: 0x198DD0
UFG::qNode<UFG::DUISurface,UFG::DUISurface> **__fastcall UFG::DUIManager::GetSurface(
        UFG::DUIManager *this,
        const char *surface_name)
{
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **p_mNext; // rdi
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **v4; // rbx

  if ( surface_name && *surface_name )
  {
    p_mNext = &this->mWindows.mNode.mNext;
    v4 = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **)&this->mSurfaces.mNode.mNext[-1].mNext;
    if ( v4 == &this->mWindows.mNode.mNext )
    {
      return 0i64;
    }
    else
    {
      while ( (unsigned int)UFG::qStringCompare((const char *)v4[8], surface_name, -1) )
      {
        v4 = &v4[2][-1].mNext;
        if ( v4 == p_mNext )
          return 0i64;
      }
      return (UFG::qNode<UFG::DUISurface,UFG::DUISurface> **)v4;
    }
  }
  else if ( (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **)&this->mSurfaces.mNode.mNext[-1].mNext == &this->mWindows.mNode.mNext )
  {
    return 0i64;
  }
  else
  {
    return &this->mSurfaces.mNode.mNext[-1].mNext;
  }
}

// File Line: 195
// RVA: 0x197620
void __fastcall UFG::DUIManager::DisableGroup(UFG::DUIManager *this, const char *group)
{
  UFG::qString *GroupData; // rax
  UFG::qString *v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx

  GroupData = UFG::DUIManager::GetGroupData(this, group);
  v3 = GroupData;
  if ( GroupData )
  {
    mNext = GroupData->mNext;
    mPrev = GroupData->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    GroupData->mPrev = GroupData;
    GroupData->mNext = GroupData;
    UFG::qString::~qString(GroupData);
    operator delete[](v3);
  }
}

// File Line: 214
// RVA: 0x1988C0
UFG::qString *__fastcall UFG::DUIManager::GetGroupData(UFG::DUIManager *this, const char *group)
{
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mActiveGroups; // rdi

  mNext = this->mActiveGroups.mNode.mNext;
  p_mActiveGroups = &this->mActiveGroups;
  if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&this->mActiveGroups )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompare((const char *)mNext[1].mNext, group, -1) )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)p_mActiveGroups )
      return 0i64;
  }
  return (UFG::qString *)mNext;
}

// File Line: 251
// RVA: 0x19DEB0
void __fastcall UFG::DUIManager::ShowWindow(
        UFG::DUIManager *this,
        UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *window,
        UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *surface,
        bool modal)
{
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *v8; // rdi
  int v9; // ebp
  UFG::qString *v10; // rax
  unsigned __int64 v11; // rbx
  UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *mPrev; // rax
  UFG::qList<UFG::DUIWindow,UFG::DUIManager,1,0> *p_mWindows; // rdx
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **p_mNext; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v15; // rax
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF

  LOBYTE(window[16].mNext) = modal;
  LOBYTE(window[9].mNext) = 1;
  BYTE2(window[10].mNext) = 1;
  if ( !surface || window[19].mNext != surface )
  {
    v7 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v8 = (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)v7;
    if ( v7 )
    {
      v7->mNext = v7;
      v7[1].mNext = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v8[1].mPrev = window;
    v8[1].mNext = surface;
    v9 = -1;
    if ( window->mNext == (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)-1i64 )
    {
      v10 = UFG::qString::FormatEx(&result, this->mUniqueWindowIDKey.mData, --this->mNextWindowIndex);
      v11 = UFG::qStringHash64(v10->mData, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qString::~qString(&result);
      window->mNext = (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)v11;
    }
    mPrev = this->mWindowsToShow.mNode.mPrev;
    mPrev->mNext = v8;
    v8->mPrev = mPrev;
    v8->mNext = &this->mWindowsToShow.mNode;
    this->mWindowsToShow.mNode.mPrev = v8;
    p_mWindows = &this->mWindows;
    p_mNext = &this->mWindows.mNode.mNext[-8].mNext;
    if ( p_mNext == (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **)&this->mTheme.mColour[15].b )
      goto LABEL_13;
    while ( 1 )
    {
      ++v9;
      if ( p_mNext == (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **)window )
        break;
      p_mNext = &p_mNext[16][-8].mNext;
      if ( p_mNext == (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **)&this->mTheme.mColour[15].b )
        goto LABEL_13;
    }
    if ( v9 == -1 )
    {
LABEL_13:
      v15 = p_mWindows->mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&window[7].mNext;
      window[7].mNext = (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)v15;
      window[8].mPrev = (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)p_mWindows;
      p_mWindows->mNode.mPrev = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&window[7].mNext;
    }
  }
}

// File Line: 349
// RVA: 0x197600
char __fastcall UFG::DUIManager::DestroyWindow(UFG::DUIManager *this, UFG::DUIWindow *window)
{
  if ( window->mMarkedToDestroy )
    return 0;
  window->mMarkedToDestroy = 1;
  return 1;
}

