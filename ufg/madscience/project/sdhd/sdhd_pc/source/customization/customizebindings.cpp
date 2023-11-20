// File Line: 36
// RVA: 0x3DE8F0
void __fastcall UFG::ScalingPoseDriver::ScalingPoseDriver(UFG::ScalingPoseDriver *this)
{
  UFG::ScalingPoseDriver *v1; // rdi
  UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject> *v2; // rcx
  const char *v3; // rax

  v1 = this;
  PoseDriver::PoseDriver((PoseDriver *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&UFG::ScalingPoseDriver::`vftable';
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mTemplateInstance.mPrev);
  v3 = UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::GetTypeName(v2);
  v1->mTemplateInstance.mTypeUID = UFG::qStringHash64(v3, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 39
// RVA: 0x3DEAA0
Expression::IMemberMap *__fastcall UFG::ScalingPoseDriver::CreateClone(UFG::ScalingPoseDriver *this)
{
  UFG::ScalingPoseDriver *v1; // rdi
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x58ui64,
         "MemberMap::CreateClone of ScalingPoseDriver",
         0i64,
         1u);
  if ( v2 )
  {
    UFG::ScalingPoseDriver::ScalingPoseDriver((UFG::ScalingPoseDriver *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  *(_QWORD *)(v4 + 8) = v1->mResourceOwner;
  *(_QWORD *)(v4 + 32) = v1->mResourceOwner;
  *(_BYTE *)(v4 + 40) = v1->mActive;
  *(_BYTE *)(v4 + 41) = v1->mDisabled;
  *(_BYTE *)(v4 + 42) = v1->mBreakpoint;
  *(_DWORD *)(v4 + 44) = v1->mName.mUID;
  UFG::qReflectHandleBase::operator=(
    (UFG::qReflectHandleBase *)(v4 + 48),
    (UFG::qReflectHandleBase *)&v1->mTemplateInstance.mPrev);
  return (Expression::IMemberMap *)v4;
}

// File Line: 55
// RVA: 0x3DF420
void __fastcall UFG::ScalingPoseDriver::UpdatePose(UFG::ScalingPoseDriver *this, SkeletalPose *pose)
{
  UFG::qReflectObject *v2; // rax
  SkeletalPose *v3; // r12
  UFG::qTree64Base::BaseNode *v4; // rdx
  Skeleton *v5; // r8
  __int64 v6; // rax
  unsigned int v7; // ebp
  __int64 v8; // r14
  __int64 v9; // rdi
  UFG::qTree64Base::BaseNode *v10; // rsi
  unsigned int v11; // eax
  __int64 v12; // rbx
  __int64 v13; // r13
  UFG::qTree64Base::BaseNode *v14; // r15
  int v15; // eax
  __int64 v16; // r12
  UFG::ScalingPoseDriver *v17; // rax
  UFG::ScalingPreset *v18; // rcx
  const char *v19; // rdx
  UFG::ScalingPreset::RegionValues *v20; // rax
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  UFG::qReflectObject *v24; // rcx
  unsigned int v25; // edx
  float v26; // xmm0_4
  __m128 v27; // xmm4
  __int128 v28; // xmm3
  __m128 v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  int v33; // edi
  __int64 v34; // rdx
  __m128 *v35; // rsi
  __int16 *v36; // rcx
  __int64 v37; // rax
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  signed __int64 v40; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm4
  hkVector4f *v43; // rsi
  hkQsTransformf *v44; // rax
  hkVector4f v45; // xmm0
  Skeleton *v46; // [rsp+20h] [rbp-B28h]
  UFG::qTree64Base::BaseNode *v47; // [rsp+28h] [rbp-B20h]
  hkQsTransformf matrixLS; // [rsp+30h] [rbp-B18h]
  __int128 v49; // [rsp+60h] [rbp-AE8h]
  char v50; // [rsp+70h] [rbp-AD8h]
  UFG::ScalingPoseDriver *v51; // [rsp+B50h] [rbp+8h]
  SkeletalPose *v52; // [rsp+B58h] [rbp+10h]
  unsigned int v53; // [rsp+B60h] [rbp+18h]
  int v54; // [rsp+B68h] [rbp+20h]

  v52 = pose;
  v51 = this;
  v2 = this->mTemplateInstance.mData;
  v3 = pose;
  if ( v2 )
  {
    v4 = v2[1].mBaseNode.mNeighbours[0];
    v47 = v4;
    if ( v4 )
    {
      v5 = v3->mRigHandle.mUFGSkeleton;
      v46 = v5;
      v6 = v5->mhkaSkeleton->m_bones.m_size;
      v54 = v6;
      if ( (signed int)v6 > 0 )
      {
        v49 = *(_OWORD *)_xmm;
        qmemcpy(&v50, &v49, 8 * ((unsigned __int64)(16 * v6 - 9) >> 3));
      }
      v7 = 0;
      v53 = (unsigned int)v4[4].mChildren[0];
      if ( v53 )
      {
        v8 = 0i64;
        v9 = 0i64;
        while ( 1 )
        {
          v10 = v4[4].mParent;
          v11 = (unsigned int)v10[v9].mChildren[1];
          if ( !v11 )
            goto LABEL_38;
          v12 = 0i64;
          v13 = v11;
          do
          {
            v14 = v10[v9].mChildren[0];
            v15 = Skeleton::GetBoneID(v3->mRigHandle.mUFGSkeleton, *(_DWORD *)((char *)&v14->mUID + v12 + 4));
            v16 = v15;
            if ( v15 < 0 )
              goto LABEL_36;
            v17 = v51;
            v18 = (UFG::ScalingPreset *)v51->mTemplateInstance.mData[2].vfptr;
            if ( !v18 )
              goto LABEL_17;
            if ( LODWORD(v10[v9].mParent) )
              v19 = (const char *)v10[v9].mUID;
            else
              v19 = &customWorldMapCaption;
            v20 = UFG::ScalingPreset::GetScaleValues(v18, v19);
            if ( !v20 )
            {
              v17 = v51;
LABEL_17:
              v24 = v17->mTemplateInstance.mData;
              v25 = (unsigned int)v24[2].mBaseNode.mChildren[1];
              if ( v25 <= v7 )
                v21 = *(float *)v10[v9].mNeighbours;
              else
                v21 = *(float *)((char *)&v24[2].mBaseNode.mChildren[0]->mUID + v8);
              if ( v25 <= v7 )
                v22 = *(float *)v10[v9].mNeighbours;
              else
                v22 = *(float *)((char *)&v24[2].mBaseNode.mChildren[0]->mUID + v8);
              if ( v25 <= v7 )
                v23 = *(float *)v10[v9].mNeighbours;
              else
                v23 = *(float *)((char *)&v24[2].mBaseNode.mChildren[0]->mUID + v8);
              goto LABEL_26;
            }
            v21 = v20->mScaleX;
            v22 = v20->mScaleY;
            v23 = v20->mScaleZ;
LABEL_26:
            v27 = (__m128)*(unsigned int *)((char *)&v14->mParent + v12);
            v26 = 1.0 - v27.m128_f32[0];
            v29 = (__m128)*(unsigned int *)((char *)&v14->mParent + v12);
            v30 = (__m128)*(unsigned int *)((char *)&v14->mParent + v12);
            v29.m128_f32[0] = v29.m128_f32[0] * v21;
            v27.m128_f32[0] = (float)(v27.m128_f32[0] * v23) + (float)(1.0 - v27.m128_f32[0]);
            v28 = *(_OWORD *)_xmm;
            v29.m128_f32[0] = v29.m128_f32[0] + v26;
            v30.m128_f32[0] = (float)(v30.m128_f32[0] * v22) + v26;
            switch ( *(_DWORD *)((char *)&v14->mUID + v12) )
            {
              case 0:
                v31 = (__m128)(unsigned int)FLOAT_1_0;
                goto LABEL_33;
              case 1:
                v28 = (__int128)_mm_unpacklo_ps(_xmm, _mm_unpacklo_ps(v30, (__m128)(unsigned int)FLOAT_1_0));
                break;
              case 2:
                v28 = (__int128)_mm_unpacklo_ps(_mm_unpacklo_ps((__m128)(unsigned int)FLOAT_1_0, v27), _xmm);
                break;
              case 3:
                v28 = (__int128)_mm_unpacklo_ps(_mm_unpacklo_ps(v29, (__m128)(unsigned int)FLOAT_1_0), _xmm);
                break;
              case 4:
                v32 = (__m128)(unsigned int)FLOAT_1_0;
                v31 = v29;
                goto LABEL_34;
              case 5:
                v31 = v29;
LABEL_33:
                v32 = v27;
LABEL_34:
                v28 = (__int128)_mm_unpacklo_ps(
                                  _mm_unpacklo_ps(v31, v32),
                                  _mm_unpacklo_ps(v30, (__m128)(unsigned int)FLOAT_1_0));
                break;
              default:
                break;
            }
            *(&v49 + v16) = v28;
LABEL_36:
            v3 = v52;
            v12 += 12i64;
            --v13;
          }
          while ( v13 );
          v4 = v47;
LABEL_38:
          ++v7;
          ++v9;
          v8 += 4i64;
          if ( v7 >= v53 )
          {
            v5 = v46;
            break;
          }
        }
      }
      v33 = v54 - 1;
      v34 = v54 - 1;
      if ( v54 - 1 >= 0 )
      {
        v35 = (__m128 *)(&v49 + v33);
        v36 = &v5->mhkaSkeleton->m_parentIndices.m_data[v33];
        do
        {
          v37 = *v36;
          if ( (signed int)v37 > 0 )
          {
            v38 = (__m128)(unsigned int)FLOAT_1_0;
            v39 = (__m128)(unsigned int)FLOAT_1_0;
            v40 = 2 * v37;
            v41 = *(__m128 *)((char *)&v49 + 8 * v40);
            v42 = (__m128)(unsigned int)FLOAT_1_0;
            v38.m128_f32[0] = 1.0 / *((float *)&v49 + 2 * v40 + 2);
            v42.m128_f32[0] = 1.0 / v41.m128_f32[0];
            v39.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85));
            *v35 = _mm_mul_ps(
                     _mm_unpacklo_ps(_mm_unpacklo_ps(v42, v38), _mm_unpacklo_ps(v39, (__m128)(unsigned int)FLOAT_1_0)),
                     *v35);
          }
          --v36;
          --v35;
          --v34;
        }
        while ( v34 >= 0 );
      }
      if ( v33 >= 0 )
      {
        v43 = (hkVector4f *)(&v49 + v33);
        do
        {
          v44 = SkeletalPose::GetQsTransformLS(v3, v33);
          matrixLS.m_translation = v44->m_translation;
          v45.m_quad = v43->m_quad;
          matrixLS.m_rotation = v44->m_rotation;
          matrixLS.m_scale = (hkVector4f)v45.m_quad;
          SkeletalPose::SetQsTransformLS(v3, v33--, &matrixLS);
          --v43;
        }
        while ( v33 >= 0 );
      }
      SkeletalPose::Renormalize(v3, 0, 0);
    }
  }
}

// File Line: 166
// RVA: 0x14C8EE0
__int64 dynamic_initializer_for__UFG::ScalingPoseDriver::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ScalingPoseDriver", 0xFFFFFFFF);
  UFG::ScalingPoseDriver::sClassNameUID = result;
  return result;
}

// File Line: 184
// RVA: 0x3DED20
void UFG::CustomizeBindings::InitBindings(void)
{
  UFG::PartCustomizer::sSaveInstanceData = UFG::CustomizeBindings::SaveInstanceData;
  UFG::PartCustomizer::sUpdateCustomizationData = (void (__fastcall *)(UFG::SimObject *, UFG::PartTemplateInstance *))_;
  UFG::PartCustomizer::sCustomizeComplete = UFG::CustomizeBindings::CustomizeComplete;
  UFG::PartCustomizer::sConfigureParts = UFG::CustomizeBindings::ConfigureParts;
  UFG::PartCustomizer::sQueueCompositeBuild = UFG::CustomizeBindings::QueueCompositeBuild;
  UFG::PartCustomizer::sSetCameraOperation = (void (__fastcall *)(UFG::SimObject *, UFG::qReflectObject *))_;
  UFG::PartCustomizer::sGetAvailableParts = UFG::CustomizeBindings::GetAvailableParts;
}

// File Line: 225
// RVA: 0x3DF370
void __fastcall UFG::CustomizeBindings::SaveInstanceData(UFG::SimObject *sim_object, UFG::PartTemplateInstance *templateInstance)
{
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::PersistentData::Binary binary; // [rsp+20h] [rbp-18h]
  unsigned int buffer_size; // [rsp+50h] [rbp+18h]
  char *buffer; // [rsp+58h] [rbp+20h]

  buffer = 0i64;
  buffer_size = 0;
  if ( (unsigned __int8)DNA::WriteToBuffer(
                          (UFG::qReflectObject *)&templateInstance->vfptr,
                          "PartTemplate",
                          (const char **)&buffer,
                          &buffer_size) )
  {
    binary.mpBuffer = buffer;
    binary.mSize = buffer_size;
    v2 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v2, 0, &binary);
    v3 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v3, CustomizationVersion, 4);
  }
}

// File Line: 239
// RVA: 0x3DEEB0
void __fastcall UFG::CustomizeBindings::OnResetLocalPlayer(UFG::SimObject *sim_object)
{
  unsigned __int16 v1; // dx
  UFG::CharacterAnimationComponent *v2; // rax
  UFG::CharacterAnimationComponent *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  Creature *v7; // rdx
  UFG::qList<PoseDriver,PoseDriver,1,0> *v8; // rdx
  UFG::qNode<PoseDriver,PoseDriver> **v9; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v10; // rax

  if ( sim_object )
  {
    v1 = sim_object->m_Flags;
    if ( (v1 >> 14) & 1 )
    {
      v2 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)sim_object);
    }
    else if ( (v1 & 0x8000u) == 0 )
    {
      if ( (v1 >> 13) & 1 )
        v2 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)sim_object);
      else
        v2 = (UFG::CharacterAnimationComponent *)((v1 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)sim_object,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(sim_object, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v2 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)sim_object);
    }
    v3 = v2;
    if ( v2 )
    {
      if ( UFG::CustomizeBindings::sCustomization )
      {
        v4 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "IMemberMap", 0i64, 1u);
        if ( v4 )
        {
          UFG::ScalingPoseDriver::ScalingPoseDriver((UFG::ScalingPoseDriver *)v4);
          v6 = v5;
        }
        else
        {
          v6 = 0i64;
        }
        UFG::qReflectHandleBase::Init(
          (UFG::qReflectHandleBase *)(v6 + 48),
          *(_QWORD *)(v6 + 64),
          UFG::CustomizeBindings::sCustomization->mBaseNode.mUID);
        v7 = v3->mCreature;
        if ( v7 )
        {
          v8 = &v7->mPoseDrivers;
          v9 = (UFG::qNode<PoseDriver,PoseDriver> **)(v6 + 16);
          v10 = v8->mNode.mPrev;
          v10->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)(v6 + 16);
          *v9 = v10;
          v9[1] = &v8->mNode;
          v8->mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)(v6 + 16);
        }
      }
    }
  }
}

// File Line: 269
// RVA: 0x3DE9C0
void __fastcall UFG::CustomizeBindings::ConfigureParts(UFG::SimObject *sim_object, UFG::PartTemplateInstance *templateInstance)
{
  UFG::PartTemplateInstance *v2; // rsi
  unsigned __int16 v3; // dx
  UFG::StreamedResourceComponent *v4; // rdi
  UFG::SimComponent *v5; // rax
  unsigned int v6; // ebx
  signed __int64 v7; // r8
  UFG::PartDefinition *v8; // rdx

  if ( sim_object )
  {
    v2 = templateInstance;
    v3 = sim_object->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::StreamedResourceComponent *)sim_object->m_Components.p[10].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::StreamedResourceComponent *)sim_object->m_Components.p[7].m_pComponent;
      }
      else
      {
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)sim_object,
                                UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                              sim_object,
                                                                              UFG::StreamedResourceComponent::_TypeUID);
        v4 = (UFG::StreamedResourceComponent *)v5;
      }
    }
    else
    {
      v4 = (UFG::StreamedResourceComponent *)sim_object->m_Components.p[10].m_pComponent;
    }
    if ( v4 )
    {
      UFG::StreamedResourceComponent::ClearResources(v4);
      UFG::StreamedResourceComponent::ResetResources(v4);
      v6 = 0;
      if ( v2->mSlots.mData.mNumItems )
      {
        do
        {
          v7 = (signed __int64)&v2->mSlots.mData.mItems[v6];
          v8 = *(UFG::PartDefinition **)(v7 + 40);
          if ( v8 )
            UFG::StreamedResourceComponent::AddPart(v4, v8, (UFG::qSymbolUC *)(v7 + 48));
          ++v6;
        }
        while ( v6 < v2->mSlots.mData.mNumItems );
      }
    }
  }
}

// File Line: 288
// RVA: 0x3DF330
void __fastcall UFG::CustomizeBindings::QueueCompositeBuild(UFG::SimObject *sim_object, bool reset_textures, UFG::PartTemplateInstance *templateInstance)
{
  UFG::PartCompositeBuilder *v3; // rax
  UFG::PartCompositeBuilder::CompositeBuildParams buildParams; // [rsp+20h] [rbp-28h]

  buildParams.mCallbackParam = sim_object;
  buildParams.mDefinition = templateInstance;
  buildParams.mCallback = UFG::CustomizeBindings::OnCompositeFinished;
  buildParams.mResetTextures = reset_textures;
  v3 = UFG::PartCompositeBuilder::Instance();
  UFG::PartCompositeBuilder::SubmitCompositeBuild(v3, &buildParams);
}

// File Line: 312
// RVA: 0x3DEB40
void __fastcall UFG::CustomizeBindings::CustomizeComplete(UFG::SimObject *sim_object, UFG::PartTemplateInstance *templateInstance)
{
  UFG::GameSaveLoad *v2; // rax

  v2 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SaveAutoGameSlot(v2);
}

// File Line: 321
// RVA: 0x3DF3E0
bool __fastcall UFG::SortPartsByName(UFG::PartDefinition *const *a, UFG::PartDefinition *const *b)
{
  UFG::qReflectObject **v2; // rbx
  char *v3; // rdi
  char *v4; // rax

  v2 = (UFG::qReflectObject **)a;
  v3 = UFG::qReflectObject::GetName(*(UFG::qReflectObject **)b);
  v4 = UFG::qReflectObject::GetName(*v2);
  return (signed int)UFG::qStringCompare(v4, v3, -1) < 0;
}

// File Line: 326
// RVA: 0x3DEB60
void __fastcall UFG::CustomizeBindings::GetAvailableParts(UFG::qArray<UFG::PartDefinition *,0> *parts, UFG::qSymbolUC *slot_name)
{
  UFG::qSymbolUC *v2; // r13
  UFG::qArray<UFG::PartDefinition *,0> *v3; // rdi
  const char *v4; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *v7; // rax
  UFG::qTree64Base *v8; // r12
  UFG::qTree64Base *v9; // rax
  signed __int64 v10; // rbp
  __int64 v11; // r15
  unsigned int v12; // ebx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::PartDefinition **v17; // r14
  signed __int64 v18; // r9
  signed __int64 v19; // r8
  UFG::PartDefinition **v20; // rax
  UFG::qTree64Base *v21; // rax

  v2 = slot_name;
  v3 = parts;
  v4 = UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::GetStaticTypeName((UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject> *)parts);
  v5 = UFG::qStringHash64(v4, 0xFFFFFFFFFFFFFFFFui64);
  v6 = UFG::qReflectWarehouse::Instance();
  v7 = UFG::qReflectWarehouse::GetInventory(v6, v5);
  v8 = &v7->mItems.mTree;
  v9 = UFG::qTree64Base::GetHead(&v7->mItems.mTree);
  if ( v9 )
  {
    v10 = (signed __int64)&v9[-1].mCount;
    if ( v9 != (UFG::qTree64Base *)8 )
    {
      do
      {
        if ( *(_DWORD *)(v10 + 96) == v2->mUID )
        {
          v11 = v3->size;
          v12 = v3->capacity;
          v13 = v11 + 1;
          if ( (signed int)v11 + 1 > v12 )
          {
            if ( v12 )
              v14 = 2 * v12;
            else
              v14 = 1;
            for ( ; v14 < v13; v14 *= 2 )
              ;
            if ( v14 <= 2 )
              v14 = 2;
            if ( v14 - v13 > 0x10000 )
              v14 = v11 + 65537;
            if ( v14 != (_DWORD)v11 )
            {
              v15 = 8i64 * v14;
              if ( !is_mul_ok(v14, 8ui64) )
                v15 = -1i64;
              v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
              v17 = (UFG::PartDefinition **)v16;
              if ( v3->p )
              {
                v18 = 0i64;
                if ( v3->size )
                {
                  do
                  {
                    v19 = v18;
                    v18 = (unsigned int)(v18 + 1);
                    v16[v19] = (UFG::allocator::free_link)v3->p[v19];
                  }
                  while ( (unsigned int)v18 < v3->size );
                }
                operator delete[](v3->p);
              }
              v3->p = v17;
              v3->capacity = v14;
            }
          }
          v20 = v3->p;
          v3->size = v13;
          v20[v11] = (UFG::PartDefinition *)v10;
        }
        v21 = UFG::qTree64Base::GetNext(v8, (UFG::qTree64Base::BaseNode *)(v10 + 8));
        if ( !v21 )
          break;
        v10 = (signed __int64)&v21[-1].mCount;
      }
      while ( v21 != (UFG::qTree64Base *)8 );
    }
  }
  UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
    (UFG::qPropertySet **)v3->p,
    (UFG::qPropertySet **)&v3->p[(signed int)v3->size - 1i64],
    (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::SortPartsByName);
}

// File Line: 371
// RVA: 0x3DED90
void __fastcall UFG::CustomizeBindings::OnCompositeFinished(UFG::PartTemplateInstance *instance, void *user_data)
{
  UFG::SimObjectGame *v2; // rbx
  unsigned __int16 v3; // dx
  UFG::PartTemplateInstance *v4; // rsi
  UFG::SimComponent *v5; // rdi
  UFG::SimComponent *v6; // rax
  unsigned __int16 v7; // cx
  UFG::StreamedResourceComponent *v8; // rax

  if ( user_data )
  {
    v2 = (UFG::SimObjectGame *)user_data;
    v3 = *((_WORD *)user_data + 38);
    v4 = instance;
    if ( (v3 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[14].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = v2->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v3 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::CompositeDrawableComponent::_TypeUID);
        v5 = v6;
      }
    }
    else
    {
      v5 = v2->m_Components.p[14].m_pComponent;
    }
    v7 = v2->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::StreamedResourceComponent *)v2->m_Components.p[7].m_pComponent;
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    if ( v5 )
    {
      if ( v8 )
        UFG::StreamedResourceComponent::UpdateMaterialModifiers(
          v8,
          (Illusion::MaterialModifierParams<10> *)&v5[1].m_BoundComponentHandles,
          v4);
    }
  }
}

// File Line: 481
// RVA: 0x14C9E20
__int64 dynamic_initializer_for__gRigsHandle__()
{
  gRigsHandle.mCallback = 0i64;
  gRigsHandle.mCallbackParam = 0i64;
  gRigsHandle.mImpl = 0i64;
  *(_DWORD *)&gRigsHandle.mFlags = 536870915;
  gRigsHandle._mTargetState.mValue = 1;
  return atexit(dynamic_atexit_destructor_for__gRigsHandle__);
}

// File Line: 482
// RVA: 0x14C9DD0
__int64 dynamic_initializer_for__gPhysicsHandle__()
{
  gPhysicsHandle.mCallback = 0i64;
  gPhysicsHandle.mCallbackParam = 0i64;
  gPhysicsHandle.mImpl = 0i64;
  *(_DWORD *)&gPhysicsHandle.mFlags = 536870915;
  gPhysicsHandle._mTargetState.mValue = 1;
  return atexit(dynamic_atexit_destructor_for__gPhysicsHandle__);
}

// File Line: 483
// RVA: 0x14C9D80
__int64 dynamic_initializer_for__gDatabaseHandle__()
{
  gDatabaseHandle.mCallback = 0i64;
  gDatabaseHandle.mCallbackParam = 0i64;
  gDatabaseHandle.mImpl = 0i64;
  *(_DWORD *)&gDatabaseHandle.mFlags = 536870915;
  gDatabaseHandle._mTargetState.mValue = 1;
  return atexit(dynamic_atexit_destructor_for__gDatabaseHandle__);
}

// File Line: 494
// RVA: 0x3DEFF0
void PartDatabase_LoadDatabase(void)
{
  if ( UFG::StreamFileWrapper::FileExists(PART_DATABASE) )
    UFG::DataStreamer::QueueStream(
      &gDatabaseHandle,
      PART_DATABASE,
      DATA_PARTSDB_RESOURCE,
      DEFAULT_PRIORITY,
      7u,
      0i64,
      0i64);
}

// File Line: 502
// RVA: 0x3DF290
void PartDatabase_ReleaseDatabase(void)
{
  UFG::DataStreamer::ReleaseStream(&gRigsHandle);
  UFG::DataStreamer::ReleaseStream(&gPhysicsHandle);
  UFG::DataStreamer::ReleaseStream(&gDatabaseHandle);
}

// File Line: 509
// RVA: 0x3DF080
void __fastcall PartDatabase_QueryPoolSize(unsigned int *mainMemory, unsigned int *textureMemory)
{
  unsigned int *v2; // rdi

  v2 = textureMemory;
  *mainMemory = g_HK_PartsDBMemoryPoolSize
              + g_HK_TrueCrowdMemoryPoolSize
              - (((unsigned __int64)UFG::StreamFileWrapper::GetAllocationSize(PART_DATABASE) + 4095) & 0xFFFFF000);
  *v2 = g_HK_TrueCrowdTexturePoolSize + g_HK_PartsDBTexturePoolSize;
}

// File Line: 517
// RVA: 0x3DF070
__int64 __fastcall PartDatabase_QueryFileSize(const char *filename)
{
  return UFG::StreamFileWrapper::GetAllocationSize(filename);
}

// File Line: 522
// RVA: 0x3DF040
void __fastcall PartDatabase_PartHasBeenLoaded(UFG::DataStreamer::Handle *handle, UFG::PartRequest *callbackParam)
{
  UFG::PartRequest *v2; // rbx
  UFG::PartDatabase *v3; // rax

  ++callbackParam->mLoadCount;
  v2 = callbackParam;
  if ( callbackParam->mLoadCount == 2 )
  {
    v3 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::OnStreamingComplete(v3, v2);
  }
}

// File Line: 534
// RVA: 0x3DF0E0
_BOOL8 __fastcall PartDatabase_QueueStream(UFG::PartRequest *pRequest)
{
  UFG::PartRequest *callbackParam; // rsi
  UFG::DataStreamer::PRIORITY v2; // ebx
  int v3; // eax
  int v4; // eax
  UFG::allocator::free_link *v5; // rax
  char v6; // bp
  UFG::DataStreamer::Handle *v7; // rax
  bool v8; // bl
  UFG::qString v10; // [rsp+48h] [rbp-80h]
  UFG::qString result; // [rsp+70h] [rbp-58h]

  callbackParam = pRequest;
  v2 = 0x2000;
  v3 = (unsigned __int64)UFG::PartRequest::GetHighestBucket(pRequest) - 1;
  if ( v3 && (v4 = v3 - 1) != 0 )
  {
    if ( v4 == 1 )
      v2 = 12286;
  }
  else
  {
    v2 = 12287;
  }
  UFG::PartDefinition::GetModelFileName((UFG::PartDefinition *)callbackParam->mPartDefHandle.mData, &result);
  v5 = UFG::qMalloc(0x30ui64, "PartDatabase_QueueStream", 0i64);
  if ( v5 )
  {
    v5->mNext = v5;
    v5[1].mNext = v5;
    v5[2].mNext = 0i64;
    v5[3].mNext = 0i64;
    v5[4].mNext = 0i64;
    LODWORD(v5[5].mNext) = 536870915;
    WORD2(v5[5].mNext) = 1;
  }
  else
  {
    v5 = 0i64;
  }
  callbackParam->mModelDataStreamerHandle = v5;
  v6 = UFG::DataStreamer::QueueStream(
         (UFG::DataStreamer::Handle *)v5,
         result.mData,
         gStreamingPoolId,
         v2,
         0,
         (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))PartDatabase_PartHasBeenLoaded,
         callbackParam);
  UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)callbackParam->mPartDefHandle.mData, &v10);
  v7 = (UFG::DataStreamer::Handle *)UFG::qMalloc(0x30ui64, "PartDatabase_QueueStream", 0i64);
  if ( v7 )
  {
    v7->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v7->mPrev;
    v7->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v7->mPrev;
    v7->mCallback = 0i64;
    v7->mCallbackParam = 0i64;
    v7->mImpl = 0i64;
    *(_DWORD *)&v7->mFlags = 0x20000003;
    v7->_mTargetState.mValue = 1;
  }
  else
  {
    v7 = 0i64;
  }
  callbackParam->mTextureDataStreamerHandle = v7;
  v8 = v6
    && UFG::DataStreamer::QueueStream(
         v7,
         v10.mData,
         gStreamingPoolId,
         v2,
         0,
         (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))PartDatabase_PartHasBeenLoaded,
         callbackParam);
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&result);
  return v8;
}

// File Line: 581
// RVA: 0x3DF2C0
void __fastcall PartDatabase_ReleaseStream(UFG::PartRequest *pRequest)
{
  UFG::DataStreamer::Handle *v1; // rdi
  UFG::PartRequest *v2; // rbx
  UFG::DataStreamer::Handle *v3; // rdi

  v1 = (UFG::DataStreamer::Handle *)pRequest->mModelDataStreamerHandle;
  v2 = pRequest;
  UFG::DataStreamer::ReleaseStream((UFG::DataStreamer::Handle *)pRequest->mModelDataStreamerHandle);
  if ( v1 )
  {
    UFG::DataStreamer::Handle::~Handle(v1);
    operator delete[](v1);
  }
  v3 = (UFG::DataStreamer::Handle *)v2->mTextureDataStreamerHandle;
  v2->mModelDataStreamerHandle = 0i64;
  UFG::DataStreamer::ReleaseStream(v3);
  if ( v3 )
  {
    UFG::DataStreamer::Handle::~Handle(v3);
    operator delete[](v3);
  }
  v2->mTextureDataStreamerHandle = 0i64;
}

// File Line: 594
// RVA: 0x3DEFC0
char __fastcall PartDatabase_IsStreamingStalled()
{
  UFG::StreamingMemory::DATA_TYPE dataTypes; // [rsp+30h] [rbp+8h]
  UFG::StreamingMemory::DATA_TYPE v2; // [rsp+34h] [rbp+Ch]

  dataTypes = gStreamingPoolId;
  v2 = gStreamingPoolIdVRam;
  return UFG::DataStreamer::IsStalled(&dataTypes, 2u);
}

