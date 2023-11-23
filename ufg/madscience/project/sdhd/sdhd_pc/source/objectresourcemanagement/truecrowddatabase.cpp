// File Line: 62
// RVA: 0x43DBD0
void __fastcall UFG::OverrideForceParams::GetMorphWeightsFromBMI(UFG::OverrideForceParams *this, float *morphWeights)
{
  unsigned int v2; // r8d
  unsigned int v3; // eax
  float v4; // xmm4_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  int v7; // xmm0_4

  if ( this->mBMIValid )
  {
    v2 = 1664525 * ARandom::c_gen.i_seed + 1013904223;
    v3 = 1664525 * v2 + 1013904223;
    ARandom::c_gen.i_seed = 1664525 * v3 + 1013904223;
    v4 = (float)((float)((float)((float)(COERCE_FLOAT((v3 >> 9) | 0x3F800000) + COERCE_FLOAT((v2 >> 9) | 0x3F800000))
                               + COERCE_FLOAT((ARandom::c_gen.i_seed >> 9) | 0x3F800000))
                       - 3.0)
               * 0.33333334)
       - 0.5;
    if ( v4 >= 0.0 )
      v5 = 0.0;
    else
      v5 = *(float *)&FLOAT_1_0;
    v6 = (float)((float)(this->mBMIMax - this->mBMIMin) * (float)(v5 + v4)) + this->mBMIMin;
    if ( v6 >= 0.0 )
      v7 = 0;
    else
      v7 = LODWORD(v6) ^ _xmm[0];
    *(_DWORD *)morphWeights = v7;
    if ( v6 <= 0.0 )
      v6 = 0.0;
    morphWeights[1] = v6;
  }
  else
  {
    *(_QWORD *)morphWeights = 0i64;
  }
}

// File Line: 85
// RVA: 0x4396D0
void __fastcall UFG::TrueCrowdResource::CacheFileSizes(UFG::TrueCrowdResource *this)
{
  unsigned int mValue; // ecx
  const char *v3; // rdi
  unsigned int v4; // ecx
  char *v5; // r8
  char *v6; // r8
  char *v7; // r8
  UFG::qString v8; // [rsp+28h] [rbp-530h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-508h] BYREF
  UFG::qString v10; // [rsp+78h] [rbp-4E0h] BYREF
  UFG::qString v11; // [rsp+A0h] [rbp-4B8h] BYREF
  char dest[128]; // [rsp+D0h] [rbp-488h] BYREF
  char v13[1032]; // [rsp+150h] [rbp-408h] BYREF

  UFG::qString::qString(&v8);
  mValue = this->mType.mValue;
  v3 = 0i64;
  if ( mValue )
  {
    v4 = mValue - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        v5 = (char *)this + this->mName.mOffset;
        if ( !this->mName.mOffset )
          v5 = 0i64;
        UFG::qSPrintf(dest, "Data\\Props_New\\%s", v5);
      }
    }
    else
    {
      v6 = (char *)this + this->mName.mOffset;
      if ( !this->mName.mOffset )
        v6 = 0i64;
      UFG::qSPrintf(dest, "Data\\Vehicles_New\\%s", v6);
    }
  }
  else
  {
    v7 = (char *)this + this->mName.mOffset;
    if ( !this->mName.mOffset )
      v7 = 0i64;
    UFG::qSPrintf(dest, "Data\\Characters_New\\%s", v7);
  }
  UFG::qString::Set(&v8, dest);
  if ( this->mName.mOffset )
    v3 = (char *)this + this->mName.mOffset;
  UFG::qString::qString(&v10, v3);
  UFG::qSPrintf(v13, v8.mData, v10.mData);
  UFG::qString::FormatEx(&result, "%s.perm.bin", v13);
  UFG::qString::FormatEx(&v11, "%s.temp.bin", v13);
  this->mModelSize = (UFG::StreamFileWrapper::GetAllocationSize(result.mData) + 4095) & 0xFFFFF000;
  this->mTextureSize = (UFG::StreamFileWrapper::GetAllocationSize(v11.mData) + 4095) & 0xFFFFF000;
  UFG::qString::~qString(&v11);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&v8);
}

// File Line: 122
// RVA: 0x43A460
UFG::TrueCrowdTextureSet *__fastcall UFG::TrueCrowdModel::ChooseNextTextureSet(UFG::TrueCrowdModel *this)
{
  unsigned __int16 mNumTextureSets; // ax
  __int64 v4; // rdx
  unsigned int v5; // edi
  unsigned int v6; // r8d
  unsigned int v7; // ecx
  __int64 mOffset; // r11
  UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *p_mTextureSets; // rbx
  __int64 v10; // r9
  char *v11; // rax
  char *v12; // r10
  __int64 v13; // rax
  char *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r8
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // r8
  int v20[16]; // [rsp+0h] [rbp-48h]

  mNumTextureSets = this->mNumTextureSets;
  if ( !mNumTextureSets )
    return 0i64;
  v4 = 0i64;
  v5 = mNumTextureSets;
  v6 = 0;
  v7 = 0;
  mOffset = this->mTextureSets.mOffset;
  p_mTextureSets = &this->mTextureSets;
  v10 = 0i64;
  do
  {
    v11 = (char *)p_mTextureSets + mOffset;
    if ( !mOffset )
      v11 = 0i64;
    v12 = &v11[v10];
    v13 = *(_QWORD *)&v11[v10];
    if ( v13 )
      v14 = &v12[v13];
    else
      v14 = 0i64;
    if ( !*((_QWORD *)v14 + 1) )
    {
      v15 = v6++;
      v20[v15] = v7;
    }
    ++v7;
    v10 += 8i64;
  }
  while ( v7 < v5 );
  if ( !v6 )
    return 0i64;
  ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
  v16 = (unsigned int)v20[(unsigned __int64)(v6 * HIWORD(ARandom::c_gen.i_seed)) >> 16];
  v17 = (char *)p_mTextureSets + p_mTextureSets->mOffset;
  if ( !p_mTextureSets->mOffset )
    v17 = 0i64;
  v18 = *(_QWORD *)&v17[8 * v16];
  v19 = &v17[8 * v16];
  if ( v18 )
    return (UFG::TrueCrowdTextureSet *)&v19[v18];
  return (UFG::TrueCrowdTextureSet *)v4;
}

// File Line: 153
// RVA: 0x443140
void __fastcall UFG::TrueCrowdTextureSet::SetRandomOverrides(
        UFG::TrueCrowdTextureSet *this,
        UFG::ModelTextureCombination *model_texture_combination,
        UFG::OverrideForceParams *ofp,
        unsigned int *colourTintIndex)
{
  signed int mNumColorTints; // r11d
  __int64 mOffset; // rax
  UFG::qColour *v7; // rax
  __int64 v8; // rax
  UFG::qColour *v9; // rax
  __int64 v10; // rax
  char *v11; // rcx

  mNumColorTints = this->mNumColorTints;
  if ( mNumColorTints )
  {
    if ( colourTintIndex )
    {
      mOffset = this->mColourTints.mOffset;
      if ( mOffset )
        v7 = (UFG::qColour *)((char *)&this->mColourTints + 16 * *colourTintIndex + mOffset);
      else
        v7 = (UFG::qColour *)(16i64 * *colourTintIndex);
      model_texture_combination->mColourTint = v7;
    }
    else if ( ofp && ofp->mColorTintValid )
    {
      v8 = this->mColourTints.mOffset;
      if ( v8 )
        v9 = (UFG::qColour *)((char *)&this->mColourTints + 16 * ofp->mColorTintIndex + v8);
      else
        v9 = (UFG::qColour *)(16i64 * ofp->mColorTintIndex);
      model_texture_combination->mColourTint = v9;
    }
    else
    {
      v10 = this->mColourTints.mOffset;
      if ( v10 )
        v11 = (char *)&this->mColourTints + v10;
      else
        v11 = 0i64;
      model_texture_combination->mColourTint = (UFG::qColour *)&v11[16 * this->mTintIndex];
      this->mTintIndex = (this->mTintIndex + 1) % mNumColorTints;
    }
  }
}

// File Line: 246
// RVA: 0x43F180
char __fastcall UFG::TrueCrowdSet::Instance::IsLoaded(UFG::TrueCrowdSet::Instance *this)
{
  unsigned int mNumParts; // r11d
  unsigned int v3; // r9d
  UFG::ModelTextureCombination *mPart; // r8
  __int64 v5; // rdi
  __int64 mModelIndex; // rcx
  __int64 mTextureSetIndex; // r10
  UFG::TrueCrowdModel *v8; // rdx
  UFG::ResourceRequest *mRequest; // rax
  __int64 mOffset; // rax
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax

  mNumParts = this->mNumParts;
  if ( !mNumParts )
    return 0;
  v3 = 0;
  mPart = this->mPart;
  v5 = -24i64 - (_QWORD)this;
  while ( 1 )
  {
    mModelIndex = mPart->mModelIndex;
    if ( (_DWORD)mModelIndex != -1 )
    {
      mTextureSetIndex = mPart->mTextureSetIndex;
      if ( (_DWORD)mTextureSetIndex == -1 )
        break;
      v8 = (UFG::TrueCrowdModel *)*((_QWORD *)&(*(UFG::qColour **)((char *)&mPart[3].mColourTint
                                                                 + v5
                                                                 + (unsigned __int64)this->mSet))->r
                                  + mModelIndex);
      mRequest = v8->mRequest;
      if ( !mRequest || mRequest->mLoadStatus != Loaded )
        break;
      if ( v8->mNumTextureSets )
      {
        mOffset = v8->mTextureSets.mOffset;
        v11 = mOffset ? (__int64)&v8->mTextureSets + mOffset : 0i64;
        v12 = *(_QWORD *)(v11 + 8 * mTextureSetIndex);
        if ( v12 )
          v12 += v11 + 8 * mTextureSetIndex;
        v13 = *(_QWORD *)(v12 + 8);
        if ( !v13 || *(_DWORD *)(v13 + 20) != 3 )
          break;
      }
    }
    ++v3;
    ++mPart;
    if ( v3 >= mNumParts )
      return 1;
  }
  return 0;
}

// File Line: 272
// RVA: 0x43F0C0
char __fastcall UFG::TrueCrowdSet::Instance::IsEqual(
        UFG::TrueCrowdSet::Instance *this,
        UFG::TrueCrowdSet::Instance *rhs)
{
  unsigned int mNumParts; // esi
  unsigned int v4; // r10d
  UFG::TrueCrowdModel ***p_p; // r11
  UFG::TrueCrowdModel ***v6; // rbx
  UFG::ModelTextureCombination *mPart; // rax
  signed __int64 v8; // rdi
  unsigned int mModelIndex; // edx
  int v10; // ecx

  mNumParts = this->mNumParts;
  if ( mNumParts != rhs->mNumParts )
    return 0;
  if ( this->mSet == rhs->mSet )
  {
    v4 = 0;
    if ( !mNumParts )
      return 1;
    p_p = &rhs->mSet->mFiles[0].p;
    v6 = &this->mSet->mFiles[0].p;
    mPart = this->mPart;
    v8 = (char *)rhs - (char *)this;
    while ( 1 )
    {
      mModelIndex = mPart->mModelIndex;
      v10 = *(unsigned int *)((char *)&mPart->mModelIndex + v8);
      if ( mPart->mModelIndex != v10
        || mModelIndex != -1
        && ((*v6)[mModelIndex] != (*p_p)[v10]
         || mPart->mTextureSetIndex != *(unsigned int *)((char *)&mPart->mTextureSetIndex + v8)) )
      {
        break;
      }
      ++v4;
      v6 += 2;
      p_p += 2;
      ++mPart;
      if ( v4 >= mNumParts )
        return 1;
    }
  }
  return 0;
}

// File Line: 349
// RVA: 0x438600
void __fastcall UFG::TrueCrowdSet::Instance::AddProxyReference(
        UFG::TrueCrowdSet::Instance *this,
        UFG::MeshResourceLoader *proxy)
{
  unsigned int mComponentCount; // eax
  unsigned int *p_mTextureSetIndex; // rbx
  __int64 v6; // r12
  __int64 v7; // rsi
  __int64 v8; // rcx
  UFG::TrueCrowdModel *v9; // r10
  __int64 v10; // rdx
  __int64 mOffset; // rax
  char *v12; // rcx
  char *v13; // rdx
  char *v14; // rax
  __int64 v15; // rax
  UFG::TrueCrowdResource *v16; // rdi
  UFG::ResourceUser user; // [rsp+48h] [rbp-18h] BYREF
  unsigned int mUID; // [rsp+A8h] [rbp+48h] BYREF
  unsigned int *priority; // [rsp+B0h] [rbp+50h] BYREF
  __int64 v20; // [rsp+B8h] [rbp+58h] BYREF

  if ( LODWORD(proxy[1].mTrueCrowdInstance.mPart[7].mColourTint) != 2 )
  {
    if ( this->mSet )
    {
      ++this->mSet->mCurrentInstances;
      mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mSet->mEntityIndex].mComponentCount;
      if ( mComponentCount )
      {
        p_mTextureSetIndex = &this->mPart[0].mTextureSetIndex;
        v6 = -28i64 - (_QWORD)this;
        v7 = mComponentCount;
        while ( 1 )
        {
          v8 = *(p_mTextureSetIndex - 1);
          if ( (_DWORD)v8 != -1 )
            break;
LABEL_20:
          p_mTextureSetIndex += 4;
          if ( !--v7 )
            return;
        }
        v9 = *(UFG::TrueCrowdModel **)(*(_QWORD *)((char *)p_mTextureSetIndex + v6 + (unsigned __int64)this->mSet + 56)
                                     + 8 * v8);
        v10 = *p_mTextureSetIndex;
        if ( (_DWORD)v10 != -1 )
        {
          mOffset = v9->mTextureSets.mOffset;
          if ( mOffset )
            v12 = (char *)&v9->mTextureSets + mOffset;
          else
            v12 = 0i64;
          v13 = &v12[8 * v10];
          if ( *(_QWORD *)v13 && (v14 = &v13[*(_QWORD *)v13]) != 0i64 )
          {
            v15 = v14 - (char *)&v20;
            v20 = v15;
            if ( v15 )
            {
              v16 = (UFG::TrueCrowdResource *)((char *)&v20 + v15);
LABEL_16:
              user.mMeshLoader = proxy;
              user.mType = Proxy;
              if ( v9 )
              {
                priority = &mUID;
                mUID = qSymbol_Low.mUID;
                LODWORD(priority) = qSymbol_Low;
                UFG::ResourcePool::RequestLoadResource(
                  &UFG::ObjectResourceManager::sInstance->mPool,
                  v9,
                  0,
                  (__int64)&priority,
                  &user);
              }
              if ( v16 )
              {
                priority = &mUID;
                mUID = qSymbol_Low.mUID;
                LODWORD(priority) = qSymbol_Low;
                UFG::ResourcePool::RequestLoadResource(
                  &UFG::ObjectResourceManager::sInstance->mPool,
                  v16,
                  1,
                  (__int64)&priority,
                  &user);
              }
              goto LABEL_20;
            }
          }
          else
          {
            v20 = 0i64;
          }
        }
        v16 = 0i64;
        goto LABEL_16;
      }
    }
  }
}

// File Line: 378
// RVA: 0x442350
void __fastcall UFG::TrueCrowdSet::Instance::RemoveProxyReference(
        UFG::TrueCrowdSet::Instance *this,
        UFG::MeshResourceLoader *proxy)
{
  unsigned int mComponentCount; // eax
  unsigned int *p_mTextureSetIndex; // rsi
  __int64 v6; // r13
  __int64 v7; // r14
  __int64 v8; // rcx
  UFG::TrueCrowdModel *v9; // rdx
  __int64 v10; // r8
  __int64 mOffset; // rax
  char *v12; // rcx
  char *v13; // r8
  char *v14; // rax
  __int64 v15; // rax
  char *v16; // rbx
  UFG::ObjectResourceManager *v17; // rdi
  UFG::ResourceRequest *v18; // r9
  UFG::ObjectResourceManager *mNext; // rax
  UFG::PriorityBucket::Type v20; // edx
  UFG::ObjectResourceManager *v21; // rdi
  UFG::ResourceRequest *v22; // r9
  UFG::ObjectResourceManager *p; // rax
  UFG::PriorityBucket::Type v24; // edx
  UFG::ResourceUser dependency; // [rsp+38h] [rbp-18h] BYREF
  unsigned int mUID; // [rsp+98h] [rbp+48h] BYREF
  unsigned int *p_mUID; // [rsp+A0h] [rbp+50h]
  __int64 v28; // [rsp+A8h] [rbp+58h] BYREF

  if ( LODWORD(proxy[1].mTrueCrowdInstance.mPart[7].mColourTint) != 2 )
  {
    --this->mSet->mCurrentInstances;
    mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mSet->mEntityIndex].mComponentCount;
    if ( mComponentCount )
    {
      p_mTextureSetIndex = &this->mPart[0].mTextureSetIndex;
      v6 = -28i64 - (_QWORD)this;
      v7 = mComponentCount;
      while ( 1 )
      {
        v8 = *(p_mTextureSetIndex - 1);
        if ( (_DWORD)v8 != -1 )
          break;
LABEL_51:
        p_mTextureSetIndex += 4;
        if ( !--v7 )
          return;
      }
      v9 = *(UFG::TrueCrowdModel **)(*(_QWORD *)((char *)p_mTextureSetIndex + v6 + (unsigned __int64)this->mSet + 56)
                                   + 8 * v8);
      v10 = *p_mTextureSetIndex;
      if ( (_DWORD)v10 != -1 )
      {
        mOffset = v9->mTextureSets.mOffset;
        if ( mOffset )
          v12 = (char *)&v9->mTextureSets + mOffset;
        else
          v12 = 0i64;
        v13 = &v12[8 * v10];
        if ( *(_QWORD *)v13 && (v14 = &v13[*(_QWORD *)v13]) != 0i64 )
        {
          v15 = v14 - (char *)&v28;
          v28 = v15;
          if ( v15 )
          {
            v16 = (char *)&v28 + v15;
            goto LABEL_15;
          }
        }
        else
        {
          v28 = 0i64;
        }
      }
      v16 = 0i64;
LABEL_15:
      dependency.mMeshLoader = proxy;
      dependency.mType = Proxy;
      if ( v9 && v9->mRequest )
      {
        p_mUID = &mUID;
        mUID = qSymbol_Low.mUID;
        v17 = UFG::ObjectResourceManager::sInstance;
        LODWORD(p_mUID) = qSymbol_Low;
        v18 = 0i64;
        mNext = (UFG::ObjectResourceManager *)UFG::ObjectResourceManager::sInstance->mPool.mRequestList.mNode.mNext;
        if ( mNext != (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
        {
          while ( mNext->mPool.mLoading.size != v9->mPathSymbol.mUID )
          {
            mNext = (UFG::ObjectResourceManager *)mNext->mPool.mQueued.p;
            if ( mNext == (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
              goto LABEL_22;
          }
          v18 = (UFG::ResourceRequest *)mNext;
        }
LABEL_22:
        if ( (_DWORD)p_mUID == qSymbol_Critical.mUID )
        {
          v20 = Critical;
        }
        else if ( (_DWORD)p_mUID == qSymbol_High.mUID )
        {
          v20 = High;
        }
        else if ( (_DWORD)p_mUID == qSymbol_Medium.mUID || (_DWORD)p_mUID == qSymbol_Low.mUID )
        {
          v20 = Low;
        }
        else
        {
          v20 = Low;
          if ( (_DWORD)p_mUID == qSymbol_Reserved.mUID )
            v20 = Reserved;
        }
        UFG::ResourceRequest::RemoveDependency(v18, v20, &dependency);
        v17->mPool.mDirty = 1;
      }
      if ( v16 && *((_QWORD *)v16 + 1) )
      {
        p_mUID = &mUID;
        mUID = qSymbol_Low.mUID;
        v21 = UFG::ObjectResourceManager::sInstance;
        LODWORD(p_mUID) = qSymbol_Low;
        v22 = 0i64;
        p = (UFG::ObjectResourceManager *)UFG::ObjectResourceManager::sInstance->mPool.mRequestList.mNode.mNext;
        if ( p != (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
        {
          while ( p->mPool.mLoading.size != *((_DWORD *)v16 + 7) )
          {
            p = (UFG::ObjectResourceManager *)p->mPool.mQueued.p;
            if ( p == (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
              goto LABEL_40;
          }
          v22 = (UFG::ResourceRequest *)p;
        }
LABEL_40:
        if ( (_DWORD)p_mUID == qSymbol_Critical.mUID )
        {
          v24 = Critical;
        }
        else if ( (_DWORD)p_mUID == qSymbol_High.mUID )
        {
          v24 = High;
        }
        else if ( (_DWORD)p_mUID == qSymbol_Medium.mUID || (_DWORD)p_mUID == qSymbol_Low.mUID )
        {
          v24 = Low;
        }
        else
        {
          v24 = Low;
          if ( (_DWORD)p_mUID == qSymbol_Reserved.mUID )
            v24 = Reserved;
        }
        UFG::ResourceRequest::RemoveDependency(v22, v24, &dependency);
        v21->mPool.mDirty = 1;
      }
      goto LABEL_51;
    }
  }
}

// File Line: 438
// RVA: 0x43F2B0
char __fastcall UFG::TrueCrowdSet::IsLoaded(UFG::TrueCrowdSet *this)
{
  unsigned int v1; // r12d
  unsigned int mComponentCount; // r13d
  UFG::TrueCrowdModel ***p_p; // r15
  char *i; // r14
  UFG::TrueCrowdModel *v5; // r8
  __int64 v6; // rax
  char *v7; // rcx
  char *v8; // rdx
  char *v9; // rcx
  UFG::ResourceRequest *v10; // rax
  __int64 v11; // rax
  unsigned int v13; // ebp
  int v14; // ebx
  UFG::TrueCrowdModel **j; // rdi
  UFG::TrueCrowdModel *v16; // rax
  UFG::ResourceRequest *mRequest; // rcx
  unsigned int mNumTextureSets; // r10d
  unsigned int v19; // edx
  __int64 mOffset; // r9
  UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *p_mTextureSets; // r11
  __int64 v22; // r8
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rax

  v1 = 0;
  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  if ( !mComponentCount )
    return 1;
  p_p = &this->mFiles[0].p;
  for ( i = &this->mComponentDetails[0].mbTextureSetIndexValid; !*(i - 1) || !*i; i += 12 )
  {
    v13 = *((_DWORD *)p_p - 2);
    if ( !v13 )
      goto LABEL_15;
    v14 = 0;
    for ( j = *p_p; ; ++j )
    {
      v16 = *j;
      mRequest = (*j)->mRequest;
      if ( mRequest )
      {
        if ( mRequest->mLoadStatus == Loaded )
          break;
      }
LABEL_33:
      if ( ++v14 >= v13 )
        return 0;
    }
    mNumTextureSets = v16->mNumTextureSets;
    v19 = 0;
    if ( !v16->mNumTextureSets )
    {
LABEL_32:
      if ( !(_WORD)mNumTextureSets )
        goto LABEL_15;
      goto LABEL_33;
    }
    mOffset = v16->mTextureSets.mOffset;
    p_mTextureSets = &v16->mTextureSets;
    v22 = 0i64;
    while ( 1 )
    {
      if ( mOffset )
        v23 = (__int64)p_mTextureSets + mOffset;
      else
        v23 = 0i64;
      v24 = v22 + v23;
      v25 = *(_QWORD *)(v22 + v23);
      if ( v25 )
        v25 += v24;
      v26 = *(_QWORD *)(v25 + 8);
      if ( v26 )
      {
        if ( *(_DWORD *)(v26 + 20) == 3 )
          break;
      }
      ++v19;
      v22 += 8i64;
      if ( v19 >= mNumTextureSets )
        goto LABEL_32;
    }
LABEL_15:
    ++v1;
    p_p += 2;
    if ( v1 >= mComponentCount )
      return 1;
  }
  v5 = **p_p;
  v6 = v5->mTextureSets.mOffset;
  if ( v6 )
    v7 = (char *)&v5->mTextureSets + v6;
  else
    v7 = 0i64;
  v8 = &v7[8 * *(unsigned int *)(i + 3)];
  if ( *(_QWORD *)v8 )
    v9 = &v8[*(_QWORD *)v8];
  else
    v9 = 0i64;
  v10 = v5->mRequest;
  if ( v10 )
  {
    if ( v10->mLoadStatus == Loaded )
    {
      v11 = *((_QWORD *)v9 + 1);
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 20) == 3 )
          goto LABEL_15;
      }
    }
  }
  return 0;
}

// File Line: 493
// RVA: 0x43F450
char __fastcall UFG::TrueCrowdSet::IsPreloaded(UFG::TrueCrowdSet *this)
{
  unsigned int v1; // r12d
  unsigned int mComponentCount; // r13d
  UFG::TrueCrowdModel ***p_p; // r15
  char *i; // r14
  UFG::TrueCrowdModel *v5; // r8
  __int64 v6; // rax
  char *v7; // rcx
  char *v8; // rdx
  char *v9; // rcx
  UFG::ResourceRequest *v10; // rax
  __int64 v11; // rax
  unsigned int v13; // ebp
  int v14; // ebx
  UFG::TrueCrowdModel **j; // rdi
  UFG::TrueCrowdModel *v16; // rax
  UFG::ResourceRequest *mRequest; // rcx
  unsigned int mNumTextureSets; // r10d
  unsigned int v19; // edx
  __int64 mOffset; // r9
  UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *p_mTextureSets; // r11
  __int64 v22; // r8
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rax

  v1 = 0;
  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  if ( !mComponentCount )
    return 1;
  p_p = &this->mFiles[0].p;
  for ( i = &this->mComponentDetails[0].mbTextureSetIndexValid; !*(i - 1) || !*i; i += 12 )
  {
    v13 = *((_DWORD *)p_p - 2);
    v14 = 0;
    if ( !v13 )
      return 0;
    for ( j = *p_p; ; ++j )
    {
      v16 = *j;
      mRequest = (*j)->mRequest;
      if ( mRequest )
      {
        if ( mRequest->mPreloads.size )
          break;
      }
LABEL_32:
      if ( ++v14 >= v13 )
        return 0;
    }
    mNumTextureSets = v16->mNumTextureSets;
    v19 = 0;
    if ( !v16->mNumTextureSets )
    {
LABEL_31:
      if ( !(_WORD)mNumTextureSets )
        goto LABEL_15;
      goto LABEL_32;
    }
    mOffset = v16->mTextureSets.mOffset;
    p_mTextureSets = &v16->mTextureSets;
    v22 = 0i64;
    while ( 1 )
    {
      if ( mOffset )
        v23 = (__int64)p_mTextureSets + mOffset;
      else
        v23 = 0i64;
      v24 = v22 + v23;
      v25 = *(_QWORD *)(v22 + v23);
      if ( v25 )
        v25 += v24;
      v26 = *(_QWORD *)(v25 + 8);
      if ( v26 )
      {
        if ( *(_DWORD *)(v26 + 56) )
          break;
      }
      ++v19;
      v22 += 8i64;
      if ( v19 >= mNumTextureSets )
        goto LABEL_31;
    }
LABEL_15:
    ++v1;
    p_p += 2;
    if ( v1 >= mComponentCount )
      return 1;
  }
  v5 = **p_p;
  v6 = v5->mTextureSets.mOffset;
  if ( v6 )
    v7 = (char *)&v5->mTextureSets + v6;
  else
    v7 = 0i64;
  v8 = &v7[8 * *(unsigned int *)(i + 3)];
  if ( *(_QWORD *)v8 )
    v9 = &v8[*(_QWORD *)v8];
  else
    v9 = 0i64;
  v10 = v5->mRequest;
  if ( v10 )
  {
    if ( v10->mPreloads.size )
    {
      v11 = *((_QWORD *)v9 + 1);
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 56) )
          goto LABEL_15;
      }
    }
  }
  return 0;
}

// File Line: 587
// RVA: 0x43D790
void __fastcall UFG::TrueCrowdSet::GetCurrentMemoryUsage(
        UFG::TrueCrowdSet *this,
        unsigned int *modelMemory,
        unsigned int *textureMemory)
{
  unsigned int mComponentCount; // r10d
  UFG::qArray<UFG::TrueCrowdModel *,0> *mFiles; // rdi
  char *p_mbTextureSetIndexValid; // rbp
  __int64 v8; // r14
  UFG::TrueCrowdModel **p; // rax
  UFG::TrueCrowdModel *v10; // rcx
  __int64 mOffset; // rax
  __int64 v12; // rcx
  _QWORD *v13; // rdx
  char *v14; // rax
  unsigned int i; // ebx
  UFG::TrueCrowdModel *v16; // r10
  unsigned int j; // r8d
  __int64 v18; // rax
  char *v19; // rdx
  __int64 v20; // r9
  char *v21; // rcx
  __int64 v22; // rdx
  char *v23; // rcx
  char *v24; // rcx
  char *v25; // rax
  __int64 v26; // rcx
  char *v27; // rax

  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  *modelMemory = 0;
  *textureMemory = 0;
  if ( mComponentCount )
  {
    mFiles = this->mFiles;
    p_mbTextureSetIndexValid = &this->mComponentDetails[0].mbTextureSetIndexValid;
    v8 = mComponentCount;
    do
    {
      if ( *(p_mbTextureSetIndexValid - 1) && *p_mbTextureSetIndexValid )
      {
        p = mFiles->p;
        v10 = *p;
        if ( (*p)->mRequest )
        {
          *modelMemory += v10->mModelSize;
          *textureMemory += v10->mTextureSize;
        }
        mOffset = v10->mTextureSets.mOffset;
        if ( mOffset )
          v12 = (__int64)&v10->mTextureSets + mOffset;
        else
          v12 = 0i64;
        v13 = (_QWORD *)(v12 + 8i64 * *(unsigned int *)(p_mbTextureSetIndexValid + 3));
        if ( *v13 )
          v14 = (char *)v13 + *v13;
        else
          v14 = 0i64;
        if ( *((_QWORD *)v14 + 1) )
          *textureMemory += *((_DWORD *)v14 + 5);
      }
      else
      {
        for ( i = 0; i < mFiles->size; ++i )
        {
          v16 = mFiles->p[i];
          if ( v16->mRequest )
          {
            *modelMemory += v16->mModelSize;
            *textureMemory += v16->mTextureSize;
          }
          for ( j = 0; j < v16->mNumTextureSets; ++j )
          {
            v18 = v16->mTextureSets.mOffset;
            if ( v18 )
              v19 = (char *)&v16->mTextureSets + v18;
            else
              v19 = 0i64;
            v20 = 8i64 * j;
            v21 = &v19[v20];
            v22 = *(_QWORD *)&v19[v20];
            if ( v22 )
              v23 = &v21[v22];
            else
              v23 = 0i64;
            if ( *((_QWORD *)v23 + 1) )
            {
              if ( v18 )
                v24 = (char *)&v16->mTextureSets + v18;
              else
                v24 = 0i64;
              v25 = &v24[v20];
              v26 = *(_QWORD *)&v24[v20];
              if ( v26 )
                v27 = &v25[v26];
              else
                v27 = 0i64;
              *textureMemory += *((_DWORD *)v27 + 5);
            }
          }
        }
      }
      p_mbTextureSetIndexValid += 12;
      ++mFiles;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 633
// RVA: 0x43A240
UFG::TrueCrowdModel *__fastcall UFG::TrueCrowdSet::ChooseNextPart(UFG::TrueCrowdSet *this)
{
  __int64 mComponentCount; // rbx
  unsigned int v3; // r10d
  int v4; // edi
  int *v5; // rdx
  UFG::TrueCrowdModel ***p_p; // r9
  __int64 v7; // r11
  unsigned int v8; // eax
  UFG::TrueCrowdModel **v9; // rcx
  __int64 v10; // r8
  UFG::qArray<UFG::TrueCrowdModel *,0> *mFiles; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  int v14; // eax
  unsigned int v15; // edx
  __int64 v16; // rcx
  __int64 v17; // r9
  unsigned int v18; // r8d
  float *v19; // r8
  float v20; // xmm0_4
  __int64 v21; // r9
  unsigned int v22; // edx
  unsigned int size; // r8d
  UFG::TrueCrowdModel **p; // rcx
  __int64 v25; // rax
  int v27[16]; // [rsp+20h] [rbp-208h] BYREF
  int dest[112]; // [rsp+60h] [rbp-1C8h] BYREF

  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  UFG::qMemSet(dest, 0, 0x40u);
  v3 = 0;
  v4 = 0;
  if ( (_DWORD)mComponentCount )
  {
    v5 = dest;
    p_p = &this->mFiles[0].p;
    v7 = (unsigned int)mComponentCount;
    do
    {
      v8 = *((_DWORD *)p_p - 2);
      if ( v8 )
      {
        v9 = *p_p;
        v10 = v8;
        v4 += v8;
        do
        {
          if ( (*v9)->mRequest )
            ++*v5;
          ++v9;
          --v10;
        }
        while ( v10 );
      }
      p_p += 2;
      ++v5;
      --v7;
    }
    while ( v7 );
    mFiles = this->mFiles;
    v12 = 0i64;
    v13 = mComponentCount;
    do
    {
      v14 = dest[v12];
      *(float *)&v27[v12] = (float)v14 * (float)(1.0 / (float)v4);
      if ( v14 == mFiles->size )
        v27[v12] = 1065353216;
      ++mFiles;
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  v15 = 1;
  v16 = 0i64;
  v17 = 1i64;
  if ( (unsigned int)mComponentCount > 1 )
  {
    if ( (int)mComponentCount - 1 >= 4 )
    {
      v18 = 3;
      do
      {
        if ( *(float *)&v27[v17] < *(float *)&v27[(unsigned int)v16] )
          v16 = v15;
        if ( *(float *)&v27[v16] > *(float *)&v27[v17 + 1] )
          v16 = v18 - 1;
        if ( *(float *)&v27[v17 + 2] < *(float *)&v27[v16] )
          v16 = v18;
        if ( *(float *)&v27[v16] > *(float *)&v27[v17 + 3] )
          v16 = v18 + 1;
        v15 += 4;
        v17 += 4i64;
        v18 += 4;
      }
      while ( v15 < (int)mComponentCount - 3 );
    }
    if ( v15 < (unsigned int)mComponentCount )
    {
      v19 = (float *)&v27[v17];
      do
      {
        v20 = *v19++;
        if ( v20 < *(float *)&v27[(unsigned int)v16] )
          LODWORD(v16) = v15;
        ++v15;
      }
      while ( v15 < (unsigned int)mComponentCount );
    }
  }
  v21 = (unsigned int)v16;
  v22 = 0;
  size = this->mFiles[(unsigned int)v16].size;
  if ( size )
  {
    p = this->mFiles[(unsigned int)v16].p;
    do
    {
      if ( !(*p)->mRequest && v3 < 0x60 )
      {
        v25 = v3++;
        dest[v25 + 16] = v22;
      }
      ++v22;
      ++p;
    }
    while ( v22 < size );
  }
  ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
  return this->mFiles[v21].p[dest[((unsigned __int64)(v3 * HIWORD(ARandom::c_gen.i_seed)) >> 16) + 16]];
}

// File Line: 693
// RVA: 0x439B10
UFG::TrueCrowdModel *__fastcall UFG::TrueCrowdSet::ChooseContractableAmbientPart(UFG::TrueCrowdSet *this)
{
  unsigned int v1; // r9d
  unsigned int v3; // r11d
  unsigned int mComponentCount; // ebx
  unsigned int v5; // edi
  UFG::TrueCrowdModel ***p_p; // r10
  unsigned int v7; // eax
  unsigned int v8; // edx
  UFG::TrueCrowdModel **v9; // rcx
  __int64 v10; // r8
  UFG::TrueCrowdModel *v11; // rdx
  unsigned int v12; // r10d
  unsigned int size; // r8d
  __int64 v14; // rcx
  __int64 v15; // rdi
  UFG::TrueCrowdModel **p; // r11
  UFG::ResourceRequest *mRequest; // r9
  unsigned int v18; // eax
  unsigned int *mPriorityRefCounts; // rcx
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // eax
  UFG::ResourceRequest *v23; // rax

  v1 = 0;
  v3 = 1;
  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  v5 = mComponentCount;
  if ( !mComponentCount )
    return 0i64;
  p_p = &this->mFiles[0].p;
  do
  {
    v7 = *((_DWORD *)p_p - 2);
    v8 = 0;
    if ( v7 )
    {
      v9 = *p_p;
      v10 = v7;
      do
      {
        if ( (*v9)->mRequest )
          ++v8;
        ++v9;
        --v10;
      }
      while ( v10 );
      if ( v8 > v3 )
      {
        v5 = v1;
        v3 = v8;
      }
    }
    ++v1;
    p_p += 2;
  }
  while ( v1 < mComponentCount );
  if ( v5 == mComponentCount )
    return 0i64;
  v11 = 0i64;
  v12 = -1;
  size = this->mFiles[v5].size;
  if ( size )
  {
    v14 = v5;
    v15 = size;
    p = this->mFiles[v14].p;
    do
    {
      mRequest = (*p)->mRequest;
      if ( mRequest )
      {
        v18 = 0;
        mPriorityRefCounts = mRequest->mPriorityRefCounts;
        while ( !*mPriorityRefCounts )
        {
          ++v18;
          ++mPriorityRefCounts;
          if ( v18 >= 5 )
            goto LABEL_33;
        }
        if ( v18 == 4 )
        {
          v20 = mRequest->mInstances.size;
          v21 = mRequest->mProxies.size;
          v22 = v21 + v20 + mRequest->mPreloads.size;
          if ( v11 )
          {
            if ( v22 >= v12 )
            {
              if ( v22 == v12 )
              {
                v23 = v11->mRequest;
                if ( v23 && v23->mLoadStatus == Loaded && mRequest->mLoadStatus != Loaded )
                {
                  v11 = *p;
                }
                else if ( v23->mInstances.size <= v20 )
                {
                  if ( v23->mProxies.size > v21 )
                    v11 = *p;
                }
                else
                {
                  v11 = *p;
                }
              }
            }
            else
            {
              v11 = *p;
              v12 = v21 + v20 + mRequest->mPreloads.size;
            }
          }
          else
          {
            v11 = *p;
            v12 = v21 + v20 + mRequest->mPreloads.size;
          }
        }
      }
LABEL_33:
      ++p;
      --v15;
    }
    while ( v15 );
  }
  return v11;
}

// File Line: 832
// RVA: 0x43DCC0
__int64 __fastcall UFG::TrueCrowdSet::GetNumModelsLoaded(UFG::TrueCrowdSet *this)
{
  unsigned int v1; // r9d
  unsigned int mComponentCount; // r8d
  UFG::TrueCrowdModel ***p_p; // r10
  __int64 v4; // r11
  unsigned int v5; // eax
  UFG::TrueCrowdModel **v6; // rcx
  __int64 v7; // r8
  UFG::ResourceRequest *mRequest; // rdx

  v1 = 0;
  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  if ( mComponentCount )
  {
    p_p = &this->mFiles[0].p;
    v4 = mComponentCount;
    do
    {
      v5 = *((_DWORD *)p_p - 2);
      if ( v5 )
      {
        v6 = *p_p;
        v7 = v5;
        do
        {
          mRequest = (*v6)->mRequest;
          if ( mRequest && mRequest->mLoadStatus == Loaded )
            ++v1;
          ++v6;
          --v7;
        }
        while ( v7 );
      }
      p_p += 2;
      --v4;
    }
    while ( v4 );
  }
  return v1;
}

// File Line: 908
// RVA: 0x43A6B0
void __fastcall UFG::TrueCrowdSet::ChooseSpecificModel(
        UFG::TrueCrowdSet *this,
        unsigned int partIndex,
        UFG::ModelTextureCombination *modelTextureCombination,
        UFG::OverrideForceParams *ofp)
{
  __int64 v4; // r10
  UFG::TrueCrowdTextureSet *v7; // rcx
  char *v9; // rdx
  unsigned int v10; // ebx
  UFG::TrueCrowdModel **p; // rax
  UFG::TrueCrowdModel *v12; // rdi
  unsigned int *p_mColourTintIndex; // r9
  __int64 mOffset; // rax
  char *v15; // rdx
  char *v16; // r8

  v4 = partIndex;
  v7 = 0i64;
  v9 = (char *)this + 12 * partIndex;
  modelTextureCombination->mModelIndex = 0;
  v10 = 0;
  if ( v9[305] )
    v10 = *((_DWORD *)v9 + 77);
  modelTextureCombination->mTextureSetIndex = v10;
  if ( this->mFiles[v4].size )
  {
    p = this->mFiles[v4].p;
    v12 = *p;
    if ( (*p)->mNumTextureSets )
    {
      if ( v9[306] )
        p_mColourTintIndex = &this->mComponentDetails[v4].mColourTintIndex;
      else
        p_mColourTintIndex = 0i64;
      mOffset = v12->mTextureSets.mOffset;
      if ( mOffset )
        v15 = (char *)&v12->mTextureSets + mOffset;
      else
        v15 = 0i64;
      v16 = &v15[8 * v10];
      if ( *(_QWORD *)v16 )
        v7 = (UFG::TrueCrowdTextureSet *)&v16[*(_QWORD *)v16];
      UFG::TrueCrowdTextureSet::SetRandomOverrides(v7, modelTextureCombination, ofp, p_mColourTintIndex);
    }
  }
  else
  {
    modelTextureCombination->mModelIndex = -1;
  }
}

// File Line: 936
// RVA: 0x43A550
void __fastcall UFG::TrueCrowdSet::ChooseRandomModel(
        UFG::TrueCrowdSet *this,
        unsigned int partIndex,
        UFG::ModelTextureCombination *modelTextureCombination,
        UFG::OverrideForceParams *ofp)
{
  unsigned int size; // ecx
  __int64 v7; // r8
  int mNumTextureSets; // eax
  unsigned int i_seed_high; // r11d
  __int64 v10; // r11
  UFG::TrueCrowdModel *v11; // r8
  __int64 mOffset; // rax
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rax
  __int64 v16; // r8
  int v17; // r11d
  __int64 v18; // rax
  __int64 v19; // rax

  size = this->mFiles[partIndex].size;
  if ( size )
  {
    ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
    v7 = (size * HIWORD(ARandom::c_gen.i_seed)) >> 16;
    mNumTextureSets = this->mFiles[partIndex].p[v7]->mNumTextureSets;
    ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
    i_seed_high = HIWORD(ARandom::c_gen.i_seed);
    modelTextureCombination->mModelIndex = v7;
    v10 = (mNumTextureSets * i_seed_high) >> 16;
    modelTextureCombination->mTextureSetIndex = v10;
    v11 = this->mFiles[partIndex].p[v7];
    if ( v11->mNumTextureSets )
    {
      mOffset = v11->mTextureSets.mOffset;
      v13 = 0i64;
      v14 = mOffset ? (__int64)&v11->mTextureSets + mOffset : 0i64;
      v15 = *(_QWORD *)(v14 + 8 * v10);
      v16 = v15 ? v15 + v14 + 8 * v10 : 0i64;
      v17 = *(_DWORD *)(v16 + 72);
      if ( v17 )
      {
        if ( ofp && ofp->mColorTintValid )
        {
          v18 = *(_QWORD *)(v16 + 56);
          if ( v18 )
            v13 = v18 + v16 + 56;
          modelTextureCombination->mColourTint = (UFG::qColour *)(v13 + 16i64 * ofp->mColorTintIndex);
        }
        else
        {
          v19 = *(_QWORD *)(v16 + 56);
          if ( v19 )
            v13 = v19 + v16 + 56;
          modelTextureCombination->mColourTint = (UFG::qColour *)(v13 + 16i64 * *(unsigned __int16 *)(v16 + 78));
          *(_WORD *)(v16 + 78) = (*(unsigned __int16 *)(v16 + 78) + 1) % v17;
        }
      }
    }
  }
  else
  {
    modelTextureCombination->mModelIndex = -1;
    modelTextureCombination->mTextureSetIndex = 0;
  }
}

// File Line: 960
// RVA: 0x439E60
void __fastcall UFG::TrueCrowdSet::ChooseLeastCommonModel(
        UFG::TrueCrowdSet *this,
        unsigned int partIndex,
        UFG::ModelTextureCombination *modelTextureCombination,
        UFG::OverrideForceParams *ofp)
{
  __int64 v4; // rbx
  char *v5; // rdx
  unsigned int size; // r11d
  unsigned int v10; // r10d
  UFG::TrueCrowdModel **p; // r9
  unsigned int v12; // r14d
  unsigned int v13; // ecx
  unsigned int v14; // r15d
  unsigned int v15; // ebp
  UFG::ResourceRequest *mRequest; // r8
  unsigned int v17; // r8d
  UFG::TrueCrowdModel *v18; // rbx
  __int64 mOffset; // r10
  __int64 v20; // r9
  char *v21; // rax
  char *v22; // rcx
  __int64 v23; // rax
  char *v24; // rcx
  __int64 v25; // rcx
  __int64 v26; // rax
  char *v27; // rcx
  char *v28; // r8
  char *v29; // rcx
  int v30; // r8d
  __int64 v31; // rax
  __int64 v32; // rax

  v4 = partIndex;
  v5 = 0i64;
  size = this->mFiles[v4].size;
  if ( size )
  {
    v10 = 4096;
    p = this->mFiles[(unsigned int)v4].p;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 4096;
    do
    {
      mRequest = (*p)->mRequest;
      if ( mRequest && mRequest->mInstances.size + mRequest->mProxies.size < v10 )
      {
        v10 = mRequest->mInstances.size + mRequest->mProxies.size;
        v12 = v13;
      }
      ++v13;
      ++p;
    }
    while ( v13 < size );
    v17 = 0;
    v18 = this->mFiles[v4].p[v12];
    if ( v18->mNumTextureSets )
    {
      mOffset = v18->mTextureSets.mOffset;
      v20 = 0i64;
      do
      {
        if ( mOffset )
          v21 = (char *)&v18->mTextureSets + mOffset;
        else
          v21 = 0i64;
        v22 = &v21[v20];
        v23 = *(_QWORD *)&v21[v20];
        if ( v23 )
          v24 = &v22[v23];
        else
          v24 = 0i64;
        v25 = *((_QWORD *)v24 + 1);
        if ( v25 && *(_DWORD *)(v25 + 40) + *(_DWORD *)(v25 + 72) < v15 )
        {
          v15 = *(_DWORD *)(v25 + 40) + *(_DWORD *)(v25 + 72);
          v14 = v17;
        }
        ++v17;
        v20 += 8i64;
      }
      while ( v17 < v18->mNumTextureSets );
    }
    modelTextureCombination->mModelIndex = v12;
    modelTextureCombination->mTextureSetIndex = v14;
    if ( v18->mNumTextureSets )
    {
      v26 = v18->mTextureSets.mOffset;
      if ( v26 )
        v27 = (char *)&v18->mTextureSets + v26;
      else
        v27 = 0i64;
      v28 = &v27[8 * v14];
      v29 = &v28[*(_QWORD *)v28];
      if ( !*(_QWORD *)v28 )
        v29 = 0i64;
      v30 = *((_DWORD *)v29 + 18);
      if ( v30 )
      {
        if ( ofp && ofp->mColorTintValid )
        {
          v31 = *((_QWORD *)v29 + 7);
          if ( v31 )
            v5 = &v29[v31 + 56];
          modelTextureCombination->mColourTint = (UFG::qColour *)&v5[16 * ofp->mColorTintIndex];
        }
        else
        {
          v32 = *((_QWORD *)v29 + 7);
          if ( v32 )
            v5 = &v29[v32 + 56];
          modelTextureCombination->mColourTint = (UFG::qColour *)&v5[16 * *((unsigned __int16 *)v29 + 39)];
          *((_WORD *)v29 + 39) = (*((unsigned __int16 *)v29 + 39) + 1) % v30;
        }
      }
    }
  }
  else
  {
    modelTextureCombination->mModelIndex = -1;
    modelTextureCombination->mTextureSetIndex = 0;
  }
}

// File Line: 1013
// RVA: 0x439C80
void __fastcall UFG::TrueCrowdSet::ChooseHighestCostModel(
        UFG::TrueCrowdSet *this,
        unsigned int partIndex,
        UFG::ModelTextureCombination *modelTextureCombination,
        UFG::OverrideForceParams *ofp)
{
  __int64 v4; // rdi
  char *v5; // rdx
  unsigned int size; // ebx
  unsigned int v10; // r11d
  UFG::TrueCrowdModel **p; // r10
  unsigned int v12; // r12d
  unsigned int v13; // r8d
  unsigned int v14; // r15d
  unsigned int v15; // ebp
  unsigned int v16; // ecx
  UFG::ResourceRequest *mRequest; // r9
  unsigned int v18; // r8d
  UFG::TrueCrowdModel *v19; // rbx
  __int64 mOffset; // r10
  __int64 v21; // r9
  char *v22; // rax
  char *v23; // rcx
  __int64 v24; // rax
  char *v25; // rcx
  __int64 v26; // rcx
  unsigned int v27; // eax
  __int64 v28; // rax
  char *v29; // rcx
  char *v30; // r8
  char *v31; // rcx
  int v32; // r8d
  __int64 v33; // rax
  __int64 v34; // rax

  v4 = partIndex;
  v5 = 0i64;
  size = this->mFiles[v4].size;
  if ( size )
  {
    v10 = 4096;
    p = this->mFiles[(unsigned int)v4].p;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 4096;
    do
    {
      v16 = 0;
      mRequest = (*p)->mRequest;
      if ( mRequest )
        v16 = mRequest->mInstances.size + mRequest->mProxies.size;
      if ( v16 < v10 )
      {
        v10 = v16;
        v14 = v13;
      }
      ++v13;
      ++p;
    }
    while ( v13 < size );
    v18 = 0;
    v19 = this->mFiles[v4].p[v14];
    if ( v19->mNumTextureSets )
    {
      mOffset = v19->mTextureSets.mOffset;
      v21 = 0i64;
      do
      {
        if ( mOffset )
          v22 = (char *)&v19->mTextureSets + mOffset;
        else
          v22 = 0i64;
        v23 = &v22[v21];
        v24 = *(_QWORD *)&v22[v21];
        if ( v24 )
          v25 = &v23[v24];
        else
          v25 = 0i64;
        v26 = *((_QWORD *)v25 + 1);
        v27 = 0;
        if ( v26 )
          v27 = *(_DWORD *)(v26 + 40) + *(_DWORD *)(v26 + 72);
        if ( v27 < v15 )
        {
          v15 = v27;
          v12 = v18;
        }
        ++v18;
        v21 += 8i64;
      }
      while ( v18 < v19->mNumTextureSets );
    }
    modelTextureCombination->mModelIndex = v14;
    modelTextureCombination->mTextureSetIndex = v12;
    if ( v19->mNumTextureSets )
    {
      v28 = v19->mTextureSets.mOffset;
      if ( v28 )
        v29 = (char *)&v19->mTextureSets + v28;
      else
        v29 = 0i64;
      v30 = &v29[8 * v12];
      v31 = &v30[*(_QWORD *)v30];
      if ( !*(_QWORD *)v30 )
        v31 = 0i64;
      v32 = *((_DWORD *)v31 + 18);
      if ( v32 )
      {
        if ( ofp && ofp->mColorTintValid )
        {
          v33 = *((_QWORD *)v31 + 7);
          if ( v33 )
            v5 = &v31[v33 + 56];
          modelTextureCombination->mColourTint = (UFG::qColour *)&v5[16 * ofp->mColorTintIndex];
        }
        else
        {
          v34 = *((_QWORD *)v31 + 7);
          if ( v34 )
            v5 = &v31[v34 + 56];
          modelTextureCombination->mColourTint = (UFG::qColour *)&v5[16 * *((unsigned __int16 *)v31 + 39)];
          *((_WORD *)v31 + 39) = (*((unsigned __int16 *)v31 + 39) + 1) % v32;
        }
      }
    }
  }
  else
  {
    modelTextureCombination->mModelIndex = -1;
    modelTextureCombination->mTextureSetIndex = 0;
  }
}

// File Line: 1149
// RVA: 0x442F60
void __fastcall UFG::TrueCrowdSet::SelectInstance(
        UFG::TrueCrowdSet *this,
        UFG::TrueCrowdSet::Instance *instance,
        UFG::OverrideForceParams *ofp,
        UFG::TrueCrowdSet::SelectionFlags selectionFlag)
{
  UFG::TrueCrowdDataBase *v4; // r10
  __int64 v5; // rbx
  UFG::OverrideForceParams *v10; // r9
  UFG::ModelTextureCombination *v11; // r8
  UFG::TrueCrowdSet *v12; // rcx
  unsigned int v13; // edx
  int NumModelsLoaded; // eax

  v4 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
  instance->mSet = this;
  v5 = 0i64;
  LODWORD(v4) = v4->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  for ( instance->mNumParts = (unsigned int)v4; (unsigned int)v5 < instance->mNumParts; v5 = (unsigned int)(v5 + 1) )
  {
    if ( this->mComponentDetails[v5].mbSpecificModel )
    {
      UFG::TrueCrowdSet::ChooseSpecificModel(this, v5, &instance->mPart[(unsigned int)v5], ofp);
    }
    else
    {
      if ( selectionFlag == eSF_LeastCommon )
      {
        v10 = ofp;
        v11 = &instance->mPart[(unsigned int)v5];
        v13 = v5;
        v12 = this;
LABEL_12:
        UFG::TrueCrowdSet::ChooseLeastCommonModel(v12, v13, v11, v10);
        continue;
      }
      if ( selectionFlag == eSF_LeastCost )
      {
        NumModelsLoaded = UFG::TrueCrowdSet::GetNumModelsLoaded(this);
        v10 = ofp;
        v11 = &instance->mPart[(unsigned int)v5];
        v13 = v5;
        v12 = this;
        if ( NumModelsLoaded )
          goto LABEL_12;
      }
      else
      {
        v10 = ofp;
        v11 = &instance->mPart[(unsigned int)v5];
        v12 = this;
        v13 = v5;
        if ( selectionFlag == eSF_HighestCost )
        {
          UFG::TrueCrowdSet::ChooseHighestCostModel(this, v5, v11, ofp);
          continue;
        }
      }
      UFG::TrueCrowdSet::ChooseRandomModel(v12, v13, v11, v10);
    }
  }
  if ( ofp )
    UFG::OverrideForceParams::GetMorphWeightsFromBMI(ofp, instance->mMorphWeights);
}

// File Line: 1203
// RVA: 0x438480
void __fastcall UFG::TrueCrowdDataBaseInventory::Add(
        UFG::TrueCrowdDataBaseInventory *this,
        UFG::TrueCrowdDataBase *resource_data)
{
  if ( resource_data )
    UFG::TrueCrowdDataBase::TrueCrowdDataBase(resource_data, 0);
  UFG::TrueCrowdDataBase::sTrueCrowdDataBase = resource_data;
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 1211
// RVA: 0x441FB0
void __fastcall UFG::TrueCrowdDataBaseInventory::Remove(
        UFG::TrueCrowdDataBaseInventory *this,
        UFG::TrueCrowdDataBase *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::TrueCrowdDataBase::~TrueCrowdDataBase(resource_data);
}

// File Line: 1218
// RVA: 0x1511C70
__int64 UFG::_dynamic_initializer_for__gTrueCrowdDataBaseInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gTrueCrowdDataBaseInventory,
    "TrueCrowdDataBaseInventory",
    0x4AEEEFDEu,
    0x90EEF023,
    0,
    0);
  UFG::gTrueCrowdDataBaseInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::TrueCrowdDataBaseInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gTrueCrowdDataBaseInventory__);
}

// File Line: 1228
// RVA: 0x437720
void __fastcall UFG::TrueCrowdDataBase::TrueCrowdDataBase(UFG::TrueCrowdDataBase *this, MemImageLoadFlag flag)
{
  unsigned int i; // esi
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rdi
  __int64 j; // rbx
  __int64 v8; // rax
  char *v9; // rdx
  unsigned int k; // r12d
  __int64 v11; // rax
  char *v12; // rcx
  char *v13; // r15
  __int64 m; // r14
  __int64 v15; // rax
  char *v16; // rcx
  char *v17; // rbx
  _QWORD *v18; // rdi
  __int64 v19; // rsi
  __int64 v20; // rbp
  char *v21; // rcx
  char *v22; // rax
  __int64 v23; // rcx
  char *v24; // rbx

  UFG::qResourceData::qResourceData(this);
  `eh vector constructor iterator(
    this->mDefinition.mEntities,
    0x50Cui64,
    25,
    (void (__fastcall *)(void *))UFG::TrueCrowdDefinition::Entity::Entity);
  this->mKnownRequests.mNode.mPrev = &this->mKnownRequests.mNode;
  this->mKnownRequests.mNode.mNext = &this->mKnownRequests.mNode;
  for ( i = 0; i < this->mNumComponentEntries; ++i )
  {
    mOffset = this->mComponentEntries.mOffset;
    if ( mOffset )
      v5 = (char *)&this->mComponentEntries + mOffset;
    else
      v5 = 0i64;
    v6 = &v5[16 * i];
    if ( v6 )
    {
      for ( j = 0i64; (unsigned int)j < *(_DWORD *)v6; j = (unsigned int)(j + 1) )
      {
        v8 = *((_QWORD *)v6 + 1);
        if ( v8 )
          v9 = &v6[v8 + 8];
        else
          v9 = 0i64;
        if ( &v9[96 * j] )
          UFG::TrueCrowdModel::TrueCrowdModel((UFG::TrueCrowdModel *)&v9[96 * j + 16], flag);
      }
    }
  }
  for ( k = 0; k < this->mNumComponentEntries; ++k )
  {
    v11 = this->mComponentEntries.mOffset;
    if ( v11 )
      v12 = (char *)&this->mComponentEntries + v11;
    else
      v12 = 0i64;
    v13 = &v12[16 * k];
    for ( m = 0i64; (unsigned int)m < *(_DWORD *)v13; m = (unsigned int)(m + 1) )
    {
      v15 = *((_QWORD *)v13 + 1);
      if ( v15 )
        v16 = &v13[v15 + 8];
      else
        v16 = 0i64;
      v17 = &v16[96 * m];
      UFG::TrueCrowdResource::CacheFileSizes((UFG::TrueCrowdResource *)(v17 + 16));
      if ( *((_WORD *)v17 + 37) )
      {
        v18 = v17 + 88;
        v19 = 0i64;
        v20 = *((unsigned __int16 *)v17 + 37);
        do
        {
          if ( *v18 )
            v21 = (char *)v18 + *v18;
          else
            v21 = 0i64;
          v22 = &v21[v19];
          v23 = *(_QWORD *)&v21[v19];
          if ( v23 )
            v24 = &v22[v23];
          else
            v24 = 0i64;
          UFG::TrueCrowdResource::CacheFileSizes((UFG::TrueCrowdResource *)v24);
          *((_WORD *)v24 + 39) = UFG::qRandom(*((_DWORD *)v24 + 18), (unsigned int *)&UFG::qDefaultSeed);
          v19 += 8i64;
          --v20;
        }
        while ( v20 );
      }
    }
  }
}

// File Line: 1262
// RVA: 0x43E5B0
void UFG::TrueCrowdDataBase::Init(void)
{
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\TrueCrowd.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
}

// File Line: 1272
// RVA: 0x43FFC0
UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *__fastcall UFG::TrueCrowdDataBase::QueryCharacterDataBase(
        UFG::TrueCrowdDataBase *this,
        unsigned int entityIndex,
        UFG::qPropertyList *query_tags,
        hkMemoryResourceContainer *componentList,
        UFG::qPropertyList *overrides,
        UFG::qPropertyList *textureSetList,
        UFG::qPropertySet *property_set)
{
  UFG::qPropertyList *v7; // r14
  unsigned int v8; // r15d
  __int64 v9; // r12
  unsigned int mNumElements; // edi
  unsigned int m_size; // esi
  unsigned int v12; // ebx
  unsigned int v13; // r13d
  unsigned int v14; // esi
  unsigned int v15; // r10d
  __int64 v16; // r15
  int **v17; // r14
  __int64 v18; // rdi
  UFG::TrueCrowdDataBase *v19; // rax
  unsigned int ElementPropertySet; // eax
  char *ValuePtr; // rax
  UFG::qPropertySet *v22; // rbx
  UFG::qSymbol *v23; // rax
  int v24; // r9d
  __int64 v25; // r8
  int v26; // ecx
  UFG::BitFlags128 *v27; // rax
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v28; // rsi
  unsigned __int64 v29; // rcx
  unsigned int v30; // r13d
  unsigned __int64 v31; // rbx
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *p_mKnownRequests; // r14
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *mNext; // rdi
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v36; // rax
  int i; // ecx
  __int64 v38; // rsi
  unsigned int v39; // r11d
  __int64 *v40; // r15
  UFG::qPropertyList *v41; // rbx
  void **p_mNext; // rdi
  __int64 v43; // r14
  UFG::qPropertyList *v44; // r8
  UFG::TrueCrowdDataBase *v45; // rcx
  __int64 v46; // rdx
  int v47; // r11d
  __int64 v48; // rax
  char *v49; // rcx
  char *v50; // rax
  unsigned int v51; // ecx
  __int64 v52; // r8
  char *v53; // rdx
  char *v54; // rsi
  __int64 v55; // r13
  unsigned int v56; // r14d
  unsigned int v57; // ebx
  unsigned int v58; // ebx
  unsigned __int64 v59; // rax
  UFG::allocator::free_link *v60; // rax
  UFG::allocator::free_link *v61; // r15
  __int64 k; // r9
  int v63; // r11d
  unsigned int v64; // ecx
  unsigned int v65; // r10d
  __int64 *v66; // rsi
  __int64 v67; // r9
  char *v68; // rdx
  char *v69; // r8
  char *v70; // rax
  __int64 mOffset; // rax
  char *v72; // rcx
  char *v73; // r8
  unsigned int v74; // r12d
  __int64 v75; // rax
  char *v76; // rdx
  char *v77; // rcx
  __int64 v78; // r15
  unsigned int v79; // esi
  unsigned int v80; // ebx
  unsigned int v81; // ebx
  unsigned __int64 v82; // rax
  UFG::allocator::free_link *v83; // rax
  UFG::allocator::free_link *v84; // r14
  unsigned int j; // r9d
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *mPrev; // rax
  unsigned int v87; // r10d
  unsigned int v88; // r8d
  _DWORD *v89; // r9
  __int64 v91; // [rsp+30h] [rbp-D0h]
  unsigned int v92; // [rsp+38h] [rbp-C8h]
  __int64 v93; // [rsp+40h] [rbp-C0h]
  unsigned int v94; // [rsp+48h] [rbp-B8h]
  unsigned __int64 v95; // [rsp+48h] [rbp-B8h]
  unsigned int v96; // [rsp+50h] [rbp-B0h]
  __int64 v97; // [rsp+50h] [rbp-B0h]
  UFG::allocator::free_link *v98; // [rsp+58h] [rbp-A8h]
  char *v99; // [rsp+60h] [rbp-A0h]
  char *v100; // [rsp+68h] [rbp-98h]
  _QWORD *v101; // [rsp+70h] [rbp-90h]
  UFG::BitFlags128 result; // [rsp+78h] [rbp-88h] BYREF
  __int64 v103; // [rsp+88h] [rbp-78h]
  int v104[16]; // [rsp+90h] [rbp-70h] BYREF
  int ptr[16]; // [rsp+D0h] [rbp-30h] BYREF
  int v106[16]; // [rsp+110h] [rbp+10h] BYREF
  __int64 v107[16]; // [rsp+150h] [rbp+50h] BYREF
  int dest[64]; // [rsp+1D0h] [rbp+D0h] BYREF
  UFG::qPropertyList *lista; // [rsp+2F8h] [rbp+1F8h]
  UFG::qPropertyList *overridesa; // [rsp+300h] [rbp+200h]
  UFG::qPropertyList *textureSetLista; // [rsp+308h] [rbp+208h]

  v103 = -2i64;
  v7 = query_tags;
  v8 = entityIndex;
  v9 = 0x50Ci64 * entityIndex;
  v91 = v9;
  v99 = (char *)this + v9;
  v92 = *(unsigned int *)((char *)&this->mDefinition.mEntities[0].mComponentCount + v9);
  mNumElements = overrides->mNumElements;
  v94 = textureSetList->mNumElements;
  m_size = componentList->m_resourceHandles.m_size;
  v96 = m_size;
  `eh vector constructor iterator(ptr, 4ui64, 16, (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(v104, 4ui64, 16, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v12 = 0;
  memset(v107, 0, sizeof(v107));
  v13 = 0;
  if ( m_size || mNumElements )
  {
    UFG::qMemSet(dest, 0, 0xC0u);
    v14 = 0;
    v15 = v92;
    if ( v92 )
    {
      v16 = v9;
      v17 = (int **)v107;
      v18 = 0i64;
      v19 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
      do
      {
        if ( v96 )
        {
          ElementPropertySet = UFG::PSWrapper::FindElementPropertySet(
                                 componentList,
                                 (UFG::qSymbol *)((char *)&v19->mDefinition.mEntities[0].mComponents[0].mName + v9));
          if ( ElementPropertySet != -1 )
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr((UFG::qPropertyList *)componentList, 0x1Au, ElementPropertySet);
            if ( ValuePtr && *(_QWORD *)ValuePtr )
              v22 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            else
              v22 = 0i64;
            ptr[v18] = UFG::qPropertySet::Get<UFG::qSymbol>(
                         v22,
                         (UFG::qArray<unsigned long,0> *)&qSymbol_Model,
                         DEPTH_RECURSE)->mUID;
            v23 = UFG::qPropertySet::Get<UFG::qSymbol>(
                    v22,
                    (UFG::qArray<unsigned long,0> *)&qSymbol_TextureSet,
                    DEPTH_RECURSE);
            if ( v23 )
            {
              v104[v18] = v23->mUID;
              *v17 = UFG::qPropertySet::Get<long>(
                       v22,
                       (UFG::qArray<unsigned long,0> *)&qSymbol_ColorTintIndex,
                       DEPTH_RECURSE);
            }
          }
        }
        else
        {
          ptr[v18] = UFG::qPropertyList::Get<UFG::qSymbol>(overrides, v14)->mUID;
          if ( v94 )
            v104[v18] = UFG::qPropertyList::Get<UFG::qSymbol>(textureSetList, v14)->mUID;
        }
        v24 = ptr[v18];
        dest[v18] = v24;
        v15 = v92;
        v25 = v14 + 2 * v92;
        dest[(unsigned int)v25 - v92] = v104[v18];
        if ( *v17 )
          v26 = **v17;
        else
          v26 = 0;
        dest[v25] = v26;
        v19 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
        if ( *(unsigned int *)((char *)&UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[0].mComponents[0].mbRequired
                             + v16)
          && v24 != -1 )
        {
          ++v13;
        }
        ++v14;
        v9 += 80i64;
        ++v18;
        ++v17;
        v16 += 80i64;
      }
      while ( v14 < v92 );
      v7 = query_tags;
      v8 = entityIndex;
      v9 = v91;
    }
    v12 = UFG::qDataHash32((char *)dest, 12i64 * v15, 0xFFFFFFFF);
  }
  if ( v13 >= *((_DWORD *)v99 + 251) )
  {
    v30 = 0;
    LODWORD(v29) = 0;
    v28 = 0i64;
    v95 = 0i64;
  }
  else
  {
    v27 = UFG::TrueCrowdDefinition::BuildBitFlagFromTags(&this->mDefinition, &result, v7, property_set);
    v28 = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v27->mFlags[0];
    v95 = v27->mFlags[0];
    v29 = v27->mFlags[1];
    v30 = 0;
  }
  v31 = (unsigned int)v29 | ((unsigned __int64)v12 << 32);
  p_mKnownRequests = &this->mKnownRequests;
  result.mFlags[0] = (unsigned __int64)&this->mKnownRequests;
  mNext = this->mKnownRequests.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)&this->mKnownRequests )
  {
    do
    {
      v34 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)mNext->mNext;
      if ( mNext[1].mPrev == v28 && mNext[1].mNext == (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v31 )
        goto LABEL_126;
      mNext = mNext->mNext;
    }
    while ( v34 != p_mKnownRequests );
  }
  v35 = UFG::qMalloc(0x1F0ui64, "TrueCrowdSet", 0i64);
  mNext = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v35;
  v98 = v35;
  if ( v35 )
  {
    v35->mNext = v35;
    v35[1].mNext = v35;
    v35[4].mNext = (UFG::allocator::free_link *)-1i64;
    LODWORD(v35[5].mNext) = 0;
    `eh vector constructor iterator(
      &v35[6],
      0x10ui64,
      16,
      (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
    v36 = mNext + 19;
    for ( i = 15; i >= 0; --i )
    {
      LOWORD(v36->mPrev) = 0;
      BYTE2(v36->mPrev) = 0;
      *(UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> **)((char *)&v36->mPrev + 4) = 0i64;
      v36 = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)((char *)v36 + 12);
    }
  }
  else
  {
    mNext = 0i64;
    v98 = 0i64;
  }
  mNext[1].mPrev = v28;
  mNext[1].mNext = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v31;
  HIDWORD(mNext[2].mPrev) = v8;
  v38 = (unsigned int)v31;
  v97 = (unsigned int)v31;
  UFG::qMemSet(v106, 0, 0x40u);
  v39 = v92;
  if ( !v92 )
    goto LABEL_116;
  v40 = v107;
  overridesa = (UFG::qPropertyList *)v107;
  v41 = (UFG::qPropertyList *)&mNext[19];
  textureSetLista = (UFG::qPropertyList *)&mNext[19];
  p_mNext = (void **)&mNext[3].mNext;
  v43 = 0i64;
  v93 = 0i64;
  v44 = (UFG::qPropertyList *)v92;
  lista = (UFG::qPropertyList *)v92;
  v45 = this;
  do
  {
    v46 = *(unsigned int *)((char *)&v45->mDefinition.mEntities[0].mComponents[0].mResourceIndex + v9);
    LOBYTE(v41->mFlags) = *(unsigned int *)((char *)&UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[0].mComponents[0].mbRequired
                                          + v9) == 0;
    v47 = *(int *)((char *)ptr + v43);
    if ( v47 == -1 )
    {
      if ( !*(unsigned int *)((char *)&UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[0].mComponents[0].mbRequired
                            + v9) )
        goto LABEL_114;
      mOffset = v45->mComponentEntries.mOffset;
      if ( mOffset )
        v72 = (char *)&v45->mComponentEntries + mOffset;
      else
        v72 = 0i64;
      v73 = &v72[16 * v46];
      v100 = v73;
      v74 = 0;
      if ( *(_DWORD *)v73 )
      {
        do
        {
          v75 = *((_QWORD *)v73 + 1);
          if ( v75 )
            v76 = &v73[v75 + 8];
          else
            v76 = 0i64;
          v77 = &v76[96 * v74];
          if ( v95 == (*(_QWORD *)v77 & v95) && v38 == (v38 & *((_QWORD *)v77 + 1)) )
          {
            v101 = v77 + 16;
            v78 = *((unsigned int *)p_mNext - 2);
            v79 = v78 + 1;
            v80 = *((_DWORD *)p_mNext - 1);
            if ( (int)v78 + 1 > v80 )
            {
              if ( v80 )
                v81 = 2 * v80;
              else
                v81 = 1;
              for ( ; v81 < v79; v81 *= 2 )
                ;
              if ( v81 <= 2 )
                v81 = 2;
              if ( v81 - v79 > 0x10000 )
                v81 = v78 + 65537;
              if ( v81 != (_DWORD)v78 )
              {
                v82 = 8i64 * v81;
                if ( !is_mul_ok(v81, 8ui64) )
                  v82 = -1i64;
                v83 = UFG::qMalloc(v82, "qArray.Add.TrueCrowdEntityComponent.TagMatch", 0i64);
                v84 = v83;
                if ( *p_mNext )
                {
                  for ( j = 0; j < *((_DWORD *)p_mNext - 2); ++j )
                    v83[j] = *(UFG::allocator::free_link *)((char *)*p_mNext + 8 * j);
                  operator delete[](*p_mNext);
                }
                *p_mNext = v84;
                *((_DWORD *)p_mNext - 1) = v81;
                v73 = v100;
                v43 = v93;
              }
            }
            *((_DWORD *)p_mNext - 2) = v79;
            *((_QWORD *)*p_mNext + v78) = v101;
            ++*(int *)((char *)v106 + v43);
            v38 = v97;
          }
          ++v74;
        }
        while ( v74 < *(_DWORD *)v73 );
        v41 = textureSetLista;
        v40 = (__int64 *)overridesa;
      }
LABEL_111:
      v9 = v91;
LABEL_112:
      v44 = lista;
      goto LABEL_113;
    }
    v48 = v45->mComponentEntries.mOffset;
    if ( v48 )
      v49 = (char *)&v45->mComponentEntries + v48;
    else
      v49 = 0i64;
    v50 = &v49[16 * v46];
    v51 = 0;
    if ( *(_DWORD *)v50 )
    {
      v52 = *((_QWORD *)v50 + 1);
      while ( 1 )
      {
        v53 = &v50[v52 + 8];
        if ( !v52 )
          v53 = 0i64;
        v54 = &v53[96 * v51];
        if ( v47 == *((_DWORD *)v54 + 11) )
          break;
        if ( ++v51 >= *(_DWORD *)v50 )
          goto LABEL_112;
      }
      v55 = *((unsigned int *)p_mNext - 2);
      v56 = v55 + 1;
      v57 = *((_DWORD *)p_mNext - 1);
      if ( (int)v55 + 1 > v57 )
      {
        if ( v57 )
          v58 = 2 * v57;
        else
          v58 = 1;
        for ( ; v58 < v56; v58 *= 2 )
          ;
        if ( v58 <= 2 )
          v58 = 2;
        if ( v58 - v56 > 0x10000 )
          v58 = v55 + 65537;
        if ( v58 != (_DWORD)v55 )
        {
          v59 = 8i64 * v58;
          if ( !is_mul_ok(v58, 8ui64) )
            v59 = -1i64;
          v60 = UFG::qMalloc(v59, "TrueCrowdEntityComponent.Override", 0i64);
          v61 = v60;
          if ( *p_mNext )
          {
            for ( k = 0i64; (unsigned int)k < *((_DWORD *)p_mNext - 2); k = (unsigned int)(k + 1) )
              v60[k] = *(UFG::allocator::free_link *)((char *)*p_mNext + 8 * k);
            operator delete[](*p_mNext);
          }
          *p_mNext = v61;
          *((_DWORD *)p_mNext - 1) = v58;
          v40 = (__int64 *)overridesa;
        }
      }
      *((_DWORD *)p_mNext - 2) = v56;
      *((_QWORD *)*p_mNext + v55) = v54 + 16;
      v43 = v93;
      ++*(int *)((char *)v106 + v93);
      v41 = textureSetLista;
      LOBYTE(textureSetLista->mFlags) = 1;
      v63 = *(int *)((char *)v104 + v93);
      v30 = 0;
      if ( v63 == -1 )
        goto LABEL_111;
      v64 = 0;
      v65 = *((unsigned __int16 *)v54 + 37);
      if ( !*((_WORD *)v54 + 37) )
        goto LABEL_111;
      v66 = (__int64 *)(v54 + 88);
      v67 = *v66;
      while ( 1 )
      {
        v68 = (char *)v66 + v67;
        if ( !v67 )
          v68 = 0i64;
        v69 = &v68[8 * v64];
        v70 = *(_QWORD *)v69 ? &v69[*(_QWORD *)v69] : 0i64;
        if ( v63 == *((_DWORD *)v70 + 7) )
          break;
        if ( ++v64 >= v65 )
          goto LABEL_111;
      }
      textureSetLista->mPad0 = v64;
      BYTE1(textureSetLista->mFlags) = 1;
      v44 = lista;
      v9 = v91;
      if ( *v40 )
      {
        LODWORD(textureSetLista->mOwner.mOffset) = *(_DWORD *)*v40;
        BYTE2(textureSetLista->mFlags) = 1;
      }
    }
LABEL_113:
    v45 = this;
LABEL_114:
    overridesa = (UFG::qPropertyList *)++v40;
    v41 = (UFG::qPropertyList *)((char *)v41 + 12);
    textureSetLista = v41;
    v9 += 80i64;
    v91 = v9;
    v43 += 4i64;
    v93 = v43;
    p_mNext += 2;
    v44 = (UFG::qPropertyList *)((char *)v44 - 1);
    lista = v44;
    v38 = v97;
  }
  while ( v44 );
  mNext = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v98;
  p_mKnownRequests = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)result.mFlags[0];
  v39 = v92;
LABEL_116:
  mPrev = p_mKnownRequests->mNode.mPrev;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  mNext->mNext = &p_mKnownRequests->mNode;
  p_mKnownRequests->mNode.mPrev = mNext;
  if ( LODWORD(mNext[3].mNext->mPrev[1].mNext) == 1 )
  {
    v87 = -1;
    v88 = 0;
    if ( v39 )
    {
      v89 = v99 + 1008;
      do
      {
        if ( *v89 == qSymbol_Body.mUID || *v89 == qSymbol_BoatBody.mUID )
          v87 = v88;
        ++v88;
        v89 += 20;
      }
      while ( v88 < v39 );
      if ( v87 != -1 && LODWORD(mNext[v87 + 3].mPrev) )
      {
        do
          *(_DWORD *)(*((_QWORD *)&mNext[v87 + 3].mNext->mPrev + v30++) + 36i64) = 1;
        while ( v30 < LODWORD(mNext[v87 + 3].mPrev) );
      }
    }
  }
LABEL_126:
  `eh vector destructor iterator(v104, 4ui64, 16, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(ptr, 4ui64, 16, (void (__fastcall *)(void *))_);
  return (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)mNext;
} ( v88 < v39 );
      if ( v87 != -1 && LODWORD(mNext[v87 + 3].mPrev) )
      {
        do
          *(_DWORD *)(*((_QWORD *)&mNext[v87 + 3].mNext->mPrev + v30++) + 36i64) = 1;
        while ( v30 < LODWORD(

// File Line: 1500
// RVA: 0x4408F0
UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *__fastcall UFG::TrueCrowdDataBase::QueryDataBase(
        UFG::TrueCrowdDataBase *this,
        UFG::qPropertySet *property_set,
        component_StreamedResource *dataPtr)
{
  unsigned int v3; // ebx
  component_StreamedResource *MemImagePtr; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertyList *v8; // r10
  __int64 mOffset; // rcx
  hkMemoryResourceContainer *v10; // r11
  __int64 v11; // rcx
  UFG::qPropertyList *textureSetList; // r9
  __int64 v13; // rcx
  UFG::qPropertyList *overrides; // r8
  unsigned int mEntityCount; // ecx
  unsigned int mUID; // edx
  UFG::TrueCrowdDefinition::Entity *mEntities; // rax

  v3 = 0;
  MemImagePtr = dataPtr;
  if ( !dataPtr )
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           property_set,
           (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
           DEPTH_RECURSE);
    if ( v7 )
      MemImagePtr = (component_StreamedResource *)UFG::qPropertySet::GetMemImagePtr(v7);
    else
      MemImagePtr = 0i64;
  }
  v8 = (UFG::qPropertyList *)((char *)MemImagePtr + MemImagePtr->ResourceTags.mOffset);
  if ( !MemImagePtr->ResourceTags.mOffset )
    v8 = 0i64;
  mOffset = MemImagePtr->ComponentList.mOffset;
  if ( mOffset )
    v10 = (hkMemoryResourceContainer *)((char *)&MemImagePtr->ComponentList + mOffset);
  else
    v10 = 0i64;
  v11 = MemImagePtr->TextureSetList.mOffset;
  if ( v11 )
    textureSetList = (UFG::qPropertyList *)((char *)&MemImagePtr->TextureSetList + v11);
  else
    textureSetList = 0i64;
  v13 = MemImagePtr->ResourceList.mOffset;
  if ( v13 )
    overrides = (UFG::qPropertyList *)((char *)&MemImagePtr->ResourceList + v13);
  else
    overrides = 0i64;
  mEntityCount = this->mDefinition.mEntityCount;
  mUID = MemImagePtr->EntityType.mUID;
  if ( mEntityCount )
  {
    mEntities = this->mDefinition.mEntities;
    while ( mEntities->mNameUID != mUID )
    {
      ++v3;
      ++mEntities;
      if ( v3 >= mEntityCount )
        goto LABEL_20;
    }
  }
  else
  {
LABEL_20:
    v3 = -1;
  }
  return UFG::TrueCrowdDataBase::QueryCharacterDataBase(this, v3, v8, v10, overrides, textureSetList, property_set);
}

// File Line: 1520
// RVA: 0x4409E0
void __fastcall UFG::TrueCrowdDataBase::QueryInstance(
        UFG::TrueCrowdDataBase *this,
        UFG::qPropertySet *property_set,
        UFG::TrueCrowdSet::Instance *instance)
{
  UFG::qPropertySet *v6; // rax
  char *MemImagePtr; // rbx
  UFG::TrueCrowdSet *DataBase; // rsi
  int *v9; // rax
  unsigned int v10; // eax
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::OverrideForceParams ofp; // [rsp+20h] [rbp-18h] BYREF

  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         property_set,
         (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    MemImagePtr = 0i64;
  DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                    this,
                                    property_set,
                                    (component_StreamedResource *)MemImagePtr);
  if ( DataBase )
  {
    ofp.mColorTintIndex = 0;
    ofp.mBMIMin = FLOAT_N1_0;
    LODWORD(ofp.mBMIMax) = (_DWORD)FLOAT_1_0;
    v9 = UFG::qPropertySet::Get<long>(
           property_set,
           (UFG::qArray<unsigned long,0> *)&qSymbol_ColorTintIndex,
           DEPTH_RECURSE);
    if ( v9 )
    {
      v10 = *v9;
      ofp.mColorTintValid = 1;
      ofp.mColorTintIndex = v10;
    }
    else
    {
      ofp.mColorTintValid = 0;
    }
    v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            property_set,
            (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
            DEPTH_RECURSE);
    if ( v11 && (v12 = UFG::qPropertySet::GetMemImagePtr(v11)) != 0i64 )
    {
      v13 = *((float *)v12 + 10);
      v14 = *((float *)v12 + 11);
      ofp.mBMIValid = 1;
      ofp.mBMIMin = v13;
      ofp.mBMIMax = v14;
    }
    else
    {
      ofp.mBMIValid = 0;
    }
    UFG::TrueCrowdSet::SelectInstance(DataBase, instance, &ofp, *((UFG::TrueCrowdSet::SelectionFlags *)MemImagePtr + 9));
  }
}

// File Line: 1535
// RVA: 0x440B10
UFG::TrueCrowdModel *__fastcall UFG::TrueCrowdDataBase::QueryModelFromPath(
        UFG::TrueCrowdDataBase *this,
        unsigned int entityIndex,
        unsigned int componentIndex,
        UFG::qSymbol *pathSymbol)
{
  __int64 mOffset; // rax
  __int64 v6; // r8
  __int64 v7; // rcx
  int v8; // eax
  unsigned int v9; // r10d
  __int64 v10; // r9
  unsigned int mUID; // ebx
  __int64 v12; // r11
  __int64 i; // rcx
  __int64 v14; // rdx

  mOffset = this->mComponentEntries.mOffset;
  v6 = componentIndex;
  if ( mOffset )
    mOffset += (__int64)&this->mComponentEntries;
  v7 = mOffset
     + 16i64
     * UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[entityIndex].mComponents[v6].mResourceIndex;
  v8 = 0;
  v9 = *(_DWORD *)v7;
  if ( !*(_DWORD *)v7 )
    return 0i64;
  v10 = *(_QWORD *)(v7 + 8);
  mUID = pathSymbol->mUID;
  v12 = v7 + 8;
  for ( i = 0i64; ; i += 96i64 )
  {
    v14 = v10 ? v10 + v12 : 0i64;
    if ( *(_DWORD *)(i + v14 + 44) == mUID )
      break;
    if ( ++v8 >= v9 )
      return 0i64;
  }
  return (UFG::TrueCrowdModel *)(i + v14 + 16);
}

// File Line: 1565
// RVA: 0x440BB0
char __fastcall UFG::TrueCrowdDataBase::QueryPreloadedInstance(
        UFG::TrueCrowdDataBase *this,
        UFG::qPropertySet *property_set,
        UFG::TrueCrowdSet::Instance *instance)
{
  UFG::qPropertySet *v4; // rdi
  UFG::TrueCrowdSet *DataBase; // rax
  unsigned int v7; // ebx
  UFG::TrueCrowdSet *v8; // rbp
  char v9; // r13
  unsigned int v10; // r15d
  __int64 mTextureSetIndex; // r8
  UFG::TrueCrowdModel *v12; // rdx
  __int64 mOffset; // rax
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rcx
  UFG::ResourceRequest *mRequest; // rax
  __int64 v18; // rax
  int v19; // edi
  unsigned int size; // esi
  UFG::TrueCrowdModel *v21; // r10
  UFG::ResourceRequest *v22; // rax
  unsigned int v23; // edx
  __int64 v24; // r9
  __int64 v25; // r8
  __int64 v26; // rax
  __int64 v27; // rcx
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rax
  int *v31; // rax
  unsigned int v32; // eax
  UFG::qPropertySet *v33; // rax
  char *MemImagePtr; // rax
  float v35; // xmm0_4
  float v36; // xmm1_4
  UFG::TrueCrowdSet *mSet; // rdi
  unsigned int v38; // ecx
  int NumModelsLoaded; // eax
  UFG::ModelTextureCombination *v40; // r8
  UFG::OverrideForceParams ofp; // [rsp+20h] [rbp-48h] BYREF
  unsigned int mComponentCount; // [rsp+80h] [rbp+18h]

  v4 = property_set;
  if ( !instance )
    return 0;
  DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(this, property_set, 0i64);
  v7 = 0;
  instance->mSet = DataBase;
  v8 = DataBase;
  v9 = 1;
  v10 = 0;
  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[DataBase->mEntityIndex].mComponentCount;
  instance->mNumParts = mComponentCount;
  if ( !mComponentCount )
    goto LABEL_36;
  do
  {
    if ( v8->mComponentDetails[v10].mbSpecificModel && v8->mComponentDetails[v10].mbTextureSetIndexValid )
    {
      mTextureSetIndex = v8->mComponentDetails[v10].mTextureSetIndex;
      v12 = *v8->mFiles[v10].p;
      mOffset = v12->mTextureSets.mOffset;
      if ( mOffset )
        v14 = (__int64)&v12->mTextureSets + mOffset;
      else
        v14 = 0i64;
      v15 = *(_QWORD *)(v14 + 8 * mTextureSetIndex);
      v16 = v15 + v14 + 8 * mTextureSetIndex;
      if ( !v15 )
        v16 = 0i64;
      mRequest = v12->mRequest;
      if ( !mRequest
        || mRequest->mLoadStatus != Loaded
        || (v18 = *(_QWORD *)(v16 + 8)) == 0
        || *(_DWORD *)(v18 + 20) != 3 )
      {
        v9 = 0;
        instance->mSet = 0i64;
        instance->mNumParts = 0;
        return v9;
      }
    }
    else
    {
      v19 = 0;
      size = v8->mFiles[v10].size;
      if ( size )
      {
        while ( 1 )
        {
          v21 = v8->mFiles[v10].p[v19];
          v22 = v21->mRequest;
          if ( v22 )
          {
            if ( v22->mLoadStatus == Loaded )
            {
              v23 = 0;
              if ( v21->mNumTextureSets )
                break;
            }
          }
LABEL_30:
          if ( ++v19 >= size )
            goto LABEL_31;
        }
        v24 = v21->mTextureSets.mOffset;
        v25 = 0i64;
        while ( 1 )
        {
          v26 = v24 ? (__int64)&v21->mTextureSets + v24 : 0i64;
          v27 = v25 + v26;
          v28 = *(_QWORD *)(v25 + v26);
          v29 = v28 ? v27 + v28 : 0i64;
          v30 = *(_QWORD *)(v29 + 8);
          if ( v30 )
          {
            if ( *(_DWORD *)(v30 + 20) == 3 )
              break;
          }
          ++v23;
          v25 += 8i64;
          if ( v23 >= v21->mNumTextureSets )
            goto LABEL_30;
        }
      }
      else
      {
LABEL_31:
        v9 = 0;
      }
    }
    ++v10;
  }
  while ( v10 < mComponentCount );
  if ( v9 )
  {
    v4 = property_set;
LABEL_36:
    ofp.mColorTintIndex = 0;
    ofp.mBMIMin = FLOAT_N1_0;
    LODWORD(ofp.mBMIMax) = (_DWORD)FLOAT_1_0;
    v31 = UFG::qPropertySet::Get<long>(v4, (UFG::qArray<unsigned long,0> *)&qSymbol_ColorTintIndex, DEPTH_RECURSE);
    if ( v31 )
    {
      v32 = *v31;
      ofp.mColorTintValid = 1;
      ofp.mColorTintIndex = v32;
    }
    else
    {
      ofp.mColorTintValid = 0;
    }
    v33 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v4,
            (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
            DEPTH_RECURSE);
    if ( v33 && (MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v33)) != 0i64 )
    {
      v35 = *((float *)MemImagePtr + 10);
      v36 = *((float *)MemImagePtr + 11);
      ofp.mBMIValid = 1;
      ofp.mBMIMin = v35;
      ofp.mBMIMax = v36;
    }
    else
    {
      ofp.mBMIValid = 0;
    }
    mSet = instance->mSet;
    v38 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[instance->mSet->mEntityIndex].mComponentCount;
    instance->mNumParts = v38;
    if ( v38 )
    {
      do
      {
        if ( mSet->mComponentDetails[v7].mbSpecificModel )
        {
          UFG::TrueCrowdSet::ChooseSpecificModel(mSet, v7, &instance->mPart[v7], &ofp);
        }
        else
        {
          NumModelsLoaded = UFG::TrueCrowdSet::GetNumModelsLoaded(mSet);
          v40 = &instance->mPart[v7];
          if ( NumModelsLoaded )
            UFG::TrueCrowdSet::ChooseLeastCommonModel(mSet, v7, v40, &ofp);
          else
            UFG::TrueCrowdSet::ChooseRandomModel(mSet, v7, v40, &ofp);
        }
        ++v7;
      }
      while ( v7 < instance->mNumParts );
    }
    UFG::OverrideForceParams::GetMorphWeightsFromBMI(&ofp, instance->mMorphWeights);
    return v9;
  }
  instance->mSet = 0i64;
  instance->mNumParts = 0;
  return v9;
}

