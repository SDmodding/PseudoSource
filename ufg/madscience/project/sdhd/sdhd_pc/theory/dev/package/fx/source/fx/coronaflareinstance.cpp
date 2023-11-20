// File Line: 15
// RVA: 0x1CD770
void __fastcall Render::CoronaFlareInstance::Init(Render::CoronaFlareInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  unsigned int v3; // edi
  Render::CoronaFlareInstance *v4; // rbx
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mCoronaFlare.mSettings.mData == 0i64;
  v3 = settingsId;
  v4 = this;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    v5 = `UFG::qGetResourceInventory<Render::CoronaFlareSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::CoronaFlareSettings>'::`2'::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xB76CCFB8);
      `UFG::qGetResourceInventory<Render::CoronaFlareSettings>'::`2'::result = v5;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v4->mCoronaFlare.mSettings.mPrev, v5);
  }
  v7 = `UFG::qGetResourceInventory<Render::CoronaFlareSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::CoronaFlareSettings>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0xB76CCFB8);
    `UFG::qGetResourceInventory<Render::CoronaFlareSettings>'::`2'::result = v7;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mCoronaFlare.mSettings.mPrev, 0xB76CCFB8, v3, v7);
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
  Render::CoronaFlare *v4; // rcx
  char **v5; // rax

  if ( this->mIsActive )
  {
    v2 = this->mIsSuspended == 0;
    this->mIsActive = 0;
    if ( v2 )
    {
      v3 = 0i64;
      if ( unk_142365D40 )
      {
        v4 = &this->mCoronaFlare;
        v5 = (char **)qword_142365D48;
        while ( *v5 != (char *)v4 )
        {
          v3 = (unsigned int)(v3 + 1);
          ++v5;
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
  Render::CoronaFlareInstance *v2; // rbx

  v2 = this;
  if ( this->mIsSuspended )
  {
    Render::CoronaFlareManager::AddCoronaFlare(&Render::gCoronaFlareManager, &this->mCoronaFlare);
    v2->mIsSuspended = 0;
  }
}

// File Line: 63
// RVA: 0x1D8490
void __fastcall Render::CoronaFlareInstance::Suspend(Render::CoronaFlareInstance *this, float sim_time)
{
  __int64 v2; // rdx
  Render::CoronaFlareInstance **v3; // rax

  if ( !this->mIsSuspended )
  {
    v2 = 0i64;
    if ( unk_142365D40 )
    {
      v3 = (Render::CoronaFlareInstance **)qword_142365D48;
      while ( *v3 != (Render::CoronaFlareInstance *)&this->mCoronaFlare )
      {
        v2 = (unsigned int)(v2 + 1);
        ++v3;
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
void __fastcall Render::CoronaFlareInstance::Update(Render::CoronaFlareInstance *this, UFG::qVector3 *cam_pos, float delta_sec)
{
  Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&this->vfptr, &this->mCoronaFlare.mTransform);
}

