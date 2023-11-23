// File Line: 90
// RVA: 0x69D310
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 128 + *p_mUID),
    variant);
  return result;
}

// File Line: 101
// RVA: 0x69D380
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePropsPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 144 + *p_mUID),
    variant);
  return result;
}

// File Line: 112
// RVA: 0x69D2A0
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCoreDoorsPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 160 + *p_mUID),
    variant);
  return result;
}

// File Line: 123
// RVA: 0x69D6E0
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 80 + *p_mUID),
    variant);
  return result;
}

// File Line: 134
// RVA: 0x69D750
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePropsPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 96 + *p_mUID),
    variant);
  return result;
}

// File Line: 145
// RVA: 0x69D670
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCoreDoorsPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 112 + *p_mUID),
    variant);
  return result;
}

// File Line: 156
// RVA: 0x69D020
UFG::qSymbol *__fastcall UFG::RacketInstance::DecalsPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level,
        unsigned int variant)
{
  UFG::qReflectObject *mData; // r10
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *p_mUID; // rax

  mData = racketType->mData;
  v6 = mData[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(mData[1].vfptr) )
  {
    case 1:
      p_mUID = &v6[2].mUID;
      break;
    case 2:
      p_mUID = v6[2].mChildren;
      break;
    case 3:
      p_mUID = v6[2].mNeighbours;
      break;
    default:
      p_mUID = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 176 + *p_mUID),
    variant);
  return result;
}

// File Line: 189
// RVA: 0x69E180
UFG::qSymbol *__fastcall UFG::RacketInstance::ThemePrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level)
{
  UFG::qSymbol *v3; // rax

  v3 = result;
  result->mUID = *(unsigned int *)(racketType->mData[1].mTypeUID + 96i64 * level + 80);
  return v3;
}

// File Line: 200
// RVA: 0x69D3F0
UFG::qSymbol *__fastcall UFG::RacketInstance::GameplayPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level)
{
  UFG::qSymbol *v3; // rax

  v3 = result;
  result->mUID = *(unsigned int *)(racketType->mData[1].mTypeUID + 96i64 * level + 84);
  return v3;
}

// File Line: 211
// RVA: 0x69CFE0
UFG::qSymbol *__fastcall UFG::RacketInstance::AmbientPrefab(
        UFG::qSymbol *result,
        UFG::qReflectHandle<UFG::RacketType> *racketType,
        unsigned int level)
{
  UFG::qSymbol *v3; // rax

  v3 = result;
  result->mUID = *(unsigned int *)(racketType->mData[1].mTypeUID + 96i64 * level + 88);
  return v3;
}

