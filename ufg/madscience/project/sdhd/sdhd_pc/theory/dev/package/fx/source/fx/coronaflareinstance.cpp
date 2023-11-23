// File Line: 15
// RVA: 0x1CD770
void __fastcall Render::CoronaFlareInstance::Init(Render::CoronaFlareInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mCoronaFlare.mSettings.mData == 0i64;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    Inventory = `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xB76CCFB8);
      `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mCoronaFlare.mSettings, Inventory);
  }
  v7 = `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0xB76CCFB8);
    `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result = v7;
  }
  UFG::qResourceHandle::Init(&this->mCoronaFlare.mSettings, 0xB76CCFB8, settingsId, v7);
}

// File Line: 24
// RVA: 0x1C55C0
void __fastcall Render::CoronaFlareInstance::Activate(Render::CoronaFlareInstance *this)
{
  if ( !this->mIsActive )
  {
    *(_WORD *)&this->mIsActive = 1;
    Render::CoronaFlareManager::AddCoronaFlare(&Render::gCoronaFlareManager, &this->mCoronaFlare);
  }
}

// File Line: 36
// RVA: 0x1CA8C0
void __fastcall Render::CoronaFlareInstance::Deactivate(Render::CoronaFlareInstance *this, bool willLoopImmediately)
{
  bool v2; // zf
  __int64 v3; // rdx
  Render::CoronaFlare *p_mCoronaFlare; // rcx
  Render::CoronaFlare **i; // rax

  if ( this->mIsActive )
  {
    v2 = !this->mIsSuspended;
    this->mIsActive = 0;
    if ( v2 )
    {
      v3 = 0i64;
      if ( unk_142365D40 )
      {
        p_mCoronaFlare = &this->mCoronaFlare;
        for ( i = (Render::CoronaFlare **)qword_142365D48; *i != p_mCoronaFlare; ++i )
        {
          v3 = (unsigned int)(v3 + 1);
          if ( (unsigned int)v3 >= unk_142365D40 )
            return;
        }
        if ( unk_142365D40 <= 1u
          || (*((_QWORD *)qword_142365D48 + v3) = *((_QWORD *)qword_142365D48 + (unsigned int)(unk_142365D40 - 1)),
              unk_142365D40 <= 1u) )
        {
          unk_142365D40 = 0;
        }
        else
        {
          --unk_142365D40;
        }
      }
    }
    else
    {
      this->mIsSuspended = 0;
    }
  }
}

// File Line: 54
// RVA: 0x1D5D60
void __fastcall Render::CoronaFlareInstance::Resume(Render::CoronaFlareInstance *this, float sim_time)
{
  if ( this->mIsSuspended )
  {
    Render::CoronaFlareManager::AddCoronaFlare(&Render::gCoronaFlareManager, &this->mCoronaFlare);
    this->mIsSuspended = 0;
  }
}

// File Line: 63
// RVA: 0x1D8490
void __fastcall Render::CoronaFlareInstance::Suspend(Render::CoronaFlareInstance *this, float sim_time)
{
  __int64 v2; // rdx
  Render::CoronaFlareInstance **i; // rax

  if ( !this->mIsSuspended )
  {
    v2 = 0i64;
    if ( unk_142365D40 )
    {
      for ( i = (Render::CoronaFlareInstance **)qword_142365D48;
            *i != (Render::CoronaFlareInstance *)&this->mCoronaFlare;
            ++i )
      {
        v2 = (unsigned int)(v2 + 1);
        if ( (unsigned int)v2 >= unk_142365D40 )
        {
          this->mIsSuspended = 1;
          return;
        }
      }
      if ( unk_142365D40 > 1u )
      {
        *((_QWORD *)qword_142365D48 + v2) = *((_QWORD *)qword_142365D48 + (unsigned int)(unk_142365D40 - 1));
        if ( unk_142365D40 > 1u )
        {
          --unk_142365D40;
          this->mIsSuspended = 1;
          return;
        }
      }
      unk_142365D40 = 0;
    }
    this->mIsSuspended = 1;
  }
}

// File Line: 72
// RVA: 0x1D8BB0
void __fastcall Render::CoronaFlareInstance::Update(
        Render::CoronaFlareInstance *this,
        UFG::qVector3 *cam_pos,
        float delta_sec)
{
  Render::FXComponentInstance::GetBasis(this, &this->mCoronaFlare.mTransform);
}

