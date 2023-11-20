// File Line: 90
// RVA: 0x69D310
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 128 + *v7),
    variant);
  return v5;
}

// File Line: 101
// RVA: 0x69D380
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCorePropsPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 144 + *v7),
    variant);
  return v5;
}

// File Line: 112
// RVA: 0x69D2A0
UFG::qSymbol *__fastcall UFG::RacketInstance::ExteriorCoreDoorsPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 160 + *v7),
    variant);
  return v5;
}

// File Line: 123
// RVA: 0x69D6E0
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 80 + *v7),
    variant);
  return v5;
}

// File Line: 134
// RVA: 0x69D750
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCorePropsPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 96 + *v7),
    variant);
  return v5;
}

// File Line: 145
// RVA: 0x69D670
UFG::qSymbol *__fastcall UFG::RacketInstance::InteriorCoreDoorsPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 112 + *v7),
    variant);
  return v5;
}

// File Line: 156
// RVA: 0x69D020
UFG::qSymbol *__fastcall UFG::RacketInstance::DecalsPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level, unsigned int variant)
{
  UFG::qReflectObject *v4; // r10
  UFG::qSymbol *v5; // rbx
  UFG::qTree64Base::BaseNode *v6; // rax
  _QWORD *v7; // rax

  v4 = racketType->mData;
  v5 = result;
  v6 = v4[2].mBaseNode.mNeighbours[0];
  switch ( LODWORD(v4[1].vfptr) )
  {
    case 1:
      v7 = &v6[2].mUID;
      break;
    case 2:
      v7 = v6[2].mChildren;
      break;
    case 3:
      v7 = v6[2].mNeighbours;
      break;
    default:
      v7 = v6[1].mNeighbours;
      break;
  }
  UFG::RacketInstance::GetPrefabVariant(
    result,
    (UFG::qReflectArray<UFG::qSymbol> *)(200i64 * level + 176 + *v7),
    variant);
  return v5;
}

// File Line: 189
// RVA: 0x69E180
UFG::qSymbol *__fastcall UFG::RacketInstance::ThemePrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level)
{
  UFG::qSymbol *v3; // rax

  v3 = result;
  result->mUID = *(unsigned int *)(racketType->mData[1].mTypeUID + 96i64 * level + 80);
  return v3;
}

// File Line: 200
// RVA: 0x69D3F0
UFG::qSymbol *__fastcall UFG::RacketInstance::GameplayPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level)
{
  UFG::qSymbol *v3; // rax

  v3 = result;
  result->mUID = *(unsigned int *)(racketType->mData[1].mTypeUID + 96i64 * level + 84);
  return v3;
}

// File Line: 211
// RVA: 0x69CFE0
UFG::qSymbol *__fastcall UFG::RacketInstance::AmbientPrefab(UFG::qSymbol *result, UFG::qReflectHandle<UFG::RacketType> *racketType, unsigned int level)
{
  UFG::qSymbol *v3; // rax

  v3 = result;
  result->mUID = *(unsigned int *)(racketType->mData[1].mTypeUID + 96i64 * level + 88);
  return v3;
}

