// File Line: 46
// RVA: 0x14703F0
__int64 UFG::_dynamic_initializer_for__gSectionLayoutInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gSectionLayoutInventory.vfptr,
    "SectionLayoutInventory",
    0xEC35A8A0,
    0x3E50F7D5u,
    0,
    0);
  UFG::gSectionLayoutInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SectionLayoutInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gSectionLayoutInventory__);
}

// File Line: 54
// RVA: 0x230270
void __fastcall UFG::SectionLayoutInventory::Add(UFG::SectionLayoutInventory *this, UFG::qResourceData *resource_data)
{
  UFG::SectionLayout *v2; // rbx
  UFG::SectionLayoutInventory *v3; // rdi

  v2 = (UFG::SectionLayout *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::gSectionLayout = v2;
  UFG::gSectionLayout_Loaded = v2;
  UFG::SectionLayout::BuildLayerTweakers();
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
}

// File Line: 73
// RVA: 0x234FF0
void __fastcall UFG::SectionLayoutInventory::Remove(UFG::SectionLayoutInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  if ( !(_S1_27 & 1) )
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
  UFG::SectionLayout *v1; // rcx
  __int64 v2; // rax
  signed __int64 v3; // rcx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v0 = 0i64;
  v1 = UFG::gSectionLayout;
  if ( UFG::gSectionLayout->mLayerCount )
  {
    do
    {
      v2 = v1->mLayers.mOffset;
      if ( v2 )
        v3 = (signed __int64)&v1->mLayers + v2;
      else
        v3 = 0i64;
      UFG::qString::FormatEx(&result, "\\Streaming\\Layers\\%s", v3 + 16 + 48 * v0);
      UFG::qString::~qString(&result);
      v0 = (unsigned int)(v0 + 1);
      v1 = UFG::gSectionLayout;
    }
    while ( (unsigned int)v0 < UFG::gSectionLayout->mLayerCount );
  }
}

// File Line: 120
// RVA: 0x232B70
signed __int64 __fastcall UFG::SectionLayout::GetSectionFromCellIndex(unsigned int sectionIndex)
{
  __int64 v1; // rdx
  signed __int64 result; // rax

  v1 = UFG::gSectionLayout->mSections.mOffset;
  if ( v1 )
    result = (signed __int64)&UFG::gSectionLayout->mSections + 48 * sectionIndex + v1;
  else
    result = 48i64 * sectionIndex;
  return result;
}

// File Line: 151
// RVA: 0x232BE0
__int64 __fastcall UFG::SectionLayout::GetSectionUIDFromIndex(unsigned int cell_index)
{
  __int64 v1; // rdx
  __int64 result; // rax

  v1 = UFG::gSectionLayout->mSections.mOffset;
  if ( v1 )
    result = *(unsigned int *)((char *)&UFG::gSectionLayout->mSections.mOffset + 48 * cell_index + v1);
  else
    result = *(unsigned int *)(48i64 * cell_index);
  return result;
}

// File Line: 187
// RVA: 0x232870
__int64 __fastcall UFG::SectionLayout::GetHighLODSectionVisIndices(unsigned int visIndex, unsigned int *outputBuffer, unsigned int outputBufferSize)
{
  __int64 v3; // r9
  unsigned int *v4; // r11
  unsigned int v5; // er8
  char *v6; // r9
  signed __int64 v7; // r10
  unsigned int i; // edx
  __int64 v9; // rax
  signed __int64 v10; // rcx
  unsigned int v11; // er9
  __int64 v12; // rcx

  *outputBuffer = visIndex;
  v3 = UFG::gSectionLayout->mSectionVis.mOffset;
  v4 = outputBuffer;
  v5 = 1;
  if ( v3 )
    v6 = (char *)&UFG::gSectionLayout->mSectionVis + v3;
  else
    v6 = 0i64;
  v7 = (signed __int64)&v6[96 * visIndex];
  if ( *(_QWORD *)(v7 + 8) )
  {
    for ( i = 0; i < *(unsigned __int16 *)(v7 + 4); ++i )
    {
      v9 = *(_QWORD *)(v7 + 8);
      if ( v9 )
        v10 = v9 + v7 + 8;
      else
        v10 = 0i64;
      v11 = *(unsigned __int16 *)(v10 + 2i64 * i);
      if ( v11 != -1 )
      {
        v12 = v5++;
        v4[v12] = v11;
      }
    }
  }
  return v5;
}

// File Line: 211
// RVA: 0x2329E0
__int64 __fastcall UFG::SectionLayout::GetLowLODSectionVisIndices(unsigned int visIndex, unsigned int *outputBuffer, unsigned int outputBufferSize)
{
  __int64 v3; // r9
  unsigned int *v4; // r11
  unsigned int v5; // er8
  char *v6; // r9
  signed __int64 v7; // r10
  unsigned int i; // edx
  __int64 v9; // rax
  signed __int64 v10; // rcx
  unsigned int v11; // er9
  __int64 v12; // rcx

  *outputBuffer = visIndex;
  v3 = UFG::gSectionLayout->mSectionVis.mOffset;
  v4 = outputBuffer;
  v5 = 1;
  if ( v3 )
    v6 = (char *)&UFG::gSectionLayout->mSectionVis + v3;
  else
    v6 = 0i64;
  v7 = (signed __int64)&v6[96 * visIndex];
  if ( *(_QWORD *)(v7 + 16) )
  {
    for ( i = 0; i < *(unsigned __int16 *)(v7 + 6); ++i )
    {
      v9 = *(_QWORD *)(v7 + 16);
      if ( v9 )
        v10 = v9 + v7 + 16;
      else
        v10 = 0i64;
      v11 = *(unsigned __int16 *)(v10 + 2i64 * i);
      if ( v11 != -1 )
      {
        v12 = v5++;
        v4[v12] = v11;
      }
    }
  }
  return v5;
}

// File Line: 234
// RVA: 0x232A70
__int64 __fastcall UFG::SectionLayout::GetLowLODSectionVisIndices_HD(unsigned int visIndex, unsigned int *outputBuffer, unsigned int outputBufferSize)
{
  unsigned int *v3; // r11
  __int64 v4; // r9
  unsigned int v5; // er8
  signed __int64 v6; // r10
  __int64 v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  unsigned int v10; // er9
  __int64 v11; // rcx

  *outputBuffer = visIndex;
  v3 = outputBuffer;
  v4 = UFG::gSectionLayout->mSectionVis.mOffset;
  v5 = 1;
  if ( v4 )
    v4 += (__int64)&UFG::gSectionLayout->mSectionVis;
  v6 = v4 + 96i64 * visIndex;
  if ( *(_QWORD *)(v6 + 80) )
  {
    v7 = 0i64;
    if ( *(_DWORD *)(v6 + 72) )
    {
      do
      {
        v8 = *(_QWORD *)(v6 + 80);
        if ( v8 )
          v9 = v8 + v6 + 80;
        else
          v9 = 0i64;
        v10 = *(unsigned __int16 *)(v9 + 2 * v7);
        if ( v10 != -1 )
        {
          v11 = v5++;
          v3[v11] = v10;
        }
        v7 = (unsigned int)(v7 + 1);
      }
      while ( (unsigned int)v7 < *(_DWORD *)(v6 + 72) );
    }
  }
  return v5;
}

// File Line: 353
// RVA: 0x232BB0
char *__fastcall UFG::SectionLayout::GetSectionNameFromCellIndex(unsigned int sectionIndex)
{
  __int64 v1; // rdx
  UFG::Section *v2; // rax
  char *result; // rax

  v1 = UFG::gSectionLayout->mSections.mOffset;
  if ( v1 )
    v1 += (__int64)&UFG::gSectionLayout->mSections;
  v2 = (UFG::Section *)(v1 + 0x30i64 * sectionIndex);
  if ( v2 )
    result = v2->mName;
  else
    result = 0i64;
  return result;
}

// File Line: 456
// RVA: 0x232840
__int64 __fastcall UFG::SectionLayout::GetFlags(unsigned int sectionIndex)
{
  __int64 v1; // rdx
  signed __int64 v2; // rcx
  __int64 result; // rax

  v1 = UFG::gSectionLayout->mSections.mOffset;
  if ( v1 )
    v1 += (__int64)&UFG::gSectionLayout->mSections;
  v2 = v1 + 48i64 * sectionIndex;
  if ( v2 )
    result = *(unsigned __int16 *)(v2 + 4);
  else
    result = 0i64;
  return result;
}

// File Line: 468
// RVA: 0x232900
__int64 __fastcall UFG::SectionLayout::GetLayerCount()
{
  return UFG::gSectionLayout->mLayerCount;
}

// File Line: 473
// RVA: 0x232910
signed __int64 __fastcall UFG::SectionLayout::GetLayerIndex(const char *layer_name)
{
  UFG::SectionLayout *v1; // rdx
  __int64 v2; // rbx
  const char *v3; // rsi
  unsigned int v4; // edi
  __int64 v5; // rax
  signed __int64 v6; // r8

  v1 = UFG::gSectionLayout;
  v2 = 0i64;
  v3 = layer_name;
  v4 = UFG::gSectionLayout->mLayerCount;
  if ( !v4 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = v1->mLayers.mOffset;
    v6 = (signed __int64)(v5 ? (UFG::qOffset64<UFG::Layer *> *)((char *)&v1->mLayers + v5) : 0i64);
    if ( !(unsigned int)UFG::qStringCompareInsensitive((const char *)(v6 + 48 * v2 + 16), v3, -1) )
      break;
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= v4 )
      return 0xFFFFFFFFi64;
    v1 = UFG::gSectionLayout;
  }
  return (unsigned int)v2;
}

// File Line: 496
// RVA: 0x2350A0
char __fastcall UFG::SectionLayout::SetLayerActive(unsigned int layer_index, bool active)
{
  int v2; // er8
  __int64 v3; // r9
  char *v4; // r9
  char result; // al

  if ( layer_index == -1 )
    return 0;
  v2 = 0;
  v3 = UFG::gSectionLayout->mLayers.mOffset;
  if ( v3 )
    v4 = (char *)&UFG::gSectionLayout->mLayers + v3;
  else
    v4 = 0i64;
  LOBYTE(v2) = active != 0;
  result = 1;
  *(_DWORD *)&v4[48 * layer_index + 8] = v2;
  return result;
}

// File Line: 510
// RVA: 0x2350F0
char __fastcall UFG::SectionLayout::SetLayerActive(const char *layer_name, bool active)
{
  bool v2; // bl
  unsigned int v3; // eax
  int v4; // er8
  __int64 v5; // r9
  char *v6; // rdx
  signed __int64 v7; // rcx
  char result; // al

  v2 = active;
  v3 = UFG::SectionLayout::GetLayerIndex(layer_name);
  if ( v3 == -1 )
    return 0;
  v4 = 0;
  v5 = UFG::gSectionLayout->mLayers.mOffset;
  if ( v5 )
    v6 = (char *)&UFG::gSectionLayout->mLayers + v5;
  else
    v6 = 0i64;
  v7 = 3i64 * v3;
  LOBYTE(v4) = v2 != 0;
  result = 1;
  *(_DWORD *)&v6[16 * v7 + 8] = v4;
  return result;
}

// File Line: 517
// RVA: 0x2329A0
const char *__fastcall UFG::SectionLayout::GetLayerName(unsigned int layer_index)
{
  __int64 v1; // rdx
  const char *result; // rax

  v1 = UFG::gSectionLayout->mLayers.mOffset;
  if ( v1 )
    result = (char *)&UFG::gSectionLayout->mOverrides + 48 * layer_index + v1;
  else
    result = (const char *)(48i64 * layer_index + 16);
  return result;
}

// File Line: 531
// RVA: 0x233200
char __fastcall UFG::SectionLayout::IsLookaheadAllowed(unsigned int visIndexFrom, unsigned int visIndexTo)
{
  unsigned int v2; // er8
  unsigned int v3; // edi
  unsigned int v4; // er11
  unsigned int v5; // esi
  __int64 v6; // r9
  __int64 v7; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::Override *> *> *v8; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::Override *> *> *v9; // rcx
  __int64 v10; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::Override *> *> *v11; // rdx

  v2 = 0;
  v3 = visIndexTo;
  v4 = UFG::gSectionLayout->mOverrideCount;
  v5 = visIndexFrom;
  if ( !v4 )
    return 1;
  v6 = 0i64;
  v7 = UFG::gSectionLayout->mOverrides.mOffset;
  while ( 1 )
  {
    v8 = v7 ? (UFG::qOffset64<UFG::qOffset64<UFG::Override *> *> *)((char *)&UFG::gSectionLayout->mOverrides + v7) : 0i64;
    v9 = &v8[v6];
    v10 = v8[v6].mOffset;
    v11 = v10 ? (UFG::qOffset64<UFG::qOffset64<UFG::Override *> *> *)((char *)v9 + v10) : 0i64;
    if ( !LODWORD(v11->mOffset) )
    {
      if ( v10 )
        v10 += (__int64)v9;
      if ( *(_DWORD *)(v10 + 4) == v5 && *(_DWORD *)(v10 + 8) == v3 )
        break;
    }
    ++v2;
    ++v6;
    if ( v2 >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 678
// RVA: 0x230D40
void __fastcall UFG::SectionLayoutEditorData::Close(UFG::SectionLayoutEditorData *this)
{
  UFG::SectionLayoutEditorData *v1; // rdi
  UFG::SectionLayout *v2; // rax
  UFG::qArray<unsigned long,0> *v3; // rcx
  unsigned int **v4; // rbx
  UFG::qArray<unsigned long,0> *v5; // rcx
  unsigned int **v6; // rbx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v7; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rax

  v1 = this;
  v2 = UFG::gSectionLayout;
  if ( this->mEditorLayout == UFG::gSectionLayout )
    v2 = UFG::gSectionLayout_Loaded;
  UFG::gSectionLayout = v2;
  v3 = this->mSectionHighLODTable;
  if ( v3 )
  {
    v4 = &v3[-1].p;
    `eh vector destructor iterator'(
      v3,
      0x10ui64,
      (int)v3[-1].p,
      (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
    operator delete[](v4);
  }
  v1->mSectionHighLODTable = 0i64;
  v5 = v1->mSectionLowLODTable;
  if ( v5 )
  {
    v6 = &v5[-1].p;
    `eh vector destructor iterator'(
      v5,
      0x10ui64,
      (int)v5[-1].p,
      (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
    operator delete[](v6);
  }
  v1->mSectionLowLODTable = 0i64;
  operator delete[](v1->mSectionTable);
  v1->mSectionTable = 0i64;
  v7 = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v1->mEditorLayout;
  if ( v1->mEditorLayout )
  {
    UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(v7 + 2);
    v8 = v7[2].mNode.mPrev;
    v9 = v7[2].mNode.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7[2].mNode.mPrev = &v7[2].mNode;
    v7[2].mNode.mNext = &v7[2].mNode;
    operator delete[](v7);
  }
  v1->mEditorLayout = 0i64;
  operator delete[](v1->mDebugText);
  v1->mDebugText = 0i64;
}

