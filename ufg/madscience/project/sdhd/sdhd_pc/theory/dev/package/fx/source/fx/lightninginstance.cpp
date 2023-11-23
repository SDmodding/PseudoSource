// File Line: 18
// RVA: 0x1C1830
void __fastcall Render::LightningInstance::LightningInstance(Render::LightningInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::LightningInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mHeadModel);
  UFG::qResourceHandle::qResourceHandle(&this->mTailModel);
  this->mHeadTransformNodeComponent.mPrev = &this->mHeadTransformNodeComponent;
  this->mHeadTransformNodeComponent.mNext = &this->mHeadTransformNodeComponent;
  this->mHeadTransformNodeComponent.m_pPointer = 0i64;
  this->mTailTransformNodeComponent.mPrev = &this->mTailTransformNodeComponent;
  this->mTailTransformNodeComponent.mNext = &this->mTailTransformNodeComponent;
  this->mTailTransformNodeComponent.m_pPointer = 0i64;
  this->mHeadLightweightFXPosition.m_pPointer = 0i64;
  this->mTailLightweightFXPosition.m_pPointer = 0i64;
  this->mElectrifiedObject = 0i64;
  Render::LightningInstance::sLastInstanceAdded = this;
}

// File Line: 23
// RVA: 0x1C3F90
void __fastcall Render::LightningInstance::~LightningInstance(Render::LightningInstance *this)
{
  Render::LightningInstance *v2; // rax
  Render::ElectrifiedObject *mElectrifiedObject; // rax
  Render::LightweightFXPosition *m_pPointer; // rax
  Render::LightweightFXPosition *v5; // rcx
  Render::LightweightFXPosition *v6; // rax
  Render::LightweightFXPosition *v7; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mTailTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mHeadTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v24; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v25; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::LightningInstance::`vftable;
  v2 = Render::LightningInstance::sLastInstanceAdded;
  if ( this == Render::LightningInstance::sLastInstanceAdded )
    v2 = 0i64;
  Render::LightningInstance::sLastInstanceAdded = v2;
  mElectrifiedObject = this->mElectrifiedObject;
  if ( mElectrifiedObject )
  {
    mElectrifiedObject->status = Status_Terminated;
    this->mElectrifiedObject->killTime = (float)(UFG::Metrics::msInstance.mSimTime_Temp + this->mMaxBoltLifeTime) + 1.0;
  }
  m_pPointer = this->mTailLightweightFXPosition.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v5 = this->mTailLightweightFXPosition.m_pPointer;
    if ( v5->mReferenceCount <= 0 )
    {
      operator delete[](v5);
      this->mTailLightweightFXPosition.m_pPointer = 0i64;
    }
  }
  v6 = this->mHeadLightweightFXPosition.m_pPointer;
  if ( v6 )
  {
    --v6->mReferenceCount;
    v7 = this->mHeadLightweightFXPosition.m_pPointer;
    if ( v7->mReferenceCount <= 0 )
    {
      operator delete[](v7);
      this->mHeadLightweightFXPosition.m_pPointer = 0i64;
    }
  }
  p_mTailTransformNodeComponent = &this->mTailTransformNodeComponent;
  if ( this->mTailTransformNodeComponent.m_pPointer )
  {
    mPrev = p_mTailTransformNodeComponent->mPrev;
    mNext = this->mTailTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTailTransformNodeComponent->mPrev = p_mTailTransformNodeComponent;
    this->mTailTransformNodeComponent.mNext = &this->mTailTransformNodeComponent;
  }
  this->mTailTransformNodeComponent.m_pPointer = 0i64;
  v11 = p_mTailTransformNodeComponent->mPrev;
  v12 = this->mTailTransformNodeComponent.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_mTailTransformNodeComponent->mPrev = p_mTailTransformNodeComponent;
  this->mTailTransformNodeComponent.mNext = &this->mTailTransformNodeComponent;
  p_mHeadTransformNodeComponent = &this->mHeadTransformNodeComponent;
  if ( this->mHeadTransformNodeComponent.m_pPointer )
  {
    v14 = p_mHeadTransformNodeComponent->mPrev;
    v15 = this->mHeadTransformNodeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_mHeadTransformNodeComponent->mPrev = p_mHeadTransformNodeComponent;
    this->mHeadTransformNodeComponent.mNext = &this->mHeadTransformNodeComponent;
  }
  this->mHeadTransformNodeComponent.m_pPointer = 0i64;
  v16 = p_mHeadTransformNodeComponent->mPrev;
  v17 = this->mHeadTransformNodeComponent.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_mHeadTransformNodeComponent->mPrev = p_mHeadTransformNodeComponent;
  this->mHeadTransformNodeComponent.mNext = &this->mHeadTransformNodeComponent;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mTailModel, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mTailModel);
  v20 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v20;
  }
  UFG::qResourceHandle::Close(&this->mHeadModel, v20);
  UFG::qResourceHandle::~qResourceHandle(&this->mHeadModel);
  v22 = `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::LightningSettings>::`2::result )
  {
    v23 = UFG::qResourceWarehouse::Instance();
    v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x21AE1C64u);
    `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result = v22;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, v22);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v24 = this->mPrev;
  v25 = this->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 37
// RVA: 0x1CEB90
void __fastcall Render::LightningInstance::Init(Render::LightningInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mSettingsHandle.mData == 0i64;
  this->mTotalEmitted = 0;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    Inventory = `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::LightningSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x21AE1C64u);
      `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  v6 = `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result;
  mSettingsId = this->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::LightningSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0x21AE1C64u);
    `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0x21AE1C64u, mSettingsId, v6);
}

// File Line: 48
// RVA: 0x1C5900
void __fastcall Render::LightningInstance::Activate(Render::LightningInstance *this)
{
  UFG::qResourceData *mData; // r14
  unsigned int modelToEmitFromUID; // edx
  unsigned int v4; // esi
  Render::FXOverride *m_pPointer; // rdi
  UFG::SimComponent *v6; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mHeadTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *v12; // rsi
  UFG::qMatrix44 *p_mBasis; // rdx
  Render::FXOverride *v14; // rcx
  float sizeScale; // xmm6_4
  Render::LightweightFXPosition *v16; // rax
  Render::LightweightFXPosition *v17; // rax
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  Render::LightweightFXPosition *v21; // rax
  Render::LightweightFXPosition *v22; // rax
  Render::ElectrifiedObject *mElectrifiedObject; // rax
  UFG::SimComponent *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::SimComponent *v26; // rdx
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v27; // rcx
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v28; // rax
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rsi
  UFG::SimComponent *v31; // rsi
  char *mTriangleInfo; // rdx
  Render::ElectrifiedObject dst; // [rsp+30h] [rbp-71h] BYREF
  Render::FXOverride *v34; // [rsp+108h] [rbp+67h]
  Render::ElectrifiedObject *p_dst; // [rsp+110h] [rbp+6Fh]

  dst.headModel = (Illusion::Model *)-2i64;
  if ( !this->mIsActive )
  {
    mData = this->mSettingsHandle.mData;
    if ( mData )
    {
      this->mMaxBoltLifeTime = *((float *)&mData[2].mResourceHandles.mNode.mNext + 1);
      modelToEmitFromUID = *(_DWORD *)&mData[2].mDebugName[20];
      v4 = *(_DWORD *)&mData[2].mDebugName[24];
      m_pPointer = this->mContainer->mStateBlockOverride.m_pPointer;
      if ( m_pPointer )
        ++m_pPointer->mReferenceCount;
      v34 = m_pPointer;
      if ( m_pPointer && m_pPointer->modelToEmitFromUID != -1 )
      {
        modelToEmitFromUID = m_pPointer->modelToEmitFromUID;
        v4 = modelToEmitFromUID;
      }
      if ( !this->mHeadModel.mData && modelToEmitFromUID != -1 )
        UFG::qTypedResourceHandle<2729299319,Illusion::Model>::Init(&this->mHeadModel, modelToEmitFromUID);
      if ( !this->mTailModel.mData && v4 != -1 )
        UFG::qTypedResourceHandle<2729299319,Illusion::Model>::Init(&this->mTailModel, v4);
      if ( !this->mHeadTransformNodeComponent.m_pPointer )
      {
        v6 = this->mContainer->mParentNode.m_pPointer;
        p_mHeadTransformNodeComponent = &this->mHeadTransformNodeComponent;
        if ( this->mHeadTransformNodeComponent.m_pPointer )
        {
          mPrev = p_mHeadTransformNodeComponent->mPrev;
          mNext = this->mHeadTransformNodeComponent.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mHeadTransformNodeComponent->mPrev = p_mHeadTransformNodeComponent;
          this->mHeadTransformNodeComponent.mNext = &this->mHeadTransformNodeComponent;
        }
        this->mHeadTransformNodeComponent.m_pPointer = v6;
        if ( v6 )
        {
          v10 = v6->m_SafePointerList.mNode.mPrev;
          v10->mNext = p_mHeadTransformNodeComponent;
          p_mHeadTransformNodeComponent->mPrev = v10;
          this->mHeadTransformNodeComponent.mNext = &v6->m_SafePointerList.mNode;
          v6->m_SafePointerList.mNode.mPrev = p_mHeadTransformNodeComponent;
        }
      }
      if ( !this->mTailTransformNodeComponent.m_pPointer )
        UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
          &this->mTailTransformNodeComponent,
          &this->mHeadTransformNodeComponent);
      this->mTotalEmitted = 0;
      *(_WORD *)&this->mIsActive = 1;
      this->mActivateTime = this->mStartTime;
      mContainer = this->mContainer;
      v12 = mContainer->mParentNode.m_pPointer;
      if ( !v12 || mContainer->mBasisRelativeToParent )
      {
        p_mBasis = &mContainer->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
        p_mBasis = (UFG::qMatrix44 *)&v12[2];
      }
      Render::FXInstance::CalcBasisHelper(
        (UFG::qMatrix44 *)&dst,
        p_mBasis,
        &this->mContainer->mSettings,
        this->mComponentIndex,
        this->mStartTime);
      v14 = this->mContainer->mStateBlockOverride.m_pPointer;
      if ( v14 )
        sizeScale = v14->sizeScale;
      else
        sizeScale = *(float *)&FLOAT_1_0;
      if ( !this->mHeadTransformNodeComponent.m_pPointer
        && !this->mTailTransformNodeComponent.m_pPointer
        && !this->mHeadLightweightFXPosition.m_pPointer
        && !this->mTailLightweightFXPosition.m_pPointer )
      {
        v16 = (Render::LightweightFXPosition *)UFG::qMalloc(0x14ui64, UFG::gGlobalNewName, 0i64);
        p_dst = (Render::ElectrifiedObject *)v16;
        if ( v16 )
          v16->mReferenceCount = 0;
        else
          v16 = 0i64;
        FX::SharedPointer<Render::LightweightFXPosition>::operator=(&this->mHeadLightweightFXPosition, v16);
        this->mHeadLightweightFXPosition.m_pPointer->alpha = 1.0;
        v17 = this->mHeadLightweightFXPosition.m_pPointer;
        v18 = *(float *)&dst.mNext;
        v17->position.x = *(float *)&dst.mNext;
        v19 = *((float *)&dst.mNext + 1);
        v17->position.y = *((float *)&dst.mNext + 1);
        v20 = *(float *)&dst.headTransformNodeComponent.mPrev;
        v17->position.z = *(float *)&dst.headTransformNodeComponent.mPrev;
        v21 = (Render::LightweightFXPosition *)UFG::qMalloc(0x14ui64, UFG::gGlobalNewName, 0i64);
        p_dst = (Render::ElectrifiedObject *)v21;
        if ( v21 )
          v21->mReferenceCount = 0;
        else
          v21 = 0i64;
        FX::SharedPointer<Render::LightweightFXPosition>::operator=(&this->mTailLightweightFXPosition, v21);
        this->mTailLightweightFXPosition.m_pPointer->alpha = 1.0;
        v22 = this->mTailLightweightFXPosition.m_pPointer;
        v22->position.x = v18;
        v22->position.y = v19;
        v22->position.z = v20;
      }
      mElectrifiedObject = this->mElectrifiedObject;
      if ( mElectrifiedObject )
      {
        mElectrifiedObject->status = Status_Active;
      }
      else
      {
        p_dst = &dst;
        dst.mPrev = &dst;
        dst.mNext = &dst;
        memset(&dst.headTransformNodeComponent, 0, sizeof(dst.headTransformNodeComponent));
        *((float *)&dst.tailLightWeightPosition.m_pPointer + 1) = sizeScale;
        LODWORD(dst.tailLightWeightPosition.m_pPointer) = 0;
        dst.tailTransformNodeComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)mData;
        dst.tailTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)this->mHeadModel.mData;
        dst.tailTransformNodeComponent.m_pPointer = (UFG::SimComponent *)this->mTailModel.mData;
        v24 = this->mHeadTransformNodeComponent.m_pPointer;
        if ( v24 )
        {
          v25 = v24->m_SafePointerList.mNode.mPrev;
          v25->mNext = &dst.headTransformNodeComponent;
          dst.headTransformNodeComponent.mPrev = v25;
          dst.headTransformNodeComponent.mNext = &v24->m_SafePointerList.mNode;
          v24->m_SafePointerList.mNode.mPrev = &dst.headTransformNodeComponent;
        }
        v26 = this->mTailTransformNodeComponent.m_pPointer;
        if ( dst.headTransformNodeComponent.mPrev )
        {
          v27 = dst.mPrev;
          v28 = dst.mNext;
          dst.mPrev->mNext = dst.mNext;
          v28->mPrev = v27;
          dst.mPrev = &dst;
          dst.mNext = &dst;
        }
        dst.headTransformNodeComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v26;
        if ( v26 )
        {
          v29 = (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)v26->m_SafePointerList.mNode.mPrev;
          v29->mNext = &dst;
          dst.mPrev = v29;
          dst.mNext = (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)&v26->m_SafePointerList;
          v26->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&dst;
        }
        v30 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)this->mHeadLightweightFXPosition.m_pPointer;
        if ( v30 != dst.headTransformNodeComponent.mNext )
        {
          if ( dst.headTransformNodeComponent.mNext )
          {
            if ( (int)--LODWORD(dst.headTransformNodeComponent.mNext->mPrev) <= 0 )
            {
              operator delete[](dst.headTransformNodeComponent.mNext);
              dst.headTransformNodeComponent.mNext = 0i64;
            }
          }
          dst.headTransformNodeComponent.mNext = v30;
          if ( v30 )
            ++LODWORD(v30->mPrev);
        }
        v31 = (UFG::SimComponent *)this->mTailLightweightFXPosition.m_pPointer;
        if ( v31 != dst.headTransformNodeComponent.m_pPointer )
        {
          if ( dst.headTransformNodeComponent.m_pPointer )
          {
            if ( (int)--LODWORD(dst.headTransformNodeComponent.m_pPointer->vfptr) <= 0 )
            {
              operator delete[](dst.headTransformNodeComponent.m_pPointer);
              dst.headTransformNodeComponent.m_pPointer = 0i64;
            }
          }
          dst.headTransformNodeComponent.m_pPointer = v31;
          if ( v31 )
            ++LODWORD(v31->vfptr);
        }
        this->mElectrifiedObject = Render::LightningManager::AddElectrifiedObject(&Render::gLightningManager, &dst);
        Render::ElectrifiedObject::~ElectrifiedObject(&dst);
      }
      if ( m_pPointer )
      {
        if ( --m_pPointer->mReferenceCount <= 0 )
        {
          mTriangleInfo = (char *)m_pPointer->mTriangleInfo;
          if ( mTriangleInfo )
            UFG::qMemoryPool::Free(m_pPointer->mMemoryPool, mTriangleInfo);
          --Render::FXOverride::sNumInstancesInService;
          operator delete[](m_pPointer);
        }
      }
    }
  }
}

// File Line: 156
// RVA: 0x1CAB60
void __fastcall Render::LightningInstance::Deactivate(Render::LightningInstance *this, bool willLoopImmediately)
{
  bool v2; // zf
  Render::ElectrifiedObject *mElectrifiedObject; // rax

  if ( this->mIsActive )
  {
    v2 = !this->mIsSuspended;
    this->mIsActive = 0;
    if ( !v2 )
      this->mIsSuspended = 0;
    mElectrifiedObject = this->mElectrifiedObject;
    if ( mElectrifiedObject )
      mElectrifiedObject->status = Status_Inactive;
  }
}

