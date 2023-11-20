// File Line: 18
// RVA: 0x1C1830
void __fastcall Render::LightningInstance::LightningInstance(Render::LightningInstance *this)
{
  Render::LightningInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v3; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::LightningInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mHeadModel.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mTailModel.mPrev);
  v3 = &v1->mHeadTransformNodeComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->mHeadTransformNodeComponent.m_pPointer = 0i64;
  v4 = &v1->mTailTransformNodeComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mTailTransformNodeComponent.m_pPointer = 0i64;
  v1->mHeadLightweightFXPosition.m_pPointer = 0i64;
  v1->mTailLightweightFXPosition.m_pPointer = 0i64;
  v1->mElectrifiedObject = 0i64;
  Render::LightningInstance::sLastInstanceAdded = v1;
}

// File Line: 23
// RVA: 0x1C3F90
void __fastcall Render::LightningInstance::~LightningInstance(Render::LightningInstance *this)
{
  Render::LightningInstance *v1; // rbx
  Render::LightningInstance *v2; // rax
  Render::ElectrifiedObject *v3; // rax
  Render::LightweightFXPosition *v4; // rax
  Render::LightweightFXPosition *v5; // rcx
  Render::LightweightFXPosition *v6; // rax
  Render::LightweightFXPosition *v7; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v24; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v25; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v26; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::LightningInstance::`vftable;
  v2 = Render::LightningInstance::sLastInstanceAdded;
  if ( this == Render::LightningInstance::sLastInstanceAdded )
    v2 = 0i64;
  Render::LightningInstance::sLastInstanceAdded = v2;
  v3 = this->mElectrifiedObject;
  if ( v3 )
  {
    v3->status = 2;
    this->mElectrifiedObject->killTime = (float)(UFG::Metrics::msInstance.mSimTime_Temp + this->mMaxBoltLifeTime) + 1.0;
  }
  v4 = this->mTailLightweightFXPosition.m_pPointer;
  if ( v4 )
  {
    --v4->mReferenceCount;
    v5 = this->mTailLightweightFXPosition.m_pPointer;
    if ( v5->mReferenceCount <= 0 )
    {
      operator delete[](v5);
      v1->mTailLightweightFXPosition.m_pPointer = 0i64;
    }
  }
  v6 = v1->mHeadLightweightFXPosition.m_pPointer;
  if ( v6 )
  {
    --v6->mReferenceCount;
    v7 = v1->mHeadLightweightFXPosition.m_pPointer;
    if ( v7->mReferenceCount <= 0 )
    {
      operator delete[](v7);
      v1->mHeadLightweightFXPosition.m_pPointer = 0i64;
    }
  }
  v8 = &v1->mTailTransformNodeComponent;
  if ( v1->mTailTransformNodeComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v1->mTailTransformNodeComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v1->mTailTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mTailTransformNodeComponent.mPrev;
  }
  v1->mTailTransformNodeComponent.m_pPointer = 0i64;
  v11 = v8->mPrev;
  v12 = v1->mTailTransformNodeComponent.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v1->mTailTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mTailTransformNodeComponent.mPrev;
  v13 = &v1->mHeadTransformNodeComponent;
  if ( v1->mHeadTransformNodeComponent.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v1->mHeadTransformNodeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v1->mHeadTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mHeadTransformNodeComponent.mPrev;
  }
  v1->mHeadTransformNodeComponent.m_pPointer = 0i64;
  v16 = v13->mPrev;
  v17 = v1->mHeadTransformNodeComponent.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v1->mHeadTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mHeadTransformNodeComponent.mPrev;
  v18 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v18;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mTailModel.mPrev, v18);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mTailModel.mPrev);
  v20 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v20;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mHeadModel.mPrev, v20);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mHeadModel.mPrev);
  v22 = `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::LightningSettings>::`2::result )
  {
    v23 = UFG::qResourceWarehouse::Instance();
    v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x21AE1C64u);
    `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result = v22;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v22);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v24 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v25 = v1->mPrev;
  v26 = v1->mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v24->mPrev = v24;
  v24->mNext = v24;
}

// File Line: 37
// RVA: 0x1CEB90
void __fastcall Render::LightningInstance::Init(Render::LightningInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  Render::LightningInstance *v3; // rbx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mSettingsHandle.mData == 0i64;
  v3 = this;
  this->mTotalEmitted = 0;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    v4 = `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::LightningSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x21AE1C64u);
      `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, v4);
  }
  v6 = `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result;
  v7 = v3->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::LightningSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0x21AE1C64u);
    `UFG::qGetResourceInventory<Render::LightningSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0x21AE1C64u, v7, v6);
}

// File Line: 48
// RVA: 0x1C5900
void __fastcall Render::LightningInstance::Activate(Render::LightningInstance *this)
{
  Render::LightningInstance *v1; // rbx
  UFG::qResourceData *v2; // r14
  unsigned int v3; // edx
  unsigned int v4; // esi
  Render::FXOverride *v5; // rdi
  UFG::SimComponent *v6; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  Render::FXInstance *v11; // rax
  UFG::qMatrix44 *v12; // rsi
  UFG::qMatrix44 *v13; // rdx
  Render::FXOverride *v14; // rcx
  int v15; // xmm6_4
  Render::LightweightFXPosition *v16; // rax
  float *v17; // rax
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  Render::LightweightFXPosition *v21; // rax
  Render::LightweightFXPosition *v22; // rax
  Render::ElectrifiedObject *v23; // rax
  UFG::SimComponent *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::SimComponent *v28; // rdx
  __int64 v29; // rcx
  _QWORD *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  Render::LightweightFXPosition *v32; // rsi
  Render::LightweightFXPosition *v33; // rsi
  Render::FXOverride::PrecalculatedTriangle *v34; // rdx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-71h]
  int v36; // [rsp+78h] [rbp-29h]
  int v37; // [rsp+7Ch] [rbp-25h]
  __int64 v38; // [rsp+88h] [rbp-19h]
  Render::FXOverride *v39; // [rsp+108h] [rbp+67h]
  UFG::qMatrix44 *v40; // [rsp+110h] [rbp+6Fh]

  v38 = -2i64;
  v1 = this;
  if ( !this->mIsActive )
  {
    v2 = this->mSettingsHandle.mData;
    if ( v2 )
    {
      this->mMaxBoltLifeTime = *((float *)&v2[2].mResourceHandles.mNode.mNext + 1);
      v3 = *(_DWORD *)&v2[2].mDebugName[20];
      v4 = *(_DWORD *)&v2[2].mDebugName[24];
      v5 = this->mContainer->mStateBlockOverride.m_pPointer;
      if ( v5 )
        ++v5->mReferenceCount;
      v39 = v5;
      if ( v5 && v5->modelToEmitFromUID != -1 )
      {
        v3 = v5->modelToEmitFromUID;
        v4 = v5->modelToEmitFromUID;
      }
      if ( !this->mHeadModel.mData && v3 != -1 )
        UFG::qTypedResourceHandle<2729299319,Illusion::Model>::Init(
          (UFG::qTypedResourceHandle<2729299319,Illusion::Model> *)&this->mHeadModel.mPrev,
          v3);
      if ( !v1->mTailModel.mData && v4 != -1 )
        UFG::qTypedResourceHandle<2729299319,Illusion::Model>::Init(
          (UFG::qTypedResourceHandle<2729299319,Illusion::Model> *)&v1->mTailModel.mPrev,
          v4);
      if ( !v1->mHeadTransformNodeComponent.m_pPointer )
      {
        v6 = v1->mContainer->mParentNode.m_pPointer;
        v7 = &v1->mHeadTransformNodeComponent;
        if ( v1->mHeadTransformNodeComponent.m_pPointer )
        {
          v8 = v7->mPrev;
          v9 = v1->mHeadTransformNodeComponent.mNext;
          v8->mNext = v9;
          v9->mPrev = v8;
          v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
          v1->mHeadTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mHeadTransformNodeComponent.mPrev;
        }
        v1->mHeadTransformNodeComponent.m_pPointer = v6;
        if ( v6 )
        {
          v10 = v6->m_SafePointerList.mNode.mPrev;
          v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
          v7->mPrev = v10;
          v1->mHeadTransformNodeComponent.mNext = &v6->m_SafePointerList.mNode;
          v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
        }
      }
      if ( !v1->mTailTransformNodeComponent.m_pPointer )
        UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
          &v1->mTailTransformNodeComponent,
          &v1->mHeadTransformNodeComponent);
      v1->mTotalEmitted = 0;
      *(_WORD *)&v1->mIsActive = 1;
      v1->mActivateTime = v1->mStartTime;
      v11 = v1->mContainer;
      v12 = (UFG::qMatrix44 *)v11->mParentNode.m_pPointer;
      if ( !v12 || v11->mBasisRelativeToParent )
      {
        v13 = &v11->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11->mParentNode.m_pPointer);
        v13 = v12 + 2;
      }
      Render::FXInstance::CalcBasisHelper(
        &dst,
        v13,
        (UFG::qResourceHandle *)&v1->mContainer->mSettings.mPrev,
        v1->mComponentIndex,
        v1->mStartTime);
      v14 = v1->mContainer->mStateBlockOverride.m_pPointer;
      if ( v14 )
        v15 = LODWORD(v14->sizeScale);
      else
        v15 = (signed int)FLOAT_1_0;
      if ( !v1->mHeadTransformNodeComponent.m_pPointer
        && !v1->mTailTransformNodeComponent.m_pPointer
        && !v1->mHeadLightweightFXPosition.m_pPointer
        && !v1->mTailLightweightFXPosition.m_pPointer )
      {
        v16 = (Render::LightweightFXPosition *)UFG::qMalloc(0x14ui64, UFG::gGlobalNewName, 0i64);
        v40 = (UFG::qMatrix44 *)v16;
        if ( v16 )
          v16->mReferenceCount = 0;
        else
          v16 = 0i64;
        FX::SharedPointer<Render::LightweightFXPosition>::operator=(&v1->mHeadLightweightFXPosition, v16);
        v1->mHeadLightweightFXPosition.m_pPointer->alpha = 1.0;
        v17 = (float *)&v1->mHeadLightweightFXPosition.m_pPointer->mReferenceCount;
        v18 = dst.v0.z;
        v17[1] = dst.v0.z;
        v19 = dst.v0.w;
        v17[2] = dst.v0.w;
        v20 = dst.v1.x;
        v17[3] = dst.v1.x;
        v21 = (Render::LightweightFXPosition *)UFG::qMalloc(0x14ui64, UFG::gGlobalNewName, 0i64);
        v40 = (UFG::qMatrix44 *)v21;
        if ( v21 )
          v21->mReferenceCount = 0;
        else
          v21 = 0i64;
        FX::SharedPointer<Render::LightweightFXPosition>::operator=(&v1->mTailLightweightFXPosition, v21);
        v1->mTailLightweightFXPosition.m_pPointer->alpha = 1.0;
        v22 = v1->mTailLightweightFXPosition.m_pPointer;
        v22->position.x = v18;
        v22->position.y = v19;
        v22->position.z = v20;
      }
      v23 = v1->mElectrifiedObject;
      if ( v23 )
      {
        v23->status = 0;
      }
      else
      {
        v40 = &dst;
        *(_QWORD *)&dst.v0.x = &dst;
        *(_QWORD *)&dst.v0.z = &dst;
        *(_QWORD *)&dst.v1.x = 0i64;
        *(_QWORD *)&dst.v1.z = 0i64;
        *(_QWORD *)&dst.v2.x = 0i64;
        v37 = v15;
        v36 = 0;
        *(_QWORD *)&dst.v2.z = v2;
        *(_QWORD *)&dst.v3.x = v1->mHeadModel.mData;
        *(_QWORD *)&dst.v3.z = v1->mTailModel.mData;
        v24 = v1->mHeadTransformNodeComponent.m_pPointer;
        if ( v24 )
        {
          v27 = v24->m_SafePointerList.mNode.mPrev;
          v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&dst.v1;
          *(_QWORD *)&dst.v1.x = v27;
          *(_QWORD *)&dst.v1.z = (char *)v24 + 8;
          v24->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&dst.v1;
        }
        v28 = v1->mTailTransformNodeComponent.m_pPointer;
        if ( *(_QWORD *)&dst.v1.x )
        {
          v29 = *(_QWORD *)&dst.v0.x;
          v30 = *(_QWORD **)&dst.v0.z;
          *(_QWORD *)(*(_QWORD *)&dst.v0.x + 8i64) = *(_QWORD *)&dst.v0.z;
          *v30 = v29;
          *(_QWORD *)&dst.v0.x = &dst;
          *(_QWORD *)&dst.v0.z = &dst;
        }
        *(_QWORD *)&dst.v1.x = v28;
        if ( v28 )
        {
          v31 = v28->m_SafePointerList.mNode.mPrev;
          v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&dst;
          *(_QWORD *)&dst.v0.x = v31;
          *(_QWORD *)&dst.v0.z = (char *)v28 + 8;
          v28->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&dst;
        }
        v32 = v1->mHeadLightweightFXPosition.m_pPointer;
        if ( v32 != *(Render::LightweightFXPosition **)&dst.v1.z )
        {
          if ( *(_QWORD *)&dst.v1.z )
          {
            if ( --**(_DWORD **)&dst.v1.z <= 0 )
            {
              operator delete[](*(void **)&dst.v1.z);
              *(_QWORD *)&dst.v1.z = 0i64;
            }
          }
          *(_QWORD *)&dst.v1.z = v32;
          if ( v32 )
            ++v32->mReferenceCount;
        }
        v33 = v1->mTailLightweightFXPosition.m_pPointer;
        if ( v33 != *(Render::LightweightFXPosition **)&dst.v2.x )
        {
          if ( *(_QWORD *)&dst.v2.x )
          {
            if ( --**(_DWORD **)&dst.v2.x <= 0 )
            {
              operator delete[](*(void **)&dst.v2.x);
              *(_QWORD *)&dst.v2.x = 0i64;
            }
          }
          *(_QWORD *)&dst.v2.x = v33;
          if ( v33 )
            ++v33->mReferenceCount;
        }
        v1->mElectrifiedObject = Render::LightningManager::AddElectrifiedObject(
                                   &Render::gLightningManager,
                                   (Render::ElectrifiedObject *)&dst);
        Render::ElectrifiedObject::~ElectrifiedObject((Render::ElectrifiedObject *)&dst);
      }
      if ( v5 )
      {
        if ( --v5->mReferenceCount <= 0 )
        {
          v34 = v5->mTriangleInfo;
          if ( v34 )
            UFG::qMemoryPool::Free(v5->mMemoryPool, v34);
          --Render::FXOverride::sNumInstancesInService;
          operator delete[](v5);
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
  Render::ElectrifiedObject *v3; // rax

  if ( this->mIsActive )
  {
    v2 = this->mIsSuspended == 0;
    this->mIsActive = 0;
    if ( !v2 )
      this->mIsSuspended = 0;
    v3 = this->mElectrifiedObject;
    if ( v3 )
      v3->status = 1;
  }
}

