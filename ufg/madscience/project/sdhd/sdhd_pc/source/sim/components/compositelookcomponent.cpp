// File Line: 66
// RVA: 0x154DA20
__int64 dynamic_initializer_for__UFG::CompositeLookComponent::s_CompositeLookComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CompositeLookComponent::s_CompositeLookComponentList__);
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
  UFG::SimComponent::SimComponent(this, 0);
  this->UFG::ICompositeLook::vfptr = (UFG::ICompositeLookVtbl *)&UFG::ICompositeLook::`vftable;
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent>;
  this->mNext = &this->UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeLookComponent::`vftable{for `UFG::SimComponent};
  this->UFG::ICompositeLook::vfptr = (UFG::ICompositeLookVtbl *)&UFG::CompositeLookComponent::`vftable{for `UFG::ICompositeLook};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CompositeLookComponent::`vftable{for `UFG::UpdateInterface};
  this->mColourTints = 0i64;
  this->mForceTransparencyState = -1;
  this->mHighlightingMode = 0;
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0>::RebindingComponentHandle<UFG::BaseAnimationComponent,0>(&this->mAnimationComponent);
  UFG::SimComponent::AddType(
    this,
    UFG::CompositeLookComponent::_CompositeLookComponentTypeUID,
    "CompositeLookComponent");
  this->mSceneryInstance = 0i64;
}

// File Line: 81
// RVA: 0x58A7F0
UFG::CompositeLookComponent *__fastcall UFG::CompositeLookComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  __int64 v6; // rbx
  UFG::CompositeLookComponent *result; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *mPrev; // rax
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CompositeDrawable::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::CompositeLookComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( required || result )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB0ui64, "CompositeLookComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::CompositeLookComponent::CompositeLookComponent((UFG::CompositeLookComponent *)v9);
      v6 = v10;
    }
    mPrev = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)(v6 + 80);
    *(_QWORD *)(v6 + 80) = mPrev;
    *(_QWORD *)(v6 + 88) = &UFG::CompositeLookComponent::s_CompositeLookComponentList;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)(v6 + 80);
    UFG::SimObjectModifier::SimObjectModifier(&v12, sceneObject->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, (UFG::SimComponent *)v6, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    return (UFG::CompositeLookComponent *)v6;
  }
  return result;
}

// File Line: 99
// RVA: 0x586490
void __fastcall UFG::CompositeLookComponent::OnAttach(UFG::CompositeLookComponent *this, UFG::SimObjectGame *object)
{
  UFG::CompositeDrawableComponent *m_pComponent; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::ICompositeLook *v7; // rax
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *p_mAnimationComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  CB_SceneryInstance *mSceneryInstance; // rax

  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)object->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)object->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                object,
                                UFG::CompositeDrawableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::CompositeDrawableComponent::_TypeUID);
        m_pComponent = (UFG::CompositeDrawableComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)object->m_Components.p[14].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v7 = &this->UFG::ICompositeLook;
  if ( !this )
    v7 = 0i64;
  p_mAnimationComponent = &this->mAnimationComponent;
  m_pComponent->mCompositeLook = v7;
  if ( this->mAnimationComponent.m_pSimComponent )
  {
    mPrev = p_mAnimationComponent->mPrev;
    mNext = this->mAnimationComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mAnimationComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mAnimationComponent.m_pSimObject = 0i64;
    this->mAnimationComponent.mNext = &this->mAnimationComponent;
    p_mAnimationComponent->mPrev = p_mAnimationComponent;
    goto LABEL_22;
  }
  if ( this->mAnimationComponent.m_pSimObject
    && (p_mAnimationComponent->mPrev != p_mAnimationComponent
     || this->mAnimationComponent.mNext != &this->mAnimationComponent) )
  {
    v11 = p_mAnimationComponent->mPrev;
    v12 = this->mAnimationComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_21;
  }
LABEL_22:
  this->mAnimationComponent.m_Changed = 1;
  this->mAnimationComponent.m_pSimObject = object;
  this->mAnimationComponent.m_TypeUID = UFG::BaseAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0>::BindInternal<UFG::SimObject>(
    &this->mAnimationComponent,
    object);
  this->mSceneryInstance = &m_pComponent->mSceneryInstance;
  this->UFG::ICompositeLook::vfptr->OnUpdateMaterial(&this->UFG::ICompositeLook, m_pComponent);
  mSceneryInstance = this->mSceneryInstance;
  mSceneryInstance->Value0[3] = 0.0;
  mSceneryInstance->Mask[3] = 0.0;
}

// File Line: 112
// RVA: 0x586B40
void __fastcall UFG::CompositeLookComponent::OnDetach(UFG::CompositeLookComponent *this)
{
  UFG::RebindingComponentHandle<UFG::BaseAnimationComponent,0> *p_mAnimationComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  p_mAnimationComponent = &this->mAnimationComponent;
  if ( this->mAnimationComponent.m_pSimComponent )
  {
    mNext = this->mAnimationComponent.mNext;
    mPrev = p_mAnimationComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAnimationComponent->mPrev = p_mAnimationComponent;
    this->mAnimationComponent.mNext = &this->mAnimationComponent;
    this->mAnimationComponent.m_Changed = 1;
    this->mAnimationComponent.m_pSimComponent = 0i64;
    this->mAnimationComponent.m_pSimObject = 0i64;
    this->mSceneryInstance = 0i64;
  }
  else if ( !this->mAnimationComponent.m_pSimObject
         || p_mAnimationComponent->mPrev == p_mAnimationComponent
         && this->mAnimationComponent.mNext == &this->mAnimationComponent )
  {
    this->mAnimationComponent.m_Changed = 1;
    this->mSceneryInstance = 0i64;
  }
  else
  {
    v5 = this->mAnimationComponent.mNext;
    v6 = p_mAnimationComponent->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    p_mAnimationComponent->mPrev = p_mAnimationComponent;
    p_mAnimationComponent->mNext = p_mAnimationComponent;
    p_mAnimationComponent->m_Changed = 1;
    p_mAnimationComponent->m_pSimObject = 0i64;
    this->mSceneryInstance = 0i64;
  }
}

// File Line: 118
// RVA: 0x5875F0
void __fastcall UFG::CompositeLookComponent::OnReset(
        UFG::CompositeLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  signed int v3; // r8d

  mNext = this->m_BoundComponentHandles.mNode.mNext;
  *(_WORD *)((char *)&this->m_pSimObject + 3) = 255;
  HIDWORD(mNext[3].mNext) = 0;
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
void __fastcall UFG::CompositeLookComponent::OnDrawSkin(
        UFG::CompositeLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::View *view,
        ModelType::ModelBindingSkin *model_binding,
        Render::SkinningParams *skinning_params)
{
  UFG::SimObjectGame *m_pSimComponent; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::BaseCameraComponent *CurrentBaseCamera; // rbx
  char *v9; // rax
  UFG::qMatrix44 *local_transform; // rcx
  char *v11; // rdx
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // xmm2_4
  float z; // xmm0_4
  unsigned __int64 mSimTimeMSec; // rax

  if ( !skinning_params->user_data_1 )
  {
    m_pSimComponent = (UFG::SimObjectGame *)this[-1].mAnimationComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      m_Flags = m_pSimComponent->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimComponent->m_Components.p[9].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pSimComponent->m_Components.p[8].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                           m_pSimComponent,
                           UFG::BaseAnimationComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimComponent, UFG::BaseAnimationComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = m_pSimComponent->m_Components.p[9].m_pComponent;
      }
      if ( m_pComponent )
      {
        if ( HIDWORD(m_pComponent[3].vfptr) == 0xA0A883FD )
        {
          CurrentBaseCamera = UFG::GetCurrentBaseCamera();
          v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
          local_transform = skinning_params->local_transform;
          v11 = v9;
          v12 = CurrentBaseCamera->mCamera.mTransformation.v3.z - local_transform->v3.z;
          v13 = CurrentBaseCamera->mCamera.mTransformation.v3.y - local_transform->v3.y;
          *(float *)v9 = CurrentBaseCamera->mCamera.mTransformation.v3.x - local_transform->v3.x;
          *((float *)v9 + 1) = v13;
          *((float *)v9 + 2) = v12;
          v14 = LODWORD(CurrentBaseCamera->mCamera.mTransformation.v2.y) ^ _xmm[0];
          z = CurrentBaseCamera->mCamera.mTransformation.v2.z;
          *((_DWORD *)v9 + 3) = LODWORD(CurrentBaseCamera->mCamera.mTransformation.v2.x) ^ _xmm[0];
          *((_DWORD *)v9 + 4) = v14;
          *((_DWORD *)v9 + 5) = LODWORD(z) ^ _xmm[0];
          mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
          *((_DWORD *)v11 + 8) = 1184645120;
          *((_DWORD *)v11 + 9) = 1050253722;
          *((_QWORD *)v11 + 3) = mSimTimeMSec;
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
  unsigned int mFrameCount; // r8d

  mFrameCount = Illusion::gEngine.mFrameCount;
  *(_WORD *)this->mTransparencyState = 0;
  *(_WORD *)&this->mTransparencyState[2] = (unsigned __int8)((int)(mFrameCount - 1) % 255);
}

// File Line: 164
// RVA: 0x5822E0
void __fastcall UFG::CompositeLookComponent::ForceVisibleTransparency(UFG::CompositeLookComponent *this)
{
  unsigned int mFrameCount; // r8d

  mFrameCount = Illusion::gEngine.mFrameCount;
  this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = (int)(mFrameCount - 1) % 255;
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
  signed int v1; // r8d

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
void __fastcall UFG::CompositeLookComponent::OnUpdateCullResults(
        UFG::CompositeLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::ViewSettings *view_settings)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  UFG::SimObjectGame *m_pSimComponent; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  char v9; // al
  int v10; // ebx
  int v11; // esi
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  int v14; // eax
  int m_pSimObject_low; // r8d
  int v16; // r11d
  int v17; // ecx
  int v18; // r9d
  int v19; // r10d
  int v20; // eax

  v4 = view_settings->mCullPixelDensityThreshold * 1.0700001;
  if ( view_settings->mCullIndex >= 6 )
    v5 = *(float *)&FLOAT_1_0;
  else
    v5 = composite_drawable->mCullResults->mPixelCoverage[view_settings->mCullIndex];
  m_pSimComponent = (UFG::SimObjectGame *)this[-1].mAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    m_Flags = m_pSimComponent->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pSimComponent->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::StreamedResourceComponent *)m_pSimComponent->m_Components.p[7].m_pComponent;
      else
        m_pComponent = (UFG::StreamedResourceComponent *)((m_Flags & 0x1000) != 0
                                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pSimComponent,
                                                            UFG::StreamedResourceComponent::_TypeUID)
                                                        : UFG::SimObject::GetComponentOfType(
                                                            m_pSimComponent,
                                                            UFG::StreamedResourceComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pSimComponent->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent && UFG::StreamedResourceComponent::AreResourcesLoaded(m_pComponent) != 1 )
    {
      BYTE2(this->m_pSimObject) = Render::TransparencySystem::msTransparencyFrameCounter
                                + (int)Render::TransparencySystem::msTransparencyFrameCounter / 255;
      return;
    }
  }
  v9 = BYTE3(this->m_pSimObject);
  v10 = Render::TransparencySystem::msOpaqueIndex;
  v11 = 0;
  if ( v4 >= v5 )
    v10 = 0;
  if ( v9 != -1 )
    v10 = v9;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  if ( BYTE3(this->m_pSimObject) || !ComponentOfType || ComponentOfType[24].m_NameUID != 5 )
  {
    m_pSimObject_low = LOBYTE(this->m_pSimObject);
    v17 = BYTE4(this->m_pSimObject) != 0 ? 2 : 0;
    v18 = (v17 == 1) + 1;
    v19 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    if ( v17 == 2 )
    {
      if ( (v19 & 1) == 0 )
      {
LABEL_33:
        if ( m_pSimObject_low >= v10 )
        {
          if ( m_pSimObject_low > v10 )
            m_pSimObject_low -= v18;
        }
        else
        {
          m_pSimObject_low += v18;
        }
      }
    }
    else
    {
      v16 = BYTE2(this->m_pSimObject);
      v20 = v19 - (v16 + 1) % 255;
      if ( v20 < 0 )
        v20 = (v16 + 1) % 255 - v19;
      if ( v20 <= 0 )
        goto LABEL_33;
      m_pSimObject_low = v10;
    }
    v14 = Render::TransparencySystem::msOpaqueIndex;
    BYTE2(this->m_pSimObject) = v19;
    if ( m_pSimObject_low > 0 )
      v11 = m_pSimObject_low;
    goto LABEL_43;
  }
  v14 = Render::TransparencySystem::msOpaqueIndex;
  if ( v10 > 0 )
    v11 = v10;
  BYTE2(this->m_pSimObject) = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
LABEL_43:
  if ( v11 < v14 )
    LOBYTE(v14) = v11;
  BYTE1(this->m_pSimObject) = v10;
  LOBYTE(this->m_pSimObject) = v14;
}

// File Line: 238
// RVA: 0x587550
_BOOL8 __fastcall UFG::CompositeLookComponent::OnIsCulled(
        UFG::CompositeLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::View *view)
{
  Illusion::SubmitContext *mSubmitContext; // r9
  UFG::SimObject *m_pSimObject; // rdx

  mSubmitContext = view->mSubmitContext;
  m_pSimObject = this->m_pSimObject;
  mSubmitContext[1].vfptr = 0i64;
  mSubmitContext[1].mStateValues.mSetValueMask.mFlags[0] = (unsigned __int64)m_pSimObject;
  return LOBYTE(this->m_pSimObject) == 0;
}

// File Line: 246
// RVA: 0x582060
void __fastcall UFG::CompositeLookComponent::ForceTransparencyOnAttachments(
        UFG::CompositeLookComponent *this,
        int transparency_target)
{
  UFG::SimComponent *m_pSimComponent; // rax
  char v3; // di
  UFG::SimObject **p_m_pSimObject; // rsi
  __int64 p_mNext; // rbx
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimComponent = this->mAnimationComponent.m_pSimComponent;
  v3 = transparency_target;
  if ( m_pSimComponent )
    m_pSimComponent = *(UFG::SimComponent **)&m_pSimComponent[2].m_TypeUID;
  if ( m_pSimComponent )
  {
    if ( HIDWORD(m_pSimComponent[3].m_SafePointerList.mNode.mNext) != transparency_target )
    {
      p_m_pSimObject = &m_pSimComponent[2].m_pSimObject;
      p_mNext = (__int64)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext[-1].mNext;
      HIDWORD(m_pSimComponent[3].m_SafePointerList.mNode.mNext) = transparency_target;
      if ( (UFG::SimObject **)p_mNext != &m_pSimComponent[2].m_pSimObject )
      {
        do
        {
          v6 = *(UFG::SimObjectGame **)(p_mNext + 104);
          if ( v6 && (v6->m_Flags & 0x2000) != 0 )
          {
            m_Flags = v6->m_Flags;
            if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CompositeLookComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v6, UFG::CompositeLookComponent::_TypeUID);
            if ( ComponentOfTypeHK )
              BYTE3(ComponentOfTypeHK[1].m_pSimObject) = v3;
          }
          p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
        }
        while ( (UFG::SimObject **)p_mNext != p_m_pSimObject );
      }
    }
  }
}

// File Line: 267
// RVA: 0x587740
void __fastcall UFG::CompositeLookComponent::OnSetHidden(
        UFG::CompositeLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        const bool bIsHidden)
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
  UFG::CompositeLookComponent::CompositeLookComponent(this);
  this->UFG::CompositeLookComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleLookComponent::`vftable{for `UFG::SimComponent};
  this->UFG::CompositeLookComponent::UFG::ICompositeLook::vfptr = (UFG::ICompositeLookVtbl *)&UFG::VehicleLookComponent::`vftable{for `UFG::ICompositeLook};
  this->UFG::CompositeLookComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::VehicleLookComponent::`vftable{for `UFG::UpdateInterface};
  this->mVehicleEffectsComponent = 0i64;
  *(_WORD *)&this->mVehiclePaintID = -1;
  UFG::SimComponent::AddType(this, UFG::VehicleLookComponent::_VehicleLookComponentTypeUID, "VehicleLookComponent");
}

// File Line: 310
// RVA: 0x587E40
void __fastcall UFG::VehicleLookComponent::OnUpdateMaterial(
        UFG::VehicleLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::SimObjectGame *m_pSimObject; // rbx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qPropertyList *v8; // r14
  UFG::qPropertyList *v9; // r15
  int v10; // eax
  const char *v11; // r14
  UFG::qResourceWarehouse *v12; // rax
  Illusion::StateBlockInventory *Inventory; // rax
  Illusion::StateBlockInventory *v14; // rdi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *StateBlock; // rax
  unsigned int v16; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v17; // rax
  unsigned int v18; // r8d
  __int64 mNumOverrides; // rdx
  unsigned int v20; // r9d
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qBaseNodeRB *Skeleton; // rax
  char *v24; // rax
  int v25; // eax
  const char *v26; // rdi
  UFG::qResourceWarehouse *v27; // rax
  Illusion::StateBlockInventory *v28; // rax
  Illusion::StateBlockInventory *v29; // rsi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v30; // rax
  unsigned int v31; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v32; // rax
  unsigned int v33; // r9d
  __int64 v34; // r10
  __int16 v35; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qBaseNodeRB *v37; // rax
  char *v38; // rax
  unsigned int original_name_uid; // [rsp+28h] [rbp-120h]
  char dest[280]; // [rsp+30h] [rbp-118h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)composite_drawable->m_pSimObject;
  m_pSceneObj = m_pSimObject->m_pSceneObj;
  if ( m_pSceneObj )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  mNext = this->m_BoundComponentHandles.mNode.mNext;
  LOWORD(this->mVehicleInteriorMS.v0.x) = -1;
  HIDWORD(mNext->mNext) = -1082130432;
  if ( mpWritableProperties )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_VehicleLook,
           DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_VehicleLookGlass,
           DEPTH_RECURSE);
    if ( v8 )
    {
      v10 = UFG::qRandom(v8->mNumElements, (unsigned int *)&UFG::qDefaultSeed);
      if ( v10 < 0 )
        v10 = -v10;
      LOBYTE(this->mVehicleInteriorMS.v0.x) = v10;
      v11 = UFG::qPropertyList::Get<char const *>(v8, (char)v10);
      if ( v11 )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        Inventory = (Illusion::StateBlockInventory *)UFG::qResourceWarehouse::GetInventory(v12, 0x4D04C7F2u);
        v14 = Inventory;
        if ( !s_DefaultPaintUID )
        {
          StateBlock = Illusion::StateBlockInventory::GetStateBlock(Inventory, 0x26228D0Fu, 1);
          if ( StateBlock )
            s_DefaultPaintUID = (unsigned int)StateBlock[1].mNode.mNext;
          else
            s_DefaultPaintUID = 0;
        }
        UFG::qSPrintf(dest, 255, "StateBlock.%s_VehicleLook", v11);
        v16 = UFG::qStringHashUpper32(dest, -1);
        v17 = Illusion::StateBlockInventory::GetStateBlock(v14, v16, 1);
        v18 = s_DefaultPaintUID;
        if ( s_DefaultPaintUID && v17 )
        {
          mNumOverrides = composite_drawable->mMaterialModifier.mNumOverrides;
          v20 = (unsigned int)v17[1].mNode.mNext;
          composite_drawable->mMaterialModifier.mNumOverrides = mNumOverrides + 1;
          Illusion::ParamOverride::SetOverride(
            &composite_drawable->mMaterialModifier.mOverrides[mNumOverrides],
            0xC6D01635,
            0x4D04C7F2u,
            v20,
            OVERRIDE_EQUALS,
            v18);
        }
        else
        {
          m_Flags = m_pSimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p[14].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
            {
              m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
            }
            else if ( (m_Flags & 0x1000) != 0 )
            {
              m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                               m_pSimObject,
                               UFG::CompositeDrawableComponent::_TypeUID);
            }
            else
            {
              m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CompositeDrawableComponent::_TypeUID);
            }
          }
          else
          {
            m_pComponent = m_pSimObject->m_Components.p[14].m_pComponent;
          }
          Skeleton = ModelType::GetSkeleton((ModelType *)m_pComponent[22].m_SafePointerList.mNode.mNext);
          v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)Skeleton);
          UFG::qPrintf("Warning: Cannot set %s VehicleLook override to %s\n", v24, v11);
        }
      }
    }
    if ( v9 )
    {
      v25 = UFG::qRandom(v9->mNumElements, (unsigned int *)&UFG::qDefaultSeed);
      if ( v25 < 0 )
        v25 = -v25;
      BYTE1(this->mVehicleInteriorMS.v0.x) = v25;
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
        UFG::qSPrintf(dest, 255, "StateBlock.%s_VehicleLook", v26);
        v31 = UFG::qStringHashUpper32(dest, -1);
        v32 = Illusion::StateBlockInventory::GetStateBlock(v29, v31, 1);
        if ( s_DefaultGlassUID && v32 )
        {
          v33 = (unsigned int)v32[1].mNode.mNext;
          v34 = composite_drawable->mMaterialModifier.mNumOverrides;
          original_name_uid = s_DefaultGlassUID;
          composite_drawable->mMaterialModifier.mNumOverrides = v34 + 1;
          Illusion::ParamOverride::SetOverride(
            &composite_drawable->mMaterialModifier.mOverrides[v34],
            0xC6D01635,
            0x4D04C7F2u,
            v33,
            OVERRIDE_EQUALS,
            original_name_uid);
        }
        else
        {
          v35 = m_pSimObject->m_Flags;
          if ( (v35 & 0x4000) != 0 || v35 < 0 )
          {
            ComponentOfTypeHK = m_pSimObject->m_Components.p[14].m_pComponent;
          }
          else if ( (v35 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = m_pSimObject->m_Components.p[9].m_pComponent;
          }
          else if ( (v35 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::CompositeDrawableComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::CompositeDrawableComponent::_TypeUID);
          }
          v37 = ModelType::GetSkeleton((ModelType *)ComponentOfTypeHK[22].m_SafePointerList.mNode.mNext);
          v38 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v37);
          UFG::qPrintf("Warning: Cannot set %s VehicleLook override to %s\n", v38, v26);
        }
      }
    }
  }
}f("Warning: Cannot set %s VehicleLook override to %s\n", v38, v26);
        }
      }
    }
  }
}

// File Line: 411
// RVA: 0x587020
void __fastcall UFG::VehicleLookComponent::OnDrawRigid(
        UFG::VehicleLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::View *view,
        ModelType::ModelBindingRigid *model_binding)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  __int64 v9; // r10
  __int64 i; // rdx
  __int64 v11; // r8
  __int64 v12; // rcx
  ModelType::ModelBindingRigid **v13; // rax

  mNext = this->m_BoundComponentHandles.mNode.mNext;
  z = UFG::qVector4::msOne.z;
  w = UFG::qVector4::msOne.w;
  x = UFG::qVector4::msOne.x;
  HIDWORD(mNext[2].mPrev) = LODWORD(UFG::qVector4::msOne.y);
  *(float *)&mNext[2].mPrev = x;
  *(float *)&mNext[2].mNext = z;
  *((float *)&mNext[2].mNext + 1) = w;
  if ( *(_QWORD *)&this->mHighlightingMode )
  {
    v9 = 0i64;
    for ( i = 0i64; i < 96; i += 24i64 )
    {
      v11 = *(_QWORD *)&this->mHighlightingMode;
      if ( *(_BYTE *)(*(_QWORD *)(v11 + 1832) + v9 + 1324) )
      {
        v12 = 0i64;
        v13 = (ModelType::ModelBindingRigid **)(i + v11 + 88);
        while ( model_binding != *v13 )
        {
          ++v12;
          ++v13;
          if ( v12 >= 3 )
            goto LABEL_9;
        }
        LODWORD(this->m_BoundComponentHandles.mNode.mNext[2].mPrev) = 0;
      }
LABEL_9:
      ++v9;
    }
  }
}

// File Line: 436
// RVA: 0x587440
void __fastcall UFG::VehicleLookComponent::OnDrawSkin(
        UFG::VehicleLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::View *view,
        ModelType::ModelBindingSkin *model_binding,
        Render::SkinningParams *skinning_params)
{
  UFG::qMatrix44 *p_mAnimationComponent; // rbx
  __int64 v9; // rax
  float *v10; // rbx
  Render::SkinningParams *v11; // rbx

  p_mAnimationComponent = (UFG::qMatrix44 *)&this->mAnimationComponent;
  SkeletalPose::GetPositionMS(composite_drawable->mPose, 0, (UFG::qMatrix44 *)&this->mAnimationComponent);
  skinning_params->mRigidTransform = p_mAnimationComponent;
  v9 = *(_QWORD *)&this->mHighlightingMode;
  if ( v9 && *(_QWORD *)(v9 + 0x728) )
  {
    v10 = (float *)UFG::qLinearAllocator::Malloc(
                     Illusion::gEngine.FrameMemory,
                     32 * skinning_params->bone_matrix_count,
                     0x10u);
    DamageRig::GetWeightList(
      *(DamageRig **)(*(_QWORD *)&this->mHighlightingMode + 1832i64),
      v10,
      skinning_params->bone_matrix_count,
      skinning_params->bone_remap_array);
    skinning_params->user_data_0 = v10;
  }
  if ( !view->mSettings->mCullIndex && view->mSubmitContext->mRenderPass == Solid )
  {
    if ( model_binding->mDecalLayer )
    {
      v11 = (Render::SkinningParams *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xA8u, 0x10u);
      UFG::qMemCopy(v11, skinning_params, 0xA8u);
      ModelType::SkinnedDecalLayer::Draw(model_binding->mDecalLayer, &Render::Skinning::gSkinning, v11);
    }
  }
}

// File Line: 459
// RVA: 0x58D840
void __fastcall UFG::VehicleLookComponent::Update(UFG::VehicleLookComponent *this, float delta_sec)
{
  UFG::SimObjectGame *v3; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  __int64 v7; // rax
  int v8; // xmm0_4

  if ( -1.0 == *((float *)&this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev->mNext
               + 1) )
  {
    v3 = *(UFG::SimObjectGame **)&this[-1].mVehicleInteriorMS.v3.x;
    if ( v3 )
    {
      m_Flags = v3->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v3->m_Components.p[14].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = v3->m_Components.p[9].m_pComponent;
        else
          m_pComponent = (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeDrawableComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(v3, UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = v3->m_Components.p[14].m_pComponent;
      }
      if ( m_pComponent )
      {
        mPrev = m_pComponent[19].m_BoundComponentHandles.mNode.mPrev;
        if ( mPrev )
          *((float *)&this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev->mNext
          + 1) = (float)(*(float *)&mPrev[1].mNext - *(float *)&mPrev->mNext) * gHeightGrim;
      }
    }
  }
  v7 = *(_QWORD *)this->mTransparencyState;
  if ( v7 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(v7 + 1832) + 1060i64) )
      v8 = (int)FLOAT_1_0;
    else
      v8 = 0;
    LODWORD(this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev->UFG::CompositeLookComponent::UFG::SimComponent::mPrev) = v8;
    HIDWORD(this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev->UFG::CompositeLookComponent::UFG::SimComponent::mPrev) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)this->mTransparencyState + 1832i64) + 1320i64);
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)this->mTransparencyState + 1832i64) + 1056i64) = 0;
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
  UFG::CompositeLookComponent::CompositeLookComponent(this);
  this->UFG::CompositeLookComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterLookComponent::`vftable{for `UFG::SimComponent};
  this->UFG::CompositeLookComponent::UFG::ICompositeLook::vfptr = (UFG::ICompositeLookVtbl *)&UFG::CharacterLookComponent::`vftable{for `UFG::ICompositeLook};
  this->UFG::CompositeLookComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CharacterLookComponent::`vftable{for `UFG::UpdateInterface};
  this->mOverlayTextureID = 0;
  this->mIsSkinSSEnabled = 0;
  *(_QWORD *)&this->mSweatLevel = 0i64;
}

// File Line: 493
// RVA: 0x58A6E0
UFG::CharacterLookComponent *__fastcall UFG::CharacterLookComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  __int64 v6; // rbx
  UFG::CharacterLookComponent *result; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *mPrev; // rax
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CompositeDrawable::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::CharacterLookComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( required || result )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC8ui64, "CharacterLookComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::CharacterLookComponent::CharacterLookComponent((UFG::CharacterLookComponent *)v9);
      v6 = v10;
    }
    mPrev = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)(v6 + 80);
    *(_QWORD *)(v6 + 80) = mPrev;
    *(_QWORD *)(v6 + 88) = &UFG::CompositeLookComponent::s_CompositeLookComponentList;
    UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)(v6 + 80);
    UFG::SimObjectModifier::SimObjectModifier(&v12, sceneObject->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, (UFG::SimComponent *)v6, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    return (UFG::CharacterLookComponent *)v6;
  }
  return result;
}

// File Line: 512
// RVA: 0x587C60
void __fastcall UFG::CharacterLookComponent::OnUpdateMaterial(
        UFG::CharacterLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::qPropertySet *mNext; // rcx
  UFG::qPropertySet *v6; // rax
  component_CompositeDrawable *MemImagePtr; // rcx
  Illusion::MaterialModifierParams<10> *p_mMaterialModifier; // r15
  __int64 mOffset; // rax
  UFG::qPropertyList *v10; // rbx
  __int64 v11; // rax
  UFG::qPropertyList *v12; // rsi
  unsigned int RandomIndex; // eax
  unsigned int mUID; // ebx
  unsigned int mNumElements; // ebp
  unsigned int v16; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qPropertyList *v19; // rax
  UFG::qSymbolUC *v20; // rax
  unsigned int *p_mUID; // rcx
  unsigned int v22; // r10d
  unsigned int mHighlightingMode; // r8d
  Illusion::ParamOverride *v24; // rcx
  int v25; // [rsp+60h] [rbp+8h] BYREF

  m_pSimObject = composite_drawable->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  if ( m_pSimObject )
  {
    mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
    if ( !mNext )
      mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
  }
  else
  {
    mNext = 0i64;
  }
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mNext,
         (UFG::qArray<unsigned long,0> *)&component_CompositeDrawable::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 )
    MemImagePtr = (component_CompositeDrawable *)UFG::qPropertySet::GetMemImagePtr(v6);
  else
    MemImagePtr = 0i64;
  *((_BYTE *)&this->mHighlightingMode + 4) = MemImagePtr->SkinSSEnabled;
  p_mMaterialModifier = &composite_drawable->mMaterialModifier;
  mOffset = MemImagePtr->OverlayWeights.mOffset;
  if ( mOffset )
  {
    v10 = (UFG::qPropertyList *)((char *)&MemImagePtr->OverlayWeights + mOffset);
    if ( v10 )
    {
      if ( v10->mNumElements )
      {
        v11 = MemImagePtr->OverlayTextures.mOffset;
        v12 = v11 ? (UFG::qPropertyList *)((char *)&MemImagePtr->OverlayTextures + v11) : 0i64;
        RandomIndex = UFG::qPropertyList::GetRandomIndex(v10);
        mUID = UFG::qPropertyList::Get<UFG::qSymbol>(v10, RandomIndex)->mUID;
        mNumElements = v12->mNumElements;
        v16 = 0;
        if ( mNumElements )
        {
          while ( 1 )
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v16);
            if ( ValuePtr && *(_QWORD *)ValuePtr )
              v18 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            else
              v18 = 0i64;
            if ( v18->mName.mUID == mUID )
              break;
            if ( ++v16 >= mNumElements )
              goto LABEL_27;
          }
          v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v18,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_Textures,
                  DEPTH_RECURSE);
          nextTextureIndex %= v19->mNumElements;
          v25 = -1;
          v20 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v19, nextTextureIndex);
          p_mUID = (unsigned int *)&v25;
          if ( v20 )
            p_mUID = &v20->mUID;
          this->mHighlightingMode = *p_mUID;
          ++nextTextureIndex;
        }
      }
    }
  }
LABEL_27:
  if ( this->mHighlightingMode )
  {
    if ( (_S12_9 & 1) != 0 )
    {
      v22 = uidTexDiffuseBlend;
    }
    else
    {
      _S12_9 |= 1u;
      v22 = UFG::qStringHash32("texDiffuseBlend", 0xFFFFFFFF);
      uidTexDiffuseBlend = v22;
    }
    mHighlightingMode = this->mHighlightingMode;
    v24 = &p_mMaterialModifier->mOverrides[p_mMaterialModifier->mNumOverrides++];
    Illusion::ParamOverride::SetTextureOverride(v24, v22, mHighlightingMode, OVERRIDE_ALWAYS, 0);
  }
}

// File Line: 562
// RVA: 0x587880
void __fastcall UFG::CharacterLookComponent::OnUpdateCullResults(
        UFG::CharacterLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::ViewSettings *view_settings)
{
  float v6; // xmm0_4
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObjectGame *v9; // rcx
  int v10; // edi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( view_settings->mCullIndex >= 6 )
    v6 = 0.0;
  else
    v6 = composite_drawable->mCullResults->mDistance[view_settings->mCullIndex];
  if ( v6 >= 4.0
    || (CurrentBaseCamera = UFG::GetCurrentBaseCamera(), (v8 = CurrentBaseCamera) != 0i64)
    && (UFG::SimComponent::IsType(CurrentBaseCamera, UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID)
     || UFG::SimComponent::IsType(v8, UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID)
     || UFG::SimComponent::IsType(v8, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID)) )
  {
    if ( !BYTE3(this->m_pSimObject) )
    {
      UFG::CompositeLookComponent::ForceTransparencyOnAttachments(
        (UFG::CharacterLookComponent *)((char *)this - 64),
        -1);
      BYTE3(this->m_pSimObject) = -1;
    }
  }
  else
  {
    v9 = *(UFG::SimObjectGame **)&this[-1].mOverlayTextureID;
    v10 = -1;
    if ( v9 )
    {
      m_Flags = v9->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v9->m_Components.p[37].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CameraSubject::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::CameraSubject::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = v9->m_Components.p[31].m_pComponent;
      }
      if ( m_pComponent
        && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[29].__vecDelDtor)(m_pComponent) )
      {
        v10 = 0;
      }
    }
    UFG::CompositeLookComponent::ForceTransparencyOnAttachments((UFG::CharacterLookComponent *)((char *)this - 64), v10);
    BYTE3(this->m_pSimObject) = v10;
  }
  UFG::CompositeLookComponent::OnUpdateCullResults(this, composite_drawable, view_settings);
}

// File Line: 600
// RVA: 0x586B30
// attributes: thunk
void __fastcall UFG::VehicleLookComponent::OnDetach(UFG::VehicleLookComponent *this)
{
  UFG::CompositeLookComponent::OnDetach(this);
}

// File Line: 605
// RVA: 0x587570
void __fastcall UFG::CharacterLookComponent::OnReset(
        UFG::CharacterLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  signed int v3; // r8d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax

  mNext = this->m_BoundComponentHandles.mNode.mNext;
  *(_WORD *)((char *)&this->m_pSimObject + 3) = 255;
  HIDWORD(mNext[3].mNext) = 0;
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
void __fastcall UFG::CharacterLookComponent::OnDraw(
        UFG::CharacterLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::View *view,
        UFG::qMatrix44 *local_matrix)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbx
  Illusion::StateValues *StateValues; // rax

  mPrev = this->mAnimationComponent.UFG::CompositeLookComponent::mPrev;
  StateValues = Render::View::GetStateValues(view);
  StateValues->mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
  StateValues->mParamValues[57] = mPrev;
}

// File Line: 619
// RVA: 0x5870D0
void __fastcall UFG::CharacterLookComponent::OnDrawSkin(
        UFG::CharacterLookComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        Render::View *view,
        ModelType::ModelBindingSkin *model_binding,
        Render::SkinningParams *skinning_params)
{
  __int64 v6; // rcx
  __int64 v8; // rax
  UFG::SimObjectCVBase *v9; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v11; // rax
  UFG::CharacterAnimationComponent *v12; // rsi
  float *v13; // rbx
  Illusion::StateValues *StateValues; // rax
  bool v15; // cf
  __int64 v16; // rbx
  void *v17; // rbx
  Illusion::StateValues *v18; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> v19; // [rsp+20h] [rbp-18h]

  v6 = *(_QWORD *)&this->m_Flags;
  if ( v6 )
  {
    v8 = v6 + 16i64 * model_binding->mModelIndex;
    *(float *)&v19.mPrev = *(float *)v8 * *(float *)v8;
    *((float *)&v19.mPrev + 1) = *(float *)(v8 + 4) * *(float *)(v8 + 4);
    *(float *)&v19.mNext = *(float *)(v8 + 8) * *(float *)(v8 + 8);
    HIDWORD(v19.mNext) = *(_DWORD *)(v8 + 12);
  }
  else
  {
    v19 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase>)UFG::qColour::White;
  }
  *this->m_BoundComponentHandles.mNode.mNext = v19;
  v9 = *(UFG::SimObjectCVBase **)&this[-1].mOverlayTextureID;
  if ( v9 )
  {
    m_Flags = v9->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v11 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
    }
    else
    {
      v11 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v9,
                                                   UFG::CharacterAnimationComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   v9,
                                                   UFG::CharacterAnimationComponent::_TypeUID));
    }
    v12 = v11;
    if ( v11 )
    {
      if ( v11->mDamageRig )
      {
        v13 = (float *)UFG::qLinearAllocator::Malloc(
                         Illusion::gEngine.FrameMemory,
                         32 * skinning_params->bone_matrix_count,
                         0x10u);
        CharacterDamageRig::GetCharacterWeightList(
          v12->mDamageRig,
          v13,
          skinning_params->bone_matrix_count,
          skinning_params->bone_remap_array);
        skinning_params->user_data_0 = v13;
        skinning_params->no_override = v12->mDamageRig->mDamaged;
      }
    }
  }
  StateValues = Render::View::GetStateValues(view);
  v15 = *(float *)&this->mSceneryInstance > 0.0;
  this->mAnimationComponent.UFG::CompositeLookComponent::mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)StateValues->mParamValues[57];
  if ( (v15 || *((float *)&this->mSceneryInstance + 1) > 0.0) && !Render::View::GetStateValues(view)->mParamValues[57] )
  {
    v16 = *((_QWORD *)Render::GetRenderCallbacks()->mRenderParam + 11);
    if ( v16 )
    {
      v17 = *(void **)(v16 + 24);
      v18 = Render::View::GetStateValues(view);
      v18->mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
      v18->mParamValues[57] = v17;
    }
  }
}

// File Line: 649
// RVA: 0x58D600
void __fastcall UFG::CharacterLookComponent::Update(UFG::CharacterLookComponent *this, float delta_sec)
{
  UFG::TimeOfDayManager *Instance; // rax
  __int64 v4; // r8
  float v5; // xmm10_4
  float mSkyIrradValue; // xmm6_4
  __int16 v7; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v9; // zf
  UFG::SimObjectGame *v10; // rcx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  unsigned int mHighlightingMode; // eax
  UFG::SimObjectCVBase *v16; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  UFG::CharacterAnimationComponent *v19; // rdx
  CharacterDamageRig *mDamageRig; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  Instance = UFG::TimeOfDayManager::GetInstance();
  v4 = *(_QWORD *)&this[-1].mAnimationComponent.m_Changed;
  v5 = Instance->m_WeatherState - 1.0;
  mSkyIrradValue = UFG::RenderWorld::msExposureMetering->mSkyIrradValue;
  if ( v4 )
  {
    v7 = *(_WORD *)(v4 + 76);
    if ( (v7 & 0x4000) != 0 )
    {
      ComponentOfTypeHK = *(UFG::SimComponent **)(*(_QWORD *)(v4 + 104) + 704i64);
    }
    else if ( v7 < 0 || (v7 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            *(UFG::SimObjectGame **)&this[-1].mAnimationComponent.m_Changed,
                            UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v9 = (v7 & 0x1000) == 0;
      v10 = *(UFG::SimObjectGame **)&this[-1].mAnimationComponent.m_Changed;
      ComponentOfTypeHK = v9
                        ? UFG::SimObject::GetComponentOfType(v10, UFG::CharacterOccupantComponent::_TypeUID)
                        : UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      mSkyIrradValue = 0.0;
  }
  if ( v5 <= 0.0 || mSkyIrradValue <= 0.2 || (v11 = *((float *)&this->mHighlightingMode + 1), v11 >= 1.0) )
  {
    v12 = *((float *)&this->mHighlightingMode + 1);
    if ( v12 > 0.0 )
      *((float *)&this->mHighlightingMode + 1) = v12 - (float)(delta_sec * 0.016666668);
  }
  else
  {
    *((float *)&this->mHighlightingMode + 1) = (float)((float)(mSkyIrradValue * v5) * (float)(delta_sec * 0.1)) + v11;
  }
  v13 = *((float *)&this->mHighlightingMode + 1);
  if ( v13 <= 0.0 )
  {
    v13 = 0.0;
  }
  else if ( v13 >= 1.0 )
  {
    v13 = *(float *)&FLOAT_1_0;
  }
  mPrev = this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev;
  mHighlightingMode = this->mHighlightingMode;
  *((float *)&this->mHighlightingMode + 1) = v13;
  HIDWORD(mPrev[2].mPrev) = mHighlightingMode;
  LODWORD(this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev[2].mNext) = *(&this->mHighlightingMode + 1);
  v16 = *(UFG::SimObjectCVBase **)&this[-1].mAnimationComponent.m_Changed;
  if ( v16 )
  {
    m_Flags = v16->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v16);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v16);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v16,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              v16,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    v19 = ComponentOfType;
    if ( ComponentOfType )
    {
      mDamageRig = ComponentOfType->mDamageRig;
      if ( mDamageRig )
      {
        HIDWORD(this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev[3].mNext) = LODWORD(mDamageRig->mPaintEffectApplied);
        v21 = this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev;
        y = mDamageRig->mPaintEffect.y;
        z = mDamageRig->mPaintEffect.z;
        *(float *)&v21[1].mPrev = mDamageRig->mPaintEffect.x;
        *((float *)&v21[1].mPrev + 1) = y;
        *(float *)&v21[1].mNext = z;
        HIDWORD(v21[1].mNext) = (_DWORD)FLOAT_1_0;
        HIDWORD(this->m_BoundComponentHandles.mNode.UFG::CompositeLookComponent::UFG::SimComponent::mPrev[2].mNext) = LODWORD(v19->mDamageRig->mCharredEffectAmount);
      }
    }
  }
}

