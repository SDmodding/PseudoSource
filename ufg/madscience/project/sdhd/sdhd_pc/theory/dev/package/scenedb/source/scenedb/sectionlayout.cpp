// File Line: 46
// RVA: 0x14703F0
__int64 UFG::_dynamic_initializer_for__gSectionLayoutInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gSectionLayoutInventory,
    "SectionLayoutInventory",
    0xEC35A8A0,
    0x3E50F7D5u,
    0,
    0);
  UFG::gSectionLayoutInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SectionLayoutInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSectionLayoutInventory__);
}

// File Line: 54
// RVA: 0x230270
void __fastcall UFG::SectionLayoutInventory::Add(UFG::SectionLayoutInventory *this, UFG::SectionLayout *resource_data)
{
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::gSectionLayout = resource_data;
  UFG::gSectionLayout_Loaded = resource_data;
  UFG::SectionLayout::BuildLayerTweakers();
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 73
// RVA: 0x234FF0
void __fastcall UFG::SectionLayoutInventory::Remove(
        UFG::SectionLayoutInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  if ( (_S1_27 & 1) == 0 )
  {
    _S1_27 |= 1u;
    stru_1423A9CB8.mEditorLayout = 0i64;
    stru_1423A9CB8.mSectionHighLODTable = 0i64;
    stru_1423A9CB8.mSectionLowLODTable = 0i64;
    stru_1423A9CB8.mSectionTable = 0i64;
  }
  UFG::SectionLayoutEditorData::Close(&stru_1423A9CB8);
  UFG::gSectionLayout = 0i64;
  UFG::gSectionLayout_Loaded = 0i64;
}

// File Line: 90
// RVA: 0x230A20
void UFG::SectionLayout::BuildLayerTweakers(void)
{
  __int64 v0; // rbx
  UFG::SectionLayout *i; // rcx
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v0 = 0i64;
  for ( i = UFG::gSectionLayout; (unsigned int)v0 < UFG::gSectionLayout->mLayerCount; i = UFG::gSectionLayout )
  {
    mOffset = i->mLayers.mOffset;
    if ( mOffset )
      v3 = (char *)&i->mLayers + mOffset;
    else
      v3 = 0i64;
    UFG::qString::FormatEx(&result, "\\Streaming\\Layers\\%s", &v3[48 * v0 + 16]);
    UFG::qString::~qString(&result);
    v0 = (unsigned int)(v0 + 1);
  }
}

// File Line: 120
// RVA: 0x232B70
signed __int64 __fastcall UFG::SectionLayout::GetSectionFromCellIndex(unsigned int sectionIndex)
{
  __int64 mOffset; // rdx

  mOffset = UFG::gSectionLayout->mSections.mOffset;
  if ( mOffset )
    return (signed __int64)&UFG::gSectionLayout->mSections + 48 * sectionIndex + mOffset;
  else
    return 48i64 * sectionIndex;
}

// File Line: 151
// RVA: 0x232BE0
__int64 __fastcall UFG::SectionLayout::GetSectionUIDFromIndex(unsigned int cell_index)
{
  __int64 mOffset; // rdx

  mOffset = UFG::gSectionLayout->mSections.mOffset;
  if ( mOffset )
    return *(unsigned int *)((char *)&UFG::gSectionLayout->mSections.mOffset + 48 * cell_index + mOffset);
  else
    return *(unsigned int *)(48i64 * cell_index);
}

// File Line: 187
// RVA: 0x232870
__int64 __fastcall UFG::SectionLayout::GetHighLODSectionVisIndices(
        unsigned int visIndex,
        unsigned int *outputBuffer,
        unsigned int outputBufferSize)
{
  __int64 mOffset; // r9
  unsigned int v5; // r8d
  char *v6; // r9
  char *v7; // r10
  unsigned int i; // edx
  __int64 v9; // rax
  char *v10; // rcx
  unsigned int v11; // r9d
  __int64 v12; // rcx

  *outputBuffer = visIndex;
  mOffset = UFG::gSectionLayout->mSectionVis.mOffset;
  v5 = 1;
  if ( mOffset )
    v6 = (char *)&UFG::gSectionLayout->mSectionVis + mOffset;
  else
    v6 = 0i64;
  v7 = &v6[96 * visIndex];
  if ( *((_QWORD *)v7 + 1) )
  {
    for ( i = 0; i < *((unsigned __int16 *)v7 + 2); ++i )
    {
      v9 = *((_QWORD *)v7 + 1);
      if ( v9 )
        v10 = &v7[v9 + 8];
      else
        v10 = 0i64;
      v11 = *(unsigned __int16 *)&v10[2 * i];
      v12 = v5++;
      outputBuffer[v12] = v11;
    }
  }
  return v5;
}

// File Line: 211
// RVA: 0x2329E0
__int64 __fastcall UFG::SectionLayout::GetLowLODSectionVisIndices(
        unsigned int visIndex,
        unsigned int *outputBuffer,
        unsigned int outputBufferSize)
{
  __int64 mOffset; // r9
  unsigned int v5; // r8d
  char *v6; // r9
  char *v7; // r10
  unsigned int i; // edx
  __int64 v9; // rax
  char *v10; // rcx
  unsigned int v11; // r9d
  __int64 v12; // rcx

  *outputBuffer = visIndex;
  mOffset = UFG::gSectionLayout->mSectionVis.mOffset;
  v5 = 1;
  if ( mOffset )
    v6 = (char *)&UFG::gSectionLayout->mSectionVis + mOffset;
  else
    v6 = 0i64;
  v7 = &v6[96 * visIndex];
  if ( *((_QWORD *)v7 + 2) )
  {
    for ( i = 0; i < *((unsigned __int16 *)v7 + 3); ++i )
    {
      v9 = *((_QWORD *)v7 + 2);
      if ( v9 )
        v10 = &v7[v9 + 16];
      else
        v10 = 0i64;
      v11 = *(unsigned __int16 *)&v10[2 * i];
      v12 = v5++;
      outputBuffer[v12] = v11;
    }
  }
  return v5;
}

// File Line: 234
// RVA: 0x232A70
__int64 __fastcall UFG::SectionLayout::GetLowLODSectionVisIndices_HD(
        unsigned int visIndex,
        unsigned int *outputBuffer,
        unsigned int outputBufferSize)
{
  __int64 mOffset; // r9
  unsigned int v5; // r8d
  __int64 v6; // r10
  __int64 i; // rax
  __int64 v8; // rcx
  __int64 v9; // rdx
  __int64 v10; // rcx

  *outputBuffer = visIndex;
  mOffset = UFG::gSectionLayout->mSectionVis.mOffset;
  v5 = 1;
  if ( mOffset )
    mOffset += (__int64)&UFG::gSectionLayout->mSectionVis;
  v6 = mOffset + 96i64 * visIndex;
  if ( *(_QWORD *)(v6 + 80) )
  {
    for ( i = 0i64; (unsigned int)i < *(_DWORD *)(v6 + 72); i = (unsigned int)(i + 1) )
    {
      v8 = *(_QWORD *)(v6 + 80);
      if ( v8 )
        v9 = v8 + v6 + 80;
      else
        v9 = 0i64;
      v10 = v5++;
      outputBuffer[v10] = *(unsigned __int16 *)(v9 + 2 * i);
    }
  }
  return v5;
}

// File Line: 353
// RVA: 0x232BB0
char *__fastcall UFG::SectionLayout::GetSectionNameFromCellIndex(unsigned int sectionIndex)
{
  __int64 mOffset; // rdx
  UFG::Section *v2; // rax

  mOffset = UFG::gSectionLayout->mSections.mOffset;
  if ( mOffset )
    mOffset += (__int64)&UFG::gSectionLayout->mSections;
  v2 = (UFG::Section *)(mOffset + 0x30i64 * sectionIndex);
  if ( v2 )
    return v2->mName;
  else
    return 0i64;
}

// File Line: 456
// RVA: 0x232840
__int64 __fastcall UFG::SectionLayout::GetFlags(unsigned int sectionIndex)
{
  __int64 mOffset; // rdx
  __int64 v2; // rcx

  mOffset = UFG::gSectionLayout->mSections.mOffset;
  if ( mOffset )
    mOffset += (__int64)&UFG::gSectionLayout->mSections;
  v2 = mOffset + 48i64 * sectionIndex;
  if ( v2 )
    return *(unsigned __int16 *)(v2 + 4);
  else
    return 0i64;
}

// File Line: 468
// RVA: 0x232900
__int64 __fastcall UFG::SectionLayout::GetLayerCount()
{
  return UFG::gSectionLayout->mLayerCount;
}

// File Line: 473
// RVA: 0x232910
__int64 __fastcall UFG::SectionLayout::GetLayerIndex(const char *layer_name)
{
  UFG::SectionLayout *v1; // rdx
  __int64 v2; // rbx
  unsigned int mLayerCount; // edi
  __int64 mOffset; // rax
  __int64 v6; // r8

  v1 = UFG::gSectionLayout;
  v2 = 0i64;
  mLayerCount = UFG::gSectionLayout->mLayerCount;
  if ( !mLayerCount )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    mOffset = v1->mLayers.mOffset;
    v6 = mOffset ? (__int64)&v1->mLayers + mOffset : 0i64;
    if ( !(unsigned int)UFG::qStringCompareInsensitive((const char *)(v6 + 48 * v2 + 16), layer_name, -1) )
      break;
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= mLayerCount )
      return 0xFFFFFFFFi64;
    v1 = UFG::gSectionLayout;
  }
  return (unsigned int)v2;
}

// File Line: 496
// RVA: 0x2350A0
bool __fastcall UFG::SectionLayout::SetLayerActive(unsigned int layer_index, bool active)
{
  int v2; // r8d
  __int64 mOffset; // r9
  char *v4; // r9
  bool result; // al

  if ( layer_index == -1 )
    return 0;
  v2 = 0;
  mOffset = UFG::gSectionLayout->mLayers.mOffset;
  if ( mOffset )
    v4 = (char *)&UFG::gSectionLayout->mLayers + mOffset;
  else
    v4 = 0i64;
  LOBYTE(v2) = active;
  result = 1;
  *(_DWORD *)&v4[48 * layer_index + 8] = v2;
  return result;
}

// File Line: 510
// RVA: 0x2350F0
bool __fastcall UFG::SectionLayout::SetLayerActive(const char *layer_name, bool active)
{
  unsigned int LayerIndex; // eax
  int v4; // r8d
  __int64 mOffset; // r9
  char *v6; // rdx
  __int64 v7; // rcx
  bool result; // al

  LayerIndex = UFG::SectionLayout::GetLayerIndex(layer_name);
  if ( LayerIndex == -1 )
    return 0;
  v4 = 0;
  mOffset = UFG::gSectionLayout->mLayers.mOffset;
  if ( mOffset )
    v6 = (char *)&UFG::gSectionLayout->mLayers + mOffset;
  else
    v6 = 0i64;
  v7 = 3i64 * LayerIndex;
  LOBYTE(v4) = active;
  result = 1;
  *(_DWORD *)&v6[16 * v7 + 8] = v4;
  return result;
}

// File Line: 517
// RVA: 0x2329A0
const char *__fastcall UFG::SectionLayout::GetLayerName(unsigned int layer_index)
{
  __int64 mOffset; // rdx

  mOffset = UFG::gSectionLayout->mLayers.mOffset;
  if ( mOffset )
    return (char *)&UFG::gSectionLayout->mOverrides + 48 * layer_index + mOffset;
  else
    return (const char *)(48i64 * layer_index + 16);
}

// File Line: 531
// RVA: 0x233200
char __fastcall UFG::SectionLayout::IsLookaheadAllowed(unsigned int visIndexFrom, unsigned int visIndexTo)
{
  unsigned int v2; // r8d
  unsigned int mOverrideCount; // r11d
  __int64 v6; // r9
  __int64 mOffset; // r10
  char *v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  char *v11; // rdx

  v2 = 0;
  mOverrideCount = UFG::gSectionLayout->mOverrideCount;
  if ( !mOverrideCount )
    return 1;
  v6 = 0i64;
  mOffset = UFG::gSectionLayout->mOverrides.mOffset;
  while ( 1 )
  {
    v8 = mOffset ? (char *)&UFG::gSectionLayout->mOverrides + mOffset : 0i64;
    v9 = &v8[v6];
    v10 = *(_QWORD *)&v8[v6];
    v11 = v10 ? &v9[v10] : 0i64;
    if ( !*(_DWORD *)v11 )
    {
      if ( v10 )
        v10 += (__int64)v9;
      if ( *(_DWORD *)(v10 + 4) == visIndexFrom && *(_DWORD *)(v10 + 8) == visIndexTo )
        break;
    }
    ++v2;
    v6 += 8i64;
    if ( v2 >= mOverrideCount )
      return 1;
  }
  return 0;
}

// File Line: 678
// RVA: 0x230D40
void __fastcall UFG::SectionLayoutEditorData::Close(UFG::SectionLayoutEditorData *this)
{
  UFG::SectionLayout *v2; // rax
  UFG::qArray<unsigned long,0> *mSectionHighLODTable; // rcx
  unsigned int **p_p; // rbx
  UFG::qArray<unsigned long,0> *mSectionLowLODTable; // rcx
  unsigned int **v6; // rbx
  UFG::SectionLayout *mEditorLayout; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  v2 = UFG::gSectionLayout;
  if ( this->mEditorLayout == UFG::gSectionLayout )
    v2 = UFG::gSectionLayout_Loaded;
  UFG::gSectionLayout = v2;
  mSectionHighLODTable = this->mSectionHighLODTable;
  if ( mSectionHighLODTable )
  {
    p_p = &mSectionHighLODTable[-1].p;
    `eh vector destructor iterator(
      mSectionHighLODTable,
      0x10ui64,
      (int)mSectionHighLODTable[-1].p,
      (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
    operator delete[](p_p);
  }
  this->mSectionHighLODTable = 0i64;
  mSectionLowLODTable = this->mSectionLowLODTable;
  if ( mSectionLowLODTable )
  {
    v6 = &mSectionLowLODTable[-1].p;
    `eh vector destructor iterator(
      mSectionLowLODTable,
      0x10ui64,
      (int)mSectionLowLODTable[-1].p,
      (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
    operator delete[](v6);
  }
  this->mSectionLowLODTable = 0i64;
  operator delete[](this->mSectionTable);
  this->mSectionTable = 0i64;
  mEditorLayout = this->mEditorLayout;
  if ( this->mEditorLayout )
  {
    UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&mEditorLayout->mResourceHandles);
    mPrev = mEditorLayout->mResourceHandles.UFG::qResourceData::mNode.mPrev;
    mNext = mEditorLayout->mResourceHandles.UFG::qResourceData::mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mEditorLayout->mResourceHandles.UFG::qResourceData::mNode.mPrev = &mEditorLayout->mResourceHandles.UFG::qResourceData::mNode;
    mEditorLayout->mResourceHandles.UFG::qResourceData::mNode.mNext = &mEditorLayout->mResourceHandles.UFG::qResourceData::mNode;
    operator delete[](mEditorLayout);
  }
  this->mEditorLayout = 0i64;
  operator delete[](this->mDebugText);
  this->mDebugText = 0i64;
}

