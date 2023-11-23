// File Line: 28
// RVA: 0x5F4670
void __fastcall UFG::UIHKOpeningCreditsData::Populate(UFG::UIHKOpeningCreditsData *this, UFG::qPropertySet *data)
{
  UFG::UIHKOpeningCreditsSection *p; // rcx
  float *p_PosX; // rbx
  unsigned int v6; // ebx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r14
  unsigned int size; // edx
  unsigned int mNumElements; // ebp
  unsigned int v11; // edi
  unsigned int capacity; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ebx
  __int64 v15; // rdi
  char *ValuePtr; // rax
  UFG::qPropertySet *v17; // rdx

  p = this->Sections.p;
  if ( p )
  {
    p_PosX = &p[-1].PosX;
    `eh vector destructor iterator(
      p,
      0x48ui64,
      LODWORD(p[-1].PosX),
      (void (__fastcall *)(void *))UFG::UIHKOpeningCreditsSection::~UIHKOpeningCreditsSection);
    operator delete[](p_PosX);
  }
  v6 = 1;
  this->Sections.p = 0i64;
  *(_QWORD *)&this->Sections.size = 0i64;
  v7 = PropertyUtils::Get<UFG::qPropertyList>(
         data,
         (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_section_list_0,
         DEPTH_RECURSE);
  v8 = v7;
  if ( v7 )
  {
    size = this->Sections.size;
    mNumElements = v7->mNumElements;
    if ( (int)(mNumElements - this->Sections.size) <= 0 )
    {
      v13 = this->Sections.size - v7->mNumElements;
      if ( v13 )
      {
        if ( v13 < size )
          this->Sections.size = size - v13;
        else
          this->Sections.size = 0;
      }
    }
    else
    {
      v11 = v7->mNumElements;
      capacity = this->Sections.capacity;
      if ( v11 > capacity )
      {
        if ( capacity )
          v6 = 2 * capacity;
        for ( ; v6 < v11; v6 *= 2 )
          ;
        if ( v6 - v11 > 0x10000 )
          v6 = v11 + 0x10000;
        UFG::qArray<UFG::UIHKOpeningCreditsSection,0>::Reallocate(&this->Sections, v6, "Sections");
      }
      this->Sections.size = v11;
    }
    v14 = 0;
    if ( mNumElements )
    {
      v15 = 0i64;
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v14);
        if ( !ValuePtr || (v17 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
          v17 = 0i64;
        UFG::UIHKOpeningCreditsSection::Populate(&this->Sections.p[v15], v17);
        ++v14;
        ++v15;
      }
      while ( v14 < mNumElements );
    }
  }
}

// File Line: 60
// RVA: 0x5F47B0
void __fastcall UFG::UIHKOpeningCreditsSection::Populate(UFG::UIHKOpeningCreditsSection *this, UFG::qPropertySet *data)
{
  unsigned int v4; // edi
  char *v5; // rax
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
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
  unsigned int size; // edx
  unsigned int mNumElements; // r15d
  UFG::qPropertyList *v20; // r13
  unsigned int v21; // esi
  unsigned int capacity; // ecx
  unsigned int v23; // ecx
  __int64 v24; // rdi
  const char *v25; // rax

  v4 = 1;
  v5 = PropertyUtils::Get<char const *>(data, (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_heading_0, DEPTH_RECURSE);
  UFG::qString::Set(&this->Heading, v5);
  p = this->Names.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mStringHash32;
    `eh vector destructor iterator(
      p,
      0x28ui64,
      p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  v8 = 0;
  this->Names.p = 0i64;
  *(_QWORD *)&this->Names.size = 0i64;
  v9 = UFG::qPropertySet::Get<float>(data, (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_start_time_0, DEPTH_RECURSE);
  v10 = 0.0;
  if ( v9 )
    v11 = *v9;
  else
    v11 = 0.0;
  this->StartTime = v11;
  v12 = UFG::qPropertySet::Get<float>(data, (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_duration_0, DEPTH_RECURSE);
  if ( v12 )
    v13 = *v12;
  else
    v13 = 0.0;
  this->Duration = v13;
  v14 = UFG::qPropertySet::Get<float>(data, (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_pos_x_0, DEPTH_RECURSE);
  if ( v14 )
    v15 = *v14;
  else
    v15 = 0.0;
  this->PosX = v15;
  v16 = UFG::qPropertySet::Get<float>(data, (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_pos_y_0, DEPTH_RECURSE);
  if ( v16 )
    v10 = *v16;
  this->PosY = v10;
  v17 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          data,
          (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_names_list_0,
          DEPTH_RECURSE);
  size = this->Names.size;
  mNumElements = v17->mNumElements;
  v20 = v17;
  if ( (int)(mNumElements - size) <= 0 )
  {
    v23 = size - v17->mNumElements;
    if ( v23 )
    {
      if ( v23 < size )
        this->Names.size = v17->mNumElements;
      else
        this->Names.size = 0;
    }
  }
  else
  {
    v21 = v17->mNumElements;
    capacity = this->Names.capacity;
    if ( v21 > capacity )
    {
      if ( capacity )
        v4 = 2 * capacity;
      for ( ; v4 < v21; v4 *= 2 )
        ;
      if ( v4 - v21 > 0x10000 )
        v4 = v21 + 0x10000;
      UFG::qArray<UFG::qString,0>::Reallocate(&this->Names, v4, "Names");
    }
    this->Names.size = v21;
  }
  if ( mNumElements )
  {
    v24 = 0i64;
    do
    {
      v25 = UFG::qPropertyList::Get<char const *>(v20, v8);
      UFG::qString::Set(&this->Names.p[v24], v25);
      ++v8;
      ++v24;
    }
    while ( v8 < mNumElements );
  }
}

// File Line: 103
// RVA: 0x5C6330
void __fastcall UFG::UIHKScreenOpeningCredits::UIHKScreenOpeningCredits(UFG::UIHKScreenOpeningCredits *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOpeningCredits::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mCurrentSectionIndex = -1;
  this->mElapsedTotal = 0.0;
  this->mData.Sections.p = 0i64;
  *(_QWORD *)&this->mData.Sections.size = 0i64;
}

// File Line: 108
// RVA: 0x5CBAF0
void __fastcall UFG::UIHKScreenOpeningCredits::~UIHKScreenOpeningCredits(UFG::UIHKScreenOpeningCredits *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKOpeningCreditsSection *p; // rcx
  float *p_PosX; // rbx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOpeningCredits::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "OpeningCredits");
  UFG::UIHKScreenOpeningCredits::gSequence = 0;
  p = this->mData.Sections.p;
  if ( p )
  {
    p_PosX = &p[-1].PosX;
    `eh vector destructor iterator(
      p,
      0x48ui64,
      LODWORD(p[-1].PosX),
      (void (__fastcall *)(void *))UFG::UIHKOpeningCreditsSection::~UIHKOpeningCreditsSection);
    operator delete[](p_PosX);
  }
  this->mData.Sections.p = 0i64;
  *(_QWORD *)&this->mData.Sections.size = 0i64;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 116
// RVA: 0x633150
void __fastcall UFG::UIHKScreenOpeningCredits::init(UFG::UIHKScreenOpeningCredits *this, UFG::UICommandData *data)
{
  char *p_result; // rcx
  const char *v4; // rdx
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol result; // [rsp+20h] [rbp-18h] BYREF
  char v8; // [rsp+40h] [rbp+8h] BYREF
  char v9; // [rsp+50h] [rbp+18h] BYREF
  char v10; // [rsp+58h] [rbp+20h] BYREF

  UFG::UIScreen::init(this, data);
  switch ( UFG::UIHKScreenOpeningCredits::gSequence )
  {
    case 1u:
      p_result = (char *)&result;
      break;
    case 2u:
      v4 = "UI-OpeningCredits2";
      p_result = &v10;
      goto LABEL_9;
    case 3u:
      v4 = "UI-OpeningCredits3";
      p_result = &v9;
      goto LABEL_9;
    default:
      p_result = &v8;
      break;
  }
  v4 = "UI-OpeningCredits1";
LABEL_9:
  v5 = UFG::qSymbol::create_from_string((UFG::qSymbol *)p_result, v4);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v5);
  if ( PropertySet )
    UFG::UIHKOpeningCreditsData::Populate(&this->mData, PropertySet);
  this->mState = STATE_BRIGHTNESS;
}

// File Line: 132
// RVA: 0x63E400
void __fastcall UFG::UIHKScreenOpeningCredits::update(UFG::UIHKScreenOpeningCredits *this, float elapsed)
{
  float v3; // xmm6_4
  UFG::UIHKScreenOpeningCredits::eState mState; // ecx
  __int32 v5; // ecx
  __int64 mCurrentSectionIndex; // rax
  __int64 v7; // rax
  UFG::UIHKOpeningCreditsSection *v8; // rdx

  if ( this->mState != STATE_UISCALE )
  {
    UFG::UIScreen::update(this, elapsed);
    if ( this->mState == NUM_CALIBRATION_STATES || NISManager::GetInstance()->mState == STATE_INCOMPLETE )
    {
      v3 = elapsed + this->mElapsedTotal;
      mState = this->mState;
      this->mElapsedTotal = v3;
      v5 = mState - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          mCurrentSectionIndex = (unsigned int)this->mCurrentSectionIndex;
          if ( (unsigned int)mCurrentSectionIndex < this->mData.Sections.size
            && (int)mCurrentSectionIndex >= 0
            && v3 > (float)(this->mData.Sections.p[mCurrentSectionIndex].Duration
                          + this->mData.Sections.p[mCurrentSectionIndex].StartTime) )
          {
            UFG::UIHKScreenOpeningCredits::Flash_Hide(this);
            this->mState = STATE_BRIGHTNESS;
          }
        }
      }
      else
      {
        v7 = (unsigned int)(this->mCurrentSectionIndex + 1);
        if ( (unsigned int)v7 < this->mData.Sections.size && (int)v7 >= 0 )
        {
          v8 = &this->mData.Sections.p[v7];
          if ( v3 > v8->StartTime )
          {
            UFG::UIHKScreenOpeningCredits::ShowSection(this, v8);
            ++this->mCurrentSectionIndex;
            this->mState = STATE_VOLUME;
          }
        }
      }
    }
    else
    {
      UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, this->mScreenUID);
      this->mState = NUM_CALIBRATION_STATES;
    }
  }
}

// File Line: 195
// RVA: 0x625D60
bool __fastcall UFG::UIHKScreenOpeningCredits::handleMessage(
        UFG::UIHKScreenOpeningCredits *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIHKScreenOpeningCredits::eState mState; // eax
  signed int v7; // eax

  if ( msgId == UI_HASH_GAME_PAUSE_20 )
  {
    mState = this->mState;
    this->mState = STATE_UISCALE;
    this->mPrePauseState = mState;
    this->mRenderable->m_shouldRender = 0;
  }
  else if ( msgId == UI_HASH_GAME_UNPAUSE_20 && this->mState == STATE_UISCALE )
  {
    this->mState = this->mPrePauseState;
    this->mRenderable->m_shouldRender = 1;
  }
  if ( this->mState == STATE_BRIGHTNESS && msgId == UI_HASH_WIDGET_FADE_OUT_20 )
  {
    v7 = this->mCurrentSectionIndex + 1;
    if ( v7 >= this->mData.Sections.size || v7 < 0 )
    {
      UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, this->mScreenUID);
      this->mState = NUM_CALIBRATION_STATES;
    }
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 259
// RVA: 0x611160
void __fastcall UFG::UIHKScreenOpeningCredits::ShowSection(
        UFG::UIHKScreenOpeningCredits *this,
        UFG::UIHKOpeningCreditsSection *section)
{
  unsigned int size; // eax
  __int64 v5; // rdi
  __int64 v6; // rsi
  char *mData; // rbx
  const char *v8; // rax
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx

  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "ClearNames", 0i64, 0i64, 0);
  UFG::UIHKScreenOpeningCredits::Flash_SetPosition(this, section->PosX, section->PosY);
  size = section->Names.size;
  if ( size )
  {
    v5 = 0i64;
    v6 = size;
    do
    {
      mData = section->Names.p[v5].mData;
      if ( mData )
      {
        if ( *mData == 36 )
          ++mData;
        v9 = UFG::qStringHashUpper32(mData, -1);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( !m_translator || (v8 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
          v8 = mData;
      }
      else
      {
        v8 = 0i64;
      }
      UFG::UIHKScreenOpeningCredits::Flash_AddName((UFG::UIScreenCredits *)this, v8);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Animate_Text", 0i64, 0i64, 0);
}

// File Line: 284
// RVA: 0x5DA1A0
void __fastcall UFG::UIHKScreenOpeningCredits::Flash_AddName(UFG::UIScreenCredits *this, const char *name)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_String;
  pargs.mValue.pString = name;
  Scaleform::GFx::Movie::Invoke(pObject, "AddName", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 296
// RVA: 0x5E0700
void __fastcall UFG::UIHKScreenOpeningCredits::Flash_SetPosition(
        UFG::UIHKScreenOpeningCredits *this,
        float pos_x,
        float pos_y)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = pos_x;
  if ( (v7 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
    v6 = 0i64;
  }
  v7 = 5;
  v8 = pos_y;
  Scaleform::GFx::Movie::Invoke(pObject, "SetPosition", 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 317
// RVA: 0x5DBA10
void __fastcall UFG::UIHKScreenOpeningCredits::Flash_Hide(UFG::UIHKScreenOpeningCredits *this)
{
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Hide", 0i64, 0i64, 0);
}

