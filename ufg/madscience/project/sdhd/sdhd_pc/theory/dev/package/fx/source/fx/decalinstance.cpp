// File Line: 13
// RVA: 0x1C0F90
void __fastcall Render::DecalInstance::DecalInstance(Render::DecalInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::DecalInstance::`vftable;
  this->mActivateTime = 0.0;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  this->mTotalEmitted = 0;
}

// File Line: 18
// RVA: 0x1CDEE0
void __fastcall Render::DecalInstance::Init(Render::DecalInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  Inventory = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xAE323146, settingsId, Inventory);
}

// File Line: 24
// RVA: 0x1D7240
void __fastcall Render::DecalInstance::SpawnDecals(Render::DecalInstance *this, unsigned int numDecals)
{
  __int64 v2; // rsi
  float *mData; // r14
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rdi
  UFG::qMatrix44 *p_mBasis; // rdx
  __int64 v8; // rdi
  float x; // xmm14_4
  float w; // xmm15_4
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm3_4
  UFG::qVector3 rayStart; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector3 vDirectionUnNormalized; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 vNormal; // [rsp+50h] [rbp-98h] BYREF
  UFG::qVector3 rayEnd; // [rsp+5Ch] [rbp-8Ch] BYREF
  float v21; // [rsp+68h] [rbp-80h]
  float v22; // [rsp+6Ch] [rbp-7Ch]
  UFG::qMatrix44 dst; // [rsp+70h] [rbp-78h] BYREF
  char v24; // [rsp+C8h] [rbp-20h]
  int v25; // [rsp+CCh] [rbp-1Ch]
  __int64 v26; // [rsp+D0h] [rbp-18h]
  int v27; // [rsp+E8h] [rbp+0h]
  int v28; // [rsp+ECh] [rbp+4h]
  int v29; // [rsp+F8h] [rbp+10h]
  int v30; // [rsp+118h] [rbp+30h]
  __int64 v31; // [rsp+128h] [rbp+40h]
  const char *v32; // [rsp+138h] [rbp+50h]
  int v33; // [rsp+140h] [rbp+58h]
  UFG::qVector3 vPos; // [rsp+144h] [rbp+5Ch] BYREF
  int v35; // [rsp+150h] [rbp+68h]
  int v36; // [rsp+154h] [rbp+6Ch]
  int v37; // [rsp+158h] [rbp+70h]

  *(_QWORD *)&dst.v2.z = -2i64;
  v2 = numDecals;
  mData = (float *)this->mSettingsHandle.mData;
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
    rayStart = *(UFG::qVector3 *)&dst.v1.z;
    if ( (_DWORD)v2 )
    {
      v8 = v2;
      x = dst.v1.x;
      w = dst.v0.w;
      do
      {
        v11 = mData[44];
        v12 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(mData[47] - v11)) + v11;
        v13 = mData[43];
        v14 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(mData[46] - v13)) + v13;
        v15 = mData[42];
        v16 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(mData[45] - v15)) + v15;
        vDirectionUnNormalized.x = (float)((float)(dst.v0.x * v16) + (float)(v21 * v14)) + (float)(dst.v0.z * v12);
        vDirectionUnNormalized.y = (float)((float)(dst.v0.y * v16) + (float)(v22 * v14)) + (float)(w * v12);
        vDirectionUnNormalized.z = (float)((float)(dst.v0.z * v16) + (float)(dst.v0.x * v14)) + (float)(x * v12);
        rayEnd.x = rayStart.x + vDirectionUnNormalized.x;
        rayEnd.y = rayStart.y + vDirectionUnNormalized.y;
        rayEnd.z = rayStart.z + vDirectionUnNormalized.z;
        v24 = 0;
        v25 = 0;
        v26 = 0i64;
        v27 = 1065353216;
        v28 = -1;
        v30 = 0;
        v29 = -1;
        v31 = 0i64;
        v32 = "SpawnDecals";
        v33 = -1;
        UFG::RayCastData::Init((UFG::RayCastData *)&dst.v3.z, &rayStart, &rayEnd, 9u);
        if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, (UFG::RayCastData *)&dst.v3.z) )
        {
          LODWORD(vNormal.x) = v35 ^ _xmm[0];
          LODWORD(vNormal.y) = v36 ^ _xmm[0];
          LODWORD(vNormal.z) = v37 ^ _xmm[0];
          Render::DecalManager::CreateDecal(&Render::gDecalManager, this->mSettingsId, &vPos, &vNormal);
        }
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 72
// RVA: 0x1C55E0
void __fastcall Render::DecalInstance::Activate(Render::DecalInstance *this)
{
  UFG::qResourceData *mData; // rax
  float mStartTime; // eax

  if ( !this->mIsActive )
  {
    mData = this->mSettingsHandle.mData;
    if ( mData )
    {
      this->mIsActive = 1;
      Render::DecalInstance::SpawnDecals(this, *(_DWORD *)mData[1].mDebugName);
      mStartTime = this->mStartTime;
      this->mIsActive = 1;
      this->mActivateTime = mStartTime;
      this->mTotalEmitted = 0;
    }
  }
}

// File Line: 92
// RVA: 0x1CA940
void __fastcall Render::ScreenParticleEmitterInstance::Deactivate(
        Render::ScreenParticleEmitterInstance *this,
        bool willLoopImmediately)
{
  this->mIsActive = 0;
}

// File Line: 97
// RVA: 0x1D17B0
void __fastcall Render::DecalInstance::Loop(Render::DecalInstance *this)
{
  UFG::qResourceData *mData; // rax

  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    if ( *(_DWORD *)&mData[1].mDebugName[8] )
      Render::DecalInstance::SpawnDecals(this, *(_DWORD *)mData[1].mDebugName);
  }
}

// File Line: 110
// RVA: 0x1D8BC0
void __fastcall Render::DecalInstance::Update(Render::DecalInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  UFG::qResourceData *mData; // rax
  float v5; // xmm1_4
  int v6; // edi
  unsigned int v7; // edi

  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    v5 = *(float *)&mData[1].mDebugName[4];
    if ( v5 > 0.0 )
    {
      v6 = (int)(float)((float)(sim_time - this->mActivateTime) * v5);
      if ( this->mTotalEmitted > v6 )
      {
        v6 = 0;
        this->mActivateTime = sim_time;
        this->mTotalEmitted = 0;
      }
      v7 = v6 - this->mTotalEmitted;
      Render::DecalInstance::SpawnDecals(this, v7);
      this->mTotalEmitted += v7;
    }
  }
}

