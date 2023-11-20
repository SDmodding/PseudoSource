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
  UFG::UIScreen *v3; // rdi
  UFG::UIHKBuffData *v4; // rbx
  float v5; // xmm0_4

  v3 = screen;
  v4 = this;
  if ( this->mState )
  {
    switch ( this->mState )
    {
      case 1:
        UFG::UIHKBuffData::Flash_Show(this, screen, 1);
        v4->mState = 2;
        break;
      case 2:
        v5 = UFG::UIHKBuffData::GetTimeLeft(this);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v4->mTimer - v5) & _xmm) > 0.5 || v5 < 0.0099999998 )
        {
          v4->mTimer = v5;
          UFG::UIHKBuffData::Flash_Refresh(v4, v3);
          if ( v4->mTimer < 0.0099999998 )
            v4->mState = 0;
        }
        break;
      case 3:
        UFG::UIHKBuffData::Flash_Refresh(this, screen);
        v4->mState = 2;
        break;
      case 4:
        UFG::UIHKBuffData::Flash_Show(this, screen, 0);
        v4->mState = 2;
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
    case 2:
      v2 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v2, Berserk_Activated) * 0.001;
      break;
    case 3:
      v4 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v4, Sharpshooter_Activated) * 0.001;
      break;
    case 4:
      v5 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v5, EnergyDrinkBuff_Activated) * 0.001;
      break;
    case 5:
      v6 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v6, TeaHouseBuff_Activated) * 0.001;
      break;
    case 6:
      v7 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v7, MassageParlourBuff_Activated) * 0.001;
      break;
    case 7:
      v8 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v8, HealthRegen_Activated) * 0.001;
      break;
    case 8:
      v9 = UFG::GameStatTracker::Instance();
      result = UFG::GameStatTracker::GetStat(v9, StrikingBuff_Activated) * 0.001;
      break;
    case 9:
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
void __fastcall UFG::UIHKBuffData::GetBuffInfo(UFG::UIHKBuffData::eBuffs type, const char **texture, const char **caption, float *maxTime)
{
  float *v4; // rbx
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rax

  v4 = maxTime;
  switch ( type )
  {
    case 2:
      *texture = "Icon_Buff_Damage";
      *caption = "$HUD_BUFF_BERSERK";
      v5 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v5, Berserk_Duration);
      break;
    case 3:
      *texture = "Icon_Buff_Shooting";
      *caption = "$HUD_BUFF_SHARPSHOOTER";
      v6 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v6, Sharpshooter_Duration_Level3);
      break;
    case 4:
      *texture = "Icon_Buff_Damage";
      *caption = "$HUD_BUFF_ENERGY_DRINK";
      v7 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v7, EnergyDrinkBuff_Duration);
      break;
    case 5:
      *texture = "Icon_Buff_Health";
      *caption = "$HUD_BUFF_TEA_HOUSE";
      v8 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v8, TeaHouseBuff_Duration);
      break;
    case 6:
      *texture = "Icon_Buff_Face";
      *caption = "$HUD_BUFF_MASSAGE";
      v9 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v9, MassageParlourBuff_Duration);
      break;
    case 7:
      *texture = "Icon_Buff_Health";
      *caption = "$HUD_BUFF_HEALTHREGEN";
      v10 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v10, HealthRegen_Duration_Level3);
      break;
    case 8:
      *texture = "Icon_Buff_Damage";
      *caption = "$HUD_BUFF_BERSERK";
      v11 = UFG::GameStatTracker::Instance();
      *v4 = UFG::GameStatTracker::GetStat(v11, StrikingBuff_Duration);
      break;
    case 9:
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
  bool v3; // si
  UFG::UIHKBuffData *v4; // rdi
  Scaleform::GFx::Movie *v5; // rbx
  double v6; // xmm6_8
  double v7; // xmm6_8
  double v8; // xmm6_8
  char *caption; // [rsp+30h] [rbp-D0h]
  char ptr; // [rsp+40h] [rbp-C0h]
  __int64 v11; // [rsp+50h] [rbp-B0h]
  unsigned int v12; // [rsp+58h] [rbp-A8h]
  double v13; // [rsp+60h] [rbp-A0h]
  char v14; // [rsp+70h] [rbp-90h]
  __int64 v15; // [rsp+80h] [rbp-80h]
  unsigned int v16; // [rsp+88h] [rbp-78h]
  char *v17; // [rsp+90h] [rbp-70h]
  char v18; // [rsp+A0h] [rbp-60h]
  __int64 v19; // [rsp+B0h] [rbp-50h]
  unsigned int v20; // [rsp+B8h] [rbp-48h]
  char *v21; // [rsp+C0h] [rbp-40h]
  char v22; // [rsp+D0h] [rbp-30h]
  __int64 v23; // [rsp+E0h] [rbp-20h]
  unsigned int v24; // [rsp+E8h] [rbp-18h]
  double v25; // [rsp+F0h] [rbp-10h]
  char v26; // [rsp+100h] [rbp+0h]
  __int64 v27; // [rsp+110h] [rbp+10h]
  unsigned int v28; // [rsp+118h] [rbp+18h]
  double v29; // [rsp+120h] [rbp+20h]
  char v30; // [rsp+130h] [rbp+30h]
  __int64 v31; // [rsp+140h] [rbp+40h]
  unsigned int v32; // [rsp+148h] [rbp+48h]
  __int64 v33; // [rsp+150h] [rbp+50h]
  __int64 v34; // [rsp+160h] [rbp+60h]
  float maxTime; // [rsp+1B8h] [rbp+B8h]
  char *texture; // [rsp+1C8h] [rbp+C8h]

  if ( screen )
  {
    v34 = -2i64;
    v3 = playIntro;
    v4 = this;
    v5 = screen->mRenderable->m_movie.pObject;
    if ( v5 )
    {
      UFG::UIHKBuffData::GetBuffInfo(this->mType, (const char **)&texture, (const char **)&caption, &maxTime);
      `eh vector constructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v6 = (double)(signed int)v4->mType;
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
          v11,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v13));
        v11 = 0i64;
      }
      v12 = 5;
      v13 = v6;
      if ( (v16 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
        v15 = 0i64;
      }
      v16 = 6;
      v17 = texture;
      if ( (v20 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
        v19 = 0i64;
      }
      v20 = 6;
      v21 = caption;
      v7 = v4->mTimer;
      if ( (v24 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v23 + 16i64))(
          v23,
          &v22,
          COERCE_DOUBLE(*(_QWORD *)&v25));
        v23 = 0i64;
      }
      v24 = 5;
      v25 = v7;
      v8 = maxTime;
      if ( (v28 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v27 + 16i64))(
          v27,
          &v26,
          COERCE_DOUBLE(*(_QWORD *)&v29));
        v27 = 0i64;
      }
      v28 = 5;
      v29 = v8;
      if ( (v32 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v31 + 16i64))(v31, &v30, v33);
        v31 = 0i64;
      }
      v32 = 2;
      LOBYTE(v33) = v3;
      Scaleform::GFx::Movie::Invoke(v5, "Buffs_Add", 0i64, (Scaleform::GFx::Value *)&ptr, 6u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 289
// RVA: 0x5DE8B0
void __fastcall UFG::UIHKBuffData::Flash_Refresh(UFG::UIHKBuffData *this, UFG::UIScreen *screen)
{
  UFG::UIHKBuffData *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  double v4; // xmm6_8
  double v5; // xmm6_8
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v7; // [rsp+50h] [rbp-68h]
  unsigned int v8; // [rsp+58h] [rbp-60h]
  double v9; // [rsp+60h] [rbp-58h]
  char v10; // [rsp+70h] [rbp-48h]
  __int64 v11; // [rsp+80h] [rbp-38h]
  unsigned int v12; // [rsp+88h] [rbp-30h]
  double v13; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4 = (double)(signed int)v2->mType;
      if ( (v8 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(
          v7,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v9));
        v7 = 0i64;
      }
      v8 = 5;
      v9 = v4;
      v5 = v2->mTimer;
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
          v11,
          &v10,
          COERCE_DOUBLE(*(_QWORD *)&v13));
        v11 = 0i64;
      }
      v12 = 5;
      v13 = v5;
      Scaleform::GFx::Movie::Invoke(v3, "Buffs_Refresh", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 314
// RVA: 0x5C94B0
void __fastcall UFG::UIHKBuffWidget::~UIHKBuffWidget(UFG::UIHKBuffWidget *this)
{
  UFG::UIHKBuffWidget *v1; // rdi
  char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this;
  v2 = this->mTexturePackFilename.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v2);
  UFG::UIHKBuffWidget::mNumTextureLoaded = 0;
  `eh vector destructor iterator(v1->mIconLoaded, 0x28ui64, 7, (void (__fastcall *)(void *))UFG::qString::~qString);
  UFG::qString::~qString(&v1->mTexturePackFilename);
}

// File Line: 330
// RVA: 0x613560
void __fastcall UFG::UIHKBuffWidget::Update(UFG::UIHKBuffWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIHKBuffWidget *v5; // rdi
  __int64 v6; // rax
  _QWORD *v7; // rax
  _QWORD *v8; // rbx
  __int64 v9; // r10
  __int64 v10; // rax
  float v11; // xmm6_4
  __int64 v12; // rax
  _QWORD *v13; // rax
  _QWORD *v14; // rbx
  __int64 v15; // r10
  __int64 v16; // rax
  __int64 v17; // [rsp+68h] [rbp+10h]

  if ( screen )
  {
    v3 = screen;
    v4 = 0;
    v5 = this;
    if ( UFG::UIHKBuffWidget::mNumBuffs )
    {
      do
        UFG::UIHKBuffData::Update(&UFG::UIHKBuffWidget::mBuffData[v4++], v3, elapsed);
      while ( v4 < UFG::UIHKBuffWidget::mNumBuffs );
    }
    if ( v5->mPerkActivate )
    {
      v5->mPerkActivate = 0;
      v6 = ((__int64 (*)(void))SkookumScript::c_world_class_p->vfptr->get_metaclass)();
      v7 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, UFG::qStaticSymbol *))(*(_QWORD *)(v6 + 8) + 32i64))(
                       v6 + 8,
                       &qSymbol_c_perk_system);
      v8 = v7;
      if ( v7 )
      {
        v9 = *v7;
        v17 = 0i64;
        (*(void (__fastcall **)(_QWORD *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))(v9 + 104))(
          v7,
          &qSymbol_get_perk_action,
          &v17,
          0i64,
          0i64,
          0i64);
        v10 = (*(__int64 (__fastcall **)(_QWORD *, UFG::qStaticSymbol *))(*v8 + 32i64))(v8, &qSymbol_i_current_perk);
        UFG::UIHKBuffWidget::LoadTexture(v5, **(const char ***)(v10 + 32));
      }
    }
    if ( v5->mPerkIsActive )
    {
      v11 = elapsed + v5->mPerkTimer;
      v5->mPerkTimer = v11;
      if ( v11 > 5.0 )
      {
        v12 = ((__int64 (*)(void))SkookumScript::c_world_class_p->vfptr->get_metaclass)();
        v13 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, UFG::qStaticSymbol *))(*(_QWORD *)(v12 + 8) + 32i64))(
                          v12 + 8,
                          &qSymbol_c_perk_system);
        v14 = v13;
        if ( v13 )
        {
          v15 = *v13;
          v17 = 0i64;
          (*(void (__fastcall **)(_QWORD *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))(v15 + 104))(
            v13,
            &qSymbol_get_perk_action,
            &v17,
            0i64,
            0i64,
            0i64);
          v16 = (*(__int64 (__fastcall **)(_QWORD *, UFG::qStaticSymbol *))(*v14 + 32i64))(v14, &qSymbol_i_current_perk);
          if ( (unsigned int)UFG::qStringCompareInsensitive(**(const char ***)(v16 + 32), "perksCopPerks_None", -1) )
          {
            UFG::UIHKBuffWidget::Clear();
            v5->mPerkIsActive = 0;
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
  const char *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  const char *v3; // rdx
  char *v4; // rbx
  char *v5; // rbx
  UFG::qString v6; // [rsp+30h] [rbp-C8h]
  UFG::qString ptr; // [rsp+58h] [rbp-A0h]
  __int64 v8; // [rsp+88h] [rbp-70h]
  unsigned int v9; // [rsp+90h] [rbp-68h]
  long double v10; // [rsp+98h] [rbp-60h]
  char v11; // [rsp+A8h] [rbp-50h]
  __int64 v12; // [rsp+B8h] [rbp-40h]
  unsigned int v13; // [rsp+C0h] [rbp-38h]
  char *v14; // [rsp+C8h] [rbp-30h]
  char v15; // [rsp+D8h] [rbp-20h]
  __int64 v16; // [rsp+E8h] [rbp-10h]
  unsigned int v17; // [rsp+F0h] [rbp-8h]
  char *v18; // [rsp+F8h] [rbp+0h]
  char v19; // [rsp+108h] [rbp+10h]
  __int64 v20; // [rsp+118h] [rbp+20h]
  unsigned int v21; // [rsp+120h] [rbp+28h]
  long double v22; // [rsp+128h] [rbp+30h]
  char v23; // [rsp+138h] [rbp+40h]
  __int64 v24; // [rsp+148h] [rbp+50h]
  unsigned int v25; // [rsp+150h] [rbp+58h]
  long double v26; // [rsp+158h] [rbp+60h]
  char v27; // [rsp+168h] [rbp+70h]
  __int64 v28; // [rsp+178h] [rbp+80h]
  unsigned int v29; // [rsp+180h] [rbp+88h]
  __int64 v30; // [rsp+188h] [rbp+90h]
  __int64 v31; // [rsp+198h] [rbp+A0h]

  v31 = -2i64;
  v1 = perk;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    v2 = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
    if ( v2 )
    {
      UFG::qString::qString(&ptr, "default");
      UFG::qString::qString(&v6, "Kleptomaniac");
      if ( (unsigned int)UFG::qStringCompare("CopPerks_HeatReduction", v1, -1) )
      {
        if ( (unsigned int)UFG::qStringCompare("CopPerks_Vehicle", v1, -1) )
        {
          if ( (unsigned int)UFG::qStringCompare("CopPerks_Surveillance", v1, -1) )
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
      if ( (v9 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, long double))(*(_QWORD *)v8 + 16i64))(
          v8,
          &ptr.mStringHash32,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v10));
        v8 = 0i64;
      }
      v9 = 5;
      v10 = DOUBLE_1_0;
      v4 = ptr.mData;
      if ( (v13 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v12 + 16i64))(v12, &v11, v14);
        v12 = 0i64;
      }
      v13 = 6;
      v14 = v4;
      v5 = v6.mData;
      if ( (v17 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
        v16 = 0i64;
      }
      v17 = 6;
      v18 = v5;
      if ( (v21 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v20 + 16i64))(
          v20,
          &v19,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v22));
        v20 = 0i64;
      }
      v21 = 5;
      v22 = DOUBLE_N1_0;
      if ( (v25 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v24 + 16i64))(
          v24,
          &v23,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v26));
        v24 = 0i64;
      }
      v25 = 5;
      v26 = DOUBLE_N1_0;
      if ( (v29 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v28 + 16i64))(v28, &v27, v30);
        v28 = 0i64;
      }
      v29 = 5;
      v30 = 0i64;
      Scaleform::GFx::Movie::Invoke(v2, "Buffs_Add", 0i64, (Scaleform::GFx::Value *)&ptr.mStringHash32, 6u);
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
  int v3; // esi
  UFG::UIHKBuffData::eBuffs v4; // edi
  UFG::HudAudio *v5; // rcx
  unsigned int v6; // edx
  UFG::UIHKBuffData *v7; // rax
  __int64 v8; // rcx
  unsigned int v9; // edx

  v2 = 0;
  v3 = seconds;
  v4 = type;
  if ( (signed int)type < 4 )
  {
LABEL_6:
    v5 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      goto LABEL_9;
    v6 = -1814360587;
    goto LABEL_8;
  }
  if ( (signed int)type > 5 )
  {
    if ( type == 6 )
    {
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_9;
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEB72E841,
        0i64,
        0,
        0i64);
    }
    goto LABEL_6;
  }
  v5 = UFG::HudAudio::m_instance;
  if ( UFG::HudAudio::m_instance )
  {
    v6 = 680684653;
LABEL_8:
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v5->vfptr, v6, 0i64, 0, 0i64);
  }
LABEL_9:
  if ( UFG::UIHKBuffWidget::mNumBuffs )
  {
    v7 = UFG::UIHKBuffWidget::mBuffData;
    while ( v7->mState )
    {
      if ( v7->mType == v4 )
      {
        v7->mType = v4;
        v7->mState = 3;
        v7->mTimer = (float)v3;
        return;
      }
      ++v2;
      ++v7;
      if ( v2 >= UFG::UIHKBuffWidget::mNumBuffs )
        goto LABEL_14;
    }
    v7->mType = v4;
    v7->mState = 1;
    v7->mTimer = (float)v3;
  }
  else
  {
LABEL_14:
    if ( UFG::UIHKBuffWidget::mNumBuffs < 6 )
    {
      v8 = UFG::UIHKBuffWidget::mNumBuffs;
      v9 = UFG::UIHKBuffWidget::mNumBuffs + 1;
      UFG::UIHKBuffWidget::mBuffData[v8].mType = v4;
      UFG::UIHKBuffWidget::mBuffData[v8].mState = 1;
      UFG::UIHKBuffWidget::mNumBuffs = v9;
      UFG::UIHKBuffWidget::mBuffData[v8].mTimer = (float)v3;
    }
  }
}

// File Line: 482
// RVA: 0x5D4FE0
void UFG::UIHKBuffWidget::Clear(void)
{
  __int64 v0; // rcx
  UFG::UIHKBuffData *v1; // rax
  Scaleform::GFx::Movie *v2; // rcx

  v0 = UFG::UIHKBuffWidget::mNumBuffs;
  if ( UFG::UIHKBuffWidget::mNumBuffs )
  {
    v1 = UFG::UIHKBuffWidget::mBuffData;
    do
    {
      v1->mState = 0;
      ++v1;
      --v0;
    }
    while ( v0 );
  }
  UFG::UIHKBuffWidget::mNumBuffs = 0;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    v2 = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
    if ( v2 )
      Scaleform::GFx::Movie::Invoke(v2, "Buffs_Remove", 0i64, 0i64, 0);
  }
}

// File Line: 501
// RVA: 0x5F11C0
void __fastcall UFG::UIHKBuffWidget::LoadTexture(UFG::UIHKBuffWidget *this, const char *tpName)
{
  const char *v2; // rsi
  UFG::UIHKBuffWidget *v3; // rdi
  char *v4; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  UFG::qString *v6; // rax
  const char *v7; // rbx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v2 = tpName;
  v3 = this;
  if ( UFG::UIHKBuffWidget::mNumTextureLoaded < 7 )
  {
    v4 = this->mTexturePackFilename.mData;
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v5, v4);
    v6 = UFG::qString::FormatEx(&result, "Data\\UI\\%s_tp.perm.bin", v2);
    UFG::qString::Set(&v3->mTexturePackFilename, v6->mData, v6->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    UFG::qString::ReplaceString(&v3->mTexturePackFilename, " ", "_", 0);
    v7 = v3->mTexturePackFilename.mData;
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v8,
      v7,
      DEFAULT_PRIORITY,
      UFG::UIHKBuffWidget::TextureLoadedCallback,
      0i64);
    UFG::qString::Set(&v3->mTexturePackFilename + UFG::UIHKBuffWidget::mNumTextureLoaded + 1i64, v2);
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

