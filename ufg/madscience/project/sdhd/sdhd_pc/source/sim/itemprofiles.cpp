// File Line: 23
// RVA: 0x518230
void __fastcall UFG::ItemProfiles::ItemProfiles(UFG::ItemProfiles *this)
{
  int v1; // edi
  const char **p_mCaptioning; // rbx

  v1 = 208;
  p_mCaptioning = &this->mProfiles[0].mCaptioning;
  do
  {
    *(p_mCaptioning - 2) = 0i64;
    *p_mCaptioning = 0i64;
    p_mCaptioning[1] = 0i64;
    UFG::qMemSet(p_mCaptioning + 2, 0, 0x18u);
    --v1;
    p_mCaptioning += 7;
  }
  while ( v1 >= 0 );
}

// File Line: 33
// RVA: 0x538E80
char __fastcall UFG::ItemProfiles::InitItemProfiles()
{
  UFG::qSymbol *v0; // rax
  UFG::qPropertySet *PropertySet; // r13
  UFG::allocator::free_link *v2; // rax
  int v3; // r15d
  __int64 v4; // r12
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // r14
  char *v8; // rdi
  int v9; // ebx
  UFG::qArray<unsigned long,0> *v10; // rbp
  bool v11; // si
  bool *v12; // rax
  int *v13; // rax
  char *v14; // rax
  char *v15; // rax
  UFG::qSymbol *v16; // rax
  UFG::qPropertyList *v17; // rsi
  char *v18; // rax
  signed int v19; // ebx
  _QWORD *v20; // rdi
  char *v21; // rax
  UFG::qSymbol result; // [rsp+70h] [rbp+8h] BYREF
  UFG::allocator::free_link *v24; // [rsp+78h] [rbp+10h]

  v0 = UFG::qSymbol::create_from_string(&result, "propprofiles-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v0);
  if ( !PropertySet || UFG::ItemProfiles::mpInstance )
    return 0;
  v2 = UFG::qMalloc(0x2DB8ui64, "ItemProfiles", 0i64);
  v24 = v2;
  if ( v2 )
    UFG::ItemProfiles::ItemProfiles((UFG::ItemProfiles *)v2);
  UFG::ItemProfiles::mpInstance = (UFG::ItemProfiles *)v2;
  v3 = 0;
  v4 = 0i64;
  do
  {
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&UFG::InventoryItemEnumSymbols[v3],
           DEPTH_RECURSE);
    v6 = (UFG::qSymbolUC *)v5;
    if ( v5 )
    {
      v7 = UFG::PropertySetManager::GetPropertySet(v5);
      if ( !v7 )
      {
        v21 = UFG::qSymbol::as_cstr_dbg(v6);
        UFG::qPrintf("Searching for property set %s, which was not found, check spelling and case\n", v21);
        return 0;
      }
      v8 = (char *)UFG::ItemProfiles::mpInstance + v4;
      v9 = 0;
      v10 = (UFG::qArray<unsigned long,0> *)&UFG::ItemPropertiesEnumSymbols;
      do
      {
        v11 = 0;
        v12 = UFG::qPropertySet::Get<bool>(v7, v10, DEPTH_RECURSE);
        if ( v12 )
          v11 = *v12;
        *(_DWORD *)v8 |= v11 << v9++;
        v10 = (UFG::qArray<unsigned long,0> *)((char *)v10 + 4);
      }
      while ( v9 < 6 );
      v13 = UFG::qPropertySet::Get<long>(v7, (UFG::qArray<unsigned long,0> *)&SimSym_ItemCost, DEPTH_RECURSE);
      if ( v13 )
        *((_DWORD *)v8 + 1) = *v13;
      v14 = UFG::qPropertySet::Get<char const *>(
              v7,
              (UFG::qArray<unsigned long,0> *)&SimSym_ItemCaptioning,
              DEPTH_RECURSE);
      if ( v14 )
        *((_QWORD *)v8 + 2) = v14;
      v15 = UFG::qPropertySet::Get<char const *>(v7, (UFG::qArray<unsigned long,0> *)&SimSym_ItemName, DEPTH_RECURSE);
      if ( v15 )
        *((_QWORD *)v8 + 3) = v15;
      v16 = UFG::qPropertySet::Get<UFG::qSymbol>(
              v7,
              (UFG::qArray<unsigned long,0> *)&SimSym_ItemDescriptionBuff,
              DEPTH_RECURSE);
      *((_DWORD *)v8 + 2) = 0;
      if ( v16 )
        *((_DWORD *)v8 + 2) = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gPlayerBuffEnum, v16);
      v17 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              v7,
              (UFG::qArray<unsigned long,0> *)&SimSym_ItemDescriptionList,
              DEPTH_RECURSE);
      if ( v17 )
      {
        v19 = 0;
        v20 = v8 + 32;
        do
          *v20++ = UFG::qPropertyList::Get<char const *>(v17, v19++);
        while ( v19 < 3 );
      }
      else
      {
        v18 = UFG::qPropertySet::Get<char const *>(
                v7,
                (UFG::qArray<unsigned long,0> *)&SimSym_ItemDescription,
                DEPTH_RECURSE);
        if ( v18 )
        {
          *((_QWORD *)v8 + 4) = v18;
          *((_QWORD *)v8 + 5) = v18;
          *((_QWORD *)v8 + 6) = v18;
        }
      }
    }
    ++v3;
    v4 += 56i64;
  }
  while ( v3 < 209 );
  return 1;
}

// File Line: 190
// RVA: 0x535A00
unsigned __int8 __fastcall UFG::ItemProfiles::HasProperty(
        UFG::eInventoryItemEnum eInventoryItem,
        unsigned int propertyIndex)
{
  unsigned int mProfile; // ecx

  if ( eInventoryItem == eINVENTORY_ITEM_INVALID )
    return 0;
  mProfile = UFG::ItemProfiles::mpInstance->mProfiles[eInventoryItem].mProfile;
  return _bittest((const int *)&mProfile, propertyIndex);
}

// File Line: 202
// RVA: 0x52C630
__int64 __fastcall UFG::ItemProfiles::GetCost(UFG::eInventoryItemEnum eInventoryItem)
{
  if ( eInventoryItem )
    return (unsigned int)UFG::ItemProfiles::mpInstance->mProfiles[eInventoryItem].mCost;
  else
    return 0i64;
}

// File Line: 214
// RVA: 0x54C680
void __fastcall UFG::ItemProfiles::SetCost(UFG::eInventoryItemEnum eInventoryItem, int itemCost)
{
  if ( eInventoryItem == eINVENTORY_ITEM_HIJACKED_VEHICLE )
    UFG::ItemProfiles::mpInstance->mProfiles[104].mCost = itemCost;
}

// File Line: 230
// RVA: 0x52AED0
const char *__fastcall UFG::ItemProfiles::GetCaptioning(UFG::eInventoryItemEnum eInventoryItem)
{
  __int64 v1; // rax
  __int64 v2; // rbx
  UFG::qString v4; // [rsp+28h] [rbp-30h] BYREF

  if ( eInventoryItem )
    return UFG::ItemProfiles::mpInstance->mProfiles[eInventoryItem].mCaptioning;
  UFG::qString::qString(&v4);
  v2 = *(_QWORD *)(v1 + 24);
  UFG::qString::~qString(&v4);
  return (const char *)v2;
}

// File Line: 242
// RVA: 0x52EB00
const char *__fastcall UFG::ItemProfiles::GetName(UFG::eInventoryItemEnum eInventoryItem)
{
  __int64 v1; // rax
  __int64 v2; // rbx
  UFG::qString v4; // [rsp+28h] [rbp-30h] BYREF

  if ( eInventoryItem )
    return UFG::ItemProfiles::mpInstance->mProfiles[eInventoryItem].mName;
  UFG::qString::qString(&v4);
  v2 = *(_QWORD *)(v1 + 24);
  UFG::qString::~qString(&v4);
  return (const char *)v2;
}

// File Line: 267
// RVA: 0x52CC00
const char *__fastcall UFG::ItemProfiles::GetDescription(UFG::eInventoryItemEnum eInventoryItem, int index)
{
  __int64 v2; // rax
  __int64 v3; // rbx
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  if ( eInventoryItem )
    return UFG::ItemProfiles::mpInstance->mProfiles[eInventoryItem].mDescription[index];
  UFG::qString::qString(&v5);
  v3 = *(_QWORD *)(v2 + 24);
  UFG::qString::~qString(&v5);
  return (const char *)v3;
}

