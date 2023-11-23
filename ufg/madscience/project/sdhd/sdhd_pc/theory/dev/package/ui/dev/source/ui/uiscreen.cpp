// File Line: 21
// RVA: 0x15AB470
__int64 UFG::_dynamic_initializer_for__UI_HASH_INIT_SCREEN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("INIT_SCREEN", -1);
  UI_HASH_INIT_SCREEN = result;
  return result;
}

// File Line: 22
// RVA: 0x15AB0D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_DESTROY_SCREEN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DESTROY_SCREEN", -1);
  UI_HASH_DESTROY_SCREEN = result;
  return result;
}

// File Line: 33
// RVA: 0xA23DA0
void __fastcall UFG::UIScreen::~UIScreen(UFG::UIScreen *this)
{
  UFG::UIScreenManager *v2; // rcx
  void (__fastcall *m_audioCallback)(const char *, unsigned int, unsigned int, unsigned int); // rax
  UFG::UIScreenRenderable *mRenderable; // rdx
  UFG::UIScreenRenderable *v5; // rcx
  UFG::qThread *mLoadThread; // rcx
  UFG::qThread *v7; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mPrev; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mNext; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  v2 = UFG::UIScreenManager::s_instance;
  m_audioCallback = UFG::UIScreenManager::s_instance->m_audioCallback;
  if ( m_audioCallback )
  {
    ((void (__fastcall *)(char *, _QWORD, _QWORD, _QWORD, __int64))m_audioCallback)(
      this->m_screenName,
      this->m_screenNameHash,
      UI_HASH_DESTROY_SCREEN,
      0i64,
      -2i64);
    v2 = UFG::UIScreenManager::s_instance;
  }
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    UFG::UIScreenManagerBase::killTweens(v2, mRenderable->m_movie.pObject);
    v5 = this->mRenderable;
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    this->mRenderable = 0i64;
  }
  if ( UFG::gEnableUIAsyncLoad )
  {
    mLoadThread = this->mLoadThread;
    if ( mLoadThread )
    {
      UFG::qThread::WaitForCompletion(mLoadThread);
      UFG::qThread::Stop(this->mLoadThread);
      v7 = this->mLoadThread;
      if ( v7 )
      {
        _((AMD_HD3D *)this->mLoadThread);
        operator delete[](v7);
      }
      this->mLoadThread = 0i64;
    }
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
}

// File Line: 61
// RVA: 0xA27C80
void __fastcall UFG::UIScreen::LoadThread(UFG::UIScreenRenderable *obj)
{
  if ( obj )
    UFG::UIScreenRenderable::Load(obj);
}

// File Line: 86
// RVA: 0xA303E0
void __fastcall UFG::UIScreen::load(UFG::UIScreen *this, UFG::UIScreenRenderable *renderable)
{
  UFG::qString *FilenameWithoutExtension; // rax
  UFG::qThread *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::qThread *v7; // rax
  UFG::qString v8; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  this->mRenderable = renderable;
  UFG::qString::qString(&v8, renderable->m_fileName);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v8, &result);
  v5 = 0i64;
  UFG::qString::Set(&v8, FilenameWithoutExtension->mData, FilenameWithoutExtension->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qStringCopy(this->m_screenName, 64, v8.mData, v8.mLength);
  this->m_screenNameHash = UFG::qStringHashUpper32(this->m_screenName, -1);
  if ( UFG::gEnableUIAsyncLoad )
  {
    v6 = UFG::qMalloc(0x40ui64, "UIScreen::load", 0i64);
    if ( v6 )
    {
      UFG::qThread::qThread((UFG::qThread *)v6, "UIScreenRenderable");
      v5 = v7;
    }
    this->mLoadThread = v5;
    if ( v5 )
      UFG::qThread::Start(v5, (void (__fastcall *)(void *))UFG::UIScreen::LoadThread, this->mRenderable);
  }
  else
  {
    UFG::UIScreenRenderable::Load(renderable);
  }
  UFG::qString::~qString(&v8);
}

// File Line: 111
// RVA: 0xA2B980
Scaleform::RefCountImplCoreVtbl *__fastcall UFG::UIScreen::getMovieSafe(UFG::UIScreen *this)
{
  Scaleform::RefCountImplCoreVtbl *result; // rax

  result = (Scaleform::RefCountImplCoreVtbl *)this->mRenderable;
  if ( result )
    return (Scaleform::RefCountImplCoreVtbl *)result[40].__vecDelDtor;
  return result;
}

// File Line: 134
// RVA: 0xA2FD50
void __fastcall UFG::UIScreen::init(UFG::UIScreen *this, UFG::UICommandData *data)
{
  float v2; // xmm0_4
  void (__fastcall *m_audioCallback)(const char *, unsigned int, unsigned int, unsigned int); // r10
  UFG::qThread *mLoadThread; // rcx
  UFG::qThread *v6; // rdi

  m_audioCallback = UFG::UIScreenManager::s_instance->m_audioCallback;
  if ( m_audioCallback )
    m_audioCallback(this->m_screenName, this->m_screenNameHash, UI_HASH_INIT_SCREEN, 0);
  if ( UFG::gEnableUIAsyncLoad )
  {
    mLoadThread = this->mLoadThread;
    if ( mLoadThread )
    {
      UFG::qThread::WaitForCompletion(mLoadThread);
      UFG::qThread::Stop(this->mLoadThread);
      v6 = this->mLoadThread;
      if ( v6 )
      {
        _((AMD_HD3D *)this->mLoadThread);
        operator delete[](v6);
      }
      this->mLoadThread = 0i64;
    }
  }
  if ( UFG::UIScreen::mInitCallback )
    UFG::UIScreen::mInitCallback(this);
  UFG::UIScreen::updateViewportScale(this, v2);
}

// File Line: 180
// RVA: 0xA2AC60
void __fastcall UFG::UIScreen::dim(UFG::UIScreen *this, UFG::UIScreen::eDimType dimType, bool instant)
{
  int v6; // edi
  int v7; // edi
  int v8; // edi
  float v9; // xmm0_4

  UFG::qPrintf("*** %s.dim(%d)\n", this->m_screenName, (unsigned int)dimType);
  this->mDimType = dimType;
  this->mCurDimDirection = -200.0;
  if ( instant )
  {
    v6 = dimType - 1;
    if ( !v6 )
    {
      v9 = 0.0;
      goto LABEL_10;
    }
    v7 = v6 - 1;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( !v8 )
      {
        v9 = FLOAT_50_0;
        goto LABEL_10;
      }
      if ( v8 == 1 )
      {
        v9 = FLOAT_10_0;
LABEL_10:
        this->mCurDimValue = v9;
        return;
      }
    }
    v9 = FLOAT_100_0;
    goto LABEL_10;
  }
}

// File Line: 200
// RVA: 0xA32440
void __fastcall UFG::UIScreen::undim(UFG::UIScreen *this, bool instant)
{
  this->mCurDimDirection = 200.0;
  if ( instant )
    this->mCurDimValue = 100.0;
}

// File Line: 216
// RVA: 0xA301B0
void __fastcall UFG::UIScreen::intro(UFG::UIScreen *this, const char *fromScreen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_String;
  pargs.mValue.pString = fromScreen;
  pObject = this->mRenderable->m_movie.pObject;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(pObject) == 1 )
    Scaleform::GFx::Movie::Invoke(pObject, "intro", 0i64, &pargs, 1u);
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(pObject) == 2 )
    Scaleform::GFx::Movie::Invoke(pObject, "root.intro", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 239
// RVA: 0xA30650
void __fastcall UFG::UIScreen::outro(UFG::UIScreen *this, const char *toScreen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  --this->mInputEnabled;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_String;
  pargs.mValue.pString = toScreen;
  pObject = this->mRenderable->m_movie.pObject;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(pObject) == 1 )
    Scaleform::GFx::Movie::Invoke(pObject, "outro", 0i64, &pargs, 1u);
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(pObject) == 2 )
    Scaleform::GFx::Movie::Invoke(pObject, "root.outro", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 264
// RVA: 0xA32660
void __fastcall UFG::UIScreen::update(UFG::UIScreen *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rdi
  float mCurDimDirection; // xmm4_4
  float v5; // xmm2_4
  __int32 v6; // ecx
  __int32 v7; // ecx
  __int32 v8; // ecx
  float v9; // xmm0_4
  bool v10; // cf
  unsigned int v11; // edx
  long double mCurDimValue; // xmm0_8
  const char *v13; // rdx
  long double v14; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  mCurDimDirection = this->mCurDimDirection;
  if ( mCurDimDirection == 0.0 )
    return;
  v5 = (float)(mCurDimDirection * elapsed) + this->mCurDimValue;
  this->mCurDimValue = v5;
  v6 = this->mDimType - 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( !v7 )
    {
LABEL_6:
      v9 = FLOAT_100_0;
      goto LABEL_10;
    }
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 != 1 )
        goto LABEL_6;
      v9 = FLOAT_10_0;
    }
    else
    {
      v9 = FLOAT_50_0;
    }
  }
  else
  {
    v9 = 0.0;
  }
LABEL_10:
  v10 = mCurDimDirection < 0.0;
  if ( mCurDimDirection > 0.0 )
  {
    if ( v5 >= 100.0 )
    {
      *(_QWORD *)&this->mCurDimValue = 1120403456i64;
      this->mDimType = eDIM_INVALID;
      v11 = UI_HASH_UNDIM_COMPLETE_35;
LABEL_17:
      UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v11, this->mScreenUID);
      goto LABEL_18;
    }
    v10 = mCurDimDirection < 0.0;
  }
  if ( v10 && v5 <= v9 )
  {
    this->mCurDimDirection = 0.0;
    this->mCurDimValue = v9;
    v11 = UI_HASH_DIM_COMPLETE_35;
    goto LABEL_17;
  }
LABEL_18:
  mCurDimValue = this->mCurDimValue;
  value.pObjectInterface = 0i64;
  value.Type = VT_Number;
  value.mValue.NValue = mCurDimValue;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(pObject) == 1 )
  {
    v13 = "_alpha";
  }
  else
  {
    v14 = (float)(this->mCurDimValue * 0.0099999998);
    value.Type = VT_Number;
    value.mValue.NValue = v14;
    v13 = "root.alpha";
  }
  Scaleform::GFx::Movie::SetVariable(pObject, v13, &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 325
// RVA: 0xA2F130
void __fastcall UFG::UIScreen::handleInput(UFG::UIScreen *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIScreenRenderable *mRenderable; // r9
  __m128i v5; // xmm0
  __m128i v6; // xmm1
  int v7; // ecx
  unsigned int v8; // r8d
  __m128i v9; // xmm0
  __m128i v10; // xmm1
  int v11; // [rsp+20h] [rbp-20h] BYREF
  char v12; // [rsp+24h] [rbp-1Ch]
  unsigned int v13; // [rsp+28h] [rbp-18h]
  unsigned int v14; // [rsp+2Ch] [rbp-14h]
  int v15; // [rsp+30h] [rbp-10h]
  __int64 v16; // [rsp+34h] [rbp-Ch]

  mRenderable = this->mRenderable;
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_35 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_35 )
  {
    v13 = 38;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_35 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_35 )
  {
    v13 = 40;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_35 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_35 )
  {
    v13 = 37;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_35 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_35 )
  {
    v13 = 39;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_35 )
  {
    v13 = 32;
LABEL_57:
    v11 = 5;
    LOBYTE(v16) = 0;
    v15 = 0;
    LOBYTE(v14) = 0;
    goto LABEL_58;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_35 )
  {
    v13 = 8;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_35 )
  {
    v13 = 100;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_BUTTON2_PRESSED_35 )
  {
    v13 = 102;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_START_PRESSED_35 )
  {
    v13 = 111;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_SELECT_PRESSED_35 )
  {
    v13 = 106;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_L1_PRESSED_35 )
  {
    v13 = 97;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_L2_PRESSED_35 )
  {
    v13 = 103;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_L3_PRESSED_35 )
  {
    v13 = 109;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_35 )
  {
    v13 = 99;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_R2_PRESSED_35 )
  {
    v13 = 105;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_BUTTON_R3_PRESSED_35 )
  {
    v13 = 107;
    goto LABEL_57;
  }
  if ( msgId == UI_HASH_MOUSE_MOVE_35 )
  {
    v5 = _mm_cvtsi32_si128(HIDWORD(msg[1].mPrev));
    v6 = _mm_cvtsi32_si128((unsigned int)msg[1].mNext);
    v11 = 1;
    v16 = 0i64;
    v13 = _mm_cvtepi32_ps(v5).m128_u32[0];
    v14 = _mm_cvtepi32_ps(v6).m128_u32[0];
    v15 = 0;
LABEL_58:
    v12 = 0;
    goto LABEL_59;
  }
  if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_35
    || msgId == UI_HASH_MOUSE_BUTTON_LEFT_RELEASED_35
    || msgId == UI_HASH_MOUSE_BUTTON_RIGHT_PRESSED_35
    || msgId == UI_HASH_MOUSE_BUTTON_RIGHT_RELEASED_35
    || msgId == UI_HASH_MOUSE_BUTTON_MIDDLE_PRESSED_35
    || msgId == UI_HASH_MOUSE_BUTTON_MIDDLE_RELEASED_35 )
  {
    v7 = 2;
    v8 = 0;
    if ( msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_35 )
    {
      if ( msgId != UI_HASH_MOUSE_BUTTON_LEFT_RELEASED_35 )
      {
        if ( msgId == UI_HASH_MOUSE_BUTTON_RIGHT_PRESSED_35 )
        {
          v8 = 1;
          goto LABEL_52;
        }
        if ( msgId == UI_HASH_MOUSE_BUTTON_RIGHT_RELEASED_35 )
        {
          v8 = 1;
        }
        else
        {
          if ( msgId == UI_HASH_MOUSE_BUTTON_MIDDLE_PRESSED_35 )
          {
            v8 = 2;
            goto LABEL_52;
          }
          if ( msgId != UI_HASH_MOUSE_BUTTON_MIDDLE_RELEASED_35 )
            goto LABEL_52;
          v8 = 2;
        }
      }
      v7 = 3;
    }
LABEL_52:
    v9 = _mm_cvtsi32_si128(HIDWORD(msg[1].mPrev));
    v10 = _mm_cvtsi32_si128((unsigned int)msg[1].mNext);
    v12 = 0;
    v11 = v7;
    v16 = v8;
    v13 = _mm_cvtepi32_ps(v9).m128_u32[0];
    v14 = _mm_cvtepi32_ps(v10).m128_u32[0];
    v15 = 0;
LABEL_59:
    mRenderable->m_movie.pObject->vfptr[35].__vecDelDtor(mRenderable->m_movie.pObject, (unsigned int)&v11);
  }
}_ps(v10).m128_u32[0];
    v15 = 0;
LABEL_59:
    mRenderable->m_movie.pObject->vfptr[35].__vecDelDtor(mRenderable->m_movi

// File Line: 451
// RVA: 0xA2F4D0
char __fastcall UFG::UIScreen::handleMessage(UFG::UIScreen *this, unsigned int msgId, UFG::UIMessage *msg)
{
  if ( msgId == UI_HASH_ENABLE_INPUT_35 )
    goto LABEL_2;
  if ( msgId == UI_HASH_DISABLE_INPUT_35 )
  {
    --this->mInputEnabled;
    return 1;
  }
  else
  {
    if ( msgId == UI_HASH_INTRO_COMPLETE_35 )
    {
LABEL_2:
      ++this->mInputEnabled;
      return 1;
    }
    return 0;
  }
}

// File Line: 475
// RVA: 0xA302B0
char __fastcall UFG::UIScreen::invoke(UFG::UIScreen *this, const char *funcName)
{
  Scaleform::GFx::Movie *pObject; // rcx
  char v4; // bl
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0;
  presult.pObjectInterface = 0i64;
  presult.Type = VT_Undefined;
  v4 = Scaleform::GFx::Movie::Invoke(pObject, funcName, &presult, 0i64, 0);
  if ( (presult.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&presult.pObjectInterface->vfptr->gap8[8])(
      presult.pObjectInterface,
      &presult,
      presult.mValue);
    presult.pObjectInterface = 0i64;
  }
  return v4;
}

// File Line: 510
// RVA: 0xA33270
void __fastcall UFG::UIScreen::updateViewportScale(UFG::UIScreen *this)
{
  Scaleform::GFx::Movie *pObject; // rsi
  int AVMVersion; // eax
  const char *v3; // r8
  __int64 v4; // rbx
  __int64 v5; // rdi
  double v6; // xmm0_8
  float v7; // xmm8_4
  __int64 v8; // rbx
  __int64 v9; // rdi
  double v10; // xmm0_8
  float v11; // xmm7_4
  Scaleform::GFx::Value pval; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v13; // [rsp+50h] [rbp-A8h]
  __int64 v14[25]; // [rsp+60h] [rbp-98h] BYREF
  __int16 v15; // [rsp+12Ch] [rbp+34h]

  v13 = -2i64;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  pObject = this->mRenderable->m_movie.pObject;
  AVMVersion = Scaleform::GFx::Movie::GetAVMVersion(pObject);
  v3 = aRoo;
  if ( AVMVersion != 1 )
    v3 = "root";
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, v3);
  if ( (pval.Type & 0x8Fu) > 1 )
  {
    v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(pObject);
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(pObject);
    v6 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v4 + 48i64))(v4);
    v7 = (float)(*(float *)&v6
               - (float)((*(float (__fastcall **)(__int64))(*(_QWORD *)v5 + 48i64))(v5) * UFG::gUIViewportScale))
       * 0.5;
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(pObject);
    v9 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(pObject);
    v10 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v8 + 56i64))(v8);
    v11 = (float)(*(float *)&v10
                - (float)((*(float (__fastcall **)(__int64))(*(_QWORD *)v9 + 56i64))(v9) * UFG::gUIViewportScale))
        * 0.5;
    memset(&v14[11], 0, 112);
    LODWORD(v14[11]) = 1065353216;
    HIDWORD(v14[13]) = 1065353216;
    LODWORD(v14[16]) = 1065353216;
    LODWORD(v14[17]) = 1065353216;
    HIDWORD(v14[19]) = 1065353216;
    LODWORD(v14[22]) = 1065353216;
    HIDWORD(v14[24]) = 1065353216;
    v15 = 0;
    pval.pObjectInterface->vfptr->GetDisplayInfo(
      pval.pObjectInterface,
      (void *)pval.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v14);
    *(double *)&v14[3] = (float)(UFG::gUIViewportScale * 100.0);
    *(double *)v14 = v7;
    v15 |= 0x1Bu;
    *(double *)&v14[1] = v11;
    pval.pObjectInterface->vfptr->SetDisplayInfo(
      pval.pObjectInterface,
      (void *)pval.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v14);
  }
  if ( (pval.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
}

