// File Line: 27
// RVA: 0x14B9A70
__int64 dynamic_initializer_for__WeightSetDataBase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WeightSetDataBase", 0xFFFFFFFF);
  WeightSetDataBase::sClassNameUID = result;
  return result;
}

// File Line: 36
// RVA: 0x14BF750
const char *dynamic_initializer_for__sWeightSetList__()
{
  const char *result; // rax

  result = Weightset::sClassName;
  sWeightSetList[0].mClassName = Weightset::sClassName;
  return result;
}

// File Line: 42
// RVA: 0x14BD210
__int64 dynamic_initializer_for__gWeightSetDataFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gWeightSetDataFactory, sWeightSetList, sWeightSetListNum);
  return atexit(dynamic_atexit_destructor_for__gWeightSetDataFactory__);
}

// File Line: 45
// RVA: 0x3AACF0
void WeightSetDataBase::Init(void)
{
  WeightSetDataBase *v0; // rcx
  UFG::allocator::free_link *v1; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v2; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v3; // rax
  UFG::qList<WeightSetGroup,WeightSetGroup,1,0> *v4; // [rsp+58h] [rbp+10h]

  v0 = (WeightSetDataBase *)UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "WeightSetDataBase", 0i64, 1u);
  if ( v0 )
  {
    v0->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
    v0->mResourceOwner = 0i64;
    v0->vfptr = (Expression::IMemberMapVtbl *)&WeightSetDataBase::`vftable;
    v4 = &v0->mWeightSetGroups;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
  }
  else
  {
    v0 = 0i64;
  }
  WeightSetDataBase::sWeightSetDataBase = v0;
  v1 = UFG::qMalloc(0x40ui64, "WeightSetDataBaseHandler", 0i64);
  v2 = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)v1;
  if ( v1 )
  {
    v1->mNext = v1;
    v1[1].mNext = v1;
    v1[2].mNext = 0i64;
    v1[3].mNext = 0i64;
    v1[4].mNext = 0i64;
    v1[5].mNext = 0i64;
    v1[6].mNext = 0i64;
    v1[7].mNext = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  v2[1].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"wst";
  v2[1].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"WeightSets";
  v2[2].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)WeightSetDataBase::LoadWeightSetGroupMemberMap;
  v2[2].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)WeightSetDataBase::NewWeightSetGroupMemberMap;
  v2[3].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)WeightSetGroup::GetResourceOwner;
  v3 = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v2;
  v2->mPrev = v3;
  v2->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev = v2;
}

// File Line: 69
// RVA: 0x3A8ED0
WeightSetDataBase *__fastcall WeightSetDataBase::GetInstance()
{
  return WeightSetDataBase::sWeightSetDataBase;
}

// File Line: 93
// RVA: 0x3AB680
WeightSetDataBase *__fastcall WeightSetDataBase::LoadWeightSetGroup(WeightSetDataBase *this, const char *bankNameFileName)
{
  WeightSetDataBase *v2; // rdi
  UFG::qString *v3; // rax
  UFG::qString *v4; // rbx
  WeightSetDataBase *v5; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  v2 = this;
  UFG::qString::qString(&v7, bankNameFileName);
  v3 = UFG::qString::GetFilenameWithoutExtension(&v7, &result);
  v4 = v3;
  if ( v3->mStringHashUpper32 == -1 )
    v3->mStringHashUpper32 = UFG::qStringHashUpper32(v3->mData, 0xFFFFFFFF);
  v5 = WeightSetDataBase::FindWeightSetGroup(v2, v4->mStringHashUpper32);
  UFG::qString::~qString(&result);
  if ( !v5 )
  {
    UFG::qString::qString(&result);
    UFG::qString::~qString(&result);
  }
  UFG::qString::~qString(&v7);
  return v5;
}

// File Line: 122
// RVA: 0x3A7960
WeightSetDataBase *__fastcall WeightSetDataBase::FindWeightSetGroup(WeightSetDataBase *this, unsigned int bankNameUID)
{
  unsigned int v2; // esi
  WeightSetDataBase *v3; // rdi
  WeightSetDataBase *v4; // rbx
  const char *v5; // rcx

  v2 = bankNameUID;
  v3 = this;
  v4 = (WeightSetDataBase *)&this->mWeightSetGroups.mNode.mNext[-1];
  if ( v4 == this )
    return 0i64;
  while ( 1 )
  {
    v5 = (const char *)((_QWORD)v4[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 ? (WeightSetDataBase *)((char *)&v4[1]
                                                                                           + ((_QWORD)v4[1].vfptr & 0xFFFFFFFFFFFFFFFEui64)) : BinString::sEmptyString);
    if ( (unsigned int)UFG::qStringHashUpper32(v5, 0xFFFFFFFF) == v2 )
      break;
    v4 = (WeightSetDataBase *)&v4->mWeightSetGroups.mNode.mNext[-1];
    if ( v4 == v3 )
      return 0i64;
  }
  return v4;
}

// File Line: 135
// RVA: 0x3ABF50
BinString *__fastcall WeightSetDataBase::NewWeightSetGroupMemberMap(const char *fileName, unsigned __int64 toolVersion)
{
  UFG::qString *v2; // rax
  BinString *v3; // rbx
  UFG::qString v5; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  UFG::qString::qString(&v5, fileName);
  v2 = UFG::qString::GetFilenameWithoutExtension(&v5, &result);
  v3 = WeightSetDataBase::CreateWeightSetGroup(WeightSetDataBase::sWeightSetDataBase, v2->mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v5);
  return v3;
}

// File Line: 141
// RVA: 0x3A66D0
BinString *__fastcall WeightSetDataBase::CreateWeightSetGroup(WeightSetDataBase *this, const char *weightSetGroupName)
{
  const char *v2; // rdi
  WeightSetDataBase *v3; // rsi
  char *v4; // rax
  BinString *v5; // rax
  BinString *v6; // rbx
  BinString *v7; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v8; // rax

  v2 = weightSetGroupName;
  v3 = this;
  v4 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::WeightSetGroup", 0i64, 1u);
  if ( v4 )
  {
    WeightSetGroup::WeightSetGroup((WeightSetGroup *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    BinString::Set(v6 + 4, v2);
    v7 = v6 + 2;
    v8 = v3->mWeightSetGroups.mNode.mPrev;
    v8->mNext = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)&v6[2];
    v7->mOffset = (__int64)v8;
    v7[1].mOffset = (__int64)&v3->mWeightSetGroups;
    v3->mWeightSetGroups.mNode.mPrev = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)&v6[2];
  }
  return v6;
}

// File Line: 160
// RVA: 0x14B9A90
__int64 dynamic_initializer_for__WeightSetGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WeightSetGroup", 0xFFFFFFFF);
  WeightSetGroup::sClassNameUID = result;
  return result;
}

// File Line: 197
// RVA: 0x3A79E0
Weightset *__fastcall WeightSetGroup::FindWeightset(WeightSetGroup *this, UFG::qSymbolUC *weightSetUID)
{
  unsigned int v2; // er8
  unsigned int v3; // er10
  __int64 v4; // r9
  unsigned int v5; // ebx
  UFG::qOffset64<UFG::qOffset64<Weightset *> *> *v6; // r11
  __int64 v7; // rcx
  char *v8; // rax
  char *v9; // rdx
  Weightset *result; // rax

  v2 = 0;
  v3 = this->mWeightsets.mCount & 0x7FFFFFFF;
  if ( !v3 )
    return 0i64;
  v4 = this->mWeightsets.mData.mOffset;
  v5 = weightSetUID->mUID;
  v6 = &this->mWeightsets.mData;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (char *)(v4 ? (UFG::qOffset64<UFG::qOffset64<Weightset *> *> *)((char *)v6 + v4) : 0i64);
    v9 = &v8[v7];
    result = *(Weightset **)&v8[v7];
    if ( result )
      result = (Weightset *)((char *)result + (_QWORD)v9);
    if ( result->mName.mUID == v5 )
      break;
    ++v2;
    v7 += 8i64;
    if ( v2 >= v3 )
      return 0i64;
  }
  return result;
}

// File Line: 212
// RVA: 0x3AEA20
void __fastcall WeightSetGroup::Serialize(WeightSetGroup *this, IActionTreeSerializer *serializer)
{
  IActionTreeSerializer *v2; // r14
  unsigned int v3; // ebx
  WeightSetGroup *v4; // rsi
  __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rdx
  __int64 v8; // rax
  void *v9; // rdi
  __int64 v10; // rax
  __int64 v11; // [rsp+28h] [rbp-30h]
  __int64 v12; // [rsp+30h] [rbp-28h]
  __int64 v13; // [rsp+40h] [rbp-18h]

  v2 = serializer;
  v3 = 0;
  v4 = this;
  if ( this->mWeightsets.mCount & 0x7FFFFFFF )
  {
    do
    {
      v5 = v4->mWeightsets.mData.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v4->mWeightsets.mData + v5;
      else
        v6 = 0i64;
      v7 = v6 + 8i64 * v3;
      v8 = *(_QWORD *)(v6 + 8i64 * v3);
      if ( v8 )
      {
        v9 = (void *)(v8 + v7);
        if ( v8 + v7 )
        {
          v10 = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v9 + 32i64))(v9);
          LODWORD(v13) = -1;
          LODWORD(v12) = 0;
          LODWORD(v11) = 1;
          v2->vfptr->_PushObjectToSerialize(
            v2,
            v9,
            1u,
            (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
            (const char *)v10,
            (QUEUE_PRIORITY)v11,
            v12,
            0i64,
            v13,
            0i64);
        }
      }
      ++v3;
    }
    while ( v3 < (v4->mWeightsets.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 233
// RVA: 0x14BF740
const char *dynamic_initializer_for__sWeightList__()
{
  const char *result; // rax

  result = WeightsetEntry::sClassName;
  sWeightList[0].mClassName = WeightsetEntry::sClassName;
  return result;
}

// File Line: 239
// RVA: 0x14BD1E0
__int64 dynamic_initializer_for__gWeightFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gWeightFactory, sWeightList, sWeightListNum);
  return atexit(dynamic_atexit_destructor_for__gWeightFactory__);
}

// File Line: 241
// RVA: 0x14B9AB0
__int64 dynamic_initializer_for__Weightset::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Weightset", 0xFFFFFFFF);
  Weightset::sClassNameUID = result;
  return result;
}

// File Line: 249
// RVA: 0x39EA90
void __fastcall Weightset::Weightset(Weightset *this, MemImageLoadFlag flag)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Weightset::`vftable;
}

// File Line: 267
// RVA: 0x39FFF0
void __fastcall Weightset::~Weightset(Weightset *this)
{
  Weightset *v1; // rbx
  __int64 v2; // rax
  __int64 v3; // rax
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Weightset::`vftable;
  v2 = this->mRawWeightSet.mOffset;
  if ( v2 && (UFG::qOffset64<float *> *)((char *)&this->mRawWeightSet + v2) )
  {
    v3 = this->mRawWeightSet.mOffset;
    if ( v3 )
      v4 = (char *)&this->mRawWeightSet + v3;
    else
      v4 = 0i64;
    operator delete[](v4);
  }
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&v1->mWeightsetEntires);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 318
// RVA: 0x3B6B10
void __fastcall fnArraySerializer(void *ptr, unsigned int count, IActionTreeSerializer *serializer, const char *className, unsigned int size, void (__fastcall *serializeFunction)(IActionTreeSerializer *, void *))
{
  IActionTreeSerializer *v6; // rsi
  char *v7; // rbx
  __int64 v8; // rdi

  if ( count )
  {
    v6 = serializer;
    v7 = (char *)ptr;
    v8 = count;
    do
    {
      ((void (__fastcall *)(IActionTreeSerializer *, char *, const char *, const char *))v6->vfptr->Serialize)(
        v6,
        v7,
        "element",
        className);
      v7 += 4;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 328
// RVA: 0x3AEB00
void __fastcall Weightset::Serialize(Weightset *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  UFG::qOffset64<float *> *v3; // rdi
  IActionTreeSerializer *v4; // r14
  Weightset *v5; // rbx
  int v6; // ecx
  float v7; // xmm0_4
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  signed __int64 v10; // rax
  unsigned int v11; // ecx
  __int64 v12; // rax
  signed __int64 v13; // rdx
  __int64 v14; // r9
  signed __int64 v15; // rax
  __int64 v16; // rdx
  signed __int64 v17; // r8
  char *v18; // rdx
  char *v19; // rdx
  __int64 v20; // rax
  char *v21; // rdx
  unsigned int v22; // edi
  __int64 v23; // rax
  signed __int64 v24; // rcx
  signed __int64 v25; // rdx
  __int64 v26; // rax
  void *v27; // rsi
  __int64 v28; // rax
  __int64 v29; // [rsp+28h] [rbp-30h]
  __int64 v30; // [rsp+30h] [rbp-28h]
  __int64 v31; // [rsp+40h] [rbp-18h]

  v2 = this->mRawWeightSet.mOffset;
  v3 = &this->mRawWeightSet;
  v4 = serializer;
  v5 = this;
  if ( !v2 || !(UFG::qOffset64<float *> *)((char *)v3 + v2) )
  {
    v6 = this->mWeightsetEntires.mCount & 0x7FFFFFFF;
    v5->mRawWeightSetLength = v6;
    v7 = (float)v6 * 1.5;
    v5->mRawWeightSetPaddedLength = (signed int)v7;
    v8 = 4i64 * (unsigned int)(signed int)v7;
    if ( !is_mul_ok((unsigned int)(signed int)v7, 4ui64) )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, UFG::gGlobalNewName, 0i64);
    if ( v9 )
      v10 = (char *)v9 - (char *)v3;
    else
      v10 = 0i64;
    v3->mOffset = v10;
    v11 = 0;
    if ( v5->mWeightsetEntires.mCount & 0x7FFFFFFF )
    {
      do
      {
        v12 = v5->mWeightsetEntires.mData.mOffset;
        if ( v12 )
          v13 = (signed __int64)&v5->mWeightsetEntires.mData + v12;
        else
          v13 = 0i64;
        v14 = v11;
        v15 = v13 + 8i64 * v11;
        v16 = *(_QWORD *)(v13 + 8i64 * v11);
        v17 = v16 + v15;
        if ( !v16 )
          v17 = 0i64;
        v18 = (char *)v3 + v3->mOffset;
        if ( !v3->mOffset )
          v18 = 0i64;
        ++v11;
        *(_DWORD *)&v18[4 * v14] = *(_DWORD *)(v17 + 24);
      }
      while ( v11 < (v5->mWeightsetEntires.mCount & 0x7FFFFFFFu) );
    }
    for ( ; v11 < v5->mRawWeightSetPaddedLength; *(_DWORD *)&v19[4 * v20] = 1132396544 )
    {
      v19 = (char *)v3 + v3->mOffset;
      if ( !v3->mOffset )
        v19 = 0i64;
      v20 = v11++;
    }
  }
  v21 = (char *)v3 + v3->mOffset;
  if ( !v3->mOffset )
    v21 = 0i64;
  v4->vfptr->_PushObjectToSerialize(
    v4,
    v21,
    v5->mRawWeightSetPaddedLength,
    fnArraySerializer,
    &customWorldMapCaption,
    PRIORITY_MEDIUM,
    16u,
    0i64,
    0,
    0i64);
  v22 = 0;
  if ( v5->mWeightsetEntires.mCount & 0x7FFFFFFF )
  {
    do
    {
      v23 = v5->mWeightsetEntires.mData.mOffset;
      if ( v23 )
        v24 = (signed __int64)&v5->mWeightsetEntires.mData + v23;
      else
        v24 = 0i64;
      v25 = v24 + 8i64 * v22;
      v26 = *(_QWORD *)(v24 + 8i64 * v22);
      if ( v26 )
      {
        v27 = (void *)(v26 + v25);
        if ( v26 + v25 )
        {
          v28 = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v27 + 32i64))(v27);
          LODWORD(v31) = -1;
          LODWORD(v30) = 0;
          LODWORD(v29) = 1;
          v4->vfptr->_PushObjectToSerialize(
            v4,
            v27,
            1u,
            (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
            (const char *)v28,
            (QUEUE_PRIORITY)v29,
            v30,
            0i64,
            v31,
            0i64);
        }
      }
      ++v22;
    }
    while ( v22 < (v5->mWeightsetEntires.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 368
// RVA: 0x3AA450
float *__fastcall Weightset::GetWeights(Weightset *this, int numBones, float weight, bool forceCopy)
{
  signed __int64 v4; // rbx
  Weightset *v5; // rdi
  __int64 v6; // rax
  float *result; // rax
  float *v8; // r10
  float v9; // xmm0_4
  __int64 v10; // rax
  int v11; // edx
  signed int v12; // er9
  unsigned __int64 v13; // r8
  __int64 v14; // rcx
  __m128 v15; // xmm1
  int v16; // eax
  __int64 v17; // r11
  __int64 v18; // rdi
  unsigned __int64 v19; // r9
  signed __int64 v20; // rcx
  unsigned __int64 v21; // rax
  __int64 v22; // rdi
  unsigned __int64 v23; // r8
  signed __int64 v24; // rax
  float *v25; // rdi
  signed __int64 i; // rcx

  v4 = numBones;
  v5 = this;
  if ( weight != 1.0 || numBones > this->mRawWeightSetPaddedLength || forceCopy )
  {
    v8 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * numBones, 0x10u);
    v9 = (float)(v5->mWeightsetEntires.mCount & 0x7FFFFFFF);
    if ( v9 >= (float)(signed int)v4 )
      v9 = (float)(signed int)v4;
    v10 = v5->mRawWeightSet.mOffset;
    v11 = 0;
    v12 = (signed int)v9;
    if ( v10 )
      v13 = (unsigned __int64)&v5->mRawWeightSet + v10;
    else
      v13 = 0i64;
    if ( v12 > 0 && (unsigned int)v12 >= 8 )
    {
      v14 = v12 - 1;
      v15 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
      if ( (unsigned __int64)v8 > v13 + 4 * v14 || (unsigned __int64)&v8[v14] < v13 )
      {
        do
        {
          *(__m128 *)&v8[v11] = _mm_mul_ps(*(__m128 *)(v13 + 4i64 * v11), v15);
          v16 = v11 + 4;
          v11 += 8;
          *(__m128 *)&v8[v16] = _mm_mul_ps(*(__m128 *)(v13 + 4i64 * v16), v15);
        }
        while ( v11 < v12 - v12 % 8 );
      }
    }
    v17 = v11;
    v18 = v12;
    if ( v11 < (signed __int64)v12 )
    {
      if ( v12 - (signed __int64)v11 >= 4 )
      {
        v19 = v13 - (_QWORD)v8;
        v20 = (signed __int64)&v8[v11 + 1];
        v21 = ((unsigned __int64)(v18 - v11 - 4) >> 2) + 1;
        v11 += 4 * v21;
        v17 += 4 * v21;
        do
        {
          v20 += 16i64;
          *(float *)(v20 - 20) = weight * *(float *)(v19 + v20 - 20);
          *(float *)(v20 - 16) = weight * *(float *)(v19 + v20 - 16);
          *(float *)(v20 - 12) = weight * *(float *)(v19 + v20 - 12);
          *(float *)(v20 - 8) = weight * *(float *)(v19 + v20 - 8);
          --v21;
        }
        while ( v21 );
      }
      if ( v17 < v18 )
      {
        v22 = v18 - v17;
        v23 = v13 - (_QWORD)v8;
        v24 = (signed __int64)&v8[v17];
        v11 += v22;
        do
        {
          v24 += 4i64;
          *(float *)(v24 - 4) = weight * *(float *)(v23 + v24 - 4);
          --v22;
        }
        while ( v22 );
      }
    }
    if ( v11 < v4 )
    {
      v25 = &v8[v11];
      for ( i = v4 - v11; i; --i )
      {
        *v25 = weight * 255.0;
        ++v25;
      }
    }
    result = v8;
  }
  else
  {
    v6 = this->mRawWeightSet.mOffset;
    if ( v6 )
      result = (float *)((char *)&this->mRawWeightSet + v6);
    else
      result = 0i64;
  }
  return result;
}

// File Line: 422
// RVA: 0x3AB7D0
void __fastcall Weightset::MaskWeights(Weightset *this, float *weights, int numWeights)
{
  signed __int64 v3; // r9
  float *v4; // r10
  float v5; // xmm0_4
  __int64 v6; // rax
  signed int v7; // edi
  char *v8; // rdx
  __int64 v9; // rcx
  int v10; // er8
  float *v11; // rax
  signed __int64 v12; // rdx
  float *v13; // rdi
  signed __int64 i; // rcx

  v3 = numWeights;
  v4 = weights;
  v5 = (float)(this->mWeightsetEntires.mCount & 0x7FFFFFFF);
  if ( v5 >= (float)numWeights )
    v5 = (float)numWeights;
  v6 = this->mRawWeightSet.mOffset;
  v7 = (signed int)v5;
  if ( v6 )
  {
    v8 = (char *)&this->mRawWeightSet + v6;
    if ( v8 )
    {
      v9 = v7;
      v10 = 0;
      if ( v7 > 0 )
      {
        v11 = v4;
        v12 = v8 - (char *)v4;
        v10 = v9;
        do
        {
          if ( 0.0 == *(float *)((char *)v11 + v12) )
            *v11 = 0.0;
          ++v11;
          --v9;
        }
        while ( v9 );
      }
      if ( v10 < v3 )
      {
        v13 = &v4[v10];
        for ( i = v3 - v10; i; --i )
        {
          *v13 = 0.0;
          ++v13;
        }
      }
    }
  }
}

// File Line: 473
// RVA: 0x14B9AD0
__int64 dynamic_initializer_for__WeightsetEntry::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WeightsetEntry", 0xFFFFFFFF);
  WeightsetEntry::sClassNameUID = result;
  return result;
}

// File Line: 485
// RVA: 0x3A0060
void __fastcall WeightsetEntry::~WeightsetEntry(WeightsetEntry *this)
{
  WeightsetEntry *v1; // rbx
  char *v2; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&WeightsetEntry::`vftable;
  if ( !(~LOBYTE(this->mName.mOffset) & 1) )
  {
    if ( this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

