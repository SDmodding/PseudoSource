// File Line: 26
// RVA: 0x1C1FA0
void __fastcall Render::VolumetricEffectInstance::VolumetricEffectInstance(Render::VolumetricEffectInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::VolumetricEffectInstance::`vftable;
  this->mOwnedVolumes.p = 0i64;
  *(_QWORD *)&this->mOwnedVolumes.size = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  *(_QWORD *)&this->mActivateTime = 0i64;
  this->mFirstFrameAfterActivateOrLoop = 0;
}

// File Line: 30
// RVA: 0x1C4960
void __fastcall Render::VolumetricEffectInstance::~VolumetricEffectInstance(Render::VolumetricEffectInstance *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  Render::VolumetricEffect **p; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::VolumetricEffectInstance::`vftable;
  Render::VolumetricEffectInstance::Deactivate(this, 0);
  Inventory = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xE4B8F46A);
    `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  p = this->mOwnedVolumes.p;
  if ( p )
    operator delete[](p);
  this->mOwnedVolumes.p = 0i64;
  *(_QWORD *)&this->mOwnedVolumes.size = 0i64;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 35
// RVA: 0x1CFF50
void __fastcall Render::VolumetricEffectInstance::Init(Render::VolumetricEffectInstance *this, unsigned int settingsId)
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
    Inventory = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xE4B8F46A);
      `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  v6 = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result;
  mSettingsId = this->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xE4B8F46A);
    `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xE4B8F46A, mSettingsId, v6);
}

// File Line: 51
// RVA: 0x1C63C0
void __fastcall Render::VolumetricEffectInstance::Activate(Render::VolumetricEffectInstance *this)
{
  float mStartTime; // eax

  if ( !this->mIsActive )
  {
    mStartTime = this->mStartTime;
    *(_WORD *)&this->mIsActive = 1;
    *(_QWORD *)&this->mActivateTime = LODWORD(mStartTime);
    this->mFirstFrameAfterActivateOrLoop = 1;
  }
}

// File Line: 94
// RVA: 0x1CAD10
void __fastcall Render::VolumetricEffectInstance::Deactivate(
        Render::VolumetricEffectInstance *this,
        bool willLoopImmediately)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  Render::VolumetricEffect *v5; // rcx
  unsigned int size; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax

  if ( this->mIsActive && !willLoopImmediately )
  {
    this->mIsActive = 0;
    Inventory = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xE4B8F46A);
      `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
    if ( this->mIsSuspended )
    {
      this->mIsSuspended = 0;
    }
    else if ( this->mOwnedVolumes.size )
    {
      while ( 1 )
      {
        Render::VolumetricEffectManager::RemoveVolume(&Render::gVolumetricEffectManager, *this->mOwnedVolumes.p);
        v5 = *this->mOwnedVolumes.p;
        if ( v5 )
          operator delete[](v5);
        size = this->mOwnedVolumes.size;
        if ( size > 1 )
          *this->mOwnedVolumes.p = this->mOwnedVolumes.p[size - 1];
        v7 = this->mOwnedVolumes.size;
        if ( v7 <= 1 )
          break;
        v8 = v7 - 1;
        this->mOwnedVolumes.size = v8;
        if ( !v8 )
          return;
      }
      this->mOwnedVolumes.size = 0;
    }
  }
}

// File Line: 148
// RVA: 0x1DB070
void __fastcall Render::VolumetricEffectInstance::Update(
        Render::VolumetricEffectInstance *this,
        UFG::qVector3 *cam_pos,
        float sim_time)
{
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v7; // rax
  Render::VolumetricEffectSettings *mData; // rbp
  unsigned int i; // edi
  Render::VolumetricEffect *v10; // rdx
  Render::VolumetricEffect *v11; // rcx
  unsigned int size; // eax
  unsigned int v13; // eax

  if ( !this->mSettingsHandle.mData )
  {
    Inventory = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result;
    mSettingsId = this->mSettingsId;
    if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0xE4B8F46A);
      `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xE4B8F46A, mSettingsId, Inventory);
    *(_QWORD *)&this->mActivateTime = LODWORD(sim_time);
  }
  mData = (Render::VolumetricEffectSettings *)this->mSettingsHandle.mData;
  if ( mData )
  {
    for ( i = 0; i < this->mOwnedVolumes.size; ++i )
    {
      Render::VolumetricEffectInstance::UpdateVolume(this, cam_pos, mData, this->mOwnedVolumes.p[i], sim_time);
      v10 = this->mOwnedVolumes.p[i];
      if ( (float)(v10->fEndTime - v10->fStartTime) > 0.0 && sim_time > v10->fEndTime )
      {
        Render::VolumetricEffectManager::RemoveVolume(&Render::gVolumetricEffectManager, v10);
        v11 = this->mOwnedVolumes.p[i];
        if ( v11 )
          operator delete[](v11);
        size = this->mOwnedVolumes.size;
        if ( size > 1 )
          this->mOwnedVolumes.p[i] = this->mOwnedVolumes.p[size - 1];
        v13 = this->mOwnedVolumes.size;
        if ( v13 > 1 )
          this->mOwnedVolumes.size = v13 - 1;
        else
          this->mOwnedVolumes.size = 0;
        --i;
      }
    }
    if ( mData->mEmissionRate > 0.0 || this->mFirstFrameAfterActivateOrLoop )
      Render::VolumetricEffectInstance::UpdateTimeEmission(this, cam_pos, mData, sim_time, mData->mEmissionRate);
  }
}

// File Line: 196
// RVA: 0x1DC920
void __fastcall Render::VolumetricEffectInstance::UpdateVolume(
        Render::VolumetricEffectInstance *this,
        UFG::qVector3 *cam_pos,
        Render::VolumetricEffectSettings *lfx,
        Render::VolumetricEffect *volume,
        float sim_time)
{
  float mStartTime; // xmm1_4
  float v10; // xmm0_4
  float lifetime; // xmm7_4
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rbp
  UFG::qMatrix44 *p_mBasis; // rdx
  float x; // xmm12_4
  float y; // xmm13_4
  float z; // xmm14_4
  float v18; // xmm9_4
  float v19; // xmm6_4
  float v20; // xmm8_4
  float mSimTimeDelta; // xmm10_4
  float v22; // xmm3_4
  float v23; // xmm6_4
  float v24; // xmm9_4
  float v25; // xmm8_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  UFG::qVector4 *v30; // rax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float w; // xmm2_4
  UFG::qVector4 result; // [rsp+30h] [rbp-E8h] BYREF
  UFG::qMatrix44 dst; // [rsp+40h] [rbp-D8h] BYREF
  int sim_timea; // [rsp+140h] [rbp+28h]

  mStartTime = this->mStartTime;
  v10 = this->mEndTime - mStartTime;
  if ( v10 <= 0.0 )
    lifetime = FLOAT_N1_0;
  else
    lifetime = (float)(sim_time - mStartTime) / v10;
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
  x = dst.v3.x;
  y = dst.v3.y;
  z = dst.v3.z;
  v18 = volume->vCurrPos.x - dst.v3.x;
  v19 = volume->vCurrPos.y - dst.v3.y;
  v20 = volume->vCurrPos.z - dst.v3.z;
  UFG::qHalfVector4::operator UFG::qVector4 const(&volume->vVelAndDamp, &result);
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  v22 = result.x;
  v23 = v19 + (float)(result.y * UFG::Metrics::msInstance.mSimTimeDelta);
  v24 = v18 + (float)(result.x * UFG::Metrics::msInstance.mSimTimeDelta);
  v25 = v20 + (float)(result.z * UFG::Metrics::msInstance.mSimTimeDelta);
  if ( v24 >= lfx->mWrapRegionMin.x )
  {
    if ( v24 > lfx->mWrapRegionMax.x )
      v24 = lfx->mWrapRegionMin.x;
  }
  else
  {
    v24 = lfx->mWrapRegionMax.x;
  }
  if ( v23 >= lfx->mWrapRegionMin.y )
  {
    if ( v23 > lfx->mWrapRegionMax.y )
      v23 = lfx->mWrapRegionMin.y;
  }
  else
  {
    v23 = lfx->mWrapRegionMax.y;
  }
  if ( v25 >= lfx->mWrapRegionMin.z )
  {
    if ( v25 > lfx->mWrapRegionMax.z )
      v25 = lfx->mWrapRegionMin.z;
  }
  else
  {
    v25 = lfx->mWrapRegionMax.z;
  }
  v26 = UFG::Metrics::msInstance.mSimTimeDelta * 0.0;
  volume->vCurrPos.x = x + v24;
  volume->vCurrPos.y = y + v23;
  v27 = v26;
  v28 = (float)(mSimTimeDelta * 0.0) + result.y;
  volume->vCurrPos.z = z + v25;
  v29 = (float)(volume->vPosAndGrav.w * mSimTimeDelta) + result.z;
  sim_timea = ((((volume->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((volume->vVelAndDamp.w.mRep & 0x3FF | (8 * (volume->vVelAndDamp.w.mRep & 0x8000))) << 13);
  result.x = (float)(v27 + v22) - (float)((float)((float)(v27 + v22) * mSimTimeDelta) * *(float *)&sim_timea);
  result.y = v28 - (float)((float)(v28 * mSimTimeDelta) * *(float *)&sim_timea);
  result.z = v29 - (float)((float)(v29 * mSimTimeDelta) * *(float *)&sim_timea);
  Render::VolumetricEffect::SetVelocity(volume, (UFG::qVector3 *)&result);
  if ( lifetime > 0.0 )
  {
    v30 = Render::VolumetricEffectInstance::ComputeColor(this, &result, cam_pos, lfx, volume, lifetime);
    v31 = v30->y;
    v32 = v30->z;
    w = v30->w;
    volume->fColour.x = v30->x;
    volume->fColour.y = v31;
    volume->fColour.z = v32;
    volume->fColour.w = w;
  }
}

// File Line: 245
// RVA: 0x1CA660
UFG::qVector3 *__fastcall Render::CreateTimeUpdateJitterVector(
        UFG::qVector3 *result,
        Render::VolumetricEffectSettings *lfx,
        UFG::qMatrix44 *curBasis,
        float scale)
{
  float v8; // xmm8_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  UFG::qVector3 *v11; // rax
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm11_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm10_4
  float v18; // xmm4_4
  float v19; // xmm5_4

  v8 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
  v9 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
  v10 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
  v11 = result;
  v12 = (float)((float)((float)(lfx->mWrapRegionMax.y - lfx->mWrapRegionMin.y) * v9) + lfx->mWrapRegionMin.y) * scale;
  v13 = (float)(lfx->mWrapRegionMin.x + (float)((float)(lfx->mWrapRegionMax.x - lfx->mWrapRegionMin.x) * v10)) * scale;
  v14 = (float)((float)(v13 * curBasis->v0.z) + curBasis->v3.z) + (float)(v12 * curBasis->v1.z);
  v15 = (float)((float)(v13 * curBasis->v0.x) + curBasis->v3.x) + (float)(v12 * curBasis->v1.x);
  v16 = (float)((float)(v13 * curBasis->v0.y) + curBasis->v3.y) + (float)(v12 * curBasis->v1.y);
  v17 = (float)((float)((float)(lfx->mWrapRegionMax.z - lfx->mWrapRegionMin.z) * v8) + lfx->mWrapRegionMin.z) * scale;
  v18 = v17 * curBasis->v2.x;
  v19 = v17 * curBasis->v2.y;
  result->z = v14 + (float)(v17 * curBasis->v2.z);
  result->x = v15 + v18;
  result->y = v16 + v19;
  return v11;
}

// File Line: 264
// RVA: 0x1DC240
void __fastcall Render::VolumetricEffectInstance::UpdateTimeEmission(
        Render::VolumetricEffectInstance *this,
        UFG::qVector3 *cam_pos,
        Render::VolumetricEffectSettings *lfx,
        float sim_time,
        float emissionRate)
{
  float v8; // xmm1_4
  int v9; // r12d
  unsigned int v10; // r12d
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbp
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qMatrix44 *p_mBasis; // rdx
  float mRadMin; // xmm6_4
  unsigned int i; // ebx
  UFG::qVector3 *updated; // rax
  float x; // xmm8_4
  float y; // xmm11_4
  float z; // xmm12_4
  float v22; // xmm5_4
  int v23; // edx
  unsigned int size; // r8d
  Render::VolumetricEffect *v25; // rcx
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm8_4
  UFG::qVector3 *v32; // rax
  float v33; // xmm7_4
  float v34; // xmm8_4
  float mDragMin; // xmm6_4
  float mGravityMin; // xmm8_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  float mLifeMin; // xmm6_4
  float v40; // xmm0_4
  UFG::qVector4 *v41; // rax
  float v42; // xmm0_4
  float v43; // xmm1_4
  float w; // xmm2_4
  __int64 v45; // r15
  unsigned int v46; // esi
  unsigned int capacity; // ebx
  unsigned int v48; // ebx
  unsigned __int64 v49; // rax
  UFG::allocator::free_link *v50; // rax
  Render::VolumetricEffect **v51; // r14
  __int64 j; // r9
  int v53; // [rsp+34h] [rbp-154h]
  int v54; // [rsp+38h] [rbp-150h]
  UFG::qVector3 velocity; // [rsp+40h] [rbp-148h] BYREF
  UFG::qVector3 vVel; // [rsp+4Ch] [rbp-13Ch] BYREF
  UFG::allocator::free_link *v57; // [rsp+58h] [rbp-130h]
  __int64 v58; // [rsp+60h] [rbp-128h]
  UFG::qVector3 result; // [rsp+68h] [rbp-120h] BYREF
  UFG::qVector3 v60; // [rsp+74h] [rbp-114h] BYREF
  UFG::qVector4 v61; // [rsp+80h] [rbp-108h] BYREF
  UFG::qMatrix44 dst; // [rsp+90h] [rbp-F8h] BYREF
  __int64 v63; // [rsp+190h] [rbp+8h]

  v58 = -2i64;
  v8 = emissionRate;
  if ( emissionRate <= 0.0 )
    v8 = 0.0;
  v9 = (int)(float)((float)(sim_time - this->mActivateTime) * v8);
  if ( this->mFirstFrameAfterActivateOrLoop )
  {
    v9 += lfx->mEmissionInit;
    this->mFirstFrameAfterActivateOrLoop = 0;
  }
  if ( this->mTotalEmitted > v9 )
  {
    this->mTotalEmitted = 0;
    v9 = 0;
    this->mActivateTime = sim_time;
  }
  v10 = v9 - this->mTotalEmitted;
  if ( v10 )
  {
    v63 = v10;
    do
    {
      v11 = UFG::qMalloc(0x170ui64, UFG::gGlobalNewName, 0i64);
      v12 = v11;
      v57 = v11;
      if ( v11 )
      {
        UFG::qHalfVector4::qHalfVector4((UFG::qHalfVector4 *)&v11[36]);
        UFG::qHalfVector4::qHalfVector4((UFG::qHalfVector4 *)&v12[37]);
        v12[44].mNext = 0i64;
        v12[45].mNext = 0i64;
      }
      else
      {
        v12 = 0i64;
      }
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
      mRadMin = lfx->mRadMin;
      *((float *)&v12[33].mNext + 1) = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed)
                                             * (float)(lfx->mRadMax - mRadMin))
                                     + mRadMin;
      for ( i = 0; i < 0x1E; ++i )
      {
        updated = Render::CreateTimeUpdateJitterVector(&result, lfx, &dst, 1.0);
        x = updated->x;
        y = updated->y;
        z = updated->z;
        v22 = 0.0;
        v23 = 0;
        size = this->mOwnedVolumes.size;
        if ( !size )
          break;
        while ( 1 )
        {
          v25 = this->mOwnedVolumes.p[v23];
          v26 = *((float *)&v12[33].mNext + 1) + v25->fScale;
          v27 = fsqrt(
                  (float)((float)((float)(x - v25->vCurrPos.x) * (float)(x - v25->vCurrPos.x))
                        + (float)((float)(y - v25->vCurrPos.y) * (float)(y - v25->vCurrPos.y)))
                + (float)((float)(z - v25->vCurrPos.z) * (float)(z - v25->vCurrPos.z)));
          if ( v26 <= 1.0 )
            v26 = *(float *)&FLOAT_1_0;
          v28 = v27 / v26;
          if ( v28 <= 0.0 )
          {
            v28 = 0.0;
          }
          else if ( v28 >= 1.0 )
          {
            v28 = *(float *)&FLOAT_1_0;
          }
          v22 = v22 + (float)(1.0 - v28);
          if ( v22 > Render::gMaximumVolumeOverlap )
            break;
          if ( ++v23 >= size )
            goto LABEL_28;
        }
      }
LABEL_28:
      *(float *)&v12[34].mNext = x;
      *((float *)&v12[34].mNext + 1) = y;
      *(float *)&v12[35].mNext = z;
      *(float *)&v12[32].mNext = x;
      *((float *)&v12[32].mNext + 1) = y;
      *(float *)&v12[33].mNext = z;
      v29 = lfx->mGlobalVelocityMax.x - lfx->mGlobalVelocityMin.x;
      v30 = lfx->mGlobalVelocityMax.y - lfx->mGlobalVelocityMin.y;
      v31 = lfx->mGlobalVelocityMax.z - lfx->mGlobalVelocityMin.z;
      v32 = UFG::qRandom(&v60, &UFG::qVector3::msOne, (unsigned int *)&UFG::qDefaultSeed);
      v33 = v30 * v32->y;
      v34 = v31 * v32->z;
      velocity.x = (float)(v29 * v32->x) + lfx->mGlobalVelocityMin.x;
      velocity.y = v33 + lfx->mGlobalVelocityMin.y;
      velocity.z = v34 + lfx->mGlobalVelocityMin.z;
      Render::VolumetricEffect::SetInitialVelocity((Render::VolumetricEffect *)v12, &velocity);
      v53 = ((((WORD1(v12[37].mNext) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((WORD1(v12[37].mNext) & 0x3FF | (8 * (WORD1(v12[37].mNext) & 0x8000))) << 13);
      v54 = ((((WORD2(v12[37].mNext) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((WORD2(v12[37].mNext) & 0x3FF | (8 * (WORD2(v12[37].mNext) & 0x8000))) << 13);
      LODWORD(vVel.x) = ((((LOWORD(v12[37].mNext) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | (((__int64)v12[37].mNext & 0x3FF | (8 * ((__int64)v12[37].mNext & 0x8000))) << 13);
      LODWORD(vVel.y) = v53;
      LODWORD(vVel.z) = v54;
      mDragMin = lfx->mDragMin;
      mGravityMin = lfx->mGravityMin;
      v37 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(lfx->mDragMax - mDragMin))
          + mDragMin;
      v38 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      Render::VolumetricEffect::SetVelocityGravityAndDrag(
        (Render::VolumetricEffect *)v12,
        &vVel,
        (float)(v38 * (float)(lfx->mGravityMax - mGravityMin)) + mGravityMin,
        v37);
      mLifeMin = lfx->mLifeMin;
      v40 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(lfx->mLifeMax - mLifeMin))
          + (float)(mLifeMin + sim_time);
      *(float *)&v12[38].mNext = sim_time;
      *((float *)&v12[38].mNext + 1) = v40;
      v41 = Render::VolumetricEffectInstance::ComputeColor(
              this,
              &v61,
              cam_pos,
              lfx,
              (Render::VolumetricEffect *)v12,
              0.0);
      v42 = v41->y;
      v43 = v41->z;
      w = v41->w;
      *(float *)&v12[39].mNext = v41->x;
      *((float *)&v12[39].mNext + 1) = v42;
      *(float *)&v12[40].mNext = v43;
      *((float *)&v12[40].mNext + 1) = w;
      *(float *)&v12[41].mNext = lfx->mIntensity;
      HIDWORD(v12[41].mNext) = LODWORD(lfx->mIntensity);
      *(float *)&v12[42].mNext = lfx->mBentNormals;
      HIDWORD(v12[42].mNext) = LODWORD(lfx->mLightingContribution);
      LOBYTE(v12[43].mNext) = this->mContainer->mParentNode.m_pPointer == Render::gFXManager.mCamTransformNode.m_pPointer;
      v45 = this->mOwnedVolumes.size;
      v46 = v45 + 1;
      capacity = this->mOwnedVolumes.capacity;
      if ( (int)v45 + 1 > capacity )
      {
        if ( capacity )
          v48 = 2 * capacity;
        else
          v48 = 1;
        for ( ; v48 < v46; v48 *= 2 )
          ;
        if ( v48 <= 2 )
          v48 = 2;
        if ( v48 - v46 > 0x10000 )
          v48 = v45 + 65537;
        if ( v48 != (_DWORD)v45 )
        {
          v49 = 8i64 * v48;
          if ( !is_mul_ok(v48, 8ui64) )
            v49 = -1i64;
          v50 = UFG::qMalloc(v49, "qArray.Add", 0i64);
          v51 = (Render::VolumetricEffect **)v50;
          if ( this->mOwnedVolumes.p )
          {
            for ( j = 0i64; (unsigned int)j < this->mOwnedVolumes.size; j = (unsigned int)(j + 1) )
              v50[j] = (UFG::allocator::free_link)this->mOwnedVolumes.p[j];
            operator delete[](this->mOwnedVolumes.p);
          }
          this->mOwnedVolumes.p = v51;
          this->mOwnedVolumes.capacity = v48;
        }
      }
      this->mOwnedVolumes.size = v46;
      this->mOwnedVolumes.p[v45] = (Render::VolumetricEffect *)v12;
      Render::VolumetricEffectManager::AddVolume(&Render::gVolumetricEffectManager, (Render::VolumetricEffect *)v12);
      --v63;
    }
    while ( v63 );
    this->mTotalEmitted += v10;
  }
  else
  {
    this->mTotalEmitted = this->mTotalEmitted;
  }
}

// File Line: 339
// RVA: 0x1C8510
UFG::qVector4 *__fastcall Render::VolumetricEffectInstance::ComputeColor(
        Render::VolumetricEffectInstance *this,
        UFG::qVector4 *result,
        UFG::qVector3 *cam_pos,
        Render::VolumetricEffectSettings *lfx,
        Render::VolumetricEffect *volume,
        float lifetime)
{
  float v6; // xmm1_4
  float w; // eax
  float v9; // xmm0_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm8_4
  float v17; // xmm0_4
  float v18; // xmm8_4
  Render::VolumetricEffectSettings::DistanceScaleKey *mDistanceScaleKeys; // rcx
  __int64 v20; // rdx
  __m128 y_low; // xmm2
  Render::VolumetricEffectSettings::DistanceScaleKey *v22; // rax
  float v23; // xmm3_4
  Render::VolumetricEffectSettings::DistanceScaleKey *v24; // r9
  float v25; // xmm2_4
  float v26; // xmm0_4

  v6 = lfx->mColorKeyPositions[0];
  if ( lifetime >= v6 )
  {
    v9 = lfx->mColorKeyPositions[1];
    if ( lifetime >= v9 )
    {
      v15 = lfx->mColorKeyPositions[2];
      if ( lifetime >= v15 )
      {
        v17 = lfx->mColorKeyPositions[3];
        if ( lifetime >= v17 )
        {
          result->x = lfx->mColorKeys[3].x;
          result->y = lfx->mColorKeys[3].y;
          result->z = lfx->mColorKeys[3].z;
          w = lfx->mColorKeys[3].w;
          goto LABEL_11;
        }
        v18 = (float)(lifetime - v15) / (float)(v17 - v15);
        v11 = (float)((float)(lfx->mColorKeys[3].x - lfx->mColorKeys[2].x) * v18) + lfx->mColorKeys[2].x;
        v12 = (float)((float)(lfx->mColorKeys[3].y - lfx->mColorKeys[2].y) * v18) + lfx->mColorKeys[2].y;
        v13 = (float)((float)(lfx->mColorKeys[3].z - lfx->mColorKeys[2].z) * v18) + lfx->mColorKeys[2].z;
        v14 = (float)((float)(lfx->mColorKeys[3].w - lfx->mColorKeys[2].w) * v18) + lfx->mColorKeys[2].w;
      }
      else
      {
        v16 = (float)(lifetime - v9) / (float)(v15 - v9);
        v11 = (float)((float)(lfx->mColorKeys[2].x - lfx->mColorKeys[1].x) * v16) + lfx->mColorKeys[1].x;
        v12 = (float)((float)(lfx->mColorKeys[2].y - lfx->mColorKeys[1].y) * v16) + lfx->mColorKeys[1].y;
        v13 = (float)((float)(lfx->mColorKeys[2].z - lfx->mColorKeys[1].z) * v16) + lfx->mColorKeys[1].z;
        v14 = (float)((float)(lfx->mColorKeys[2].w - lfx->mColorKeys[1].w) * v16) + lfx->mColorKeys[1].w;
      }
    }
    else
    {
      v10 = (float)(lifetime - v6) / (float)(v9 - v6);
      v11 = (float)((float)(lfx->mColorKeys[1].x - lfx->mColorKeys[0].x) * v10) + lfx->mColorKeys[0].x;
      v12 = (float)((float)(lfx->mColorKeys[1].y - lfx->mColorKeys[0].y) * v10) + lfx->mColorKeys[0].y;
      v13 = (float)((float)(lfx->mColorKeys[1].z - lfx->mColorKeys[0].z) * v10) + lfx->mColorKeys[0].z;
      v14 = (float)((float)(lfx->mColorKeys[1].w - lfx->mColorKeys[0].w) * v10) + lfx->mColorKeys[0].w;
    }
    result->x = v11;
    result->y = v12;
    result->z = v13;
    result->w = v14;
    goto LABEL_12;
  }
  result->x = lfx->mColorKeys[0].x;
  result->y = lfx->mColorKeys[0].y;
  result->z = lfx->mColorKeys[0].z;
  w = lfx->mColorKeys[0].w;
LABEL_11:
  result->w = w;
LABEL_12:
  if ( lfx->mUseDistanceScale )
  {
    mDistanceScaleKeys = lfx->mDistanceScaleKeys;
    v20 = 0i64;
    y_low = (__m128)LODWORD(volume->vCurrPos.y);
    v22 = lfx->mDistanceScaleKeys;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - cam_pos->y) * (float)(y_low.m128_f32[0] - cam_pos->y))
                              + (float)((float)(volume->vCurrPos.x - cam_pos->x)
                                      * (float)(volume->vCurrPos.x - cam_pos->x)))
                      + (float)((float)(volume->vCurrPos.z - cam_pos->z) * (float)(volume->vCurrPos.z - cam_pos->z));
    LODWORD(v23) = _mm_sqrt_ps(y_low).m128_u32[0];
    do
    {
      if ( v23 < v22->mDistance )
        break;
      v20 = (unsigned int)(v20 + 1);
      ++v22;
    }
    while ( (unsigned int)v20 < 5 );
    if ( (_DWORD)v20 && (mDistanceScaleKeys = &lfx->mDistanceScaleKeys[(unsigned int)(v20 - 1)], (_DWORD)v20 == 5) )
      v24 = &lfx->mDistanceScaleKeys[4];
    else
      v24 = &lfx->mDistanceScaleKeys[v20];
    v25 = 0.0;
    v26 = mDistanceScaleKeys->mDistance - v24->mDistance;
    if ( v26 < 0.0 )
      LODWORD(v26) ^= _xmm[0];
    if ( v26 >= 0.001 )
      v25 = (float)(v23 - mDistanceScaleKeys->mDistance) / (float)(v24->mDistance - mDistanceScaleKeys->mDistance);
    result->w = (float)((float)((float)(v24->mScale - mDistanceScaleKeys->mScale) * v25) + mDistanceScaleKeys->mScale)
              * result->w;
  }
  return result;
}

// File Line: 432
// RVA: 0x1C8320
void __fastcall Render::VolumetricEffectInstance::ChatlineLiveUpdate(Render::VolumetricEffectInstance *this)
{
  unsigned int size; // edx
  Render::VolumetricEffect *v3; // rdi
  unsigned int v4; // eax
  Render::VolumetricEffect **p; // r8
  Render::VolumetricEffect **v6; // rcx
  __int64 v7; // rsi
  CullManager *v8; // rax
  Render::VolumetricEffect *v9; // rcx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  float mStartTime; // eax

  if ( this->mOwnedVolumes.size )
  {
    while ( 1 )
    {
      size = Render::gVolumetricEffectManager.mVolumes.size;
      v3 = *this->mOwnedVolumes.p;
      v4 = 0;
      if ( Render::gVolumetricEffectManager.mVolumes.size )
      {
        p = Render::gVolumetricEffectManager.mVolumes.p;
        v6 = Render::gVolumetricEffectManager.mVolumes.p;
        while ( *v6 != v3 )
        {
          ++v4;
          ++v6;
          if ( v4 >= Render::gVolumetricEffectManager.mVolumes.size )
            goto LABEL_13;
        }
        v7 = v4;
        if ( Render::gVolumetricEffectManager.mVolumes.p[v4]->cull_info )
        {
          v8 = CullManager::Instance();
          CullManager::FreePersistentCullInfo(v8, v3->cull_results, v3->cull_info);
          v3->cull_results = 0i64;
          v3->cull_info = 0i64;
          p = Render::gVolumetricEffectManager.mVolumes.p;
          size = Render::gVolumetricEffectManager.mVolumes.size;
        }
        if ( size <= 1 || (p[v7] = p[size - 1], Render::gVolumetricEffectManager.mVolumes.size <= 1) )
          Render::gVolumetricEffectManager.mVolumes.size = 0;
        else
          --Render::gVolumetricEffectManager.mVolumes.size;
      }
LABEL_13:
      v9 = *this->mOwnedVolumes.p;
      if ( v9 )
        operator delete[](v9);
      v10 = this->mOwnedVolumes.size;
      if ( v10 > 1 )
        *this->mOwnedVolumes.p = this->mOwnedVolumes.p[v10 - 1];
      v11 = this->mOwnedVolumes.size;
      if ( v11 <= 1 )
        break;
      v12 = v11 - 1;
      this->mOwnedVolumes.size = v12;
      if ( !v12 )
        goto LABEL_21;
    }
    this->mOwnedVolumes.size = 0;
  }
LABEL_21:
  mStartTime = this->mStartTime;
  this->mTotalEmitted = 0;
  this->mFirstFrameAfterActivateOrLoop = 1;
  this->mActivateTime = mStartTime;
}

