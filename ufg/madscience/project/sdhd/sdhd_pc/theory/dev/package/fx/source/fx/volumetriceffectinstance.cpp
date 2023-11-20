// File Line: 26
// RVA: 0x1C1FA0
void __fastcall Render::VolumetricEffectInstance::VolumetricEffectInstance(Render::VolumetricEffectInstance *this)
{
  Render::VolumetricEffectInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::VolumetricEffectInstance::`vftable';
  this->mOwnedVolumes.p = 0i64;
  *(_QWORD *)&this->mOwnedVolumes.size = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  *(_QWORD *)&v1->mActivateTime = 0i64;
  v1->mFirstFrameAfterActivateOrLoop = 0;
}

// File Line: 30
// RVA: 0x1C4960
void __fastcall Render::VolumetricEffectInstance::~VolumetricEffectInstance(Render::VolumetricEffectInstance *this)
{
  Render::VolumetricEffectInstance *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  Render::VolumetricEffect **v4; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::VolumetricEffectInstance::`vftable';
  Render::VolumetricEffectInstance::Deactivate(this, 0);
  v2 = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xE4B8F46A);
    `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v4 = v1->mOwnedVolumes.p;
  if ( v4 )
    operator delete[](v4);
  v1->mOwnedVolumes.p = 0i64;
  *(_QWORD *)&v1->mOwnedVolumes.size = 0i64;
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  v5 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 35
// RVA: 0x1CFF50
void __fastcall Render::VolumetricEffectInstance::Init(Render::VolumetricEffectInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  Render::VolumetricEffectInstance *v3; // rbx
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
    v4 = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0xE4B8F46A);
      `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, v4);
  }
  v6 = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result;
  v7 = v3->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xE4B8F46A);
    `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0xE4B8F46A, v7, v6);
}

// File Line: 51
// RVA: 0x1C63C0
void __fastcall Render::VolumetricEffectInstance::Activate(Render::VolumetricEffectInstance *this)
{
  float v1; // eax

  if ( !this->mIsActive )
  {
    v1 = this->mStartTime;
    *(_WORD *)&this->mIsActive = 1;
    *(_QWORD *)&this->mActivateTime = LODWORD(v1);
    this->mFirstFrameAfterActivateOrLoop = 1;
  }
}

// File Line: 94
// RVA: 0x1CAD10
void __fastcall Render::VolumetricEffectInstance::Deactivate(Render::VolumetricEffectInstance *this, bool willLoopImmediately)
{
  Render::VolumetricEffectInstance *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  Render::VolumetricEffect *v5; // rcx
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // eax

  v2 = this;
  if ( this->mIsActive && !willLoopImmediately )
  {
    this->mIsActive = 0;
    v3 = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xE4B8F46A);
      `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result = v3;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mSettingsHandle.mPrev, v3);
    if ( v2->mIsSuspended )
    {
      v2->mIsSuspended = 0;
    }
    else if ( v2->mOwnedVolumes.size )
    {
      while ( 1 )
      {
        Render::VolumetricEffectManager::RemoveVolume(&Render::gVolumetricEffectManager, *v2->mOwnedVolumes.p);
        v5 = *v2->mOwnedVolumes.p;
        if ( v5 )
          operator delete[](v5);
        v6 = v2->mOwnedVolumes.size;
        if ( v6 > 1 )
          *v2->mOwnedVolumes.p = v2->mOwnedVolumes.p[v6 - 1];
        v7 = v2->mOwnedVolumes.size;
        if ( v7 <= 1 )
          break;
        v8 = v7 - 1;
        v2->mOwnedVolumes.size = v8;
        if ( !v8 )
          return;
      }
      v2->mOwnedVolumes.size = 0;
    }
  }
}

// File Line: 148
// RVA: 0x1DB070
void __fastcall Render::VolumetricEffectInstance::Update(Render::VolumetricEffectInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  UFG::qVector3 *v3; // r14
  Render::VolumetricEffectInstance *v4; // rbx
  UFG::qResourceInventory *v5; // rax
  unsigned int v6; // edi
  UFG::qResourceWarehouse *v7; // rax
  Render::VolumetricEffectSettings *v8; // rbp
  unsigned int i; // edi
  Render::VolumetricEffect *v10; // rdx
  Render::VolumetricEffect *v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // eax

  v3 = cam_pos;
  v4 = this;
  if ( !this->mSettingsHandle.mData )
  {
    v5 = `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result;
    v6 = this->mSettingsId;
    if ( !`UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v7, 0xE4B8F46A);
      `UFG::qGetResourceInventory<Render::VolumetricEffectSettings>'::`2'::result = v5;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mSettingsHandle.mPrev, 0xE4B8F46A, v6, v5);
    *(_QWORD *)&v4->mActivateTime = LODWORD(sim_time);
  }
  v8 = (Render::VolumetricEffectSettings *)v4->mSettingsHandle.mData;
  if ( v8 )
  {
    for ( i = 0; i < v4->mOwnedVolumes.size; ++i )
    {
      Render::VolumetricEffectInstance::UpdateVolume(v4, v3, v8, v4->mOwnedVolumes.p[i], sim_time);
      v10 = v4->mOwnedVolumes.p[i];
      if ( (float)(v10->fEndTime - v10->fStartTime) > 0.0 && sim_time > v10->fEndTime )
      {
        Render::VolumetricEffectManager::RemoveVolume(&Render::gVolumetricEffectManager, v10);
        v11 = v4->mOwnedVolumes.p[i];
        if ( v11 )
          operator delete[](v11);
        v12 = v4->mOwnedVolumes.size;
        if ( v12 > 1 )
          v4->mOwnedVolumes.p[i] = v4->mOwnedVolumes.p[v12 - 1];
        v13 = v4->mOwnedVolumes.size;
        if ( v13 > 1 )
          v4->mOwnedVolumes.size = v13 - 1;
        else
          v4->mOwnedVolumes.size = 0;
        --i;
      }
    }
    if ( v8->mEmissionRate > 0.0 || v4->mFirstFrameAfterActivateOrLoop )
      Render::VolumetricEffectInstance::UpdateTimeEmission(v4, v3, v8, sim_time, v8->mEmissionRate);
  }
}

// File Line: 196
// RVA: 0x1DC920
void __fastcall Render::VolumetricEffectInstance::UpdateVolume(Render::VolumetricEffectInstance *this, UFG::qVector3 *cam_pos, Render::VolumetricEffectSettings *lfx, Render::VolumetricEffect *volume, float sim_time)
{
  float v5; // xmm1_4
  Render::VolumetricEffect *v6; // rdi
  Render::VolumetricEffectSettings *v7; // rbx
  UFG::qVector3 *v8; // r14
  Render::VolumetricEffectInstance *v9; // rsi
  float v10; // xmm0_4
  float lifetime; // xmm7_4
  Render::FXInstance *v12; // rax
  UFG::SimComponent *v13; // rbp
  UFG::qMatrix44 *v14; // rdx
  float v15; // xmm12_4
  float v16; // xmm13_4
  float v17; // xmm14_4
  float v18; // xmm9_4
  float v19; // xmm6_4
  float v20; // xmm8_4
  float v21; // xmm10_4
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
  float v33; // xmm2_4
  UFG::qVector4 result; // [rsp+30h] [rbp-E8h]
  UFG::qMatrix44 dst; // [rsp+40h] [rbp-D8h]
  float sim_timea; // [rsp+140h] [rbp+28h]

  v5 = this->mStartTime;
  v6 = volume;
  v7 = lfx;
  v8 = cam_pos;
  v9 = this;
  v10 = this->mEndTime - v5;
  if ( v10 <= 0.0 )
    lifetime = FLOAT_N1_0;
  else
    lifetime = (float)(sim_time - v5) / v10;
  v12 = this->mContainer;
  v13 = v12->mParentNode.m_pPointer;
  if ( !v13 || v12->mBasisRelativeToParent )
  {
    v14 = &v12->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12->mParentNode.m_pPointer);
    v14 = (UFG::qMatrix44 *)&v13[2];
  }
  Render::FXInstance::CalcBasisHelper(
    &dst,
    v14,
    (UFG::qResourceHandle *)&v9->mContainer->mSettings.mPrev,
    v9->mComponentIndex,
    v9->mStartTime);
  v15 = dst.v3.x;
  v16 = dst.v3.y;
  v17 = dst.v3.z;
  v18 = v6->vCurrPos.x - dst.v3.x;
  v19 = v6->vCurrPos.y - dst.v3.y;
  v20 = v6->vCurrPos.z - dst.v3.z;
  UFG::qHalfVector4::operator UFG::qVector4 const(&v6->vVelAndDamp, &result);
  v21 = UFG::Metrics::msInstance.mSimTimeDelta;
  v22 = result.x;
  v23 = v19 + (float)(result.y * UFG::Metrics::msInstance.mSimTimeDelta);
  v24 = v18 + (float)(result.x * UFG::Metrics::msInstance.mSimTimeDelta);
  v25 = v20 + (float)(result.z * UFG::Metrics::msInstance.mSimTimeDelta);
  if ( v24 >= v7->mWrapRegionMin.x )
  {
    if ( v24 > v7->mWrapRegionMax.x )
      v24 = v7->mWrapRegionMin.x;
  }
  else
  {
    v24 = v7->mWrapRegionMax.x;
  }
  if ( v23 >= v7->mWrapRegionMin.y )
  {
    if ( v23 > v7->mWrapRegionMax.y )
      v23 = v7->mWrapRegionMin.y;
  }
  else
  {
    v23 = v7->mWrapRegionMax.y;
  }
  if ( v25 >= v7->mWrapRegionMin.z )
  {
    if ( v25 > v7->mWrapRegionMax.z )
      v25 = v7->mWrapRegionMin.z;
  }
  else
  {
    v25 = v7->mWrapRegionMax.z;
  }
  v26 = UFG::Metrics::msInstance.mSimTimeDelta * 0.0;
  v6->vCurrPos.x = v15 + v24;
  v6->vCurrPos.y = v16 + v23;
  v27 = v26;
  v28 = (float)(v21 * 0.0) + result.y;
  v6->vCurrPos.z = v17 + v25;
  v29 = (float)(v6->vPosAndGrav.w * v21) + result.z;
  LODWORD(sim_timea) = (((((unsigned int)v6->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v6->vVelAndDamp.w.mRep & 0x3FF | 8 * (v6->vVelAndDamp.w.mRep & 0x8000)) << 13);
  result.x = (float)(v27 + v22) - (float)((float)((float)(v27 + v22) * v21) * sim_timea);
  result.y = v28 - (float)((float)(v28 * v21) * sim_timea);
  result.z = v29 - (float)((float)(v29 * v21) * sim_timea);
  Render::VolumetricEffect::SetVelocity(v6, (UFG::qVector3 *)&result);
  if ( lifetime > 0.0 )
  {
    v30 = Render::VolumetricEffectInstance::ComputeColor(v9, &result, v8, v7, v6, lifetime);
    v31 = v30->y;
    v32 = v30->z;
    v33 = v30->w;
    v6->fColour.x = v30->x;
    v6->fColour.y = v31;
    v6->fColour.z = v32;
    v6->fColour.w = v33;
  }
}

// File Line: 245
// RVA: 0x1CA660
UFG::qVector3 *__fastcall Render::CreateTimeUpdateJitterVector(UFG::qVector3 *result, Render::VolumetricEffectSettings *lfx, UFG::qMatrix44 *curBasis, float scale)
{
  Render::VolumetricEffectSettings *v4; // rbx
  UFG::qMatrix44 *v5; // rdi
  UFG::qVector3 *v6; // rsi
  float v7; // xmm9_4
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

  v4 = lfx;
  v5 = curBasis;
  v6 = result;
  v7 = scale;
  v8 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  v9 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  v10 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  v11 = v6;
  v12 = (float)((float)((float)(v4->mWrapRegionMax.y - v4->mWrapRegionMin.y) * v9) + v4->mWrapRegionMin.y) * scale;
  v13 = (float)(v4->mWrapRegionMin.x + (float)((float)(v4->mWrapRegionMax.x - v4->mWrapRegionMin.x) * v10)) * scale;
  v14 = (float)((float)(v13 * v5->v0.z) + v5->v3.z) + (float)(v12 * v5->v1.z);
  v15 = (float)((float)(v13 * v5->v0.x) + v5->v3.x) + (float)(v12 * v5->v1.x);
  v16 = (float)((float)(v13 * v5->v0.y) + v5->v3.y) + (float)(v12 * v5->v1.y);
  v17 = (float)((float)((float)(v4->mWrapRegionMax.z - v4->mWrapRegionMin.z) * v8) + v4->mWrapRegionMin.z) * v7;
  v18 = v17 * v5->v2.x;
  v19 = v17 * v5->v2.y;
  v6->z = v14 + (float)(v17 * v5->v2.z);
  v6->x = v15 + v18;
  v6->y = v16 + v19;
  return v11;
}

// File Line: 264
// RVA: 0x1DC240
void __fastcall Render::VolumetricEffectInstance::UpdateTimeEmission(Render::VolumetricEffectInstance *this, UFG::qVector3 *cam_pos, Render::VolumetricEffectSettings *lfx, float sim_time, float emissionRate)
{
  float v5; // xmm13_4
  Render::VolumetricEffectSettings *v6; // r13
  Render::VolumetricEffectInstance *v7; // rdi
  float v8; // xmm1_4
  int v9; // er12
  unsigned int v10; // er12
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbp
  Render::FXInstance *v13; // rax
  UFG::qMatrix44 *v14; // rbx
  UFG::qMatrix44 *v15; // rdx
  float v16; // xmm6_4
  unsigned int v17; // ebx
  UFG::qVector3 *v18; // rax
  float v19; // xmm8_4
  float v20; // xmm11_4
  float v21; // xmm12_4
  float v22; // xmm5_4
  int v23; // edx
  unsigned int v24; // er8
  float *v25; // rcx
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm8_4
  UFG::qVector3 *v32; // rax
  float v33; // xmm7_4
  float v34; // xmm8_4
  float v35; // ST34_4
  float v36; // ST38_4
  float v37; // xmm6_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  float v40; // xmm0_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  UFG::qVector4 *v43; // rax
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  __int64 v47; // r15
  unsigned int v48; // esi
  unsigned int v49; // ebx
  unsigned int v50; // ebx
  unsigned __int64 v51; // rax
  UFG::allocator::free_link *v52; // rax
  Render::VolumetricEffect **v53; // r14
  __int64 v54; // r9
  UFG::qVector3 velocity; // [rsp+40h] [rbp-148h]
  UFG::qVector3 vVel; // [rsp+4Ch] [rbp-13Ch]
  UFG::allocator::free_link *v57; // [rsp+58h] [rbp-130h]
  __int64 v58; // [rsp+60h] [rbp-128h]
  UFG::qVector3 result; // [rsp+68h] [rbp-120h]
  UFG::qVector3 v60; // [rsp+74h] [rbp-114h]
  UFG::qVector4 v61; // [rsp+80h] [rbp-108h]
  UFG::qMatrix44 dst; // [rsp+90h] [rbp-F8h]
  __int64 v63; // [rsp+190h] [rbp+8h]
  UFG::qVector3 *cam_posa; // [rsp+198h] [rbp+10h]

  cam_posa = cam_pos;
  v58 = -2i64;
  v5 = sim_time;
  v6 = lfx;
  v7 = this;
  v8 = emissionRate;
  if ( emissionRate <= 0.0 )
    v8 = 0.0;
  v9 = (signed int)(float)((float)(sim_time - this->mActivateTime) * v8);
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
      v13 = v7->mContainer;
      v14 = (UFG::qMatrix44 *)v13->mParentNode.m_pPointer;
      if ( !v14 || v13->mBasisRelativeToParent )
      {
        v15 = &v13->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13->mParentNode.m_pPointer);
        v15 = v14 + 2;
      }
      Render::FXInstance::CalcBasisHelper(
        &dst,
        v15,
        (UFG::qResourceHandle *)&v7->mContainer->mSettings.mPrev,
        v7->mComponentIndex,
        v7->mStartTime);
      v16 = v6->mRadMin;
      *((float *)&v12[33].mNext + 1) = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(v6->mRadMax - v16)) + v16;
      v17 = 0;
      do
      {
        v18 = Render::CreateTimeUpdateJitterVector(&result, v6, &dst, 1.0);
        v19 = v18->x;
        v20 = v18->y;
        v21 = v18->z;
        v22 = 0.0;
        v23 = 0;
        v24 = v7->mOwnedVolumes.size;
        if ( !v24 )
          break;
        while ( 1 )
        {
          v25 = &v7->mOwnedVolumes.p[v23]->mTransform.v0.x;
          v26 = *((float *)&v12[33].mNext + 1) + v25[67];
          v27 = fsqrt(
                  (float)((float)((float)(v19 - v25[64]) * (float)(v19 - v25[64]))
                        + (float)((float)(v20 - v25[65]) * (float)(v20 - v25[65])))
                + (float)((float)(v21 - v25[66]) * (float)(v21 - v25[66])));
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
          if ( ++v23 >= v24 )
            goto LABEL_28;
        }
        ++v17;
      }
      while ( v17 < 0x1E );
LABEL_28:
      *(float *)&v12[34].mNext = v19;
      *((float *)&v12[34].mNext + 1) = v20;
      *(float *)&v12[35].mNext = v21;
      *(float *)&v12[32].mNext = v19;
      *((float *)&v12[32].mNext + 1) = v20;
      *(float *)&v12[33].mNext = v21;
      v29 = v6->mGlobalVelocityMax.x - v6->mGlobalVelocityMin.x;
      v30 = v6->mGlobalVelocityMax.y - v6->mGlobalVelocityMin.y;
      v31 = v6->mGlobalVelocityMax.z - v6->mGlobalVelocityMin.z;
      v32 = UFG::qRandom(&v60, &UFG::qVector3::msOne, &UFG::qDefaultSeed);
      v33 = v30 * v32->y;
      v34 = v31 * v32->z;
      velocity.x = (float)(v29 * v32->x) + v6->mGlobalVelocityMin.x;
      velocity.y = v33 + v6->mGlobalVelocityMin.y;
      velocity.z = v34 + v6->mGlobalVelocityMin.z;
      Render::VolumetricEffect::SetInitialVelocity((Render::VolumetricEffect *)v12, &velocity);
      LODWORD(v35) = (((((unsigned int)WORD1(v12[37].mNext) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((WORD1(v12[37].mNext) & 0x3FF | 8 * (WORD1(v12[37].mNext) & 0x8000)) << 13);
      LODWORD(v36) = (((((unsigned int)WORD2(v12[37].mNext) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((WORD2(v12[37].mNext) & 0x3FF | 8 * (WORD2(v12[37].mNext) & 0x8000)) << 13);
      LODWORD(vVel.x) = (((((unsigned int)LOWORD(v12[37].mNext) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | (((_QWORD)v12[37].mNext & 0x3FF | 8 * ((_QWORD)v12[37].mNext & 0x8000)) << 13);
      vVel.y = v35;
      vVel.z = v36;
      v37 = v6->mDragMin;
      v38 = v6->mGravityMin;
      v39 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(v6->mDragMax - v37)) + v37;
      v40 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
      Render::VolumetricEffect::SetVelocityGravityAndDrag(
        (Render::VolumetricEffect *)v12,
        &vVel,
        (float)(v40 * (float)(v6->mGravityMax - v38)) + v38,
        v39);
      v41 = v6->mLifeMin;
      v42 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(v6->mLifeMax - v41)) + (float)(v41 + v5);
      *(float *)&v12[38].mNext = v5;
      *((float *)&v12[38].mNext + 1) = v42;
      v43 = Render::VolumetricEffectInstance::ComputeColor(v7, &v61, cam_posa, v6, (Render::VolumetricEffect *)v12, 0.0);
      v44 = v43->y;
      v45 = v43->z;
      v46 = v43->w;
      *(float *)&v12[39].mNext = v43->x;
      *((float *)&v12[39].mNext + 1) = v44;
      *(float *)&v12[40].mNext = v45;
      *((float *)&v12[40].mNext + 1) = v46;
      *(float *)&v12[41].mNext = v6->mIntensity;
      HIDWORD(v12[41].mNext) = LODWORD(v6->mIntensity);
      *(float *)&v12[42].mNext = v6->mBentNormals;
      HIDWORD(v12[42].mNext) = LODWORD(v6->mLightingContribution);
      LOBYTE(v12[43].mNext) = v7->mContainer->mParentNode.m_pPointer == Render::gFXManager.mCamTransformNode.m_pPointer;
      v47 = v7->mOwnedVolumes.size;
      v48 = v47 + 1;
      v49 = v7->mOwnedVolumes.capacity;
      if ( (signed int)v47 + 1 > v49 )
      {
        if ( v49 )
          v50 = 2 * v49;
        else
          v50 = 1;
        for ( ; v50 < v48; v50 *= 2 )
          ;
        if ( v50 <= 2 )
          v50 = 2;
        if ( v50 - v48 > 0x10000 )
          v50 = v47 + 65537;
        if ( v50 != (_DWORD)v47 )
        {
          v51 = 8i64 * v50;
          if ( !is_mul_ok(v50, 8ui64) )
            v51 = -1i64;
          v52 = UFG::qMalloc(v51, "qArray.Add", 0i64);
          v53 = (Render::VolumetricEffect **)v52;
          if ( v7->mOwnedVolumes.p )
          {
            v54 = 0i64;
            if ( v7->mOwnedVolumes.size )
            {
              do
              {
                v52[v54] = (UFG::allocator::free_link)v7->mOwnedVolumes.p[v54];
                v54 = (unsigned int)(v54 + 1);
              }
              while ( (unsigned int)v54 < v7->mOwnedVolumes.size );
            }
            operator delete[](v7->mOwnedVolumes.p);
          }
          v7->mOwnedVolumes.p = v53;
          v7->mOwnedVolumes.capacity = v50;
        }
      }
      v7->mOwnedVolumes.size = v48;
      v7->mOwnedVolumes.p[v47] = (Render::VolumetricEffect *)v12;
      Render::VolumetricEffectManager::AddVolume(&Render::gVolumetricEffectManager, (Render::VolumetricEffect *)v12);
      --v63;
    }
    while ( v63 );
    v7->mTotalEmitted += v10;
  }
  else
  {
    this->mTotalEmitted = this->mTotalEmitted;
  }
}

// File Line: 339
// RVA: 0x1C8510
UFG::qVector4 *__fastcall Render::VolumetricEffectInstance::ComputeColor(Render::VolumetricEffectInstance *this, UFG::qVector4 *result, UFG::qVector3 *cam_pos, Render::VolumetricEffectSettings *lfx, Render::VolumetricEffect *volume, float lifetime)
{
  float v6; // xmm1_4
  UFG::qVector4 *v7; // r10
  float v8; // eax
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
  float *v19; // rcx
  __int64 v20; // rdx
  __m128 v21; // xmm2
  float *v22; // rax
  float v23; // xmm3_4
  float *v24; // r9
  float v25; // xmm2_4
  float v26; // xmm0_4

  v6 = lfx->mColorKeyPositions[0];
  v7 = result;
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
          v8 = lfx->mColorKeys[3].w;
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
  v8 = lfx->mColorKeys[0].w;
LABEL_11:
  result->w = v8;
LABEL_12:
  if ( lfx->mUseDistanceScale )
  {
    v19 = (float *)lfx->mDistanceScaleKeys;
    v20 = 0i64;
    v21 = (__m128)LODWORD(volume->vCurrPos.y);
    v22 = (float *)lfx->mDistanceScaleKeys;
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - cam_pos->y) * (float)(v21.m128_f32[0] - cam_pos->y))
                            + (float)((float)(volume->vCurrPos.x - cam_pos->x) * (float)(volume->vCurrPos.x - cam_pos->x)))
                    + (float)((float)(volume->vCurrPos.z - cam_pos->z) * (float)(volume->vCurrPos.z - cam_pos->z));
    LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v21);
    do
    {
      if ( v23 < *v22 )
        break;
      v20 = (unsigned int)(v20 + 1);
      v22 += 2;
    }
    while ( (unsigned int)v20 < 5 );
    if ( (_DWORD)v20 && (v19 = (float *)(&lfx->mNode.mParent + (unsigned int)(v20 - 1) + 34i64), (_DWORD)v20 == 5) )
      v24 = (float *)&lfx->mDistanceScaleKeys[4];
    else
      v24 = (float *)&lfx->mDistanceScaleKeys[v20];
    v25 = 0.0;
    v26 = *v19 - *v24;
    if ( v26 < 0.0 )
      LODWORD(v26) ^= _xmm[0];
    if ( v26 >= 0.001 )
      v25 = (float)(v23 - *v19) / (float)(*v24 - *v19);
    v7->w = (float)((float)((float)(v24[1] - v19[1]) * v25) + v19[1]) * v7->w;
  }
  return v7;
}

// File Line: 432
// RVA: 0x1C8320
void __fastcall Render::VolumetricEffectInstance::ChatlineLiveUpdate(Render::VolumetricEffectInstance *this)
{
  Render::VolumetricEffectInstance *v1; // rbx
  unsigned int v2; // edx
  Render::VolumetricEffect *v3; // rdi
  unsigned int v4; // eax
  Render::VolumetricEffect **v5; // r8
  Render::VolumetricEffect **v6; // rcx
  __int64 v7; // rsi
  CullManager *v8; // rax
  Render::VolumetricEffect *v9; // rcx
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  float v13; // eax

  v1 = this;
  if ( this->mOwnedVolumes.size )
  {
    while ( 1 )
    {
      v2 = Render::gVolumetricEffectManager.mVolumes.size;
      v3 = *v1->mOwnedVolumes.p;
      v4 = 0;
      if ( Render::gVolumetricEffectManager.mVolumes.size )
      {
        v5 = Render::gVolumetricEffectManager.mVolumes.p;
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
          v5 = Render::gVolumetricEffectManager.mVolumes.p;
          v2 = Render::gVolumetricEffectManager.mVolumes.size;
        }
        if ( v2 <= 1 || (v5[v7] = v5[v2 - 1], Render::gVolumetricEffectManager.mVolumes.size <= 1) )
          Render::gVolumetricEffectManager.mVolumes.size = 0;
        else
          --Render::gVolumetricEffectManager.mVolumes.size;
      }
LABEL_13:
      v9 = *v1->mOwnedVolumes.p;
      if ( v9 )
        operator delete[](v9);
      v10 = v1->mOwnedVolumes.size;
      if ( v10 > 1 )
        *v1->mOwnedVolumes.p = v1->mOwnedVolumes.p[v10 - 1];
      v11 = v1->mOwnedVolumes.size;
      if ( v11 <= 1 )
        break;
      v12 = v11 - 1;
      v1->mOwnedVolumes.size = v12;
      if ( !v12 )
        goto LABEL_21;
    }
    v1->mOwnedVolumes.size = 0;
  }
LABEL_21:
  v13 = v1->mStartTime;
  v1->mTotalEmitted = 0;
  v1->mFirstFrameAfterActivateOrLoop = 1;
  v1->mActivateTime = v13;
}

