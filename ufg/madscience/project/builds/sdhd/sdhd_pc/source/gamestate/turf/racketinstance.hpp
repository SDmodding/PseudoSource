// File Line: 35
// RVA: 0x419760
void __fastcall UFG::RacketInstance::RacketInstance(UFG::RacketInstance *this, unsigned int racketID)
{
  UFG::qReflectHandle<UFG::RacketType> *p_mType; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v5; // rcx
  const char *TypeName; // rax

  this->mData = 0i64;
  p_mType = &this->mType;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mType);
  TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v5);
  p_mType->mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  this->mContainingBlock = 0i64;
  UFG::RacketInstance::Init(this, racketID);
}

// File Line: 45
// RVA: 0x41B8C0
UFG::RacketInstanceData *__fastcall UFG::RacketInstance::ID(UFG::RacketInstance *this)
{
  UFG::RacketInstanceData *result; // rax

  result = this->mData;
  if ( this->mData )
    return (UFG::RacketInstanceData *)result->id;
  return result;
}

// File Line: 61
// RVA: 0x41ADC0
UFG::qSymbol *__fastcall UFG::RacketInstance::GetPrefabVariant(
        UFG::qSymbol *result,
        UFG::qReflectArray<UFG::qSymbol> *arr,
        unsigned int variant)
{
  unsigned int mNumItems; // eax
  UFG::qSymbol *v4; // rax

  mNumItems = arr->mData.mNumItems;
  if ( mNumItems )
  {
    if ( variant >= mNumItems )
      variant = mNumItems - 1;
    v4 = result;
    result->mUID = (unsigned int)arr->mData.mItems[variant];
  }
  else
  {
    result->mUID = -1;
    return result;
  }
  return v4;
}

// File Line: 84
// RVA: 0x41AB70
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 128 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 95
// RVA: 0x41AC00
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePropsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 144 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 106
// RVA: 0x41AAE0
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCoreDoorsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 160 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 117
// RVA: 0x41BCF0
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 80 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 128
// RVA: 0x41BD80
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePropsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 96 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 139
// RVA: 0x41BC60
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCoreDoorsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 112 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 150
// RVA: 0x41AA50
UFG::qSymbol *__fastcall UFG::RacketInstance::DecalsPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v4; // rax
  _QWORD *p_mUID; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v4 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v4[2].mUID;
        break;
      case 2:
        p_mUID = v4[2].mChildren;
        break;
      case 3:
        p_mUID = v4[2].mNeighbours;
        break;
      default:
        p_mUID = v4[1].mNeighbours;
        break;
    }
    UFG::RacketInstance::GetPrefabVariant(
      result,
      (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * this->mData->level + 176 + *p_mUID),
      this->mData->variant);
    return result;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
}

// File Line: 161
// RVA: 0x41E7E0
UFG::qSymbol *__fastcall UFG::RacketInstance::UnderConstructionPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qTree64Base::BaseNode *v3; // rax
  _QWORD *p_mUID; // rax
  unsigned int v5; // ecx
  UFG::qSymbol *v6; // rax

  if ( this->mData && this->mType.mData )
  {
    mData = this->mType.mData;
    v3 = mData[2].mBaseNode.mNeighbours[0];
    switch ( LODWORD(mData[1].vfptr) )
    {
      case 1:
        p_mUID = &v3[2].mUID;
        break;
      case 2:
        p_mUID = v3[2].mChildren;
        break;
      case 3:
        p_mUID = v3[2].mNeighbours;
        break;
      default:
        p_mUID = v3[1].mNeighbours;
        break;
    }
    v5 = *(_DWORD *)(200i64 * this->mData->level + *p_mUID + 192);
    v6 = result;
    result->mUID = v5;
  }
  else
  {
    result->mUID = -1;
    return result;
  }
  return v6;
}

// File Line: 183
// RVA: 0x41E7A0
UFG::qSymbol *__fastcall UFG::RacketInstance::ThemePrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qSymbol *v3; // rax

  if ( this->mData && (mData = this->mType.mData) != 0i64 )
  {
    v3 = result;
    result->mUID = *(unsigned int *)(96i64 * this->mData->level + mData[1].mTypeUID + 80);
  }
  else
  {
    result->mUID = -1;
    return result;
  }
  return v3;
}

// File Line: 194
// RVA: 0x41AC90
UFG::qSymbol *__fastcall UFG::RacketInstance::GameplayPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qSymbol *v3; // rax

  if ( this->mData && (mData = this->mType.mData) != 0i64 )
  {
    v3 = result;
    result->mUID = *(unsigned int *)(96i64 * this->mData->level + mData[1].mTypeUID + 84);
  }
  else
  {
    result->mUID = -1;
    return result;
  }
  return v3;
}

// File Line: 205
// RVA: 0x41A2A0
UFG::qSymbol *__fastcall UFG::RacketInstance::AmbientPrefab(UFG::RacketInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // r8
  UFG::qSymbol *v3; // rax

  if ( this->mData && (mData = this->mType.mData) != 0i64 )
  {
    v3 = result;
    result->mUID = *(unsigned int *)(96i64 * this->mData->level + mData[1].mTypeUID + 88);
  }
  else
  {
    result->mUID = -1;
    return result;
  }
  return v3;
}

