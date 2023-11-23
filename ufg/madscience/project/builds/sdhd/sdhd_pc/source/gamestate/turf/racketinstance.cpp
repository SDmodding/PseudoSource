// File Line: 25
// RVA: 0x41BA20
void __fastcall UFG::RacketInstance::Init(UFG::RacketInstance *this, unsigned int racketID)
{
  UFG::RacketInstanceData *RacketInstanceData; // rax
  UFG::qReflectHandleBase *RacketType; // rax
  _BYTE result[48]; // [rsp+28h] [rbp-30h] BYREF

  RacketInstanceData = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, racketID);
  this->mData = RacketInstanceData;
  if ( RacketInstanceData )
  {
    RacketType = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                              (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)result,
                                              RacketInstanceData->type.mData);
    UFG::qReflectHandleBase::operator=(&this->mType, RacketType);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)result);
  }
  this->mContainingBlock = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                             UFG::PlaceholderGameDB::ms_pSingleton,
                             racketID);
}

// File Line: 44
// RVA: 0x41B8F0
__int64 __fastcall UFG::RacketInstance::Index(UFG::RacketInstance *this)
{
  unsigned int v2; // ebx
  unsigned int *racketId; // rdi
  unsigned int v4; // ebp
  unsigned int v5; // esi
  UFG::TurfBlockInstance v7; // [rsp+28h] [rbp-50h] BYREF

  UFG::RacketInstance::ContainingBlock(this, &v7);
  if ( v7.mData && v7.mTurfData && v7.mTurfTemplate.mData )
  {
    v2 = 0;
    racketId = v7.mData->racketId;
    v4 = -1;
    while ( 1 )
    {
      v5 = *racketId;
      if ( v5 == (unsigned int)UFG::RacketInstance::ID(this) )
        break;
      ++v2;
      ++racketId;
      if ( v2 >= 4 )
        goto LABEL_10;
    }
  }
  else
  {
    v2 = 0;
  }
  v4 = v2;
LABEL_10:
  UFG::qReflectHandleBase::~qReflectHandleBase(&v7.mTurfTemplate);
  return v4;
}

// File Line: 60
// RVA: 0x41A7E0
UFG::TurfBlockInstance *__fastcall UFG::RacketInstance::ContainingBlock(
        UFG::RacketInstance *this,
        UFG::TurfBlockInstance *result)
{
  UFG::TurfBlockInstanceData *mContainingBlock; // rax
  unsigned int id; // edx

  mContainingBlock = this->mContainingBlock;
  if ( mContainingBlock )
    id = mContainingBlock->id;
  else
    id = -1;
  UFG::TurfBlockInstance::TurfBlockInstance(result, id);
  return result;
}

// File Line: 123
// RVA: 0x41A2E0
void __fastcall UFG::RacketInstance::BlockGridPosition(UFG::RacketInstance *this, UFG::qVector2 *outGrid)
{
  unsigned int v4; // ebp
  UFG::qReflectObject *mData; // rax
  UFG::qReflectObject *v6; // r13
  UFG::TurfInstanceData *mTurfData; // r15
  unsigned int v8; // ebx
  unsigned int *blockId; // rdi
  unsigned int v10; // ebx
  unsigned int *v11; // rdi
  UFG::TurfBlockInstance result; // [rsp+28h] [rbp-60h] BYREF

  v4 = 0;
  *outGrid = 0i64;
  mData = this->mType.mData;
  if ( !mData || LODWORD(mData[1].vfptr) != 3 )
  {
    UFG::RacketInstance::ContainingBlock(this, &result);
    if ( result.mData )
    {
      v6 = result.mTurfTemplate.mData;
      mTurfData = result.mTurfData;
      if ( result.mTurfData )
      {
        if ( !result.mTurfTemplate.mData )
          goto LABEL_29;
        v8 = 0;
        blockId = result.mTurfData->blockId;
        while ( *blockId != UFG::TurfBlockInstance::ID(&result) )
        {
          ++v8;
          ++blockId;
          if ( v8 >= 8 )
          {
            v8 = 0;
            break;
          }
        }
        if ( LODWORD(v6[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v8]) == 2 )
        {
          if ( UFG::RacketInstance::Index(this) > 1 )
            outGrid->y = outGrid->y + 1.0;
          if ( UFG::RacketInstance::Index(this) != 3 && UFG::RacketInstance::Index(this) != 1 )
            goto LABEL_26;
        }
        else
        {
LABEL_29:
          if ( !mTurfData || !v6 )
            goto LABEL_26;
          v10 = 0;
          v11 = mTurfData->blockId;
          while ( *v11 != UFG::TurfBlockInstance::ID(&result) )
          {
            ++v10;
            ++v11;
            if ( v10 >= 8 )
              goto LABEL_23;
          }
          v4 = v10;
LABEL_23:
          if ( LODWORD(v6[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v4]) != 1 || !UFG::RacketInstance::Index(this) )
            goto LABEL_26;
        }
        outGrid->x = outGrid->x + 1.0;
      }
    }
LABEL_26:
    UFG::qReflectHandleBase::~qReflectHandleBase(&result.mTurfTemplate);
  }
}

// File Line: 172
// RVA: 0x41A450
void __fastcall UFG::RacketInstance::BlockPosition(UFG::RacketInstance *this, UFG::qVector3 *outPosition)
{
  UFG::qReflectObject *mData; // rax
  float v5; // xmm7_4
  float v6; // xmm6_4
  UFG::TurfBlockInstance *v7; // rax
  UFG::qReflectObject *v8; // rax
  UFG::TurfBlockInstance *v9; // rbx
  float v10; // xmm9_4
  float v11; // xmm8_4
  UFG::qReflectObject *v12; // rdi
  UFG::RacketType::eSize v13; // ecx
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm6_4
  UFG::qVector3 outSize; // [rsp+10h] [rbp-51h] BYREF
  UFG::qVector3 outOffset; // [rsp+20h] [rbp-41h] BYREF
  UFG::TurfBlockInstance result; // [rsp+30h] [rbp-31h] BYREF
  UFG::qVector2 outGrid; // [rsp+C8h] [rbp+67h] BYREF
  UFG::qVector2 outPositiona; // [rsp+D0h] [rbp+6Fh] BYREF

  mData = this->mType.mData;
  v5 = 0.0;
  if ( mData && LODWORD(mData[1].vfptr) == 3 )
  {
    v6 = FLOAT_2_0;
  }
  else
  {
    v7 = UFG::RacketInstance::ContainingBlock(this, &result);
    UFG::TurfBlockInstance::GridPosition(v7, &outPositiona);
    outGrid = (UFG::qVector2)&result.mTurfTemplate;
    UFG::qReflectHandleBase::~qReflectHandleBase(&result.mTurfTemplate);
    UFG::RacketInstance::BlockGridPosition(this, &outGrid);
    v5 = outGrid.x + outPositiona.x;
    v6 = outGrid.y + outPositiona.y;
  }
  if ( this->mData )
  {
    v8 = this->mType.mData;
    if ( v8 )
      UFG::RacketType::GetWorldPositionOffset((UFG::RacketType::eSize)v8[1].vfptr, &outOffset);
  }
  outPosition->x = UFG::TurfManager::TURF_LOT_SIZE * v5;
  LODWORD(outPosition->y) = COERCE_UNSIGNED_INT(UFG::TurfManager::TURF_LOT_SIZE * v6) ^ _xmm[0];
  outPosition->z = outOffset.z;
  v9 = UFG::RacketInstance::ContainingBlock(this, &result);
  outGrid = 0i64;
  UFG::TurfBlockInstance::GridPosition(v9, &outGrid);
  v10 = outGrid.x * UFG::TurfManager::TURF_LOT_SIZE;
  LODWORD(v11) = COERCE_UNSIGNED_INT(outGrid.y * UFG::TurfManager::TURF_LOT_SIZE) ^ _xmm[0];
  if ( v9->mData && v9->mTurfData && (v12 = v9->mTurfTemplate.mData) != 0i64 )
    v13 = (UFG::RacketType::eSize)v12[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * UFG::TurfBlockInstance::Index(v9)];
  else
    v13 = SMALL;
  UFG::RacketType::GetWorldSize(v13, &outSize);
  v14 = (float)(outSize.x * 0.5) + v10;
  v15 = v11 - (float)(outSize.y * 0.5);
  v16 = outSize.z * 0.5;
  outGrid = (UFG::qVector2)&result.mTurfTemplate;
  UFG::qReflectHandleBase::~qReflectHandleBase(&result.mTurfTemplate);
  outPosition->x = outPosition->x - v14;
  outPosition->y = outPosition->y - v15;
  outPosition->z = outPosition->z - v16;
}

