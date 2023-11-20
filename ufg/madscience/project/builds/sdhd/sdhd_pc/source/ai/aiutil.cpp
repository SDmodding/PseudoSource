// File Line: 81
// RVA: 0x361AA0
UFG::SimComponent *__fastcall UFG::GetOriginatingSpawnPoint(UFG::SimObject *pSimObject)
{
  UFG::SceneObjectProperties *v1; // rcx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // edx
  bool v6; // zf

  if ( pSimObject )
  {
    v1 = pSimObject->m_pSceneObj;
    if ( v1 )
    {
      v2 = (UFG::SimObjectGame *)v1->mpOwner.m_pPointer;
      if ( v2 )
      {
        v3 = v2->m_Flags;
        if ( (v3 >> 14) & 1 || (v3 & 0x8000u) != 0 || (v3 >> 13) & 1 )
        {
          v4 = UFG::SpawnPoint::_TypeUID;
        }
        else
        {
          v6 = ((v3 >> 12) & 1) == 0;
          v4 = UFG::SpawnPoint::_TypeUID;
          if ( v6 )
            return UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::SpawnPoint::_TypeUID);
        }
        return UFG::SimObjectGame::GetComponentOfTypeHK(v2, v4);
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
bool __fastcall UFG::IsAnyLocalPlayer(UFG::SimObject *object)
{
  return object && object == (UFG::SimObject *)LocalPlayer;
}

// File Line: 161
// RVA: 0x36A9B0
bool __fastcall UFG::IsFemale(UFG::SimObject *pSimObject)
{
  UFG::SimObjectCharacterPropertiesComponent *v1; // rax
  bool result; // al

  if ( pSimObject
    && (v1 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)pSimObject)) != 0i64 )
  {
    result = v1->m_eGender == 2;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 186
// RVA: 0x37C560
char __fastcall UFG::PlaceOnGround(UFG::qVector3 *out, UFG::qVector3 *position, float height_above_ground, float cast_distance_down, float cast_distance_up)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  UFG::qVector3 *v8; // rbx
  float v9; // xmm1_4
  char result; // al
  float v11; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-118h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-108h]
  UFG::RayCastData data; // [rsp+40h] [rbp-F8h]

  v5 = position->y;
  v6 = position->x;
  v7 = position->z;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_extraInfo = -1;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  rayStart.x = v6;
  rayEnd.x = v6;
  rayStart.y = v5;
  data.mOutput.m_shapeKeys[0] = -1;
  v8 = out;
  rayEnd.y = v5;
  LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
  rayStart.z = v7 + cast_distance_up;
  data.mOutput.m_rootCollidable = 0i64;
  data.mCollisionModelName.mUID = -1;
  rayEnd.z = v7 - cast_distance_down;
  data.mDebugName = "PlaceOnGround";
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v9 = data.point.y;
  result = 1;
  v8->x = data.point.x;
  v11 = data.point.z;
  v8->y = v9;
  v8->z = v11 + height_above_ground;
  return result;
}

// File Line: 208
// RVA: 0x37C400
char __fastcall UFG::PlaceOnGround(UFG::qVector3 *out, UFG::qVector3 *position, float height_above_ground, float cast_distance)
{
  float v4; // xmm4_4
  UFG::qVector3 *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  char result; // al
  float v12; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-118h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-108h]
  UFG::RayCastData data; // [rsp+40h] [rbp-F8h]

  v4 = cast_distance;
  v5 = out;
  if ( cast_distance == 0.0 )
    v4 = FLOAT_3_0;
  v6 = position->y;
  v7 = position->z;
  v8 = position->x;
  v9 = v4 * 0.5;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  rayStart.y = v6;
  rayEnd.y = v6;
  data.mOutput.m_rootCollidable = 0i64;
  rayEnd.z = v7 - v9;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  rayStart.x = v8;
  rayEnd.x = v8;
  rayStart.z = v7 + v9;
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
  v5->x = data.point.x;
  v12 = data.point.z;
  v5->y = v10;
  v5->z = v12 + height_above_ground;
  return result;
}

// File Line: 248
// RVA: 0x3549B0
void UFG::DrawDebugText(int x, int y, UFG::qColour *colour, const char *format, ...)
{
  int v4; // esi
  UFG::qColour *v5; // rbx
  int v6; // edi
  Render::DebugDrawContext *v7; // rax
  char dest; // [rsp+30h] [rbp-2018h]
  va_list va; // [rsp+2070h] [rbp+28h]

  va_start(va, format);
  v4 = x;
  v5 = colour;
  v6 = y;
  if ( (unsigned int)UFG::qVSPrintf(&dest, 0x2000, format, va) )
  {
    v7 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawTextA(v7, v4, v6, v5, &dest);
  }
}

// File Line: 297
// RVA: 0x354A30
void __usercall UFG::DrawDebugText(UFG::TransformNodeComponent *transform@<rcx>, UFG::qColour *colour@<rdx>, const char *format@<r8>, int a4@<eax>, __int64 a5@<r9>, ...)
{
  UFG::qColour *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx
  Render::DebugDrawContext *v7; // rax
  char dest; // [rsp+20h] [rbp-2018h]
  const char *v9; // [rsp+2050h] [rbp+18h]
  __int64 v10; // [rsp+2058h] [rbp+20h]

  v9 = format;
  v10 = a5;
  v5 = colour;
  v6 = transform;
  if ( (unsigned int)UFG::qVSPrintf(&dest, a4 - 40, format, (char *)&v10) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v7 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawText(v7, (UFG::qVector3 *)&v6->mWorldTransform.v3, v5, &dest);
  }
}

// File Line: 322
// RVA: 0x354AB0
void __fastcall UFG::DrawLine(UFG::TransformNodeComponent *transform1, UFG::TransformNodeComponent *transform2, UFG::qColour *colour, float z_offset)
{
  UFG::TransformNodeComponent *v4; // rbx
  UFG::TransformNodeComponent *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  Render::DebugDrawContext *v11; // rax
  UFG::qVector3 p1; // [rsp+40h] [rbp-48h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-38h]
  UFG::qColour coloura; // [rsp+60h] [rbp-28h]

  if ( transform1 )
  {
    v4 = transform2;
    v5 = transform1;
    if ( transform2 )
    {
      coloura = *colour;
      UFG::TransformNodeComponent::UpdateWorldTransform(transform2);
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      v6 = v5->mWorldTransform.v3.y;
      p0.x = v5->mWorldTransform.v3.x;
      v7 = v4->mWorldTransform.v3.x;
      p0.y = v6;
      v8 = v4->mWorldTransform.v3.y;
      p1.x = v7;
      v9 = z_offset + v5->mWorldTransform.v3.z;
      v10 = z_offset + v4->mWorldTransform.v3.z;
      p1.y = v8;
      p0.z = v9;
      p1.z = v10;
      v11 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawLine(
        v11,
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
  UFG::qVector3 *v3; // rsi
  UFG::qVector3 *v4; // rdi
  UFG::qColour *v5; // rbx
  Render::DebugDrawContext *v6; // rax

  v3 = point1;
  v4 = point2;
  v5 = colour;
  v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawLine(v6, v3, v4, v5, 0i64, 0i64, 0);
}

// File Line: 418
// RVA: 0x353860
void __fastcall UFG::DrawBoxScreenSpace(float xpos, float ypos, float height, float width, UFG::qColour *colour)
{
  Render::DebugDrawContext *v5; // rdi
  UFG::qVector3 p1; // [rsp+40h] [rbp-40h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-30h]
  UFG::qVector3 v8; // [rsp+60h] [rbp-20h]
  UFG::qVector3 v9; // [rsp+70h] [rbp-10h]

  p0.x = xpos;
  p0.y = xpos;
  v8.y = xpos;
  p1.x = xpos;
  p0.z = 0.0;
  v8.z = 0.0;
  p1.z = 0.0;
  v8.x = xpos + width;
  p1.y = xpos + height;
  v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawLine(v5, &p0, &p1, colour, 0i64, 0i64, 0);
  v9.x = (float)(p1.x + v8.x) - p0.x;
  v9.y = (float)(v8.y + p1.y) - p0.y;
  v9.z = (float)(p1.z + v8.z) - p0.z;
  Render::DebugDrawContext::DrawLine(v5, &p1, &v9, colour, 0i64, 0i64, 0);
  v9.x = (float)(p1.x + v8.x) - p0.x;
  v9.y = (float)(v8.y + p1.y) - p0.y;
  v9.z = (float)(p1.z + v8.z) - p0.z;
  Render::DebugDrawContext::DrawLine(v5, &v9, &v8, colour, 0i64, 0i64, 0);
  Render::DebugDrawContext::DrawLine(v5, &v8, &p0, colour, 0i64, 0i64, 0);
}

// File Line: 436
// RVA: 0x362550
float __fastcall UFG::GetRandomNumberInRange(float min, float max)
{
  float v2; // xmm7_4
  float result; // xmm0_4

  v2 = min;
  result = max;
  if ( max > v2 )
  {
    result = UFG::qRandom(max - v2, &UFG::qDefaultSeed) + v2;
    if ( result <= v2 )
      result = v2;
    if ( result >= max )
      result = max;
  }
  return result;
}

// File Line: 448
// RVA: 0x362520
__int64 __fastcall UFG::GetRandomNumberInRange(int min, int max)
{
  __int64 result; // rax

  result = (unsigned int)max;
  if ( max > min )
    result = min + (unsigned int)UFG::qRandom((signed int)result - min + 1, &UFG::qDefaultSeed);
  return result;
}

// File Line: 579
// RVA: 0x364ED0
bool __fastcall UFG::HasRangedWeaponEquippedWithAmmo(UFG::TargetingSystemBaseComponent *targeting_system_component)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::GunComponent *v3; // rax
  UFG::GunComponent *v4; // rdi
  int v5; // ebx

  if ( !targeting_system_component )
    return 0;
  v1 = (UFG::SimObjectGame *)targeting_system_component->m_pTargets[(unsigned __int8)targeting_system_component->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
  if ( !v1 )
    return 0;
  v2 = v1->m_Flags;
  if ( (v2 >> 14) & 1 )
  {
    v3 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID);
  }
  else if ( (v2 & 0x8000u) == 0 )
  {
    if ( (v2 >> 13) & 1 )
      v3 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID);
    else
      v3 = (UFG::GunComponent *)((v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v1,
                                                    UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v1->vfptr,
                                                                                     UFG::GunComponent::_TypeUID));
  }
  else
  {
    v3 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID);
  }
  v4 = v3;
  if ( !v3 )
    return 0;
  v5 = UFG::GunComponent::GetTotalAmmo(v3);
  return (signed int)((unsigned __int64)UFG::GunComponent::GetClipAmmo(v4) + v5) > 0;
}

// File Line: 604
// RVA: 0x364E20
bool __fastcall UFG::HasRangedWeapon(UFG::TargetingSystemBaseComponent *targeting_system_component)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  bool result; // al

  result = 0;
  if ( targeting_system_component )
  {
    v1 = (UFG::SimObjectGame *)targeting_system_component->m_pTargets[(unsigned __int8)targeting_system_component->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
    if ( v1 )
    {
      v2 = v1->m_Flags;
      if ( (v2 >> 14) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID);
      }
      else if ( (v2 & 0x8000u) == 0 )
      {
        if ( (v2 >> 13) & 1 )
          v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID);
        else
          v3 = (v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GunComponent::_TypeUID);
      }
      if ( v3 )
        result = 1;
    }
  }
  return result;
}

// File Line: 628
// RVA: 0x36A500
bool __fastcall UFG::IsDowned(UFG::ActionTreeComponent *action_tree_component, UFG::HealthComponent *health_component)
{
  UFG::HealthComponent *v2; // rdi
  UFG::ActionTreeComponent *v3; // rbx
  unsigned int v4; // eax
  ActionController *v5; // rbx

  v2 = health_component;
  v3 = action_tree_component;
  v4 = _S5_7;
  if ( !(_S5_7 & 1) )
  {
    _S5_7 |= 1u;
    downed.mUID = UFG::qStringHashUpper32("Downed", 0xFFFFFFFF);
    v4 = _S5_7;
  }
  if ( !(v4 & 2) )
  {
    _S5_7 = v4 | 2;
    knockOut.mUID = UFG::qStringHashUpper32("KnockOut", 0xFFFFFFFF);
    v4 = _S5_7;
  }
  if ( !(v4 & 4) )
  {
    _S5_7 = v4 | 4;
    ragdoll.mUID = UFG::qStringHashUpper32("Ragdoll", 0xFFFFFFFF);
    v4 = _S5_7;
  }
  if ( !(v4 & 8) )
  {
    _S5_7 = v4 | 8;
    mostUsedIndex_Downed = GetMostUsedIndex(downed.mUID);
    v4 = _S5_7;
  }
  if ( !(v4 & 0x10) )
  {
    _S5_7 = v4 | 0x10;
    mostUsedIndex_KnockOut = GetMostUsedIndex(knockOut.mUID);
    v4 = _S5_7;
  }
  if ( !(v4 & 0x20) )
  {
    _S5_7 = v4 | 0x20;
    mostUsedIndex_RagDoll = GetMostUsedIndex(ragdoll.mUID);
  }
  if ( !v3 || !v2 )
    return 0;
  v5 = &v3->mActionController;
  return ActionController::IsPlaying(v5, &downed, mostUsedIndex_Downed, 0)
      || ActionController::IsPlaying(v5, &knockOut, mostUsedIndex_KnockOut, 0)
      || ActionController::IsPlaying(v5, &ragdoll, mostUsedIndex_RagDoll, 0)
      || v2->m_bIsKnockedOut;
}

// File Line: 670
// RVA: 0x36BB20
unsigned __int8 __fastcall UFG::IsStunned(UFG::ActionTreeComponent *action_tree_component)
{
  UFG::ActionTreeComponent *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned __int8 result; // al

  v1 = action_tree_component;
  v2 = _S7_7;
  if ( !(_S7_7 & 1) )
  {
    _S7_7 |= 1u;
    stunned.mUID = UFG::qStringHashUpper32("Stunned", 0xFFFFFFFF);
    v2 = _S7_7;
  }
  if ( v2 & 2 )
  {
    v3 = mostUsedIndex_Stunned;
  }
  else
  {
    _S7_7 = v2 | 2;
    v3 = GetMostUsedIndex(stunned.mUID);
    mostUsedIndex_Stunned = v3;
  }
  if ( v1 )
    result = ActionController::IsPlaying(&v1->mActionController, &stunned, v3, 0);
  else
    result = 0;
  return result;
}

// File Line: 740
// RVA: 0x362D30
__int64 __fastcall UFG::GetTerrainTypeHash(UFG::CharacterPhysicsComponent *character_physics_component)
{
  UFG::CharacterPhysicsComponent *v1; // rdi
  unsigned int v2; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v3; // rcx
  const char *v4; // rax
  UFG::qReflectHandleBase v6; // [rsp+28h] [rbp-30h]

  v1 = character_physics_component;
  v2 = 0;
  if ( character_physics_component )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v6);
    v4 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v3);
    v6.mTypeUID = UFG::qStringHash64(v4, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v6, v6.mTypeUID, v1->mGroundProperties.groundSurfaceHandleUid);
    if ( v6.mData )
      v2 = (unsigned int)v6.mData[1].mHandles.mNode.mPrev;
    UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
  }
  return v2;
}

// File Line: 760
// RVA: 0x362CF0
signed __int64 __fastcall UFG::GetTerrainTypeEnum(unsigned int terrainTypeHash)
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
char __fastcall UFG::AreCharactersAllied(UFG::SimObject *sim_object_1, UFG::SimObject *sim_object_2)
{
  char v2; // si
  UFG::SimObjectCVBase *v3; // rdi
  UFG::SimObjectCharacterPropertiesComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimObjectCharacterPropertiesComponent *v6; // rax
  UFG::SimObjectCharacterPropertiesComponent *v7; // rdx
  unsigned __int16 v8; // cx
  UFG::SimObjectCharacterPropertiesComponent *v9; // rax
  bool v10; // di
  __int64 v11; // rbx
  __int64 v12; // rbp
  UFG::GameStatTracker *v13; // rdx

  v2 = 0;
  v3 = (UFG::SimObjectCVBase *)sim_object_2;
  if ( sim_object_1 )
  {
    v5 = sim_object_1->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)sim_object_1);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)sim_object_1,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)sim_object_1,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             sim_object_1,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)sim_object_1);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  if ( v3 )
  {
    v8 = v3->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    v7 = v9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v4 || !v7 )
    return 0;
  v10 = ((v4->m_eCharacterType - 15) & 0xFFFFFFEF) == 0 && ((v7->m_eCharacterType - 15) & 0xFFFFFFEF) == 0;
  v11 = v4->m_eFactionClass;
  v12 = v7->m_eFactionClass;
  v13 = UFG::GameStatTracker::Instance();
  if ( v10 || v13->mFactionInterface.mStandings[0][v12 + 39 * v11] == FACTIONSTANDING_ALLIED )
    v2 = 1;
  return v2;
}

// File Line: 847
// RVA: 0x36AAA0
unsigned __int8 __fastcall UFG::IsHostage(UFG::SimObject *simObject)
{
  unsigned __int16 v1; // dx
  UFG::SimComponent *v2; // rbx
  UFG::SimComponent *v3; // rax
  unsigned int v4; // eax
  unsigned int v5; // eax

  if ( !simObject )
    return 0;
  v1 = simObject->m_Flags;
  if ( (v1 >> 14) & 1 )
  {
    v2 = simObject->m_Components.p[7].m_pComponent;
  }
  else if ( (v1 & 0x8000u) == 0 )
  {
    if ( (v1 >> 13) & 1 )
    {
      v2 = simObject->m_Components.p[6].m_pComponent;
    }
    else
    {
      v3 = (v1 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)simObject,
                              UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                      simObject,
                                                                      UFG::ActionTreeComponent::_TypeUID);
      v2 = v3;
    }
  }
  else
  {
    v2 = simObject->m_Components.p[7].m_pComponent;
  }
  if ( !v2 )
    return 0;
  v4 = _S9_6;
  if ( !(_S9_6 & 1) )
  {
    _S9_6 |= 1u;
    hostage.mUID = UFG::qStringHashUpper32("Hostage", 0xFFFFFFFF);
    v4 = _S9_6;
  }
  if ( v4 & 2 )
  {
    v5 = mostUsedIndex_hostage;
  }
  else
  {
    _S9_6 = v4 | 2;
    v5 = GetMostUsedIndex(hostage.mUID);
    mostUsedIndex_hostage = v5;
  }
  return ActionController::IsPlaying((ActionController *)&v2[3], &hostage, v5, 1);
}

// File Line: 865
// RVA: 0x36B450
bool __fastcall UFG::IsKnockedOut(UFG::SimObject *simObject)
{
  unsigned __int16 v1; // dx
  UFG::SimComponent *v2; // rax
  bool result; // al

  if ( simObject
    && ((v1 = simObject->m_Flags, !((v1 >> 14) & 1)) ? ((v1 & 0x8000u) == 0 ? (!((v1 >> 13) & 1) ? (!((v1 >> 12) & 1) ? (v2 = UFG::SimObject::GetComponentOfType(simObject, UFG::HealthComponent::_TypeUID)) : (v2 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::HealthComponent::_TypeUID))) : (v2 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::HealthComponent::_TypeUID))) : (v2 = simObject->m_Components.p[6].m_pComponent)) : (v2 = simObject->m_Components.p[6].m_pComponent),
        v2) )
  {
    result = BYTE4(v2[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 881
// RVA: 0x36B3C0
bool __fastcall UFG::IsKilled(UFG::SimObject *simObject)
{
  unsigned __int16 v1; // dx
  UFG::HealthComponent *v2; // rax
  bool result; // al

  if ( simObject
    && ((v1 = simObject->m_Flags, !((v1 >> 14) & 1)) ? ((v1 & 0x8000u) == 0 ? (!((v1 >> 13) & 1) ? (!((v1 >> 12) & 1) ? (v2 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(simObject, UFG::HealthComponent::_TypeUID)) : (v2 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::HealthComponent::_TypeUID))) : (v2 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::HealthComponent::_TypeUID))) : (v2 = (UFG::HealthComponent *)simObject->m_Components.p[6].m_pComponent)) : (v2 = (UFG::HealthComponent *)simObject->m_Components.p[6].m_pComponent),
        v2) )
  {
    result = UFG::HealthComponent::GetIsKilled(v2);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 899
// RVA: 0x3634F0
UFG::qVector3 *__fastcall UFG::GetVelocity(UFG::qVector3 *result, UFG::SimObject *simObject)
{
  float v2; // xmm1_4
  UFG::SimObjectGame *v3; // rbx
  UFG::qVector3 *v4; // rdi
  float v5; // xmm0_4
  unsigned __int16 v6; // cx
  UFG::CharacterPhysicsComponent *v7; // rax
  UFG::qVector3 *v8; // rax
  unsigned __int16 v9; // cx
  UFG::PhysicsMoverInterface *v10; // rax
  unsigned __int16 v11; // cx
  UFG::RigidBody *v12; // rax
  float v13; // ecx
  UFG::qVector3 resulta; // [rsp+20h] [rbp-18h]

  v2 = UFG::qVector3::msZero.y;
  v3 = (UFG::SimObjectGame *)simObject;
  v4 = result;
  result->x = UFG::qVector3::msZero.x;
  v5 = UFG::qVector3::msZero.z;
  result->y = v2;
  result->z = v5;
  if ( !simObject )
    return v4;
  v6 = simObject->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = (UFG::CharacterPhysicsComponent *)simObject->m_Components.p[27].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
    {
      v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)simObject,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else if ( (v6 >> 12) & 1 )
    {
      v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)simObject,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                               simObject,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
  }
  else
  {
    v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)simObject,
                                             UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( v7 )
  {
    v8 = UFG::CharacterPhysicsComponent::GetVelocity(v7, &resulta);
LABEL_33:
    v4->x = v8->x;
    v13 = v8->y;
    v4->z = v8->z;
    v4->y = v13;
    return v4;
  }
  v9 = v3->m_Flags;
  if ( !((v9 >> 14) & 1) )
  {
    if ( (v9 & 0x8000u) != 0 )
    {
      v10 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      goto LABEL_20;
    }
    if ( !((v9 >> 13) & 1) )
    {
      if ( (v9 >> 12) & 1 )
        v10 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v3,
                                              UFG::PhysicsMoverInterface::_TypeUID);
      else
        v10 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v3->vfptr,
                                              UFG::PhysicsMoverInterface::_TypeUID);
LABEL_20:
      if ( v10 )
      {
        v8 = UFG::PhysicsMoverInterface::GetVelocity(v10, &resulta);
        goto LABEL_33;
      }
      goto LABEL_22;
    }
  }
LABEL_22:
  v11 = v3->m_Flags;
  if ( (v11 >> 14) & 1 )
  {
    v12 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 13) & 1 )
    {
      v12 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v11 >> 12) & 1 )
    {
      v12 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v12 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                (UFG::SimObject *)&v3->vfptr,
                                UFG::RigidBodyComponent::_TypeUID);
    }
  }
  else
  {
    v12 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  if ( v12 )
  {
    v8 = UFG::RigidBody::GetVelocity(v12, &resulta);
    goto LABEL_33;
  }
  return v4;
}peUID);
  }
  

// File Line: 933
// RVA: 0x362150
UFG::qVector3 *__fastcall UFG::GetPosition(UFG::qVector3 *result, UFG::SimObject *simObject)
{
  float v2; // xmm1_4
  UFG::qVector3 *v3; // rbx
  float v4; // xmm0_4
  UFG::TransformNodeComponent *v5; // rdi
  unsigned __int16 v7; // cx
  UFG::RigidBody *v8; // rax
  UFG::qVector3 *v9; // rax
  float v10; // ecx
  UFG::qVector3 resulta; // [rsp+20h] [rbp-18h]

  v2 = UFG::qVector3::msZero.y;
  v3 = result;
  result->x = UFG::qVector3::msZero.x;
  v4 = UFG::qVector3::msZero.z;
  result->y = v2;
  result->z = v4;
  if ( !simObject )
    return result;
  v5 = simObject->m_pTransformNodeComponent;
  if ( v5 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(simObject->m_pTransformNodeComponent);
    v3->x = v5->mWorldTransform.v3.x;
    v3->y = v5->mWorldTransform.v3.y;
    v3->z = v5->mWorldTransform.v3.z;
    return v3;
  }
  v7 = simObject->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                             (UFG::SimObjectGame *)simObject,
                             UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
    {
      v8 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                               (UFG::SimObjectGame *)simObject,
                               UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v7 >> 12) & 1 )
    {
      v8 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                               (UFG::SimObjectGame *)simObject,
                               UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v8 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
    }
  }
  else
  {
    v8 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                             (UFG::SimObjectGame *)simObject,
                             UFG::RigidBodyComponent::_TypeUID);
  }
  if ( !v8 )
    return v3;
  v9 = UFG::RigidBody::GetCentreOfMass(v8, &resulta);
  v3->x = v9->x;
  v10 = v9->y;
  v3->z = v9->z;
  v3->y = v10;
  return v3;
}

// File Line: 1006
// RVA: 0x36BAA0
bool __fastcall UFG::IsSpawning(UFG::SimObject *simObject)
{
  unsigned __int16 v1; // dx
  UFG::ActiveAIEntityComponent *v2; // rax
  bool result; // al

  if ( simObject
    && ((v1 = simObject->m_Flags, !((v1 >> 14) & 1)) ? ((v1 & 0x8000u) == 0 ? (!((v1 >> 13) & 1) ? (!((v1 >> 12) & 1) ? (v2 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(simObject, UFG::ActiveAIEntityComponent::_TypeUID)) : (v2 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::ActiveAIEntityComponent::_TypeUID))) : (v2 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::ActiveAIEntityComponent::_TypeUID))) : (v2 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)simObject))) : (v2 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)simObject)),
        v2) )
  {
    result = v2->m_IsSpawning;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 1024
// RVA: 0x36B9F0
char __fastcall UFG::IsSkippingIntoPOI(UFG::SimObject *pSimObj)
{
  UFG::SimObject *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::SimComponent *v3; // rax

  v1 = pSimObj;
  if ( pSimObj )
  {
    v2 = pSimObj->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[43].m_pComponent;
LABEL_9:
      if ( v3
        && v3[8].m_SafePointerList.mNode.mNext
        && v3[8].m_TypeUID
        && LOBYTE(v3[8].m_Flags)
        && v3[8].m_NameUID != -1 )
      {
        return 1;
      }
      return UFG::IsSpawning(v1);
    }
    if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = v1->m_Components.p[12].m_pComponent;
        goto LABEL_9;
      }
      if ( !((v2 >> 12) & 1) )
      {
        v3 = UFG::SimObject::GetComponentOfType(v1, UFG::InterestPointUserComponent::_TypeUID);
        goto LABEL_9;
      }
    }
    return UFG::IsSpawning(v1);
  }
  return 0;
}

// File Line: 1059
// RVA: 0x36A870
bool __fastcall UFG::IsFacingPosition(UFG::SimObject *pSimObject, UFG::qVector3 *position, float max_angle_degrees)
{
  UFG::qVector3 *v3; // rdi
  float v4; // xmm6_4
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-28h]

  v3 = position;
  v4 = max_angle_degrees;
  if ( !pSimObject )
    return 0;
  v5 = pSimObject->m_pTransformNodeComponent;
  if ( !v5 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
  v6 = v5->mWorldTransform.v0.y;
  v1.x = v5->mWorldTransform.v0.x;
  v7 = v5->mWorldTransform.v0.z;
  v1.y = v6;
  v1.z = v7;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v8 = v3->y - v5->mWorldTransform.v3.y;
  v2.x = v3->x - v5->mWorldTransform.v3.x;
  v9 = v3->z;
  v2.y = v8;
  v2.z = v9 - v5->mWorldTransform.v3.z;
  v10 = (float)(UFG::qAngleBetween(&v1, &v2) * 180.0) * 0.31830987;
  if ( max_angle_degrees < 0.0 )
    v4 = UFG::gFacingThresoldDegrees;
  return v4 > COERCE_FLOAT(LODWORD(v10) & _xmm);
}

// File Line: 1072
// RVA: 0x36A7E0
bool __fastcall UFG::IsFacingDirection(UFG::SimObject *pSimObject, UFG::qVector3 *direction, float max_angle_degrees)
{
  UFG::qVector3 *v3; // rdi
  float v4; // xmm6_4
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm0_4

  v3 = direction;
  v4 = max_angle_degrees;
  if ( !pSimObject )
    return 0;
  v5 = pSimObject->m_pTransformNodeComponent;
  if ( !v5 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
  v6 = (float)(UFG::qAngleBetween((UFG::qVector3 *)&v5->mWorldTransform, v3) * 180.0) * 0.31830987;
  if ( max_angle_degrees < 0.0 )
    v4 = UFG::gFacingThresoldDegrees;
  return v4 > COERCE_FLOAT(LODWORD(v6) & _xmm);
}

// File Line: 1083
// RVA: 0x14B9260
__int64 UFG::_dynamic_initializer_for__symbip01Head__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Head", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symbip01Head, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symbip01Head__);
}

// File Line: 1085
// RVA: 0x34FDC0
void __fastcall UFG::ComputeObjectRaycastPosition(UFG::SimObject *pObject, UFG::qVector3 *raycastPosition)
{
  UFG::qVector3 *v2; // rsi
  UFG::SimObjectCVBase *v3; // rbx
  unsigned __int16 v4; // cx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *v6; // rdi
  int v7; // eax
  UFG::qVector3 *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // eax
  UFG::TransformNodeComponent *v12; // rbx
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v2 = raycastPosition;
  v3 = (UFG::SimObjectCVBase *)pObject;
  if ( !pObject )
  {
    v12 = 0i64;
    goto LABEL_18;
  }
  v4 = pObject->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      v5 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
  }
  if ( !v5
    || (v6 = v5->mCreature) == 0i64
    || !v6->mPose.mRigHandle.mData
    || (v7 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, UFG::symbip01Head.mUID), v7 == -1) )
  {
    v12 = v3->m_pTransformNodeComponent;
LABEL_18:
    UFG::TransformNodeComponent::UpdateWorldTransform(v12);
    v11 = v12->mWorldTransform.v3.x;
    v9 = v12->mWorldTransform.v3.y;
    v10 = v12->mWorldTransform.v3.z;
    goto LABEL_19;
  }
  v8 = Creature::GetTranslation(v6, &result, v7);
  v9 = v8->y;
  v10 = v8->z;
  v11 = v8->x;
LABEL_19:
  v2->z = v10;
  v2->y = v9;
  v2->x = v11;
}

// File Line: 1117
// RVA: 0x389890
bool __fastcall UFG::TargetIsVisible(UFG::RayCastData *ray_cast_data, UFG::SimObject *to_object, UFG::SimObject **ray_hit_object)
{
  UFG::SimObject **v3; // rdi
  hkpRigidBody *v4; // rax
  unsigned __int64 v5; // rax
  UFG::SimObject *v6; // rax
  bool v7; // bl
  unsigned __int16 v8; // cx
  UFG::CharacterOccupantComponent *v9; // rax
  bool result; // al

  v3 = ray_hit_object;
  if ( !ray_cast_data->hit )
    return 1;
  v4 = ray_cast_data->mHavokRigidBody;
  if ( !v4 )
    return 0;
  v5 = v4->m_userData;
  if ( !v5 )
    return 0;
  v6 = *(UFG::SimObject **)(v5 + 24);
  if ( v6 )
    v6 = (UFG::SimObject *)v6->mNode.mParent;
  *ray_hit_object = v6;
  v7 = v6 == to_object;
  if ( v6 != to_object
    && to_object
    && ((v8 = to_object->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(to_object, UFG::CharacterOccupantComponent::_TypeUID)) : (v9 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)to_object, UFG::CharacterOccupantComponent::_TypeUID))) : (v9 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)to_object, UFG::CharacterOccupantComponent::_TypeUID))) : (v9 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)to_object, UFG::CharacterOccupantComponent::_TypeUID))) : (v9 = (UFG::CharacterOccupantComponent *)to_object->m_Components.p[44].m_pComponent),
        v9) )
  {
    result = UFG::CharacterOccupantComponent::GetCurrentVehicle(v9) == (UFG::VehicleOccupantComponent *)*v3;
  }
  else
  {
    result = v7;
  }
  return result;
}

// File Line: 1161
// RVA: 0x3533F0
bool __fastcall UFG::DoRaycast(UFG::qVector3 *from_position, UFG::qVector3 *to_position, UFG::SimObject *to_object, UFG::qVector3 *last_valid_position, UFG::SimObject **ray_hit_object, UFG::AsyncRayCastData *async_ray_cast_data, bool debug_draw, UFG::qColour *debug_colour)
{
  UFG::qVector3 *v8; // rbx
  UFG::SimObject *v9; // r12
  UFG::qVector3 *v10; // rdi
  UFG::qVector3 *v11; // rsi
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  Render::DebugDrawContext *v17; // rax
  bool result; // al
  bool v19; // al
  bool v20; // si
  Render::DebugDrawContext *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  UFG::qVector3 p0; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 p1; // [rsp+50h] [rbp-B0h]
  UFG::qColour colour; // [rsp+60h] [rbp-A0h]
  UFG::RayCastData data; // [rsp+70h] [rbp-90h]

  v8 = last_valid_position;
  v9 = to_object;
  v10 = to_position;
  v11 = from_position;
  if ( debug_draw )
  {
    v12 = from_position->x;
    colour = *debug_colour;
    v13 = from_position->y;
    p0.x = v12;
    v14 = to_position->x;
    p0.y = v13;
    p1.y = to_position->y;
    v15 = to_position->z;
    p1.x = v14;
    v16 = from_position->z + 0.1;
    p1.z = v15 + 0.1;
    p0.z = v16;
    v17 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(
      v17,
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
      v11,
      v10,
      12u,
      async_ray_cast_data->raycastCallback,
      async_ray_cast_data->simComponent.m_pPointer,
      async_ray_cast_data->callbackUserData);
    result = 0;
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
    UFG::RayCastData::Init(&data, v11, v10, 0xCu);
    UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
    v19 = UFG::TargetIsVisible(&data, v9, ray_hit_object);
    v20 = v19;
    if ( v8 )
    {
      if ( v19 )
      {
        v24 = v10->y;
        v25 = v10->z;
        v8->x = v10->x;
        v8->y = v24;
        v8->z = v25;
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
        v8->x = data.point.x;
        v23 = data.point.z;
        v8->y = v22;
        v8->z = v23;
      }
    }
    result = v20;
  }
  return result;
}

// File Line: 1219
// RVA: 0x353730
bool __fastcall UFG::DoRaycast(UFG::TransformNodeComponent *from_transform, UFG::qVector3 *to_position, UFG::SimObject *to_object, float z_offset, bool use_z_offset_for_destination, UFG::qVector3 *last_valid_position, UFG::SimObject **ray_hit_object, UFG::AsyncRayCastData *async_ray_cast_data, bool debug_draw, UFG::qColour *debug_colour)
{
  UFG::SimObject *v10; // rsi
  UFG::qVector3 *v11; // rdi
  float v12; // xmm6_4
  UFG::TransformNodeComponent *v13; // rbx
  __m128 v14; // xmm4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  UFG::qVector3 to_positiona; // [rsp+40h] [rbp-38h]
  UFG::qVector3 from_position; // [rsp+50h] [rbp-28h]

  v10 = to_object;
  v11 = to_position;
  v12 = z_offset;
  v13 = from_transform;
  if ( !from_transform )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(from_transform);
  v14 = (__m128)LODWORD(v13->mWorldTransform.v3.y);
  v15 = v11->x;
  v16 = v13->mWorldTransform.v3.x;
  v17 = v11->y;
  v18 = v13->mWorldTransform.v3.z;
  *ray_hit_object = 0i64;
  v19 = v11->z;
  LODWORD(from_position.y) = v14.m128_i32[0];
  to_positiona.x = v15;
  from_position.x = v16;
  to_positiona.y = v17;
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - v17) * (float)(v14.m128_f32[0] - v17))
                          + (float)((float)(v16 - v15) * (float)(v16 - v15)))
                  + (float)((float)(v18 - v19) * (float)(v18 - v19));
  if ( COERCE_FLOAT(_mm_sqrt_ps(v14)) > 100.0 )
    return 0;
  from_position.z = v18 + v12;
  if ( !use_z_offset_for_destination )
    v12 = 0.0;
  to_positiona.z = v19 + v12;
  return UFG::DoRaycast(
           &from_position,
           &to_positiona,
           v10,
           last_valid_position,
           ray_hit_object,
           async_ray_cast_data,
           debug_draw,
           debug_colour);
}

// File Line: 1261
// RVA: 0x353670
bool __fastcall UFG::DoRaycast(UFG::TransformNodeComponent *from_transform, UFG::TransformNodeComponent *to_transform, float z_offset, bool use_z_offset_for_destination, UFG::qVector3 *last_valid_position, UFG::SimObject **ray_hit_object, UFG::AsyncRayCastData *async_ray_cast_data, bool debug_draw, UFG::qColour *debug_colour)
{
  bool v9; // si
  UFG::TransformNodeComponent *v10; // rdi
  UFG::TransformNodeComponent *v11; // rbp
  UFG::SimObject *v12; // rbx

  v9 = use_z_offset_for_destination;
  v10 = to_transform;
  v11 = from_transform;
  if ( !to_transform )
    return 0;
  v12 = to_transform->m_pSimObject;
  UFG::TransformNodeComponent::UpdateWorldTransform(to_transform);
  return UFG::DoRaycast(
           v11,
           (UFG::qVector3 *)&v10->mWorldTransform.v3,
           v12,
           z_offset,
           v9,
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
char __fastcall UFG::GetDesiredRanges(UFG::SimObject *pSimObject, float *outMinimumDesired, float *outMaximumDesired, float *outDesired)
{
  float *v4; // rbx
  float *v5; // rdi
  float *v6; // rsi
  unsigned __int16 v7; // r10
  UFG::TargetingSystemPedBaseComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  CAkScheduledItem *v12; // rax

  *outMinimumDesired = 0.0;
  *outMaximumDesired = 25.0;
  v4 = outDesired;
  *outDesired = 10.0;
  v5 = outMaximumDesired;
  v6 = outMinimumDesired;
  if ( !pSimObject )
    return 0;
  v7 = pSimObject->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>((UFG::SimObjectCVBase *)pSimObject);
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
      v8 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)pSimObject,
                                                     UFG::TargetingSystemPedBaseComponent::_TypeUID);
    else
      v8 = (UFG::TargetingSystemPedBaseComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)pSimObject,
                                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(pSimObject, UFG::TargetingSystemPedBaseComponent::_TypeUID));
  }
  else
  {
    v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>((UFG::SimObjectCVBase *)pSimObject);
  }
  if ( !v8 )
    return 0;
  v9 = (UFG::SimObjectGame *)v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
  if ( !v9 )
    return 0;
  v10 = v9->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
    else
      v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::GunComponent::_TypeUID);
  }
  else
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
  }
  if ( !v11 )
    return 0;
  v12 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v11);
  *v6 = *(float *)(*(_QWORD *)(*(_QWORD *)&v12[2].m_cmdStop.iRelativeTime
                             + 8i64 * (unsigned int)v12[2].m_cmdPlay.fadeParams.iFadeOffset
                             + 8)
                 + 448i64);
  *v5 = *(float *)(*(_QWORD *)(*(_QWORD *)&v12[2].m_cmdStop.iRelativeTime
                             + 8i64 * (unsigned int)v12[2].m_cmdPlay.fadeParams.iFadeOffset
                             + 8)
                 + 452i64);
  *v4 = *(float *)(*(_QWORD *)(*(_QWORD *)&v12[2].m_cmdStop.iRelativeTime
                             + 8i64 * (unsigned int)v12[2].m_cmdPlay.fadeParams.iFadeOffset
                             + 8)
                 + 456i64);
  return 1;
}

// File Line: 1430
// RVA: 0x3608F0
UFG::qVector3 *__fastcall UFG::GetLayerLoadPosition(UFG::qVector3 *result)
{
  float v1; // xmm1_4
  UFG::qVector3 *v2; // rbx
  float v3; // xmm0_4
  UFG::BaseCameraComponent *v4; // rcx

  v1 = UFG::qVector3::msZero.y;
  v2 = result;
  result->x = UFG::qVector3::msZero.x;
  v3 = UFG::qVector3::msZero.z;
  result->y = v1;
  result->z = v3;
  v4 = UFG::Director::Get()->mCurrentCamera;
  if ( v4 )
    v4 = (UFG::BaseCameraComponent *)((char *)v4 + 80);
  v2->x = v4->mCamera.mView.v2.x;
  v2->y = v4->mCamera.mView.v2.y;
  v2->z = v4->mCamera.mView.v2.z;
  return v2;
}

// File Line: 1459
// RVA: 0x363140
UFG::TriggerUpdateContext *__fastcall UFG::GetTriggerUpdateContext(UFG::TriggerUpdateContext *result)
{
  UFG::CharacterOccupantComponent *v1; // rsi
  UFG::TriggerUpdateContext *v2; // rdi
  float v3; // xmm1_4
  float v4; // xmm2_4
  UFG::SimObjectCharacter *v5; // rax
  UFG::TransformNodeComponent *v6; // rbx
  float v7; // xmm0_4
  float v8; // xmm1_4
  UFG::SimObjectGame *v9; // r8
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  bool v13; // zf
  UFG::SimObjectCVBase *v14; // rax

  v1 = 0i64;
  v2 = result;
  result->mpPlayer = 0i64;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  result->mPlayerPos.x = UFG::qVector3::msZero.x;
  result->mPlayerPos.y = v3;
  result->mPlayerPos.z = v4;
  *(_WORD *)&result->mIsPlayerOnFoot = 0;
  result->mIsPlayerOnBike = 0;
  v5 = LocalPlayer;
  result->mpPlayer = (UFG::SimObject *)&LocalPlayer->vfptr;
  if ( v5 )
  {
    v6 = v5->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5->m_pTransformNodeComponent);
    v7 = v6->mWorldTransform.v3.y;
    v8 = v6->mWorldTransform.v3.z;
    v2->mPlayerPos.x = v6->mWorldTransform.v3.x;
    v2->mPlayerPos.y = v7;
    v2->mPlayerPos.z = v8;
    v9 = (UFG::SimObjectGame *)v2->mpPlayer;
    if ( v2->mpPlayer )
    {
      v10 = v9->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v1 = (UFG::CharacterOccupantComponent *)v9->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)v2->mpPlayer,
                    UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v13 = ((v10 >> 12) & 1) == 0;
            v12 = (UFG::SimObjectGame *)v2->mpPlayer;
            if ( v13 )
              v11 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v12->vfptr,
                      UFG::CharacterOccupantComponent::_TypeUID);
            else
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CharacterOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)v2->mpPlayer,
                  UFG::CharacterOccupantComponent::_TypeUID);
        }
        v1 = (UFG::CharacterOccupantComponent *)v11;
      }
    }
    v2->mIsPlayerInVehicle = v1 != 0i64;
    v13 = v1 == 0i64;
    if ( v1 )
    {
      v14 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v1);
      if ( v14 )
        v2->mIsPlayerOnBike = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v14)->m_eSimObjectVehicleType == 1;
      v13 = v1 == 0i64;
    }
    v2->mIsPlayerOnFoot = v13;
  }
  return v2;
}

