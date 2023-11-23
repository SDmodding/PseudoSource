// File Line: 26
// RVA: 0x1C1080
void __fastcall Render::EffectEmitterInstance::EffectEmitterInstance(Render::EffectEmitterInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::EffectEmitterInstance::`vftable;
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
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  this->mNumActiveNodes = 0;
  this->mIsHidden = 0;
  this->mTimeOfLastUpdate = 0.0;
}

// File Line: 31
// RVA: 0x1C3380
void __fastcall Render::EffectEmitterInstance::~EffectEmitterInstance(Render::EffectEmitterInstance *this)
{
  Render::EffectEmitterSettingsHandle *p_mSettingsHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::EffectEmitterInstance::`vftable;
  p_mSettingsHandle = &this->mSettingsHandle;
  Inventory = `UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xFF1F2832);
    `UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mSettingsHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 36
// RVA: 0x1CE440
void __fastcall Render::EffectEmitterInstance::Init(Render::EffectEmitterInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mSettingsHandle.mData == 0i64;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    Inventory = `UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xFF1F2832);
      `UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  v6 = `UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result;
  mSettingsId = this->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xFF1F2832);
    `UFG::qGetResourceInventory<Render::EffectEmitterSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xFF1F2832, mSettingsId, v6);
}

// File Line: 51
// RVA: 0x1C63E0
void __fastcall Render::EffectEmitterInstance::ActivateEffect(
        Render::EffectEmitterInstance *this,
        unsigned int i,
        Render::EffectEmitterSettings *efx,
        UFG::qMatrix44 *curBasis)
{
  __int64 v6; // r14
  UFG::qMemoryPool *SimulationMemoryPool; // rax
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
  __int64 mNumActiveNodes; // rcx
  unsigned int v33; // ebx
  UFG::qVector3 pos; // [rsp+48h] [rbp-80h] BYREF

  v6 = i;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "EffectEmitter::TransformNode", 0i64, 1u);
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
    if ( efx->mJitterType )
    {
      if ( efx->mJitterType == 1 )
      {
        v15 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) - 0.5;
        v16 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) - 0.5;
        v12 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) - 0.5) * efx->mJitter.x;
        v13 = v16 * efx->mJitter.y;
        v14 = v15 * efx->mJitter.z;
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
        v17 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * 2.0) - 1.0;
        v18 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * 2.0) - 1.0;
        v19 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * 2.0) - 1.0;
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
    pos.x = v12 + curBasis->v3.x;
    pos.y = v13 + curBasis->v3.y;
    pos.z = v14 + curBasis->v3.z;
    UFG::TransformNodeComponent::SetLocalTranslation(v11, &pos);
    this->mActiveEffects[this->mNumActiveNodes].node = v11;
    v22 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    v23 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    v24 = (float)((float)(efx->mGlobalVelocityMax.x - efx->mGlobalVelocityMin.x)
                * UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed))
        + efx->mGlobalVelocityMin.x;
    v25 = (float)((float)(efx->mGlobalVelocityMax.y - efx->mGlobalVelocityMin.y) * v23) + efx->mGlobalVelocityMin.y;
    v26 = (float)((float)(efx->mGlobalVelocityMax.z - efx->mGlobalVelocityMin.z) * v22) + efx->mGlobalVelocityMin.z;
    v27 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    v28 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    v29 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    Render::EffectEmitterSettings::GetLocalVelocity(efx, &pos, v29, v28, v27, curBasis);
    v30 = pos.y + v25;
    v31 = pos.z + v26;
    mNumActiveNodes = this->mNumActiveNodes;
    this->mActiveEffects[mNumActiveNodes].globalVelocity.x = pos.x + v24;
    this->mActiveEffects[mNumActiveNodes].globalVelocity.y = v30;
    this->mActiveEffects[mNumActiveNodes].globalVelocity.z = v31;
    this->mActiveEffects[this->mNumActiveNodes].drag = (float)((float)(efx->mDragMax - efx->mDragMin)
                                                             * UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed))
                                                     + efx->mDragMin;
    this->mActiveEffects[this->mNumActiveNodes].gravity = (float)((float)(efx->mGravityMax - efx->mGravityMin)
                                                                * UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed))
                                                        + efx->mGravityMin;
    v33 = efx->mEffectUIDs[v6];
    UFG::TransformNodeComponent::UpdateWorldTransform(v11);
    this->mActiveEffects[this->mNumActiveNodes++].effectHandle = Render::FXManager::CreateEffect(
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
  Render::EffectEmitterSettings *mData; // rsi
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qMatrix44 *p_mBasis; // rdx
  unsigned int i; // ebx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h] BYREF

  if ( !this->mIsActive )
  {
    mData = (Render::EffectEmitterSettings *)this->mSettingsHandle.mData;
    *(_WORD *)&this->mIsActive = 1;
    if ( mData )
    {
      mContainer = this->mContainer;
      m_pPointer = mContainer->mParentNode.m_pPointer;
      if ( !m_pPointer || mContainer->mBasisRelativeToParent )
      {
        p_mBasis = &mContainer->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
        p_mBasis = (UFG::qMatrix44 *)&m_pPointer[2];
      }
      Render::FXInstance::CalcBasisHelper(
        &dst,
        p_mBasis,
        &this->mContainer->mSettings,
        this->mComponentIndex,
        this->mStartTime);
      if ( mData->mRandomlySpawnOne )
      {
        gNextEffectIndex = (gNextEffectIndex + 1) % mData->mNumEffects;
        Render::EffectEmitterInstance::ActivateEffect(this, gNextEffectIndex, mData, &dst);
      }
      else
      {
        for ( i = 0; i < mData->mNumEffects; ++i )
          Render::EffectEmitterInstance::ActivateEffect(this, i, mData, &dst);
      }
    }
  }
}

// File Line: 135
// RVA: 0x1CAA30
void __fastcall Render::EffectEmitterInstance::Deactivate(
        Render::EffectEmitterInstance *this,
        bool willLoopImmediately)
{
  __int64 v3; // rdi
  unsigned int effectHandle; // edx
  UFG::qBaseTreeRB *v5; // rax
  int v6; // edx
  hkGeometryUtils::IVertices *v7; // rcx
  int v8; // r8d
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v9; // rbx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mPrev; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mNext; // rax
  int v12; // r8d
  UFG::TransformNodeComponent *node; // rcx

  if ( this->mIsActive )
  {
    v3 = 0i64;
    for ( *(_WORD *)&this->mIsActive = 0; (unsigned int)v3 < this->mNumActiveNodes; v3 = (unsigned int)(v3 + 1) )
    {
      effectHandle = this->mActiveEffects[v3].effectHandle;
      if ( effectHandle != -1 )
      {
        if ( effectHandle )
        {
          v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, effectHandle);
          v9 = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)v5;
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
            mPrev = v9[3].mPrev;
            mNext = v9[3].mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            v9[3].mPrev = v9 + 3;
            v9[3].mNext = v9 + 3;
            Render::FXInstance::~FXInstance((Render::FXInstance *)v9, (_DWORD)v9 + 48, v12);
            operator delete[](v9);
          }
        }
      }
      node = this->mActiveEffects[v3].node;
      if ( node )
        node->vfptr->__vecDelDtor(node, 1u);
    }
    this->mNumActiveNodes = 0;
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
void __fastcall Render::EffectEmitterInstance::Update(
        Render::EffectEmitterInstance *this,
        UFG::qVector3 *cam_pos,
        float simTime)
{
  __int64 v4; // rdi
  float i; // xmm9_4
  __int64 v6; // rcx
  UFG::TransformNodeComponent *node; // r8
  float drag; // xmm0_4
  float y; // xmm6_4
  float z; // xmm8_4
  int v11; // xmm7_4
  float v12; // xmm5_4
  float x; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-78h] BYREF

  if ( this->mSettingsHandle.mData )
  {
    if ( this->mTimeOfLastUpdate == 0.0 )
      this->mTimeOfLastUpdate = simTime;
    v4 = 0i64;
    for ( i = simTime - this->mTimeOfLastUpdate; (unsigned int)v4 < this->mNumActiveNodes; v4 = (unsigned int)(v4 + 1) )
    {
      v6 = v4;
      node = this->mActiveEffects[v4].node;
      drag = this->mActiveEffects[v4].drag;
      y = node->mLocalTransform.v3.y;
      z = node->mLocalTransform.v3.z;
      v11 = LODWORD(this->mActiveEffects[v4].globalVelocity.y) ^ _xmm[0];
      v12 = (float)((float)(COERCE_FLOAT(LODWORD(this->mActiveEffects[v4].globalVelocity.z) ^ _xmm[0]) * drag)
                  + this->mActiveEffects[v4].gravity)
          * i;
      x = node->mLocalTransform.v3.x;
      this->mActiveEffects[v6].globalVelocity.x = this->mActiveEffects[v4].globalVelocity.x
                                                + (float)((float)(COERCE_FLOAT(LODWORD(this->mActiveEffects[v4].globalVelocity.x) ^ _xmm[0])
                                                                * drag)
                                                        * i);
      v14 = v12 + this->mActiveEffects[v4].globalVelocity.z;
      v15 = (float)((float)(*(float *)&v11 * drag) * i) + this->mActiveEffects[v4].globalVelocity.y;
      this->mActiveEffects[v6].globalVelocity.z = v14;
      this->mActiveEffects[v6].globalVelocity.y = v15;
      v16 = this->mActiveEffects[v4].globalVelocity.x;
      pos.z = (float)(v14 * i) + z;
      pos.x = x + (float)(v16 * i);
      pos.y = (float)(v15 * i) + y;
      node->mWorldVelocity.x = v16;
      node->mWorldVelocity.y = v15;
      node->mWorldVelocity.z = v14;
      UFG::TransformNodeComponent::SetLocalTranslation(node, &pos);
    }
    this->mTimeOfLastUpdate = simTime;
  }
}

