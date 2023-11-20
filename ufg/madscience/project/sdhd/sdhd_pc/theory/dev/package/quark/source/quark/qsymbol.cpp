// File Line: 54
// RVA: 0x1467E90
__int64 UFG::_dynamic_initializer_for__gNullQSymbol__()
{
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gNullQSymbol, 0xFFFFFFFF);
  return atexit(UFG::_dynamic_atexit_destructor_for__gNullQSymbol__);
}

// File Line: 55
// RVA: 0x1467EC0
__int64 UFG::_dynamic_initializer_for__gNullQSymbolUC__()
{
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gNullQSymbolUC, 0xFFFFFFFF);
  return atexit(UFG::_dynamic_atexit_destructor_for__gNullQSymbolUC__);
}

// File Line: 64
// RVA: 0x18BA30
__int64 __fastcall UFG::qSymbolUIDFromStringN(const char *str, unsigned int length, unsigned int prevHash)
{
  unsigned int v3; // eax
  unsigned int v4; // er9
  const char *v5; // rdx
  const char *v6; // rax
  char v7; // cl
  unsigned __int64 v8; // r10
  char v9; // al

  v3 = length;
  v4 = 0;
  v5 = str;
  if ( v3 == -1 )
  {
    if ( str )
    {
      v6 = str;
      do
        v7 = *v6++;
      while ( v7 );
      v3 = (_DWORD)v6 - (_DWORD)v5 - 1;
    }
    else
    {
      v3 = 0;
    }
  }
  if ( v5 )
  {
    v8 = v3;
    if ( v3 )
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
const char *__fastcall UFG::qSymbolLookupStringFromSymbolTableResources(unsigned int uid)
{
  unsigned int v1; // ebx
  UFG::SymbolTableResourceInventory *v2; // rax
  const char *v3; // rdi
  UFG::qMemoryPool *v4; // rcx
  UFG::allocator::free_link *v5; // rax
  signed __int64 v6; // rdi
  UFG::qBaseNodeRB *v7; // rcx
  signed __int64 v8; // rdx
  UFG::qBaseNodeRB *i; // rax
  UFG::qBaseNodeRB *v10; // r10
  int v11; // er8
  int v12; // ecx
  UFG::qBaseNodeRB *v13; // rax
  signed __int64 v14; // r11
  int v15; // eax
  signed __int64 v16; // r9
  unsigned int v17; // edx
  __int64 v18; // rax
  const char *result; // rax
  UFG::qBaseNodeRB *v20; // rcx
  signed __int64 v21; // rdx
  UFG::qBaseNodeRB *j; // rax
  UFG::qBaseNodeRB *v23; // rax
  UFG::qBaseNodeRB *v24; // rcx

  v1 = uid;
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
  v6 = (signed __int64)&v2->mResourceDatas;
  v7 = v2->mResourceDatas.mTree.mRoot.mChild[0];
  v8 = (signed __int64)&v2->mResourceDatas.mTree.mNULL;
  for ( i = v7->mChild[0]; i != (UFG::qBaseNodeRB *)v8; i = i->mChild[0] )
    v7 = i;
  v10 = 0i64;
  if ( v7 != (UFG::qBaseNodeRB *)v8 )
    v10 = v7;
  while ( 2 )
  {
    if ( !v10 )
      return 0i64;
    v11 = 0;
    v12 = v10[2].mUID;
    v13 = v10[3].mParent;
    if ( v13 )
      v14 = (signed __int64)&v10[3] + (_QWORD)v13;
    else
      v14 = 0i64;
    if ( v12 < 0 )
      goto LABEL_26;
    while ( 1 )
    {
      v15 = (v12 + v11) / 2;
      v16 = v14 + 16i64 * v15;
      v17 = *(_DWORD *)v16;
      if ( v1 <= *(_DWORD *)v16 )
        break;
      v11 = v15 + 1;
LABEL_22:
      if ( v11 > v12 )
        goto LABEL_26;
    }
    if ( v1 < v17 )
    {
      v12 = v15 - 1;
      goto LABEL_22;
    }
    if ( v1 != v17 )
      goto LABEL_22;
    v18 = *(_QWORD *)(v16 + 8);
    if ( !v18 || (result = (const char *)(v16 + v18 + 8)) == 0i64 )
    {
LABEL_26:
      v20 = v10->mChild[1];
      v21 = v6 + 32;
      if ( (UFG::qBaseNodeRB *)(v6 + 32) == v20 )
      {
        v23 = (UFG::qBaseNodeRB *)((_QWORD)v10->mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v10 == v23->mChild[1] )
        {
          do
          {
            v24 = v23;
            v23 = (UFG::qBaseNodeRB *)((_QWORD)v23->mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v24 == v23->mChild[1] );
        }
        v10 = v23;
        if ( v23 == (UFG::qBaseNodeRB *)v6 )
          v10 = 0i64;
      }
      else
      {
        for ( j = v20->mChild[0]; j != (UFG::qBaseNodeRB *)v21; j = j->mChild[0] )
          v20 = j;
        v10 = v20;
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
  unsigned int v1; // edi
  char *result; // rax
  char *v3; // rbx
  int v4; // ecx

  v1 = uid;
  if ( uid == -1 )
    return &customWorldMapCaption;
  result = (char *)UFG::qSymbolLookupStringFromSymbolTableResources(uid);
  if ( !result )
  {
    v3 = &byte_14235BF70[16 * dword_14235BFF0];
    UFG::qSPrintf(&byte_14235BF70[16 * dword_14235BFF0], &byte_1416B0B34, v1);
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
  UFG::qSymbol *v4; // r9
  char v5; // cl

  v2 = -1;
  v3 = pszSymbolString;
  v4 = this;
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
  if ( v2 != v4->mUID )
    v4->mUID = v2;
}

// File Line: 461
// RVA: 0x180880
UFG::qSymbol *__fastcall UFG::qSymbol::create_from_string(UFG::qSymbol *result, const char *pszSymbolString)
{
  unsigned int v2; // eax
  const char *v3; // r8
  UFG::qSymbol *v4; // r9
  UFG::qSymbol *v5; // rax
  char v6; // cl

  v2 = -1;
  v3 = pszSymbolString;
  v4 = result;
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
    v4->mUID = v2;
    v5 = v4;
  }
  else
  {
    result->mUID = -1;
    v5 = result;
  }
  return v5;
}

// File Line: 479
// RVA: 0x18DE80
void __fastcall UFG::qSymbol::set_null(UFG::qSymbol *this)
{
  this->mUID = UFG::gNullQSymbol.mUID;
}

// File Line: 503
// RVA: 0x1809A0
UFG::qSymbol *__fastcall UFG::qSymbol::create_suffix(UFG::qSymbol *result, UFG::qSymbol *name_a, const char *suffix)
{
  unsigned int v3; // edx
  UFG::qSymbol *v4; // rbx
  char i; // al

  v3 = name_a->mUID;
  v4 = result;
  if ( suffix )
  {
    for ( i = *suffix; *suffix; i = *suffix )
    {
      ++suffix;
      v3 = (v3 << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(v3))];
    }
  }
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)result, v3);
  return v4;
}

// File Line: 522
// RVA: 0x180980
UFG::qSymbol *__fastcall UFG::qSymbol::create_increment(UFG::qSymbol *result, UFG::qSymbol *name, int incrementValue)
{
  UFG::qSymbol *v3; // rbx

  v3 = result;
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)result, name->mUID + 1);
  return v3;
}

// File Line: 647
// RVA: 0x18DC80
void __fastcall UFG::qSymbolUC::set_from_cstr(UFG::qSymbolUC *this, const char *pszSymbolString)
{
  signed int v2; // er8
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
  signed int v2; // er8
  const char *v3; // r9
  UFG::qSymbolUC *v4; // rax
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
    v4 = result;
  }
  else
  {
    result->mUID = -1;
    v4 = result;
  }
  return v4;
}

// File Line: 675
// RVA: 0x18DE90
void __fastcall UFG::qSymbolUC::set_null(UFG::qSymbolUC *this)
{
  this->mUID = UFG::gNullQSymbolUC.mUID;
}

// File Line: 925
// RVA: 0x160AC0
void __fastcall UFG::SymbolTableResourceInventory::SymbolTableResourceInventory(UFG::SymbolTableResourceInventory *this)
{
  UFG::SymbolTableResourceInventory *v1; // rbx

  v1 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "SymbolTableResourceInventory",
    0x7C98C388u,
    0xE4868DBE,
    0,
    0);
  v1->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SymbolTableResourceInventory::`vftable;
  v1->mbAutoUnpackSymbols = 0;
}

// File Line: 929
// RVA: 0x165240
void __fastcall UFG::SymbolTableResourceInventory::Add(UFG::SymbolTableResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::SymbolTableResourceInventory *v3; // rdi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v4; // [rsp+50h] [rbp+18h]

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
  {
    resource_data->mNode.mParent = 0i64;
    resource_data->mNode.mChild[0] = 0i64;
    resource_data->mNode.mChild[1] = 0i64;
    v4 = &resource_data->mResourceHandles;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3->mpLastLoadedResource = (UFG::SymbolTableResource *)v2;
}

// File Line: 956
// RVA: 0x17A070
void __fastcall UFG::SymbolTableResourceInventory::Remove(UFG::SymbolTableResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rdi
  UFG::SymbolTableResourceInventory *v3; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax

  v2 = resource_data;
  v3 = this;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v4 = v2->mResourceHandles.mNode.mPrev;
  v5 = v2->mResourceHandles.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v2->mResourceHandles.mNode.mPrev = &v2->mResourceHandles.mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
  if ( (UFG::qResourceData *)v3->mpLastLoadedResource == v2 )
    v3->mpLastLoadedResource = 0i64;
}

