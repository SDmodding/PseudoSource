// File Line: 19
// RVA: 0x41BA90
void __fastcall UFG::TurfBlockInstance::Init(UFG::TurfBlockInstance *this, unsigned int turfBlockID)
{
  unsigned int v2; // edi
  UFG::TurfBlockInstance *v3; // rbx
  UFG::TurfBlockInstanceData *v4; // rax
  UFG::TurfInstanceData *v5; // rax
  UFG::qReflectHandle<UFG::TurfTemplate> *v6; // rax
  UFG::qReflectHandle<UFG::TurfTemplate> result; // [rsp+28h] [rbp-30h]

  v2 = turfBlockID;
  v3 = this;
  v4 = UFG::PlaceholderGameDB::GetTurfBlockInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, turfBlockID);
  v3->mData = v4;
  if ( v4 )
  {
    v5 = UFG::PlaceholderGameDB::GetTurfInstanceDataForBlockId(UFG::PlaceholderGameDB::ms_pSingleton, v2);
    v3->mTurfData = v5;
    if ( v5 )
    {
      v6 = UFG::TurfManager::GetTurfTemplate(&result, v5->templateName.mData);
      UFG::qReflectHandleBase::operator=(
        (UFG::qReflectHandleBase *)&v3->mTurfTemplate.mPrev,
        (UFG::qReflectHandleBase *)&v6->mPrev);
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
    }
  }
}

// File Line: 49
// RVA: 0x41B9A0
__int64 __fastcall UFG::TurfBlockInstance::Index(UFG::TurfBlockInstance *this)
{
  UFG::TurfBlockInstance *v1; // rsi
  UFG::TurfInstanceData *v2; // rdi
  unsigned int v3; // ebx
  unsigned int *v4; // rdi

  v1 = this;
  if ( !this->mData )
    return 0i64;
  v2 = this->mTurfData;
  if ( !v2 || !this->mTurfTemplate.mData )
    return 0i64;
  v3 = 0;
  v4 = v2->blockId;
  while ( *v4 != (unsigned int)UFG::TurfBlockInstance::ID(v1) )
  {
    ++v3;
    ++v4;
    if ( v3 >= 8 )
      return 0i64;
  }
  return v3;
}

// File Line: 83
// RVA: 0x41B7D0
void __fastcall UFG::TurfBlockInstance::GridPosition(UFG::TurfBlockInstance *this, UFG::qVector2 *outPosition)
{
  UFG::qVector2 *v2; // r14
  UFG::TurfBlockInstance *v3; // rsi
  UFG::TurfInstanceData *v4; // rdi
  UFG::qReflectObject *v5; // rbx
  UFG::qReflectObject *v6; // r15
  unsigned int v7; // ebp
  unsigned int *v8; // rdi
  unsigned int v9; // ebx

  v2 = outPosition;
  v3 = this;
  if ( this->mData )
  {
    v4 = this->mTurfData;
    if ( v4 )
    {
      v5 = this->mTurfTemplate.mData;
      if ( v5 && LODWORD(v5[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * UFG::TurfBlockInstance::Index(this)]) == 3 )
      {
        v2->y = 2.0;
        v2->x = 0.0;
      }
      else if ( v4 )
      {
        v6 = v3->mTurfTemplate.mData;
        if ( v6 )
        {
          v7 = 0;
          v8 = v4->blockId;
          v9 = 0;
          while ( *v8 != UFG::TurfBlockInstance::ID(v3) )
          {
            ++v9;
            ++v8;
            if ( v9 >= 8 )
              goto LABEL_13;
          }
          v7 = v9;
LABEL_13:
          v2->x = *((float *)&v6[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v7] + 1);
          v2->y = *(float *)&v3->mTurfTemplate.mData[1].mBaseNode.mNeighbours[1][1].mNeighbours[13
                                                                                              * UFG::TurfBlockInstance::Index(v3)
                                                                                              + 1];
        }
      }
    }
  }
}

// File Line: 122
// RVA: 0x41C5C0
float __fastcall UFG::TurfBlockInstance::Rotation(UFG::TurfBlockInstance *this)
{
  UFG::TurfBlockInstanceData *v1; // rbp
  int v2; // edi
  UFG::TurfBlockInstance *v3; // rbx
  UFG::TurfInstanceData *v4; // rsi
  UFG::qReflectObject *v5; // r14
  UFG::qReflectObject *v7; // rsi
  int v8; // esi
  UFG::qReflectObject *v9; // r14
  UFG::qReflectObject *v10; // rbp

  v1 = this->mData;
  v2 = 0;
  v3 = this;
  if ( !this->mData )
    goto LABEL_33;
  v4 = this->mTurfData;
  if ( !v4 )
    goto LABEL_33;
  v5 = this->mTurfTemplate.mData;
  if ( v5
    && LODWORD(v5[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * (unsigned int)UFG::TurfBlockInstance::Index(this)]) == 3 )
  {
    return 0.0;
  }
  if ( v4 && (v7 = v3->mTurfTemplate.mData) != 0i64 )
    v8 = *((_DWORD *)&v7[1].mBaseNode.mNeighbours[1][2].mUID + 26 * (unsigned int)UFG::TurfBlockInstance::Index(v3));
  else
LABEL_33:
    v8 = 0;
  if ( v1 )
  {
    if ( v3->mTurfData )
    {
      v9 = v3->mTurfTemplate.mData;
      if ( v9 )
        v2 = *((_DWORD *)&v9[1].mBaseNode.mNeighbours[1][2].mUID
             + 26 * (unsigned int)UFG::TurfBlockInstance::Index(v3)
             + 1);
    }
    if ( v1 )
    {
      if ( v3->mTurfData )
      {
        v10 = v3->mTurfTemplate.mData;
        if ( v10 )
        {
          if ( LODWORD(v10[1].mBaseNode.mNeighbours[1][1].mNeighbours[13
                                                                    * (unsigned int)UFG::TurfBlockInstance::Index(v3)]) == 1 )
          {
            if ( v8 != 1 && v8 != 4 && v2 != 1 && v2 != 4 )
              return 0.0;
            return FLOAT_3_1415927;
          }
        }
      }
    }
  }
  if ( v8 == 1 )
  {
    if ( v2 == 4 )
      return FLOAT_3_1415927;
    return FLOAT_N1_5707964;
  }
  if ( v2 == 1 )
    return FLOAT_N1_5707964;
  if ( v8 != 4 && v2 != 4 )
    return 0.0;
  return FLOAT_1_5707964;
}

// File Line: 333
// RVA: 0x41BF50
void __fastcall UFG::TurfBlockInstance::PopulateEmptyLots(UFG::TurfBlockInstance *this)
{
  UFG::TurfBlockInstance *v1; // rbx
  UFG::TurfBlockInstanceData *v2; // r14
  UFG::TurfInstanceData *v3; // rsi
  UFG::qReflectObject *v4; // r15
  unsigned int v5; // edi
  unsigned int *v6; // rsi
  int v7; // edx
  unsigned int v8; // edi
  int v9; // edx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v10; // rcx
  const char *v11; // rax
  UFG::RacketInstanceData *v12; // rax
  UFG::qReflectHandle<UFG::RacketType> *v13; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  UFG::RacketInstanceData *v16; // rax
  UFG::qReflectHandle<UFG::RacketType> *v17; // rax
  int v18; // eax
  UFG::qReflectHandleBase *v19; // rcx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v20; // rcx
  const char *v21; // rax
  UFG::RacketInstanceData *v22; // rax
  UFG::qReflectHandle<UFG::RacketType> *v23; // rax
  UFG::RacketInstanceData *v24; // [rsp+20h] [rbp-B8h]
  UFG::RacketInstanceData *v25; // [rsp+20h] [rbp-B8h]
  UFG::RacketInstanceData *v26; // [rsp+20h] [rbp-B8h]
  UFG::qReflectHandleBase v27; // [rsp+28h] [rbp-B0h]
  UFG::TurfBlockInstanceData *v28; // [rsp+50h] [rbp-88h]
  UFG::qReflectHandle<UFG::RacketType> result; // [rsp+58h] [rbp-80h]
  __int64 v30; // [rsp+90h] [rbp-48h]
  UFG::RacketInstance v31; // [rsp+A0h] [rbp-38h]
  __int64 v32; // [rsp+D8h] [rbp+0h]
  void *v33; // [rsp+118h] [rbp+40h]

  v32 = -2i64;
  v1 = this;
  v2 = this->mData;
  if ( this->mData )
  {
    v3 = this->mTurfData;
    if ( v3 )
    {
      v4 = this->mTurfTemplate.mData;
      if ( v4 )
      {
        v5 = 0;
        v6 = v3->blockId;
        while ( *v6 != (unsigned int)UFG::TurfBlockInstance::ID(v1) )
        {
          ++v5;
          ++v6;
          if ( v5 >= 8 )
          {
            v5 = 0;
            break;
          }
        }
        v7 = (int)v4[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v5];
        v8 = v2->racketId[0];
        v33 = &v27;
        v9 = v7 - 1;
        if ( !v9 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v27);
          v21 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v20);
          v27.mTypeUID = UFG::qStringHash64(v21, 0xFFFFFFFFFFFFFFFFui64);
          v28 = 0i64;
          v22 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          v26 = v22;
          if ( v22 )
          {
            v23 = UFG::TurfManager::GetRacketType(&result, v22->type.mData);
            UFG::qReflectHandleBase::operator=(&v27, (UFG::qReflectHandleBase *)&v23->mPrev);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
          }
          v28 = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          if ( v26 && v27.mData )
          {
            if ( !LODWORD(v27.mData[1].vfptr) )
            {
              UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result.mTypeUID, v1->mData->racketId[1]);
              if ( !result.mTypeUID || !v30 )
                v1->mData->racketId[1] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, 0);
              v33 = &result.mNameUID;
              UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mNameUID);
            }
          }
          else
          {
            v1->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, MEDIUM);
          }
          v33 = &v27;
          goto LABEL_68;
        }
        if ( v9 != 1 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v27);
          v11 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v10);
          v27.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
          v28 = 0i64;
          v12 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          v24 = v12;
          if ( v12 )
          {
            v13 = UFG::TurfManager::GetRacketType(&result, v12->type.mData);
            UFG::qReflectHandleBase::operator=(&v27, (UFG::qReflectHandleBase *)&v13->mPrev);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
          }
          v28 = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          if ( !v24 || !v27.mData )
            v1->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, 0);
          v33 = &v27;
          goto LABEL_68;
        }
        UFG::qReflectHandleBase::qReflectHandleBase(&v27);
        v15 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v14);
        v27.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
        v28 = 0i64;
        v16 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
        v25 = v16;
        if ( v16 )
        {
          v17 = UFG::TurfManager::GetRacketType(&result, v16->type.mData);
          UFG::qReflectHandleBase::operator=(&v27, (UFG::qReflectHandleBase *)&v17->mPrev);
          UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
        }
        v28 = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB::ms_pSingleton, v8);
        if ( v25 && v27.mData )
        {
          v18 = (int)v27.mData[1].vfptr;
          if ( v18 != 2 )
          {
            if ( v18 == 1 )
            {
              UFG::RacketInstance::RacketInstance(&v31, v1->mData->racketId[2]);
              if ( v31.mData && v31.mType.mData )
              {
                if ( !LODWORD(v31.mType.mData[1].vfptr) )
                {
                  UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result, v1->mData->racketId[3]);
                  if ( !result.mPrev || !result.mPrev )
                    v1->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, 0);
                  v33 = &result.mNext;
                  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mNext);
                }
              }
              else
              {
                v1->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, MEDIUM);
              }
              v33 = &v31.mType;
LABEL_54:
              v19 = (UFG::qReflectHandleBase *)&v31.mType.mPrev;
LABEL_55:
              UFG::qReflectHandleBase::~qReflectHandleBase(v19);
              goto LABEL_56;
            }
            if ( !v18 )
            {
              UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result.mTypeUID, v1->mData->racketId[1]);
              if ( !result.mTypeUID || !v30 )
                v1->mData->racketId[1] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, 0);
              UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result, v1->mData->racketId[2]);
              if ( result.mPrev )
              {
                if ( !LODWORD(result.mPrev[5].mPrev) )
                {
                  UFG::RacketInstance::RacketInstance(&v31, v1->mData->racketId[3]);
                  if ( !v31.mData || !v31.mType.mData )
                    v1->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, 0);
                  v33 = &v31.mType;
                  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v31.mType.mPrev);
                }
              }
              else
              {
                v1->mData->racketId[2] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, MEDIUM);
              }
              v33 = &result.mNext;
              UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mNext);
              v33 = &result.mNameUID;
              v19 = (UFG::qReflectHandleBase *)&result.mNameUID;
              goto LABEL_55;
            }
          }
        }
        else
        {
          if ( v1->mData->racketId[2] != -1 )
          {
            v1->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, MEDIUM);
            UFG::RacketInstance::RacketInstance(&v31, v1->mData->racketId[2]);
            if ( v31.mData && v31.mType.mData )
            {
              if ( !LODWORD(v31.mType.mData[1].vfptr) )
              {
                UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result.mTypeUID, v1->mData->racketId[3]);
                if ( !result.mTypeUID || !v30 )
                  v1->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, 0);
                v33 = &result.mNameUID;
                UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mNameUID);
              }
            }
            else
            {
              v1->mData->racketId[2] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, MEDIUM);
            }
            v33 = &v31.mType;
            goto LABEL_54;
          }
          v1->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(v1, LARGE);
        }
LABEL_56:
        v33 = &v27;
LABEL_68:
        UFG::qReflectHandleBase::~qReflectHandleBase(&v27);
        return;
      }
    }
  }
}

// File Line: 703
// RVA: 0x41A830
__int64 __fastcall UFG::TurfBlockInstance::CreateEmptyLotRacket(UFG::TurfBlockInstance *this, UFG::RacketType::eSize size)
{
  UFG::RacketType::eSize v2; // ebx
  UFG::TurfManager *v3; // rax
  UFG::qReflectObject *v4; // rbx
  char *v5; // rax
  UFG::qReflectHandle<UFG::RacketType> result; // [rsp+28h] [rbp-30h]

  v2 = size;
  v3 = UFG::TurfManager::Instance();
  v4 = UFG::TurfManager::GetRandomEmptyRacketType(v3, &result, v2)->mData;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
  v5 = UFG::qReflectObject::GetName(v4);
  return UFG::PlaceholderGameDB::CreateNewRacket(v5);
}

