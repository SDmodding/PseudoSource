// File Line: 62
// RVA: 0x43DBD0
void __fastcall UFG::OverrideForceParams::GetMorphWeightsFromBMI(UFG::OverrideForceParams *this, float *morphWeights)
{
  unsigned int v2; // eax
  unsigned int v3; // er8
  unsigned int v4; // eax
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  int v8; // xmm0_4

  if ( this->mBMIValid )
  {
    v2 = 1664525 * ARandom::c_gen.i_seed + 1013904223;
    v3 = v2;
    v4 = 1664525 * v2 + 1013904223;
    ARandom::c_gen.i_seed = 1664525 * v4 + 1013904223;
    v5 = (float)((float)((float)((float)(COERCE_FLOAT((v4 >> 9) | 0x3F800000) + COERCE_FLOAT((v3 >> 9) | 0x3F800000))
                               + COERCE_FLOAT((ARandom::c_gen.i_seed >> 9) | 0x3F800000))
                       - 3.0)
               * 0.33333334)
       - 0.5;
    if ( v5 >= 0.0 )
      v6 = 0.0;
    else
      v6 = *(float *)&FLOAT_1_0;
    v7 = (float)((float)(this->mBMIMax - this->mBMIMin) * (float)(v6 + v5)) + this->mBMIMin;
    if ( v7 >= 0.0 )
      v8 = 0;
    else
      v8 = LODWORD(v7) ^ _xmm[0];
    *(_DWORD *)morphWeights = v8;
    if ( v7 <= 0.0 )
      v7 = 0.0;
    morphWeights[1] = v7;
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
  UFG::TrueCrowdResource *v1; // rbx
  unsigned int v2; // ecx
  const char *v3; // rdi
  int v4; // ecx
  char *v5; // r8
  const char *v6; // rdx
  UFG::qString v7; // [rsp+28h] [rbp-530h]
  UFG::qString result; // [rsp+50h] [rbp-508h]
  UFG::qString v9; // [rsp+78h] [rbp-4E0h]
  UFG::qString v10; // [rsp+A0h] [rbp-4B8h]
  char dest; // [rsp+D0h] [rbp-488h]
  char v12; // [rsp+150h] [rbp-408h]

  v1 = this;
  UFG::qString::qString(&v7);
  v2 = v1->mType.mValue;
  v3 = 0i64;
  if ( v2 )
  {
    v4 = v2 - 1;
    if ( v4 )
    {
      if ( v4 != 1 )
        goto LABEL_14;
      v5 = (char *)v1 + v1->mName.mOffset;
      if ( !v1->mName.mOffset )
        v5 = 0i64;
      v6 = "Data\\Props_New\\%s";
    }
    else
    {
      v5 = (char *)v1 + v1->mName.mOffset;
      if ( !v1->mName.mOffset )
        v5 = 0i64;
      v6 = "Data\\Vehicles_New\\%s";
    }
  }
  else
  {
    v5 = (char *)v1 + v1->mName.mOffset;
    if ( !v1->mName.mOffset )
      v5 = 0i64;
    v6 = "Data\\Characters_New\\%s";
  }
  UFG::qSPrintf(&dest, v6, v5);
LABEL_14:
  UFG::qString::Set(&v7, &dest);
  if ( v1->mName.mOffset )
    v3 = (char *)v1 + v1->mName.mOffset;
  UFG::qString::qString(&v9, v3);
  UFG::qSPrintf(&v12, v7.mData, v9.mData);
  UFG::qString::FormatEx(&result, "%s.perm.bin", &v12);
  UFG::qString::FormatEx(&v10, "%s.temp.bin", &v12);
  v1->mModelSize = ((unsigned __int64)UFG::StreamFileWrapper::GetAllocationSize(result.mData) + 4095) & 0xFFFFF000;
  v1->mTextureSize = ((unsigned __int64)UFG::StreamFileWrapper::GetAllocationSize(v10.mData) + 4095) & 0xFFFFF000;
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v9);
  UFG::qString::~qString(&v7);
}

// File Line: 122
// RVA: 0x43A460
UFG::TrueCrowdTextureSet *__fastcall UFG::TrueCrowdModel::ChooseNextTextureSet(UFG::TrueCrowdModel *this)
{
  unsigned __int16 v1; // ax
  UFG::TrueCrowdModel *v2; // r9
  signed __int64 v4; // rdx
  unsigned int v5; // edi
  unsigned int v6; // er8
  unsigned int v7; // ecx
  __int64 v8; // r11
  UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *v9; // rbx
  __int64 v10; // r9
  char *v11; // rax
  char *v12; // r10
  __int64 v13; // rax
  char *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r8
  char *v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // r8
  int v20[16]; // [rsp+0h] [rbp-48h]

  v1 = this->mNumTextureSets;
  v2 = this;
  if ( !v1 )
    return 0i64;
  v4 = 0i64;
  v5 = v1;
  v6 = 0;
  v7 = 0;
  if ( !v1 )
    return 0i64;
  v8 = v2->mTextureSets.mOffset;
  v9 = &v2->mTextureSets;
  v10 = 0i64;
  do
  {
    v11 = (char *)v9 + v8;
    if ( !v8 )
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
  v16 = (unsigned int)v20[(unsigned __int64)(v6 * (ARandom::c_gen.i_seed >> 16)) >> 16];
  v17 = (char *)v9 + v9->mOffset;
  if ( !v9->mOffset )
    v17 = 0i64;
  v18 = *(_QWORD *)&v17[8 * v16];
  v19 = (signed __int64)&v17[8 * v16];
  if ( v18 )
    v4 = v18 + v19;
  return (UFG::TrueCrowdTextureSet *)v4;
}

// File Line: 153
// RVA: 0x443140
void __fastcall UFG::TrueCrowdTextureSet::SetRandomOverrides(UFG::TrueCrowdTextureSet *this, UFG::ModelTextureCombination *model_texture_combination, UFG::OverrideForceParams *ofp, unsigned int *colourTintIndex)
{
  signed int v4; // er11
  UFG::TrueCrowdTextureSet *v5; // r10
  __int64 v6; // rax
  UFG::qColour *v7; // rax
  __int64 v8; // rax
  UFG::qColour *v9; // rax
  __int64 v10; // rax
  char *v11; // rcx

  v4 = this->mNumColorTints;
  v5 = this;
  if ( v4 )
  {
    if ( colourTintIndex )
    {
      v6 = this->mColourTints.mOffset;
      if ( v6 )
        v7 = (UFG::qColour *)((char *)&this->mColourTints + 16 * *colourTintIndex + v6);
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
      model_texture_combination->mColourTint = (UFG::qColour *)&v11[16 * v5->mTintIndex];
      v5->mTintIndex = (v5->mTintIndex + 1) % v4;
    }
  }
}

// File Line: 246
// RVA: 0x43F180
char __fastcall UFG::TrueCrowdSet::Instance::IsLoaded(UFG::TrueCrowdSet::Instance *this)
{
  unsigned int v1; // er11
  UFG::TrueCrowdSet::Instance *v2; // rbx
  unsigned int v3; // er9
  UFG::ModelTextureCombination *v4; // r8
  signed __int64 v5; // rdi
  __int64 v6; // rcx
  __int64 v7; // r10
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax

  v1 = this->mNumParts;
  v2 = this;
  if ( !v1 )
    return 0;
  v3 = 0;
  if ( !v1 )
    return 1;
  v4 = this->mPart;
  v5 = -24i64 - (_QWORD)this;
  while ( 1 )
  {
    v6 = v4->mModelIndex;
    if ( (_DWORD)v6 != -1 )
    {
      v7 = v4->mTextureSetIndex;
      if ( (_DWORD)v7 == -1 )
        break;
      v8 = *((_QWORD *)&(*(UFG::qColour **)((char *)&v4[3].mColourTint + v5 + (unsigned __int64)v2->mSet))->r + v6);
      v9 = *(_QWORD *)(v8 + 8);
      if ( !v9 || *(_DWORD *)(v9 + 20) != 3 )
        break;
      if ( *(_WORD *)(v8 + 58) )
      {
        v10 = *(_QWORD *)(v8 + 72);
        v11 = v10 ? v10 + v8 + 72 : 0i64;
        v12 = *(_QWORD *)(v11 + 8 * v7);
        if ( v12 )
          v12 += v11 + 8 * v7;
        v13 = *(_QWORD *)(v12 + 8);
        if ( !v13 || *(_DWORD *)(v13 + 20) != 3 )
          break;
      }
    }
    ++v3;
    ++v4;
    if ( v3 >= v1 )
      return 1;
  }
  return 0;
}

// File Line: 272
// RVA: 0x43F0C0
char __fastcall UFG::TrueCrowdSet::Instance::IsEqual(UFG::TrueCrowdSet::Instance *this, UFG::TrueCrowdSet::Instance *rhs)
{
  unsigned int v2; // esi
  unsigned int v4; // er10
  UFG::TrueCrowdModel ***v5; // r11
  UFG::TrueCrowdModel ***v6; // rbx
  UFG::ModelTextureCombination *v7; // rax
  signed __int64 v8; // rdi
  unsigned int v9; // edx
  int v10; // ecx

  v2 = this->mNumParts;
  if ( v2 != rhs->mNumParts )
    return 0;
  if ( this->mSet == rhs->mSet )
  {
    v4 = 0;
    if ( !v2 )
      return 1;
    v5 = &rhs->mSet->mFiles[0].p;
    v6 = &this->mSet->mFiles[0].p;
    v7 = this->mPart;
    v8 = (char *)rhs - (char *)this;
    while ( 1 )
    {
      v9 = v7->mModelIndex;
      v10 = *(unsigned int *)((char *)&v7->mModelIndex + v8);
      if ( v7->mModelIndex != v10
        || v9 != -1
        && ((*v6)[v9] != (*v5)[v10] || v7->mTextureSetIndex != *(unsigned int *)((char *)&v7->mTextureSetIndex + v8)) )
      {
        break;
      }
      ++v4;
      v6 += 2;
      v5 += 2;
      ++v7;
      if ( v4 >= v2 )
        return 1;
    }
  }
  return 0;
}

// File Line: 349
// RVA: 0x438600
void __fastcall UFG::TrueCrowdSet::Instance::AddProxyReference(UFG::TrueCrowdSet::Instance *this, UFG::PedSpawningInfo *proxy)
{
  UFG::PedSpawningInfo *v2; // r15
  UFG::TrueCrowdSet::Instance *v3; // r14
  unsigned int v4; // eax
  unsigned int *v5; // rbx
  signed __int64 v6; // r12
  __int64 v7; // rsi
  __int64 v8; // rcx
  __int64 v9; // r10
  __int64 v10; // rdx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // rdx
  char *v14; // rax
  __int64 v15; // rax
  UFG::TrueCrowdResource *v16; // rdi
  UFG::ResourceUser user; // [rsp+48h] [rbp-18h]
  unsigned int v18; // [rsp+A8h] [rbp+48h]
  unsigned int *priority; // [rsp+B0h] [rbp+50h]
  __int64 v20; // [rsp+B8h] [rbp+58h]

  v2 = proxy;
  v3 = this;
  if ( proxy->mPedType != 2 )
  {
    if ( this->mSet )
    {
      ++this->mSet->mCurrentInstances;
      v4 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mSet->mEntityIndex].mComponentCount;
      if ( v4 )
      {
        v5 = &this->mPart[0].mTextureSetIndex;
        v6 = -28i64 - (_QWORD)this;
        v7 = v4;
        while ( 1 )
        {
          v8 = *(v5 - 1);
          if ( (_DWORD)v8 != -1 )
            break;
LABEL_20:
          v5 += 4;
          if ( !--v7 )
            return;
        }
        v9 = *(_QWORD *)(*(_QWORD *)((char *)v5 + v6 + (unsigned __int64)v3->mSet + 56) + 8 * v8);
        v10 = *v5;
        if ( (_DWORD)v10 != -1 )
        {
          v11 = *(_QWORD *)(v9 + 72);
          if ( v11 )
            v12 = v11 + v9 + 72;
          else
            v12 = 0i64;
          v13 = (_QWORD *)(v12 + 8 * v10);
          if ( *v13 && (v14 = (char *)v13 + *v13) != 0i64 )
          {
            v15 = v14 - (char *)&v20;
            v20 = v15;
            if ( v15 )
            {
              v16 = (UFG::TrueCrowdResource *)((char *)&v20 + v15);
LABEL_16:
              user.mMeshLoader = (UFG::MeshResourceLoader *)v2;
              user.mType = 2;
              if ( v9 )
              {
                priority = &v18;
                v18 = qSymbol_Low.mUID;
                LODWORD(priority) = qSymbol_Low;
                UFG::ResourcePool::RequestLoadResource(
                  &UFG::ObjectResourceManager::sInstance->mPool,
                  (UFG::TrueCrowdResource *)v9,
                  0,
                  (__int64)&priority,
                  &user);
              }
              if ( v16 )
              {
                priority = &v18;
                v18 = qSymbol_Low.mUID;
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
void __fastcall UFG::TrueCrowdSet::Instance::RemoveProxyReference(UFG::TrueCrowdSet::Instance *this, UFG::PedSpawningInfo *proxy)
{
  UFG::PedSpawningInfo *v2; // r12
  UFG::TrueCrowdSet::Instance *v3; // r15
  unsigned int v4; // eax
  unsigned int *v5; // rsi
  signed __int64 v6; // r13
  __int64 v7; // r14
  __int64 v8; // rcx
  __int64 v9; // rdx
  __int64 v10; // r8
  __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // r8
  char *v14; // rax
  __int64 v15; // rax
  char *v16; // rbx
  UFG::ObjectResourceManager *v17; // rdi
  UFG::ResourceRequest *v18; // r9
  UFG::ObjectResourceManager *v19; // rax
  UFG::PriorityBucket::Type v20; // edx
  UFG::ObjectResourceManager *v21; // rdi
  UFG::ResourceRequest *v22; // r9
  UFG::ObjectResourceManager *v23; // rax
  UFG::PriorityBucket::Type v24; // edx
  UFG::ResourceUser dependency; // [rsp+38h] [rbp-18h]
  unsigned int v26; // [rsp+98h] [rbp+48h]
  unsigned int *v27; // [rsp+A0h] [rbp+50h]
  __int64 v28; // [rsp+A8h] [rbp+58h]

  v2 = proxy;
  v3 = this;
  if ( proxy->mPedType != 2 )
  {
    --this->mSet->mCurrentInstances;
    v4 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mSet->mEntityIndex].mComponentCount;
    if ( v4 )
    {
      v5 = &this->mPart[0].mTextureSetIndex;
      v6 = -28i64 - (_QWORD)this;
      v7 = v4;
      while ( 1 )
      {
        v8 = *(v5 - 1);
        if ( (_DWORD)v8 != -1 )
          break;
LABEL_51:
        v5 += 4;
        if ( !--v7 )
          return;
      }
      v9 = *(_QWORD *)(*(_QWORD *)((char *)v5 + v6 + (unsigned __int64)v3->mSet + 56) + 8 * v8);
      v10 = *v5;
      if ( (_DWORD)v10 != -1 )
      {
        v11 = *(_QWORD *)(v9 + 72);
        if ( v11 )
          v12 = v11 + v9 + 72;
        else
          v12 = 0i64;
        v13 = (_QWORD *)(v12 + 8 * v10);
        if ( *v13 && (v14 = (char *)v13 + *v13) != 0i64 )
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
      dependency.mMeshLoader = (UFG::MeshResourceLoader *)v2;
      dependency.mType = 2;
      if ( v9 && *(_QWORD *)(v9 + 8) )
      {
        v27 = &v26;
        v26 = qSymbol_Low.mUID;
        v17 = UFG::ObjectResourceManager::sInstance;
        LODWORD(v27) = qSymbol_Low;
        v18 = 0i64;
        v19 = (UFG::ObjectResourceManager *)UFG::ObjectResourceManager::sInstance->mPool.mRequestList.mNode.mNext;
        if ( v19 != (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
        {
          while ( v19->mPool.mLoading.size != *(_DWORD *)(v9 + 28) )
          {
            v19 = (UFG::ObjectResourceManager *)v19->mPool.mQueued.p;
            if ( v19 == (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
              goto LABEL_22;
          }
          v18 = (UFG::ResourceRequest *)v19;
        }
LABEL_22:
        if ( (_DWORD)v27 == qSymbol_Critical.mUID )
        {
          v20 = 2;
        }
        else if ( (_DWORD)v27 == qSymbol_High.mUID )
        {
          v20 = 3;
        }
        else if ( (_DWORD)v27 == qSymbol_Medium.mUID || (_DWORD)v27 == qSymbol_Low.mUID )
        {
          v20 = 4;
        }
        else
        {
          v20 = 4;
          if ( (_DWORD)v27 == qSymbol_Reserved.mUID )
            v20 = 1;
        }
        UFG::ResourceRequest::RemoveDependency(v18, v20, &dependency);
        v17->mPool.mDirty = 1;
      }
      if ( v16 && *((_QWORD *)v16 + 1) )
      {
        v27 = &v26;
        v26 = qSymbol_Low.mUID;
        v21 = UFG::ObjectResourceManager::sInstance;
        LODWORD(v27) = qSymbol_Low;
        v22 = 0i64;
        v23 = (UFG::ObjectResourceManager *)UFG::ObjectResourceManager::sInstance->mPool.mRequestList.mNode.mNext;
        if ( v23 != (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
        {
          while ( v23->mPool.mLoading.size != *((_DWORD *)v16 + 7) )
          {
            v23 = (UFG::ObjectResourceManager *)v23->mPool.mQueued.p;
            if ( v23 == (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
              goto LABEL_40;
          }
          v22 = (UFG::ResourceRequest *)v23;
        }
LABEL_40:
        if ( (_DWORD)v27 == qSymbol_Critical.mUID )
        {
          v24 = 2;
        }
        else if ( (_DWORD)v27 == qSymbol_High.mUID )
        {
          v24 = 3;
        }
        else if ( (_DWORD)v27 == qSymbol_Medium.mUID || (_DWORD)v27 == qSymbol_Low.mUID )
        {
          v24 = 4;
        }
        else
        {
          v24 = 4;
          if ( (_DWORD)v27 == qSymbol_Reserved.mUID )
            v24 = 1;
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
  unsigned int v1; // er12
  unsigned int v2; // er13
  UFG::TrueCrowdModel ***v3; // r15
  char *v4; // r14
  UFG::TrueCrowdModel *v5; // r8
  __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  UFG::ResourceRequest *v12; // rax
  __int64 v13; // rax
  unsigned int v15; // ebp
  unsigned int v16; // ebx
  UFG::TrueCrowdModel **v17; // rdi
  UFG::TrueCrowdModel *v18; // rax
  UFG::ResourceRequest *v19; // rcx
  unsigned int v20; // er10
  unsigned int v21; // edx
  __int64 v22; // r9
  signed __int64 v23; // r11
  __int64 v24; // r8
  signed __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rax

  v1 = 0;
  v2 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  if ( !v2 )
    return 1;
  v3 = &this->mFiles[0].p;
  v4 = &this->mComponentDetails[0].mbTextureSetIndexValid;
  while ( !*(v4 - 1) || !*v4 )
  {
    v15 = *((_DWORD *)v3 - 2);
    if ( !v15 )
      goto LABEL_15;
    v16 = 0;
    if ( !v15 )
      return 0;
    v17 = *v3;
    while ( 1 )
    {
      v18 = *v17;
      v19 = (*v17)->mRequest;
      if ( v19 )
      {
        if ( v19->mLoadStatus == 3 )
          break;
      }
LABEL_34:
      ++v16;
      ++v17;
      if ( v16 >= v15 )
        return 0;
    }
    v20 = v18->mNumTextureSets;
    v21 = 0;
    if ( !v18->mNumTextureSets )
    {
LABEL_33:
      if ( (_WORD)v20 == 0 )
        goto LABEL_15;
      goto LABEL_34;
    }
    v22 = v18->mTextureSets.mOffset;
    v23 = (signed __int64)&v18->mTextureSets;
    v24 = 0i64;
    while ( 1 )
    {
      if ( v22 )
        v25 = v22 + v23;
      else
        v25 = 0i64;
      v26 = v24 + v25;
      v27 = *(_QWORD *)(v24 + v25);
      if ( v27 )
        v27 += v26;
      v28 = *(_QWORD *)(v27 + 8);
      if ( v28 )
      {
        if ( *(_DWORD *)(v28 + 20) == 3 )
          break;
      }
      ++v21;
      v24 += 8i64;
      if ( v21 >= v20 )
        goto LABEL_33;
    }
LABEL_15:
    ++v1;
    v4 += 12;
    v3 += 2;
    if ( v1 >= v2 )
      return 1;
  }
  v5 = **v3;
  v6 = v5->mTextureSets.mOffset;
  if ( v6 )
    v7 = (signed __int64)&v5->mTextureSets + v6;
  else
    v7 = 0i64;
  v8 = *(unsigned int *)(v4 + 3);
  v9 = v7 + 8 * v8;
  v10 = *(_QWORD *)(v7 + 8 * v8);
  if ( v10 )
    v11 = v10 + v9;
  else
    v11 = 0i64;
  v12 = v5->mRequest;
  if ( v12 )
  {
    if ( v12->mLoadStatus == 3 )
    {
      v13 = *(_QWORD *)(v11 + 8);
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 + 20) == 3 )
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
  unsigned int v1; // er12
  unsigned int v2; // er13
  UFG::TrueCrowdModel ***v3; // r15
  char *v4; // r14
  UFG::TrueCrowdModel *v5; // r8
  __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  UFG::ResourceRequest *v12; // rax
  __int64 v13; // rax
  unsigned int v15; // ebp
  unsigned int v16; // ebx
  UFG::TrueCrowdModel **v17; // rdi
  UFG::TrueCrowdModel *v18; // rax
  UFG::ResourceRequest *v19; // rcx
  unsigned int v20; // er10
  unsigned int v21; // edx
  __int64 v22; // r9
  signed __int64 v23; // r11
  __int64 v24; // r8
  signed __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rax

  v1 = 0;
  v2 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  if ( !v2 )
    return 1;
  v3 = &this->mFiles[0].p;
  v4 = &this->mComponentDetails[0].mbTextureSetIndexValid;
  while ( !*(v4 - 1) || !*v4 )
  {
    v15 = *((_DWORD *)v3 - 2);
    v16 = 0;
    if ( !v15 )
      return 0;
    v17 = *v3;
    while ( 1 )
    {
      v18 = *v17;
      v19 = (*v17)->mRequest;
      if ( v19 )
      {
        if ( v19->mPreloads.size )
          break;
      }
LABEL_33:
      ++v16;
      ++v17;
      if ( v16 >= v15 )
        return 0;
    }
    v20 = v18->mNumTextureSets;
    v21 = 0;
    if ( !v18->mNumTextureSets )
    {
LABEL_32:
      if ( (_WORD)v20 == 0 )
        goto LABEL_15;
      goto LABEL_33;
    }
    v22 = v18->mTextureSets.mOffset;
    v23 = (signed __int64)&v18->mTextureSets;
    v24 = 0i64;
    while ( 1 )
    {
      if ( v22 )
        v25 = v22 + v23;
      else
        v25 = 0i64;
      v26 = v24 + v25;
      v27 = *(_QWORD *)(v24 + v25);
      if ( v27 )
        v27 += v26;
      v28 = *(_QWORD *)(v27 + 8);
      if ( v28 )
      {
        if ( *(_DWORD *)(v28 + 56) )
          break;
      }
      ++v21;
      v24 += 8i64;
      if ( v21 >= v20 )
        goto LABEL_32;
    }
LABEL_15:
    ++v1;
    v4 += 12;
    v3 += 2;
    if ( v1 >= v2 )
      return 1;
  }
  v5 = **v3;
  v6 = v5->mTextureSets.mOffset;
  if ( v6 )
    v7 = (signed __int64)&v5->mTextureSets + v6;
  else
    v7 = 0i64;
  v8 = *(unsigned int *)(v4 + 3);
  v9 = v7 + 8 * v8;
  v10 = *(_QWORD *)(v7 + 8 * v8);
  if ( v10 )
    v11 = v10 + v9;
  else
    v11 = 0i64;
  v12 = v5->mRequest;
  if ( v12 )
  {
    if ( v12->mPreloads.size )
    {
      v13 = *(_QWORD *)(v11 + 8);
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 + 56) )
          goto LABEL_15;
      }
    }
  }
  return 0;
}

// File Line: 587
// RVA: 0x43D790
void __fastcall UFG::TrueCrowdSet::GetCurrentMemoryUsage(UFG::TrueCrowdSet *this, unsigned int *modelMemory, unsigned int *textureMemory)
{
  unsigned int *v3; // r11
  unsigned int *v4; // rsi
  unsigned int v5; // er10
  UFG::qArray<UFG::TrueCrowdModel *,0> *v6; // rdi
  char *v7; // rbp
  __int64 v8; // r14
  UFG::TrueCrowdModel **v9; // rax
  UFG::TrueCrowdModel *v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // rdx
  __int64 v15; // rax
  signed __int64 v16; // rax
  unsigned int i; // ebx
  UFG::TrueCrowdModel *v18; // r10
  unsigned int v19; // er8
  __int64 v20; // rax
  signed __int64 v21; // rdx
  signed __int64 v22; // r9
  signed __int64 v23; // rcx
  __int64 v24; // rdx
  signed __int64 v25; // rcx
  signed __int64 v26; // rcx
  signed __int64 v27; // rax
  __int64 v28; // rcx
  signed __int64 v29; // rax

  v3 = textureMemory;
  v4 = modelMemory;
  v5 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  *modelMemory = 0;
  *textureMemory = 0;
  if ( v5 )
  {
    v6 = this->mFiles;
    v7 = &this->mComponentDetails[0].mbTextureSetIndexValid;
    v8 = v5;
    do
    {
      if ( *(v7 - 1) && *v7 )
      {
        v9 = v6->p;
        v10 = *v9;
        if ( (*v9)->mRequest )
        {
          *v4 += v10->mModelSize;
          *v3 += v10->mTextureSize;
        }
        v11 = v10->mTextureSets.mOffset;
        if ( v11 )
          v12 = (signed __int64)&v10->mTextureSets + v11;
        else
          v12 = 0i64;
        v13 = *(unsigned int *)(v7 + 3);
        v14 = v12 + 8 * v13;
        v15 = *(_QWORD *)(v12 + 8 * v13);
        if ( v15 )
          v16 = v14 + v15;
        else
          v16 = 0i64;
        if ( *(_QWORD *)(v16 + 8) )
          *v3 += *(_DWORD *)(v16 + 20);
      }
      else
      {
        for ( i = 0; i < v6->size; ++i )
        {
          v18 = v6->p[i];
          if ( v18->mRequest )
          {
            *v4 += v18->mModelSize;
            *v3 += v18->mTextureSize;
          }
          v19 = 0;
          if ( v18->mNumTextureSets > 0u )
          {
            do
            {
              v20 = v18->mTextureSets.mOffset;
              if ( v20 )
                v21 = (signed __int64)&v18->mTextureSets + v20;
              else
                v21 = 0i64;
              v22 = 8i64 * v19;
              v23 = v22 + v21;
              v24 = *(_QWORD *)(v22 + v21);
              if ( v24 )
                v25 = v24 + v23;
              else
                v25 = 0i64;
              if ( *(_QWORD *)(v25 + 8) )
              {
                if ( v20 )
                  v26 = (signed __int64)&v18->mTextureSets + v20;
                else
                  v26 = 0i64;
                v27 = v22 + v26;
                v28 = *(_QWORD *)(v22 + v26);
                if ( v28 )
                  v29 = v28 + v27;
                else
                  v29 = 0i64;
                *v3 += *(_DWORD *)(v29 + 20);
              }
              ++v19;
            }
            while ( v19 < v18->mNumTextureSets );
          }
        }
      }
      v7 += 12;
      ++v6;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 633
// RVA: 0x43A240
UFG::TrueCrowdModel *__fastcall UFG::TrueCrowdSet::ChooseNextPart(UFG::TrueCrowdSet *this)
{
  UFG::TrueCrowdSet *v1; // rsi
  __int64 v2; // rbx
  unsigned int v3; // er10
  signed int v4; // edi
  int *v5; // rdx
  UFG::TrueCrowdModel ***v6; // r9
  __int64 v7; // r11
  unsigned int v8; // eax
  UFG::TrueCrowdModel **v9; // rcx
  __int64 v10; // r8
  UFG::qArray<UFG::TrueCrowdModel *,0> *v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  signed int v14; // eax
  unsigned int v15; // edx
  __int64 v16; // rcx
  signed __int64 v17; // r9
  unsigned int v18; // er8
  float *v19; // r8
  float v20; // xmm0_4
  __int64 v21; // r9
  unsigned int v22; // edx
  unsigned int v23; // er8
  UFG::TrueCrowdModel **v24; // rcx
  __int64 v25; // rax
  int v27; // [rsp+20h] [rbp-208h]
  int v28; // [rsp+24h] [rbp-204h]
  int v29; // [rsp+28h] [rbp-200h]
  int v30[13]; // [rsp+2Ch] [rbp-1FCh]
  int dest[16]; // [rsp+60h] [rbp-1C8h]
  int v32[96]; // [rsp+A0h] [rbp-188h]

  v1 = this;
  v2 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  UFG::qMemSet(dest, 0, 0x40u);
  v3 = 0;
  v4 = 0;
  if ( (_DWORD)v2 )
  {
    v5 = dest;
    v6 = &v1->mFiles[0].p;
    v7 = (unsigned int)v2;
    do
    {
      v8 = *((_DWORD *)v6 - 2);
      if ( v8 )
      {
        v9 = *v6;
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
      v6 += 2;
      ++v5;
      --v7;
    }
    while ( v7 );
    if ( (_DWORD)v2 )
    {
      v11 = v1->mFiles;
      v12 = 0i64;
      v13 = v2;
      do
      {
        v14 = dest[v12];
        *(float *)((char *)&v27 + v12 * 4) = (float)v14 * (float)(1.0 / (float)v4);
        if ( v14 == v11->size )
          *(int *)((char *)&v27 + v12 * 4) = 1065353216;
        ++v11;
        ++v12;
        --v13;
      }
      while ( v13 );
    }
  }
  v15 = 1;
  v16 = 0i64;
  v17 = 1i64;
  if ( (unsigned int)v2 > 1 )
  {
    if ( (signed int)v2 - 1 >= 4 )
    {
      v18 = 3;
      do
      {
        if ( *((float *)&v27 + v17) < *((float *)&v27 + (unsigned int)v16) )
          v16 = v15;
        if ( *((float *)&v27 + v16) > *((float *)&v28 + v17) )
          v16 = v18 - 1;
        if ( *((float *)&v29 + v17) < *((float *)&v27 + v16) )
          v16 = v18;
        if ( *((float *)&v27 + v16) > *(float *)&v30[v17] )
          v16 = v18 + 1;
        v15 += 4;
        v17 += 4i64;
        v18 += 4;
      }
      while ( v15 < (signed int)v2 - 3 );
    }
    if ( v15 < (unsigned int)v2 )
    {
      v19 = (float *)(&v27 + v17);
      do
      {
        v20 = *v19;
        ++v19;
        if ( v20 < *((float *)&v27 + (unsigned int)v16) )
          LODWORD(v16) = v15;
        ++v15;
      }
      while ( v15 < (unsigned int)v2 );
    }
  }
  v21 = (unsigned int)v16;
  v22 = 0;
  v23 = *((_DWORD *)&v1->mPrev + 4 * ((unsigned int)v16 + 3i64));
  if ( v23 )
  {
    v24 = v1->mFiles[(unsigned int)v16].p;
    do
    {
      if ( !(*v24)->mRequest && v3 < 0x60 )
      {
        v25 = v3++;
        v32[v25] = v22;
      }
      ++v22;
      ++v24;
    }
    while ( v22 < v23 );
  }
  ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
  return v1->mFiles[v21].p[v32[(unsigned __int64)(v3 * (ARandom::c_gen.i_seed >> 16)) >> 16]];
}

// File Line: 693
// RVA: 0x439B10
UFG::TrueCrowdModel *__fastcall UFG::TrueCrowdSet::ChooseContractableAmbientPart(UFG::TrueCrowdSet *this)
{
  unsigned int v1; // er9
  UFG::TrueCrowdSet *v2; // rsi
  unsigned int v3; // er11
  unsigned int v4; // ebx
  unsigned int v5; // edi
  UFG::TrueCrowdModel ***v6; // r10
  unsigned int v7; // eax
  unsigned int v8; // edx
  UFG::TrueCrowdModel **v9; // rcx
  __int64 v10; // r8
  UFG::TrueCrowdModel *v11; // rdx
  unsigned int v12; // er10
  unsigned int v13; // er8
  signed __int64 v14; // rcx
  __int64 v15; // rdi
  UFG::TrueCrowdModel **v16; // r11
  UFG::ResourceRequest *v17; // r9
  unsigned int v18; // eax
  unsigned int *v19; // rcx
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // eax
  UFG::ResourceRequest *v23; // rax

  v1 = 0;
  v2 = this;
  v3 = 1;
  v4 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = &this->mFiles[0].p;
  do
  {
    v7 = *((_DWORD *)v6 - 2);
    v8 = 0;
    if ( v7 )
    {
      v9 = *v6;
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
    v6 += 2;
  }
  while ( v1 < v4 );
  if ( v5 == v4 )
    return 0i64;
  v11 = 0i64;
  v12 = -1;
  v13 = *((_DWORD *)&v2->mPrev + 4 * (v5 + 3i64));
  if ( v13 )
  {
    v14 = v5;
    v15 = v13;
    v16 = v2->mFiles[v14].p;
    do
    {
      v17 = (*v16)->mRequest;
      if ( v17 )
      {
        v18 = 0;
        v19 = v17->mPriorityRefCounts;
        while ( !*v19 )
        {
          ++v18;
          ++v19;
          if ( v18 >= 5 )
            goto LABEL_33;
        }
        if ( v18 == 4 )
        {
          v20 = v17->mInstances.size;
          v21 = v17->mProxies.size;
          v22 = v21 + v20 + v17->mPreloads.size;
          if ( v11 )
          {
            if ( v22 >= v12 )
            {
              if ( v22 == v12 )
              {
                v23 = v11->mRequest;
                if ( v23 && v23->mLoadStatus == 3 && v17->mLoadStatus != 3 )
                {
                  v11 = *v16;
                }
                else if ( v23->mInstances.size <= v20 )
                {
                  if ( v23->mProxies.size > v21 )
                    v11 = *v16;
                }
                else
                {
                  v11 = *v16;
                }
              }
            }
            else
            {
              v11 = *v16;
              v12 = v21 + v20 + v17->mPreloads.size;
            }
          }
          else
          {
            v11 = *v16;
            v12 = v21 + v20 + v17->mPreloads.size;
          }
        }
      }
LABEL_33:
      ++v16;
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
  unsigned int v1; // er9
  unsigned int v2; // er8
  UFG::TrueCrowdModel ***v3; // r10
  __int64 v4; // r11
  unsigned int v5; // eax
  UFG::TrueCrowdModel **v6; // rcx
  __int64 v7; // r8
  UFG::ResourceRequest *v8; // rdx

  v1 = 0;
  v2 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  if ( v2 )
  {
    v3 = &this->mFiles[0].p;
    v4 = v2;
    do
    {
      v5 = *((_DWORD *)v3 - 2);
      if ( v5 )
      {
        v6 = *v3;
        v7 = v5;
        do
        {
          v8 = (*v6)->mRequest;
          if ( v8 && v8->mLoadStatus == 3 )
            ++v1;
          ++v6;
          --v7;
        }
        while ( v7 );
      }
      v3 += 2;
      --v4;
    }
    while ( v4 );
  }
  return v1;
}

// File Line: 908
// RVA: 0x43A6B0
void __fastcall UFG::TrueCrowdSet::ChooseSpecificModel(UFG::TrueCrowdSet *this, unsigned int partIndex, UFG::ModelTextureCombination *modelTextureCombination, UFG::OverrideForceParams *ofp)
{
  __int64 v4; // r10
  UFG::ModelTextureCombination *v5; // r11
  UFG::TrueCrowdSet *v6; // r8
  UFG::TrueCrowdTextureSet *v7; // rcx
  UFG::OverrideForceParams *v8; // rsi
  signed __int64 v9; // rdx
  unsigned int v10; // ebx
  UFG::TrueCrowdModel **v11; // rax
  UFG::TrueCrowdModel *v12; // rdi
  unsigned int *v13; // r9
  __int64 v14; // rax
  signed __int64 v15; // rdx
  __int64 v16; // rax

  v4 = partIndex;
  v5 = modelTextureCombination;
  v6 = this;
  v7 = 0i64;
  v8 = ofp;
  v9 = (signed __int64)v6 + 12 * partIndex;
  v5->mModelIndex = 0;
  v10 = 0;
  if ( *(_BYTE *)(v9 + 305) )
    v10 = *(_DWORD *)(v9 + 308);
  v5->mTextureSetIndex = v10;
  if ( *((_DWORD *)&v6->mPrev + 4 * (v4 + 3)) )
  {
    v11 = v6->mFiles[v4].p;
    v12 = *v11;
    if ( (*v11)->mNumTextureSets > 0u )
    {
      if ( *(_BYTE *)(v9 + 306) )
        v13 = (unsigned int *)((char *)v6 + 12 * (v4 + 26));
      else
        v13 = 0i64;
      v14 = v12->mTextureSets.mOffset;
      if ( v14 )
        v15 = (signed __int64)&v12->mTextureSets + v14;
      else
        v15 = 0i64;
      v16 = *(_QWORD *)(v15 + 8i64 * v10);
      if ( v16 )
        v7 = (UFG::TrueCrowdTextureSet *)(v16 + v15 + 8i64 * v10);
      UFG::TrueCrowdTextureSet::SetRandomOverrides(v7, v5, v8, v13);
    }
  }
  else
  {
    v5->mModelIndex = -1;
  }
}

// File Line: 936
// RVA: 0x43A550
void __fastcall UFG::TrueCrowdSet::ChooseRandomModel(UFG::TrueCrowdSet *this, unsigned int partIndex, UFG::ModelTextureCombination *modelTextureCombination, UFG::OverrideForceParams *ofp)
{
  UFG::TrueCrowdSet *v4; // rdi
  UFG::ModelTextureCombination *v5; // r10
  int v6; // ecx
  unsigned int v7; // er11
  unsigned int v8; // er8
  unsigned int v9; // er11
  __int64 v10; // r8
  int v11; // eax
  __int64 v12; // r11
  UFG::TrueCrowdModel *v13; // r8
  __int64 v14; // rax
  signed __int64 v15; // rcx
  signed __int64 v16; // rdx
  __int64 v17; // rax
  signed __int64 v18; // r8
  int v19; // er11
  __int64 v20; // rax
  __int64 v21; // rax

  v4 = this;
  v5 = modelTextureCombination;
  v6 = *((_DWORD *)&this->mPrev + 4 * (partIndex + 3i64));
  if ( v6 )
  {
    v7 = 1664525 * ARandom::c_gen.i_seed + 1013904223;
    ARandom::c_gen.i_seed = v7;
    v8 = v7;
    v9 = 1664525 * v7 + 1013904223;
    v10 = v6 * (v8 >> 16) >> 16;
    v11 = v4->mFiles[partIndex].p[v10]->mNumTextureSets;
    ARandom::c_gen.i_seed = v9;
    v5->mModelIndex = v10;
    v12 = v11 * (v9 >> 16) >> 16;
    v5->mTextureSetIndex = v12;
    v13 = v4->mFiles[partIndex].p[v10];
    if ( v13->mNumTextureSets )
    {
      v14 = v13->mTextureSets.mOffset;
      v15 = 0i64;
      v16 = (signed __int64)(v14 ? (UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *)((char *)&v13->mTextureSets
                                                                                                  + v14) : 0i64);
      v17 = *(_QWORD *)(v16 + 8 * v12);
      v18 = v17 ? v17 + v16 + 8 * v12 : 0i64;
      v19 = *(_DWORD *)(v18 + 72);
      if ( v19 )
      {
        if ( ofp && ofp->mColorTintValid )
        {
          v20 = *(_QWORD *)(v18 + 56);
          if ( v20 )
            v15 = v20 + v18 + 56;
          v5->mColourTint = (UFG::qColour *)(v15 + 16i64 * ofp->mColorTintIndex);
        }
        else
        {
          v21 = *(_QWORD *)(v18 + 56);
          if ( v21 )
            v15 = v21 + v18 + 56;
          v5->mColourTint = (UFG::qColour *)(v15 + 16i64 * *(unsigned __int16 *)(v18 + 78));
          *(_WORD *)(v18 + 78) = (*(unsigned __int16 *)(v18 + 78) + 1) % v19;
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
void __fastcall UFG::TrueCrowdSet::ChooseLeastCommonModel(UFG::TrueCrowdSet *this, unsigned int partIndex, UFG::ModelTextureCombination *modelTextureCombination, UFG::OverrideForceParams *ofp)
{
  __int64 v4; // rbx
  signed __int64 v5; // rdx
  UFG::OverrideForceParams *v6; // r12
  UFG::ModelTextureCombination *v7; // rsi
  UFG::TrueCrowdSet *v8; // rdi
  unsigned int v9; // er11
  unsigned int v10; // er10
  UFG::TrueCrowdModel **v11; // r9
  unsigned int v12; // er14
  unsigned int v13; // ecx
  unsigned int v14; // er15
  unsigned int v15; // ebp
  UFG::ResourceRequest *v16; // r8
  unsigned int v17; // er8
  UFG::TrueCrowdModel *v18; // rbx
  __int64 v19; // r10
  __int64 v20; // r9
  signed __int64 v21; // rax
  signed __int64 v22; // rcx
  __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // rcx
  __int64 v26; // rax
  signed __int64 v27; // rcx
  __int64 v28; // rax
  signed __int64 v29; // rcx
  int v30; // er8
  __int64 v31; // rax
  __int64 v32; // rax

  v4 = partIndex;
  v5 = 0i64;
  v6 = ofp;
  v7 = modelTextureCombination;
  v8 = this;
  v9 = *((_DWORD *)&this->mPrev + 4 * (v4 + 3));
  if ( v9 )
  {
    v10 = 4096;
    v11 = this->mFiles[(unsigned int)v4].p;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 4096;
    do
    {
      v16 = (*v11)->mRequest;
      if ( v16 && v16->mInstances.size + v16->mProxies.size < v10 )
      {
        v10 = v16->mInstances.size + v16->mProxies.size;
        v12 = v13;
      }
      ++v13;
      ++v11;
    }
    while ( v13 < v9 );
    v17 = 0;
    v18 = v8->mFiles[v4].p[v12];
    if ( v18->mNumTextureSets )
    {
      v19 = v18->mTextureSets.mOffset;
      v20 = 0i64;
      do
      {
        if ( v19 )
          v21 = (signed __int64)&v18->mTextureSets + v19;
        else
          v21 = 0i64;
        v22 = v20 + v21;
        v23 = *(_QWORD *)(v20 + v21);
        if ( v23 )
          v24 = v23 + v22;
        else
          v24 = 0i64;
        v25 = *(_QWORD *)(v24 + 8);
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
    v7->mModelIndex = v12;
    v7->mTextureSetIndex = v14;
    if ( v18->mNumTextureSets > 0u )
    {
      v26 = v18->mTextureSets.mOffset;
      if ( v26 )
        v27 = (signed __int64)&v18->mTextureSets + v26;
      else
        v27 = 0i64;
      v28 = *(_QWORD *)(v27 + 8i64 * v14);
      v29 = v28 + v27 + 8i64 * v14;
      if ( !v28 )
        v29 = 0i64;
      v30 = *(_DWORD *)(v29 + 72);
      if ( v30 )
      {
        if ( v6 && v6->mColorTintValid )
        {
          v31 = *(_QWORD *)(v29 + 56);
          if ( v31 )
            v5 = v31 + v29 + 56;
          v7->mColourTint = (UFG::qColour *)(v5 + 16i64 * v6->mColorTintIndex);
        }
        else
        {
          v32 = *(_QWORD *)(v29 + 56);
          if ( v32 )
            v5 = v32 + v29 + 56;
          v7->mColourTint = (UFG::qColour *)(v5 + 16i64 * *(unsigned __int16 *)(v29 + 78));
          *(_WORD *)(v29 + 78) = (*(unsigned __int16 *)(v29 + 78) + 1) % v30;
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
void __fastcall UFG::TrueCrowdSet::ChooseHighestCostModel(UFG::TrueCrowdSet *this, unsigned int partIndex, UFG::ModelTextureCombination *modelTextureCombination, UFG::OverrideForceParams *ofp)
{
  __int64 v4; // rdi
  signed __int64 v5; // rdx
  UFG::OverrideForceParams *v6; // r13
  UFG::ModelTextureCombination *v7; // r14
  UFG::TrueCrowdSet *v8; // rsi
  unsigned int v9; // ebx
  unsigned int v10; // er11
  UFG::TrueCrowdModel **v11; // r10
  unsigned int v12; // er12
  unsigned int v13; // er8
  unsigned int v14; // er15
  unsigned int v15; // ebp
  unsigned int v16; // ecx
  UFG::ResourceRequest *v17; // r9
  unsigned int v18; // er8
  UFG::TrueCrowdModel *v19; // rbx
  __int64 v20; // r10
  __int64 v21; // r9
  signed __int64 v22; // rax
  signed __int64 v23; // rcx
  __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // rcx
  unsigned int v27; // eax
  __int64 v28; // rax
  signed __int64 v29; // rcx
  __int64 v30; // rax
  signed __int64 v31; // rcx
  int v32; // er8
  __int64 v33; // rax
  __int64 v34; // rax

  v4 = partIndex;
  v5 = 0i64;
  v6 = ofp;
  v7 = modelTextureCombination;
  v8 = this;
  v9 = *((_DWORD *)&this->mPrev + 4 * (v4 + 3));
  if ( v9 )
  {
    v10 = 4096;
    v11 = this->mFiles[(unsigned int)v4].p;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 4096;
    do
    {
      v16 = 0;
      v17 = (*v11)->mRequest;
      if ( v17 )
        v16 = v17->mInstances.size + v17->mProxies.size;
      if ( v16 < v10 )
      {
        v10 = v16;
        v14 = v13;
      }
      ++v13;
      ++v11;
    }
    while ( v13 < v9 );
    v18 = 0;
    v19 = v8->mFiles[v4].p[v14];
    if ( v19->mNumTextureSets )
    {
      v20 = v19->mTextureSets.mOffset;
      v21 = 0i64;
      do
      {
        if ( v20 )
          v22 = (signed __int64)&v19->mTextureSets + v20;
        else
          v22 = 0i64;
        v23 = v21 + v22;
        v24 = *(_QWORD *)(v21 + v22);
        if ( v24 )
          v25 = v24 + v23;
        else
          v25 = 0i64;
        v26 = *(_QWORD *)(v25 + 8);
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
    v7->mModelIndex = v14;
    v7->mTextureSetIndex = v12;
    if ( v19->mNumTextureSets > 0u )
    {
      v28 = v19->mTextureSets.mOffset;
      if ( v28 )
        v29 = (signed __int64)&v19->mTextureSets + v28;
      else
        v29 = 0i64;
      v30 = *(_QWORD *)(v29 + 8i64 * v12);
      v31 = v30 + v29 + 8i64 * v12;
      if ( !v30 )
        v31 = 0i64;
      v32 = *(_DWORD *)(v31 + 72);
      if ( v32 )
      {
        if ( v6 && v6->mColorTintValid )
        {
          v33 = *(_QWORD *)(v31 + 56);
          if ( v33 )
            v5 = v33 + v31 + 56;
          v7->mColourTint = (UFG::qColour *)(v5 + 16i64 * v6->mColorTintIndex);
        }
        else
        {
          v34 = *(_QWORD *)(v31 + 56);
          if ( v34 )
            v5 = v34 + v31 + 56;
          v7->mColourTint = (UFG::qColour *)(v5 + 16i64 * *(unsigned __int16 *)(v31 + 78));
          *(_WORD *)(v31 + 78) = (*(unsigned __int16 *)(v31 + 78) + 1) % v32;
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
void __fastcall UFG::TrueCrowdSet::SelectInstance(UFG::TrueCrowdSet *this, UFG::TrueCrowdSet::Instance *instance, UFG::OverrideForceParams *ofp, UFG::TrueCrowdSet::SelectionFlags selectionFlag)
{
  UFG::TrueCrowdDataBase *v4; // r10
  __int64 v5; // rbx
  UFG::OverrideForceParams *v6; // rbp
  UFG::TrueCrowdSet::Instance *v7; // r14
  UFG::TrueCrowdSet::SelectionFlags v8; // er15
  UFG::TrueCrowdSet *v9; // rdi
  UFG::ModelTextureCombination *v10; // r8
  int v11; // eax
  UFG::OverrideForceParams *v12; // r9
  UFG::ModelTextureCombination *v13; // r8
  unsigned int v14; // edx
  UFG::TrueCrowdSet *v15; // rcx

  v4 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
  instance->mSet = this;
  v5 = 0i64;
  v6 = ofp;
  v7 = instance;
  LODWORD(v4) = v4->mDefinition.mEntities[this->mEntityIndex].mComponentCount;
  v8 = selectionFlag;
  v9 = this;
  instance->mNumParts = (unsigned int)v4;
  if ( (_DWORD)v4 )
  {
    do
    {
      if ( v9->mComponentDetails[v5].mbSpecificModel )
      {
        UFG::TrueCrowdSet::ChooseSpecificModel(v9, v5, &v7->mPart[(unsigned int)v5], v6);
      }
      else
      {
        if ( v8 == 1 )
        {
          v12 = v6;
          v13 = &v7->mPart[(unsigned int)v5];
          v14 = v5;
          v15 = v9;
LABEL_12:
          UFG::TrueCrowdSet::ChooseLeastCommonModel(v15, v14, v13, v12);
          goto LABEL_13;
        }
        if ( v8 != 2 )
        {
          v10 = &v7->mPart[(unsigned int)v5];
          if ( v8 == 3 )
            UFG::TrueCrowdSet::ChooseHighestCostModel(v9, v5, v10, v6);
          else
            UFG::TrueCrowdSet::ChooseRandomModel(v9, v5, v10, v6);
          goto LABEL_13;
        }
        v11 = UFG::TrueCrowdSet::GetNumModelsLoaded(v9);
        v12 = v6;
        v13 = &v7->mPart[(unsigned int)v5];
        v14 = v5;
        v15 = v9;
        if ( v11 )
          goto LABEL_12;
        UFG::TrueCrowdSet::ChooseRandomModel(v9, v5, v13, v6);
      }
LABEL_13:
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < v7->mNumParts );
  }
  if ( v6 )
    UFG::OverrideForceParams::GetMorphWeightsFromBMI(v6, v7->mMorphWeights);
}

// File Line: 1203
// RVA: 0x438480
void __fastcall UFG::TrueCrowdDataBaseInventory::Add(UFG::TrueCrowdDataBaseInventory *this, UFG::qResourceData *resource_data)
{
  UFG::TrueCrowdDataBase *v2; // rbx
  UFG::TrueCrowdDataBaseInventory *v3; // rdi

  v2 = (UFG::TrueCrowdDataBase *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::TrueCrowdDataBase::TrueCrowdDataBase((UFG::TrueCrowdDataBase *)resource_data, 0);
  UFG::TrueCrowdDataBase::sTrueCrowdDataBase = v2;
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
}

// File Line: 1211
// RVA: 0x441FB0
void __fastcall UFG::TrueCrowdDataBaseInventory::Remove(UFG::TrueCrowdDataBaseInventory *this, UFG::qResourceData *resource_data)
{
  UFG::TrueCrowdDataBase *v2; // rbx

  v2 = (UFG::TrueCrowdDataBase *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::TrueCrowdDataBase::~TrueCrowdDataBase(v2);
}

// File Line: 1218
// RVA: 0x1511C70
__int64 UFG::_dynamic_initializer_for__gTrueCrowdDataBaseInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gTrueCrowdDataBaseInventory.vfptr,
    "TrueCrowdDataBaseInventory",
    0x4AEEEFDEu,
    0x90EEF023,
    0,
    0);
  UFG::gTrueCrowdDataBaseInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::TrueCrowdDataBaseInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gTrueCrowdDataBaseInventory__);
}

// File Line: 1228
// RVA: 0x437720
void __fastcall UFG::TrueCrowdDataBase::TrueCrowdDataBase(UFG::TrueCrowdDataBase *this, MemImageLoadFlag flag)
{
  UFG::TrueCrowdDataBase *v2; // r13
  unsigned int v3; // esi
  __int64 v4; // rax
  signed __int64 v5; // rcx
  signed __int64 v6; // rdi
  __int64 v7; // rbx
  __int64 v8; // rax
  signed __int64 v9; // rdx
  unsigned int v10; // er12
  __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // r15
  __int64 v14; // r14
  __int64 v15; // rax
  signed __int64 v16; // rcx
  signed __int64 v17; // rbx
  _QWORD *v18; // rdi
  __int64 v19; // rsi
  __int64 v20; // rbp
  char *v21; // rcx
  char *v22; // rax
  __int64 v23; // rcx
  char *v24; // rbx
  unsigned int flaga; // [rsp+A8h] [rbp+10h]
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v26; // [rsp+B0h] [rbp+18h]

  flaga = flag.flag;
  v2 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  `eh vector constructor iterator(
    v2->mDefinition.mEntities,
    0x50Cui64,
    25,
    (void (__fastcall *)(void *))UFG::TrueCrowdDefinition::Entity::Entity);
  v26 = &v2->mKnownRequests;
  v26->mNode.mPrev = &v26->mNode;
  v26->mNode.mNext = &v26->mNode;
  v3 = 0;
  if ( v2->mNumComponentEntries )
  {
    do
    {
      v4 = v2->mComponentEntries.mOffset;
      if ( v4 )
        v5 = (signed __int64)&v2->mComponentEntries + v4;
      else
        v5 = 0i64;
      v6 = v5 + 16i64 * v3;
      if ( v6 )
      {
        v7 = 0i64;
        if ( *(_DWORD *)v6 )
        {
          do
          {
            v8 = *(_QWORD *)(v6 + 8);
            if ( v8 )
              v9 = v8 + v6 + 8;
            else
              v9 = 0i64;
            if ( v9 + 96 * v7 )
              UFG::TrueCrowdModel::TrueCrowdModel((UFG::TrueCrowdModel *)(v9 + 96 * v7 + 16), (MemImageLoadFlag)flaga);
            v7 = (unsigned int)(v7 + 1);
          }
          while ( (unsigned int)v7 < *(_DWORD *)v6 );
        }
      }
      ++v3;
    }
    while ( v3 < v2->mNumComponentEntries );
  }
  v10 = 0;
  if ( v2->mNumComponentEntries )
  {
    do
    {
      v11 = v2->mComponentEntries.mOffset;
      if ( v11 )
        v12 = (signed __int64)&v2->mComponentEntries + v11;
      else
        v12 = 0i64;
      v13 = v12 + 16i64 * v10;
      v14 = 0i64;
      if ( *(_DWORD *)v13 )
      {
        do
        {
          v15 = *(_QWORD *)(v13 + 8);
          if ( v15 )
            v16 = v15 + v13 + 8;
          else
            v16 = 0i64;
          v17 = v16 + 96 * v14;
          UFG::TrueCrowdResource::CacheFileSizes((UFG::TrueCrowdResource *)(v17 + 16));
          if ( *(_WORD *)(v17 + 74) )
          {
            v18 = (_QWORD *)(v17 + 88);
            v19 = 0i64;
            v20 = *(unsigned __int16 *)(v17 + 74);
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
              *((_WORD *)v24 + 39) = UFG::qRandom(*((_DWORD *)v24 + 18), &UFG::qDefaultSeed);
              v19 += 8i64;
              --v20;
            }
            while ( v20 );
          }
          v14 = (unsigned int)(v14 + 1);
        }
        while ( (unsigned int)v14 < *(_DWORD *)v13 );
      }
      ++v10;
    }
    while ( v10 < v2->mNumComponentEntries );
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
UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *__fastcall UFG::TrueCrowdDataBase::QueryCharacterDataBase(UFG::TrueCrowdDataBase *this, unsigned int entityIndex, UFG::qPropertyList *query_tags, UFG::qPropertyList *componentList, UFG::qPropertyList *overrides, UFG::qPropertyList *textureSetList, UFG::qPropertySet *property_set)
{
  UFG::qPropertyList *v7; // r14
  unsigned int v8; // er15
  signed __int64 v9; // r12
  unsigned int v10; // edi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned int v13; // er13
  unsigned int v14; // esi
  unsigned int v15; // er10
  signed __int64 v16; // r15
  int **v17; // r14
  __int64 v18; // rdi
  UFG::TrueCrowdDataBase *v19; // rax
  unsigned int v20; // eax
  char *v21; // rax
  UFG::qPropertySet *v22; // rbx
  UFG::qSymbol *v23; // rax
  int v24; // er9
  __int64 v25; // r8
  int v26; // ecx
  UFG::BitFlags128 *v27; // rax
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // rcx
  unsigned int v30; // er13
  unsigned __int64 v31; // rbx
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v32; // r14
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v33; // rdi
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v34; // rax
  UFG::allocator::free_link *v35; // rax
  signed __int64 v36; // rax
  signed int v37; // ecx
  __int64 v38; // rsi
  unsigned int v39; // er11
  __int64 *v40; // r15
  UFG::qPropertyList *v41; // rbx
  void **v42; // rdi
  __int64 v43; // r14
  UFG::qPropertyList *v44; // r8
  UFG::TrueCrowdDataBase *v45; // rcx
  __int64 v46; // rdx
  int v47; // er11
  __int64 v48; // rax
  signed __int64 v49; // rcx
  signed __int64 v50; // rax
  unsigned int v51; // ecx
  __int64 v52; // r8
  signed __int64 v53; // rdx
  signed __int64 v54; // rsi
  __int64 v55; // r13
  unsigned int v56; // er14
  unsigned int v57; // ebx
  unsigned int v58; // ebx
  unsigned __int64 v59; // rax
  UFG::allocator::free_link *v60; // rax
  UFG::allocator::free_link *v61; // r15
  __int64 v62; // r9
  int v63; // er11
  unsigned int v64; // ecx
  unsigned int v65; // er10
  __int64 *v66; // rsi
  __int64 v67; // r9
  char *v68; // rdx
  char *v69; // r8
  char *v70; // rax
  __int64 v71; // rax
  signed __int64 v72; // rcx
  signed __int64 v73; // r8
  unsigned int v74; // er12
  __int64 v75; // rax
  signed __int64 v76; // rdx
  _QWORD *v77; // rcx
  __int64 v78; // r15
  unsigned int v79; // esi
  unsigned int v80; // ebx
  unsigned int v81; // ebx
  unsigned __int64 v82; // rax
  UFG::allocator::free_link *v83; // rax
  UFG::allocator::free_link *v84; // r14
  unsigned int v85; // er9
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v86; // rax
  unsigned int v87; // er10
  unsigned int v88; // er8
  _DWORD *v89; // r9
  signed __int64 v91; // [rsp+30h] [rbp-D0h]
  unsigned int v92; // [rsp+38h] [rbp-C8h]
  __int64 v93; // [rsp+40h] [rbp-C0h]
  unsigned int v94; // [rsp+48h] [rbp-B8h]
  unsigned __int64 v95; // [rsp+48h] [rbp-B8h]
  unsigned int v96; // [rsp+50h] [rbp-B0h]
  __int64 v97; // [rsp+50h] [rbp-B0h]
  UFG::allocator::free_link *v98; // [rsp+58h] [rbp-A8h]
  char *v99; // [rsp+60h] [rbp-A0h]
  signed __int64 v100; // [rsp+68h] [rbp-98h]
  signed __int64 v101; // [rsp+70h] [rbp-90h]
  UFG::BitFlags128 result; // [rsp+78h] [rbp-88h]
  __int64 v103; // [rsp+88h] [rbp-78h]
  int v104[16]; // [rsp+90h] [rbp-70h]
  int ptr[16]; // [rsp+D0h] [rbp-30h]
  int v106; // [rsp+110h] [rbp+10h]
  __int64 v107; // [rsp+150h] [rbp+50h]
  char Dst; // [rsp+158h] [rbp+58h]
  int dest[64]; // [rsp+1D0h] [rbp+D0h]
  UFG::TrueCrowdDataBase *v110; // [rsp+2E0h] [rbp+1E0h]
  unsigned int v111; // [rsp+2E8h] [rbp+1E8h]
  UFG::qPropertyList *v112; // [rsp+2F0h] [rbp+1F0h]
  UFG::qPropertyList *list; // [rsp+2F8h] [rbp+1F8h]
  UFG::qPropertyList *lista; // [rsp+2F8h] [rbp+1F8h]
  UFG::qPropertyList *overridesa; // [rsp+300h] [rbp+200h]
  UFG::qPropertyList *textureSetLista; // [rsp+308h] [rbp+208h]

  list = componentList;
  v112 = query_tags;
  v111 = entityIndex;
  v110 = this;
  v103 = -2i64;
  v7 = query_tags;
  v8 = entityIndex;
  v9 = 0x50Ci64 * entityIndex;
  v91 = v9;
  v99 = (char *)this + v9;
  v92 = *(unsigned int *)((char *)&this->mDefinition.mEntities[0].mComponentCount + v9);
  v10 = overrides->mNumElements;
  v94 = textureSetList->mNumElements;
  v11 = componentList->mNumElements;
  v96 = componentList->mNumElements;
  `eh vector constructor iterator(ptr, 4ui64, 16, (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(v104, 4ui64, 16, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v12 = 0;
  v107 = 0i64;
  memset(&Dst, 0, 0x78ui64);
  v13 = 0;
  if ( v11 || v10 )
  {
    UFG::qMemSet(dest, 0, 0xC0u);
    v14 = 0;
    v15 = v92;
    if ( v92 )
    {
      v16 = v9;
      v17 = (int **)&v107;
      v18 = 0i64;
      v19 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
      do
      {
        if ( v96 )
        {
          v20 = UFG::PSWrapper::FindElementPropertySet(
                  list,
                  (UFG::qSymbol *)((char *)v19->mDefinition.mEntities[0].mComponents + v9));
          if ( v20 != -1 )
          {
            v21 = UFG::qPropertyList::GetValuePtr(list, 0x1Au, v20);
            if ( v21 && *(_QWORD *)v21 )
              v22 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21];
            else
              v22 = 0i64;
            ptr[v18] = UFG::qPropertySet::Get<UFG::qSymbol>(v22, (UFG::qSymbol *)&qSymbol_Model.mUID, DEPTH_RECURSE)->mUID;
            v23 = UFG::qPropertySet::Get<UFG::qSymbol>(v22, (UFG::qSymbol *)&qSymbol_TextureSet.mUID, DEPTH_RECURSE);
            if ( v23 )
            {
              v104[v18] = v23->mUID;
              *v17 = UFG::qPropertySet::Get<long>(v22, (UFG::qSymbol *)&qSymbol_ColorTintIndex.mUID, DEPTH_RECURSE);
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
      v7 = v112;
      v8 = v111;
      v9 = v91;
    }
    v12 = UFG::qDataHash32(dest, 12i64 * v15, 0xFFFFFFFF);
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
    v27 = UFG::TrueCrowdDefinition::BuildBitFlagFromTags(&v110->mDefinition, &result, v7, property_set);
    v28 = v27->mFlags[0];
    v95 = v27->mFlags[0];
    v29 = v27->mFlags[1];
    v30 = 0;
  }
  v31 = (unsigned int)v29 | ((unsigned __int64)v12 << 32);
  v32 = &v110->mKnownRequests;
  result.mFlags[0] = (unsigned __int64)&v110->mKnownRequests;
  v33 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)v110->mKnownRequests.mNode.mNext;
  if ( v33 != &v110->mKnownRequests )
  {
    do
    {
      v34 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)v33->mNode.mNext;
      if ( v33[1].mNode.mPrev == (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v28
        && v33[1].mNode.mNext == (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v31 )
      {
        goto LABEL_126;
      }
      v33 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)v33->mNode.mNext;
    }
    while ( v34 != v32 );
  }
  v35 = UFG::qMalloc(0x1F0ui64, "TrueCrowdSet", 0i64);
  v33 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)v35;
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
    v36 = (signed __int64)&v33[19];
    v37 = 15;
    do
    {
      *(_WORD *)v36 = 0;
      *(_BYTE *)(v36 + 2) = 0;
      *(_QWORD *)(v36 + 4) = 0i64;
      v36 += 12i64;
      --v37;
    }
    while ( v37 >= 0 );
  }
  else
  {
    v33 = 0i64;
    v98 = 0i64;
  }
  v33[1].mNode.mPrev = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v28;
  v33[1].mNode.mNext = (UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *)v31;
  HIDWORD(v33[2].mNode.mPrev) = v8;
  v38 = (unsigned int)v31;
  v97 = (unsigned int)v31;
  UFG::qMemSet(&v106, 0, 0x40u);
  v39 = v92;
  if ( !v92 )
    goto LABEL_116;
  v40 = &v107;
  overridesa = (UFG::qPropertyList *)&v107;
  v41 = (UFG::qPropertyList *)&v33[19];
  textureSetLista = (UFG::qPropertyList *)&v33[19];
  v42 = (void **)&v33[3].mNode.mNext;
  v43 = 0i64;
  v93 = 0i64;
  v44 = (UFG::qPropertyList *)v92;
  lista = (UFG::qPropertyList *)v92;
  v45 = v110;
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
      v71 = v45->mComponentEntries.mOffset;
      if ( v71 )
        v72 = (signed __int64)&v45->mComponentEntries + v71;
      else
        v72 = 0i64;
      v73 = v72 + 16 * v46;
      v100 = v73;
      v74 = 0;
      if ( *(_DWORD *)v73 )
      {
        do
        {
          v75 = *(_QWORD *)(v73 + 8);
          if ( v75 )
            v76 = v73 + v75 + 8;
          else
            v76 = 0i64;
          v77 = (_QWORD *)(v76 + 96i64 * v74);
          if ( v95 == (*v77 & v95) && v38 == (v38 & v77[1]) )
          {
            v101 = (signed __int64)(v77 + 2);
            v78 = *((unsigned int *)v42 - 2);
            v79 = v78 + 1;
            v80 = *((_DWORD *)v42 - 1);
            if ( (signed int)v78 + 1 > v80 )
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
                if ( *v42 )
                {
                  v85 = 0;
                  if ( *((_DWORD *)v42 - 2) )
                  {
                    do
                    {
                      v83[v85] = *(UFG::allocator::free_link *)((char *)*v42 + 8 * v85);
                      ++v85;
                    }
                    while ( v85 < *((_DWORD *)v42 - 2) );
                  }
                  operator delete[](*v42);
                }
                *v42 = v84;
                *((_DWORD *)v42 - 1) = v81;
                v73 = v100;
                v43 = v93;
              }
            }
            *((_DWORD *)v42 - 2) = v79;
            *((_QWORD *)*v42 + v78) = v101;
            ++*(int *)((char *)&v106 + v43);
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
      v49 = (signed __int64)&v45->mComponentEntries + v48;
    else
      v49 = 0i64;
    v50 = v49 + 16 * v46;
    v51 = 0;
    if ( *(_DWORD *)v50 )
    {
      v52 = *(_QWORD *)(v50 + 8);
      while ( 1 )
      {
        v53 = v52 + v50 + 8;
        if ( !v52 )
          v53 = 0i64;
        v54 = v53 + 96i64 * v51;
        if ( v47 == *(_DWORD *)(v54 + 44) )
          break;
        if ( ++v51 >= *(_DWORD *)v50 )
          goto LABEL_112;
      }
      v55 = *((unsigned int *)v42 - 2);
      v56 = v55 + 1;
      v57 = *((_DWORD *)v42 - 1);
      if ( (signed int)v55 + 1 > v57 )
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
          if ( *v42 )
          {
            v62 = 0i64;
            if ( *((_DWORD *)v42 - 2) )
            {
              do
              {
                v60[v62] = *(UFG::allocator::free_link *)((char *)*v42 + 8 * v62);
                v62 = (unsigned int)(v62 + 1);
              }
              while ( (unsigned int)v62 < *((_DWORD *)v42 - 2) );
            }
            operator delete[](*v42);
          }
          *v42 = v61;
          *((_DWORD *)v42 - 1) = v58;
          v40 = (__int64 *)overridesa;
        }
      }
      *((_DWORD *)v42 - 2) = v56;
      *((_QWORD *)*v42 + v55) = v54 + 16;
      v43 = v93;
      ++*(int *)((char *)&v106 + v43);
      v41 = textureSetLista;
      LOBYTE(textureSetLista->mFlags) = 1;
      v63 = *(int *)((char *)v104 + v93);
      v30 = 0;
      if ( v63 == -1 )
        goto LABEL_111;
      v64 = 0;
      v65 = *(unsigned __int16 *)(v54 + 74);
      if ( !*(_WORD *)(v54 + 74) )
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
    v45 = v110;
LABEL_114:
    ++v40;
    overridesa = (UFG::qPropertyList *)v40;
    v41 = (UFG::qPropertyList *)((char *)v41 + 12);
    textureSetLista = v41;
    v9 += 80i64;
    v91 = v9;
    v43 += 4i64;
    v93 = v43;
    v42 += 2;
    v44 = (UFG::qPropertyList *)((char *)v44 - 1);
    lista = v44;
    v38 = v97;
  }
  while ( v44 );
  v33 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)v98;
  v32 = (UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *)result.mFlags[0];
  v39 = v92;
LABEL_116:
  v86 = v32->mNode.mPrev;
  v86->mNext = &v33->mNode;
  v33->mNode.mPrev = v86;
  v33->mNode.mNext = &v32->mNode;
  v32->mNode.mPrev = &v33->mNode;
  if ( LODWORD(v33[3].mNode.mNext->mPrev[1].mNext) == 1 )
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
      if ( v87 != -1 && LODWORD(v33[v87 + 3i64].mNode.mPrev) )
      {
        do
          *(_DWORD *)(*((_QWORD *)&v33[v87 + 3].mNode.mNext->mPrev + v30++) + 36i64) = 1;
        while ( v30 < LODWORD(v33[v87 + 3i64].mNode.mPrev) );
      }
    }
  }
LABEL_126:
  `eh vector destructor iterator(v104, 4ui64, 16, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(ptr, 4ui64, 16, (void (__fastcall *)(void *))_);
  return v33;
}        ++v88;
        v89 += 20;
      }
      while ( v88 < v39 );
      if ( v87 != -1 && LODWORD(v3

// File Line: 1500
// RVA: 0x4408F0
UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *__fastcall UFG::TrueCrowdDataBase::QueryDataBase(UFG::TrueCrowdDataBase *this, UFG::qPropertySet *property_set, component_StreamedResource *dataPtr)
{
  unsigned int v3; // ebx
  component_StreamedResource *v4; // rax
  UFG::qPropertySet *v5; // rsi
  UFG::TrueCrowdDataBase *v6; // rdi
  UFG::qPropertySet *v7; // rax
  UFG::qPropertyList *v8; // r10
  __int64 v9; // rcx
  UFG::qPropertyList *v10; // r11
  __int64 v11; // rcx
  UFG::qPropertyList *textureSetList; // r9
  __int64 v13; // rcx
  UFG::qPropertyList *overrides; // r8
  unsigned int v15; // ecx
  unsigned int v16; // edx
  UFG::TrueCrowdDefinition::Entity *v17; // rax

  v3 = 0;
  v4 = dataPtr;
  v5 = property_set;
  v6 = this;
  if ( !dataPtr )
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           property_set,
           (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( v7 )
      v4 = (component_StreamedResource *)UFG::qPropertySet::GetMemImagePtr(v7);
    else
      v4 = 0i64;
  }
  v8 = (UFG::qPropertyList *)((char *)v4 + v4->ResourceTags.mOffset);
  if ( !v4->ResourceTags.mOffset )
    v8 = 0i64;
  v9 = v4->ComponentList.mOffset;
  if ( v9 )
    v10 = (UFG::qPropertyList *)((char *)&v4->ComponentList + v9);
  else
    v10 = 0i64;
  v11 = v4->TextureSetList.mOffset;
  if ( v11 )
    textureSetList = (UFG::qPropertyList *)((char *)&v4->TextureSetList + v11);
  else
    textureSetList = 0i64;
  v13 = v4->ResourceList.mOffset;
  if ( v13 )
    overrides = (UFG::qPropertyList *)((char *)&v4->ResourceList + v13);
  else
    overrides = 0i64;
  v15 = v6->mDefinition.mEntityCount;
  v16 = v4->EntityType.mUID;
  if ( v15 )
  {
    v17 = v6->mDefinition.mEntities;
    while ( v17->mNameUID != v16 )
    {
      ++v3;
      ++v17;
      if ( v3 >= v15 )
        goto LABEL_20;
    }
  }
  else
  {
LABEL_20:
    v3 = -1;
  }
  return UFG::TrueCrowdDataBase::QueryCharacterDataBase(v6, v3, v8, v10, overrides, textureSetList, v5);
}

// File Line: 1520
// RVA: 0x4409E0
void __fastcall UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase *this, UFG::qPropertySet *property_set, UFG::TrueCrowdSet::Instance *instance)
{
  UFG::qPropertySet *v3; // rdi
  UFG::TrueCrowdSet::Instance *v4; // rbp
  UFG::TrueCrowdDataBase *v5; // rsi
  UFG::qPropertySet *v6; // rax
  char *v7; // rbx
  UFG::TrueCrowdSet *v8; // rsi
  unsigned int *v9; // rax
  unsigned int v10; // eax
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::OverrideForceParams ofp; // [rsp+20h] [rbp-18h]

  v3 = property_set;
  v4 = instance;
  v5 = this;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         property_set,
         (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v7 = 0i64;
  v8 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(v5, v3, (component_StreamedResource *)v7);
  if ( v8 )
  {
    ofp.mColorTintIndex = 0;
    ofp.mBMIMin = FLOAT_N1_0;
    LODWORD(ofp.mBMIMax) = (_DWORD)FLOAT_1_0;
    v9 = (unsigned int *)UFG::qPropertySet::Get<long>(v3, (UFG::qSymbol *)&qSymbol_ColorTintIndex.mUID, DEPTH_RECURSE);
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
            v3,
            (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
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
    UFG::TrueCrowdSet::SelectInstance(v8, v4, &ofp, *((UFG::TrueCrowdSet::SelectionFlags *)v7 + 9));
  }
}

// File Line: 1535
// RVA: 0x440B10
UFG::TrueCrowdModel *__fastcall UFG::TrueCrowdDataBase::QueryModelFromPath(UFG::TrueCrowdDataBase *this, unsigned int entityIndex, unsigned int componentIndex, UFG::qSymbol *pathSymbol)
{
  __int64 v4; // rax
  UFG::qSymbol *v5; // rbx
  __int64 v6; // r8
  signed __int64 v7; // rcx
  unsigned int v8; // eax
  unsigned int v9; // er10
  __int64 v10; // r9
  unsigned int v11; // ebx
  signed __int64 v12; // r11
  __int64 v13; // rcx
  signed __int64 v14; // rdx

  v4 = this->mComponentEntries.mOffset;
  v5 = pathSymbol;
  v6 = componentIndex;
  if ( v4 )
    v4 += (__int64)&this->mComponentEntries;
  v7 = v4
     + 16i64
     * UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[entityIndex].mComponents[v6].mResourceIndex;
  v8 = 0;
  v9 = *(_DWORD *)v7;
  if ( !*(_DWORD *)v7 )
    return 0i64;
  v10 = *(_QWORD *)(v7 + 8);
  v11 = v5->mUID;
  v12 = v7 + 8;
  v13 = 0i64;
  while ( 1 )
  {
    v14 = v10 ? v10 + v12 : 0i64;
    if ( *(_DWORD *)(v13 + v14 + 44) == v11 )
      break;
    ++v8;
    v13 += 96i64;
    if ( v8 >= v9 )
      return 0i64;
  }
  return (UFG::TrueCrowdModel *)(v13 + v14 + 16);
}

// File Line: 1565
// RVA: 0x440BB0
char __fastcall UFG::TrueCrowdDataBase::QueryPreloadedInstance(UFG::TrueCrowdDataBase *this, UFG::qPropertySet *property_set, UFG::TrueCrowdSet::Instance *instance)
{
  UFG::TrueCrowdSet::Instance *v3; // r12
  UFG::qPropertySet *v4; // rdi
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v6; // rax
  unsigned int v7; // ebx
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v8; // rbp
  char v9; // r13
  unsigned int v10; // er15
  __int64 v11; // r8
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v12; // rdx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  signed __int64 v16; // rcx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v17; // rax
  __int64 v18; // rax
  unsigned int v19; // edi
  unsigned int v20; // esi
  __int64 v21; // r10
  __int64 v22; // rax
  unsigned int v23; // edx
  __int64 v24; // r9
  __int64 v25; // r8
  signed __int64 v26; // rax
  signed __int64 v27; // rcx
  __int64 v28; // rax
  signed __int64 v29; // rax
  __int64 v30; // rax
  unsigned int *v31; // rax
  unsigned int v32; // eax
  UFG::qPropertySet *v33; // rax
  char *v34; // rax
  float v35; // xmm0_4
  float v36; // xmm1_4
  UFG::TrueCrowdSet *v37; // rdi
  unsigned int v38; // ecx
  int v39; // eax
  UFG::ModelTextureCombination *v40; // r8
  UFG::OverrideForceParams ofp; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v42; // [rsp+78h] [rbp+10h]
  unsigned int v43; // [rsp+80h] [rbp+18h]

  v42 = property_set;
  v3 = instance;
  v4 = property_set;
  if ( !instance )
    return 0;
  v6 = UFG::TrueCrowdDataBase::QueryDataBase(this, property_set, 0i64);
  v7 = 0;
  v3->mSet = (UFG::TrueCrowdSet *)v6;
  v8 = v6;
  v9 = 1;
  v10 = 0;
  v43 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[HIDWORD(v6[2].mNode.mPrev)].mComponentCount;
  v3->mNumParts = v43;
  if ( !v43 )
    goto LABEL_36;
  do
  {
    if ( *((_BYTE *)&v8[19].mNode.mPrev + 12 * v10) && *((_BYTE *)&v8[19].mNode.mPrev + 12 * v10 + 1) )
    {
      v11 = *((unsigned int *)&v8[19].mNode.mPrev + 3 * v10 + 1);
      v12 = v8[v10 + 3].mNode.mNext->mPrev;
      v13 = v12[4].mNext;
      if ( v13 )
        v14 = (signed __int64)&v12[4].mNext + (_QWORD)v13;
      else
        v14 = 0i64;
      v15 = *(_QWORD *)(v14 + 8 * v11);
      v16 = v15 + v14 + 8 * v11;
      if ( !v15 )
        v16 = 0i64;
      v17 = v12->mNext;
      if ( !v17 || HIDWORD(v17[1].mPrev) != 3 || (v18 = *(_QWORD *)(v16 + 8)) == 0 || *(_DWORD *)(v18 + 20) != 3 )
      {
        v9 = 0;
        v3->mSet = 0i64;
        v3->mNumParts = 0;
        return v9;
      }
    }
    else
    {
      v19 = 0;
      v20 = (unsigned int)v8[v10 + 3i64].mNode.mPrev;
      if ( v20 )
      {
        while ( 1 )
        {
          v21 = *((_QWORD *)&v8[v10 + 3].mNode.mNext->mPrev + v19);
          v22 = *(_QWORD *)(v21 + 8);
          if ( v22 )
          {
            if ( *(_DWORD *)(v22 + 20) == 3 )
            {
              v23 = 0;
              if ( *(_WORD *)(v21 + 58) )
                break;
            }
          }
LABEL_30:
          if ( ++v19 >= v20 )
            goto LABEL_31;
        }
        v24 = *(_QWORD *)(v21 + 72);
        v25 = 0i64;
        while ( 1 )
        {
          v26 = v24 ? v24 + v21 + 72 : 0i64;
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
          if ( v23 >= *(unsigned __int16 *)(v21 + 58) )
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
  while ( v10 < v43 );
  if ( v9 )
  {
    v4 = v42;
LABEL_36:
    ofp.mColorTintIndex = 0;
    ofp.mBMIMin = FLOAT_N1_0;
    LODWORD(ofp.mBMIMax) = (_DWORD)FLOAT_1_0;
    v31 = (unsigned int *)UFG::qPropertySet::Get<long>(v4, (UFG::qSymbol *)&qSymbol_ColorTintIndex.mUID, DEPTH_RECURSE);
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
            (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v33 && (v34 = UFG::qPropertySet::GetMemImagePtr(v33)) != 0i64 )
    {
      v35 = *((float *)v34 + 10);
      v36 = *((float *)v34 + 11);
      ofp.mBMIValid = 1;
      ofp.mBMIMin = v35;
      ofp.mBMIMax = v36;
    }
    else
    {
      ofp.mBMIValid = 0;
    }
    v37 = v3->mSet;
    v38 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v3->mSet->mEntityIndex].mComponentCount;
    v3->mNumParts = v38;
    if ( v38 )
    {
      do
      {
        if ( v37->mComponentDetails[v7].mbSpecificModel )
        {
          UFG::TrueCrowdSet::ChooseSpecificModel(v37, v7, &v3->mPart[v7], &ofp);
        }
        else
        {
          v39 = UFG::TrueCrowdSet::GetNumModelsLoaded(v37);
          v40 = &v3->mPart[v7];
          if ( v39 )
            UFG::TrueCrowdSet::ChooseLeastCommonModel(v37, v7, v40, &ofp);
          else
            UFG::TrueCrowdSet::ChooseRandomModel(v37, v7, v40, &ofp);
        }
        ++v7;
      }
      while ( v7 < v3->mNumParts );
    }
    UFG::OverrideForceParams::GetMorphWeightsFromBMI(&ofp, v3->mMorphWeights);
    return v9;
  }
  v3->mSet = 0i64;
  v3->mNumParts = 0;
  return v9;
}

