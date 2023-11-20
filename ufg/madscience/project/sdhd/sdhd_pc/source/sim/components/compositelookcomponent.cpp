// File Line: 66
// RVA: 0x154DA20
__int64 dynamic_initializer_for__UFG::CompositeLookComponent::s_CompositeLookComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CompositeLookComponent::s_CompositeLookComponentList__);
}

// File Line: 67
// RVA: 0x154D580
__int64 dynamic_initializer_for__UFG::CompositeLookComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::CompositeLookComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::CompositeLookComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::CompositeLookComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::CompositeLookComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 74
// RVA: 0x57C910
void __fastcall UFG::CompositeLookComponent::CompositeLookComponent(UFG::CompositeLookComponent *this)
{
  UFG::CompositeLookComponent *v1; // rbx
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v2; // rax

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v1->vfptr = (UFG::ICompositeLookVtbl *)&UFG::ICompositeLook::`vftable;
  v1->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v2 = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeLookComponent::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::ICompositeLookVtbl *)&UFG::CompositeLookComponent::`vftable{for `UFG::ICompositeLook};
  v1->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CompositeLookComponent::`vftable{for `UFG::UpdateInterface};
  v1->mColourTints = 0i64;
  v1->mForceTransparencyState = -1;
  v1->mHighlightingMode = 0;
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0>::RebindingComponentHandle<UFG::BaseAnimationComponent,0>(&v1->mAnimationComponent);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::CompositeLookComponent::_CompositeLookComponentTypeUID,
    "CompositeLookComponent");
  v1->mSceneryInstance = 0i64;
}

// File Line: 81
// RVA: 0x58A7F0
UFG::CompositeLookComponent *__fastcall UFG::CompositeLookComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rdi
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::CompositeLookComponent *v6; // rbx
  UFG::CompositeLookComponent *result; // rax
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::CompositeLookComponent *v10; // rax
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v11; // rcx
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v12; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CompositeDrawable::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::CompositeLookComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( v2 || result )
  {
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0xB0ui64, "CompositeLookComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::CompositeLookComponent::CompositeLookComponent((UFG::CompositeLookComponent *)v9);
      v6 = v10;
    }
    v11 = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mPrev;
    v12 = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mPrev;
    v11->mPrev = v12;
    v11->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&UFG::CompositeLookComponent::s_CompositeLookComponentList;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mPrev;
    UFG::SimObjectModifier::SimObjectModifier(&v13, v3->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, (UFG::SimComponent *)&v6->vfptr, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
    result = v6;
  }
  return result;
}

// File Line: 99
// RVA: 0x586490
void __fastcall UFG::CompositeLookComponent::OnAttach(UFG::CompositeLookComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbx
  UFG::CompositeLookComponent *v3; // rsi
  UFG::SimComponent *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  signed __int64 v7; // rax
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *v8; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  CB_SceneryInstance *v13; // rax

  v2 = object;
  v3 = this;
  if ( object )
  {
    v5 = object->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = object->m_Components.p[14].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = object->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)object,
                 UFG::CompositeDrawableComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType(object, UFG::CompositeDrawableComponent::_TypeUID);
        v4 = v6;
      }
    }
    else
    {
      v4 = object->m_Components.p[14].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = (signed __int64)&v3->vfptr;
  if ( !v3 )
    v7 = 0i64;
  v8 = &v3->mAnimationComponent;
  v4[1].m_pSimObject = (UFG::SimObject *)v7;
  if ( v3->mAnimationComponent.m_pSimComponent )
  {
    v9 = v8->mPrev;
    v10 = v3->mAnimationComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v3->mAnimationComponent.m_pSimComponent = 0i64;
LABEL_21:
    v3->mAnimationComponent.m_pSimObject = 0i64;
    v3->mAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mAnimationComponent.mPrev;
    v8->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v8->mPrev;
    goto LABEL_22;
  }
  if ( v3->mAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *)v8->mPrev != v8
     || (UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *)v3->mAnimationComponent.mNext != &v3->mAnimationComponent) )
  {
    v11 = v8->mPrev;
    v12 = v3->mAnimationComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_21;
  }
LABEL_22:
  v3->mAnimationComponent.m_Changed = 1;
  v3->mAnimationComponent.m_pSimObject = v2;
  v3->mAnimationComponent.m_TypeUID = UFG::BaseAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0>::BindInternal<UFG::SimObject>(
    &v3->mAnimationComponent,
    v2);
  v3->mSceneryInstance = (CB_SceneryInstance *)&v4[18].m_TypeUID;
  v3->vfptr->OnUpdateMaterial((UFG::ICompositeLook *)&v3->vfptr, (UFG::CompositeDrawableComponent *)v4);
  v13 = v3->mSceneryInstance;
  v13->Value0[3] = 0.0;
  v13->Mask[3] = 0.0;
}

// File Line: 112
// RVA: 0x586B40
void __fastcall UFG::CompositeLookComponent::OnDetach(UFG::CompositeLookComponent *this)
{
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *v1; // r8
  UFG::CompositeLookComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  v1 = &this->mAnimationComponent;
  v2 = this;
  if ( this->mAnimationComponent.m_pSimComponent )
  {
    v3 = this->mAnimationComponent.mNext;
    v4 = v1->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    this->mAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mAnimationComponent.mPrev;
    this->mAnimationComponent.m_Changed = 1;
    this->mAnimationComponent.m_pSimComponent = 0i64;
    this->mAnimationComponent.m_pSimObject = 0i64;
    this->mSceneryInstance = 0i64;
  }
  else if ( this->mAnimationComponent.m_pSimObject
         && ((UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *)v1->mPrev != v1
          || (UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *)this->mAnimationComponent.mNext != &this->mAnimationComponent) )
  {
    v5 = this->mAnimationComponent.mNext;
    v6 = v1->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimObject = 0i64;
    v2->mSceneryInstance = 0i64;
  }
  else
  {
    this->mAnimationComponent.m_Changed = 1;
    this->mSceneryInstance = 0i64;
  }
}

// File Line: 118
// RVA: 0x5875F0
void __fastcall UFG::CompositeLookComponent::OnReset(UFG::CompositeLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  signed int v3; // er8

  v2 = this->m_BoundComponentHandles.mNode.mNext;
  *(_WORD *)((char *)&this->m_pSimObject + 3) = 255;
  HIDWORD(v2[3].mNext) = 0;
  LODWORD(this->m_BoundComponentHandles.mNode.mNext[2].mPrev) = 0;
  HIDWORD(this->m_BoundComponentHandles.mNode.mNext[2].mNext) = 0;
  v3 = Illusion::gEngine.mFrameCount - 1;
  if ( Render::TransparencySystem::msEnabled )
    LOBYTE(this->m_pSimObject) = 0;
  else
    LOBYTE(this->m_pSimObject) = Render::TransparencySystem::msOpaqueIndex;
  BYTE1(this->m_pSimObject) = Render::TransparencySystem::msOpaqueIndex;
  BYTE2(this->m_pSimObject) = v3 + v3 / 255;
}

// File Line: 130
// RVA: 0x5872D0
void __fastcall UFG::CompositeLookComponent::OnDrawSkin(UFG::CompositeLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::View *view, ModelType::ModelBindingSkin *model_binding, Render::SkinningParams *skinning_params)
{
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::BaseCameraComponent *v8; // rbx
  char *v9; // rax
  UFG::qMatrix44 *v10; // rcx
  char *v11; // rdx
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // xmm2_4
  float v15; // xmm0_4
  unsigned __int64 v16; // rax

  if ( !skinning_params->user_data_1 )
  {
    v5 = (UFG::SimObjectGame *)this[-1].mAnimationComponent.m_pSimComponent;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v5->m_Components.p[9].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = v5->m_Components.p[8].m_pComponent;
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::BaseAnimationComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v7 = v5->m_Components.p[9].m_pComponent;
      }
      if ( v7 )
      {
        if ( HIDWORD(v7[3].vfptr) == 0xA0A883FD )
        {
          v8 = UFG::GetCurrentBaseCamera();
          v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
          v10 = skinning_params->local_transform;
          v11 = v9;
          v12 = v8->mCamera.mTransformation.v3.z - v10->v3.z;
          v13 = v8->mCamera.mTransformation.v3.y - v10->v3.y;
          *(float *)v9 = v8->mCamera.mTransformation.v3.x - v10->v3.x;
          *((float *)v9 + 1) = v13;
          *((float *)v9 + 2) = v12;
          v14 = LODWORD(v8->mCamera.mTransformation.v2.y) ^ _xmm[0];
          v15 = v8->mCamera.mTransformation.v2.z;
          *((_DWORD *)v9 + 3) = LODWORD(v8->mCamera.mTransformation.v2.x) ^ _xmm[0];
          *((_DWORD *)v9 + 4) = v14;
          *((_DWORD *)v9 + 5) = LODWORD(v15) ^ _xmm[0];
          v16 = UFG::Metrics::msInstance.mSimTimeMSec;
          *((_DWORD *)v11 + 8) = 1184645120;
          *((_DWORD *)v11 + 9) = 1050253722;
          *((_QWORD *)v11 + 3) = v16;
          skinning_params->user_data_1 = v11;
        }
      }
    }
  }
}

// File Line: 156
// RVA: 0x582020
void __fastcall UFG::CompositeLookComponent::ForceInvisibleTransparency(UFG::CompositeLookComponent *this)
{
  unsigned int v1; // er8

  v1 = Illusion::gEngine.mFrameCount;
  *(_WORD *)this->mTransparencyState = 0;
  *(_WORD *)&this->mTransparencyState[2] = (unsigned __int8)((signed int)(v1 - 1) % 255);
}

// File Line: 164
// RVA: 0x5822E0
void __fastcall UFG::CompositeLookComponent::ForceVisibleTransparency(UFG::CompositeLookComponent *this)
{
  unsigned int v1; // er8

  v1 = Illusion::gEngine.mFrameCount;
  this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = (signed int)(v1 - 1) % 255;
  this->mForceTransparencyState = Render::TransparencySystem::msOpaqueIndex;
}

// File Line: 172
// RVA: 0x582010
void __fastcall UFG::CompositeLookComponent::ForceFadeOut(UFG::CompositeLookComponent *this)
{
  this->mForceTransparencyState = 0;
}

// File Line: 177
// RVA: 0x582000
void __fastcall UFG::CompositeLookComponent::ForceFadeIn(UFG::CompositeLookComponent *this)
{
  this->mForceTransparencyState = Render::TransparencySystem::msOpaqueIndex;
}

// File Line: 182
// RVA: 0x58C6B0
void __fastcall UFG::CompositeLookComponent::StartFadeIn(UFG::CompositeLookComponent *this)
{
  signed int v1; // er8

  v1 = Render::TransparencySystem::msTransparencyFrameCounter - 1;
  if ( Render::TransparencySystem::msEnabled )
    this->mTransparencyState[0] = 0;
  else
    this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = v1 + v1 / 255;
  this->mForceTransparencyState = Render::TransparencySystem::msOpaqueIndex;
}

// File Line: 189
// RVA: 0x582B30
_BOOL8 __fastcall UFG::CompositeLookComponent::HasFadedOut(UFG::CompositeLookComponent *this)
{
  return this->mTransparencyState[0] == 0;
}

// File Line: 194
// RVA: 0x582B20
bool __fastcall UFG::CompositeLookComponent::HasFadedIn(UFG::CompositeLookComponent *this)
{
  return (unsigned __int8)this->mTransparencyState[0] == Render::TransparencySystem::msOpaqueIndex;
}

// File Line: 199
// RVA: 0x587A00
void __fastcall UFG::CompositeLookComponent::OnUpdateCullResults(UFG::CompositeLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::ViewSettings *view_settings)
{
  unsigned __int8 *v3; // rdi
  float v4; // xmm6_4
  float v5; // xmm7_4
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::StreamedResourceComponent *v8; // rax
  signed __int8 v9; // al
  int v10; // ebx
  int v11; // esi
  UFG::SimObject *v12; // rcx
  UFG::SimComponent *v13; // rax
  int v14; // eax
  int v15; // er8
  int v16; // er11
  int v17; // ecx
  int v18; // er9
  int v19; // er10
  int v20; // eax

  v3 = (unsigned __int8 *)this;
  v4 = view_settings->mCullPixelDensityThreshold * 1.0700001;
  if ( view_settings->mCullIndex >= 6 )
    v5 = *(float *)&FLOAT_1_0;
  else
    v5 = composite_drawable->mCullResults->mPixelCoverage[view_settings->mCullIndex];
  v6 = (UFG::SimObjectGame *)this[-1].mAnimationComponent.m_pSimComponent;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::StreamedResourceComponent *)v6->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UFG::StreamedResourceComponent *)v6->m_Components.p[7].m_pComponent;
      else
        v8 = (UFG::StreamedResourceComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v6,
                                                                   UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::StreamedResourceComponent::_TypeUID));
    }
    else
    {
      v8 = (UFG::StreamedResourceComponent *)v6->m_Components.p[10].m_pComponent;
    }
    if ( v8 && UFG::StreamedResourceComponent::AreResourcesLoaded(v8) != 1 )
    {
      v3[42] = Render::TransparencySystem::msTransparencyFrameCounter
             + (signed int)Render::TransparencySystem::msTransparencyFrameCounter / 255;
      return;
    }
  }
  v9 = v3[43];
  v10 = Render::TransparencySystem::msOpaqueIndex;
  v11 = 0;
  if ( v4 >= v5 )
    v10 = 0;
  if ( v9 != -1 )
    v10 = v9;
  v12 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v12 )
    v13 = UFG::SimObject::GetComponentOfType(v12, UFG::FollowCameraComponent::_TypeUID);
  else
    v13 = 0i64;
  if ( v3[43] || !v13 || v13[24].m_NameUID != 5 )
  {
    v15 = v3[40];
    v17 = v3[44] != 0 ? 2 : 0;
    v18 = (v17 == 1) + 1;
    v19 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    if ( v17 != 3 )
    {
      if ( v17 == 2 )
      {
        if ( !(v19 & 1) )
        {
LABEL_33:
          if ( v15 >= v10 )
          {
            if ( v15 > v10 )
              v15 -= v18;
          }
          else
          {
            v15 += v18;
          }
        }
LABEL_41:
        v14 = Render::TransparencySystem::msOpaqueIndex;
        v3[42] = v19;
        if ( v15 > 0 )
          v11 = v15;
        goto LABEL_43;
      }
      v16 = v3[42];
      v20 = v19 - (v16 + 1) % 255;
      if ( v20 < 0 )
        v20 = (v16 + 1) % 255 - v19;
      if ( v20 <= 0 )
        goto LABEL_33;
    }
    v15 = v10;
    goto LABEL_41;
  }
  v14 = Render::TransparencySystem::msOpaqueIndex;
  if ( v10 > 0 )
    v11 = v10;
  v3[42] = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
LABEL_43:
  if ( v11 < v14 )
    LOBYTE(v14) = v11;
  v3[41] = v10;
  v3[40] = v14;
}

// File Line: 238
// RVA: 0x587550
_BOOL8 __fastcall UFG::CompositeLookComponent::OnIsCulled(UFG::CompositeLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::View *view)
{
  Illusion::SubmitContext *v3; // r9
  UFG::SimObject *v4; // rdx

  v3 = view->mSubmitContext;
  v4 = this->m_pSimObject;
  v3[1].vfptr = 0i64;
  v3[1].mStateValues.mSetValueMask.mFlags[0] = (unsigned __int64)v4;
  return LOBYTE(this->m_pSimObject) == 0;
}

// File Line: 246
// RVA: 0x582060
void __fastcall UFG::CompositeLookComponent::ForceTransparencyOnAttachments(UFG::CompositeLookComponent *this, int transparency_target)
{
  UFG::SimComponent *v2; // rax
  char v3; // di
  signed __int64 v4; // rsi
  signed __int64 v5; // rbx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax

  v2 = this->mAnimationComponent.m_pSimComponent;
  v3 = transparency_target;
  if ( v2 )
    v2 = *(UFG::SimComponent **)&v2[2].m_TypeUID;
  if ( v2 )
  {
    if ( HIDWORD(v2[3].m_SafePointerList.mNode.mNext) != transparency_target )
    {
      v4 = (signed __int64)&v2[2].m_pSimObject;
      v5 = (signed __int64)&v2[2].m_BoundComponentHandles.mNode.mNext[-1].mNext;
      HIDWORD(v2[3].m_SafePointerList.mNode.mNext) = transparency_target;
      if ( (UFG::SimObject **)v5 != &v2[2].m_pSimObject )
      {
        do
        {
          v6 = *(UFG::SimObjectGame **)(v5 + 104);
          if ( v6 && (v6->m_Flags >> 13) & 1 )
          {
            v7 = v6->m_Flags;
            if ( (v7 >> 14) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CompositeLookComponent::_TypeUID);
            }
            else if ( (v7 & 0x8000u) == 0 )
            {
              if ( (v7 >> 13) & 1 )
              {
                v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CompositeLookComponent::_TypeUID);
              }
              else if ( (v7 >> 12) & 1 )
              {
                v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CompositeLookComponent::_TypeUID);
              }
              else
              {
                v8 = UFG::SimObject::GetComponentOfType(
                       (UFG::SimObject *)&v6->vfptr,
                       UFG::CompositeLookComponent::_TypeUID);
              }
            }
            else
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CompositeLookComponent::_TypeUID);
            }
            if ( v8 )
              BYTE3(v8[1].m_pSimObject) = v3;
          }
          v5 = *(_QWORD *)(v5 + 16) - 8i64;
        }
        while ( v5 != v4 );
      }
    }
  }
}

// File Line: 267
// RVA: 0x587740
void __fastcall UFG::CompositeLookComponent::OnSetHidden(UFG::CompositeLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, const bool bIsHidden)
{
  int v3; // eax

  v3 = Render::TransparencySystem::msOpaqueIndex;
  if ( composite_drawable->mIsHidden )
    v3 = 0;
  UFG::CompositeLookComponent::ForceTransparencyOnAttachments((UFG::CompositeLookComponent *)((char *)this - 64), v3);
}

// File Line: 273
// RVA: 0x582670
UFG::ComponentIDDesc *__fastcall UFG::VehicleLookComponent::GetDesc(UFG::VehicleLookComponent *this)
{
  return &UFG::VehicleLookComponent::_TypeIDesc;
}

// File Line: 286
// RVA: 0x57D1E0
void __fastcall UFG::VehicleLookComponent::VehicleLookComponent(UFG::VehicleLookComponent *this)
{
  UFG::VehicleLookComponent *v1; // rbx

  v1 = this;
  UFG::CompositeLookComponent::CompositeLookComponent((UFG::CompositeLookComponent *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleLookComponent::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::ICompositeLookVtbl *)&UFG::VehicleLookComponent::`vftable{for `UFG::ICompositeLook};
  v1->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::VehicleLookComponent::`vftable{for `UFG::UpdateInterface};
  v1->mVehicleEffectsComponent = 0i64;
  *(_WORD *)&v1->mVehiclePaintID = -1;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::VehicleLookComponent::_VehicleLookComponentTypeUID,
    "VehicleLookComponent");
}

// File Line: 310
// RVA: 0x587E40
void __fastcall UFG::VehicleLookComponent::OnUpdateMaterial(UFG::VehicleLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::SimObjectGame *v2; // rbx
  UFG::CompositeDrawableComponent *v3; // rbp
  UFG::VehicleLookComponent *v4; // rsi
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qPropertyList *v8; // r14
  UFG::qPropertyList *v9; // r15
  int v10; // eax
  const char *v11; // r14
  UFG::qResourceWarehouse *v12; // rax
  Illusion::StateBlockInventory *v13; // rax
  Illusion::StateBlockInventory *v14; // rdi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v15; // rax
  unsigned int v16; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v17; // rax
  unsigned int v18; // er8
  __int64 v19; // rdx
  unsigned int v20; // er9
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  UFG::qBaseNodeRB *v23; // rax
  char *v24; // rax
  int v25; // eax
  const char *v26; // rdi
  UFG::qResourceWarehouse *v27; // rax
  Illusion::StateBlockInventory *v28; // rax
  Illusion::StateBlockInventory *v29; // rsi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v30; // rax
  unsigned int v31; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v32; // rax
  unsigned int v33; // er9
  __int64 v34; // r10
  unsigned int original_name_uid; // ST28_4
  unsigned __int16 v36; // cx
  UFG::SimComponent *v37; // rax
  UFG::qBaseNodeRB *v38; // rax
  char *v39; // rax
  char dest; // [rsp+30h] [rbp-118h]

  v2 = (UFG::SimObjectGame *)composite_drawable->m_pSimObject;
  v3 = composite_drawable;
  v4 = this;
  v5 = v2->m_pSceneObj;
  if ( v5 )
  {
    v6 = v5->mpWritableProperties;
    if ( !v6 )
      v6 = v5->mpConstProperties;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = this->m_BoundComponentHandles.mNode.mNext;
  LOWORD(this->mVehicleInteriorMS.v0.x) = -1;
  HIDWORD(v7->mNext) = -1082130432;
  if ( v6 )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&qSymbol_VehicleLook.mUID, DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&qSymbol_VehicleLookGlass.mUID, DEPTH_RECURSE);
    if ( v8 )
    {
      v10 = UFG::qRandom(v8->mNumElements, &UFG::qDefaultSeed);
      if ( v10 < 0 )
        v10 = -v10;
      LOBYTE(v4->mVehicleInteriorMS.v0.x) = v10;
      v11 = UFG::qPropertyList::Get<char const *>(v8, (char)v10);
      if ( v11 )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        v13 = (Illusion::StateBlockInventory *)UFG::qResourceWarehouse::GetInventory(v12, 0x4D04C7F2u);
        v14 = v13;
        if ( !s_DefaultPaintUID )
        {
          v15 = Illusion::StateBlockInventory::GetStateBlock(v13, 0x26228D0Fu, 1);
          if ( v15 )
            s_DefaultPaintUID = (unsigned int)v15[1].mNode.mNext;
          else
            s_DefaultPaintUID = 0;
        }
        UFG::qSPrintf(&dest, 255, "StateBlock.%s_VehicleLook", v11);
        v16 = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
        v17 = Illusion::StateBlockInventory::GetStateBlock(v14, v16, 1);
        v18 = s_DefaultPaintUID;
        if ( s_DefaultPaintUID && v17 )
        {
          v19 = v3->mMaterialModifier.mNumOverrides;
          v20 = (unsigned int)v17[1].mNode.mNext;
          v3->mMaterialModifier.mNumOverrides = v19 + 1;
          Illusion::ParamOverride::SetOverride(
            &v3->mMaterialModifier.mOverrides[v19],
            0xC6D01635,
            0x4D04C7F2u,
            v20,
            OVERRIDE_EQUALS,
            v18);
        }
        else
        {
          v21 = v2->m_Flags;
          if ( (v21 >> 14) & 1 )
          {
            v22 = v2->m_Components.p[14].m_pComponent;
          }
          else if ( (v21 & 0x8000u) == 0 )
          {
            if ( (v21 >> 13) & 1 )
            {
              v22 = v2->m_Components.p[9].m_pComponent;
            }
            else if ( (v21 >> 12) & 1 )
            {
              v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeDrawableComponent::_TypeUID);
            }
            else
            {
              v22 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v2->vfptr,
                      UFG::CompositeDrawableComponent::_TypeUID);
            }
          }
          else
          {
            v22 = v2->m_Components.p[14].m_pComponent;
          }
          v23 = ModelType::GetSkeleton((ModelType *)v22[22].m_SafePointerList.mNode.mNext);
          v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v23);
          UFG::qPrintf("Warning: Cannot set %s VehicleLook override to %s\n", v24, v11);
        }
      }
    }
    if ( v9 )
    {
      v25 = UFG::qRandom(v9->mNumElements, &UFG::qDefaultSeed);
      if ( v25 < 0 )
        v25 = -v25;
      BYTE1(v4->mVehicleInteriorMS.v0.x) = v25;
      v26 = UFG::qPropertyList::Get<char const *>(v9, (char)v25);
      if ( v26 )
      {
        v27 = UFG::qResourceWarehouse::Instance();
        v28 = (Illusion::StateBlockInventory *)UFG::qResourceWarehouse::GetInventory(v27, 0x4D04C7F2u);
        v29 = v28;
        if ( !s_DefaultGlassUID )
        {
          v30 = Illusion::StateBlockInventory::GetStateBlock(v28, 0x5C70C5A7u, 1);
          if ( v30 )
            s_DefaultGlassUID = (unsigned int)v30[1].mNode.mNext;
          else
            s_DefaultGlassUID = 0;
        }
        UFG::qSPrintf(&dest, 255, "StateBlock.%s_VehicleLook", v26);
        v31 = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
        v32 = Illusion::StateBlockInventory::GetStateBlock(v29, v31, 1);
        if ( s_DefaultGlassUID && v32 )
        {
          v33 = (unsigned int)v32[1].mNode.mNext;
          v34 = v3->mMaterialModifier.mNumOverrides;
          original_name_uid = s_DefaultGlassUID;
          v3->mMaterialModifier.mNumOverrides = v34 + 1;
          Illusion::ParamOverride::SetOverride(
            &v3->mMaterialModifier.mOverrides[v34],
            0xC6D01635,
            0x4D04C7F2u,
            v33,
            OVERRIDE_EQUALS,
            original_name_uid);
        }
        else
        {
          v36 = v2->m_Flags;
          if ( (v36 >> 14) & 1 || (v36 & 0x8000u) != 0 )
          {
            v37 = v2->m_Components.p[14].m_pComponent;
          }
          else if ( (v36 >> 13) & 1 )
          {
            v37 = v2->m_Components.p[9].m_pComponent;
          }
          else if ( (v36 >> 12) & 1 )
          {
            v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeDrawableComponent::_TypeUID);
          }
          else
          {
            v37 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v2->vfptr,
                    UFG::CompositeDrawableComponent::_TypeUID);
          }
          v38 = ModelType::GetSkeleton((ModelType *)v37[22].m_SafePointerList.mNode.mNext);
          v39 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v38);
          UFG::qPrintf("Warning: Cannot set %s VehicleLook override to %s\n", v39, v26);
        }
      }
    }
  }
}

// File Line: 411
// RVA: 0x587020
void __fastcall UFG::VehicleLookComponent::OnDrawRigid(UFG::VehicleLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::View *view, ModelType::ModelBindingRigid *model_binding)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  float v5; // xmm2_4
  UFG::VehicleLookComponent *v6; // r11
  float v7; // xmm3_4
  float v8; // xmm0_4
  __int64 v9; // r10
  signed __int64 v10; // rdx
  __int64 v11; // r8
  signed __int64 v12; // rcx
  ModelType::ModelBindingRigid **v13; // rax

  v4 = this->m_BoundComponentHandles.mNode.mNext;
  v5 = UFG::qVector4::msOne.z;
  v6 = this;
  v7 = UFG::qVector4::msOne.w;
  v8 = UFG::qVector4::msOne.x;
  HIDWORD(v4[2].mPrev) = LODWORD(UFG::qVector4::msOne.y);
  *(float *)&v4[2].mPrev = v8;
  *(float *)&v4[2].mNext = v5;
  *((float *)&v4[2].mNext + 1) = v7;
  if ( *(_QWORD *)&this->mHighlightingMode )
  {
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      v11 = *(_QWORD *)&v6->mHighlightingMode;
      if ( *(_BYTE *)(*(_QWORD *)(v11 + 1832) + v9 + 1324) )
      {
        v12 = 0i64;
        v13 = (ModelType::ModelBindingRigid **)(v10 + v11 + 88);
        while ( model_binding != *v13 )
        {
          ++v12;
          ++v13;
          if ( v12 >= 3 )
            goto LABEL_9;
        }
        LODWORD(v6->m_BoundComponentHandles.mNode.mNext[2].mPrev) = 0;
      }
LABEL_9:
      v10 += 24i64;
      ++v9;
    }
    while ( v10 < 96 );
  }
}

// File Line: 436
// RVA: 0x587440
void __fastcall UFG::VehicleLookComponent::OnDrawSkin(UFG::VehicleLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::View *view, ModelType::ModelBindingSkin *model_binding, Render::SkinningParams *skinning_params)
{
  UFG::qMatrix44 *v5; // rbx
  UFG::VehicleLookComponent *v6; // r14
  Render::View *v7; // rdi
  ModelType::ModelBindingSkin *v8; // rbp
  __int64 v9; // rax
  float *v10; // rbx
  Render::SkinningParams *v11; // rbx

  v5 = (UFG::qMatrix44 *)&this->mAnimationComponent;
  v6 = this;
  v7 = view;
  v8 = model_binding;
  SkeletalPose::GetPositionMS(composite_drawable->mPose, 0, (UFG::qMatrix44 *)&this->mAnimationComponent);
  skinning_params->mRigidTransform = v5;
  v9 = *(_QWORD *)&v6->mHighlightingMode;
  if ( v9 && *(_QWORD *)(v9 + 0x728) )
  {
    v10 = (float *)UFG::qLinearAllocator::Malloc(
                     Illusion::gEngine.FrameMemory,
                     32 * skinning_params->bone_matrix_count,
                     0x10u);
    DamageRig::GetWeightList(
      *(DamageRig **)(*(_QWORD *)&v6->mHighlightingMode + 1832i64),
      v10,
      skinning_params->bone_matrix_count,
      skinning_params->bone_remap_array);
    skinning_params->user_data_0 = v10;
  }
  if ( !v7->mSettings->mCullIndex && v7->mSubmitContext->mRenderPass == Solid )
  {
    if ( v8->mDecalLayer )
    {
      v11 = (Render::SkinningParams *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xA8u, 0x10u);
      UFG::qMemCopy(v11, skinning_params, 0xA8u);
      ModelType::SkinnedDecalLayer::Draw(v8->mDecalLayer, &Render::Skinning::gSkinning, v11);
    }
  }
}

// File Line: 459
// RVA: 0x58D840
void __fastcall UFG::VehicleLookComponent::Update(UFG::VehicleLookComponent *this, float delta_sec)
{
  UFG::VehicleLookComponent *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  __int64 v7; // rax
  int v8; // xmm0_4

  v2 = this;
  if ( -1.0 == *((float *)&this->m_BoundComponentHandles.mNode.mPrev->mNext + 1) )
  {
    v3 = *(UFG::SimObjectGame **)&this[-1].mVehicleInteriorMS.v3.x;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v3->m_Components.p[14].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v5 = v3->m_Components.p[9].m_pComponent;
        else
          v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        v5 = v3->m_Components.p[14].m_pComponent;
      }
      if ( v5 )
      {
        v6 = v5[19].m_BoundComponentHandles.mNode.mPrev;
        if ( v6 )
          *((float *)&v2->m_BoundComponentHandles.mNode.mPrev->mNext + 1) = (float)(*(float *)&v6[1].mNext
                                                                                  - *(float *)&v6->mNext)
                                                                          * gHeightGrim;
      }
    }
  }
  v7 = *(_QWORD *)v2->mTransparencyState;
  if ( v7 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(v7 + 1832) + 1060i64) )
      v8 = (signed int)FLOAT_1_0;
    else
      v8 = 0;
    v2->m_BoundComponentHandles.mNode.mPrev->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v8;
    HIDWORD(v2->m_BoundComponentHandles.mNode.mPrev->mPrev) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v2->mTransparencyState
                                                                                    + 1832i64)
                                                                        + 1320i64);
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v2->mTransparencyState + 1832i64) + 1056i64) = 0;
  }
}

// File Line: 482
// RVA: 0x5829C0
const char *__fastcall UFG::CharacterLookComponent::GetTypeName(UFG::CharacterLookComponent *this)
{
  return "CharacterLookComponent";
}

// File Line: 489
// RVA: 0x57C8B0
void __fastcall UFG::CharacterLookComponent::CharacterLookComponent(UFG::CharacterLookComponent *this)
{
  UFG::CharacterLookComponent *v1; // rbx

  v1 = this;
  UFG::CompositeLookComponent::CompositeLookComponent((UFG::CompositeLookComponent *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterLookComponent::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::ICompositeLookVtbl *)&UFG::CharacterLookComponent::`vftable{for `UFG::ICompositeLook};
  v1->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CharacterLookComponent::`vftable{for `UFG::UpdateInterface};
  v1->mOverlayTextureID = 0;
  v1->mIsSkinSSEnabled = 0;
  *(_QWORD *)&v1->mSweatLevel = 0i64;
}

// File Line: 493
// RVA: 0x58A6E0
UFG::CharacterLookComponent *__fastcall UFG::CharacterLookComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rdi
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::CharacterLookComponent *v6; // rbx
  UFG::CharacterLookComponent *result; // rax
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::CharacterLookComponent *v10; // rax
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v11; // rcx
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v12; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CompositeDrawable::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::CharacterLookComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( v2 || result )
  {
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0xC8ui64, "CharacterLookComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::CharacterLookComponent::CharacterLookComponent((UFG::CharacterLookComponent *)v9);
      v6 = v10;
    }
    v11 = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mPrev;
    v12 = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mPrev;
    v11->mPrev = v12;
    v11->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&UFG::CompositeLookComponent::s_CompositeLookComponentList;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)&v6->mPrev;
    UFG::SimObjectModifier::SimObjectModifier(&v13, v3->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, (UFG::SimComponent *)&v6->vfptr, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
    result = v6;
  }
  return result;
}

// File Line: 512
// RVA: 0x587C60
void __fastcall UFG::CharacterLookComponent::OnUpdateMaterial(UFG::CharacterLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::CompositeDrawableComponent *v2; // rbx
  UFG::CharacterLookComponent *v3; // r14
  UFG::SimObject *v4; // rax
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  component_CompositeDrawable *v7; // rcx
  signed __int64 v8; // r15
  __int64 v9; // rax
  UFG::qPropertyList *v10; // rbx
  __int64 v11; // rax
  UFG::qPropertyList *v12; // rsi
  unsigned int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // ebp
  unsigned int v16; // edi
  char *v17; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qPropertyList *v19; // rax
  UFG::qSymbolUC *v20; // rax
  int *v21; // rcx
  unsigned int v22; // er10
  unsigned int v23; // er8
  Illusion::ParamOverride *v24; // rcx
  int v25; // [rsp+60h] [rbp+8h]

  v2 = composite_drawable;
  v3 = this;
  v4 = composite_drawable->m_pSimObject;
  if ( v4 )
    v4 = (UFG::SimObject *)v4->m_pSceneObj;
  if ( v4 )
  {
    v5 = (UFG::qPropertySet *)v4[1].m_SafePointerList.mNode.mNext;
    if ( !v5 )
      v5 = (UFG::qPropertySet *)v4[1].m_SafePointerWithCallbackList.mNode.mPrev;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_CompositeDrawable::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
    v7 = (component_CompositeDrawable *)UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v7 = 0i64;
  *((_BYTE *)&v3->mHighlightingMode + 4) = v7->SkinSSEnabled;
  v8 = (signed __int64)&v2->mMaterialModifier;
  v9 = v7->OverlayWeights.mOffset;
  if ( v9 )
  {
    v10 = (UFG::qPropertyList *)((char *)&v7->OverlayWeights + v9);
    if ( v10 )
    {
      if ( v10->mNumElements )
      {
        v11 = v7->OverlayTextures.mOffset;
        v12 = (UFG::qPropertyList *)(v11 ? (UFG::qOffset64<UFG::qPropertyList *> *)((char *)&v7->OverlayTextures + v11) : 0i64);
        v13 = UFG::qPropertyList::GetRandomIndex(v10);
        v14 = UFG::qPropertyList::Get<UFG::qSymbol>(v10, v13)->mUID;
        v15 = v12->mNumElements;
        v16 = 0;
        if ( v15 )
        {
          while ( 1 )
          {
            v17 = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v16);
            if ( v17 && *(_QWORD *)v17 )
              v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17];
            else
              v18 = 0i64;
            if ( v18->mName.mUID == v14 )
              break;
            if ( ++v16 >= v15 )
              goto LABEL_27;
          }
          v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(v18, (UFG::qSymbol *)&qSymbol_Textures.mUID, DEPTH_RECURSE);
          nextTextureIndex %= v19->mNumElements;
          v25 = -1;
          v20 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v19, nextTextureIndex);
          v21 = &v25;
          if ( v20 )
            v21 = (int *)v20;
          v3->mHighlightingMode = *v21;
          ++nextTextureIndex;
        }
      }
    }
  }
LABEL_27:
  if ( v3->mHighlightingMode )
  {
    if ( _S12_9 & 1 )
    {
      v22 = uidTexDiffuseBlend;
    }
    else
    {
      _S12_9 |= 1u;
      v22 = UFG::qStringHash32("texDiffuseBlend", 0xFFFFFFFF);
      uidTexDiffuseBlend = v22;
    }
    v23 = v3->mHighlightingMode;
    v24 = (Illusion::ParamOverride *)(104i64 * (signed int)(*(_DWORD *)(v8 + 8))++ + v8 + 16);
    Illusion::ParamOverride::SetTextureOverride(v24, v22, v23, 0, 0);
  }
}

// File Line: 562
// RVA: 0x587880
void __fastcall UFG::CharacterLookComponent::OnUpdateCullResults(UFG::CharacterLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::ViewSettings *view_settings)
{
  Render::ViewSettings *v3; // rbp
  UFG::CompositeDrawableComponent *v4; // rsi
  UFG::CharacterLookComponent *v5; // rbx
  float v6; // xmm0_4
  UFG::BaseCameraComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObjectGame *v9; // rcx
  int v10; // edi
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rcx
  UFG::SimComponent *v13; // rax

  v3 = view_settings;
  v4 = composite_drawable;
  v5 = this;
  if ( view_settings->mCullIndex >= 6 )
    v6 = 0.0;
  else
    v6 = composite_drawable->mCullResults->mDistance[view_settings->mCullIndex];
  if ( v6 >= 4.0
    || (v7 = UFG::GetCurrentBaseCamera(), (v8 = (UFG::SimComponent *)&v7->vfptr) != 0i64)
    && (UFG::SimComponent::IsType(
          (UFG::SimComponent *)&v7->vfptr,
          UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID)
     || UFG::SimComponent::IsType(v8, UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID)
     || UFG::SimComponent::IsType(v8, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID)) )
  {
    if ( !BYTE3(v5->m_pSimObject) )
    {
      UFG::CompositeLookComponent::ForceTransparencyOnAttachments(
        (UFG::CompositeLookComponent *)&v5[-1].mAnimationComponent.mNext,
        -1);
      BYTE3(v5->m_pSimObject) = -1;
    }
  }
  else
  {
    v9 = *(UFG::SimObjectGame **)&v5[-1].mOverlayTextureID;
    v10 = -1;
    if ( v9 )
    {
      v11 = v9->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v12 = v9->m_Components.p[37].m_pComponent;
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
        }
        else
        {
          v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::CameraSubject::_TypeUID);
        }
        v12 = v13;
      }
      else
      {
        v12 = v9->m_Components.p[31].m_pComponent;
      }
      if ( v12 && ((unsigned __int8 (*)(void))v12->vfptr[29].__vecDelDtor)() )
        v10 = 0;
    }
    UFG::CompositeLookComponent::ForceTransparencyOnAttachments(
      (UFG::CompositeLookComponent *)&v5[-1].mAnimationComponent.mNext,
      v10);
    BYTE3(v5->m_pSimObject) = v10;
  }
  UFG::CompositeLookComponent::OnUpdateCullResults((UFG::CompositeLookComponent *)&v5->vfptr, v4, v3);
}

// File Line: 600
// RVA: 0x586B30
void __fastcall UFG::VehicleLookComponent::OnDetach(UFG::VehicleLookComponent *this)
{
  UFG::CompositeLookComponent::OnDetach((UFG::CompositeLookComponent *)&this->vfptr);
}

// File Line: 605
// RVA: 0x587570
void __fastcall UFG::CharacterLookComponent::OnReset(UFG::CharacterLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  signed int v3; // er8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax

  v2 = this->m_BoundComponentHandles.mNode.mNext;
  *(_WORD *)((char *)&this->m_pSimObject + 3) = 255;
  HIDWORD(v2[3].mNext) = 0;
  LODWORD(this->m_BoundComponentHandles.mNode.mNext[2].mPrev) = 0;
  HIDWORD(this->m_BoundComponentHandles.mNode.mNext[2].mNext) = 0;
  v3 = Illusion::gEngine.mFrameCount - 1;
  if ( Render::TransparencySystem::msEnabled )
    LOBYTE(this->m_pSimObject) = 0;
  else
    LOBYTE(this->m_pSimObject) = Render::TransparencySystem::msOpaqueIndex;
  BYTE1(this->m_pSimObject) = Render::TransparencySystem::msOpaqueIndex;
  BYTE2(this->m_pSimObject) = v3 + v3 / 255;
  v4 = this->m_BoundComponentHandles.mNode.mNext;
  this->mSceneryInstance = 0i64;
  LODWORD(v4[2].mPrev) = 0;
  HIDWORD(this->m_BoundComponentHandles.mNode.mNext[2].mNext) = 0;
}

// File Line: 614
// RVA: 0x586FF0
void __fastcall UFG::CharacterLookComponent::OnDraw(UFG::CharacterLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::View *view, UFG::qMatrix44 *local_matrix)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rbx
  Illusion::StateValues *v5; // rax

  v4 = this->mAnimationComponent.mPrev;
  v5 = Render::View::GetStateValues(view);
  v5->mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
  v5->mParamValues[57] = v4;
}

// File Line: 619
// RVA: 0x5870D0
void __fastcall UFG::CharacterLookComponent::OnDrawSkin(UFG::CharacterLookComponent *this, UFG::CompositeDrawableComponent *composite_drawable, Render::View *view, ModelType::ModelBindingSkin *model_binding, Render::SkinningParams *skinning_params)
{
  UFG::CharacterLookComponent *v5; // rbp
  __int64 v6; // rcx
  Render::View *v7; // r14
  signed __int64 v8; // rax
  float *v9; // rcx
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::CharacterAnimationComponent *v12; // rax
  UFG::CharacterAnimationComponent *v13; // rsi
  float *v14; // rbx
  Illusion::StateValues *v15; // rax
  bool v16; // cf
  __int64 v17; // rbx
  void *v18; // rbx
  Illusion::StateValues *v19; // rax
  float v20; // [rsp+20h] [rbp-18h]
  float v21; // [rsp+24h] [rbp-14h]
  float v22; // [rsp+28h] [rbp-10h]
  float v23; // [rsp+2Ch] [rbp-Ch]

  v5 = this;
  v6 = *(_QWORD *)&this->m_Flags;
  v7 = view;
  if ( v6 )
  {
    v8 = v6 + 16i64 * model_binding->mModelIndex;
    v20 = *(float *)v8 * *(float *)v8;
    v21 = *(float *)(v8 + 4) * *(float *)(v8 + 4);
    v22 = *(float *)(v8 + 8) * *(float *)(v8 + 8);
    v23 = *(float *)(v8 + 12);
  }
  else
  {
    v20 = UFG::qColour::White.r;
    v21 = UFG::qColour::White.g;
    v22 = UFG::qColour::White.b;
    v23 = UFG::qColour::White.a;
  }
  v9 = (float *)v5->m_BoundComponentHandles.mNode.mNext;
  *v9 = v20;
  v9[1] = v21;
  v9[2] = v22;
  v9[3] = v23;
  v10 = *(UFG::SimObjectCVBase **)&v5[-1].mOverlayTextureID;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
      else
        v12 = (UFG::CharacterAnimationComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v10->vfptr,
                                                                       UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
    v13 = v12;
    if ( v12 )
    {
      if ( v12->mDamageRig )
      {
        v14 = (float *)UFG::qLinearAllocator::Malloc(
                         Illusion::gEngine.FrameMemory,
                         32 * skinning_params->bone_matrix_count,
                         0x10u);
        CharacterDamageRig::GetCharacterWeightList(
          v13->mDamageRig,
          v14,
          skinning_params->bone_matrix_count,
          skinning_params->bone_remap_array);
        skinning_params->user_data_0 = v14;
        skinning_params->no_override = v13->mDamageRig->mDamaged;
      }
    }
  }
  v15 = Render::View::GetStateValues(v7);
  v16 = *(float *)&v5->mSceneryInstance > 0.0;
  v5->mAnimationComponent.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v15->mParamValues[57];
  if ( (v16 || *((float *)&v5->mSceneryInstance + 1) > 0.0) && !Render::View::GetStateValues(v7)->mParamValues[57] )
  {
    v17 = *((_QWORD *)Render::GetRenderCallbacks()->mRenderParam + 11);
    if ( v17 )
    {
      v18 = *(void **)(v17 + 24);
      v19 = Render::View::GetStateValues(v7);
      v19->mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
      v19->mParamValues[57] = v18;
    }
  }
}

// File Line: 649
// RVA: 0x58D600
void __fastcall UFG::CharacterLookComponent::Update(UFG::CharacterLookComponent *this, float delta_sec)
{
  UFG::CharacterLookComponent *v2; // rbx
  UFG::TimeOfDayManager *v3; // rax
  __int64 v4; // r8
  float v5; // xmm10_4
  float v6; // xmm6_4
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  bool v9; // zf
  UFG::SimObjectGame *v10; // rcx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  unsigned int v15; // eax
  UFG::SimObjectCVBase *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::CharacterAnimationComponent *v18; // rax
  UFG::CharacterAnimationComponent *v19; // rdx
  CharacterDamageRig *v20; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm2_4

  v2 = this;
  v3 = UFG::TimeOfDayManager::GetInstance();
  v4 = *(_QWORD *)&v2[-1].mAnimationComponent.m_Changed;
  v5 = v3->m_WeatherState - 1.0;
  v6 = UFG::RenderWorld::msExposureMetering->mSkyIrradValue;
  if ( v4 )
  {
    v7 = *(_WORD *)(v4 + 76);
    if ( (v7 >> 14) & 1 )
    {
      v8 = *(UFG::SimComponent **)(*(_QWORD *)(v4 + 104) + 704i64);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
               *(UFG::SimObjectGame **)&v2[-1].mAnimationComponent.m_Changed,
               UFG::CharacterOccupantComponent::_TypeUID);
      }
      else
      {
        v9 = ((v7 >> 12) & 1) == 0;
        v10 = *(UFG::SimObjectGame **)&v2[-1].mAnimationComponent.m_Changed;
        v8 = v9 ? UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v10->vfptr,
                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v10,
                                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
             *(UFG::SimObjectGame **)&v2[-1].mAnimationComponent.m_Changed,
             UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v8 )
      v6 = 0.0;
  }
  if ( v5 <= 0.0 || v6 <= 0.2 || (v11 = *((float *)&v2->mHighlightingMode + 1), v11 >= 1.0) )
  {
    v12 = *((float *)&v2->mHighlightingMode + 1);
    if ( v12 > 0.0 )
      *((float *)&v2->mHighlightingMode + 1) = v12 - (float)(delta_sec * 0.016666668);
  }
  else
  {
    *((float *)&v2->mHighlightingMode + 1) = (float)((float)(v6 * v5) * (float)(delta_sec * 0.1)) + v11;
  }
  v13 = *((float *)&v2->mHighlightingMode + 1);
  if ( v13 <= 0.0 )
  {
    v13 = 0.0;
  }
  else if ( v13 >= 1.0 )
  {
    v13 = *(float *)&FLOAT_1_0;
  }
  v14 = v2->m_BoundComponentHandles.mNode.mPrev;
  v15 = v2->mHighlightingMode;
  *((float *)&v2->mHighlightingMode + 1) = v13;
  HIDWORD(v14[2].mPrev) = v15;
  LODWORD(v2->m_BoundComponentHandles.mNode.mPrev[2].mNext) = *(&v2->mHighlightingMode + 1);
  v16 = *(UFG::SimObjectCVBase **)&v2[-1].mAnimationComponent.m_Changed;
  if ( v16 )
  {
    v17 = v16->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v18 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v16);
    }
    else if ( (v17 & 0x8000u) == 0 )
    {
      if ( (v17 >> 13) & 1 )
      {
        v18 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v16);
      }
      else if ( (v17 >> 12) & 1 )
      {
        v18 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v16->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v18 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v16->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v18 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v16);
    }
    v19 = v18;
    if ( v18 )
    {
      v20 = v18->mDamageRig;
      if ( v20 )
      {
        HIDWORD(v2->m_BoundComponentHandles.mNode.mPrev[3].mNext) = LODWORD(v20->mPaintEffectApplied);
        v21 = v2->m_BoundComponentHandles.mNode.mPrev;
        v22 = v20->mPaintEffect.y;
        v23 = v20->mPaintEffect.z;
        *(float *)&v21[1].mPrev = v20->mPaintEffect.x;
        *((float *)&v21[1].mPrev + 1) = v22;
        *(float *)&v21[1].mNext = v23;
        HIDWORD(v21[1].mNext) = (_DWORD)FLOAT_1_0;
        HIDWORD(v2->m_BoundComponentHandles.mNode.mPrev[2].mNext) = LODWORD(v19->mDamageRig->mCharredEffectAmount);
      }
    }
  }
}

