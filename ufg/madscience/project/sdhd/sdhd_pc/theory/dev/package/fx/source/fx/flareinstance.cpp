// File Line: 15
// RVA: 0x1CE7D0
void __fastcall Render::FlareInstance::Init(Render::FlareInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mFlare.mSettings.mData == 0i64;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    Inventory = `UFG::qGetResourceInventory<Render::FlareSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FlareSettings>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA6535FBB);
      `UFG::qGetResourceInventory<Render::FlareSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mFlare.mSettings, Inventory);
  }
  v7 = `UFG::qGetResourceInventory<Render::FlareSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FlareSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0xA6535FBB);
    `UFG::qGetResourceInventory<Render::FlareSettings>::`2::result = v7;
  }
  UFG::qResourceHandle::Init(&this->mFlare.mSettings, 0xA6535FBB, settingsId, v7);
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
    v2 = !this->mIsSuspended;
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
  float mStartTime; // xmm3_4
  float v5; // xmm1_4

  mStartTime = this->mStartTime;
  v5 = this->mEndTime - mStartTime;
  if ( v5 > 0.0 )
    this->mFlare.mLifeTime = (float)(delta_sec - mStartTime) / v5;
  Render::FXComponentInstance::GetBasis(this, &this->mFlare.mTransform);
  this->mFlare.mSplitScreenViewMask = this->mContainer->mSplitScreenViewMask;
}

