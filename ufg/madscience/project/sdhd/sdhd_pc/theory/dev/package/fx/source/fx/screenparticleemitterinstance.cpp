// File Line: 16
// RVA: 0x1C1E50
void __fastcall Render::ScreenParticleEmitterInstance::ScreenParticleEmitterInstance(
        Render::ScreenParticleEmitterInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ScreenParticleEmitterInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  this->mIsEmitting = 0;
  *(_QWORD *)&this->mStartEmissionSimTime = 0i64;
}

// File Line: 20
// RVA: 0x1C46D0
void __fastcall Render::ScreenParticleEmitterInstance::~ScreenParticleEmitterInstance(
        Render::ScreenParticleEmitterInstance *this)
{
  UFG::qTypedResourceHandle<894188764,Render::ScreenParticleEmitterSettings> *p_mSettingsHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::ScreenParticleEmitterInstance::`vftable;
  p_mSettingsHandle = &this->mSettingsHandle;
  Inventory = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x354C3CDCu);
    `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result = Inventory;
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

// File Line: 24
// RVA: 0x1CFB80
void __fastcall Render::ScreenParticleEmitterInstance::Init(
        Render::ScreenParticleEmitterInstance *this,
        unsigned int settingsId)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  Inventory = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x354C3CDCu);
    `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0x354C3CDCu, settingsId, Inventory);
}

// File Line: 50
// RVA: 0x1D9B90
void __fastcall Render::ScreenParticleEmitterInstance::Update(
        Render::ScreenParticleEmitterInstance *this,
        UFG::qVector3 *cam_pos,
        float simTime)
{
  Render::ScreenParticleEmitterSettings *mData; // rdi
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rsi
  UFG::qMatrix44 *p_mBasis; // rdx
  __m128 y_low; // xmm2
  unsigned int mEmissionInit; // edx
  float v12; // xmm1_4
  int v13; // edx
  __int64 v14; // rbx
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-58h] BYREF

  mData = (Render::ScreenParticleEmitterSettings *)this->mSettingsHandle.mData;
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
    y_low = (__m128)LODWORD(dst.v3.y);
    y_low.m128_f32[0] = (float)((float)((float)(dst.v3.y - cam_pos->y) * (float)(dst.v3.y - cam_pos->y))
                              + (float)((float)(dst.v3.x - cam_pos->x) * (float)(dst.v3.x - cam_pos->x)))
                      + (float)((float)(dst.v3.z - cam_pos->z) * (float)(dst.v3.z - cam_pos->z));
    if ( _mm_sqrt_ps(y_low).m128_f32[0] >= mData->mEmissionDistance )
    {
      this->mIsEmitting = 0;
    }
    else
    {
      mEmissionInit = 0;
      if ( !this->mIsEmitting )
      {
        this->mStartEmissionSimTime = simTime;
        this->mParticlesEmitted = 0;
        this->mIsEmitting = 1;
        mEmissionInit = mData->mEmissionInit;
      }
      v12 = (float)((float)(simTime - this->mStartEmissionSimTime) * mData->mEmissionRate)
          - (float)this->mParticlesEmitted;
      v13 = (int)v12 + mEmissionInit;
      this->mParticlesEmitted += (int)v12;
      if ( v13 > 0 )
      {
        v14 = (unsigned int)v13;
        do
        {
          Render::ScreenParticleEmitterManager::AddParticle(&Render::gScreenParticleEmitterManager, mData, simTime);
          --v14;
        }
        while ( v14 );
      }
    }
  }
}

