// File Line: 44
// RVA: 0x1C0E50
void __fastcall Render::BeamInstance::BeamInstance(Render::BeamInstance *this)
{
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v1; // rax

  v1 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::BeamInstance::`vftable;
  this->mCallback = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
}

// File Line: 47
// RVA: 0x1C2D10
void __fastcall Render::BeamInstance::~BeamInstance(Render::BeamInstance *this)
{
  Render::BeamInstance *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  Render::BeamInstanceCallbackUserData *v4; // rax
  Render::BeamInstanceCallbackUserData *v5; // rcx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v8; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v9; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v10; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::BeamInstance::`vftable;
  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    v2 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v3 = UFG::qResourceWarehouse::Instance();
      v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v2;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v2);
    if ( v1->mIsSuspended )
      v1->mIsSuspended = 0;
  }
  v4 = v1->mCallback;
  if ( v4 )
  {
    v4->IsValid = 0;
    v5 = v1->mCallback;
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
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v6);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v8 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
}

// File Line: 63
// RVA: 0x1CD440
void __fastcall Render::BeamInstance::Init(Render::BeamInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  Render::BeamInstance *v3; // rbx
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
    v4 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, v4);
  }
  v6 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
  v7 = v3->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xA0AAE10F);
    `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0xA0AAE10F, v7, v6);
}

// File Line: 73
// RVA: 0x1C5510
void __fastcall Render::BeamInstance::Activate(Render::BeamInstance *this)
{
  Render::BeamInstance *v1; // rbx
  Render::FXInstance *v2; // rax
  UFG::SimComponent *v3; // rdi
  UFG::qMatrix44 *v4; // rdx
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::qMatrix44 dst; // [rsp+30h] [rbp-48h]

  v1 = this;
  if ( !this->mIsActive )
  {
    v2 = this->mContainer;
    v3 = v2->mParentNode.m_pPointer;
    if ( !v3 || v2->mBasisRelativeToParent )
    {
      v4 = &v2->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->mParentNode.m_pPointer);
      v4 = (UFG::qMatrix44 *)&v3[2];
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      v4,
      (UFG::qResourceHandle *)&v1->mContainer->mSettings.mPrev,
      v1->mComponentIndex,
      v1->mStartTime);
    v5 = dst.v3.y;
    v1->mLastPosition.x = dst.v3.x;
    v6 = dst.v3.z;
    v1->mLastPosition.y = v5;
    v1->mLastPosition.z = v6;
    *(_WORD *)&v1->mIsActive = 1;
  }
}

// File Line: 86
// RVA: 0x1CA860
void __fastcall Render::BeamInstance::Deactivate(Render::BeamInstance *this, bool willLoopImmediately)
{
  Render::BeamInstance *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax

  v2 = this;
  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    v3 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v3;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mSettingsHandle.mPrev, v3);
    if ( v2->mIsSuspended )
      v2->mIsSuspended = 0;
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
  Render::BeamInstance *v3; // rbx
  unsigned int v4; // edi
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rdi
  Render::FXInstance *v8; // rax
  UFG::qMatrix44 *v9; // rsi
  UFG::qMatrix44 *v10; // rdx
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rdx
  float v17; // xmm11_4
  float v18; // xmm5_4
  __m128 v19; // xmm4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm3_4
  __m128 v23; // xmm2
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  float v27; // [rsp+40h] [rbp-51h]
  float v28; // [rsp+44h] [rbp-4Dh]
  float v29; // [rsp+48h] [rbp-49h]
  UFG::qMatrix44 dst; // [rsp+58h] [rbp-39h]
  UFG::allocator::free_link *retaddr; // [rsp+F8h] [rbp+67h]

  v3 = this;
  if ( !this->mSettingsHandle.mData )
  {
    v4 = this->mSettingsId;
    v5 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA0AAE10F);
      `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v5;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0xA0AAE10F, v4, v5);
  }
  v7 = v3->mSettingsHandle.mData;
  if ( v7 )
  {
    v8 = v3->mContainer;
    v9 = (UFG::qMatrix44 *)v8->mParentNode.m_pPointer;
    if ( !v9 || v8->mBasisRelativeToParent )
    {
      v10 = &v8->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8->mParentNode.m_pPointer);
      v10 = v9 + 2;
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      v10,
      (UFG::qResourceHandle *)&v3->mContainer->mSettings.mPrev,
      v3->mComponentIndex,
      v3->mStartTime);
    if ( *(_DWORD *)&v7[1].mDebugName[4] == 1 )
    {
      v11 = dst.v3.x;
      v3->mLastPosition.x = dst.v3.x;
      v12 = dst.v3.y;
      v3->mLastPosition.y = dst.v3.y;
      v13 = dst.v3.z;
      v3->mLastPosition.z = dst.v3.z;
      v14 = *((float *)&v7[1].mResourceHandles.mNode.mNext + 1);
      v27 = v11 + (float)(dst.v0.x * v14);
      v28 = v12 + (float)(dst.v0.y * v14);
      v29 = v13 + (float)(dst.v0.z * v14);
      v15 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v16 = v15;
      retaddr = v15;
      if ( v15 )
      {
        LOWORD(v15->mNext) = 1;
        BYTE2(v15->mNext) = 0;
        v15[1].mNext = (UFG::allocator::free_link *)v3;
        v15[2].mNext = (UFG::allocator::free_link *)v7;
      }
      else
      {
        v16 = 0i64;
      }
      v3->mCallback = (Render::BeamInstanceCallbackUserData *)v16;
      if ( ((unsigned __int8 (__fastcall *)(UFG::BasePhysicsSystem *, UFG::qVector3 *, float *, signed __int64, void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *), _QWORD, UFG::allocator::free_link *, signed __int64, _QWORD, _QWORD))UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay)(
             UFG::BasePhysicsSystem::mInstance,
             &v3->mLastPosition,
             &v27,
             12i64,
             Render::BeamInstance::AsyncRayCallback,
             0i64,
             v16,
             -2i64,
             *(_QWORD *)&v27,
             *(_QWORD *)&v29) )
      {
        v3->mCallback->CallbackPending = 1;
        v3->mCallback->CallbackProcessed = 0;
      }
      else
      {
        operator delete[](v3->mCallback);
        v3->mCallback = 0i64;
      }
    }
    else
    {
      v17 = dst.v3.x;
      v18 = v3->mLastPosition.x - dst.v3.x;
      v19 = (__m128)LODWORD(v3->mLastPosition.y);
      v20 = dst.v3.y;
      v19.m128_f32[0] = v19.m128_f32[0] - dst.v3.y;
      v21 = dst.v3.z;
      v22 = v3->mLastPosition.z - dst.v3.z;
      v23 = v19;
      v23.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18)) + (float)(v22 * v22);
      LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
      v25 = (float)((float)((float)(1.0 / v24) * v18) * *((float *)&v7[1].mResourceHandles.mNode.mNext + 1)) + dst.v3.x;
      v23.m128_f32[0] = (float)((float)((float)(1.0 / v24) * v19.m128_f32[0])
                              * *((float *)&v7[1].mResourceHandles.mNode.mNext + 1))
                      + dst.v3.y;
      v26 = (float)((float)((float)(1.0 / v24) * v22) * *((float *)&v7[1].mResourceHandles.mNode.mNext + 1)) + dst.v3.z;
      dst.v3.y = 0.0;
      *(_QWORD *)&dst.v0.x = v7;
      dst.v2 = (UFG::qVector4)UFG::qColour::Maroon;
      dst.v1.y = dst.v3.x;
      dst.v1.z = v20;
      dst.v1.w = dst.v3.z;
      dst.v0.z = v25;
      LODWORD(dst.v0.w) = v23.m128_i32[0];
      dst.v1.x = v26;
      dst.v3.x = *(float *)&v7[1].mResourceHandles.mNode.mNext;
      Render::BeamManager::AddBeam(&Render::gBeamManager, (Render::BeamManager::AddBeamParameters *)&dst);
      v3->mLastPosition.x = v17;
      v3->mLastPosition.y = v20;
      v3->mLastPosition.z = v21;
    }
  }
}

// File Line: 185
// RVA: 0x1C7490
void __fastcall Render::BeamInstance::AsyncRayCallback(UFG::RayCastData *ray, UFG::SimComponent *__formal, void *callbackUserData)
{
  bool v3; // zf
  _QWORD *v4; // rbx
  __int64 v5; // rax
  Render::BeamSettings *v6; // rdx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  Render::BeamManager::AddBeamParameters beamParameters; // [rsp+20h] [rbp-48h]

  v3 = *(_BYTE *)callbackUserData == 0;
  v4 = callbackUserData;
  *(_WORD *)((char *)callbackUserData + 1) = 256;
  if ( !v3 )
  {
    v5 = *((_QWORD *)callbackUserData + 1);
    if ( *(_BYTE *)(v5 + 44) && !*(_BYTE *)(v5 + 45) )
    {
      v6 = (Render::BeamSettings *)*((_QWORD *)callbackUserData + 2);
      if ( v6 && v6->mLifeTime > 0.0 )
      {
        v3 = ray->hit == 0;
        beamParameters.age = 0.0;
        beamParameters.beamSettings = v6;
        beamParameters.colour = UFG::qColour::Maroon;
        v7 = *(float *)(v5 + 68);
        beamParameters.startPoint.x = *(float *)(v5 + 64);
        v8 = *(float *)(v5 + 72);
        beamParameters.startPoint.y = v7;
        v9 = v6->mWidth;
        beamParameters.startPoint.z = v8;
        beamParameters.width = v9;
        if ( v3 )
        {
          v11 = ray->mInput.m_to.m_quad.m128_f32[2];
          v10 = ray->mInput.m_to.m_quad.m128_f32[1];
          beamParameters.endPoint.x = ray->mInput.m_to.m_quad.m128_f32[0];
          beamParameters.endPoint.z = v11;
        }
        else
        {
          v10 = ray->point.y;
          beamParameters.endPoint.x = ray->point.x;
          beamParameters.endPoint.z = ray->point.z;
        }
        beamParameters.endPoint.y = v10;
        Render::BeamManager::AddBeam(&Render::gBeamManager, &beamParameters);
      }
      v5 = v4[1];
    }
    *(_QWORD *)(v5 + 56) = 0i64;
  }
  operator delete[](v4);
}

