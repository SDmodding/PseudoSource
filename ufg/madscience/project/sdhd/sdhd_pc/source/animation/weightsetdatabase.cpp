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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gWeightSetDataFactory__);
}

// File Line: 45
// RVA: 0x3AACF0
void WeightSetDataBase::Init(void)
{
  WeightSetDataBase *v0; // rcx
  UFG::allocator::free_link *v1; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v2; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *mPrev; // rax

  v0 = (WeightSetDataBase *)UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "WeightSetDataBase", 0i64, 1u);
  if ( v0 )
  {
    v0->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
    v0->mResourceOwner = 0i64;
    v0->vfptr = (Expression::IMemberMapVtbl *)&WeightSetDataBase::`vftable;
    v0->mWeightSetGroups.mNode.mPrev = &v0->mWeightSetGroups.mNode;
    v0->mWeightSetGroups.mNode.mNext = &v0->mWeightSetGroups.mNode;
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
  mPrev = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v2;
  v2->mPrev = mPrev;
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
WeightSetDataBase *__fastcall WeightSetDataBase::LoadWeightSetGroup(
        WeightSetDataBase *this,
        const char *bankNameFileName)
{
  UFG::qString *FilenameWithoutExtension; // rax
  UFG::qString *v4; // rbx
  WeightSetDataBase *WeightSetGroup; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v7, bankNameFileName);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v7, &result);
  v4 = FilenameWithoutExtension;
  if ( FilenameWithoutExtension->mStringHashUpper32 == -1 )
    FilenameWithoutExtension->mStringHashUpper32 = UFG::qStringHashUpper32(FilenameWithoutExtension->mData, -1);
  WeightSetGroup = WeightSetDataBase::FindWeightSetGroup(this, v4->mStringHashUpper32);
  UFG::qString::~qString(&result);
  if ( !WeightSetGroup )
  {
    UFG::qString::qString(&result);
    UFG::qString::~qString(&result);
  }
  UFG::qString::~qString(&v7);
  return WeightSetGroup;
}

// File Line: 122
// RVA: 0x3A7960
WeightSetDataBase *__fastcall WeightSetDataBase::FindWeightSetGroup(WeightSetDataBase *this, unsigned int bankNameUID)
{
  WeightSetDataBase *v4; // rbx
  const char *v5; // rcx

  v4 = (WeightSetDataBase *)&this->mWeightSetGroups.mNode.mNext[-1];
  if ( v4 == this )
    return 0i64;
  while ( 1 )
  {
    v5 = ((unsigned __int64)v4[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0
       ? (char *)&v4[1] + ((unsigned __int64)v4[1].vfptr & 0xFFFFFFFFFFFFFFFEui64)
       : BinString::sEmptyString;
    if ( (unsigned int)UFG::qStringHashUpper32(v5, -1) == bankNameUID )
      break;
    v4 = (WeightSetDataBase *)&v4->mWeightSetGroups.mNode.mNext[-1];
    if ( v4 == this )
      return 0i64;
  }
  return v4;
}

// File Line: 135
// RVA: 0x3ABF50
WeightSetGroup *__fastcall WeightSetDataBase::NewWeightSetGroupMemberMap(
        const char *fileName,
        unsigned __int64 toolVersion)
{
  UFG::qString *FilenameWithoutExtension; // rax
  WeightSetGroup *WeightSetGroup; // rbx
  UFG::qString v5; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v5, fileName);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v5, &result);
  WeightSetGroup = WeightSetDataBase::CreateWeightSetGroup(
                     WeightSetDataBase::sWeightSetDataBase,
                     FilenameWithoutExtension->mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v5);
  return WeightSetGroup;
}

// File Line: 141
// RVA: 0x3A66D0
WeightSetGroup *__fastcall WeightSetDataBase::CreateWeightSetGroup(WeightSetDataBase *this, char *weightSetGroupName)
{
  char *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *mPrev; // rax

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
    BinString::Set((BinString *)(v6 + 32), weightSetGroupName);
    mPrev = this->mWeightSetGroups.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)(v6 + 16);
    *(_QWORD *)(v6 + 16) = mPrev;
    *(_QWORD *)(v6 + 24) = &this->mWeightSetGroups;
    this->mWeightSetGroups.mNode.mPrev = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)(v6 + 16);
  }
  return (WeightSetGroup *)v6;
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
  int v2; // r8d
  unsigned int v3; // r10d
  __int64 mOffset; // r9
  unsigned int mUID; // ebx
  UFG::qOffset64<UFG::qOffset64<Weightset *> *> *p_mData; // r11
  __int64 i; // rcx
  char *v8; // rax
  char *v9; // rdx
  Weightset *result; // rax

  v2 = 0;
  v3 = this->mWeightsets.mCount & 0x7FFFFFFF;
  if ( !v3 )
    return 0i64;
  mOffset = this->mWeightsets.mData.mOffset;
  mUID = weightSetUID->mUID;
  p_mData = &this->mWeightsets.mData;
  for ( i = 0i64; ; i += 8i64 )
  {
    v8 = mOffset ? (char *)p_mData + mOffset : 0i64;
    v9 = &v8[i];
    result = *(Weightset **)&v8[i];
    if ( result )
      result = (Weightset *)((char *)result + (_QWORD)v9);
    if ( result->mName.mUID == mUID )
      break;
    if ( ++v2 >= v3 )
      return 0i64;
  }
  return result;
}

// File Line: 212
// RVA: 0x3AEA20
void __fastcall WeightSetGroup::Serialize(WeightSetGroup *this, IActionTreeSerializer *serializer)
{
  unsigned int v3; // ebx
  __int64 mOffset; // rax
  char *v6; // rcx
  char *v7; // rdx
  __int64 v8; // rax
  char *v9; // rdi
  const char *v10; // rax

  v3 = 0;
  if ( (this->mWeightsets.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      mOffset = this->mWeightsets.mData.mOffset;
      if ( mOffset )
        v6 = (char *)&this->mWeightsets.mData + mOffset;
      else
        v6 = 0i64;
      v7 = &v6[8 * v3];
      v8 = *(_QWORD *)v7;
      if ( *(_QWORD *)v7 )
      {
        v9 = &v7[v8];
        if ( &v7[v8] )
        {
          v10 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 32i64))(v9);
          serializer->vfptr->_PushObjectToSerialize(
            serializer,
            v9,
            1u,
            (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
            v10,
            PRIORITY_MEDIUM,
            0,
            0i64,
            -1u,
            0i64);
        }
      }
      ++v3;
    }
    while ( v3 < (this->mWeightsets.mCount & 0x7FFFFFFFu) );
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gWeightFactory__);
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
  __int64 mOffset; // rax
  __int64 v3; // rax
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&Weightset::`vftable;
  mOffset = this->mRawWeightSet.mOffset;
  if ( mOffset && (UFG::qOffset64<float *> *)((char *)&this->mRawWeightSet + mOffset) )
  {
    v3 = this->mRawWeightSet.mOffset;
    if ( v3 )
      v4 = (char *)&this->mRawWeightSet + v3;
    else
      v4 = 0i64;
    operator delete[](v4);
  }
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&this->mWeightsetEntires);
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 318
// RVA: 0x3B6B10
void __fastcall fnArraySerializer(
        char *ptr,
        unsigned int count,
        IActionTreeSerializer *serializer,
        const char *className,
        unsigned int size,
        void (__fastcall *serializeFunction)(IActionTreeSerializer *, void *))
{
  __int64 v8; // rdi

  if ( count )
  {
    v8 = count;
    do
    {
      ((void (__fastcall *)(IActionTreeSerializer *, char *, const char *, const char *))serializer->vfptr->Serialize)(
        serializer,
        ptr,
        "element",
        className);
      ptr += 4;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 328
// RVA: 0x3AEB00
void __fastcall Weightset::Serialize(Weightset *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  UFG::qOffset64<float *> *p_mRawWeightSet; // rdi
  int v6; // ecx
  float v7; // xmm0_4
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  unsigned int v11; // ecx
  __int64 v12; // rax
  char *v13; // rdx
  __int64 v14; // r9
  char *v15; // rax
  char *v16; // r8
  char *v17; // rdx
  char *v18; // rdx
  __int64 v19; // rax
  char *v20; // rdx
  unsigned int v21; // edi
  __int64 v22; // rax
  char *v23; // rcx
  char *v24; // rdx
  __int64 v25; // rax
  char *v26; // rsi
  const char *v27; // rax

  mOffset = this->mRawWeightSet.mOffset;
  p_mRawWeightSet = &this->mRawWeightSet;
  if ( !mOffset || !(UFG::qOffset64<float *> *)((char *)p_mRawWeightSet + mOffset) )
  {
    v6 = this->mWeightsetEntires.mCount & 0x7FFFFFFF;
    this->mRawWeightSetLength = v6;
    v7 = (float)v6 * 1.5;
    this->mRawWeightSetPaddedLength = (int)v7;
    v8 = 4i64 * (unsigned int)(int)v7;
    if ( !is_mul_ok((unsigned int)(int)v7, 4ui64) )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, UFG::gGlobalNewName, 0i64);
    if ( v9 )
      v10 = (char *)v9 - (char *)p_mRawWeightSet;
    else
      v10 = 0i64;
    p_mRawWeightSet->mOffset = v10;
    v11 = 0;
    if ( (this->mWeightsetEntires.mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v12 = this->mWeightsetEntires.mData.mOffset;
        if ( v12 )
          v13 = (char *)&this->mWeightsetEntires.mData + v12;
        else
          v13 = 0i64;
        v14 = v11;
        v15 = &v13[8 * v11];
        v16 = &v15[*(_QWORD *)v15];
        if ( !*(_QWORD *)v15 )
          v16 = 0i64;
        v17 = (char *)p_mRawWeightSet + p_mRawWeightSet->mOffset;
        if ( !p_mRawWeightSet->mOffset )
          v17 = 0i64;
        ++v11;
        *(_DWORD *)&v17[4 * v14] = *((_DWORD *)v16 + 6);
      }
      while ( v11 < (this->mWeightsetEntires.mCount & 0x7FFFFFFFu) );
    }
    for ( ; v11 < this->mRawWeightSetPaddedLength; *(_DWORD *)&v18[4 * v19] = 1132396544 )
    {
      v18 = (char *)p_mRawWeightSet + p_mRawWeightSet->mOffset;
      if ( !p_mRawWeightSet->mOffset )
        v18 = 0i64;
      v19 = v11++;
    }
  }
  v20 = (char *)p_mRawWeightSet + p_mRawWeightSet->mOffset;
  if ( !p_mRawWeightSet->mOffset )
    v20 = 0i64;
  serializer->vfptr->_PushObjectToSerialize(
    serializer,
    v20,
    this->mRawWeightSetPaddedLength,
    fnArraySerializer,
    &customCaption,
    PRIORITY_MEDIUM,
    16u,
    0i64,
    0,
    0i64);
  v21 = 0;
  if ( (this->mWeightsetEntires.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v22 = this->mWeightsetEntires.mData.mOffset;
      if ( v22 )
        v23 = (char *)&this->mWeightsetEntires.mData + v22;
      else
        v23 = 0i64;
      v24 = &v23[8 * v21];
      v25 = *(_QWORD *)v24;
      if ( *(_QWORD *)v24 )
      {
        v26 = &v24[v25];
        if ( &v24[v25] )
        {
          v27 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v26 + 32i64))(v26);
          serializer->vfptr->_PushObjectToSerialize(
            serializer,
            v26,
            1u,
            (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
            v27,
            PRIORITY_MEDIUM,
            0,
            0i64,
            -1u,
            0i64);
        }
      }
      ++v21;
    }
    while ( v21 < (this->mWeightsetEntires.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 368
// RVA: 0x3AA450
float *__fastcall Weightset::GetWeights(Weightset *this, unsigned int numBones, float weight, bool forceCopy)
{
  __int64 v4; // rbx
  __int64 v6; // rax
  char *v8; // r10
  float v9; // xmm0_4
  __int64 mOffset; // rax
  int v11; // edx
  int v12; // r9d
  char *v13; // r8
  __int64 v14; // rcx
  __m128 v15; // xmm1
  int v16; // eax
  __int64 v17; // r11
  __int64 v18; // rdi
  signed __int64 v19; // r9
  __int64 v20; // rcx
  unsigned __int64 v21; // rax
  __int64 v22; // rdi
  signed __int64 v23; // r8
  char *v24; // rax
  float *v25; // rdi
  __int64 i; // rcx

  v4 = (int)numBones;
  if ( weight != 1.0 || numBones > this->mRawWeightSetPaddedLength || forceCopy )
  {
    v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * numBones, 0x10u);
    v9 = (float)(this->mWeightsetEntires.mCount & 0x7FFFFFFF);
    if ( v9 >= (float)(int)v4 )
      v9 = (float)(int)v4;
    mOffset = this->mRawWeightSet.mOffset;
    v11 = 0;
    v12 = (int)v9;
    if ( mOffset )
      v13 = (char *)&this->mRawWeightSet + mOffset;
    else
      v13 = 0i64;
    if ( v12 >= 8 )
    {
      v14 = v12 - 1;
      v15 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
      if ( v8 > &v13[4 * v14] || &v8[4 * v14] < v13 )
      {
        do
        {
          *(__m128 *)&v8[4 * v11] = _mm_mul_ps(*(__m128 *)&v13[4 * v11], v15);
          v16 = v11 + 4;
          v11 += 8;
          *(__m128 *)&v8[4 * v16] = _mm_mul_ps(*(__m128 *)&v13[4 * v16], v15);
        }
        while ( v11 < (int)v9 - ((int)v9 & 7) );
      }
    }
    v17 = v11;
    v18 = v12;
    if ( v11 < (__int64)v12 )
    {
      if ( v12 - (__int64)v11 >= 4 )
      {
        v19 = v13 - v8;
        v20 = (__int64)&v8[4 * v11 + 4];
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
        v23 = v13 - v8;
        v24 = &v8[4 * v17];
        v11 += v22;
        do
        {
          v24 += 4;
          *((float *)v24 - 1) = weight * *(float *)&v24[v23 - 4];
          --v22;
        }
        while ( v22 );
      }
    }
    if ( v11 < v4 )
    {
      v25 = (float *)&v8[4 * v11];
      for ( i = v4 - v11; i; --i )
        *v25++ = weight * 255.0;
    }
    return (float *)v8;
  }
  else
  {
    v6 = this->mRawWeightSet.mOffset;
    if ( v6 )
      return (float *)((char *)&this->mRawWeightSet + v6);
    else
      return 0i64;
  }
}

// File Line: 422
// RVA: 0x3AB7D0
void __fastcall Weightset::MaskWeights(Weightset *this, float *weights, int numWeights)
{
  __int64 v3; // r9
  float v5; // xmm0_4
  __int64 mOffset; // rax
  int v7; // edi
  char *v8; // rdx
  __int64 v9; // rcx
  int v10; // r8d
  float *v11; // rax
  __int64 v12; // rdx
  float *v13; // rdi
  __int64 i; // rcx

  v3 = numWeights;
  v5 = (float)(this->mWeightsetEntires.mCount & 0x7FFFFFFF);
  if ( v5 >= (float)numWeights )
    v5 = (float)numWeights;
  mOffset = this->mRawWeightSet.mOffset;
  v7 = (int)v5;
  if ( mOffset )
  {
    v8 = (char *)&this->mRawWeightSet + mOffset;
    if ( v8 )
    {
      v9 = v7;
      v10 = 0;
      if ( v7 > 0 )
      {
        v11 = weights;
        v12 = v8 - (char *)weights;
        v10 = (int)v5;
        do
        {
          if ( *(float *)((char *)v11 + v12) == 0.0 )
            *v11 = 0.0;
          ++v11;
          --v9;
        }
        while ( v9 );
      }
      if ( v10 < v3 )
      {
        v13 = &weights[v10];
        for ( i = v3 - v10; i; --i )
          *v13++ = 0.0;
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
  char *v2; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&WeightsetEntry::`vftable;
  if ( (this->mName.mOffset & 1) != 0 && (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

