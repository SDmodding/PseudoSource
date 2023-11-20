// File Line: 35
// RVA: 0x419760
void __fastcall UFG::RacketInstance::RacketInstance(UFG::RacketInstance *this, unsigned int racketID)
{
  unsigned int v2; // edi
  UFG::RacketInstance *v3; // rsi
  UFG::qReflectHandle<UFG::RacketType> *v4; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v5; // rcx
  const char *v6; // rax

  v2 = racketID;
  v3 = this;
  this->mData = 0i64;
  v4 = &this->mType;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mType.mPrev);
  v6 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v5);
  v4->mTypeUID = UFG::qStringHash64(v6, 0xFFFFFFFFFFFFFFFFui64);
  v3->mContainingBlock = 0i64;
  UFG::RacketInstance::Init(v3, v2);
}

// File Line: 45
// RVA: 0x41B8C0
UFG::RacketInstanceData *__fastcall UFG::RacketInstance::ID(UFG::RacketInstance *this)
{
  UFG::RacketInstanceData *result; // rax

  result = this->mData;
  if ( this->mData )
    result = (UFG::RacketInstanceData *)result->id;
  return result;
}

// File Line: 61
// RVA: 0x41ADC0
UFG::qSymbol *__fastcall UFG::RacketInstance::GetPrefabVariant(UFG::qSymbol *result, UFG::qReflectArray<UFG::qSymbol> *arr, unsigned int variant)
{
  unsigned int v3; // eax
  UFG::qSymbol *v4; // rax

  v3 = arr->mData.mNumItems;
  if ( v3 >= 1 )
  {
    if ( variant >= v3 )
      variant = v3 - 1;
    v4 = result;
    result->mUID = (unsigned int)arr->mData.mItems[variant];
  }
  else
  {
    result->mUID = -1;
    v4 = result;
  }
  return v4;
}

// File Line: 84
// RVA: 0x41AB70
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 128 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 95
// RVA: 0x41AC00
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePropsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 144 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 106
// RVA: 0x41AAE0
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCoreDoorsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 160 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 117
// RVA: 0x41BCF0
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 80 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 128
// RVA: 0x41BD80
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePropsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 96 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 139
// RVA: 0x41BC60
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCoreDoorsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 112 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 150
// RVA: 0x41AA50
UFG::qSymbol *__fastcall UFG::RacketInstance::DecalsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::qReflectObject *v3; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *v5; // rax
  UFG::qSymbol *v6; // rax

  v2 = result;
  if ( this->mData && this->mType.mData )
  {
    v3 = this->mType.mData;
    v4 = v3[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v3[1].vfptr) )
    {
      case 1:
        v5 = &v4[2].mUID;
        break;
      case 2:
        v5 = v4[2].mChildren;
        break;
      case 3:
        v5 = v4[2].mNeighbours;
        break;
      default:
        v5 = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 176 + *v5),
      this->mData->variant);
    v6 = v2;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 161
// RVA: 0x41E7E0
UFG::qSymbol *__fastcall UFG::RacketInstance::UnderConstructionPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *v2; // r8
  UFG::qTree64Base::BaseNode *v3; // rax
  _QWORD *v4; // rax
  unsigned int v5; // ecx
  UFG::qSymbol *v6; // rax

  if ( this->mData && this->mType.mData )
  {
    v2 = this->mType.mData;
    v3 = v2[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(v2[1].vfptr) )
    {
      case 1:
        v4 = &v3[2].mUID;
        break;
      case 2:
        v4 = v3[2].mChildren;
        break;
      case 3:
        v4 = v3[2].mNeighbours;
        break;
      default:
        v4 = v3[1].mNeighbours;
        break;
    }
    v5 = *(_DWORD *)(200i64 * this->mData->level + *v4 + 192);
    v6 = result;
    result->mUID = v5;
  }
  else
  {
    result->mUID = -1;
    v6 = result;
  }
  return v6;
}

// File Line: 183
// RVA: 0x41E7A0
UFG::qSymbol *__fastcall UFG::RacketInstance::ThemePrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *v2; // r8
  UFG::qSymbol *v3; // rax

  if ( this->mData && (v2 = this->mType.mData) != 0i64 )
  {
    v3 = result;
    result->mUID = *(unsigned int *)(96i64 * this->mData->level + v2[1].mTypeUID + 80);
  }
  else
  {
    result->mUID = -1;
    v3 = result;
  }
  return v3;
}

// File Line: 194
// RVA: 0x41AC90
UFG::qSymbol *__fastcall UFG::RacketInstance::GameplayPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *v2; // r8
  UFG::qSymbol *v3; // rax

  if ( this->mData && (v2 = this->mType.mData) != 0i64 )
  {
    v3 = result;
    result->mUID = *(unsigned int *)(96i64 * this->mData->level + v2[1].mTypeUID + 84);
  }
  else
  {
    result->mUID = -1;
    v3 = result;
  }
  return v3;
}

// File Line: 205
// RVA: 0x41A2A0
UFG::qSymbol *__fastcall UFG::RacketInstance::AmbientPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *v2; // r8
  UFG::qSymbol *v3; // rax

  if ( this->mData && (v2 = this->mType.mData) != 0i64 )
  {
    v3 = result;
    result->mUID = *(unsigned int *)(96i64 * this->mData->level + v2[1].mTypeUID + 88);
  }
  else
  {
    result->mUID = -1;
    v3 = result;
  }
  return v3;
}

