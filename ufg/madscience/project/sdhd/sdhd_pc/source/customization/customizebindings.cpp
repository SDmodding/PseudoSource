// File Line: 36
// RVA: 0x3DE8F0
void __fastcall UFG::ScalingPoseDriver::ScalingPoseDriver(UFG::ScalingPoseDriver *this)
{
  UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject> *v2; // rcx
  const char *TypeName; // rax

  PoseDriver::PoseDriver(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&UFG::ScalingPoseDriver::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mTemplateInstance);
  TypeName = UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::GetTypeName(v2);
  this->mTemplateInstance.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 39
// RVA: 0x3DEAA0
Expression::IMemberMap *__fastcall UFG::ScalingPoseDriver::CreateClone(UFG::ScalingPoseDriver *this)
{
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx

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
  *(_QWORD *)(v4 + 8) = this->PoseDriver::Expression::IMemberMap::mResourceOwner;
  *(_QWORD *)(v4 + 32) = this->PoseDriver::mResourceOwner;
  *(_BYTE *)(v4 + 40) = this->mActive;
  *(_BYTE *)(v4 + 41) = this->mDisabled;
  *(_BYTE *)(v4 + 42) = this->mBreakpoint;
  *(_DWORD *)(v4 + 44) = this->mName.mUID;
  UFG::qReflectHandleBase::operator=((UFG::qReflectHandleBase *)(v4 + 48), &this->mTemplateInstance);
  return (Expression::IMemberMap *)v4;
}

// File Line: 55
// RVA: 0x3DF420
void __fastcall UFG::ScalingPoseDriver::UpdatePose(UFG::ScalingPoseDriver *this, SkeletalPose *pose)
{
  UFG::qReflectObject *mData; // rax
  SkeletalPose *v3; // r12
  UFG::qTree64Base::BaseNode *v4; // rdx
  Skeleton *mUFGSkeleton; // r8
  __int64 m_size; // rax
  unsigned int v7; // ebp
  __int64 v8; // r14
  __int64 v9; // rdi
  UFG::qTree64Base::BaseNode *mParent; // rsi
  unsigned int v11; // eax
  __int64 v12; // rbx
  __int64 v13; // r13
  UFG::qTree64Base::BaseNode *v14; // r15
  int BoneID; // eax
  __int64 v16; // r12
  UFG::ScalingPoseDriver *v17; // rax
  UFG::qReflectObjectVtbl *vfptr; // rcx
  const char *mUID; // rdx
  UFG::ScalingPreset::RegionValues *ScaleValues; // rax
  float mScaleX; // xmm3_4
  float mScaleY; // xmm2_4
  float mScaleZ; // xmm1_4
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
  __int64 v40; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm4
  hkVector4f *v43; // rsi
  hkQsTransformf *QsTransformLS; // rax
  hkVector4f v45; // xmm0
  Skeleton *v46; // [rsp+20h] [rbp-B28h]
  UFG::qTree64Base::BaseNode *v47; // [rsp+28h] [rbp-B20h]
  hkQsTransformf matrixLS; // [rsp+30h] [rbp-B18h] BYREF
  __int128 v49; // [rsp+60h] [rbp-AE8h] BYREF
  char v50[2672]; // [rsp+70h] [rbp-AD8h] BYREF
  unsigned int v53; // [rsp+B60h] [rbp+18h]
  int v54; // [rsp+B68h] [rbp+20h]

  mData = this->mTemplateInstance.mData;
  v3 = pose;
  if ( mData )
  {
    v4 = mData[1].mBaseNode.mNeighbours[0];
    v47 = v4;
    if ( v4 )
    {
      mUFGSkeleton = v3->mRigHandle.mUFGSkeleton;
      v46 = mUFGSkeleton;
      m_size = mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
      v54 = m_size;
      if ( (int)m_size > 0 )
      {
        v49 = *(_OWORD *)_xmm;
        qmemcpy(v50, &v49, 8 * ((unsigned __int64)(16 * m_size - 9) >> 3));
      }
      v7 = 0;
      v53 = (unsigned int)v4[4].mChildren[0];
      if ( v53 )
      {
        v8 = 0i64;
        v9 = 0i64;
        while ( 1 )
        {
          mParent = v4[4].mParent;
          v11 = (unsigned int)mParent[v9].mChildren[1];
          if ( !v11 )
            goto LABEL_38;
          v12 = 0i64;
          v13 = v11;
          do
          {
            v14 = mParent[v9].mChildren[0];
            BoneID = Skeleton::GetBoneID(v3->mRigHandle.mUFGSkeleton, *(_DWORD *)((char *)&v14->mUID + v12 + 4));
            v16 = BoneID;
            if ( BoneID < 0 )
              goto LABEL_36;
            v17 = this;
            vfptr = this->mTemplateInstance.mData[2].vfptr;
            if ( !vfptr )
              goto LABEL_17;
            if ( LODWORD(mParent[v9].mParent) )
              mUID = (const char *)mParent[v9].mUID;
            else
              mUID = &customCaption;
            ScaleValues = UFG::ScalingPreset::GetScaleValues((UFG::ScalingPreset *)vfptr, mUID);
            if ( !ScaleValues )
            {
              v17 = this;
LABEL_17:
              v24 = v17->mTemplateInstance.mData;
              v25 = (unsigned int)v24[2].mBaseNode.mChildren[1];
              if ( v25 <= v7 )
                mScaleX = *(float *)mParent[v9].mNeighbours;
              else
                mScaleX = *(float *)((char *)&v24[2].mBaseNode.mChildren[0]->mUID + v8);
              if ( v25 <= v7 )
                mScaleY = *(float *)mParent[v9].mNeighbours;
              else
                mScaleY = *(float *)((char *)&v24[2].mBaseNode.mChildren[0]->mUID + v8);
              if ( v25 <= v7 )
                mScaleZ = *(float *)mParent[v9].mNeighbours;
              else
                mScaleZ = *(float *)((char *)&v24[2].mBaseNode.mChildren[0]->mUID + v8);
              goto LABEL_26;
            }
            mScaleX = ScaleValues->mScaleX;
            mScaleY = ScaleValues->mScaleY;
            mScaleZ = ScaleValues->mScaleZ;
LABEL_26:
            v27 = (__m128)*(unsigned int *)((char *)&v14->mParent + v12);
            v26 = 1.0 - v27.m128_f32[0];
            v29 = v27;
            v30 = v27;
            v29.m128_f32[0] = v27.m128_f32[0] * mScaleX;
            v27.m128_f32[0] = (float)(v27.m128_f32[0] * mScaleZ) + (float)(1.0 - v27.m128_f32[0]);
            v28 = *(_OWORD *)_xmm;
            v29.m128_f32[0] = v29.m128_f32[0] + v26;
            v30.m128_f32[0] = (float)(v30.m128_f32[0] * mScaleY) + v26;
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
            *(_OWORD *)&v50[16 * v16 - 16] = v28;
LABEL_36:
            v3 = pose;
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
            mUFGSkeleton = v46;
            break;
          }
        }
      }
      v33 = v54 - 1;
      v34 = v54 - 1;
      if ( v54 - 1 >= 0 )
      {
        v35 = (__m128 *)&v50[16 * v33 - 16];
        v36 = &mUFGSkeleton->mhkaSkeleton->m_parentIndices.m_data[v33];
        do
        {
          v37 = *v36;
          if ( (int)v37 > 0 )
          {
            v38 = (__m128)(unsigned int)FLOAT_1_0;
            v39 = (__m128)(unsigned int)FLOAT_1_0;
            v40 = 2 * v37;
            v41 = *(__m128 *)&v50[8 * v40 - 16];
            v42 = (__m128)(unsigned int)FLOAT_1_0;
            v38.m128_f32[0] = 1.0 / *(float *)&v50[8 * v40 - 8];
            v42.m128_f32[0] = 1.0 / v41.m128_f32[0];
            v39.m128_f32[0] = 1.0 / _mm_shuffle_ps(v41, v41, 85).m128_f32[0];
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
        v43 = (hkVector4f *)&v50[16 * v33 - 16];
        do
        {
          QsTransformLS = SkeletalPose::GetQsTransformLS(v3, v33);
          matrixLS.m_translation = QsTransformLS->m_translation;
          v45.m_quad = v43->m_quad;
          matrixLS.m_rotation = QsTransformLS->m_rotation;
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
  UFG::PartCustomizer::sConfigureParts = (void (__fastcall *)(UFG::SimObject *, UFG::PartTemplateInstance *))UFG::CustomizeBindings::ConfigureParts;
  UFG::PartCustomizer::sQueueCompositeBuild = UFG::CustomizeBindings::QueueCompositeBuild;
  UFG::PartCustomizer::sSetCameraOperation = (void (__fastcall *)(UFG::SimObject *, UFG::qReflectObject *))_;
  UFG::PartCustomizer::sGetAvailableParts = (void (__fastcall *)(UFG::qArray<UFG::PartDefinition *,0> *, UFG::qSymbolUC *))UFG::CustomizeBindings::GetAvailableParts;
}

// File Line: 225
// RVA: 0x3DF370
void __fastcall UFG::CustomizeBindings::SaveInstanceData(
        UFG::SimObject *sim_object,
        UFG::PartTemplateInstance *templateInstance)
{
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::PersistentData::Binary binary; // [rsp+20h] [rbp-18h] BYREF
  unsigned int buffer_size; // [rsp+50h] [rbp+18h] BYREF
  char *buffer; // [rsp+58h] [rbp+20h] BYREF

  buffer = 0i64;
  buffer_size = 0;
  if ( (unsigned __int8)DNA::WriteToBuffer(templateInstance, "PartTemplate", (const char **)&buffer, &buffer_size) )
  {
    binary.mpBuffer = buffer;
    binary.mSize = buffer_size;
    v2 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v2, CustomizationData, &binary);
    v3 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v3, CustomizationVersion, 4);
  }
}

// File Line: 239
// RVA: 0x3DEEB0
void __fastcall UFG::CustomizeBindings::OnResetLocalPlayer(UFG::SimObjectCVBase *sim_object)
{
  signed __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  UFG::CharacterAnimationComponent *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  Creature *mCreature; // rdx
  UFG::qList<PoseDriver,PoseDriver,1,0> *p_mPoseDrivers; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  if ( sim_object )
  {
    m_Flags = sim_object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(sim_object);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)sim_object);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                sim_object,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                sim_object,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    v3 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK && UFG::CustomizeBindings::sCustomization )
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
      mCreature = v3->mCreature;
      if ( mCreature )
      {
        p_mPoseDrivers = &mCreature->mPoseDrivers;
        mPrev = p_mPoseDrivers->mNode.mPrev;
        mPrev->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)(v6 + 16);
        *(_QWORD *)(v6 + 16) = mPrev;
        *(_QWORD *)(v6 + 24) = p_mPoseDrivers;
        p_mPoseDrivers->mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)(v6 + 16);
      }
    }
  }
}

// File Line: 269
// RVA: 0x3DE9C0
void __fastcall UFG::CustomizeBindings::ConfigureParts(
        UFG::SimObjectGame *sim_object,
        UFG::PartTemplateInstance *templateInstance)
{
  signed __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rdi
  UFG::SimComponent *v5; // rax
  unsigned int i; // ebx
  UFG::PartTemplateInstance::SlotEntry *v7; // r8
  UFG::PartDefinition *mData; // rdx

  if ( sim_object )
  {
    m_Flags = sim_object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)sim_object->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)sim_object->m_Components.p[7].m_pComponent;
      }
      else
      {
        v5 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(sim_object, UFG::StreamedResourceComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(sim_object, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)v5;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)sim_object->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::StreamedResourceComponent::ClearResources(m_pComponent);
      UFG::StreamedResourceComponent::ResetResources(m_pComponent);
      for ( i = 0; i < templateInstance->mSlots.mData.mNumItems; ++i )
      {
        v7 = &templateInstance->mSlots.mData.mItems[i];
        mData = (UFG::PartDefinition *)v7->mBasePart.mPart.mData;
        if ( mData )
          UFG::StreamedResourceComponent::AddPart(m_pComponent, mData, &v7->mBasePart.mTextureSet);
      }
    }
  }
}

// File Line: 288
// RVA: 0x3DF330
void __fastcall UFG::CustomizeBindings::QueueCompositeBuild(
        UFG::SimObject *sim_object,
        bool reset_textures,
        UFG::PartTemplateInstance *templateInstance)
{
  UFG::PartCompositeBuilder *v3; // rax
  UFG::PartCompositeBuilder::CompositeBuildParams buildParams; // [rsp+20h] [rbp-28h] BYREF

  buildParams.mCallbackParam = sim_object;
  buildParams.mDefinition = templateInstance;
  buildParams.mCallback = (void (__fastcall *)(UFG::PartTemplateInstance *, void *))UFG::CustomizeBindings::OnCompositeFinished;
  buildParams.mResetTextures = reset_textures;
  v3 = UFG::PartCompositeBuilder::Instance();
  UFG::PartCompositeBuilder::SubmitCompositeBuild(v3, &buildParams);
}

// File Line: 312
// RVA: 0x3DEB40
void __fastcall UFG::CustomizeBindings::CustomizeComplete(
        UFG::SimObject *sim_object,
        UFG::PartTemplateInstance *templateInstance)
{
  UFG::GameSaveLoad *v2; // rax

  v2 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SaveAutoGameSlot(v2);
}

// File Line: 321
// RVA: 0x3DF3E0
bool __fastcall UFG::SortPartsByName(UFG::qReflectObject **a, UFG::qReflectObject **b)
{
  char *Name; // rdi
  char *v4; // rax

  Name = UFG::qReflectObject::GetName(*b);
  v4 = UFG::qReflectObject::GetName(*a);
  return (int)UFG::qStringCompare(v4, Name, -1) < 0;
}

// File Line: 326
// RVA: 0x3DEB60
void __fastcall UFG::CustomizeBindings::GetAvailableParts(
        UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject> *parts,
        UFG::qSymbolUC *slot_name)
{
  const char *StaticTypeName; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // r12
  UFG::qTree64Base *Head; // rax
  UFG::PartDefinition *p_mCount; // rbp
  __int64 vfptr_low; // r15
  unsigned int vfptr_high; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::PartDefinition **v16; // r14
  __int64 i; // r9
  __int64 v18; // r8
  UFG::PartDefinition **mUID; // rax
  UFG::qTree64Base *Next; // rax

  StaticTypeName = UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::GetStaticTypeName(parts);
  v5 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  v6 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v6, v5)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = (UFG::PartDefinition *)&Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        if ( p_mCount->mSlotName.mUID == slot_name->mUID )
        {
          vfptr_low = LODWORD(parts->vfptr);
          vfptr_high = HIDWORD(parts->vfptr);
          v12 = vfptr_low + 1;
          if ( (int)vfptr_low + 1 > vfptr_high )
          {
            if ( vfptr_high )
              v13 = 2 * vfptr_high;
            else
              v13 = 1;
            for ( ; v13 < v12; v13 *= 2 )
              ;
            if ( v13 <= 2 )
              v13 = 2;
            if ( v13 - v12 > 0x10000 )
              v13 = vfptr_low + 65537;
            if ( v13 != (_DWORD)vfptr_low )
            {
              v14 = 8i64 * v13;
              if ( !is_mul_ok(v13, 8ui64) )
                v14 = -1i64;
              v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
              v16 = (UFG::PartDefinition **)v15;
              if ( parts->mBaseNode.mUID )
              {
                for ( i = 0i64;
                      (unsigned int)i < LODWORD(parts->vfptr);
                      v15[v18] = *(UFG::allocator::free_link *)(v18 * 8 + parts->mBaseNode.mUID) )
                {
                  v18 = i;
                  i = (unsigned int)(i + 1);
                }
                operator delete[]((void *)parts->mBaseNode.mUID);
              }
              parts->mBaseNode.mUID = (unsigned __int64)v16;
              HIDWORD(parts->vfptr) = v13;
            }
          }
          mUID = (UFG::PartDefinition **)parts->mBaseNode.mUID;
          LODWORD(parts->vfptr) = v12;
          mUID[vfptr_low] = p_mCount;
        }
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, &p_mCount->mBaseNode);
        if ( !Next )
          break;
        p_mCount = (UFG::PartDefinition *)&Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
  UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
    (UFG::qPropertySet **)parts->mBaseNode.mUID,
    (UFG::qPropertySet **)(parts->mBaseNode.mUID + 8 * (SLODWORD(parts->vfptr) - 1i64)),
    (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::SortPartsByName);
}

// File Line: 371
// RVA: 0x3DED90
void __fastcall UFG::CustomizeBindings::OnCompositeFinished(
        UFG::PartTemplateInstance *instance,
        UFG::SimObjectGame *user_data)
{
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v7; // cx
  UFG::StreamedResourceComponent *ComponentOfType; // rax

  if ( user_data )
  {
    m_Flags = user_data->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = user_data->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = user_data->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                user_data,
                                UFG::CompositeDrawableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(user_data, UFG::CompositeDrawableComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = user_data->m_Components.p[14].m_pComponent;
    }
    v7 = user_data->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      ComponentOfType = (UFG::StreamedResourceComponent *)user_data->m_Components.p[10].m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      if ( (v7 & 0x2000) != 0 )
      {
        ComponentOfType = (UFG::StreamedResourceComponent *)user_data->m_Components.p[7].m_pComponent;
      }
      else if ( (v7 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              user_data,
                                                              UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                              user_data,
                                                              UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = (UFG::StreamedResourceComponent *)user_data->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( ComponentOfType )
        UFG::StreamedResourceComponent::UpdateMaterialModifiers(
          ComponentOfType,
          (Illusion::MaterialModifierParams<10> *)&m_pComponent[1].m_BoundComponentHandles,
          instance);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gRigsHandle__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPhysicsHandle__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDatabaseHandle__);
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
  *mainMemory = g_HK_PartsDBMemoryPoolSize
              + g_HK_TrueCrowdMemoryPoolSize
              - ((UFG::StreamFileWrapper::GetAllocationSize(PART_DATABASE) + 4095) & 0xFFFFF000);
  *textureMemory = g_HK_TrueCrowdTexturePoolSize + g_HK_PartsDBTexturePoolSize;
}

// File Line: 517
// RVA: 0x3DF070
// attributes: thunk
__int64 __fastcall PartDatabase_QueryFileSize(const char *filename)
{
  return UFG::StreamFileWrapper::GetAllocationSize(filename);
}

// File Line: 522
// RVA: 0x3DF040
void __fastcall PartDatabase_PartHasBeenLoaded(UFG::DataStreamer::Handle *handle, UFG::PartRequest *callbackParam)
{
  UFG::PartDatabase *v3; // rax

  if ( ++callbackParam->mLoadCount == 2 )
  {
    v3 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::OnStreamingComplete(v3, callbackParam);
  }
}

// File Line: 534
// RVA: 0x3DF0E0
_BOOL8 __fastcall PartDatabase_QueueStream(UFG::PartRequest *pRequest)
{
  UFG::DataStreamer::PRIORITY v2; // ebx
  int v3; // eax
  int v4; // eax
  UFG::DataStreamer::Handle *v5; // rax
  char v6; // bp
  UFG::DataStreamer::Handle *v7; // rax
  bool v8; // bl
  UFG::qString v10; // [rsp+48h] [rbp-80h] BYREF
  UFG::qString v11; // [rsp+70h] [rbp-58h] BYREF

  v2 = DEFAULT_PRIORITY;
  v3 = UFG::PartRequest::GetHighestBucket(pRequest) - 1;
  if ( v3 && (v4 = v3 - 1) != 0 )
  {
    if ( v4 == 1 )
      v2 = 12286;
  }
  else
  {
    v2 = 12287;
  }
  UFG::PartDefinition::GetModelFileName((UFG::PartDefinition *)pRequest->mPartDefHandle.mData, &v11);
  v5 = (UFG::DataStreamer::Handle *)UFG::qMalloc(0x30ui64, "PartDatabase_QueueStream", 0i64);
  if ( v5 )
  {
    v5->mPrev = v5;
    v5->mNext = v5;
    v5->mCallback = 0i64;
    v5->mCallbackParam = 0i64;
    v5->mImpl = 0i64;
    *(_DWORD *)&v5->mFlags = 536870915;
    v5->_mTargetState.mValue = 1;
  }
  else
  {
    v5 = 0i64;
  }
  pRequest->mModelDataStreamerHandle = v5;
  v6 = UFG::DataStreamer::QueueStream(
         v5,
         v11.mData,
         gStreamingPoolId,
         v2,
         0,
         (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))PartDatabase_PartHasBeenLoaded,
         pRequest);
  UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)pRequest->mPartDefHandle.mData, &v10);
  v7 = (UFG::DataStreamer::Handle *)UFG::qMalloc(0x30ui64, "PartDatabase_QueueStream", 0i64);
  if ( v7 )
  {
    v7->mPrev = v7;
    v7->mNext = v7;
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
  pRequest->mTextureDataStreamerHandle = v7;
  v8 = v6
    && UFG::DataStreamer::QueueStream(
         v7,
         v10.mData,
         gStreamingPoolId,
         v2,
         0,
         (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))PartDatabase_PartHasBeenLoaded,
         pRequest);
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&v11);
  return v8;
}

// File Line: 581
// RVA: 0x3DF2C0
void __fastcall PartDatabase_ReleaseStream(UFG::PartRequest *pRequest)
{
  UFG::DataStreamer::Handle *mModelDataStreamerHandle; // rdi
  UFG::DataStreamer::Handle *mTextureDataStreamerHandle; // rdi

  mModelDataStreamerHandle = (UFG::DataStreamer::Handle *)pRequest->mModelDataStreamerHandle;
  UFG::DataStreamer::ReleaseStream(mModelDataStreamerHandle);
  if ( mModelDataStreamerHandle )
  {
    UFG::DataStreamer::Handle::~Handle(mModelDataStreamerHandle);
    operator delete[](mModelDataStreamerHandle);
  }
  mTextureDataStreamerHandle = (UFG::DataStreamer::Handle *)pRequest->mTextureDataStreamerHandle;
  pRequest->mModelDataStreamerHandle = 0i64;
  UFG::DataStreamer::ReleaseStream(mTextureDataStreamerHandle);
  if ( mTextureDataStreamerHandle )
  {
    UFG::DataStreamer::Handle::~Handle(mTextureDataStreamerHandle);
    operator delete[](mTextureDataStreamerHandle);
  }
  pRequest->mTextureDataStreamerHandle = 0i64;
}

// File Line: 594
// RVA: 0x3DEFC0
char __fastcall PartDatabase_IsStreamingStalled()
{
  UFG::StreamingMemory::DATA_TYPE dataTypes; // [rsp+30h] [rbp+8h] BYREF
  UFG::StreamingMemory::DATA_TYPE v2; // [rsp+34h] [rbp+Ch]

  dataTypes = gStreamingPoolId;
  v2 = gStreamingPoolIdVRam;
  return UFG::DataStreamer::IsStalled(&dataTypes, 2u);
}

