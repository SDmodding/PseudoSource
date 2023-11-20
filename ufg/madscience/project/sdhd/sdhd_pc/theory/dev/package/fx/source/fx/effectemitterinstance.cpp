// File Line: 26
// RVA: 0x1C1080
void __fastcall Render::EffectEmitterInstance::EffectEmitterInstance(Render::EffectEmitterInstance *this)
{
  Render::EffectEmitterInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::EffectEmitterInstance::`vftable';
  this->mActiveEffects[0].node = 0i64;
  this->mActiveEffects[0].effectHandle = -1;
  this->mActiveEffects[1].node = 0i64;
  this->mActiveEffects[1].effectHandle = -1;
  this->mActiveEffects[2].node = 0i64;
  this->mActiveEffects[2].effectHandle = -1;
  this->mActiveEffects[3].node = 0i64;
  this->mActiveEffects[3].effectHandle = -1;
  this->mActiveEffects[4].node = 0i64;
  this->mActiveEffects[4].effectHandle = -1;
  this->mActiveEffects[5].node = 0i64;
  this->mActiveEffects[5].effectHandle = -1;
  this->mActiveEffects[6].node = 0i64;
  this->mActiveEffects[6].effectHandle = -1;
  this->mActiveEffects[7].node = 0i64;
  this->mActiveEffects[7].effectHandle = -1;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  v1->mNumActiveNodes = 0;
  v1->mIsHidden = 0;
  v1->mTimeOfLastUpdate = 0.0;
}

// File Line: 31
// RVA: 0x1C3380
void __fastcall Render::EffectEmitterInstance::~EffectEmitterInstance(Render::EffectEmitterInstance *this)
{
  Render::EffectEmitterInstance *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::EffectEmitterInstance::`vftable';
  v2 = (UFG::qResourceHandle *)&this->mSettingsHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xFF1F2832);
    `UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  v5 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 36
// RVA: 0x1CE440
void __fastcall Render::EffectEmitterInstance::Init(Render::EffectEmitterInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  Render::EffectEmitterInstance *v3; // rbx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mSettingsHandle.mData == 0i64;
  v3 = this;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    v4 = `UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0xFF1F2832);
      `UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, v4);
  }
  v6 = `UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result;
  v7 = v3->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xFF1F2832);
    `UFG::qGetResourceInventory<Render::EffectEmitterSettings>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0xFF1F2832, v7, v6);
}

// File Line: 51
// RVA: 0x1C63E0
void __fastcall Render::EffectEmitterInstance::ActivateEffect(Render::EffectEmitterInstance *this, unsigned int i, Render::EffectEmitterSettings *efx, UFG::qMatrix44 *curBasis)
{
  UFG::qMatrix44 *mBasis; // rbp
  Render::EffectEmitterSettings *v5; // rbx
  __int64 v6; // r14
  Render::EffectEmitterInstance *v7; // rsi
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::TransformNodeComponent *v10; // rax
  UFG::TransformNodeComponent *v11; // rdi
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm8_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm7_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm10_4
  float v25; // xmm9_4
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  signed __int64 v32; // rcx
  unsigned int v33; // ebx
  UFG::qVector3 pos; // [rsp+48h] [rbp-80h]

  mBasis = curBasis;
  v5 = efx;
  v6 = i;
  v7 = this;
  v8 = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(v8, 0x110ui64, "EffectEmitter::TransformNode", 0i64, 1u);
  *(_QWORD *)&pos.x = v9;
  if ( v9 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v9, 0x52E9019Bu, 0i64, 0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v11 )
  {
    if ( v5->mJitterType )
    {
      if ( v5->mJitterType == 1 )
      {
        v15 = UFG::qRandom(1.0, &UFG::qDefaultSeed) - 0.5;
        v16 = UFG::qRandom(1.0, &UFG::qDefaultSeed) - 0.5;
        v12 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) - 0.5) * v5->mJitter.x;
        v13 = v16 * v5->mJitter.y;
        v14 = v15 * v5->mJitter.z;
      }
      else
      {
        v12 = 0.0;
        v13 = 0.0;
        v14 = 0.0;
      }
    }
    else
    {
      do
      {
        v17 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * 2.0) - 1.0;
        v18 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * 2.0) - 1.0;
        v19 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * 2.0) - 1.0;
      }
      while ( (float)((float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v17 * v17)) >= 1.0 );
      v20 = (float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v17 * v17);
      v21 = 0.0;
      if ( v20 != 0.0 )
        v21 = 1.0 / fsqrt(v20);
      v12 = v19 * v21;
      v13 = v18 * v21;
      v14 = v17 * v21;
    }
    pos.x = v12 + mBasis->v3.x;
    pos.y = v13 + mBasis->v3.y;
    pos.z = v14 + mBasis->v3.z;
    UFG::TransformNodeComponent::SetLocalTranslation(v11, &pos);
    v7->mActiveEffects[v7->mNumActiveNodes].node = v11;
    v22 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    v23 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    v24 = (float)((float)(v5->mGlobalVelocityMax.x - v5->mGlobalVelocityMin.x) * UFG::qRandom(1.0, &UFG::qDefaultSeed))
        + v5->mGlobalVelocityMin.x;
    v25 = (float)((float)(v5->mGlobalVelocityMax.y - v5->mGlobalVelocityMin.y) * v23) + v5->mGlobalVelocityMin.y;
    v26 = (float)((float)(v5->mGlobalVelocityMax.z - v5->mGlobalVelocityMin.z) * v22) + v5->mGlobalVelocityMin.z;
    v27 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    v28 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    v29 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    Render::EffectEmitterSettings::GetLocalVelocity(v5, &pos, v29, v28, v27, mBasis);
    v30 = pos.y + v25;
    v31 = pos.z + v26;
    v32 = v7->mNumActiveNodes;
    v7->mActiveEffects[v32].globalVelocity.x = pos.x + v24;
    v7->mActiveEffects[v32].globalVelocity.y = v30;
    v7->mActiveEffects[v32].globalVelocity.z = v31;
    *((float *)&v7->vfptr + 10 * (v7->mNumActiveNodes + 2i64)) = (float)((float)(v5->mDragMax - v5->mDragMin)
                                                                       * UFG::qRandom(1.0, &UFG::qDefaultSeed))
                                                               + v5->mDragMin;
    v7->mActiveEffects[v7->mNumActiveNodes].gravity = (float)((float)(v5->mGravityMax - v5->mGravityMin)
                                                            * UFG::qRandom(1.0, &UFG::qDefaultSeed))
                                                    + v5->mGravityMin;
    v33 = v5->mEffectUIDs[v6];
    UFG::TransformNodeComponent::UpdateWorldTransform(v11);
    v7->mActiveEffects[v7->mNumActiveNodes++].effectHandle = Render::FXManager::CreateEffect(
                                                               &Render::gFXManager,
                                                               v33,
                                                               &v11->mWorldTransform,
                                                               v11);
  }
}

// File Line: 105
// RVA: 0x1C57E0
void __fastcall Render::EffectEmitterInstance::Activate(Render::EffectEmitterInstance *this)
{
  Render::EffectEmitterInstance *v1; // rdi
  Render::EffectEmitterSettings *v2; // rsi
  Render::FXInstance *v3; // rax
  UFG::SimComponent *v4; // rbx
  UFG::qMatrix44 *v5; // rdx
  unsigned int v6; // ebx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h]

  v1 = this;
  if ( !this->mIsActive )
  {
    v2 = (Render::EffectEmitterSettings *)this->mSettingsHandle.mData;
    *(_WORD *)&this->mIsActive = 1;
    if ( v2 )
    {
      v3 = this->mContainer;
      v4 = v3->mParentNode.m_pPointer;
      if ( !v4 || v3->mBasisRelativeToParent )
      {
        v5 = &v3->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mParentNode.m_pPointer);
        v5 = (UFG::qMatrix44 *)&v4[2];
      }
      Render::FXInstance::CalcBasisHelper(
        &dst,
        v5,
        (UFG::qResourceHandle *)&v1->mContainer->mSettings.mPrev,
        v1->mComponentIndex,
        v1->mStartTime);
      if ( v2->mRandomlySpawnOne )
      {
        gNextEffectIndex = (gNextEffectIndex + 1) % v2->mNumEffects;
        Render::EffectEmitterInstance::ActivateEffect(v1, gNextEffectIndex, v2, &dst);
      }
      else
      {
        v6 = 0;
        if ( v2->mNumEffects )
        {
          do
            Render::EffectEmitterInstance::ActivateEffect(v1, v6++, v2, &dst);
          while ( v6 < v2->mNumEffects );
        }
      }
    }
  }
}

// File Line: 135
// RVA: 0x1CAA30
void __fastcall Render::EffectEmitterInstance::Deactivate(Render::EffectEmitterInstance *this, bool willLoopImmediately)
{
  Render::EffectEmitterInstance *v2; // rsi
  __int64 v3; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  int v6; // edx
  hkGeometryUtils::IVertices *v7; // rcx
  int v8; // er8
  Render::FXInstance *v9; // rbx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v10; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v11; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v12; // rdx
  __int64 v13; // r8
  UFG::TransformNodeComponent *v14; // rcx

  v2 = this;
  if ( this->mIsActive )
  {
    v3 = 0i64;
    *(_WORD *)&this->mIsActive = 0;
    if ( this->mNumActiveNodes )
    {
      do
      {
        v4 = v2->mActiveEffects[v3].effectHandle;
        if ( v4 != -1 )
        {
          if ( v4 )
          {
            v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v4);
            v9 = (Render::FXInstance *)v5;
            if ( v5 )
            {
              if ( *(_QWORD *)&v5[1].mNULL.mUID
                && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v7, v6, v8) )
              {
                UFG::AudioVFXManager::Remove(v9);
              }
              UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                (UFG::qBaseTreeVariableRB<unsigned __int64> *)&Render::gFXManager,
                (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
              v10 = v9->mPrev;
              v11 = v9->mNext;
              v12 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v9->mPrev;
              v10->mNext = v11;
              v11->mPrev = v10;
              v12->mPrev = v12;
              v12->mNext = v12;
              Render::FXInstance::~FXInstance(v9, (_DWORD)v9 + 48, v13);
              operator delete[](v9);
            }
          }
        }
        v14 = v2->mActiveEffects[v3].node;
        if ( v14 )
          v14->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v14->vfptr, 1u);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v2->mNumActiveNodes );
    }
    v2->mNumActiveNodes = 0;
  }
}

// File Line: 156
// RVA: 0x1D8510
void __fastcall Render::LightningInstance::Suspend(Render::LightningInstance *this, float sim_time)
{
  if ( !this->mIsSuspended )
    this->mIsSuspended = 1;
}

// File Line: 164
// RVA: 0x1D5DA0
void __fastcall Render::LightningInstance::Resume(Render::LightningInstance *this, float sim_time)
{
  if ( this->mIsSuspended )
    this->mIsSuspended = 0;
}

// File Line: 220
// RVA: 0x1D8C30
void __fastcall Render::EffectEmitterInstance::Update(Render::EffectEmitterInstance *this, UFG::qVector3 *cam_pos, float simTime)
{
  Render::EffectEmitterInstance *v3; // rbx
  signed __int64 v4; // rdi
  float v5; // xmm9_4
  signed __int64 v6; // rcx
  UFG::TransformNodeComponent *v7; // r8
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm8_4
  int v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-78h]

  v3 = this;
  if ( this->mSettingsHandle.mData )
  {
    if ( 0.0 == this->mTimeOfLastUpdate )
      this->mTimeOfLastUpdate = simTime;
    v4 = 0i64;
    v5 = simTime - this->mTimeOfLastUpdate;
    if ( this->mNumActiveNodes )
    {
      do
      {
        v6 = v4;
        v7 = v3->mActiveEffects[v4].node;
        v8 = v3->mActiveEffects[v4].drag;
        v9 = v7->mLocalTransform.v3.y;
        v10 = v7->mLocalTransform.v3.z;
        v11 = LODWORD(v3->mActiveEffects[v4].globalVelocity.y) ^ _xmm[0];
        v12 = (float)((float)(COERCE_FLOAT(LODWORD(v3->mActiveEffects[v4].globalVelocity.z) ^ _xmm[0]) * v8)
                    + v3->mActiveEffects[v4].gravity)
            * v5;
        v13 = v7->mLocalTransform.v3.x;
        v3->mActiveEffects[v6].globalVelocity.x = v3->mActiveEffects[v4].globalVelocity.x
                                                + (float)((float)(COERCE_FLOAT(LODWORD(v3->mActiveEffects[v4].globalVelocity.x) ^ _xmm[0])
                                                                * v8)
                                                        * v5);
        v14 = v12 + v3->mActiveEffects[v4].globalVelocity.z;
        v15 = (float)((float)(*(float *)&v11 * v8) * v5) + v3->mActiveEffects[v4].globalVelocity.y;
        v3->mActiveEffects[v6].globalVelocity.z = v14;
        v3->mActiveEffects[v6].globalVelocity.y = v15;
        v16 = v3->mActiveEffects[v4].globalVelocity.x;
        v17 = v3->mActiveEffects[v4].globalVelocity.x * v5;
        pos.z = (float)(v14 * v5) + v10;
        pos.x = v13 + v17;
        pos.y = (float)(v15 * v5) + v9;
        v7->mWorldVelocity.x = v16;
        v7->mWorldVelocity.y = v15;
        v7->mWorldVelocity.z = v14;
        UFG::TransformNodeComponent::SetLocalTranslation(v7, &pos);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < v3->mNumActiveNodes );
    }
    v3->mTimeOfLastUpdate = simTime;
  }
}

