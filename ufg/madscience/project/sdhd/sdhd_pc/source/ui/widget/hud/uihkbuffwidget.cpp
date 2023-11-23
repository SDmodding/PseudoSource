// File Line: 32
// RVA: 0x1566E20
__int64 dynamic_initializer_for__UFG::UIHKBuffWidget::mBuffData__()
{
  __int64 result; // rax

  result = 0i64;
  *(_QWORD *)&UFG::UIHKBuffWidget::mBuffData[0].mState = 0i64;
  qword_142432018 = 0i64;
  qword_142432020 = 0i64;
  qword_142432028 = 0i64;
  qword_142432030 = 0i64;
  qword_142432038 = 0i64;
  qword_142432040 = 0i64;
  qword_142432048 = 0i64;
  qword_142432050 = 0i64;
  qword_142432058 = 0i64;
  dword_142432060 = 0;
  return result;
}

// File Line: 63
// RVA: 0x613480
void __fastcall UFG::UIHKBuffData::Update(UFG::UIHKBuffData *this, UFG::UIScreen *screen, float elapsed)
{
  float TimeLeft; // xmm0_4

  if ( this->mState )
  {
    switch ( this->mState )
    {
      case STATE_ROOT_MENU:
        UFG::UIHKBuffData::Flash_Show(this, screen, 1);
        this->mState = STATE_PHONE_CONTACTS;
        break;
      case STATE_PHONE_CONTACTS:
        TimeLeft = UFG::UIHKBuffData::GetTimeLeft(this);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(this->mTimer - TimeLeft) & _xmm) > 0.5 || TimeLeft < 0.0099999998 )
        {
          this->mTimer = TimeLeft;
          UFG::UIHKBuffData::Flash_Refresh(this, screen);
          if ( this->mTimer < 0.0099999998 )
            this->mState = STATE_IDLE;
        }
        break;
      case STATE_TEXT_INBOX:
        UFG::UIHKBuffData::Flash_Refresh(this, screen);
        this->mState = STATE_PHONE_CONTACTS;
        break;
      case STATE_INCOMING_CALL:
        UFG::UIHKBuffData::Flash_Show(this, screen, 0);
        this->mState = STATE_PHONE_CONTACTS;
        break;
    }
  }
}

// File Line: 125
// RVA: 0x5E9750
float __fastcall UFG::UIHKBuffData::GetTimeLeft(UFG::UIHKBuffData *this)
{
  float v1; // xmm0_4
  UFG::GameStatTracker *v2; // rax
  float result; // xmm0_4
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax

  v1 = 0.0;
  switch ( this->mType )
  {
    case eBUFF_BERSERK:
      v2 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v2, Berserk_Activated) * 0.001;
      break;
    case eBUFF_SHARP_SHOOTER:
      v4 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v4, Sharpshooter_Activated) * 0.001;
      break;
    case eBUFF_ENERGY_DRINK:
      v5 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v5, EnergyDrinkBuff_Activated) * 0.001;
      break;
    case eBUFF_TEA_HOUSE:
      v6 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v6, TeaHouseBuff_Activated) * 0.001;
      break;
    case eBUFF_MASSAGE:
      v7 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v7, MassageParlourBuff_Activated) * 0.001;
      break;
    case eBUFF_HEALTHREGEN:
      v8 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v8, HealthRegen_Activated) * 0.001;
      break;
    case eBUFF_STRIKING:
      v9 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v9, StrikingBuff_Activated) * 0.001;
      break;
    case eBUFF_DEBUG_TEST:
      v1 = FLOAT_30000_0;
      goto LABEL_10;
    default:
LABEL_10:
      result = v1 * 0.001;
      break;
  }
  return result;
}

// File Line: 200
// RVA: 0x5E6BE0
void __fastcall UFG::UIHKBuffData::GetBuffInfo(
        UFG::UIHKBuffData::eBuffs type,
        const char **texture,
        const char **caption,
        float *maxTime)
{
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rax

  switch ( type )
  {
    case eBUFF_BERSERK:
      *texture = "Icon_Buff_Damage";
      *caption = "$HUD_BUFF_BERSERK";
      v5 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v5, Berserk_Duration);
      break;
    case eBUFF_SHARP_SHOOTER:
      *texture = "Icon_Buff_Shooting";
      *caption = "$HUD_BUFF_SHARPSHOOTER";
      v6 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v6, Sharpshooter_Duration_Level3);
      break;
    case eBUFF_ENERGY_DRINK:
      *texture = "Icon_Buff_Damage";
      *caption = "$HUD_BUFF_ENERGY_DRINK";
      v7 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v7, EnergyDrinkBuff_Duration);
      break;
    case eBUFF_TEA_HOUSE:
      *texture = "Icon_Buff_Health";
      *caption = "$HUD_BUFF_TEA_HOUSE";
      v8 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v8, TeaHouseBuff_Duration);
      break;
    case eBUFF_MASSAGE:
      *texture = "Icon_Buff_Face";
      *caption = "$HUD_BUFF_MASSAGE";
      v9 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v9, MassageParlourBuff_Duration);
      break;
    case eBUFF_HEALTHREGEN:
      *texture = "Icon_Buff_Health";
      *caption = "$HUD_BUFF_HEALTHREGEN";
      v10 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v10, HealthRegen_Duration_Level3);
      break;
    case eBUFF_STRIKING:
      *texture = "Icon_Buff_Damage";
      *caption = "$HUD_BUFF_BERSERK";
      v11 = UFG::GameStatTracker::Instance();
      *maxTime = UFG::GameStatTracker::GetStat(v11, StrikingBuff_Duration);
      break;
    case eBUFF_DEBUG_TEST:
      *maxTime = 90000.0;
      *texture = "DEFAULT_TEXTURE";
      *caption = "DEBUG";
      break;
    default:
      *maxTime = 100000.0;
      *texture = "DEFAULT_TEXTURE";
      *caption = "Something went terribly wrong";
      break;
  }
}

// File Line: 262
// RVA: 0x5E2540
void __fastcall UFG::UIHKBuffData::Flash_Show(UFG::UIHKBuffData *this, UFG::UIScreen *screen, bool playIntro)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v6; // xmm6_8
  double mTimer; // xmm6_8
  double v8; // xmm6_8
  char *caption; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-C0h] BYREF
  char v11[16]; // [rsp+70h] [rbp-90h] BYREF
  __int64 v12; // [rsp+80h] [rbp-80h]
  int v13; // [rsp+88h] [rbp-78h]
  char *v14; // [rsp+90h] [rbp-70h]
  char v15[16]; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v16; // [rsp+B0h] [rbp-50h]
  int v17; // [rsp+B8h] [rbp-48h]
  char *v18; // [rsp+C0h] [rbp-40h]
  char v19[16]; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v20; // [rsp+E0h] [rbp-20h]
  int v21; // [rsp+E8h] [rbp-18h]
  double v22; // [rsp+F0h] [rbp-10h]
  char v23[16]; // [rsp+100h] [rbp+0h] BYREF
  __int64 v24; // [rsp+110h] [rbp+10h]
  int v25; // [rsp+118h] [rbp+18h]
  double v26; // [rsp+120h] [rbp+20h]
  char v27[16]; // [rsp+130h] [rbp+30h] BYREF
  __int64 v28; // [rsp+140h] [rbp+40h]
  int v29; // [rsp+148h] [rbp+48h]
  __int64 v30; // [rsp+150h] [rbp+50h]
  __int64 v31; // [rsp+160h] [rbp+60h]
  float maxTime; // [rsp+1B8h] [rbp+B8h] BYREF
  char *texture; // [rsp+1C8h] [rbp+C8h] BYREF

  if ( screen )
  {
    v31 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::UIHKBuffData::GetBuffInfo(this->mType, (const char **)&texture, (const char **)&caption, &maxTime);
      `eh vector constructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v6.NValue = (double)(int)this->mType;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue = v6;
      if ( (v13 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
        v12 = 0i64;
      }
      v13 = 6;
      v14 = texture;
      if ( (v17 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
        v16 = 0i64;
      }
      v17 = 6;
      v18 = caption;
      mTimer = this->mTimer;
      if ( (v21 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v20 + 16i64))(
          v20,
          v19,
          COERCE_DOUBLE(*(_QWORD *)&v22));
        v20 = 0i64;
      }
      v21 = 5;
      v22 = mTimer;
      v8 = maxTime;
      if ( (v25 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v24 + 16i64))(
          v24,
          v23,
          COERCE_DOUBLE(*(_QWORD *)&v26));
        v24 = 0i64;
      }
      v25 = 5;
      v26 = v8;
      if ( (v29 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v28 + 16i64))(v28, v27, v30);
        v28 = 0i64;
      }
      v29 = 2;
      LOBYTE(v30) = playIntro;
      Scaleform::GFx::Movie::Invoke(pObject, "Buffs_Add", 0i64, &ptr, 6u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 289
// RVA: 0x5DE8B0
void __fastcall UFG::UIHKBuffData::Flash_Refresh(UFG::UIHKBuffData *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  double mTimer; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  char v7[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v8; // [rsp+80h] [rbp-38h]
  int v9; // [rsp+88h] [rbp-30h]
  double v10; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4.NValue = (double)(int)this->mType;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue = v4;
      mTimer = this->mTimer;
      if ( (v9 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(
          v8,
          v7,
          COERCE_DOUBLE(*(_QWORD *)&v10));
        v8 = 0i64;
      }
      v9 = 5;
      v10 = mTimer;
      Scaleform::GFx::Movie::Invoke(pObject, "Buffs_Refresh", 0i64, &ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 314
// RVA: 0x5C94B0
void __fastcall UFG::UIHKBuffWidget::~UIHKBuffWidget(UFG::UIHKBuffWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mTexturePackFilename.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::UIHKBuffWidget::mNumTextureLoaded = 0;
  `eh vector destructor iterator(this->mIconLoaded, 0x28ui64, 7, (void (__fastcall *)(void *))UFG::qString::~qString);
  UFG::qString::~qString(&this->mTexturePackFilename);
}

// File Line: 330
// RVA: 0x613560
void __fastcall UFG::UIHKBuffWidget::Update(UFG::UIHKBuffWidget *this, UFG::UIScreen *screen, float elapsed)
{
  unsigned int i; // ebx
  SSMetaClass *v6; // rax
  SSInstance *v7; // rax
  SSInstance *v8; // rbx
  SSObjectBaseVtbl *vfptr; // r10
  __int64 v10; // rax
  float v11; // xmm6_4
  SSMetaClass *v12; // rax
  SSInstance *v13; // rax
  SSInstance *v14; // rbx
  SSObjectBaseVtbl *v15; // r10
  __int64 v16; // rax
  __int64 v17; // [rsp+68h] [rbp+10h] BYREF

  if ( screen )
  {
    for ( i = 0; i < UFG::UIHKBuffWidget::mNumBuffs; ++i )
      UFG::UIHKBuffData::Update(&UFG::UIHKBuffWidget::mBuffData[i], screen, elapsed);
    if ( this->mPerkActivate )
    {
      this->mPerkActivate = 0;
      v6 = SkookumScript::c_world_class_p->vfptr->get_metaclass(SkookumScript::c_world_class_p);
      v7 = v6->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->get_data_by_name(
             &v6->SSInstanceUnreffed,
             (ASymbol *)&qSymbol_c_perk_system);
      v8 = v7;
      if ( v7 )
      {
        vfptr = v7->vfptr;
        v17 = 0i64;
        ((void (__fastcall *)(SSInstance *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))vfptr[1].set_data_by_name)(
          v7,
          &qSymbol_get_perk_action,
          &v17,
          0i64,
          0i64,
          0i64);
        v10 = (__int64)v8->vfptr->get_data_by_name(v8, (ASymbol *)&qSymbol_i_current_perk);
        UFG::UIHKBuffWidget::LoadTexture(this, **(const char ***)(v10 + 32));
      }
    }
    if ( this->mPerkIsActive )
    {
      v11 = elapsed + this->mPerkTimer;
      this->mPerkTimer = v11;
      if ( v11 > 5.0 )
      {
        v12 = SkookumScript::c_world_class_p->vfptr->get_metaclass(SkookumScript::c_world_class_p);
        v13 = v12->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->get_data_by_name(
                &v12->SSInstanceUnreffed,
                (ASymbol *)&qSymbol_c_perk_system);
        v14 = v13;
        if ( v13 )
        {
          v15 = v13->vfptr;
          v17 = 0i64;
          ((void (__fastcall *)(SSInstance *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))v15[1].set_data_by_name)(
            v13,
            &qSymbol_get_perk_action,
            &v17,
            0i64,
            0i64,
            0i64);
          v16 = (__int64)v14->vfptr->get_data_by_name(v14, (ASymbol *)&qSymbol_i_current_perk);
          if ( (unsigned int)UFG::qStringCompareInsensitive(**(const char ***)(v16 + 32), "perksCopPerks_None", -1) )
          {
            UFG::UIHKBuffWidget::Clear();
            this->mPerkIsActive = 0;
          }
        }
      }
    }
  }
}

// File Line: 381
// RVA: 0x5D2720
void __fastcall UFG::UIHKBuffWidget::AddPerk(const char *perk)
{
  Scaleform::GFx::Movie *pObject; // rdi
  const char *v3; // rdx
  char *mData; // rbx
  char *v5; // rbx
  UFG::qString v6; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qString ptr; // [rsp+58h] [rbp-A0h] BYREF
  __int64 v8; // [rsp+88h] [rbp-70h]
  int v9; // [rsp+90h] [rbp-68h]
  long double v10; // [rsp+98h] [rbp-60h]
  char v11[16]; // [rsp+A8h] [rbp-50h] BYREF
  __int64 v12; // [rsp+B8h] [rbp-40h]
  int v13; // [rsp+C0h] [rbp-38h]
  char *v14; // [rsp+C8h] [rbp-30h]
  char v15[16]; // [rsp+D8h] [rbp-20h] BYREF
  __int64 v16; // [rsp+E8h] [rbp-10h]
  int v17; // [rsp+F0h] [rbp-8h]
  char *v18; // [rsp+F8h] [rbp+0h]
  char v19[16]; // [rsp+108h] [rbp+10h] BYREF
  __int64 v20; // [rsp+118h] [rbp+20h]
  int v21; // [rsp+120h] [rbp+28h]
  long double v22; // [rsp+128h] [rbp+30h]
  char v23[16]; // [rsp+138h] [rbp+40h] BYREF
  __int64 v24; // [rsp+148h] [rbp+50h]
  int v25; // [rsp+150h] [rbp+58h]
  long double v26; // [rsp+158h] [rbp+60h]
  char v27[16]; // [rsp+168h] [rbp+70h] BYREF
  __int64 v28; // [rsp+178h] [rbp+80h]
  int v29; // [rsp+180h] [rbp+88h]
  __int64 v30; // [rsp+188h] [rbp+90h]
  __int64 v31; // [rsp+198h] [rbp+A0h]

  v31 = -2i64;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    pObject = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::qString::qString(&ptr, "default");
      UFG::qString::qString(&v6, "Kleptomaniac");
      if ( (unsigned int)UFG::qStringCompare("CopPerks_HeatReduction", perk, -1) )
      {
        if ( (unsigned int)UFG::qStringCompare("CopPerks_Vehicle", perk, -1) )
        {
          if ( (unsigned int)UFG::qStringCompare("CopPerks_Surveillance", perk, -1) )
          {
            UFG::qString::Set(&ptr, "Icon_Social_Help");
            v3 = "Something went terribly wrong";
          }
          else
          {
            UFG::qString::Set(&ptr, "CopPerks_Surveillance");
            v3 = "$HUD_PERK_SURVEILLANCE";
          }
        }
        else
        {
          UFG::qString::Set(&ptr, "CopPerks_Vehicle");
          v3 = "$HUD_PERK_VEHICLE";
        }
      }
      else
      {
        UFG::qString::Set(&ptr, "CopPerks_HeatReduction");
        v3 = "$HUD_PERK_REDUCE_HEAT";
      }
      UFG::qString::Set(&v6, v3);
      `eh vector constructor iterator(
        &ptr.mStringHash32,
        0x30ui64,
        6,
        (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v9 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, long double))(*(_QWORD *)v8 + 16i64))(
          v8,
          &ptr.mStringHash32,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v10));
        v8 = 0i64;
      }
      v9 = 5;
      v10 = DOUBLE_1_0;
      mData = ptr.mData;
      if ( (v13 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
        v12 = 0i64;
      }
      v13 = 6;
      v14 = mData;
      v5 = v6.mData;
      if ( (v17 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
        v16 = 0i64;
      }
      v17 = 6;
      v18 = v5;
      if ( (v21 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v20 + 16i64))(
          v20,
          v19,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v22));
        v20 = 0i64;
      }
      v21 = 5;
      v22 = DOUBLE_N1_0;
      if ( (v25 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v24 + 16i64))(
          v24,
          v23,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v26));
        v24 = 0i64;
      }
      v25 = 5;
      v26 = DOUBLE_N1_0;
      if ( (v29 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v28 + 16i64))(v28, v27, v30);
        v28 = 0i64;
      }
      v29 = 5;
      v30 = 0i64;
      Scaleform::GFx::Movie::Invoke(pObject, "Buffs_Add", 0i64, (Scaleform::GFx::Value *)&ptr.mStringHash32, 6u);
      `eh vector destructor iterator(
        &ptr.mStringHash32,
        0x30ui64,
        6,
        (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v6);
      UFG::qString::~qString(&ptr);
    }
  }
}

// File Line: 434
// RVA: 0x5D18D0
void __fastcall UFG::UIHKBuffWidget::Add(UFG::UIHKBuffData::eBuffs type, int seconds)
{
  unsigned int v2; // ebx
  UFG::HudAudio *v5; // rcx
  unsigned int v6; // edx
  UFG::UIHKBuffData *v7; // rax
  __int64 v8; // rcx
  unsigned int v9; // edx

  v2 = 0;
  if ( type < eBUFF_ENERGY_DRINK )
  {
LABEL_6:
    v5 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      goto LABEL_9;
    v6 = -1814360587;
    goto LABEL_8;
  }
  if ( type > eBUFF_TEA_HOUSE )
  {
    if ( type == eBUFF_MASSAGE )
    {
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_9;
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEB72E841, 0i64, 0, 0i64);
    }
    goto LABEL_6;
  }
  v5 = UFG::HudAudio::m_instance;
  if ( UFG::HudAudio::m_instance )
  {
    v6 = 680684653;
LABEL_8:
    UFG::AudioEntity::CreateAndPlayEvent(v5, v6, 0i64, 0, 0i64);
  }
LABEL_9:
  if ( UFG::UIHKBuffWidget::mNumBuffs )
  {
    v7 = UFG::UIHKBuffWidget::mBuffData;
    while ( v7->mState )
    {
      if ( v7->mType == type )
      {
        v7->mType = type;
        v7->mState = STATE_TEXT_INBOX;
        v7->mTimer = (float)seconds;
        return;
      }
      ++v2;
      ++v7;
      if ( v2 >= UFG::UIHKBuffWidget::mNumBuffs )
        goto LABEL_14;
    }
    v7->mType = type;
    v7->mState = STATE_ROOT_MENU;
    v7->mTimer = (float)seconds;
  }
  else
  {
LABEL_14:
    if ( UFG::UIHKBuffWidget::mNumBuffs < 6 )
    {
      v8 = UFG::UIHKBuffWidget::mNumBuffs;
      v9 = UFG::UIHKBuffWidget::mNumBuffs + 1;
      UFG::UIHKBuffWidget::mBuffData[v8].mType = type;
      UFG::UIHKBuffWidget::mBuffData[v8].mState = STATE_ROOT_MENU;
      UFG::UIHKBuffWidget::mNumBuffs = v9;
      UFG::UIHKBuffWidget::mBuffData[v8].mTimer = (float)seconds;
    }
  }
}

// File Line: 482
// RVA: 0x5D4FE0
void UFG::UIHKBuffWidget::Clear(void)
{
  __int64 v0; // rcx
  UFG::UIHKBuffData *v1; // rax
  Scaleform::GFx::Movie *pObject; // rcx

  v0 = UFG::UIHKBuffWidget::mNumBuffs;
  if ( UFG::UIHKBuffWidget::mNumBuffs )
  {
    v1 = UFG::UIHKBuffWidget::mBuffData;
    do
    {
      v1->mState = STATE_IDLE;
      ++v1;
      --v0;
    }
    while ( v0 );
  }
  UFG::UIHKBuffWidget::mNumBuffs = 0;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    pObject = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "Buffs_Remove", 0i64, 0i64, 0);
  }
}

// File Line: 501
// RVA: 0x5F11C0
void __fastcall UFG::UIHKBuffWidget::LoadTexture(UFG::UIHKBuffWidget *this, const char *tpName)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  UFG::qString *v6; // rax
  char *v7; // rbx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( UFG::UIHKBuffWidget::mNumTextureLoaded < 7 )
  {
    mData = this->mTexturePackFilename.mData;
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v5, mData);
    v6 = UFG::qString::FormatEx(&result, "Data\\UI\\%s_tp.perm.bin", tpName);
    UFG::qString::Set(&this->mTexturePackFilename, v6->mData, v6->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    UFG::qString::ReplaceString(&this->mTexturePackFilename, " ", "_", 0);
    v7 = this->mTexturePackFilename.mData;
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v8,
      v7,
      DEFAULT_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHKBuffWidget::TextureLoadedCallback,
      0i64);
    UFG::qString::Set(&this->mIconLoaded[UFG::UIHKBuffWidget::mNumTextureLoaded], tpName);
  }
}

// File Line: 528
// RVA: 0x6127D0
void __fastcall UFG::UIHKBuffWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud *v2; // rdx

  v2 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    UFG::UIHKBuffWidget::AddPerk(UFG::UIHKScreenHud::mInstance->Buffs.mIconLoaded[UFG::UIHKBuffWidget::mNumTextureLoaded].mData);
    v2 = UFG::UIHKScreenHud::mInstance;
  }
  ++UFG::UIHKBuffWidget::mNumTextureLoaded;
  v2->Buffs.mPerkIsActive = 1;
  v2->Buffs.mPerkTimer = 0.0;
}

