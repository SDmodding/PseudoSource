// File Line: 40
// RVA: 0x1C1C80
void __fastcall Render::ParticleEmitterInstance::ParticleEmitterInstance(Render::ParticleEmitterInstance *this)
{
  Render::ParticleEmitterInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ParticleEmitterInstance::`vftable';
  this->mCurrentBuffer = 0i64;
  *(_QWORD *)&this->mActivateTime = 0i64;
  this->mPrevDistance = 0.0;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  v1->mFirstFrameAfterActivateOrLoop = 0;
  *(_QWORD *)&v1->mSuspendTime = 0i64;
  v1->mNumVerticesInMeshEmissionBuffer = 0;
  v1->mCurrentBuffer = 0i64;
  ++Render::ParticleEmitterInstance::mInstanceCount;
}

// File Line: 46
// RVA: 0x1C44D0
void __fastcall Render::ParticleEmitterInstance::~ParticleEmitterInstance(Render::ParticleEmitterInstance *this)
{
  Render::ParticleEmitterInstance *v1; // rbx
  Render::ParticleEmitterBuffer *v2; // rax
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v8; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v9; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ParticleEmitterInstance::`vftable';
  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    v2 = this->mCurrentBuffer;
    if ( v2 )
    {
      v2->mOwner = 0i64;
      this->mCurrentBuffer = 0i64;
    }
    v3 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v3;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v3);
  }
  --Render::ParticleEmitterInstance::mInstanceCount;
  v5 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  v7 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 53
// RVA: 0x1CC600
__int64 __fastcall Render::GetNumVerticesInMeshEmissionBuffer(unsigned int meshEmissionName)
{
  unsigned int v1; // ebx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  char *v5; // rbx
  UFG::qBaseNodeRB *v6; // rax
  _QWORD *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceHandle v10; // [rsp+28h] [rbp-30h]

  v1 = meshEmissionName;
  if ( !meshEmissionName )
    return 0i64;
  UFG::qResourceHandle::qResourceHandle(&v10);
  v3 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Init(&v10, 0xA2ADCD77, v1, v3);
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
  v8 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v8;
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
  Render::ParticleEmitterInstance *v3; // rbx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *v9; // rax
  __m128 v10; // xmm2

  v2 = this->mSettingsHandle.mData == 0i64;
  v3 = this;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    v4 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, v4);
  }
  v6 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
  v7 = v3->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0x3BEE21DCu, v7, v6);
  v9 = v3->mSettingsHandle.mData;
  if ( v9 )
  {
    v10 = 0i64;
    v10.m128_f32[0] = (float)1;
    v3->mPrevBasis.v0 = (UFG::qVector4)v10;
    v3->mPrevBasis.v1 = (UFG::qVector4)_mm_shuffle_ps(v10, v10, 81);
    v3->mPrevBasis.v2 = (UFG::qVector4)_mm_shuffle_ps(v10, v10, 69);
    v3->mPrevBasis.v3 = (UFG::qVector4)_mm_shuffle_ps(v10, v10, 21);
    v3->mCurrentBasis.v0 = (UFG::qVector4)v10;
    v3->mCurrentBasis.v1 = (UFG::qVector4)_mm_shuffle_ps(v10, v10, 81);
    v3->mCurrentBasis.v2 = (UFG::qVector4)_mm_shuffle_ps(v10, v10, 69);
    v3->mCurrentBasis.v3 = (UFG::qVector4)_mm_shuffle_ps(v10, v10, 21);
    v3->mNumVerticesInMeshEmissionBuffer = Render::GetNumVerticesInMeshEmissionBuffer((unsigned int)v9[5].mNode.mChild[0]);
  }
}

// File Line: 95
// RVA: 0x1C6320
void __fastcall Render::ParticleEmitterInstance::Activate(Render::ParticleEmitterInstance *this)
{
  Render::ParticleEmitterInstance *v1; // rdi
  float v2; // eax
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1

  v1 = this;
  if ( !this->mIsActive )
  {
    v2 = this->mStartTime;
    this->mIsActive = 1;
    this->mTotalEmitted = 0;
    this->mActivateTime = v2;
    Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&this->vfptr, &this->mCurrentBasis);
    v3 = v1->mCurrentBasis.v1;
    v4 = v1->mCurrentBasis.v2;
    v5 = v1->mCurrentBasis.v3;
    v1->mPrevBasis.v0 = v1->mCurrentBasis.v0;
    v1->mPrevBasis.v1 = v3;
    v1->mPrevBasis.v2 = v4;
    v1->mPrevBasis.v3 = v5;
    v1->mPrevDistance = 0.0;
    v1->mFirstFrameAfterActivateOrLoop = 1;
    v1->mVertexIndexToStartMeshEmissionFrom = 0.0;
  }
}

// File Line: 132
// RVA: 0x1CAC80
void __fastcall Render::ParticleEmitterInstance::Deactivate(Render::ParticleEmitterInstance *this, bool willLoopImmediately)
{
  Render::ParticleEmitterInstance *v2; // rbx
  Render::ParticleEmitterBuffer *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  v2 = this;
  if ( this->mIsActive )
  {
    v3 = this->mCurrentBuffer;
    this->mIsActive = 0;
    if ( v3 )
    {
      v3->mOwner = 0i64;
      this->mCurrentBuffer = 0i64;
    }
    v4 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mSettingsHandle.mPrev, v4);
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
  Render::ParticleEmitterInstance *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  unsigned int v4; // ebx
  UFG::qResourceWarehouse *v5; // rax
  Render::ParticleEmitterSettings *v6; // rbx
  float emissionRate; // xmm6_4
  Render::FXOverride *v8; // rcx
  float v9; // xmm8_4
  Render::ParticleEmitterBuffer *v10; // rax
  Render::ParticleEmitterBuffer *v11; // rcx
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qMatrix44 *v15; // rax
  Render::ParticleEmitterBuffer *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1

  v2 = this;
  if ( this->mIsSuspended )
  {
    if ( !this->mSettingsHandle.mData )
    {
      v3 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
      v4 = this->mSettingsId;
      if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
      {
        v5 = UFG::qResourceWarehouse::Instance();
        v3 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BEE21DCu);
        `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v3;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mSettingsHandle.mPrev, 0x3BEE21DCu, v4, v3);
      *(_QWORD *)&v2->mActivateTime = LODWORD(sim_time);
    }
    v6 = (Render::ParticleEmitterSettings *)v2->mSettingsHandle.mData;
    if ( v6 )
    {
      v2->mIsSuspended = 0;
      if ( v6->mPriority || v6->mEmissionInit != 1 || 0.0 != v6->mEmissionRate )
      {
        if ( !Render::ParticleEmitterInstance::UpdateCurrentBuffer(v2, 0, v6, sim_time, 0.0) )
        {
          v2->mIsSuspended = 1;
          return;
        }
        emissionRate = v6->mEmissionRate;
        v8 = v2->mContainer->mStateBlockOverride.m_pPointer;
        if ( v8 )
          emissionRate = emissionRate * v8->emissionScale;
        v9 = v6->mLifeMax;
        if ( v9 >= (float)(sim_time - v2->mSuspendTime) )
          v9 = sim_time - v2->mSuspendTime;
        if ( !v6->mModel.mData )
        {
          v10 = v2->mCurrentBuffer;
          if ( v10 )
          {
            v10->mOwner = 0i64;
            v2->mCurrentBuffer = 0i64;
          }
          return;
        }
        if ( emissionRate >= 0.0 && !Render::ParticleEmitterInstance::HasSequentialMeshEmissionReachedTheEnd(v2) )
          Render::ParticleEmitterInstance::UpdateResumeTimeEmission(v2, v6, sim_time - v9, sim_time, emissionRate);
      }
      v11 = v2->mCurrentBuffer;
      if ( v11 )
      {
        if ( v2->mContainer->mParentNode.m_pPointer && v6->mSpace == 1 )
        {
          v12 = v2->mCurrentBasis.v1;
          v13 = v2->mCurrentBasis.v2;
          v14 = v2->mCurrentBasis.v3;
          v11->mLastKnownGoodBasis.v0 = v2->mCurrentBasis.v0;
          v11->mLastKnownGoodBasis.v1 = v12;
          v11->mLastKnownGoodBasis.v2 = v13;
          v11->mLastKnownGoodBasis.v3 = v14;
        }
        v15 = Render::FXInstance::GetBasis(v2->mContainer);
        v16 = v2->mCurrentBuffer;
        v17 = v15->v3.y;
        v18 = v15->v3.z;
        v16->mLastKnownEffectPos.x = v15->v3.x;
        v16->mLastKnownEffectPos.y = v17;
        v16->mLastKnownEffectPos.z = v18;
      }
      Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&v2->vfptr, &v2->mCurrentBasis);
      v19 = v2->mCurrentBasis.v1;
      v20 = v2->mCurrentBasis.v2;
      v21 = v2->mCurrentBasis.v3;
      v2->mPrevBasis.v0 = v2->mCurrentBasis.v0;
      v2->mPrevBasis.v1 = v19;
      v2->mPrevBasis.v2 = v20;
      v2->mPrevBasis.v3 = v21;
    }
  }
}

// File Line: 233
// RVA: 0x1D85C0
void __fastcall Render::ParticleEmitterInstance::Suspend(Render::ParticleEmitterInstance *this, float sim_time)
{
  UFG::qResourceData *v2; // rax
  Render::ParticleEmitterBuffer *v3; // rax
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  if ( !this->mIsSuspended )
  {
    v2 = this->mSettingsHandle.mData;
    if ( !v2
      || BYTE1(v2[8].mNode.mChild[1])
      || LODWORD(v2[5].mNode.mChild[1]) != 1
      || *((float *)v2[5].mNode.mChild + 1) != 0.0 )
    {
      v3 = this->mCurrentBuffer;
      if ( v3 )
      {
        v3->mOwner = 0i64;
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
void __fastcall Render::ParticleEmitterInstance::Update(Render::ParticleEmitterInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  Render::ParticleEmitterInstance *v3; // rbx
  float v4; // xmm6_4
  UFG::qResourceInventory *v5; // rax
  unsigned int v6; // edi
  UFG::qResourceWarehouse *v7; // rax
  Render::ParticleEmitterBuffer *v8; // rax
  Render::ParticleEmitterSettings *v9; // rdi
  Render::ParticleEmitterBuffer *v10; // rax
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  float v14; // xmm0_4
  float v15; // xmm4_4
  UFG::qResourceData *v16; // rax
  float v17; // xmm3_4
  Render::ParticleEmitterBuffer *v18; // rcx
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qMatrix44 *v22; // rax
  Render::ParticleEmitterBuffer *v23; // rcx
  float v24; // xmm0_4
  float v25; // xmm1_4

  v3 = this;
  v4 = sim_time;
  if ( !this->mSettingsHandle.mData )
  {
    v5 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result;
    v6 = this->mSettingsId;
    if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v7, 0x3BEE21DCu);
      `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>'::`2'::result = v5;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0x3BEE21DCu, v6, v5);
    v8 = v3->mCurrentBuffer;
    *(_QWORD *)&v3->mActivateTime = LODWORD(sim_time);
    if ( v8 )
    {
      v8->mOwner = 0i64;
      v3->mCurrentBuffer = 0i64;
    }
  }
  v9 = (Render::ParticleEmitterSettings *)v3->mSettingsHandle.mData;
  if ( v9 )
  {
    if ( v9->mModel.mData )
    {
      v11 = v3->mCurrentBasis.v1;
      v12 = v3->mCurrentBasis.v2;
      v13 = v3->mCurrentBasis.v3;
      v3->mPrevBasis.v0 = v3->mCurrentBasis.v0;
      v3->mPrevBasis.v1 = v11;
      v3->mPrevBasis.v2 = v12;
      v3->mPrevBasis.v3 = v13;
      Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&v3->vfptr, &v3->mCurrentBasis);
      v12.x = v3->mCurrentBasis.v3.y - v3->mPrevBasis.v3.y;
      v14 = 1.0 / UFG::Metrics::msInstance.mSimTimeDelta;
      v15 = (float)(1.0 / UFG::Metrics::msInstance.mSimTimeDelta)
          * (float)(v3->mCurrentBasis.v3.z - v3->mPrevBasis.v3.z);
      v3->mVelocity.x = (float)(1.0 / UFG::Metrics::msInstance.mSimTimeDelta)
                      * (float)(v3->mCurrentBasis.v3.x - v3->mPrevBasis.v3.x);
      v3->mVelocity.z = v15;
      v3->mVelocity.y = v14 * v12.x;
      v16 = v3->mSettingsHandle.mData;
      if ( !LODWORD(v16[5].mNode.mChild[0])
        || !(((unsigned __int8)v16[4].mDebugName[20] >> 6) & 1)
        || (float)(signed int)v3->mNumVerticesInMeshEmissionBuffer > v3->mVertexIndexToStartMeshEmissionFrom )
      {
        v17 = v9->mEmissionRate;
        if ( v17 < 0.0 )
          Render::ParticleEmitterInstance::UpdateDistanceEmission(v3, v9, v4, v17);
        else
          Render::ParticleEmitterInstance::UpdateTimeEmission(v3, v9, v4, v17);
      }
      v18 = v3->mCurrentBuffer;
      if ( v18 )
      {
        if ( v3->mContainer->mParentNode.m_pPointer && v9->mSpace == 1 )
        {
          v19 = v3->mCurrentBasis.v1;
          v20 = v3->mCurrentBasis.v2;
          v21 = v3->mCurrentBasis.v3;
          v18->mLastKnownGoodBasis.v0 = v3->mCurrentBasis.v0;
          v18->mLastKnownGoodBasis.v1 = v19;
          v18->mLastKnownGoodBasis.v2 = v20;
          v18->mLastKnownGoodBasis.v3 = v21;
        }
        v22 = Render::FXInstance::GetBasis(v3->mContainer);
        v23 = v3->mCurrentBuffer;
        v24 = v22->v3.y;
        v25 = v22->v3.z;
        v23->mLastKnownEffectPos.x = v22->v3.x;
        v23->mLastKnownEffectPos.y = v24;
        v23->mLastKnownEffectPos.z = v25;
      }
    }
    else
    {
      v10 = v3->mCurrentBuffer;
      if ( v10 )
      {
        v10->mOwner = 0i64;
        v3->mCurrentBuffer = 0i64;
      }
    }
  }
}   if ( v10 )
      {
        v10->mOwner = 0i64;
        v3->mCurrentBuffer = 0i64;


// File Line: 317
// RVA: 0x1DB250
char __fastcall Render::ParticleEmitterInstance::UpdateCurrentBuffer(Render::ParticleEmitterInstance *this, int add_count, Render::ParticleEmitterSettings *pfx, float sim_time)
{
  Render::ParticleEmitterInstance *v4; // rbx
  Render::ParticleEmitterBuffer *v5; // rcx
  Render::ParticleEmitterSettings *v6; // rdi
  Render::ParticleEmitterBuffer *v7; // rcx

  v4 = this;
  v5 = this->mCurrentBuffer;
  v6 = pfx;
  if ( v5 )
  {
    if ( (signed int)(v5->mCapacity - v5->mTaskInfo.inputParam->currentAddCount - v5->mCount) < add_count )
    {
      v5->mOwner = 0i64;
      v4->mCurrentBuffer = 0i64;
    }
  }
  if ( v4->mCurrentBuffer )
    return 0;
  v7 = Render::ParticleEmitterManager::GetParticleBuffer(
         &Render::gParticleEmitterManager,
         pfx,
         sim_time,
         v4->mCanStealBuffer);
  v4->mCurrentBuffer = v7;
  if ( !v7 )
  {
    ((void (__fastcall *)(Render::ParticleEmitterInstance *))v4->vfptr->Suspend)(v4);
    return 0;
  }
  Render::ParticleEmitterBuffer::Activate(v7, sim_time, v4, v6, v4->mContainer, &v4->mPrevBasis);
  return 1;
}

// File Line: 356
// RVA: 0x1CD3A0
bool __fastcall Render::ParticleEmitterInstance::HasSequentialMeshEmissionReachedTheEnd(Render::ParticleEmitterInstance *this)
{
  UFG::qResourceData *v1; // rax
  bool result; // al

  v1 = this->mSettingsHandle.mData;
  if ( LODWORD(v1[5].mNode.mChild[0]) && ((unsigned __int8)v1[4].mDebugName[20] >> 6) & 1 )
    result = (float)(signed int)this->mNumVerticesInMeshEmissionBuffer <= this->mVertexIndexToStartMeshEmissionFrom;
  else
    result = 0;
  return result;
}

// File Line: 370
// RVA: 0x1DC020
void __fastcall Render::ParticleEmitterInstance::UpdateTimeEmission(Render::ParticleEmitterInstance *this, Render::ParticleEmitterSettings *pfx, float sim_time, float emissionRate)
{
  Render::ParticleEmitterInstance *v4; // rdi
  Render::ParticleEmitterSettings *v5; // rbp
  float v6; // xmm0_4
  bool v7; // cl
  float v8; // xmm6_4
  signed int v9; // esi
  bool v10; // al
  Render::ParticleEmitterBuffer *v11; // rax
  unsigned int v12; // esi
  unsigned int v13; // er8
  int v14; // ebx
  Render::ParticleEmitterBuffer *v15; // rdx
  Render::ParticleRenderUpdateTaskParam *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm3
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 v24; // xmm1

  v4 = this;
  v5 = pfx;
  v6 = sim_time - this->mActivateTime;
  v7 = this->mFirstFrameAfterActivateOrLoop;
  v8 = sim_time;
  v9 = (signed int)(float)(v6 * emissionRate);
  v10 = v7 || !BYTE1(v4->mSettingsHandle.mData[8].mNode.mChild[1]);
  v4->mCanStealBuffer = v10;
  if ( v7 )
  {
    v9 += pfx->mEmissionInit;
    v4->mFirstFrameAfterActivateOrLoop = 0;
  }
  if ( v4->mTotalEmitted > v9 )
  {
    v4->mActivateTime = sim_time;
    v4->mTotalEmitted = 0;
    v9 = 0;
  }
  v11 = v4->mCurrentBuffer;
  v12 = v9 - v4->mTotalEmitted;
  if ( v11 )
    v13 = v11->mCapacity;
  else
    v13 = 0;
  while ( v12 )
  {
    v14 = v12;
    if ( v12 > v13 )
      v14 = v13;
    v4->mTotalEmitted += v14;
    v12 -= v14;
    Render::ParticleEmitterInstance::UpdateCurrentBuffer(v4, v14, v5, v8);
    v15 = v4->mCurrentBuffer;
    if ( !v15 )
      break;
    v16 = v15->mTaskInfo.inputParam;
    if ( v14 > v15->mCapacity - v15->mTaskInfo.inputParam->currentAddCount - v15->mCount )
      v14 = v15->mCapacity - v16->currentAddCount - v15->mCount;
    v13 = v15->mCapacity;
    if ( v14 )
    {
      v16->pSettings = v5;
      v17 = v4->mVelocity.y;
      v18 = v4->mVelocity.z;
      v16->emitterVelocity.x = v4->mVelocity.x;
      v16->emitterVelocity.y = v17;
      v16->emitterVelocity.z = v18;
      v16->resumeTimeSkip = 0.0;
      v16->creationSimTime = v8;
      v19 = v4->mPrevBasis.v1;
      v20 = v4->mPrevBasis.v2;
      v21 = v4->mPrevBasis.v3;
      v16->oldBasis.v0 = v4->mPrevBasis.v0;
      v16->oldBasis.v1 = v19;
      v16->oldBasis.v2 = v20;
      v16->oldBasis.v3 = v21;
      v22 = v4->mCurrentBasis.v1;
      v23 = v4->mCurrentBasis.v2;
      v24 = v4->mCurrentBasis.v3;
      v16->curBasis.v0 = v4->mCurrentBasis.v0;
      v16->curBasis.v1 = v22;
      v16->curBasis.v2 = v23;
      v16->curBasis.v3 = v24;
      v16->vertexIndexToStartMeshEmissionFrom = v4->mVertexIndexToStartMeshEmissionFrom;
      v4->mVertexIndexToStartMeshEmissionFrom = (float)((float)v14 * v5->mMeshEmissionVertexSkip)
                                              + v4->mVertexIndexToStartMeshEmissionFrom;
      v16->currentAddCount = v14;
      v16->emissionType = 0;
    }
  }
}

// File Line: 447
// RVA: 0x1DBDC0
void __fastcall Render::ParticleEmitterInstance::UpdateResumeTimeEmission(Render::ParticleEmitterInstance *this, Render::ParticleEmitterSettings *pfx, float start_time, float end_time, float emissionRate)
{
  float v5; // xmm0_4
  Render::ParticleEmitterSettings *v6; // rbp
  Render::ParticleEmitterInstance *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm9_4
  bool v10; // cl
  signed int v11; // esi
  bool v12; // al
  float v13; // xmm7_4
  Render::ParticleEmitterBuffer *v14; // rax
  unsigned int v15; // edx
  int v16; // edi
  Render::ParticleEmitterBuffer *v17; // rcx
  Render::ParticleRenderUpdateTaskParam *v18; // rcx
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 v24; // xmm1
  UFG::qVector4 v25; // xmm3
  UFG::qVector4 v26; // xmm2

  v5 = end_time - this->mSuspendTime;
  v6 = pfx;
  v7 = this;
  v8 = end_time;
  v9 = start_time;
  if ( v5 >= (float)((float)(pfx->mLifeMax + pfx->mLifeMin) * 0.5) )
    v5 = (float)(pfx->mLifeMax + pfx->mLifeMin) * 0.5;
  v10 = this->mFirstFrameAfterActivateOrLoop;
  v11 = (signed int)(float)(v5 * emissionRate);
  v12 = v10 || !BYTE1(v7->mSettingsHandle.mData[8].mNode.mChild[1]);
  v7->mCanStealBuffer = v12;
  if ( v10 )
  {
    v11 += pfx->mEmissionInit;
    v7->mFirstFrameAfterActivateOrLoop = 0;
  }
  *(_QWORD *)&v7->mActivateTime = LODWORD(end_time);
  if ( v11 )
    v13 = (float)(end_time - start_time) / (float)v11;
  else
    v13 = 0.0;
  v14 = v7->mCurrentBuffer;
  if ( v14 )
    v15 = v14->mCapacity;
  else
    v15 = 0;
  while ( v11 )
  {
    v16 = v11;
    if ( v11 > v15 )
      v16 = v15;
    v7->mTotalEmitted += v16;
    v11 -= v16;
    Render::ParticleEmitterInstance::UpdateCurrentBuffer(v7, v16, v6, v8);
    v17 = v7->mCurrentBuffer;
    if ( !v17 )
      break;
    v15 = v17->mCapacity;
    if ( v16 )
    {
      v18 = v17->mTaskInfo.inputParam;
      v18->pSettings = v6;
      v19 = v7->mVelocity.y;
      v20 = v7->mVelocity.z;
      v18->emitterVelocity.x = v7->mVelocity.x;
      v18->emitterVelocity.y = v19;
      v18->emitterVelocity.z = v20;
      v18->creationSimTime = v9;
      v18->resumeTimeSkip = v13;
      v18->currentAddCount = v16;
      v18->emissionType = 0;
      v21 = v7->mPrevBasis.v1;
      v22 = v7->mPrevBasis.v2;
      v23 = v7->mPrevBasis.v3;
      v18->oldBasis.v0 = v7->mPrevBasis.v0;
      v18->oldBasis.v1 = v21;
      v18->oldBasis.v2 = v22;
      v18->oldBasis.v3 = v23;
      v24 = v7->mCurrentBasis.v3;
      v25 = v7->mCurrentBasis.v1;
      v26 = v7->mCurrentBasis.v2;
      v18->curBasis.v0 = v7->mCurrentBasis.v0;
      v18->curBasis.v1 = v25;
      v18->curBasis.v2 = v26;
      v18->curBasis.v3 = v24;
      v18->vertexIndexToStartMeshEmissionFrom = v7->mVertexIndexToStartMeshEmissionFrom;
      v9 = v9 + (float)((float)v16 * v13);
      v7->mVertexIndexToStartMeshEmissionFrom = (float)((float)v16 * v6->mMeshEmissionVertexSkip)
                                              + v7->mVertexIndexToStartMeshEmissionFrom;
    }
  }
}

// File Line: 538
// RVA: 0x1DB320
void __fastcall Render::ParticleEmitterInstance::UpdateDistanceEmission(Render::ParticleEmitterInstance *this, Render::ParticleEmitterSettings *pfx, float sim_time, float emissionRate)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  Render::ParticleEmitterSettings *v6; // rbp
  Render::ParticleEmitterInstance *v7; // rbx
  __m128 v8; // xmm0
  float v9; // xmm7_4
  float v10; // xmm9_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  Render::ParticleEmitterBuffer *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm9_4
  float v16; // xmm2_4
  signed int v17; // esi
  int v18; // edx
  int v19; // edi
  Render::ParticleEmitterBuffer *v20; // rcx
  Render::ParticleRenderUpdateTaskParam *v21; // rcx
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::qVector4 v24; // xmm3
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm1
  UFG::qVector4 v28; // xmm3
  UFG::qVector4 v29; // xmm2

  v4 = this->mPrevBasis.v3.y;
  v5 = this->mPrevBasis.v3.z;
  v6 = pfx;
  v7 = this;
  v8 = (__m128)LODWORD(this->mCurrentBasis.v3.y);
  v9 = sim_time;
  v10 = this->mPrevBasis.v3.x;
  LODWORD(v11) = LODWORD(emissionRate) ^ _xmm[0];
  if ( v10 == 0.0 && v4 == 0.0 && v5 == 0.0 )
  {
    v10 = this->mCurrentBasis.v3.x;
    v4 = this->mCurrentBasis.v3.y;
    v5 = this->mCurrentBasis.v3.z;
  }
  v12 = this->mPrevDistance;
  v13 = this->mCurrentBuffer;
  v14 = this->mCurrentBasis.v3.x - v10;
  v15 = v11 - v12;
  v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] - v4) * (float)(v8.m128_f32[0] - v4)) + (float)(v14 * v14))
                 + (float)((float)(this->mCurrentBasis.v3.z - v5) * (float)(this->mCurrentBasis.v3.z - v5));
  v16 = v12 + COERCE_FLOAT(_mm_sqrt_ps(v8));
  v17 = (signed int)(float)(v16 / v11);
  this->mPrevDistance = v16 - (float)((float)v17 * v11);
  if ( v13 )
    v18 = v13->mCapacity;
  else
    v18 = 0;
  for ( ;
        v17;
        v7->mVertexIndexToStartMeshEmissionFrom = (float)((float)v19 * v6->mMeshEmissionVertexSkip)
                                                + v7->mVertexIndexToStartMeshEmissionFrom )
  {
    v19 = v17;
    if ( v17 > v18 )
      v19 = v18;
    v7->mTotalEmitted += v19;
    v17 -= v19;
    Render::ParticleEmitterInstance::UpdateCurrentBuffer(v7, v19, v6, v9);
    v20 = v7->mCurrentBuffer;
    if ( !v20 )
      break;
    v18 = v20->mCapacity;
    v21 = v20->mTaskInfo.inputParam;
    v21->pSettings = v6;
    v22 = v7->mVelocity.y;
    v23 = v7->mVelocity.z;
    v21->emitterVelocity.x = v7->mVelocity.x;
    v21->emitterVelocity.z = v23;
    v21->emitterVelocity.y = v22;
    v21->creationSimTime = v9;
    v24 = v7->mPrevBasis.v1;
    v25 = v7->mPrevBasis.v2;
    v26 = v7->mPrevBasis.v3;
    v21->oldBasis.v0 = v7->mPrevBasis.v0;
    v21->oldBasis.v1 = v24;
    v21->oldBasis.v2 = v25;
    v21->oldBasis.v3 = v26;
    v27 = v7->mCurrentBasis.v3;
    v28 = v7->mCurrentBasis.v1;
    v29 = v7->mCurrentBasis.v2;
    v21->curBasis.v0 = v7->mCurrentBasis.v0;
    v21->curBasis.v1 = v28;
    v21->curBasis.v2 = v29;
    v21->curBasis.v3 = v27;
    v21->t = v15;
    v21->resumeTimeSkip = 0.0;
    v21->currentAddCount = v19;
    v21->emissionType = 1;
    v21->spacing = v11;
    v21->vertexIndexToStartMeshEmissionFrom = v7->mVertexIndexToStartMeshEmissionFrom;
    v15 = v15 + (float)((float)v19 * v11);
  }
}

