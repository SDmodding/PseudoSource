// File Line: 38
// RVA: 0x614250
void __fastcall UFG::UIHKHeatLevelWidget::Update(UFG::UIHKHeatLevelWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKHeatLevelWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // r15
  bool v4; // di
  char v5; // si
  char v6; // r14
  bool v7; // r12
  int v8; // eax
  UFG::CopSystem *v9; // rax
  int v10; // edx
  bool v11; // di
  bool v12; // sf
  unsigned __int8 v13; // of
  char v14; // al
  UFG::CopSystem *v15; // rax
  bool v16; // di
  double v17; // xmm6_8
  bool v18; // bl
  UFG::HudAudio *v19; // rcx
  Scaleform::GFx::Value value; // [rsp+18h] [rbp-39h]
  char v21; // [rsp+48h] [rbp-9h]
  __int64 v22; // [rsp+58h] [rbp+7h]
  unsigned int v23; // [rsp+60h] [rbp+Fh]
  __int64 v24; // [rsp+68h] [rbp+17h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      v4 = this->mVisibleChanged;
      v5 = 0;
      v6 = 0;
      if ( v4 )
      {
        this->mVisibleChanged = 0;
        value.pObjectInterface = 0i64;
        value.Type = 0;
        v7 = this->mVisible;
        value.Type = 2;
        value.mValue.BValue = v7;
        Scaleform::GFx::Movie::SetVariable(v3, "mcHeatMeter._visible", &value, 1i64);
        Scaleform::GFx::Movie::SetVariable(v3, "mc_MinimapPulse._visible", &value, 1i64);
        if ( ((unsigned int)value.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = 0;
      }
      if ( v2->mVisible )
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
        v10 = v2->mHeatLevel;
        v11 = v2->mHeatLevel != v8 || v4;
        v13 = __OFSUB__(v8, v2->mHeatLevel);
        v12 = v8 - v2->mHeatLevel < 0;
        if ( v8 > v2->mHeatLevel )
        {
          if ( v8 >= 0 )
          {
            v5 = 0;
            if ( v10 >= 0 )
              v5 = 1;
          }
          v13 = __OFSUB__(v8, v10);
          v12 = v8 - v10 < 0;
        }
        if ( v12 ^ v13 )
        {
          if ( v8 >= 0 )
          {
            v6 = 0;
            if ( v10 >= 0 )
              v6 = 1;
          }
        }
        v2->mHeatLevel = v8;
        if ( UFG::gUITweakUseFakeCopCooldown )
        {
          v14 = UFG::gUITweakFakeCopCooldownValue;
        }
        else
        {
          v15 = UFG::CopSystem::Instance();
          v14 = ((__int64 (__fastcall *)(UFG::CopSystem *))v15->vfptr[8].__vecDelDtor)(v15);
        }
        v16 = v2->mCopCooldown != v14 || v11;
        v2->mCopCooldown = v14;
        if ( v16 )
        {
          value.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
          `eh vector constructor iterator(
            &value,
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v17 = (double)v2->mHeatLevel;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v17;
          v18 = v2->mCopCooldown;
          if ( (v23 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, &v21, v24);
            v22 = 0i64;
          }
          v23 = 2;
          LOBYTE(v24) = v18;
          Scaleform::GFx::Movie::Invoke(v3, "Cops_SetHeatLevel", 0i64, &value, 2u);
          `eh vector destructor iterator(
            &value,
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        }
        v19 = UFG::HudAudio::m_instance;
        if ( v5 && UFG::HudAudio::m_instance )
        {
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0x2AF52CB4u,
            0i64,
            0,
            0i64);
          v19 = UFG::HudAudio::m_instance;
        }
        if ( v6 )
        {
          if ( v19 )
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v19->vfptr, 0x2AF52CB4u, 0i64, 0, 0i64);
        }
      }
    }
  }
}

