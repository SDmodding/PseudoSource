// File Line: 74
// RVA: 0x1974B0
UFG::DUISurface *__fastcall UFG::DUIManager::CreateWindowInternal(UFG::DUIManager *this, const char *type_name, const char *surface_name, const char *group_tag)
{
  const char *v4; // rdi
  const char *v5; // rbx
  const char *v6; // rsi
  UFG::DUIManager *v7; // r14
  UFG::DUISurface *v8; // rax
  UFG::DUISurface *v9; // r15
  DNA::DNAFactory *v10; // rax
  UFG::DUIWindow *v11; // rbp
  const char *v12; // rsi
  unsigned int v13; // ebx
  UFG::qString result; // [rsp+28h] [rbp-40h]

  v4 = group_tag;
  v5 = surface_name;
  v6 = type_name;
  v7 = this;
  v8 = UFG::DUIManager::GetSurface(this, surface_name);
  v9 = v8;
  if ( v8 )
  {
    UFG::qString::FormatEx(&result, "%s|%s", v5, v6, -2i64);
    v10 = DNA::DNAFactory::Instance();
    v11 = (UFG::DUIWindow *)DNA::DNAFactory::CreateObject(v10, v6, result.mData);
    v12 = &customWorldMapCaption;
    if ( v4 )
      v12 = v4;
    v13 = (unsigned __int64)UFG::qStringLength(v12) + 1;
    UFG::qReflectArray<char>::Resize(&v11->mGroupTag.mText, v13, "qReflectString::Set()");
    UFG::qMemCopy(v11->mGroupTag.mText.mData.mItems, v12, v13);
    UFG::DUIManager::ShowWindow(v7, v11, v9, 0);
    UFG::qString::~qString(&result);
    v8 = (UFG::DUISurface *)v11;
  }
  return v8;
}

// File Line: 153
// RVA: 0x198DD0
UFG::qNode<UFG::DUISurface,UFG::DUISurface> **__fastcall UFG::DUIManager::GetSurface(UFG::DUIManager *this, const char *surface_name)
{
  const char *v2; // rsi
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **v3; // rdi
  UFG::DUISurface *v4; // rbx
  UFG::qNode<UFG::DUISurface,UFG::DUISurface> **result; // rax

  v2 = surface_name;
  if ( surface_name && *surface_name )
  {
    v3 = &this->mWindows.mNode.mNext;
    v4 = (UFG::DUISurface *)&this->mSurfaces.mNode.mNext[-1].mNext;
    if ( v4 == (UFG::DUISurface *)&this->mWindows.mNode.mNext )
    {
LABEL_6:
      result = 0i64;
    }
    else
    {
      while ( (unsigned int)UFG::qStringCompare(v4->mName.mData, v2, -1) )
      {
        v4 = (UFG::DUISurface *)&v4->mNext[-1].mNext;
        if ( v4 == (UFG::DUISurface *)v3 )
          goto LABEL_6;
      }
      result = (UFG::qNode<UFG::DUISurface,UFG::DUISurface> **)v4;
    }
  }
  else if ( (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> **)&this->mSurfaces.mNode.mNext[-1].mNext == &this->mWindows.mNode.mNext )
  {
    result = 0i64;
  }
  else
  {
    result = &this->mSurfaces.mNode.mNext[-1].mNext;
  }
  return result;
}

// File Line: 195
// RVA: 0x197620
void __fastcall UFG::DUIManager::DisableGroup(UFG::DUIManager *this, const char *group)
{
  UFG::qString *v2; // rax
  UFG::qString *v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rdx

  v2 = UFG::DUIManager::GetGroupData(this, group);
  v3 = v2;
  if ( v2 )
  {
    v4 = v2->mNext;
    v5 = v2->mPrev;
    v5->mNext = v4;
    v4->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
    UFG::qString::~qString(v2);
    operator delete[](v3);
  }
}

// File Line: 214
// RVA: 0x1988C0
UFG::qNode<UFG::qString,UFG::qString> *__fastcall UFG::DUIManager::GetGroupData(UFG::DUIManager *this, const char *group)
{
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // rdi
  const char *v4; // rsi

  v2 = this->mActiveGroups.mNode.mNext;
  v3 = &this->mActiveGroups;
  v4 = group;
  if ( v2 == (UFG::qNode<UFG::qString,UFG::qString> *)&this->mActiveGroups )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompare((const char *)v2[1].mNext, v4, -1) )
  {
    v2 = v2->mNext;
    if ( v2 == (UFG::qNode<UFG::qString,UFG::qString> *)v3 )
      return 0i64;
  }
  return v2;
}

// File Line: 251
// RVA: 0x19DEB0
void __fastcall UFG::DUIManager::ShowWindow(UFG::DUIManager *this, UFG::DUIWindow *window, UFG::DUISurface *surface, bool modal)
{
  UFG::DUISurface *v4; // rbx
  UFG::DUIWindow *v5; // rsi
  UFG::DUIManager *v6; // r14
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  signed int v9; // ebp
  UFG::qString *v10; // rax
  unsigned __int64 v11; // rbx
  UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *v12; // rax
  UFG::qList<UFG::DUIWindow,UFG::DUIManager,1,0> *v13; // rdx
  signed __int64 v14; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v15; // rcx
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v16; // rax
  UFG::qString result; // [rsp+28h] [rbp-40h]

  v4 = surface;
  v5 = window;
  v6 = this;
  window->mIsModal = modal;
  window->mVisible = 1;
  window->mBringToFont = 1;
  if ( !surface || window->mSurface != surface )
  {
    v7 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v8 = v7;
    if ( v7 )
    {
      v7->mNext = v7;
      v7[1].mNext = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v8[2].mNext = (UFG::allocator::free_link *)v5;
    v8[3].mNext = (UFG::allocator::free_link *)v4;
    v9 = -1;
    if ( v5->mBaseNode.mUID == -1i64 )
    {
      v10 = UFG::qString::FormatEx(&result, v6->mUniqueWindowIDKey.mData, --v6->mNextWindowIndex);
      v11 = UFG::qStringHash64(v10->mData, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qString::~qString(&result);
      v5->mBaseNode.mUID = v11;
    }
    v12 = v6->mWindowsToShow.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)v8;
    v8->mNext = (UFG::allocator::free_link *)v12;
    v8[1].mNext = (UFG::allocator::free_link *)&v6->mWindowsToShow;
    v6->mWindowsToShow.mNode.mPrev = (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)v8;
    v13 = &v6->mWindows;
    v14 = (signed __int64)&v6->mWindows.mNode.mNext[-8].mNext;
    if ( (UFG::DUIManager *)v14 == (UFG::DUIManager *)&v6->mTheme.mColour[15].b )
      goto LABEL_13;
    while ( 1 )
    {
      ++v9;
      if ( (UFG::DUIWindow *)v14 == v5 )
        break;
      v14 = *(_QWORD *)(v14 + 128) - 120i64;
      if ( (UFG::DUIManager *)v14 == (UFG::DUIManager *)&v6->mTheme.mColour[15].b )
        goto LABEL_13;
    }
    if ( v9 == -1 )
    {
LABEL_13:
      v15 = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&v5->mPrev;
      v16 = v13->mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&v5->mPrev;
      v15->mPrev = v16;
      v15->mNext = &v13->mNode;
      v13->mNode.mPrev = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&v5->mPrev;
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

