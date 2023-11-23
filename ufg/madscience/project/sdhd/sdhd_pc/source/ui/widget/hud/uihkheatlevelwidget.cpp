// File Line: 38
// RVA: 0x614250
void __fastcall UFG::UIHKHeatLevelWidget::Update(UFG::UIHKHeatLevelWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // r15
  bool mVisibleChanged; // di
  bool v5; // si
  bool v6; // r14
  bool mVisible; // r12
  int v8; // eax
  UFG::CopSystem *v9; // rax
  int mHeatLevel; // edx
  bool v11; // di
  bool v12; // cc
  char v13; // al
  UFG::CopSystem *v14; // rax
  bool v15; // di
  Scaleform::GFx::Value::ValueUnion v16; // xmm6_8
  bool mCopCooldown; // bl
  UFG::HudAudio *v18; // rcx
  Scaleform::GFx::Value value; // [rsp+18h] [rbp-39h] BYREF
  char v20[16]; // [rsp+48h] [rbp-9h] BYREF
  __int64 v21; // [rsp+58h] [rbp+7h]
  int v22; // [rsp+60h] [rbp+Fh]
  __int64 v23; // [rsp+68h] [rbp+17h]

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      mVisibleChanged = this->mVisibleChanged;
      v5 = 0;
      v6 = 0;
      if ( mVisibleChanged )
      {
        this->mVisibleChanged = 0;
        value.pObjectInterface = 0i64;
        value.Type = VT_Undefined;
        mVisible = this->mVisible;
        value.Type = VT_Boolean;
        value.mValue.BValue = mVisible;
        Scaleform::GFx::Movie::SetVariable(pObject, "mcHeatMeter._visible", &value, 1i64);
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_MinimapPulse._visible", &value, 1i64);
        if ( (value.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = VT_Undefined;
      }
      if ( this->mVisible )
      {
        if ( UFG::gUITweakUseFakeCopHeatLevel )
        {
          v8 = UFG::gUITweakFakeCopHeatLevelValue;
        }
        else
        {
          v9 = UFG::CopSystem::Instance();
          v8 = ((__int64 (__fastcall *)(UFG::CopSystem *))v9->vfptr[89].__vecDelDtor)(v9);
        }
        mHeatLevel = this->mHeatLevel;
        v11 = this->mHeatLevel != v8 || mVisibleChanged;
        v12 = v8 < this->mHeatLevel;
        if ( v8 > this->mHeatLevel )
        {
          if ( v8 >= 0 )
            v5 = mHeatLevel >= 0;
          v12 = v8 < mHeatLevel;
        }
        if ( v12 && v8 >= 0 )
          v6 = mHeatLevel >= 0;
        this->mHeatLevel = v8;
        if ( UFG::gUITweakUseFakeCopCooldown )
        {
          v13 = UFG::gUITweakFakeCopCooldownValue;
        }
        else
        {
          v14 = UFG::CopSystem::Instance();
          v13 = ((__int64 (__fastcall *)(UFG::CopSystem *))v14->vfptr[8].__vecDelDtor)(v14);
        }
        v15 = this->mCopCooldown != v13 || v11;
        this->mCopCooldown = v13;
        if ( v15 )
        {
          value.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
          `eh vector constructor iterator(
            &value,
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v16.NValue = (double)this->mHeatLevel;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v16;
          mCopCooldown = this->mCopCooldown;
          if ( (v22 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, v20, v23);
            v21 = 0i64;
          }
          v22 = 2;
          LOBYTE(v23) = mCopCooldown;
          Scaleform::GFx::Movie::Invoke(pObject, "Cops_SetHeatLevel", 0i64, &value, 2u);
          `eh vector destructor iterator(
            &value,
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        }
        v18 = UFG::HudAudio::m_instance;
        if ( v5 && UFG::HudAudio::m_instance )
        {
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x2AF52CB4u, 0i64, 0, 0i64);
          v18 = UFG::HudAudio::m_instance;
        }
        if ( v6 )
        {
          if ( v18 )
            UFG::AudioEntity::CreateAndPlayEvent(v18, 0x2AF52CB4u, 0i64, 0, 0i64);
        }
      }
    }
  }
}

