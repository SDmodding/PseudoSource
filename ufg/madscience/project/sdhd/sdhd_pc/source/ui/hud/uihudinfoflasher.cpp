// File Line: 45
// RVA: 0x6208A0
UFG::UIHUDInfoFlasher *__fastcall UFG::UIHUDInfoFlasher::getInstance()
{
  return UFG::UIHUDInfoFlasher::mInstance;
}

// File Line: 133
// RVA: 0x63B2B0
void __fastcall UFG::UIHUDInfoFlasher::show(UFG::UIHUDInfoFlasher *this, UFG::InfoFlasherBase *new_flasher)
{
  UFG::qList<UFG::InfoFlasherBase,UFG::InfoFlasherBase,1,0> *v2; // r8
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *v3; // rcx
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *v4; // rax

  if ( new_flasher )
  {
    v2 = &this->mFlasherList;
    v3 = (UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *)&new_flasher->mPrev;
    v4 = v2->mNode.mPrev;
    v4->mNext = (UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *)&new_flasher->mPrev;
    v3->mPrev = v4;
    v3->mNext = &v2->mNode;
    v2->mNode.mPrev = (UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *)&new_flasher->mPrev;
  }
}

// File Line: 166
// RVA: 0x5C3AF0
void __fastcall UFG::InfoFlasherBase::InfoFlasherBase(UFG::InfoFlasherBase *this, const char *text, float displayTime, bool repeat, float repeatTime)
{
  bool v5; // bl
  UFG::InfoFlasherBase *v6; // rdi
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *v7; // rax

  v5 = repeat;
  v6 = this;
  v7 = (UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::InfoFlasherBaseVtbl *)&UFG::InfoFlasherBase::`vftable';
  this->m_eState = 0;
  UFG::qString::qString(&this->m_sHintTxt, text);
  v6->m_fDisplayTime = displayTime;
  v6->m_bRepeatMsg = v5;
  v6->m_fRepeatTime = repeatTime;
  *(_QWORD *)&v6->m_fTimerDisplay = 0i64;
  v6->m_fHintReminderTimeout = 0.0;
  v6->mGFxMovie.pObjectInterface = 0i64;
  v6->mGFxMovie.Type = 0;
}

// File Line: 171
// RVA: 0x5C9180
void __fastcall UFG::InfoFlasherBase::~InfoFlasherBase(UFG::InfoFlasherBase *this)
{
  UFG::InfoFlasherBase *v1; // rbx
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *v2; // rdx
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *v3; // rcx
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::InfoFlasherBaseVtbl *)&UFG::InfoFlasherBase::`vftable';
  if ( ((unsigned int)this->mGFxMovie.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&this->mGFxMovie.pObjectInterface->vfptr->gap8[8])(
      this->mGFxMovie.pObjectInterface,
      &this->mGFxMovie,
      *(_QWORD *)&this->mGFxMovie.mValue.NValue);
    v1->mGFxMovie.pObjectInterface = 0i64;
  }
  v1->mGFxMovie.Type = 0;
  UFG::qString::~qString(&v1->m_sHintTxt);
  v2 = (UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 183
// RVA: 0x63AB30
void __usercall UFG::InfoFlasherBase::show(UFG::InfoFlasherBase *this@<rcx>, Scaleform::GFx::Movie *movie@<rdx>, float a3@<xmm0>)
{
  UFG::InfoFlasherBase *v3; // rbx
  const char *v4; // rdi
  __int64 v5; // rsi
  __int64 v6; // rdx
  UFG::UIGfxTranslator *v7; // rcx
  char v8; // [rsp+40h] [rbp-B8h]
  __int64 v9; // [rsp+50h] [rbp-A8h]
  unsigned int v10; // [rsp+58h] [rbp-A0h]
  __int64 v11; // [rsp+60h] [rbp-98h]
  __int64 v12; // [rsp+70h] [rbp-88h]
  double v13; // [rsp+78h] [rbp-80h]
  double v14; // [rsp+80h] [rbp-78h]
  int Dst; // [rsp+D8h] [rbp-20h]
  int v16; // [rsp+ECh] [rbp-Ch]
  int v17; // [rsp+100h] [rbp+8h]
  int v18; // [rsp+108h] [rbp+10h]
  int v19; // [rsp+11Ch] [rbp+24h]
  int v20; // [rsp+130h] [rbp+38h]
  int v21; // [rsp+144h] [rbp+4Ch]
  __int16 v22; // [rsp+14Ch] [rbp+54h]

  v12 = -2i64;
  v3 = this;
  if ( (this->mGFxMovie.Type & 0x8F) != 1 )
  {
    memset(&Dst, 0, 0x30ui64);
    Dst = 1065353216;
    v16 = 1065353216;
    v17 = 1065353216;
    memset(&v18, 0, 0x40ui64);
    v18 = 1065353216;
    v19 = 1065353216;
    v20 = 1065353216;
    v21 = 1065353216;
    v22 = 0;
    v3->mGFxMovie.pObjectInterface->vfptr->GetDisplayInfo(
      v3->mGFxMovie.pObjectInterface,
      v3->mGFxMovie.mValue.pStringManaged,
      (Scaleform::GFx::Value::DisplayInfo *)&v13);
    v3->vfptr->getX(v3);
    v22 |= 1u;
    v13 = a3;
    v3->vfptr->getY(v3);
    v22 |= 2u;
    v14 = a3;
    v3->mGFxMovie.pObjectInterface->vfptr->SetDisplayInfo(
      v3->mGFxMovie.pObjectInterface,
      v3->mGFxMovie.mValue.pStringManaged,
      (Scaleform::GFx::Value::DisplayInfo *)&v13);
    v4 = v3->m_sHintTxt.mData;
    if ( v4 )
    {
      if ( *v4 == 36 )
        ++v4;
      v6 = (unsigned int)UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
      v7 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v7 || (v5 = (__int64)v7->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v6)) == 0 )
        v5 = (__int64)v4;
    }
    else
    {
      v5 = 0i64;
    }
    v9 = 0i64;
    v10 = 6;
    v11 = v5;
    v3->mGFxMovie.pObjectInterface->vfptr->Invoke(
      v3->mGFxMovie.pObjectInterface,
      v3->mGFxMovie.mValue.pStringManaged,
      0i64,
      "Show",
      (Scaleform::GFx::Value *)&v8,
      1ui64,
      (v3->mGFxMovie.Type & 0x8F) == 10);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC7346121,
        0i64,
        0,
        0i64);
    v3->m_eState = 2;
    if ( (v10 >> 6) & 1 )
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v9 + 16i64))(v9, &v8, v11);
  }
}

// File Line: 276
// RVA: 0x5C3B80
void __fastcall UFG::InfoFlasherRaidInfo::InfoFlasherRaidInfo(UFG::InfoFlasherRaidInfo *this, const char *caption, float duration, const char *rival_name, const char *icon_path)
{
  const char *v5; // rbx
  UFG::InfoFlasherRaidInfo *v6; // rdi

  v5 = rival_name;
  v6 = this;
  UFG::InfoFlasherBase::InfoFlasherBase((UFG::InfoFlasherBase *)&this->vfptr, caption, duration, 0, 3.0);
  v6->vfptr = (UFG::InfoFlasherBaseVtbl *)&UFG::InfoFlasherRaidInfo::`vftable';
  UFG::qString::qString(&v6->mRivalName, v5);
  UFG::qString::qString(&v6->mIconPath, icon_path);
}

// File Line: 280
// RVA: 0x63AD60
void __usercall UFG::InfoFlasherRaidInfo::show(UFG::InfoFlasherRaidInfo *this@<rcx>, Scaleform::GFx::Movie *movie@<rdx>, float a3@<xmm0>)
{
  UFG::InfoFlasherRaidInfo *v3; // rbx
  __int64 v4; // rdi
  __int64 v5; // rdi
  __int64 v6; // rdi
  bool v7; // ST30_1
  char ptr; // [rsp+40h] [rbp-B8h]
  __int64 v9; // [rsp+50h] [rbp-A8h]
  unsigned int v10; // [rsp+58h] [rbp-A0h]
  __int64 v11; // [rsp+60h] [rbp-98h]
  char v12; // [rsp+70h] [rbp-88h]
  __int64 v13; // [rsp+78h] [rbp-80h]
  unsigned int v14; // [rsp+80h] [rbp-78h]
  __int64 v15; // [rsp+88h] [rbp-70h]
  char v16; // [rsp+98h] [rbp-60h]
  __int64 v17; // [rsp+A8h] [rbp-50h]
  unsigned int v18; // [rsp+B0h] [rbp-48h]
  __int64 v19; // [rsp+B8h] [rbp-40h]
  __int64 v20; // [rsp+C8h] [rbp-30h]
  double v21; // [rsp+D8h] [rbp-20h]
  double v22; // [rsp+E0h] [rbp-18h]
  int Dst; // [rsp+138h] [rbp+40h]
  int v24; // [rsp+14Ch] [rbp+54h]
  int v25; // [rsp+160h] [rbp+68h]
  int v26; // [rsp+168h] [rbp+70h]
  int v27; // [rsp+17Ch] [rbp+84h]
  int v28; // [rsp+190h] [rbp+98h]
  int v29; // [rsp+1A4h] [rbp+ACh]
  __int16 v30; // [rsp+1ACh] [rbp+B4h]

  v20 = -2i64;
  v3 = this;
  if ( (this->mGFxMovie.Type & 0x8F) != 1 )
  {
    memset(&Dst, 0, 0x30ui64);
    Dst = 1065353216;
    v24 = 1065353216;
    v25 = 1065353216;
    memset(&v26, 0, 0x40ui64);
    v26 = 1065353216;
    v27 = 1065353216;
    v28 = 1065353216;
    v29 = 1065353216;
    v30 = 0;
    v3->mGFxMovie.pObjectInterface->vfptr->GetDisplayInfo(
      v3->mGFxMovie.pObjectInterface,
      v3->mGFxMovie.mValue.pStringManaged,
      (Scaleform::GFx::Value::DisplayInfo *)&v21);
    v3->vfptr->getX((UFG::InfoFlasherBase *)&v3->vfptr);
    v30 |= 1u;
    v21 = a3;
    v3->vfptr->getY((UFG::InfoFlasherBase *)&v3->vfptr);
    v30 |= 2u;
    v22 = a3;
    v3->mGFxMovie.pObjectInterface->vfptr->SetDisplayInfo(
      v3->mGFxMovie.pObjectInterface,
      v3->mGFxMovie.mValue.pStringManaged,
      (Scaleform::GFx::Value::DisplayInfo *)&v21);
    `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4 = (__int64)v3->m_sHintTxt.mData;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v11);
      v9 = 0i64;
    }
    v10 = 6;
    v11 = v4;
    v5 = (__int64)v3->mRivalName.mData;
    if ( (v14 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
      v13 = 0i64;
    }
    v14 = 6;
    v15 = v5;
    v6 = (__int64)v3->mIconPath.mData;
    if ( (v18 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
      v17 = 0i64;
    }
    v18 = 6;
    v19 = v6;
    v7 = (v3->mGFxMovie.Type & 0x8F) == 10;
    v3->mGFxMovie.pObjectInterface->vfptr->Invoke(
      v3->mGFxMovie.pObjectInterface,
      v3->mGFxMovie.mValue.pStringManaged,
      0i64,
      "Show",
      (Scaleform::GFx::Value *)&ptr,
      3ui64,
      v7);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC7346121,
        0i64,
        0,
        0i64);
    v3->m_eState = 2;
    `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

