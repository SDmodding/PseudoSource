// File Line: 40
// RVA: 0x1C1C80
void __fastcall Render::ParticleEmitterInstance::ParticleEmitterInstance(Render::ParticleEmitterInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ParticleEmitterInstance::`vftable;
  this->mCurrentBuffer = 0i64;
  *(_QWORD *)&this->mActivateTime = 0i64;
  this->mPrevDistance = 0.0;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  this->mFirstFrameAfterActivateOrLoop = 0;
  *(_QWORD *)&this->mSuspendTime = 0i64;
  this->mNumVerticesInMeshEmissionBuffer = 0;
  this->mCurrentBuffer = 0i64;
  ++Render::ParticleEmitterInstance::mInstanceCount;
}

// File Line: 46
// RVA: 0x1C44D0
void __fastcall Render::ParticleEmitterInstance::~ParticleEmitterInstance(Render::ParticleEmitterInstance *this)
{
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ParticleEmitterInstance::`vftable;
  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    mCurrentBuffer = this->mCurrentBuffer;
    if ( mCurrentBuffer )
    {
      mCurrentBuffer->mOwner = 0i64;
      this->mCurrentBuffer = 0i64;
    }
    Inventory = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  --Render::ParticleEmitterInstance::mInstanceCount;
  v5 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = v5;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, v5);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 53
// RVA: 0x1CC600
__int64 __fastcall Render::GetNumVerticesInMeshEmissionBuffer(unsigned int meshEmissionName)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  char *v5; // rbx
  UFG::qBaseNodeRB *v6; // rax
  _QWORD *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceHandle v10; // [rsp+28h] [rbp-30h] BYREF

  if ( !meshEmissionName )
    return 0i64;
  UFG::qResourceHandle::qResourceHandle(&v10);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v10, 0xA2ADCD77, meshEmissionName, Inventory);
  v5 = 0i64;
  if ( v10.mData )
  {
    v6 = v10.mData[2].mNode.mChild[0];
    if ( v6 )
      v7 = (UFG::qBaseNodeRB **)((char *)&v10.mData->mNode.mParent + (unsigned __int64)&v6[5].mUID);
    else
      v7 = 0i64;
    if ( *v7 )
      v5 = (char *)v7 + *v7;
    LODWORD(v5) = *(_DWORD *)(*((_QWORD *)v5 + 14) + 108i64);
  }
  v8 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v8;
  }
  UFG::qResourceHandle::Close(&v10, v8);
  UFG::qResourceHandle::~qResourceHandle(&v10);
  return (unsigned int)v5;
}

// File Line: 75
// RVA: 0x1CF4E0
void __fastcall Render::ParticleEmitterInstance::Init(Render::ParticleEmitterInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *mData; // rax
  UFG::qVector4 v10; // xmm2

  v2 = this->mSettingsHandle.mData == 0i64;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    Inventory = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  v6 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
  mSettingsId = this->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0x3BEE21DCu, mSettingsId, v6);
  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    v10 = 0i64;
    v10.x = (float)1;
    this->mPrevBasis.v0 = v10;
    this->mPrevBasis.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 81);
    this->mPrevBasis.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 69);
    this->mPrevBasis.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 21);
    this->mCurrentBasis.v0 = v10;
    this->mCurrentBasis.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 81);
    this->mCurrentBasis.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 69);
    this->mCurrentBasis.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 21);
    this->mNumVerticesInMeshEmissionBuffer = Render::GetNumVerticesInMeshEmissionBuffer((unsigned int)mData[5].mNode.mChild[0]);
  }
}

// File Line: 95
// RVA: 0x1C6320
void __fastcall Render::ParticleEmitterInstance::Activate(Render::ParticleEmitterInstance *this)
{
  float mStartTime; // eax
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1

  if ( !this->mIsActive )
  {
    mStartTime = this->mStartTime;
    this->mIsActive = 1;
    this->mTotalEmitted = 0;
    this->mActivateTime = mStartTime;
    Render::FXComponentInstance::GetBasis(this, &this->mCurrentBasis);
    v3 = this->mCurrentBasis.v1;
    v4 = this->mCurrentBasis.v2;
    v5 = this->mCurrentBasis.v3;
    this->mPrevBasis.v0 = this->mCurrentBasis.v0;
    this->mPrevBasis.v1 = v3;
    this->mPrevBasis.v2 = v4;
    this->mPrevBasis.v3 = v5;
    this->mPrevDistance = 0.0;
    this->mFirstFrameAfterActivateOrLoop = 1;
    this->mVertexIndexToStartMeshEmissionFrom = 0.0;
  }
}

// File Line: 132
// RVA: 0x1CAC80
void __fastcall Render::ParticleEmitterInstance::Deactivate(
        Render::ParticleEmitterInstance *this,
        bool willLoopImmediately)
{
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  if ( this->mIsActive )
  {
    mCurrentBuffer = this->mCurrentBuffer;
    this->mIsActive = 0;
    if ( mCurrentBuffer )
    {
      mCurrentBuffer->mOwner = 0i64;
      this->mCurrentBuffer = 0i64;
    }
    Inventory = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
}

// File Line: 143
// RVA: 0x1D1840
void __fastcall Render::ParticleEmitterInstance::Loop(Render::ParticleEmitterInstance *this)
{
  this->mFirstFrameAfterActivateOrLoop = 1;
}

// File Line: 148
// RVA: 0x1D5DB0
void __fastcall Render::ParticleEmitterInstance::Resume(Render::ParticleEmitterInstance *this, float sim_time)
{
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mSettingsId; // ebx
  UFG::qResourceWarehouse *v5; // rax
  Render::ParticleEmitterSettings *mData; // rbx
  float emissionRate; // xmm6_4
  Render::FXOverride *m_pPointer; // rcx
  float mLifeMax; // xmm8_4
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  Render::ParticleEmitterBuffer *v11; // rcx
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qMatrix44 *Basis; // rax
  Render::ParticleEmitterBuffer *v16; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1

  if ( this->mIsSuspended )
  {
    if ( !this->mSettingsHandle.mData )
    {
      Inventory = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
      mSettingsId = this->mSettingsId;
      if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
      {
        v5 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x3BEE21DCu);
        `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&this->mSettingsHandle, 0x3BEE21DCu, mSettingsId, Inventory);
      *(_QWORD *)&this->mActivateTime = LODWORD(sim_time);
    }
    mData = (Render::ParticleEmitterSettings *)this->mSettingsHandle.mData;
    if ( mData )
    {
      this->mIsSuspended = 0;
      if ( mData->mPriority || mData->mEmissionInit != 1 || mData->mEmissionRate != 0.0 )
      {
        if ( !Render::ParticleEmitterInstance::UpdateCurrentBuffer(this, 0, mData, sim_time, 0.0) )
        {
          this->mIsSuspended = 1;
          return;
        }
        emissionRate = mData->mEmissionRate;
        m_pPointer = this->mContainer->mStateBlockOverride.m_pPointer;
        if ( m_pPointer )
          emissionRate = emissionRate * m_pPointer->emissionScale;
        mLifeMax = mData->mLifeMax;
        if ( mLifeMax >= (float)(sim_time - this->mSuspendTime) )
          mLifeMax = sim_time - this->mSuspendTime;
        if ( !mData->mModel.mData )
        {
          mCurrentBuffer = this->mCurrentBuffer;
          if ( mCurrentBuffer )
          {
            mCurrentBuffer->mOwner = 0i64;
            this->mCurrentBuffer = 0i64;
          }
          return;
        }
        if ( emissionRate >= 0.0 && !Render::ParticleEmitterInstance::HasSequentialMeshEmissionReachedTheEnd(this) )
          Render::ParticleEmitterInstance::UpdateResumeTimeEmission(
            this,
            mData,
            sim_time - mLifeMax,
            sim_time,
            emissionRate);
      }
      v11 = this->mCurrentBuffer;
      if ( v11 )
      {
        if ( this->mContainer->mParentNode.m_pPointer && mData->mSpace == 1 )
        {
          v12 = this->mCurrentBasis.v1;
          v13 = this->mCurrentBasis.v2;
          v14 = this->mCurrentBasis.v3;
          v11->mLastKnownGoodBasis.v0 = this->mCurrentBasis.v0;
          v11->mLastKnownGoodBasis.v1 = v12;
          v11->mLastKnownGoodBasis.v2 = v13;
          v11->mLastKnownGoodBasis.v3 = v14;
        }
        Basis = Render::FXInstance::GetBasis(this->mContainer);
        v16 = this->mCurrentBuffer;
        y = Basis->v3.y;
        z = Basis->v3.z;
        v16->mLastKnownEffectPos.x = Basis->v3.x;
        v16->mLastKnownEffectPos.y = y;
        v16->mLastKnownEffectPos.z = z;
      }
      Render::FXComponentInstance::GetBasis(this, &this->mCurrentBasis);
      v19 = this->mCurrentBasis.v1;
      v20 = this->mCurrentBasis.v2;
      v21 = this->mCurrentBasis.v3;
      this->mPrevBasis.v0 = this->mCurrentBasis.v0;
      this->mPrevBasis.v1 = v19;
      this->mPrevBasis.v2 = v20;
      this->mPrevBasis.v3 = v21;
    }
  }
}

// File Line: 233
// RVA: 0x1D85C0
void __fastcall Render::ParticleEmitterInstance::Suspend(Render::ParticleEmitterInstance *this, float sim_time)
{
  UFG::qResourceData *mData; // rax
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  if ( !this->mIsSuspended )
  {
    mData = this->mSettingsHandle.mData;
    if ( !mData
      || BYTE1(mData[8].mNode.mChild[1])
      || LODWORD(mData[5].mNode.mChild[1]) != 1
      || *((float *)mData[5].mNode.mChild + 1) != 0.0 )
    {
      mCurrentBuffer = this->mCurrentBuffer;
      if ( mCurrentBuffer )
      {
        mCurrentBuffer->mOwner = 0i64;
        this->mCurrentBuffer = 0i64;
      }
    }
    this->mSuspendTime = sim_time;
    this->mIsSuspended = 1;
    v4 = this->mCurrentBasis.v1;
    v5 = this->mCurrentBasis.v2;
    v6 = this->mCurrentBasis.v3;
    this->mPrevBasis.v0 = this->mCurrentBasis.v0;
    this->mPrevBasis.v1 = v4;
    this->mPrevBasis.v2 = v5;
    this->mPrevBasis.v3 = v6;
    *(_QWORD *)&this->mVelocity.x = 0i64;
    this->mVelocity.z = 0.0;
  }
}

// File Line: 253
// RVA: 0x1D9950
void __fastcall Render::ParticleEmitterInstance::Update(
        Render::ParticleEmitterInstance *this,
        UFG::qVector3 *cam_pos,
        float sim_time)
{
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v7; // rax
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  Render::ParticleEmitterSettings *mData; // rdi
  Render::ParticleEmitterBuffer *v10; // rax
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  float v14; // xmm0_4
  float v15; // xmm4_4
  UFG::qResourceData *v16; // rax
  float mEmissionRate; // xmm3_4
  Render::ParticleEmitterBuffer *v18; // rcx
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qMatrix44 *Basis; // rax
  Render::ParticleEmitterBuffer *v23; // rcx
  float y; // xmm0_4
  float z; // xmm1_4

  if ( !this->mSettingsHandle.mData )
  {
    Inventory = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
    mSettingsId = this->mSettingsId;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mSettingsHandle, 0x3BEE21DCu, mSettingsId, Inventory);
    mCurrentBuffer = this->mCurrentBuffer;
    *(_QWORD *)&this->mActivateTime = LODWORD(sim_time);
    if ( mCurrentBuffer )
    {
      mCurrentBuffer->mOwner = 0i64;
      this->mCurrentBuffer = 0i64;
    }
  }
  mData = (Render::ParticleEmitterSettings *)this->mSettingsHandle.mData;
  if ( mData )
  {
    if ( mData->mModel.mData )
    {
      v11 = this->mCurrentBasis.v1;
      v12 = this->mCurrentBasis.v2;
      v13 = this->mCurrentBasis.v3;
      this->mPrevBasis.v0 = this->mCurrentBasis.v0;
      this->mPrevBasis.v1 = v11;
      this->mPrevBasis.v2 = v12;
      this->mPrevBasis.v3 = v13;
      Render::FXComponentInstance::GetBasis(this, &this->mCurrentBasis);
      v12.x = this->mCurrentBasis.v3.y - this->mPrevBasis.v3.y;
      v14 = 1.0 / UFG::Metrics::msInstance.mSimTimeDelta;
      v15 = (float)(1.0 / UFG::Metrics::msInstance.mSimTimeDelta)
          * (float)(this->mCurrentBasis.v3.z - this->mPrevBasis.v3.z);
      this->mVelocity.x = (float)(1.0 / UFG::Metrics::msInstance.mSimTimeDelta)
                        * (float)(this->mCurrentBasis.v3.x - this->mPrevBasis.v3.x);
      this->mVelocity.z = v15;
      this->mVelocity.y = v14 * v12.x;
      v16 = this->mSettingsHandle.mData;
      if ( !LODWORD(v16[5].mNode.mChild[0])
        || (v16[4].mDebugName[20] & 0x40) == 0
        || (float)(int)this->mNumVerticesInMeshEmissionBuffer > this->mVertexIndexToStartMeshEmissionFrom )
      {
        mEmissionRate = mData->mEmissionRate;
        if ( mEmissionRate < 0.0 )
          Render::ParticleEmitterInstance::UpdateDistanceEmission(this, mData, sim_time, mEmissionRate);
        else
          Render::ParticleEmitterInstance::UpdateTimeEmission(this, mData, sim_time, mEmissionRate);
      }
      v18 = this->mCurrentBuffer;
      if ( v18 )
      {
        if ( this->mContainer->mParentNode.m_pPointer && mData->mSpace == 1 )
        {
          v19 = this->mCurrentBasis.v1;
          v20 = this->mCurrentBasis.v2;
          v21 = this->mCurrentBasis.v3;
          v18->mLastKnownGoodBasis.v0 = this->mCurrentBasis.v0;
          v18->mLastKnownGoodBasis.v1 = v19;
          v18->mLastKnownGoodBasis.v2 = v20;
          v18->mLastKnownGoodBasis.v3 = v21;
        }
        Basis = Render::FXInstance::GetBasis(this->mContainer);
        v23 = this->mCurrentBuffer;
        y = Basis->v3.y;
        z = Basis->v3.z;
        v23->mLastKnownEffectPos.x = Basis->v3.x;
        v23->mLastKnownEffectPos.y = y;
        v23->mLastKnownEffectPos.z = z;
      }
    }
    else
    {
      v10 = this->mCurrentBuffer;
      if ( v10 )
      {
        v10->mOwner = 0i64;
        this->mCurrentBuffer = 0i64;
      }
    }
  }
}

// File Line: 317
// RVA: 0x1DB250
char __fastcall Render::ParticleEmitterInstance::UpdateCurrentBuffer(
        Render::ParticleEmitterInstance *this,
        int add_count,
        Render::ParticleEmitterSettings *pfx,
        float sim_time)
{
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rcx
  Render::ParticleEmitterBuffer *ParticleBuffer; // rcx

  mCurrentBuffer = this->mCurrentBuffer;
  if ( mCurrentBuffer )
  {
    if ( (signed int)(mCurrentBuffer->mCapacity
                    - mCurrentBuffer->mTaskInfo.inputParam->currentAddCount
                    - mCurrentBuffer->mCount) < add_count )
    {
      mCurrentBuffer->mOwner = 0i64;
      this->mCurrentBuffer = 0i64;
    }
  }
  if ( this->mCurrentBuffer )
    return 0;
  ParticleBuffer = Render::ParticleEmitterManager::GetParticleBuffer(
                     &Render::gParticleEmitterManager,
                     pfx,
                     sim_time,
                     this->mCanStealBuffer);
  this->mCurrentBuffer = ParticleBuffer;
  if ( !ParticleBuffer )
  {
    ((void (__fastcall *)(Render::ParticleEmitterInstance *))this->vfptr->Suspend)(this);
    return 0;
  }
  Render::ParticleEmitterBuffer::Activate(ParticleBuffer, sim_time, this, pfx, this->mContainer, &this->mPrevBasis);
  return 1;
}

// File Line: 356
// RVA: 0x1CD3A0
bool __fastcall Render::ParticleEmitterInstance::HasSequentialMeshEmissionReachedTheEnd(
        Render::ParticleEmitterInstance *this)
{
  UFG::qResourceData *mData; // rax

  mData = this->mSettingsHandle.mData;
  return LODWORD(mData[5].mNode.mChild[0])
      && (mData[4].mDebugName[20] & 0x40) != 0
      && (float)(int)this->mNumVerticesInMeshEmissionBuffer <= this->mVertexIndexToStartMeshEmissionFrom;
}

// File Line: 370
// RVA: 0x1DC020
void __fastcall Render::ParticleEmitterInstance::UpdateTimeEmission(
        Render::ParticleEmitterInstance *this,
        Render::ParticleEmitterSettings *pfx,
        float sim_time,
        float emissionRate)
{
  float v6; // xmm0_4
  bool mFirstFrameAfterActivateOrLoop; // cl
  int v9; // esi
  bool v10; // al
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  unsigned int v12; // esi
  unsigned int mCapacity; // r8d
  int v14; // ebx
  Render::ParticleEmitterBuffer *v15; // rdx
  Render::ParticleRenderUpdateTaskParam *inputParam; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm3
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 v24; // xmm1

  v6 = sim_time - this->mActivateTime;
  mFirstFrameAfterActivateOrLoop = this->mFirstFrameAfterActivateOrLoop;
  v9 = (int)(float)(v6 * emissionRate);
  v10 = mFirstFrameAfterActivateOrLoop || !BYTE1(this->mSettingsHandle.mData[8].mNode.mChild[1]);
  this->mCanStealBuffer = v10;
  if ( mFirstFrameAfterActivateOrLoop )
  {
    v9 += pfx->mEmissionInit;
    this->mFirstFrameAfterActivateOrLoop = 0;
  }
  if ( this->mTotalEmitted > v9 )
  {
    this->mActivateTime = sim_time;
    this->mTotalEmitted = 0;
    v9 = 0;
  }
  mCurrentBuffer = this->mCurrentBuffer;
  v12 = v9 - this->mTotalEmitted;
  if ( mCurrentBuffer )
    mCapacity = mCurrentBuffer->mCapacity;
  else
    mCapacity = 0;
  while ( v12 )
  {
    v14 = v12;
    if ( v12 > mCapacity )
      v14 = mCapacity;
    this->mTotalEmitted += v14;
    v12 -= v14;
    Render::ParticleEmitterInstance::UpdateCurrentBuffer(this, v14, pfx, sim_time);
    v15 = this->mCurrentBuffer;
    if ( !v15 )
      break;
    inputParam = v15->mTaskInfo.inputParam;
    if ( v14 > v15->mCapacity - v15->mTaskInfo.inputParam->currentAddCount - v15->mCount )
      v14 = v15->mCapacity - inputParam->currentAddCount - v15->mCount;
    mCapacity = v15->mCapacity;
    if ( v14 )
    {
      inputParam->pSettings = pfx;
      y = this->mVelocity.y;
      z = this->mVelocity.z;
      inputParam->emitterVelocity.x = this->mVelocity.x;
      inputParam->emitterVelocity.y = y;
      inputParam->emitterVelocity.z = z;
      inputParam->resumeTimeSkip = 0.0;
      inputParam->creationSimTime = sim_time;
      v19 = this->mPrevBasis.v1;
      v20 = this->mPrevBasis.v2;
      v21 = this->mPrevBasis.v3;
      inputParam->oldBasis.v0 = this->mPrevBasis.v0;
      inputParam->oldBasis.v1 = v19;
      inputParam->oldBasis.v2 = v20;
      inputParam->oldBasis.v3 = v21;
      v22 = this->mCurrentBasis.v1;
      v23 = this->mCurrentBasis.v2;
      v24 = this->mCurrentBasis.v3;
      inputParam->curBasis.v0 = this->mCurrentBasis.v0;
      inputParam->curBasis.v1 = v22;
      inputParam->curBasis.v2 = v23;
      inputParam->curBasis.v3 = v24;
      inputParam->vertexIndexToStartMeshEmissionFrom = this->mVertexIndexToStartMeshEmissionFrom;
      this->mVertexIndexToStartMeshEmissionFrom = (float)((float)v14 * pfx->mMeshEmissionVertexSkip)
                                                + this->mVertexIndexToStartMeshEmissionFrom;
      inputParam->currentAddCount = v14;
      inputParam->emissionType = 0;
    }
  }
}

// File Line: 447
// RVA: 0x1DBDC0
void __fastcall Render::ParticleEmitterInstance::UpdateResumeTimeEmission(
        Render::ParticleEmitterInstance *this,
        Render::ParticleEmitterSettings *pfx,
        float start_time,
        float end_time,
        float emissionRate)
{
  float v5; // xmm0_4
  float v9; // xmm9_4
  bool mFirstFrameAfterActivateOrLoop; // cl
  int v11; // esi
  bool v12; // al
  float v13; // xmm7_4
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  unsigned int mCapacity; // edx
  int v16; // edi
  Render::ParticleEmitterBuffer *v17; // rcx
  Render::ParticleRenderUpdateTaskParam *inputParam; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 v24; // xmm1
  UFG::qVector4 v25; // xmm3
  UFG::qVector4 v26; // xmm2

  v5 = end_time - this->mSuspendTime;
  v9 = start_time;
  if ( v5 >= (float)((float)(pfx->mLifeMax + pfx->mLifeMin) * 0.5) )
    v5 = (float)(pfx->mLifeMax + pfx->mLifeMin) * 0.5;
  mFirstFrameAfterActivateOrLoop = this->mFirstFrameAfterActivateOrLoop;
  v11 = (int)(float)(v5 * emissionRate);
  v12 = mFirstFrameAfterActivateOrLoop || !BYTE1(this->mSettingsHandle.mData[8].mNode.mChild[1]);
  this->mCanStealBuffer = v12;
  if ( mFirstFrameAfterActivateOrLoop )
  {
    v11 += pfx->mEmissionInit;
    this->mFirstFrameAfterActivateOrLoop = 0;
  }
  *(_QWORD *)&this->mActivateTime = LODWORD(end_time);
  if ( v11 )
    v13 = (float)(end_time - start_time) / (float)v11;
  else
    v13 = 0.0;
  mCurrentBuffer = this->mCurrentBuffer;
  if ( mCurrentBuffer )
    mCapacity = mCurrentBuffer->mCapacity;
  else
    mCapacity = 0;
  while ( v11 )
  {
    v16 = v11;
    if ( v11 > mCapacity )
      v16 = mCapacity;
    this->mTotalEmitted += v16;
    v11 -= v16;
    Render::ParticleEmitterInstance::UpdateCurrentBuffer(this, v16, pfx, end_time);
    v17 = this->mCurrentBuffer;
    if ( !v17 )
      break;
    mCapacity = v17->mCapacity;
    if ( v16 )
    {
      inputParam = v17->mTaskInfo.inputParam;
      inputParam->pSettings = pfx;
      y = this->mVelocity.y;
      z = this->mVelocity.z;
      inputParam->emitterVelocity.x = this->mVelocity.x;
      inputParam->emitterVelocity.y = y;
      inputParam->emitterVelocity.z = z;
      inputParam->creationSimTime = v9;
      inputParam->resumeTimeSkip = v13;
      inputParam->currentAddCount = v16;
      inputParam->emissionType = 0;
      v21 = this->mPrevBasis.v1;
      v22 = this->mPrevBasis.v2;
      v23 = this->mPrevBasis.v3;
      inputParam->oldBasis.v0 = this->mPrevBasis.v0;
      inputParam->oldBasis.v1 = v21;
      inputParam->oldBasis.v2 = v22;
      inputParam->oldBasis.v3 = v23;
      v24 = this->mCurrentBasis.v3;
      v25 = this->mCurrentBasis.v1;
      v26 = this->mCurrentBasis.v2;
      inputParam->curBasis.v0 = this->mCurrentBasis.v0;
      inputParam->curBasis.v1 = v25;
      inputParam->curBasis.v2 = v26;
      inputParam->curBasis.v3 = v24;
      inputParam->vertexIndexToStartMeshEmissionFrom = this->mVertexIndexToStartMeshEmissionFrom;
      v9 = v9 + (float)((float)v16 * v13);
      this->mVertexIndexToStartMeshEmissionFrom = (float)((float)v16 * pfx->mMeshEmissionVertexSkip)
                                                + this->mVertexIndexToStartMeshEmissionFrom;
    }
  }
}

// File Line: 538
// RVA: 0x1DB320
void __fastcall Render::ParticleEmitterInstance::UpdateDistanceEmission(
        Render::ParticleEmitterInstance *this,
        Render::ParticleEmitterSettings *pfx,
        float sim_time,
        float emissionRate)
{
  float y; // xmm4_4
  float z; // xmm5_4
  __m128 y_low; // xmm0
  float x; // xmm9_4
  float v11; // xmm6_4
  float mPrevDistance; // xmm2_4
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rax
  float v14; // xmm1_4
  float v15; // xmm9_4
  float v16; // xmm2_4
  int v17; // esi
  int mCapacity; // edx
  int v19; // edi
  Render::ParticleEmitterBuffer *v20; // rcx
  Render::ParticleRenderUpdateTaskParam *inputParam; // rcx
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::qVector4 v24; // xmm3
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm1
  UFG::qVector4 v28; // xmm3
  UFG::qVector4 v29; // xmm2

  y = this->mPrevBasis.v3.y;
  z = this->mPrevBasis.v3.z;
  y_low = (__m128)LODWORD(this->mCurrentBasis.v3.y);
  x = this->mPrevBasis.v3.x;
  LODWORD(v11) = LODWORD(emissionRate) ^ _xmm[0];
  if ( x == 0.0 && y == 0.0 && z == 0.0 )
  {
    x = this->mCurrentBasis.v3.x;
    y = this->mCurrentBasis.v3.y;
    z = this->mCurrentBasis.v3.z;
  }
  mPrevDistance = this->mPrevDistance;
  mCurrentBuffer = this->mCurrentBuffer;
  v14 = this->mCurrentBasis.v3.x - x;
  v15 = v11 - mPrevDistance;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)(v14 * v14))
                    + (float)((float)(this->mCurrentBasis.v3.z - z) * (float)(this->mCurrentBasis.v3.z - z));
  v16 = mPrevDistance + _mm_sqrt_ps(y_low).m128_f32[0];
  v17 = (int)(float)(v16 / v11);
  this->mPrevDistance = v16 - (float)((float)v17 * v11);
  if ( mCurrentBuffer )
    mCapacity = mCurrentBuffer->mCapacity;
  else
    mCapacity = 0;
  for ( ;
        v17;
        this->mVertexIndexToStartMeshEmissionFrom = (float)((float)v19 * pfx->mMeshEmissionVertexSkip)
                                                  + this->mVertexIndexToStartMeshEmissionFrom )
  {
    v19 = v17;
    if ( v17 > mCapacity )
      v19 = mCapacity;
    this->mTotalEmitted += v19;
    v17 -= v19;
    Render::ParticleEmitterInstance::UpdateCurrentBuffer(this, v19, pfx, sim_time);
    v20 = this->mCurrentBuffer;
    if ( !v20 )
      break;
    mCapacity = v20->mCapacity;
    inputParam = v20->mTaskInfo.inputParam;
    inputParam->pSettings = pfx;
    v22 = this->mVelocity.y;
    v23 = this->mVelocity.z;
    inputParam->emitterVelocity.x = this->mVelocity.x;
    inputParam->emitterVelocity.z = v23;
    inputParam->emitterVelocity.y = v22;
    inputParam->creationSimTime = sim_time;
    v24 = this->mPrevBasis.v1;
    v25 = this->mPrevBasis.v2;
    v26 = this->mPrevBasis.v3;
    inputParam->oldBasis.v0 = this->mPrevBasis.v0;
    inputParam->oldBasis.v1 = v24;
    inputParam->oldBasis.v2 = v25;
    inputParam->oldBasis.v3 = v26;
    v27 = this->mCurrentBasis.v3;
    v28 = this->mCurrentBasis.v1;
    v29 = this->mCurrentBasis.v2;
    inputParam->curBasis.v0 = this->mCurrentBasis.v0;
    inputParam->curBasis.v1 = v28;
    inputParam->curBasis.v2 = v29;
    inputParam->curBasis.v3 = v27;
    inputParam->t = v15;
    inputParam->resumeTimeSkip = 0.0;
    inputParam->currentAddCount = v19;
    inputParam->emissionType = 1;
    inputParam->spacing = v11;
    inputParam->vertexIndexToStartMeshEmissionFrom = this->mVertexIndexToStartMeshEmissionFrom;
    v15 = v15 + (float)((float)v19 * v11);
  }
}

