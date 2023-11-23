// File Line: 81
// RVA: 0x361AA0
UFG::SpawnPoint *__fastcall UFG::GetOriginatingSpawnPoint(UFG::SimObject *pSimObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v4; // edx
  bool v6; // zf

  if ( pSimObject )
  {
    m_pSceneObj = pSimObject->m_pSceneObj;
    if ( m_pSceneObj )
    {
      m_pPointer = (UFG::SimObjectGame *)m_pSceneObj->mpOwner.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
        {
          v4 = UFG::SpawnPoint::_TypeUID;
        }
        else
        {
          v6 = (m_Flags & 0x1000) == 0;
          v4 = UFG::SpawnPoint::_TypeUID;
          if ( v6 )
            return (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SpawnPoint::_TypeUID);
        }
        return (UFG::SpawnPoint *)UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v4);
      }
    }
  }
  return 0i64;
}

// File Line: 135
// RVA: 0x360C20
UFG::SimObjectCharacter *__fastcall UFG::GetLocalPlayer()
{
  return LocalPlayer;
}

// File Line: 145
// RVA: 0x369F00
bool __fastcall UFG::IsAnyLocalPlayer(UFG::SimObjectCharacter *object)
{
  return object && object == LocalPlayer;
}

// File Line: 161
// RVA: 0x36A9B0
bool __fastcall UFG::IsFemale(UFG::SimObjectCVBase *pSimObject)
{
  UFG::SimObjectCharacterPropertiesComponent *v1; // rax

  return pSimObject
      && (v1 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pSimObject)) != 0i64
      && v1->m_eGender == eGENDER_FEMALE;
}

// File Line: 186
// RVA: 0x37C560
char __fastcall UFG::PlaceOnGround(
        UFG::qVector3 *out,
        UFG::qVector3 *position,
        float height_above_ground,
        float cast_distance_down,
        float cast_distance_up)
{
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm4_4
  float v9; // xmm1_4
  char result; // al
  float v11; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-118h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-108h] BYREF
  UFG::RayCastData data; // [rsp+40h] [rbp-F8h] BYREF

  y = position->y;
  x = position->x;
  z = position->z;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_extraInfo = -1;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  rayStart.x = x;
  rayEnd.x = x;
  rayStart.y = y;
  data.mOutput.m_shapeKeys[0] = -1;
  rayEnd.y = y;
  LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
  rayStart.z = z + cast_distance_up;
  data.mOutput.m_rootCollidable = 0i64;
  data.mCollisionModelName.mUID = -1;
  rayEnd.z = z - cast_distance_down;
  data.mDebugName = "PlaceOnGround";
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v9 = data.point.y;
  result = 1;
  out->x = data.point.x;
  v11 = data.point.z;
  out->y = v9;
  out->z = v11 + height_above_ground;
  return result;
}

// File Line: 208
// RVA: 0x37C400
char __fastcall UFG::PlaceOnGround(
        UFG::qVector3 *out,
        UFG::qVector3 *position,
        float height_above_ground,
        float cast_distance)
{
  float v4; // xmm4_4
  float y; // xmm0_4
  float z; // xmm3_4
  float x; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  char result; // al
  float v12; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-118h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-108h] BYREF
  UFG::RayCastData data; // [rsp+40h] [rbp-F8h] BYREF

  v4 = cast_distance;
  if ( cast_distance == 0.0 )
    v4 = FLOAT_3_0;
  y = position->y;
  z = position->z;
  x = position->x;
  v9 = v4 * 0.5;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  rayStart.y = y;
  rayEnd.y = y;
  data.mOutput.m_rootCollidable = 0i64;
  rayEnd.z = z - v9;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  rayStart.x = x;
  rayEnd.x = x;
  rayStart.z = z + v9;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mDebugName = "PlaceOnGround";
  LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v10 = data.point.y;
  result = 1;
  out->x = data.point.x;
  v12 = data.point.z;
  out->y = v10;
  out->z = v12 + height_above_ground;
  return result;
}

// File Line: 248
// RVA: 0x3549B0
void UFG::DrawDebugText(int x, int y, UFG::qColour *colour, const char *format, ...)
{
  Render::DebugDrawContext *Context; // rax
  char dest[8216]; // [rsp+30h] [rbp-2018h] BYREF
  va_list va; // [rsp+2070h] [rbp+28h] BYREF

  va_start(va, format);
  if ( (unsigned int)UFG::qVSPrintf(dest, 0x2000, format, va) )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawTextA(Context, x, y, colour, dest);
  }
}

// File Line: 297
// RVA: 0x354A30
void UFG::DrawDebugText(
        UFG::TransformNodeComponent *transform,
        UFG::qColour *colour,
        const char *format,
        __int64 a4,
        ...)
{
  int v4; // eax
  Render::DebugDrawContext *Context; // rax
  char dest[8216]; // [rsp+20h] [rbp-2018h] BYREF
  __int64 v9; // [rsp+2058h] [rbp+20h] BYREF

  v9 = a4;
  if ( (unsigned int)UFG::qVSPrintf(dest, v4 - 40, format, (char *)&v9) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(transform);
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawText(Context, (UFG::qVector3 *)&transform->mWorldTransform.v3, colour, dest);
  }
}

// File Line: 322
// RVA: 0x354AB0
void __fastcall UFG::DrawLine(
        UFG::TransformNodeComponent *transform1,
        UFG::TransformNodeComponent *transform2,
        UFG::qColour *colour,
        float z_offset)
{
  float y; // xmm1_4
  float x; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 p1; // [rsp+40h] [rbp-48h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-38h] BYREF
  UFG::qColour coloura; // [rsp+60h] [rbp-28h] BYREF

  if ( transform1 )
  {
    if ( transform2 )
    {
      coloura = *colour;
      UFG::TransformNodeComponent::UpdateWorldTransform(transform2);
      UFG::TransformNodeComponent::UpdateWorldTransform(transform1);
      y = transform1->mWorldTransform.v3.y;
      p0.x = transform1->mWorldTransform.v3.x;
      x = transform2->mWorldTransform.v3.x;
      p0.y = y;
      v8 = transform2->mWorldTransform.v3.y;
      p1.x = x;
      v9 = z_offset + transform1->mWorldTransform.v3.z;
      v10 = z_offset + transform2->mWorldTransform.v3.z;
      p1.y = v8;
      p0.z = v9;
      p1.z = v10;
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      Render::DebugDrawContext::DrawLine(
        Context,
        &p0,
        &p1,
        &coloura,
        &UFG::qMatrix44::msIdentity,
        (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
        0);
    }
  }
}

// File Line: 358
// RVA: 0x354BB0
void __fastcall UFG::DrawLineScreenSpace(UFG::qVector3 *point1, UFG::qVector3 *point2, UFG::qColour *colour)
{
  Render::DebugDrawContext *Context; // rax

  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawLine(Context, point1, point2, colour, 0i64, 0i64, 0);
}

// File Line: 418
// RVA: 0x353860
void __fastcall UFG::DrawBoxScreenSpace(float xpos, float ypos, float height, float width, UFG::qColour *colour)
{
  Render::DebugDrawContext *Context; // rdi
  UFG::qVector3 p1; // [rsp+40h] [rbp-40h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-30h] BYREF
  UFG::qVector3 v8; // [rsp+60h] [rbp-20h] BYREF
  UFG::qVector3 v9; // [rsp+70h] [rbp-10h] BYREF

  p0.x = xpos;
  p0.y = xpos;
  v8.y = xpos;
  p1.x = xpos;
  p0.z = 0.0;
  v8.z = 0.0;
  p1.z = 0.0;
  v8.x = xpos + width;
  p1.y = xpos + height;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawLine(Context, &p0, &p1, colour, 0i64, 0i64, 0);
  v9.x = (float)(p1.x + v8.x) - p0.x;
  v9.y = (float)(v8.y + p1.y) - p0.y;
  v9.z = (float)(p1.z + v8.z) - p0.z;
  Render::DebugDrawContext::DrawLine(Context, &p1, &v9, colour, 0i64, 0i64, 0);
  v9.x = (float)(p1.x + v8.x) - p0.x;
  v9.y = (float)(v8.y + p1.y) - p0.y;
  v9.z = (float)(p1.z + v8.z) - p0.z;
  Render::DebugDrawContext::DrawLine(Context, &v9, &v8, colour, 0i64, 0i64, 0);
  Render::DebugDrawContext::DrawLine(Context, &v8, &p0, colour, 0i64, 0i64, 0);
}

// File Line: 436
// RVA: 0x362550
float __fastcall UFG::GetRandomNumberInRange(float min, float max)
{
  float result; // xmm0_4

  result = max;
  if ( max > min )
  {
    result = UFG::qRandom(max - min, (unsigned int *)&UFG::qDefaultSeed) + min;
    if ( result <= min )
      result = min;
    if ( result >= max )
      return max;
  }
  return result;
}

// File Line: 448
// RVA: 0x362520
__int64 __fastcall UFG::GetRandomNumberInRange(int min, unsigned int max)
{
  __int64 result; // rax

  result = max;
  if ( (int)max > min )
    return min + (unsigned int)UFG::qRandom(max - min + 1, (unsigned int *)&UFG::qDefaultSeed);
  return result;
}

// File Line: 579
// RVA: 0x364ED0
bool __fastcall UFG::HasRangedWeaponEquippedWithAmmo(UFG::TargetingSystemBaseComponent *targeting_system_component)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax
  UFG::GunComponent *v4; // rdi
  int TotalAmmo; // ebx

  if ( !targeting_system_component )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)targeting_system_component->m_pTargets[(unsigned __int8)targeting_system_component->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               m_pPointer,
                                               UFG::GunComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
  v4 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  TotalAmmo = UFG::GunComponent::GetTotalAmmo(ComponentOfTypeHK);
  return (int)(UFG::GunComponent::GetClipAmmo(v4) + TotalAmmo) > 0;
}

// File Line: 604
// RVA: 0x364E20
bool __fastcall UFG::HasRangedWeapon(UFG::TargetingSystemBaseComponent *targeting_system_component)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  result = 0;
  if ( targeting_system_component )
  {
    m_pPointer = (UFG::SimObjectGame *)targeting_system_component->m_pTargets[(unsigned __int8)targeting_system_component->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        return 1;
    }
  }
  return result;
}

// File Line: 628
// RVA: 0x36A500
bool __fastcall UFG::IsDowned(UFG::ActionTreeComponent *action_tree_component, UFG::HealthComponent *health_component)
{
  unsigned int v4; // eax
  ActionController *p_mActionController; // rbx

  v4 = _S5_7;
  if ( (_S5_7 & 1) == 0 )
  {
    _S5_7 |= 1u;
    downed.mUID = UFG::qStringHashUpper32("Downed", -1);
    v4 = _S5_7;
  }
  if ( (v4 & 2) == 0 )
  {
    _S5_7 = v4 | 2;
    knockOut.mUID = UFG::qStringHashUpper32("KnockOut", -1);
    v4 = _S5_7;
  }
  if ( (v4 & 4) == 0 )
  {
    _S5_7 = v4 | 4;
    ragdoll.mUID = UFG::qStringHashUpper32("Ragdoll", -1);
    v4 = _S5_7;
  }
  if ( (v4 & 8) == 0 )
  {
    _S5_7 = v4 | 8;
    mostUsedIndex_Downed = GetMostUsedIndex(downed.mUID);
    v4 = _S5_7;
  }
  if ( (v4 & 0x10) == 0 )
  {
    _S5_7 = v4 | 0x10;
    mostUsedIndex_KnockOut = GetMostUsedIndex(knockOut.mUID);
    v4 = _S5_7;
  }
  if ( (v4 & 0x20) == 0 )
  {
    _S5_7 = v4 | 0x20;
    mostUsedIndex_RagDoll = GetMostUsedIndex(ragdoll.mUID);
  }
  if ( !action_tree_component || !health_component )
    return 0;
  p_mActionController = &action_tree_component->mActionController;
  return ActionController::IsPlaying(p_mActionController, &downed, mostUsedIndex_Downed, 0)
      || ActionController::IsPlaying(p_mActionController, &knockOut, mostUsedIndex_KnockOut, 0)
      || ActionController::IsPlaying(p_mActionController, &ragdoll, mostUsedIndex_RagDoll, 0)
      || health_component->m_bIsKnockedOut;
}

// File Line: 670
// RVA: 0x36BB20
unsigned __int8 __fastcall UFG::IsStunned(UFG::ActionTreeComponent *action_tree_component)
{
  unsigned int v2; // eax
  unsigned int MostUsedIndex; // eax

  v2 = _S7_7;
  if ( (_S7_7 & 1) == 0 )
  {
    _S7_7 |= 1u;
    stunned.mUID = UFG::qStringHashUpper32("Stunned", -1);
    v2 = _S7_7;
  }
  if ( (v2 & 2) != 0 )
  {
    MostUsedIndex = mostUsedIndex_Stunned;
  }
  else
  {
    _S7_7 = v2 | 2;
    MostUsedIndex = GetMostUsedIndex(stunned.mUID);
    mostUsedIndex_Stunned = MostUsedIndex;
  }
  if ( action_tree_component )
    return ActionController::IsPlaying(&action_tree_component->mActionController, &stunned, MostUsedIndex, 0);
  else
    return 0;
}

// File Line: 740
// RVA: 0x362D30
__int64 __fastcall UFG::GetTerrainTypeHash(UFG::CharacterPhysicsComponent *character_physics_component)
{
  unsigned int mPrev; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v3; // rcx
  const char *TypeName; // rax
  UFG::qReflectHandleBase v6; // [rsp+28h] [rbp-30h] BYREF

  mPrev = 0;
  if ( character_physics_component )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v6);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v3);
    v6.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(
      &v6,
      v6.mTypeUID,
      character_physics_component->mGroundProperties.groundSurfaceHandleUid);
    if ( v6.mData )
      mPrev = (unsigned int)v6.mData[1].mHandles.mNode.mPrev;
    UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
  }
  return mPrev;
}

// File Line: 760
// RVA: 0x362CF0
__int64 __fastcall UFG::GetTerrainTypeEnum(unsigned int terrainTypeHash)
{
  switch ( terrainTypeHash )
  {
    case 0x31BF8DE9u:
      return 1i64;
    case 0x5F6C3831u:
      return 0i64;
    case 0x9421E102:
      return 2i64;
  }
  return (unsigned int)(terrainTypeHash != -65687271) + 3;
}

// File Line: 820
// RVA: 0x3421D0
char __fastcall UFG::AreCharactersAllied(UFG::SimObjectCVBase *sim_object_1, UFG::SimObjectCVBase *sim_object_2)
{
  char v2; // si
  UFG::SimObjectCharacterPropertiesComponent *v4; // rbx
  signed __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCharacterPropertiesComponent *v7; // rdx
  signed __int16 v8; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  bool v10; // di
  __int64 m_eFactionClass; // rbx
  __int64 v12; // rbp
  UFG::GameStatTracker *v13; // rdx

  v2 = 0;
  if ( sim_object_1 )
  {
    m_Flags = sim_object_1->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(sim_object_1);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          sim_object_1,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          sim_object_1,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  if ( sim_object_2 )
  {
    v8 = sim_object_2->m_Flags;
    if ( (v8 & 0x4000) != 0 || v8 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(sim_object_2);
    }
    else if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        sim_object_2,
                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                        sim_object_2,
                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    v7 = ComponentOfType;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v4 || !v7 )
    return 0;
  v10 = ((v4->m_eCharacterType - 15) & 0xFFFFFFEF) == 0 && ((v7->m_eCharacterType - 15) & 0xFFFFFFEF) == 0;
  m_eFactionClass = v4->m_eFactionClass;
  v12 = v7->m_eFactionClass;
  v13 = UFG::GameStatTracker::Instance();
  if ( v10 || v13->mFactionInterface.mStandings[m_eFactionClass][v12] == FACTIONSTANDING_ALLIED )
    return 1;
  return v2;
}

// File Line: 847
// RVA: 0x36AAA0
unsigned __int8 __fastcall UFG::IsHostage(UFG::SimObjectGame *simObject)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v3; // rax
  unsigned int v4; // eax
  unsigned int MostUsedIndex; // eax

  if ( !simObject )
    return 0;
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = simObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = simObject->m_Components.p[6].m_pComponent;
    }
    else
    {
      v3 = (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::ActionTreeComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(simObject, UFG::ActionTreeComponent::_TypeUID);
      m_pComponent = v3;
    }
  }
  else
  {
    m_pComponent = simObject->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v4 = _S9_6;
  if ( (_S9_6 & 1) == 0 )
  {
    _S9_6 |= 1u;
    hostage.mUID = UFG::qStringHashUpper32("Hostage", -1);
    v4 = _S9_6;
  }
  if ( (v4 & 2) != 0 )
  {
    MostUsedIndex = mostUsedIndex_hostage;
  }
  else
  {
    _S9_6 = v4 | 2;
    MostUsedIndex = GetMostUsedIndex(hostage.mUID);
    mostUsedIndex_hostage = MostUsedIndex;
  }
  return ActionController::IsPlaying((ActionController *)&m_pComponent[3], &hostage, MostUsedIndex, 1);
}

// File Line: 865
// RVA: 0x36B450
bool __fastcall UFG::IsKnockedOut(UFG::SimObjectGame *simObject)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( simObject
    && ((m_Flags = simObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(simObject, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = simObject->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = simObject->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK) )
  {
    return BYTE4(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 881
// RVA: 0x36B3C0
bool __fastcall UFG::IsKilled(UFG::SimObjectGame *simObject)
{
  signed __int16 m_Flags; // dx
  UFG::HealthComponent *ComponentOfTypeHK; // rax
  bool result; // al

  result = simObject
        && ((m_Flags = simObject->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             simObject,
                                                             UFG::HealthComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                                             simObject,
                                                             UFG::HealthComponent::_TypeUID)))
           : (ComponentOfTypeHK = (UFG::HealthComponent *)simObject->m_Components.p[6].m_pComponent))
          : (ComponentOfTypeHK = (UFG::HealthComponent *)simObject->m_Components.p[6].m_pComponent),
            ComponentOfTypeHK)
        && UFG::HealthComponent::GetIsKilled(ComponentOfTypeHK);
  return result;
}

// File Line: 899
// RVA: 0x3634F0
UFG::qVector3 *__fastcall UFG::GetVelocity(UFG::qVector3 *result, UFG::SimObjectGame *simObject)
{
  float y; // xmm1_4
  float z; // xmm0_4
  signed __int16 m_Flags; // cx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax
  UFG::qVector3 *Velocity; // rax
  signed __int16 v9; // cx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  signed __int16 v11; // cx
  UFG::RigidBody *ComponentOfType; // rax
  UFG::qVector3 resulta; // [rsp+20h] [rbp-18h] BYREF

  y = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  result->z = z;
  if ( !simObject )
    return result;
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterPhysicsComponent *)simObject->m_Components.p[27].m_pComponent;
  }
  else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
  {
    m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       simObject,
                                                       UFG::CharacterPhysicsComponent::_TypeUID);
  }
  else
  {
    m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                       simObject,
                                                       UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( m_pComponent )
  {
    Velocity = UFG::CharacterPhysicsComponent::GetVelocity(m_pComponent, &resulta);
LABEL_30:
    result->x = Velocity->x;
    *(_QWORD *)&result->y = *(_QWORD *)&Velocity->y;
    return result;
  }
  v9 = simObject->m_Flags;
  if ( (v9 & 0x4000) == 0 )
  {
    if ( v9 < 0 )
    {
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)simObject->m_Components.p[34].m_pComponent;
      goto LABEL_19;
    }
    if ( (v9 & 0x2000) == 0 )
    {
      if ( (v9 & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            simObject,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                            simObject,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
LABEL_19:
      if ( ComponentOfTypeHK )
      {
        Velocity = UFG::PhysicsMoverInterface::GetVelocity(ComponentOfTypeHK, &resulta);
        goto LABEL_30;
      }
    }
  }
  v11 = simObject->m_Flags;
  if ( (v11 & 0x4000) != 0 || v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
    ComponentOfType = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          simObject,
                                          UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
  if ( ComponentOfType )
  {
    Velocity = UFG::RigidBody::GetVelocity(ComponentOfType, &resulta);
    goto LABEL_30;
  }
  return result;
}

// File Line: 933
// RVA: 0x362150
UFG::qVector3 *__fastcall UFG::GetPosition(UFG::qVector3 *result, UFG::SimObjectGame *simObject)
{
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  signed __int16 m_Flags; // cx
  UFG::RigidBody *ComponentOfTypeHK; // rax
  UFG::qVector3 resulta; // [rsp+20h] [rbp-18h] BYREF

  y = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  result->z = z;
  if ( !simObject )
    return result;
  m_pTransformNodeComponent = simObject->m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(simObject->m_pTransformNodeComponent);
    result->x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    result->y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    result->z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    return result;
  }
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            simObject,
                                            UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                            simObject,
                                            UFG::RigidBodyComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return result;
  *result = *UFG::RigidBody::GetCentreOfMass(ComponentOfTypeHK, &resulta);
  return result;
}

// File Line: 1006
// RVA: 0x36BAA0
bool __fastcall UFG::IsSpawning(UFG::SimObjectCVBase *simObject)
{
  signed __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  if ( simObject
    && ((m_Flags = simObject->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(simObject))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               simObject,
                                                               UFG::ActiveAIEntityComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                               simObject,
                                                               UFG::ActiveAIEntityComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK->m_IsSpawning;
  }
  else
  {
    return 0;
  }
}

// File Line: 1024
// RVA: 0x36B9F0
char __fastcall UFG::IsSkippingIntoPOI(UFG::SimObject *pSimObj)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  if ( pSimObj )
  {
    m_Flags = pSimObj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObj->m_Components.p[43].m_pComponent;
LABEL_9:
      if ( m_pComponent
        && m_pComponent[8].m_SafePointerList.mNode.mNext
        && m_pComponent[8].m_TypeUID
        && LOBYTE(m_pComponent[8].m_Flags)
        && m_pComponent[8].m_NameUID != -1 )
      {
        return 1;
      }
      return UFG::IsSpawning(pSimObj);
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = pSimObj->m_Components.p[12].m_pComponent;
        goto LABEL_9;
      }
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObj, UFG::InterestPointUserComponent::_TypeUID);
        goto LABEL_9;
      }
    }
    return UFG::IsSpawning(pSimObj);
  }
  return 0;
}

// File Line: 1059
// RVA: 0x36A870
bool __fastcall UFG::IsFacingPosition(UFG::SimObject *pSimObject, UFG::qVector3 *position, float max_angle_degrees)
{
  float v4; // xmm6_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-28h] BYREF

  v4 = max_angle_degrees;
  if ( !pSimObject )
    return 0;
  m_pTransformNodeComponent = pSimObject->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
  v1.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  v1.y = y;
  v1.z = z;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v8 = position->y - m_pTransformNodeComponent->mWorldTransform.v3.y;
  v2.x = position->x - m_pTransformNodeComponent->mWorldTransform.v3.x;
  v9 = position->z;
  v2.y = v8;
  v2.z = v9 - m_pTransformNodeComponent->mWorldTransform.v3.z;
  v10 = (float)(UFG::qAngleBetween(&v1, &v2) * 180.0) * 0.31830987;
  if ( max_angle_degrees < 0.0 )
    v4 = UFG::gFacingThresoldDegrees;
  return v4 > COERCE_FLOAT(LODWORD(v10) & _xmm);
}

// File Line: 1072
// RVA: 0x36A7E0
bool __fastcall UFG::IsFacingDirection(UFG::SimObject *pSimObject, UFG::qVector3 *direction, float max_angle_degrees)
{
  float v4; // xmm6_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v6; // xmm0_4

  v4 = max_angle_degrees;
  if ( !pSimObject )
    return 0;
  m_pTransformNodeComponent = pSimObject->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
  v6 = (float)(UFG::qAngleBetween((UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform, direction) * 180.0)
     * 0.31830987;
  if ( max_angle_degrees < 0.0 )
    v4 = UFG::gFacingThresoldDegrees;
  return v4 > COERCE_FLOAT(LODWORD(v6) & _xmm);
}

// File Line: 1083
// RVA: 0x14B9260
__int64 UFG::_dynamic_initializer_for__symbip01Head__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Head", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symbip01Head, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symbip01Head__);
}

// File Line: 1085
// RVA: 0x34FDC0
void __fastcall UFG::ComputeObjectRaycastPosition(UFG::SimObjectCVBase *pObject, UFG::qVector3 *raycastPosition)
{
  signed __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rdi
  int BoneID; // eax
  UFG::qVector3 *Translation; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  if ( !pObject )
  {
    m_pTransformNodeComponent = 0i64;
    goto LABEL_17;
  }
  m_Flags = pObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(pObject);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)pObject);
  }
  else if ( (m_Flags & 0x1000) != 0 )
  {
    ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              pObject,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              pObject,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
  }
  if ( !ComponentOfTypeHK
    || (mCreature = ComponentOfTypeHK->mCreature) == 0i64
    || !mCreature->mPose.mRigHandle.mData
    || (BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::symbip01Head.mUID), BoneID == -1) )
  {
    m_pTransformNodeComponent = pObject->m_pTransformNodeComponent;
LABEL_17:
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    goto LABEL_18;
  }
  Translation = Creature::GetTranslation(mCreature, &result, BoneID);
  y = Translation->y;
  z = Translation->z;
  x = Translation->x;
LABEL_18:
  raycastPosition->z = z;
  raycastPosition->y = y;
  raycastPosition->x = x;
}

// File Line: 1117
// RVA: 0x389890
char __fastcall UFG::TargetIsVisible(
        UFG::RayCastData *ray_cast_data,
        UFG::SimObjectGame *to_object,
        UFG::VehicleOccupantComponent **ray_hit_object)
{
  hkpRigidBody *mHavokRigidBody; // rax
  unsigned __int64 m_userData; // rax
  UFG::SimObject *mParent; // rax
  bool v7; // bl
  signed __int16 m_Flags; // cx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax

  if ( !ray_cast_data->hit )
    return 1;
  mHavokRigidBody = ray_cast_data->mHavokRigidBody;
  if ( !mHavokRigidBody )
    return 0;
  m_userData = mHavokRigidBody->m_userData;
  if ( !m_userData )
    return 0;
  mParent = *(UFG::SimObject **)(m_userData + 24);
  if ( mParent )
    mParent = (UFG::SimObject *)mParent->mNode.mParent;
  *ray_hit_object = (UFG::VehicleOccupantComponent *)mParent;
  v7 = mParent == to_object;
  if ( mParent != to_object
    && to_object
    && ((m_Flags = to_object->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 to_object,
                                                                 UFG::CharacterOccupantComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 to_object,
                                                                 UFG::CharacterOccupantComponent::_TypeUID)))
      : (ComponentOfType = (UFG::CharacterOccupantComponent *)to_object->m_Components.p[44].m_pComponent),
        ComponentOfType) )
  {
    return UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType) == *ray_hit_object;
  }
  else
  {
    return v7;
  }
}

// File Line: 1161
// RVA: 0x3533F0
bool __fastcall UFG::DoRaycast(
        UFG::qVector3 *from_position,
        UFG::qVector3 *to_position,
        UFG::SimObject *to_object,
        UFG::qVector3 *last_valid_position,
        UFG::SimObject **ray_hit_object,
        UFG::AsyncRayCastData *async_ray_cast_data,
        bool debug_draw,
        UFG::qColour *debug_colour)
{
  float x; // xmm1_4
  float y; // xmm0_4
  float v14; // xmm1_4
  float z; // xmm0_4
  float v16; // xmm1_4
  Render::DebugDrawContext *Context; // rax
  bool IsVisible; // al
  bool v20; // si
  Render::DebugDrawContext *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  UFG::qVector3 p0; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 p1; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qColour colour; // [rsp+60h] [rbp-A0h] BYREF
  UFG::RayCastData data; // [rsp+70h] [rbp-90h] BYREF

  if ( debug_draw )
  {
    x = from_position->x;
    colour = *debug_colour;
    y = from_position->y;
    p0.x = x;
    v14 = to_position->x;
    p0.y = y;
    p1.y = to_position->y;
    z = to_position->z;
    p1.x = v14;
    v16 = from_position->z + 0.1;
    p1.z = z + 0.1;
    p0.z = v16;
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(
      Context,
      &p0,
      &p1,
      &colour,
      &UFG::qMatrix44::msIdentity,
      (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
      0);
  }
  if ( async_ray_cast_data )
  {
    UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
      UFG::BasePhysicsSystem::mInstance,
      from_position,
      to_position,
      12u,
      async_ray_cast_data->raycastCallback,
      async_ray_cast_data->simComponent.m_pPointer,
      async_ray_cast_data->callbackUserData);
    return 0;
  }
  else
  {
    data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
    data.mOutput.m_extraInfo = -1;
    LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
    data.mInput.m_filterInfo = 0;
    data.mInput.m_userData = 0i64;
    data.mOutput.m_shapeKeyIndex = 0;
    data.mOutput.m_shapeKeys[0] = -1;
    data.mOutput.m_rootCollidable = 0i64;
    data.mDebugName = 0i64;
    data.mCollisionModelName.mUID = -1;
    UFG::RayCastData::Init(&data, from_position, to_position, 0xCu);
    UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
    IsVisible = UFG::TargetIsVisible(&data, to_object, ray_hit_object);
    v20 = IsVisible;
    if ( last_valid_position )
    {
      if ( IsVisible )
      {
        v24 = to_position->y;
        v25 = to_position->z;
        last_valid_position->x = to_position->x;
        last_valid_position->y = v24;
        last_valid_position->z = v25;
      }
      else
      {
        if ( debug_draw )
        {
          colour = *debug_colour;
          p0 = data.point;
          v21 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
          Render::DebugDrawContext::DrawPoint(v21, &p0, &colour, &UFG::qMatrix44::msIdentity, 0i64);
        }
        v22 = data.point.y;
        last_valid_position->x = data.point.x;
        v23 = data.point.z;
        last_valid_position->y = v22;
        last_valid_position->z = v23;
      }
    }
    return v20;
  }
}

// File Line: 1219
// RVA: 0x353730
bool __fastcall UFG::DoRaycast(
        UFG::TransformNodeComponent *from_transform,
        UFG::qVector3 *to_position,
        UFG::SimObject *to_object,
        float z_offset,
        bool use_z_offset_for_destination,
        UFG::qVector3 *last_valid_position,
        UFG::SimObject **ray_hit_object,
        UFG::AsyncRayCastData *async_ray_cast_data,
        bool debug_draw,
        UFG::qColour *debug_colour)
{
  __m128 y_low; // xmm4
  float x; // xmm0_4
  float v16; // xmm2_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v19; // xmm5_4
  UFG::qVector3 to_positiona; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 from_position; // [rsp+50h] [rbp-28h] BYREF

  if ( !from_transform )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(from_transform);
  y_low = (__m128)LODWORD(from_transform->mWorldTransform.v3.y);
  x = to_position->x;
  v16 = from_transform->mWorldTransform.v3.x;
  y = to_position->y;
  z = from_transform->mWorldTransform.v3.z;
  *ray_hit_object = 0i64;
  v19 = to_position->z;
  LODWORD(from_position.y) = y_low.m128_i32[0];
  to_positiona.x = x;
  from_position.x = v16;
  to_positiona.y = y;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)((float)(v16 - x) * (float)(v16 - x)))
                    + (float)((float)(z - v19) * (float)(z - v19));
  if ( _mm_sqrt_ps(y_low).m128_f32[0] > 100.0 )
    return 0;
  from_position.z = z + z_offset;
  if ( !use_z_offset_for_destination )
    z_offset = 0.0;
  to_positiona.z = v19 + z_offset;
  return UFG::DoRaycast(
           &from_position,
           &to_positiona,
           to_object,
           last_valid_position,
           ray_hit_object,
           async_ray_cast_data,
           debug_draw,
           debug_colour);
}

// File Line: 1261
// RVA: 0x353670
bool __fastcall UFG::DoRaycast(
        UFG::TransformNodeComponent *from_transform,
        UFG::TransformNodeComponent *to_transform,
        float z_offset,
        bool use_z_offset_for_destination,
        UFG::qVector3 *last_valid_position,
        UFG::SimObject **ray_hit_object,
        UFG::AsyncRayCastData *async_ray_cast_data,
        bool debug_draw,
        UFG::qColour *debug_colour)
{
  UFG::SimObject *m_pSimObject; // rbx

  if ( !to_transform )
    return 0;
  m_pSimObject = to_transform->m_pSimObject;
  UFG::TransformNodeComponent::UpdateWorldTransform(to_transform);
  return UFG::DoRaycast(
           from_transform,
           (UFG::qVector3 *)&to_transform->mWorldTransform.v3,
           m_pSimObject,
           z_offset,
           use_z_offset_for_destination,
           last_valid_position,
           ray_hit_object,
           async_ray_cast_data,
           debug_draw,
           debug_colour);
}

// File Line: 1287
// RVA: 0x3419B0
void __fastcall UFG::AllAIUpdateAttackTargetsNow(UFG *this)
{
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> **i; // rax

  for ( i = &UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext;
        i != (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> **)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList
                                                                                      - 1336);
        i = &i[168][-84].mNext )
  {
    *((_DWORD *)i + 484) = -915135504;
  }
}

// File Line: 1337
// RVA: 0x35E160
char __fastcall UFG::GetDesiredRanges(
        UFG::SimObjectCVBase *pSimObject,
        float *outMinimumDesired,
        float *outMaximumDesired,
        float *outDesired)
{
  signed __int16 m_Flags; // r10
  UFG::TargetingSystemPedBaseComponent *v8; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v10; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax

  *outMinimumDesired = 0.0;
  *outMaximumDesired = 25.0;
  *outDesired = 10.0;
  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(pSimObject);
  else
    v8 = (UFG::TargetingSystemPedBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    pSimObject,
                                                    UFG::TargetingSystemPedBaseComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    pSimObject,
                                                    UFG::TargetingSystemPedBaseComponent::_TypeUID));
  if ( !v8 )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    return 0;
  v10 = m_pPointer->m_Flags;
  if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0;
  SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)ComponentOfTypeHK);
  *outMinimumDesired = *(float *)(*(_QWORD *)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                                            + 8i64
                                            * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                                            + 8)
                                + 448i64);
  *outMaximumDesired = *(float *)(*(_QWORD *)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                                            + 8i64
                                            * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                                            + 8)
                                + 452i64);
  *outDesired = *(float *)(*(_QWORD *)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                                     + 8i64
                                     * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                                     + 8)
                         + 456i64);
  return 1;
}

// File Line: 1430
// RVA: 0x3608F0
UFG::qVector3 *__fastcall UFG::GetLayerLoadPosition(UFG::qVector3 *result)
{
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx

  y = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  result->z = z;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
  result->x = mCurrentCamera->mCamera.mView.v2.x;
  result->y = mCurrentCamera->mCamera.mView.v2.y;
  result->z = mCurrentCamera->mCamera.mView.v2.z;
  return result;
}

// File Line: 1459
// RVA: 0x363140
UFG::TriggerUpdateContext *__fastcall UFG::GetTriggerUpdateContext(UFG::TriggerUpdateContext *result)
{
  UFG::CharacterOccupantComponent *m_pComponent; // rsi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObjectCharacter *v5; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v7; // xmm0_4
  float v8; // xmm1_4
  UFG::SimObject *mpPlayer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v12; // rcx
  bool v13; // zf
  UFG::SimObjectCVBase *CurrentVehicle; // rax

  m_pComponent = 0i64;
  result->mpPlayer = 0i64;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  result->mPlayerPos.x = UFG::qVector3::msZero.x;
  result->mPlayerPos.y = y;
  result->mPlayerPos.z = z;
  *(_WORD *)&result->mIsPlayerOnFoot = 0;
  result->mIsPlayerOnBike = 0;
  v5 = LocalPlayer;
  result->mpPlayer = LocalPlayer;
  if ( v5 )
  {
    m_pTransformNodeComponent = v5->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v7 = m_pTransformNodeComponent->mWorldTransform.v3.y;
    v8 = m_pTransformNodeComponent->mWorldTransform.v3.z;
    result->mPlayerPos.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    result->mPlayerPos.y = v7;
    result->mPlayerPos.z = v8;
    mpPlayer = result->mpPlayer;
    if ( result->mpPlayer )
    {
      m_Flags = mpPlayer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::CharacterOccupantComponent *)mpPlayer->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)result->mpPlayer,
                                UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v13 = (m_Flags & 0x1000) == 0;
          v12 = (UFG::SimObjectGame *)result->mpPlayer;
          if ( v13 )
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v12, UFG::CharacterOccupantComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CharacterOccupantComponent::_TypeUID);
        }
        m_pComponent = (UFG::CharacterOccupantComponent *)ComponentOfTypeHK;
      }
    }
    result->mIsPlayerInVehicle = m_pComponent != 0i64;
    v13 = m_pComponent == 0i64;
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
        result->mIsPlayerOnBike = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(CurrentVehicle)->m_eSimObjectVehicleType == eSIM_OBJ_VEHICLE_TYPE_BIKE;
      v13 = m_pComponent == 0i64;
    }
    result->mIsPlayerOnFoot = v13;
  }
  return result;
}

