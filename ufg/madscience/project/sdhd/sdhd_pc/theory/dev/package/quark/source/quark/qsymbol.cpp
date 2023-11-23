// File Line: 54
// RVA: 0x1467E90
__int64 UFG::_dynamic_initializer_for__gNullQSymbol__()
{
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gNullQSymbol, 0xFFFFFFFF);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gNullQSymbol__);
}

// File Line: 55
// RVA: 0x1467EC0
__int64 UFG::_dynamic_initializer_for__gNullQSymbolUC__()
{
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gNullQSymbolUC, 0xFFFFFFFF);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gNullQSymbolUC__);
}

// File Line: 64
// RVA: 0x18BA30
__int64 __fastcall UFG::qSymbolUIDFromStringN(const char *str, int length, unsigned int prevHash)
{
  unsigned int v4; // r9d
  const char *v5; // rdx
  const char *v6; // rax
  unsigned __int64 v8; // r10
  char v9; // al

  v4 = 0;
  v5 = str;
  if ( length == -1 )
  {
    if ( str )
    {
      v6 = str;
      while ( *v6++ )
        ;
      length = (_DWORD)v6 - (_DWORD)v5 - 1;
    }
    else
    {
      length = 0;
    }
  }
  if ( v5 )
  {
    v8 = (unsigned int)length;
    if ( length )
    {
      do
      {
        v9 = *v5;
        ++v4;
        ++v5;
        prevHash = (prevHash << 8) ^ sCrcTable32[(unsigned __int8)(v9 ^ HIBYTE(prevHash))];
      }
      while ( v4 < v8 );
    }
  }
  return prevHash;
}

// File Line: 78
// RVA: 0x18B890
char *__fastcall UFG::qSymbolLookupStringFromSymbolTableResources(unsigned int uid)
{
  UFG::SymbolTableResourceInventory *v2; // rax
  const char *v3; // rdi
  UFG::qMemoryPool *v4; // rcx
  UFG::allocator::free_link *v5; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *p_mResourceDatas; // rdi
  UFG::qBaseNodeRB *v7; // rcx
  UFG::qBaseNodeRB *p_mNULL; // rdx
  UFG::qBaseNodeRB *i; // rax
  UFG::qBaseNodeRB *p_mRoot; // r10
  int v11; // r8d
  int mUID; // ecx
  UFG::qBaseNodeRB *mParent; // rax
  char *v14; // r11
  int v15; // eax
  char *v16; // r9
  unsigned int v17; // edx
  __int64 v18; // rax
  char *result; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v20; // rcx
  UFG::qBaseNodeRB *v21; // rdx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *j; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v23; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v24; // rcx

  v2 = UFG::gSymbolTableResourceInventory;
  if ( !UFG::gSymbolTableResourceInventory )
  {
    v3 = UFG::gGlobalNewName;
    v4 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v4 = UFG::gMainMemoryPool;
    }
    v5 = UFG::qMemoryPool::Allocate(v4, 0x130ui64, v3, 0i64, 1u);
    if ( v5 )
      UFG::SymbolTableResourceInventory::SymbolTableResourceInventory((UFG::SymbolTableResourceInventory *)v5);
    else
      v2 = 0i64;
    UFG::gSymbolTableResourceInventory = v2;
  }
  p_mResourceDatas = &v2->mResourceDatas;
  v7 = v2->mResourceDatas.mTree.mRoot.mChild[0];
  p_mNULL = &v2->mResourceDatas.mTree.mNULL;
  for ( i = v7->mChild[0]; i != p_mNULL; i = i->mChild[0] )
    v7 = i;
  p_mRoot = 0i64;
  if ( v7 != p_mNULL )
    p_mRoot = v7;
  while ( 2 )
  {
    if ( !p_mRoot )
      return 0i64;
    v11 = 0;
    mUID = p_mRoot[2].mUID;
    mParent = p_mRoot[3].mParent;
    if ( mParent )
      v14 = (char *)&p_mRoot[3] + (_QWORD)mParent;
    else
      v14 = 0i64;
    if ( mUID < 0 )
      goto LABEL_26;
    while ( 1 )
    {
      v15 = (mUID + v11) / 2;
      v16 = &v14[16 * v15];
      v17 = *(_DWORD *)v16;
      if ( uid <= *(_DWORD *)v16 )
        break;
      v11 = v15 + 1;
LABEL_22:
      if ( v11 > mUID )
        goto LABEL_26;
    }
    if ( uid < v17 )
    {
      mUID = v15 - 1;
      goto LABEL_22;
    }
    if ( uid != v17 )
      goto LABEL_22;
    v18 = *((_QWORD *)v16 + 1);
    if ( !v18 || (result = &v16[v18 + 8]) == 0i64 )
    {
LABEL_26:
      v20 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)p_mRoot->mChild[1];
      v21 = &p_mResourceDatas->mTree.mNULL;
      if ( &p_mResourceDatas->mTree.mNULL == (UFG::qBaseNodeRB *)v20 )
      {
        v23 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)p_mRoot->mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( p_mRoot == v23->mTree.mRoot.mChild[1] )
        {
          do
          {
            v24 = v23;
            v23 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v23->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v24 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v23->mTree.mRoot.mChild[1] );
        }
        p_mRoot = &v23->mTree.mRoot;
        if ( v23 == p_mResourceDatas )
          p_mRoot = 0i64;
      }
      else
      {
        for ( j = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v20->mTree.mRoot.mChild[0];
              j != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v21;
              j = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)j->mTree.mRoot.mChild[0] )
        {
          v20 = j;
        }
        p_mRoot = &v20->mTree.mRoot;
      }
      continue;
    }
    return result;
  }
}

// File Line: 137
// RVA: 0x17CC10
_BOOL8 __fastcall UFG::qSymbolRegistry::SetAssertOnEmptySymbolCtor(bool bAssert)
{
  _BOOL8 result; // rax

  result = gSymbolAssertOnEmptyCtor;
  gSymbolAssertOnEmptyCtor = bAssert;
  return result;
}

// File Line: 211
// RVA: 0x16F070
char *__fastcall UFG::qSymbolRegistry::Get(unsigned int uid)
{
  char *result; // rax
  char *v3; // rbx
  int v4; // ecx

  if ( uid == -1 )
    return &customCaption;
  result = (char *)UFG::qSymbolLookupStringFromSymbolTableResources(uid);
  if ( !result )
  {
    v3 = &byte_14235BF70[16 * dword_14235BFF0];
    UFG::qSPrintf(v3, &byte_1416B0B34, uid);
    v4 = dword_14235BFF0 + 1;
    if ( dword_14235BFF0 == 7 )
      v4 = 0;
    result = v3;
    dword_14235BFF0 = v4;
  }
  return result;
}

// File Line: 265
// RVA: 0x1795E0
bool __fastcall UFG::qSymbolRegistry::PurgeRef(unsigned int uid)
{
  return uid == -1;
}

// File Line: 387
// RVA: 0x162150
UFG::qWiseSymbol *__fastcall UFG::qSymbol::qSymbol(UFG::qWiseSymbol *result, unsigned int uid)
{
  result->mUID = uid;
  return result;
}

// File Line: 435
// RVA: 0x18DD20
void __fastcall UFG::qSymbol::set_from_symbol(UFG::qSymbol *this, UFG::qSymbol *sym)
{
  this->mUID = sym->mUID;
}

// File Line: 449
// RVA: 0x18DC30
void __fastcall UFG::qSymbol::set_from_cstr(UFG::qSymbol *this, const char *pszSymbolString)
{
  unsigned int v2; // eax
  const char *v3; // r8
  char v5; // cl

  v2 = -1;
  v3 = pszSymbolString;
  if ( pszSymbolString )
  {
    v5 = *pszSymbolString;
    if ( *pszSymbolString )
    {
      do
      {
        ++v3;
        v2 = (v2 << 8) ^ sCrcTable32[(unsigned __int8)(v5 ^ HIBYTE(v2))];
        v5 = *v3;
      }
      while ( *v3 );
    }
  }
  if ( v2 != this->mUID )
    this->mUID = v2;
}

// File Line: 461
// RVA: 0x180880
UFG::qSymbol *__fastcall UFG::qSymbol::create_from_string(UFG::qSymbol *result, const char *pszSymbolString)
{
  unsigned int v2; // eax
  const char *v3; // r8
  char v6; // cl

  v2 = -1;
  v3 = pszSymbolString;
  if ( pszSymbolString )
  {
    v6 = *pszSymbolString;
    if ( *pszSymbolString )
    {
      do
      {
        ++v3;
        v2 = (v2 << 8) ^ sCrcTable32[(unsigned __int8)(v6 ^ HIBYTE(v2))];
        v6 = *v3;
      }
      while ( *v3 );
    }
    result->mUID = v2;
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 479
// RVA: 0x18DE80
void __fastcall UFG::qSymbol::set_null(UFG::qSymbol *this)
{
  this->mUID = UFG::gNullQSymbol.mUID;
}

// File Line: 503
// RVA: 0x1809A0
UFG::qWiseSymbol *__fastcall UFG::qSymbol::create_suffix(UFG::qWiseSymbol *result, UFG::qSymbol *name_a, char *suffix)
{
  unsigned int mUID; // edx
  char i; // al

  mUID = name_a->mUID;
  if ( suffix )
  {
    for ( i = *suffix; *suffix; i = *suffix )
    {
      ++suffix;
      mUID = (mUID << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(mUID))];
    }
  }
  UFG::qSymbol::qSymbol(result, mUID);
  return result;
}

// File Line: 522
// RVA: 0x180980
UFG::qWiseSymbol *__fastcall UFG::qSymbol::create_increment(
        UFG::qWiseSymbol *result,
        UFG::qSymbol *name,
        int incrementValue)
{
  UFG::qSymbol::qSymbol(result, name->mUID + 1);
  return result;
}

// File Line: 647
// RVA: 0x18DC80
void __fastcall UFG::qSymbolUC::set_from_cstr(UFG::qSymbolUC *this, const char *pszSymbolString)
{
  unsigned int v2; // r8d
  const char *v3; // r9
  char v4; // al

  v2 = -1;
  v3 = pszSymbolString;
  if ( pszSymbolString )
  {
    v4 = *pszSymbolString;
    if ( *pszSymbolString )
    {
      do
      {
        if ( v4 <= 122 && v4 >= 97 )
          v4 -= 32;
        ++v3;
        v2 = (v2 << 8) ^ sCrcTable32[(unsigned __int8)(v4 ^ HIBYTE(v2))];
        v4 = *v3;
      }
      while ( *v3 );
    }
  }
  if ( v2 != this->mUID )
    this->mUID = v2;
}

// File Line: 661
// RVA: 0x1808E0
UFG::qSymbolUC *__fastcall UFG::qSymbolUC::create_from_string(UFG::qSymbolUC *result, const char *pszSymbolString)
{
  unsigned int v2; // r8d
  const char *v3; // r9
  char v5; // al

  v2 = -1;
  v3 = pszSymbolString;
  if ( pszSymbolString )
  {
    v5 = *pszSymbolString;
    if ( *pszSymbolString )
    {
      do
      {
        if ( v5 <= 122 && v5 >= 97 )
          v5 -= 32;
        ++v3;
        v2 = (v2 << 8) ^ sCrcTable32[(unsigned __int8)(v5 ^ HIBYTE(v2))];
        v5 = *v3;
      }
      while ( *v3 );
    }
    result->mUID = v2;
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 675
// RVA: 0x18DE90
void __fastcall UFG::qSymbolUC::set_null(UFG::qSymbolUC *this)
{
  this->mUID = UFG::gNullQSymbolUC.mUID;
}

// File Line: 925
// RVA: 0x160AC0
void __fastcall UFG::SymbolTableResourceInventory::SymbolTableResourceInventory(
        UFG::SymbolTableResourceInventory *this)
{
  UFG::qResourceInventory::qResourceInventory(this, "SymbolTableResourceInventory", 0x7C98C388u, 0xE4868DBE, 0, 0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SymbolTableResourceInventory::`vftable;
  this->mbAutoUnpackSymbols = 0;
}

// File Line: 929
// RVA: 0x165240
void __fastcall UFG::SymbolTableResourceInventory::Add(
        UFG::SymbolTableResourceInventory *this,
        UFG::SymbolTableResource *resource_data)
{
  if ( resource_data )
  {
    resource_data->mNode.mParent = 0i64;
    resource_data->mNode.mChild[0] = 0i64;
    resource_data->mNode.mChild[1] = 0i64;
    resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
    resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
  }
  UFG::qResourceInventory::Add(this, resource_data);
  this->mpLastLoadedResource = resource_data;
}

// File Line: 956
// RVA: 0x17A070
void __fastcall UFG::SymbolTableResourceInventory::Remove(
        UFG::SymbolTableResourceInventory *this,
        UFG::SymbolTableResource *resource_data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&resource_data->mResourceHandles);
  mPrev = resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
  if ( this->mpLastLoadedResource == resource_data )
    this->mpLastLoadedResource = 0i64;
}

