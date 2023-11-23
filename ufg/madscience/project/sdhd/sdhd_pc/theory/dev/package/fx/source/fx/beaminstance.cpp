// File Line: 44
// RVA: 0x1C0E50
void __fastcall Render::BeamInstance::BeamInstance(Render::BeamInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::BeamInstance::`vftable;
  this->mCallback = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
}

// File Line: 47
// RVA: 0x1C2D10
void __fastcall Render::BeamInstance::~BeamInstance(Render::BeamInstance *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  Render::BeamInstanceCallbackUserData *mCallback; // rax
  Render::BeamInstanceCallbackUserData *v5; // rcx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::BeamInstance::`vftable;
  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    Inventory = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v3 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
    if ( this->mIsSuspended )
      this->mIsSuspended = 0;
  }
  mCallback = this->mCallback;
  if ( mCallback )
  {
    mCallback->IsValid = 0;
    v5 = this->mCallback;
    if ( !v5->CallbackPending )
      operator delete[](v5);
  }
  v6 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xA0AAE10F);
    `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, v6);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 63
// RVA: 0x1CD440
void __fastcall Render::BeamInstance::Init(Render::BeamInstance *this, unsigned int settingsId)
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
    Inventory = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  v6 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
  mSettingsId = this->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xA0AAE10F);
    `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xA0AAE10F, mSettingsId, v6);
}

// File Line: 73
// RVA: 0x1C5510
void __fastcall Render::BeamInstance::Activate(Render::BeamInstance *this)
{
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rdi
  UFG::qMatrix44 *p_mBasis; // rdx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h] BYREF

  if ( !this->mIsActive )
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
    y = dst.v3.y;
    this->mLastPosition.x = dst.v3.x;
    z = dst.v3.z;
    this->mLastPosition.y = y;
    this->mLastPosition.z = z;
    *(_WORD *)&this->mIsActive = 1;
  }
}

// File Line: 86
// RVA: 0x1CA860
void __fastcall Render::BeamInstance::Deactivate(Render::BeamInstance *this, bool willLoopImmediately)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax

  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    Inventory = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
    if ( this->mIsSuspended )
      this->mIsSuspended = 0;
  }
}

// File Line: 105
// RVA: 0x1D5D90
void __fastcall Render::GeoInstance::Resume(Render::TrackStripInstance *this, float sim_time)
{
  this->mIsSuspended = 0;
}

// File Line: 110
// RVA: 0x1D8650
void __fastcall Render::BeamInstance::Suspend(Render::TrackStripInstance *this, float sim_time)
{
  this->mIsSuspended = 1;
}

// File Line: 116
// RVA: 0x1D8860
void __fastcall Render::BeamInstance::Update(Render::BeamInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  unsigned int mSettingsId; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *mData; // rdi
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rsi
  UFG::qMatrix44 *p_mBasis; // rdx
  float x; // xmm6_4
  float y; // xmm5_4
  float z; // xmm4_4
  float v14; // xmm0_4
  UFG::allocator::free_link *v15; // rax
  Render::BeamInstanceCallbackUserData *v16; // rdx
  float v17; // xmm11_4
  float v18; // xmm5_4
  __m128 y_low; // xmm4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm3_4
  __m128 v23; // xmm2
  float v24; // xmm8_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  int v27[6]; // [rsp+40h] [rbp-51h] BYREF
  UFG::qMatrix44 dst; // [rsp+58h] [rbp-39h] BYREF
  UFG::allocator::free_link *retaddr; // [rsp+F8h] [rbp+67h]

  if ( !this->mSettingsHandle.mData )
  {
    mSettingsId = this->mSettingsId;
    Inventory = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xA0AAE10F, mSettingsId, Inventory);
  }
  mData = this->mSettingsHandle.mData;
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
    if ( *(_DWORD *)&mData[1].mDebugName[4] == 1 )
    {
      x = dst.v3.x;
      this->mLastPosition.x = dst.v3.x;
      y = dst.v3.y;
      this->mLastPosition.y = dst.v3.y;
      z = dst.v3.z;
      this->mLastPosition.z = dst.v3.z;
      v14 = *((float *)&mData[1].mResourceHandles.mNode.mNext + 1);
      *(float *)v27 = x + (float)(dst.v0.x * v14);
      *(float *)&v27[1] = y + (float)(dst.v0.y * v14);
      *(float *)&v27[2] = z + (float)(dst.v0.z * v14);
      v15 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v16 = (Render::BeamInstanceCallbackUserData *)v15;
      retaddr = v15;
      if ( v15 )
      {
        LOWORD(v15->mNext) = 1;
        BYTE2(v15->mNext) = 0;
        v15[1].mNext = (UFG::allocator::free_link *)this;
        v15[2].mNext = (UFG::allocator::free_link *)mData;
      }
      else
      {
        v16 = 0i64;
      }
      this->mCallback = v16;
      if ( ((unsigned __int8 (__fastcall *)(UFG::BasePhysicsSystem *, UFG::qVector3 *, int *, __int64, void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, char *), _QWORD, Render::BeamInstanceCallbackUserData *, __int64))UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay)(
             UFG::BasePhysicsSystem::mInstance,
             &this->mLastPosition,
             v27,
             12i64,
             Render::BeamInstance::AsyncRayCallback,
             0i64,
             v16,
             -2i64) )
      {
        this->mCallback->CallbackPending = 1;
        this->mCallback->CallbackProcessed = 0;
      }
      else
      {
        operator delete[](this->mCallback);
        this->mCallback = 0i64;
      }
    }
    else
    {
      v17 = dst.v3.x;
      v18 = this->mLastPosition.x - dst.v3.x;
      y_low = (__m128)LODWORD(this->mLastPosition.y);
      v20 = dst.v3.y;
      y_low.m128_f32[0] = y_low.m128_f32[0] - dst.v3.y;
      v21 = dst.v3.z;
      v22 = this->mLastPosition.z - dst.v3.z;
      v23 = y_low;
      v23.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v18 * v18))
                      + (float)(v22 * v22);
      v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
      v25 = (float)((float)(v24 * v18) * *((float *)&mData[1].mResourceHandles.mNode.mNext + 1)) + dst.v3.x;
      v23.m128_f32[0] = (float)((float)(v24 * y_low.m128_f32[0]) * *((float *)&mData[1].mResourceHandles.mNode.mNext + 1))
                      + dst.v3.y;
      v26 = (float)((float)(v24 * v22) * *((float *)&mData[1].mResourceHandles.mNode.mNext + 1)) + dst.v3.z;
      dst.v3.y = 0.0;
      *(_QWORD *)&dst.v0.x = mData;
      dst.v2 = (UFG::qVector4)UFG::qColour::Maroon;
      dst.v1.y = dst.v3.x;
      dst.v1.z = v20;
      dst.v1.w = dst.v3.z;
      dst.v0.z = v25;
      LODWORD(dst.v0.w) = v23.m128_i32[0];
      dst.v1.x = v26;
      dst.v3.x = *(float *)&mData[1].mResourceHandles.mNode.mNext;
      Render::BeamManager::AddBeam(&Render::gBeamManager, (Render::BeamManager::AddBeamParameters *)&dst);
      this->mLastPosition.x = v17;
      this->mLastPosition.y = v20;
      this->mLastPosition.z = v21;
    }
  }
}

// File Line: 185
// RVA: 0x1C7490
void __fastcall Render::BeamInstance::AsyncRayCallback(
        UFG::RayCastData *ray,
        UFG::SimComponent *__formal,
        char *callbackUserData)
{
  bool v3; // zf
  __int64 v5; // rax
  Render::BeamSettings *v6; // rdx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float mWidth; // xmm1_4
  float y; // xmm1_4
  float v12; // xmm2_4
  Render::BeamManager::AddBeamParameters beamParameters; // [rsp+20h] [rbp-48h] BYREF

  v3 = *callbackUserData == 0;
  *(_WORD *)(callbackUserData + 1) = 256;
  if ( !v3 )
  {
    v5 = *((_QWORD *)callbackUserData + 1);
    if ( *(_BYTE *)(v5 + 44) && !*(_BYTE *)(v5 + 45) )
    {
      v6 = (Render::BeamSettings *)*((_QWORD *)callbackUserData + 2);
      if ( v6 && v6->mLifeTime > 0.0 )
      {
        v3 = !ray->hit;
        beamParameters.age = 0.0;
        beamParameters.beamSettings = v6;
        beamParameters.colour.r = UFG::qColour::Maroon.r;
        beamParameters.colour.g = UFG::qColour::Maroon.g;
        beamParameters.colour.b = UFG::qColour::Maroon.b;
        v7 = *(float *)(v5 + 64);
        beamParameters.colour.a = UFG::qColour::Maroon.a;
        v8 = *(float *)(v5 + 68);
        beamParameters.startPoint.x = v7;
        v9 = *(float *)(v5 + 72);
        beamParameters.startPoint.y = v8;
        mWidth = v6->mWidth;
        beamParameters.startPoint.z = v9;
        beamParameters.width = mWidth;
        if ( v3 )
        {
          v12 = ray->mInput.m_to.m_quad.m128_f32[2];
          y = ray->mInput.m_to.m_quad.m128_f32[1];
          LODWORD(beamParameters.endPoint.x) = ray->mInput.m_to.m_quad.m128_i32[0];
          beamParameters.endPoint.z = v12;
        }
        else
        {
          y = ray->point.y;
          beamParameters.endPoint.x = ray->point.x;
          beamParameters.endPoint.z = ray->point.z;
        }
        beamParameters.endPoint.y = y;
        Render::BeamManager::AddBeam(&Render::gBeamManager, &beamParameters);
      }
      v5 = *((_QWORD *)callbackUserData + 1);
    }
    *(_QWORD *)(v5 + 56) = 0i64;
  }
  operator delete[](callbackUserData);
}

