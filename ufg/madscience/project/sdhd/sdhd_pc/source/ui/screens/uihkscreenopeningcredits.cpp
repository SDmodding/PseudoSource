// File Line: 28
// RVA: 0x5F4670
void __fastcall UFG::UIHKOpeningCreditsData::Populate(UFG::UIHKOpeningCreditsData *this, UFG::qPropertySet *data)
{
  UFG::UIHKOpeningCreditsData *v2; // rsi
  UFG::UIHKOpeningCreditsSection *v3; // rcx
  UFG::qPropertySet *v4; // rdi
  float *v5; // rbx
  unsigned int v6; // ebx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r14
  unsigned int v9; // edx
  unsigned int v10; // ebp
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ebx
  __int64 v15; // rdi
  char *v16; // rax
  UFG::qPropertySet *v17; // rdx

  v2 = this;
  v3 = this->Sections.p;
  v4 = data;
  if ( v3 )
  {
    v5 = &v3[-1].PosX;
    `eh vector destructor iterator(
      v3,
      0x48ui64,
      LODWORD(v3[-1].PosX),
      (void (__fastcall *)(void *))UFG::UIHKOpeningCreditsSection::~UIHKOpeningCreditsSection);
    operator delete[](v5);
  }
  v6 = 1;
  v2->Sections.p = 0i64;
  *(_QWORD *)&v2->Sections.size = 0i64;
  v7 = PropertyUtils::Get<UFG::qPropertyList>(v4, (UFG::qSymbol *)&UICreditsSymbol_section_list_0.mUID, DEPTH_RECURSE);
  v8 = v7;
  if ( v7 )
  {
    v9 = v2->Sections.size;
    v10 = v7->mNumElements;
    if ( (signed int)(v7->mNumElements - v2->Sections.size) <= 0 )
    {
      v13 = v2->Sections.size - v7->mNumElements;
      if ( v2->Sections.size != v7->mNumElements )
      {
        if ( v13 < v9 )
          v2->Sections.size = v9 - v13;
        else
          v2->Sections.size = 0;
      }
    }
    else
    {
      v11 = v7->mNumElements;
      v12 = v2->Sections.capacity;
      if ( v11 > v12 )
      {
        if ( v12 )
          v6 = 2 * v12;
        for ( ; v6 < v11; v6 *= 2 )
          ;
        if ( v6 - v11 > 0x10000 )
          v6 = v11 + 0x10000;
        UFG::qArray<UFG::UIHKOpeningCreditsSection,0>::Reallocate(&v2->Sections, v6, "Sections");
      }
      v2->Sections.size = v11;
    }
    v14 = 0;
    if ( v10 )
    {
      v15 = 0i64;
      do
      {
        v16 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v14);
        if ( !v16 || (v17 = (UFG::qPropertySet *)&v16[*(_QWORD *)v16], !*(_QWORD *)v16) )
          v17 = 0i64;
        UFG::UIHKOpeningCreditsSection::Populate(&v2->Sections.p[v15], v17);
        ++v14;
        ++v15;
      }
      while ( v14 < v10 );
    }
  }
}

// File Line: 60
// RVA: 0x5F47B0
void __fastcall UFG::UIHKOpeningCreditsSection::Populate(UFG::UIHKOpeningCreditsSection *this, UFG::qPropertySet *data)
{
  UFG::qPropertySet *v2; // rsi
  UFG::UIHKOpeningCreditsSection *v3; // rbp
  unsigned int v4; // edi
  char *v5; // rax
  UFG::qString *v6; // rcx
  unsigned int *v7; // rbx
  unsigned int v8; // ebx
  float *v9; // rax
  float v10; // xmm6_4
  float v11; // xmm0_4
  float *v12; // rax
  float v13; // xmm0_4
  float *v14; // rax
  float v15; // xmm0_4
  float *v16; // rax
  UFG::qPropertyList *v17; // rax
  unsigned int v18; // edx
  unsigned int v19; // er15
  UFG::qPropertyList *v20; // r13
  unsigned int v21; // esi
  unsigned int v22; // ecx
  __int64 v23; // rdi
  const char *v24; // rax

  v2 = data;
  v3 = this;
  v4 = 1;
  v5 = PropertyUtils::Get<char const *>(data, (UFG::qSymbol *)&UICreditsSymbol_heading_0.mUID, DEPTH_RECURSE);
  UFG::qString::Set(&v3->Heading, v5);
  v6 = v3->Names.p;
  if ( v6 )
  {
    v7 = &v6[-1].mStringHash32;
    `eh vector destructor iterator(
      v6,
      0x28ui64,
      v6[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v7);
  }
  v8 = 0;
  v3->Names.p = 0i64;
  *(_QWORD *)&v3->Names.size = 0i64;
  v9 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&UICreditsSymbol_start_time_0.mUID, DEPTH_RECURSE);
  v10 = 0.0;
  if ( v9 )
    v11 = *v9;
  else
    v11 = 0.0;
  v3->StartTime = v11;
  v12 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&UICreditsSymbol_duration_0.mUID, DEPTH_RECURSE);
  if ( v12 )
    v13 = *v12;
  else
    v13 = 0.0;
  v3->Duration = v13;
  v14 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&UICreditsSymbol_pos_x_0.mUID, DEPTH_RECURSE);
  if ( v14 )
    v15 = *v14;
  else
    v15 = 0.0;
  v3->PosX = v15;
  v16 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&UICreditsSymbol_pos_y_0.mUID, DEPTH_RECURSE);
  if ( v16 )
    v10 = *v16;
  v3->PosY = v10;
  v17 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v2,
          (UFG::qSymbol *)&UICreditsSymbol_names_list_0.mUID,
          DEPTH_RECURSE);
  v18 = v3->Names.size;
  v19 = v17->mNumElements;
  v20 = v17;
  if ( (signed int)(v17->mNumElements - v18) <= 0 )
  {
    if ( v18 != v17->mNumElements )
    {
      if ( v18 - v17->mNumElements < v18 )
        v3->Names.size = v17->mNumElements;
      else
        v3->Names.size = 0;
    }
  }
  else
  {
    v21 = v17->mNumElements;
    v22 = v3->Names.capacity;
    if ( v21 > v22 )
    {
      if ( v22 )
        v4 = 2 * v22;
      for ( ; v4 < v21; v4 *= 2 )
        ;
      if ( v4 - v21 > 0x10000 )
        v4 = v21 + 0x10000;
      UFG::qArray<UFG::qString,0>::Reallocate(&v3->Names, v4, "Names");
    }
    v3->Names.size = v21;
  }
  if ( v19 )
  {
    v23 = 0i64;
    do
    {
      v24 = UFG::qPropertyList::Get<char const *>(v20, v8);
      UFG::qString::Set(&v3->Names.p[v23], v24);
      ++v8;
      ++v23;
    }
    while ( v8 < v19 );
  }
}

// File Line: 103
// RVA: 0x5C6330
void __fastcall UFG::UIHKScreenOpeningCredits::UIHKScreenOpeningCredits(UFG::UIHKScreenOpeningCredits *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax
  UFG::UIHKOpeningCreditsData *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOpeningCredits::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mCurrentSectionIndex = -1;
  this->mElapsedTotal = 0.0;
  v2 = &this->mData;
  v2->Sections.p = 0i64;
  *(_QWORD *)&v2->Sections.size = 0i64;
}

// File Line: 108
// RVA: 0x5CBAF0
void __fastcall UFG::UIHKScreenOpeningCredits::~UIHKScreenOpeningCredits(UFG::UIHKScreenOpeningCredits *this)
{
  UFG::UIHKScreenOpeningCredits *v1; // rsi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKOpeningCreditsSection *v3; // rcx
  char *v4; // rbx

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOpeningCredits::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "OpeningCredits");
  UFG::UIHKScreenOpeningCredits::gSequence = 0;
  v3 = v1->mData.Sections.p;
  if ( v3 )
  {
    v4 = (char *)&v3[-1].PosX;
    `eh vector destructor iterator(
      v3,
      0x48ui64,
      LODWORD(v3[-1].PosX),
      (void (__fastcall *)(void *))UFG::UIHKOpeningCreditsSection::~UIHKOpeningCreditsSection);
    operator delete[](v4);
  }
  v1->mData.Sections.p = 0i64;
  *(_QWORD *)&v1->mData.Sections.size = 0i64;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 116
// RVA: 0x633150
void __fastcall UFG::UIHKScreenOpeningCredits::init(UFG::UIHKScreenOpeningCredits *this, UFG::UICommandData *data)
{
  UFG::UIHKOpeningCreditsData *v2; // rbx
  char *v3; // rcx
  const char *v4; // rdx
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qSymbol result; // [rsp+20h] [rbp-18h]
  char v8; // [rsp+40h] [rbp+8h]
  char v9; // [rsp+50h] [rbp+18h]
  char v10; // [rsp+58h] [rbp+20h]

  v2 = (UFG::UIHKOpeningCreditsData *)this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  switch ( UFG::UIHKScreenOpeningCredits::gSequence )
  {
    case 1u:
      v3 = (char *)&result;
      break;
    case 2u:
      v4 = "UI-OpeningCredits2";
      v3 = &v10;
      goto LABEL_9;
    case 3u:
      v4 = "UI-OpeningCredits3";
      v3 = &v9;
      goto LABEL_9;
    default:
      v3 = &v8;
      break;
  }
  v4 = "UI-OpeningCredits1";
LABEL_9:
  v5 = UFG::qSymbol::create_from_string((UFG::qSymbol *)v3, v4);
  v6 = UFG::PropertySetManager::GetPropertySet(v5);
  if ( v6 )
    UFG::UIHKOpeningCreditsData::Populate(v2 + 10, v6);
  v2[9].Sections.size = 1;
}

// File Line: 132
// RVA: 0x63E400
void __fastcall UFG::UIHKScreenOpeningCredits::update(UFG::UIHKScreenOpeningCredits *this, float elapsed)
{
  UFG::UIHKScreenOpeningCredits *v2; // rbx
  float v3; // xmm6_4
  UFG::UIHKScreenOpeningCredits::eState v4; // ecx
  int v5; // ecx
  __int64 v6; // rax
  __int64 v7; // rax
  UFG::UIHKOpeningCreditsSection *v8; // rdx

  v2 = this;
  if ( this->mState != 3 )
  {
    UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
    if ( v2->mState == 4 || NISManager::GetInstance()->mState == 4 )
    {
      v3 = elapsed + v2->mElapsedTotal;
      v4 = v2->mState;
      v2->mElapsedTotal = v3;
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v6 = (unsigned int)v2->mCurrentSectionIndex;
          if ( (unsigned int)v6 < v2->mData.Sections.size
            && (signed int)v6 >= 0
            && v3 > (float)(v2->mData.Sections.p[v6].Duration + v2->mData.Sections.p[v6].StartTime) )
          {
            UFG::UIHKScreenOpeningCredits::Flash_Hide(v2);
            v2->mState = 1;
          }
        }
      }
      else
      {
        v7 = (unsigned int)(v2->mCurrentSectionIndex + 1);
        if ( (unsigned int)v7 < v2->mData.Sections.size && (signed int)v7 >= 0 )
        {
          v8 = &v2->mData.Sections.p[v7];
          if ( v3 > v8->StartTime )
          {
            UFG::UIHKScreenOpeningCredits::ShowSection(v2, v8);
            ++v2->mCurrentSectionIndex;
            v2->mState = 2;
          }
        }
      }
    }
    else
    {
      UFG::UIScreenManagerBase::queuePopOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v2->mScreenUID);
      v2->mState = 4;
    }
  }
}

// File Line: 195
// RVA: 0x625D60
bool __fastcall UFG::UIHKScreenOpeningCredits::handleMessage(UFG::UIHKScreenOpeningCredits *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIHKScreenOpeningCredits *v5; // rbx
  UFG::UIHKScreenOpeningCredits::eState v6; // eax
  unsigned int v7; // eax

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_GAME_PAUSE_20 )
  {
    v6 = this->mState;
    this->mState = 3;
    this->mPrePauseState = v6;
    this->mRenderable->m_shouldRender = 0;
  }
  else if ( msgId == UI_HASH_GAME_UNPAUSE_20 && this->mState == 3 )
  {
    this->mState = this->mPrePauseState;
    this->mRenderable->m_shouldRender = 1;
  }
  if ( this->mState == 1 && msgId == UI_HASH_WIDGET_FADE_OUT_20 )
  {
    v7 = this->mCurrentSectionIndex + 1;
    if ( v7 >= this->mData.Sections.size || (v7 & 0x80000000) != 0 )
    {
      UFG::UIScreenManagerBase::queuePopOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        this->mScreenUID);
      v5->mState = 4;
    }
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 259
// RVA: 0x611160
void __fastcall UFG::UIHKScreenOpeningCredits::ShowSection(UFG::UIHKScreenOpeningCredits *this, UFG::UIHKOpeningCreditsSection *section)
{
  UFG::UIHKScreenOpeningCredits *v2; // rbp
  UFG::UIHKOpeningCreditsSection *v3; // r14
  unsigned int v4; // eax
  __int64 v5; // rdi
  __int64 v6; // rsi
  const char *v7; // rbx
  const char *v8; // rax
  unsigned int v9; // eax
  UFG::UIGfxTranslator *v10; // rcx

  v2 = this;
  v3 = section;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "ClearNames", 0i64, 0i64, 0);
  UFG::UIHKScreenOpeningCredits::Flash_SetPosition(v2, v3->PosX, v3->PosY);
  v4 = v3->Names.size;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4;
    do
    {
      v7 = v3->Names.p[v5].mData;
      if ( v7 )
      {
        if ( *v7 == 36 )
          ++v7;
        v9 = UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
        v10 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v10
          || (v8 = (const char *)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v9)) == 0i64 )
        {
          v8 = v7;
        }
      }
      else
      {
        v8 = 0i64;
      }
      UFG::UIHKScreenOpeningCredits::Flash_AddName((UFG::UIScreenCredits *)v2, v8);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "Animate_Text", 0i64, 0i64, 0);
}

// File Line: 284
// RVA: 0x5DA1A0
void __fastcall UFG::UIHKScreenOpeningCredits::Flash_AddName(UFG::UIScreenCredits *this, const char *name)
{
  const char *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = name;
  v3 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = v2;
  Scaleform::GFx::Movie::Invoke(v3, "AddName", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 296
// RVA: 0x5E0700
void __fastcall UFG::UIHKScreenOpeningCredits::Flash_SetPosition(UFG::UIHKScreenOpeningCredits *this, float pos_x, float pos_y)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v6 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
    v5 = 0i64;
  }
  v6 = 5;
  v7 = pos_x;
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = pos_y;
  Scaleform::GFx::Movie::Invoke(v3, "SetPosition", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 317
// RVA: 0x5DBA10
void __fastcall UFG::UIHKScreenOpeningCredits::Flash_Hide(UFG::UIHKScreenOpeningCredits *this)
{
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Hide", 0i64, 0i64, 0);
}

