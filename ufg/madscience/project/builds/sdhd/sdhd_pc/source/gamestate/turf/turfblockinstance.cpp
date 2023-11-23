// File Line: 19
// RVA: 0x41BA90
void __fastcall UFG::TurfBlockInstance::Init(UFG::TurfBlockInstance *this, unsigned int turfBlockID)
{
  UFG::TurfBlockInstanceData *TurfBlockInstanceData; // rax
  UFG::TurfInstanceData *TurfInstanceDataForBlockId; // rax
  UFG::qReflectHandleBase *TurfTemplate; // rax
  _BYTE result[48]; // [rsp+28h] [rbp-30h] BYREF

  TurfBlockInstanceData = UFG::PlaceholderGameDB::GetTurfBlockInstanceData(
                            UFG::PlaceholderGameDB::ms_pSingleton,
                            turfBlockID);
  this->mData = TurfBlockInstanceData;
  if ( TurfBlockInstanceData )
  {
    TurfInstanceDataForBlockId = UFG::PlaceholderGameDB::GetTurfInstanceDataForBlockId(
                                   UFG::PlaceholderGameDB::ms_pSingleton,
                                   turfBlockID);
    this->mTurfData = TurfInstanceDataForBlockId;
    if ( TurfInstanceDataForBlockId )
    {
      TurfTemplate = (UFG::qReflectHandleBase *)UFG::TurfManager::GetTurfTemplate(
                                                  (UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *)result,
                                                  TurfInstanceDataForBlockId->templateName.mData);
      UFG::qReflectHandleBase::operator=(&this->mTurfTemplate, TurfTemplate);
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)result);
    }
  }
}

// File Line: 49
// RVA: 0x41B9A0
__int64 __fastcall UFG::TurfBlockInstance::Index(UFG::TurfBlockInstance *this)
{
  UFG::TurfInstanceData *mTurfData; // rdi
  unsigned int v3; // ebx
  unsigned int *i; // rdi

  if ( !this->mData )
    return 0i64;
  mTurfData = this->mTurfData;
  if ( !mTurfData || !this->mTurfTemplate.mData )
    return 0i64;
  v3 = 0;
  for ( i = mTurfData->blockId; *i != (unsigned int)UFG::TurfBlockInstance::ID(this); ++i )
  {
    if ( ++v3 >= 8 )
      return 0i64;
  }
  return v3;
}

// File Line: 83
// RVA: 0x41B7D0
void __fastcall UFG::TurfBlockInstance::GridPosition(UFG::TurfBlockInstance *this, UFG::qVector2 *outPosition)
{
  UFG::TurfInstanceData *mTurfData; // rdi
  UFG::qReflectObject *mData; // rbx
  UFG::qReflectObject *v6; // r15
  unsigned int v7; // ebp
  unsigned int *blockId; // rdi
  unsigned int v9; // ebx

  if ( this->mData )
  {
    mTurfData = this->mTurfData;
    if ( mTurfData )
    {
      mData = this->mTurfTemplate.mData;
      if ( mData
        && LODWORD(mData[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * UFG::TurfBlockInstance::Index(this)]) == 3 )
      {
        outPosition->y = 2.0;
        outPosition->x = 0.0;
      }
      else
      {
        v6 = this->mTurfTemplate.mData;
        if ( v6 )
        {
          v7 = 0;
          blockId = mTurfData->blockId;
          v9 = 0;
          while ( *blockId != UFG::TurfBlockInstance::ID(this) )
          {
            ++v9;
            ++blockId;
            if ( v9 >= 8 )
              goto LABEL_12;
          }
          v7 = v9;
LABEL_12:
          outPosition->x = *((float *)&v6[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v7] + 1);
          outPosition->y = *(float *)&this->mTurfTemplate.mData[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * UFG::TurfBlockInstance::Index(this) + 1];
        }
      }
    }
  }
}

// File Line: 122
// RVA: 0x41C5C0
float __fastcall UFG::TurfBlockInstance::Rotation(UFG::TurfBlockInstance *this)
{
  UFG::TurfBlockInstanceData *mData; // rbp
  int v2; // edi
  UFG::qReflectObject *v4; // r14
  UFG::qReflectObject *v6; // rsi
  int v7; // esi
  UFG::qReflectObject *v8; // r14
  UFG::qReflectObject *v9; // rbp

  mData = this->mData;
  v2 = 0;
  if ( !this->mData || !this->mTurfData )
    goto LABEL_8;
  v4 = this->mTurfTemplate.mData;
  if ( v4
    && LODWORD(v4[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * (unsigned int)UFG::TurfBlockInstance::Index(this)]) == 3 )
  {
    return 0.0;
  }
  v6 = this->mTurfTemplate.mData;
  if ( v6 )
    v7 = *((_DWORD *)&v6[1].mBaseNode.mNeighbours[1][2].mUID + 26 * (unsigned int)UFG::TurfBlockInstance::Index(this));
  else
LABEL_8:
    v7 = 0;
  if ( mData )
  {
    if ( this->mTurfData )
    {
      v8 = this->mTurfTemplate.mData;
      if ( v8 )
        v2 = *((_DWORD *)&v8[1].mBaseNode.mNeighbours[1][2].mUID
             + 26 * (unsigned int)UFG::TurfBlockInstance::Index(this)
             + 1);
    }
    if ( this->mTurfData )
    {
      v9 = this->mTurfTemplate.mData;
      if ( v9 )
      {
        if ( LODWORD(v9[1].mBaseNode.mNeighbours[1][1].mNeighbours[13
                                                                 * (unsigned int)UFG::TurfBlockInstance::Index(this)]) == 1 )
        {
          if ( v7 != 1 && v7 != 4 && v2 != 1 && v2 != 4 )
            return 0.0;
          return FLOAT_3_1415927;
        }
      }
    }
  }
  if ( v7 == 1 )
  {
    if ( v2 == 4 )
      return FLOAT_3_1415927;
    return FLOAT_N1_5707964;
  }
  if ( v2 == 1 )
    return FLOAT_N1_5707964;
  if ( v7 != 4 && v2 != 4 )
    return 0.0;
  return FLOAT_1_5707964;
}

// File Line: 333
// RVA: 0x41BF50
void __fastcall UFG::TurfBlockInstance::PopulateEmptyLots(UFG::TurfBlockInstance *this)
{
  UFG::TurfBlockInstanceData *mData; // r14
  UFG::TurfInstanceData *mTurfData; // rsi
  UFG::qReflectObject *v4; // r15
  unsigned int v5; // edi
  unsigned int *blockId; // rsi
  int v7; // edx
  unsigned int v8; // edi
  int v9; // edx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v10; // rcx
  const char *v11; // rax
  UFG::RacketInstanceData *v12; // rax
  UFG::qReflectHandleBase *v13; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  UFG::RacketInstanceData *v16; // rax
  UFG::qReflectHandleBase *v17; // rax
  int vfptr; // eax
  UFG::qReflectHandleBase *p_mType; // rcx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v20; // rcx
  const char *TypeName; // rax
  UFG::RacketInstanceData *RacketInstanceData; // rax
  UFG::qReflectHandleBase *RacketType; // rax
  UFG::RacketInstanceData *v24; // [rsp+20h] [rbp-B8h]
  UFG::RacketInstanceData *v25; // [rsp+20h] [rbp-B8h]
  UFG::RacketInstanceData *v26; // [rsp+20h] [rbp-B8h]
  UFG::qReflectHandleBase v27; // [rsp+28h] [rbp-B0h] BYREF
  UFG::TurfBlockInstanceData *TurfBlockInstanceDataForRacketId; // [rsp+50h] [rbp-88h]
  UFG::RacketInstance result; // [rsp+58h] [rbp-80h] BYREF
  __int64 v30; // [rsp+90h] [rbp-48h]
  UFG::RacketInstance v31; // [rsp+A0h] [rbp-38h] BYREF
  __int64 v32; // [rsp+D8h] [rbp+0h]
  void *p_mTypeUID; // [rsp+118h] [rbp+40h]

  v32 = -2i64;
  mData = this->mData;
  if ( this->mData )
  {
    mTurfData = this->mTurfData;
    if ( mTurfData )
    {
      v4 = this->mTurfTemplate.mData;
      if ( v4 )
      {
        v5 = 0;
        blockId = mTurfData->blockId;
        while ( *blockId != (unsigned int)UFG::TurfBlockInstance::ID(this) )
        {
          ++v5;
          ++blockId;
          if ( v5 >= 8 )
          {
            v5 = 0;
            break;
          }
        }
        v7 = (int)v4[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v5];
        v8 = mData->racketId[0];
        p_mTypeUID = &v27;
        v9 = v7 - 1;
        if ( !v9 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v27);
          TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v20);
          v27.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
          TurfBlockInstanceDataForRacketId = 0i64;
          RacketInstanceData = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          v26 = RacketInstanceData;
          if ( RacketInstanceData )
          {
            RacketType = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                                      (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&result,
                                                      RacketInstanceData->type.mData);
            UFG::qReflectHandleBase::operator=(&v27, RacketType);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result);
          }
          TurfBlockInstanceDataForRacketId = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                               UFG::PlaceholderGameDB::ms_pSingleton,
                                               v8);
          if ( v26 && v27.mData )
          {
            if ( !LODWORD(v27.mData[1].vfptr) )
            {
              UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result.mType.mNext, this->mData->racketId[1]);
              if ( !result.mType.mNext || !v30 )
                this->mData->racketId[1] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, SMALL);
              p_mTypeUID = &result.mType.mTypeUID;
              UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mType.mTypeUID);
            }
          }
          else
          {
            this->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, MEDIUM);
          }
          p_mTypeUID = &v27;
          goto LABEL_67;
        }
        if ( v9 != 1 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v27);
          v11 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v10);
          v27.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
          TurfBlockInstanceDataForRacketId = 0i64;
          v12 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          v24 = v12;
          if ( v12 )
          {
            v13 = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                               (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&result,
                                               v12->type.mData);
            UFG::qReflectHandleBase::operator=(&v27, v13);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result);
          }
          TurfBlockInstanceDataForRacketId = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                               UFG::PlaceholderGameDB::ms_pSingleton,
                                               v8);
          if ( !v24 || !v27.mData )
            this->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, SMALL);
          p_mTypeUID = &v27;
          goto LABEL_67;
        }
        UFG::qReflectHandleBase::qReflectHandleBase(&v27);
        v15 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v14);
        v27.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
        TurfBlockInstanceDataForRacketId = 0i64;
        v16 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
        v25 = v16;
        if ( v16 )
        {
          v17 = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                             (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&result,
                                             v16->type.mData);
          UFG::qReflectHandleBase::operator=(&v27, v17);
          UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result);
        }
        TurfBlockInstanceDataForRacketId = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                             UFG::PlaceholderGameDB::ms_pSingleton,
                                             v8);
        if ( v25 && v27.mData )
        {
          vfptr = (int)v27.mData[1].vfptr;
          if ( vfptr != 2 )
          {
            if ( vfptr == 1 )
            {
              UFG::RacketInstance::RacketInstance(&v31, this->mData->racketId[2]);
              if ( v31.mData && v31.mType.mData )
              {
                if ( !LODWORD(v31.mType.mData[1].vfptr) )
                {
                  UFG::RacketInstance::RacketInstance(&result, this->mData->racketId[3]);
                  if ( !result.mData )
                    this->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, SMALL);
                  p_mTypeUID = &result.mType;
                  UFG::qReflectHandleBase::~qReflectHandleBase(&result.mType);
                }
              }
              else
              {
                this->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, MEDIUM);
              }
              p_mTypeUID = &v31.mType;
LABEL_53:
              p_mType = &v31.mType;
LABEL_54:
              UFG::qReflectHandleBase::~qReflectHandleBase(p_mType);
              goto LABEL_55;
            }
            if ( !vfptr )
            {
              UFG::RacketInstance::RacketInstance((UFG::RacketInstance *)&result.mType.mNext, this->mData->racketId[1]);
              if ( !result.mType.mNext || !v30 )
                this->mData->racketId[1] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, SMALL);
              UFG::RacketInstance::RacketInstance(&result, this->mData->racketId[2]);
              if ( result.mData )
              {
                if ( !LODWORD(result.mData[1].type.mPrev) )
                {
                  UFG::RacketInstance::RacketInstance(&v31, this->mData->racketId[3]);
                  if ( !v31.mData || !v31.mType.mData )
                    this->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, SMALL);
                  p_mTypeUID = &v31.mType;
                  UFG::qReflectHandleBase::~qReflectHandleBase(&v31.mType);
                }
              }
              else
              {
                this->mData->racketId[2] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, MEDIUM);
              }
              p_mTypeUID = &result.mType;
              UFG::qReflectHandleBase::~qReflectHandleBase(&result.mType);
              p_mTypeUID = &result.mType.mTypeUID;
              p_mType = (UFG::qReflectHandleBase *)&result.mType.mTypeUID;
              goto LABEL_54;
            }
          }
        }
        else
        {
          if ( this->mData->racketId[2] != -1 )
          {
            this->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, MEDIUM);
            UFG::RacketInstance::RacketInstance(&v31, this->mData->racketId[2]);
            if ( v31.mData && v31.mType.mData )
            {
              if ( !LODWORD(v31.mType.mData[1].vfptr) )
              {
                UFG::RacketInstance::RacketInstance(
                  (UFG::RacketInstance *)&result.mType.mNext,
                  this->mData->racketId[3]);
                if ( !result.mType.mNext || !v30 )
                  this->mData->racketId[3] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, SMALL);
                p_mTypeUID = &result.mType.mTypeUID;
                UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mType.mTypeUID);
              }
            }
            else
            {
              this->mData->racketId[2] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, MEDIUM);
            }
            p_mTypeUID = &v31.mType;
            goto LABEL_53;
          }
          this->mData->racketId[0] = UFG::TurfBlockInstance::CreateEmptyLotRacket(this, LARGE);
        }
LABEL_55:
        p_mTypeUID = &v27;
LABEL_67:
        UFG::qReflectHandleBase::~qReflectHandleBase(&v27);
      }
    }
  }
}

// File Line: 703
// RVA: 0x41A830
__int64 __fastcall UFG::TurfBlockInstance::CreateEmptyLotRacket(
        UFG::TurfBlockInstance *this,
        UFG::RacketType::eSize size)
{
  UFG::TurfManager *v3; // rax
  UFG::qReflectObject *mData; // rbx
  char *Name; // rax
  UFG::qReflectHandle<UFG::RacketType> result; // [rsp+28h] [rbp-30h] BYREF

  v3 = UFG::TurfManager::Instance();
  mData = UFG::TurfManager::GetRandomEmptyRacketType(v3, &result, size)->mData;
  UFG::qReflectHandleBase::~qReflectHandleBase(&result);
  Name = UFG::qReflectObject::GetName(mData);
  return UFG::PlaceholderGameDB::CreateNewRacket(Name);
}

