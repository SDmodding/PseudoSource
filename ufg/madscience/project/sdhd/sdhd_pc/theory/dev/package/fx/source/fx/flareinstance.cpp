// File Line: 15
// RVA: 0x1CE7D0
void __fastcall Render::FlareInstance::Init(Render::FlareInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  unsigned int v3; // edi
  Render::FlareInstance *v4; // rbx
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mFlare.mSettings.mData == 0i64;
  v3 = settingsId;
  v4 = this;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    v5 = `UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA6535FBB);
      `UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result = v5;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v4->mFlare.mSettings.mPrev, v5);
  }
  v7 = `UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0xA6535FBB);
    `UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result = v7;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mFlare.mSettings.mPrev, 0xA6535FBB, v3, v7);
}

// File Line: 24
// RVA: 0x1C58E0
void __fastcall Render::FlareInstance::Activate(Render::FlareInstance *this)
{
  if ( !this->mIsActive )
  {
    *(_WORD *)&this->mIsActive = 1;
    Render::FlareManager::AddFlare(&Render::gFlareManager, &this->mFlare);
  }
}

// File Line: 36
// RVA: 0x1CAB30
void __fastcall Render::FlareInstance::Deactivate(Render::FlareInstance *this, bool willLoopImmediately)
{
  bool v2; // zf

  if ( this->mIsActive )
  {
    v2 = this->mIsSuspended == 0;
    this->mIsActive = 0;
    if ( v2 )
      Render::FlareManager::RemoveFlare(&Render::gFlareManager, &this->mFlare);
    else
      this->mIsSuspended = 0;
  }
}

// File Line: 76
// RVA: 0x1D9740
void __fastcall Render::FlareInstance::Update(Render::FlareInstance *this, UFG::qVector3 *cam_pos, float delta_sec)
{
  float v3; // xmm3_4
  Render::FlareInstance *v4; // rbx
  float v5; // xmm1_4

  v3 = this->mStartTime;
  v4 = this;
  v5 = this->mEndTime - v3;
  if ( v5 > 0.0 )
    this->mFlare.mLifeTime = (float)(delta_sec - v3) / v5;
  Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&this->vfptr, &this->mFlare.mTransform);
  v4->mFlare.mSplitScreenViewMask = v4->mContainer->mSplitScreenViewMask;
}

