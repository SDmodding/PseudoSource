// File Line: 25
// RVA: 0x41BA20
void __fastcall UFG::RacketInstance::Init(UFG::RacketInstance *this, unsigned int racketID)
{
  unsigned int v2; // edi
  UFG::RacketInstance *v3; // rbx
  UFG::RacketInstanceData *v4; // rax
  UFG::qReflectHandle<UFG::RacketType> *v5; // rax
  UFG::qReflectHandle<UFG::RacketType> result; // [rsp+28h] [rbp-30h]

  v2 = racketID;
  v3 = this;
  v4 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, racketID);
  v3->mData = v4;
  if ( v4 )
  {
    v5 = UFG::TurfManager::GetRacketType(&result, v4->type.mData);
    UFG::qReflectHandleBase::operator=(
      (UFG::qReflectHandleBase *)&v3->mType.mPrev,
      (UFG::qReflectHandleBase *)&v5->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
  }
  v3->mContainingBlock = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                           UFG::PlaceholderGameDB::ms_pSingleton,
                           v2);
}

// File Line: 44
// RVA: 0x41B8F0
__int64 __fastcall UFG::RacketInstance::Index(UFG::RacketInstance *this)
{
  UFG::RacketInstance *v1; // r14
  unsigned int v2; // ebx
  int *v3; // rdi
  unsigned int v4; // ebp
  int v5; // esi
  __int64 v7; // [rsp+28h] [rbp-50h]
  __int64 v8; // [rsp+30h] [rbp-48h]
  UFG::qReflectHandleBase v9; // [rsp+38h] [rbp-40h]

  v1 = this;
  UFG::RacketInstance::ContainingBlock(this, (UFG::TurfBlockInstance *)&v7);
  if ( v7 && v8 && v9.mData )
  {
    v2 = 0;
    v3 = (int *)(v7 + 4);
    v4 = -1;
    while ( 1 )
    {
      v5 = *v3;
      if ( v5 == (unsigned int)UFG::RacketInstance::ID(v1) )
        break;
      ++v2;
      ++v3;
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
  UFG::qReflectHandleBase::~qReflectHandleBase(&v9);
  return v4;
}

// File Line: 60
// RVA: 0x41A7E0
UFG::TurfBlockInstance *__fastcall UFG::RacketInstance::ContainingBlock(UFG::RacketInstance *this, UFG::TurfBlockInstance *result)
{
  UFG::TurfBlockInstance *v2; // rbx
  UFG::TurfBlockInstanceData *v3; // rax
  unsigned int v4; // edx

  v2 = result;
  v3 = this->mContainingBlock;
  if ( v3 )
    v4 = v3->id;
  else
    v4 = -1;
  UFG::TurfBlockInstance::TurfBlockInstance(v2, v4);
  return v2;
}

// File Line: 123
// RVA: 0x41A2E0
void __fastcall UFG::RacketInstance::BlockGridPosition(UFG::RacketInstance *this, UFG::qVector2 *outGrid)
{
  UFG::qVector2 *v2; // rsi
  UFG::RacketInstance *v3; // r14
  unsigned int v4; // ebp
  UFG::qReflectObject *v5; // rax
  UFG::qReflectObject *v6; // r13
  UFG::TurfInstanceData *v7; // r15
  unsigned int v8; // ebx
  unsigned int *v9; // rdi
  unsigned int v10; // ebx
  unsigned int *v11; // rdi
  UFG::TurfBlockInstance result; // [rsp+28h] [rbp-60h]

  v2 = outGrid;
  v3 = this;
  v4 = 0;
  *outGrid = 0i64;
  v5 = this->mType.mData;
  if ( !v5 || LODWORD(v5[1].vfptr) != 3 )
  {
    UFG::RacketInstance::ContainingBlock(this, &result);
    if ( result.mData )
    {
      v6 = result.mTurfTemplate.mData;
      v7 = result.mTurfData;
      if ( result.mTurfData )
      {
        if ( !result.mTurfTemplate.mData )
          goto LABEL_29;
        v8 = 0;
        v9 = result.mTurfData->blockId;
        while ( *v9 != UFG::TurfBlockInstance::ID(&result) )
        {
          ++v8;
          ++v9;
          if ( v8 >= 8 )
          {
            v8 = 0;
            break;
          }
        }
        if ( LODWORD(v6[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v8]) == 2 )
        {
          if ( UFG::RacketInstance::Index(v3) > 1 )
            v2->y = v2->y + 1.0;
          if ( UFG::RacketInstance::Index(v3) != 3 && UFG::RacketInstance::Index(v3) != 1 )
            goto LABEL_26;
        }
        else
        {
LABEL_29:
          if ( !v7 || !v6 )
            goto LABEL_26;
          v10 = 0;
          v11 = v7->blockId;
          while ( *v11 != UFG::TurfBlockInstance::ID(&result) )
          {
            ++v10;
            ++v11;
            if ( v10 >= 8 )
              goto LABEL_23;
          }
          v4 = v10;
LABEL_23:
          if ( LODWORD(v6[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v4]) != 1 )
            goto LABEL_26;
          if ( !UFG::RacketInstance::Index(v3) )
            goto LABEL_26;
        }
        v2->x = v2->x + 1.0;
      }
    }
LABEL_26:
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mTurfTemplate.mPrev);
  }
}

// File Line: 172
// RVA: 0x41A450
void __fastcall UFG::RacketInstance::BlockPosition(UFG::RacketInstance *this, UFG::qVector3 *outPosition)
{
  UFG::qVector3 *v2; // rsi
  UFG::RacketInstance *v3; // rbx
  UFG::qReflectObject *v4; // rax
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
  UFG::qVector3 outSize; // [rsp+10h] [rbp-51h]
  UFG::qVector3 outOffset; // [rsp+20h] [rbp-41h]
  UFG::TurfBlockInstance result; // [rsp+30h] [rbp-31h]
  UFG::qVector2 outGrid; // [rsp+C8h] [rbp+67h]
  UFG::qVector2 outPositiona; // [rsp+D0h] [rbp+6Fh]

  v2 = outPosition;
  v3 = this;
  v4 = this->mType.mData;
  v5 = 0.0;
  if ( v4 && LODWORD(v4[1].vfptr) == 3 )
  {
    v6 = FLOAT_2_0;
  }
  else
  {
    v7 = UFG::RacketInstance::ContainingBlock(this, &result);
    UFG::TurfBlockInstance::GridPosition(v7, &outPositiona);
    outGrid = (UFG::qVector2)&result.mTurfTemplate;
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mTurfTemplate.mPrev);
    UFG::RacketInstance::BlockGridPosition(v3, &outGrid);
    v5 = outGrid.x + outPositiona.x;
    v6 = outGrid.y + outPositiona.y;
  }
  if ( v3->mData )
  {
    v8 = v3->mType.mData;
    if ( v8 )
      UFG::RacketType::GetWorldPositionOffset((UFG::RacketType::eSize)v8[1].vfptr, &outOffset);
  }
  v2->x = UFG::TurfManager::TURF_LOT_SIZE * v5;
  LODWORD(v2->y) = COERCE_UNSIGNED_INT(UFG::TurfManager::TURF_LOT_SIZE * v6) ^ _xmm[0];
  v2->z = outOffset.z;
  v9 = UFG::RacketInstance::ContainingBlock(v3, &result);
  outGrid = 0i64;
  UFG::TurfBlockInstance::GridPosition(v9, &outGrid);
  v10 = outGrid.x * UFG::TurfManager::TURF_LOT_SIZE;
  LODWORD(v11) = COERCE_UNSIGNED_INT(outGrid.y * UFG::TurfManager::TURF_LOT_SIZE) ^ _xmm[0];
  if ( v9->mData && v9->mTurfData && (v12 = v9->mTurfTemplate.mData) != 0i64 )
    v13 = (UFG::RacketType::eSize)v12[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * UFG::TurfBlockInstance::Index(v9)];
  else
    v13 = 0;
  UFG::RacketType::GetWorldSize(v13, &outSize);
  v14 = (float)(outSize.x * 0.5) + v10;
  v15 = v11 - (float)(outSize.y * 0.5);
  v16 = outSize.z * 0.5;
  outGrid = (UFG::qVector2)&result.mTurfTemplate;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mTurfTemplate.mPrev);
  v2->x = v2->x - v14;
  v2->y = v2->y - v15;
  v2->z = v2->z - v16;
}

