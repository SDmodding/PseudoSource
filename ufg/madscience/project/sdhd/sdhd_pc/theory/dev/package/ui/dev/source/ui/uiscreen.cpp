// File Line: 21
// RVA: 0x15AB470
__int64 UFG::_dynamic_initializer_for__UI_HASH_INIT_SCREEN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("INIT_SCREEN", 0xFFFFFFFF);
  UI_HASH_INIT_SCREEN = result;
  return result;
}

// File Line: 22
// RVA: 0x15AB0D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_DESTROY_SCREEN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DESTROY_SCREEN", 0xFFFFFFFF);
  UI_HASH_DESTROY_SCREEN = result;
  return result;
}

// File Line: 33
// RVA: 0xA23DA0
void __fastcall UFG::UIScreen::~UIScreen(UFG::UIScreen *this)
{
  UFG::UIScreen *v1; // rbx
  UFG::UIScreenManager *v2; // rcx
  void (__fastcall *v3)(const char *, unsigned int, unsigned int, unsigned int); // rax
  UFG::UIScreenRenderable *v4; // rdx
  UFG::UIScreenRenderable *v5; // rcx
  UFG::qThread *v6; // rcx
  UFG::qThread *v7; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v8; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v9; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  v2 = UFG::UIScreenManager::s_instance;
  v3 = UFG::UIScreenManager::s_instance->m_audioCallback;
  if ( v3 )
  {
    ((void (__fastcall *)(char *, _QWORD, _QWORD, _QWORD, signed __int64))v3)(
      v1->m_screenName,
      v1->m_screenNameHash,
      UI_HASH_DESTROY_SCREEN,
      0i64,
      -2i64);
    v2 = UFG::UIScreenManager::s_instance;
  }
  v4 = v1->mRenderable;
  if ( v4 )
  {
    UFG::UIScreenManagerBase::killTweens((UFG::UIScreenManagerBase *)&v2->vfptr, v4->m_movie.pObject);
    v5 = v1->mRenderable;
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    v1->mRenderable = 0i64;
  }
  if ( UFG::gEnableUIAsyncLoad )
  {
    v6 = v1->mLoadThread;
    if ( v6 )
    {
      UFG::qThread::WaitForCompletion(v6);
      UFG::qThread::Stop(v1->mLoadThread);
      v7 = v1->mLoadThread;
      if ( v7 )
      {
        _((AMD_HD3D *)v1->mLoadThread);
        operator delete[](v7);
      }
      v1->mLoadThread = 0i64;
    }
  }
  v8 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
}

// File Line: 61
// RVA: 0xA27C80
void __fastcall UFG::UIScreen::LoadThread(void *obj)
{
  JUMPOUT(obj, 0i64, UFG::UIScreenRenderable::Load);
}

// File Line: 86
// RVA: 0xA303E0
void __fastcall UFG::UIScreen::load(UFG::UIScreen *this, UFG::UIScreenRenderable *renderable)
{
  UFG::UIScreenRenderable *v2; // rbp
  UFG::UIScreen *v3; // rsi
  UFG::qString *v4; // rax
  UFG::qThread *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::qThread *v7; // rax
  UFG::qString v8; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v2 = renderable;
  v3 = this;
  this->mRenderable = renderable;
  UFG::qString::qString(&v8, renderable->m_fileName);
  v4 = UFG::qString::GetFilenameWithoutExtension(&v8, &result);
  v5 = 0i64;
  UFG::qString::Set(&v8, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qStringCopy(v3->m_screenName, 64, v8.mData, v8.mLength);
  v3->m_screenNameHash = UFG::qStringHashUpper32(v3->m_screenName, 0xFFFFFFFF);
  if ( UFG::gEnableUIAsyncLoad )
  {
    v6 = UFG::qMalloc(0x40ui64, "UIScreen::load", 0i64);
    if ( v6 )
    {
      UFG::qThread::qThread((UFG::qThread *)v6, "UIScreenRenderable");
      v5 = v7;
    }
    v3->mLoadThread = v5;
    if ( v5 )
      UFG::qThread::Start(v5, UFG::UIScreen::LoadThread, v3->mRenderable);
  }
  else
  {
    UFG::UIScreenRenderable::Load(v2);
  }
  UFG::qString::~qString(&v8);
}

// File Line: 111
// RVA: 0xA2B980
Scaleform::GFx::Movie *__fastcall UFG::UIScreen::getMovieSafe(UFG::UIScreen *this)
{
  Scaleform::GFx::Movie *result; // rax

  result = (Scaleform::GFx::Movie *)this->mRenderable;
  if ( result )
    result = (Scaleform::GFx::Movie *)result[10].vfptr;
  return result;
}

// File Line: 134
// RVA: 0xA2FD50
void __usercall UFG::UIScreen::init(UFG::UIScreen *this@<rcx>, UFG::UICommandData *data@<rdx>, float a3@<xmm0>)
{
  UFG::UIScreen *v3; // rbx
  void (__fastcall *v4)(const char *, unsigned int, unsigned int, unsigned int); // r10
  UFG::qThread *v5; // rcx
  UFG::qThread *v6; // rdi

  v3 = this;
  v4 = UFG::UIScreenManager::s_instance->m_audioCallback;
  if ( v4 )
    v4(this->m_screenName, this->m_screenNameHash, UI_HASH_INIT_SCREEN, 0);
  if ( UFG::gEnableUIAsyncLoad )
  {
    v5 = v3->mLoadThread;
    if ( v5 )
    {
      UFG::qThread::WaitForCompletion(v5);
      UFG::qThread::Stop(v3->mLoadThread);
      v6 = v3->mLoadThread;
      if ( v6 )
      {
        _((AMD_HD3D *)v3->mLoadThread);
        operator delete[](v6);
      }
      v3->mLoadThread = 0i64;
    }
  }
  if ( UFG::UIScreen::mInitCallback )
    UFG::UIScreen::mInitCallback(v3);
  UFG::UIScreen::updateViewportScale(v3, a3);
}

// File Line: 180
// RVA: 0xA2AC60
void __fastcall UFG::UIScreen::dim(UFG::UIScreen *this, UFG::UIScreen::eDimType dimType, bool instant)
{
  UFG::UIScreen::eDimType v3; // edi
  UFG::UIScreen *v4; // rsi
  bool v5; // bl
  int v6; // edi
  int v7; // edi
  int v8; // edi
  float v9; // xmm0_4

  v3 = dimType;
  v4 = this;
  v5 = instant;
  UFG::qPrintf("*** %s.dim(%d)\n", this->m_screenName, (unsigned int)dimType);
  v4->mDimType = v3;
  v4->mCurDimDirection = -200.0;
  if ( v5 )
  {
    v6 = v3 - 1;
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
        v4->mCurDimValue = v9;
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
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  pargs.pObjectInterface = 0i64;
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = fromScreen;
  v2 = this->mRenderable->m_movie.pObject;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v2) == 1 )
    Scaleform::GFx::Movie::Invoke(v2, "intro", 0i64, &pargs, 1u);
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v2) == 2 )
    Scaleform::GFx::Movie::Invoke(v2, "root.intro", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 239
// RVA: 0xA30650
void __fastcall UFG::UIScreen::outro(UFG::UIScreen *this, const char *toScreen)
{
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  --this->mInputEnabled;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = toScreen;
  v2 = this->mRenderable->m_movie.pObject;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v2) == 1 )
    Scaleform::GFx::Movie::Invoke(v2, "outro", 0i64, &pargs, 1u);
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v2) == 2 )
    Scaleform::GFx::Movie::Invoke(v2, "root.outro", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 264
// RVA: 0xA32660
void __fastcall UFG::UIScreen::update(UFG::UIScreen *this, float elapsed)
{
  UFG::UIScreen *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  float v4; // xmm4_4
  float v5; // xmm2_4
  __int32 v6; // ecx
  int v7; // ecx
  int v8; // ecx
  float v9; // xmm0_4
  bool v10; // cf
  unsigned int v11; // edx
  long double v12; // xmm0_8
  const char *v13; // rdx
  double v14; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h]

  v2 = this;
  v3 = this->mRenderable->m_movie.pObject;
  v4 = this->mCurDimDirection;
  if ( v4 == 0.0 )
    return;
  v5 = (float)(v4 * elapsed) + this->mCurDimValue;
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
  v10 = v4 < 0.0;
  if ( v4 > 0.0 )
  {
    if ( v5 >= 100.0 )
    {
      *(_QWORD *)&v2->mCurDimValue = 1120403456i64;
      v2->mDimType = 0;
      v11 = UI_HASH_UNDIM_COMPLETE_35;
      goto LABEL_17;
    }
    v10 = v4 < 0.0;
  }
  if ( !v10 || v5 > v9 )
    goto LABEL_18;
  v2->mCurDimDirection = 0.0;
  v2->mCurDimValue = v9;
  v11 = UI_HASH_DIM_COMPLETE_35;
LABEL_17:
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v11,
    v2->mScreenUID);
LABEL_18:
  v12 = v2->mCurDimValue;
  value.pObjectInterface = 0i64;
  value.Type = 5;
  value.mValue.NValue = v12;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v3) == 1 )
  {
    v13 = "_alpha";
  }
  else
  {
    v14 = (float)(v2->mCurDimValue * 0.0099999998);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 5;
    value.mValue.NValue = v14;
    v13 = "root.alpha";
  }
  Scaleform::GFx::Movie::SetVariable(v3, v13, &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 325
// RVA: 0xA2F130
void __fastcall UFG::UIScreen::handleInput(UFG::UIScreen *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIScreenRenderable *v3; // r9
  UFG::UIMessage *v4; // r15
  __m128i v5; // xmm0
  __m128i v6; // xmm1
  signed int v7; // ecx
  unsigned int v8; // er8
  __m128i v9; // xmm0
  __m128i v10; // xmm1
  int v11; // [rsp+20h] [rbp-20h]
  char v12; // [rsp+24h] [rbp-1Ch]
  int v13; // [rsp+28h] [rbp-18h]
  int v14; // [rsp+2Ch] [rbp-14h]
  int v15; // [rsp+30h] [rbp-10h]
  __int64 v16; // [rsp+34h] [rbp-Ch]

  v3 = this->mRenderable;
  v4 = msg;
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
    v13 = (unsigned __int128)_mm_cvtepi32_ps(v5);
    v14 = (unsigned __int128)_mm_cvtepi32_ps(v6);
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
    v9 = _mm_cvtsi32_si128(HIDWORD(v4[1].mPrev));
    v10 = _mm_cvtsi32_si128((unsigned int)v4[1].mNext);
    v12 = 0;
    v11 = v7;
    v16 = v8;
    v13 = (unsigned __int128)_mm_cvtepi32_ps(v9);
    v14 = (unsigned __int128)_mm_cvtepi32_ps(v10);
    v15 = 0;
LABEL_59:
    v3->m_movie.pObject->vfptr[35].__vecDelDtor(
      (Scaleform::RefCountImplCore *)&v3->m_movie.pObject->vfptr,
      (unsigned int)&v11);
  }
} 0;
LABEL_59:
    v3->m_movie.pObject->vfptr[35].__vecDe

// File Line: 451
// RVA: 0xA2F4D0
bool __fastcall UFG::UIScreen::handleMessage(UFG::UIScreen *this, unsigned int msgId, UFG::UIMessage *msg)
{
  bool result; // al

  if ( msgId == UI_HASH_ENABLE_INPUT_35 )
    goto LABEL_2;
  if ( msgId == UI_HASH_DISABLE_INPUT_35 )
  {
    --this->mInputEnabled;
    result = 1;
  }
  else
  {
    if ( msgId == UI_HASH_INTRO_COMPLETE_35 )
    {
LABEL_2:
      ++this->mInputEnabled;
      return 1;
    }
    result = 0;
  }
  return result;
}

// File Line: 475
// RVA: 0xA302B0
bool __fastcall UFG::UIScreen::invoke(UFG::UIScreen *this, const char *funcName)
{
  Scaleform::GFx::Movie *v2; // rcx
  __int64 v4; // rbx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h]

  v2 = this->mRenderable->m_movie.pObject;
  if ( !v2 )
    return 0;
  presult.pObjectInterface = 0i64;
  presult.Type = 0;
  v4 = (unsigned __int8)Scaleform::GFx::Movie::Invoke(v2, funcName, &presult, 0i64, 0);
  if ( ((unsigned int)presult.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&presult.pObjectInterface->vfptr->gap8[8])(
      presult.pObjectInterface,
      &presult,
      *(_QWORD *)&presult.mValue.NValue);
    presult.pObjectInterface = 0i64;
  }
  return v4;
}

// File Line: 510
// RVA: 0xA33270
void __usercall UFG::UIScreen::updateViewportScale(UFG::UIScreen *this@<rcx>, float a2@<xmm0>)
{
  Scaleform::GFx::Movie *v2; // rsi
  int v3; // eax
  const char *v4; // r8
  __int64 v5; // rbx
  __int64 v6; // rdi
  float v7; // xmm8_4
  float v8; // xmm0_4
  __int64 v9; // rbx
  __int64 v10; // rdi
  float v11; // xmm7_4
  Scaleform::GFx::Value pval; // [rsp+20h] [rbp-D8h]
  __int64 v13; // [rsp+50h] [rbp-A8h]
  double v14; // [rsp+60h] [rbp-98h]
  double v15; // [rsp+68h] [rbp-90h]
  double v16; // [rsp+78h] [rbp-80h]
  int Dst; // [rsp+B8h] [rbp-40h]
  int v18; // [rsp+CCh] [rbp-2Ch]
  int v19; // [rsp+E0h] [rbp-18h]
  int v20; // [rsp+E8h] [rbp-10h]
  int v21; // [rsp+FCh] [rbp+4h]
  int v22; // [rsp+110h] [rbp+18h]
  int v23; // [rsp+124h] [rbp+2Ch]
  __int16 v24; // [rsp+12Ch] [rbp+34h]

  v13 = -2i64;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  v2 = this->mRenderable->m_movie.pObject;
  v3 = Scaleform::GFx::Movie::GetAVMVersion(v2);
  v4 = aRoo;
  if ( v3 != 1 )
    v4 = "root";
  Scaleform::GFx::Movie::GetVariable(v2, &pval, v4);
  if ( (pval.Type & 0x8Fu) > 1 )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))v2->vfptr[1].__vecDelDtor)(v2);
    v6 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))v2->vfptr[1].__vecDelDtor)(v2);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 48i64))(v5);
    v7 = a2;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 48i64))(v6);
    v8 = a2 * UFG::gUIViewportScale;
    v9 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))v2->vfptr[1].__vecDelDtor)(v2);
    v10 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))v2->vfptr[1].__vecDelDtor)(v2);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 56i64))(v9);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 56i64))(v10);
    v11 = (float)(v8 - (float)(v8 * UFG::gUIViewportScale)) * 0.5;
    memset(&Dst, 0, 0x30ui64);
    Dst = 1065353216;
    v18 = 1065353216;
    v19 = 1065353216;
    memset(&v20, 0, 0x40ui64);
    v20 = 1065353216;
    v21 = 1065353216;
    v22 = 1065353216;
    v23 = 1065353216;
    v24 = 0;
    pval.pObjectInterface->vfptr->GetDisplayInfo(
      pval.pObjectInterface,
      *(void **)&pval.mValue.NValue,
      (Scaleform::GFx::Value::DisplayInfo *)&v14);
    v16 = (float)(UFG::gUIViewportScale * 100.0);
    v14 = (float)((float)(v7 - v8) * 0.5);
    v24 |= 0x1Bu;
    v15 = v11;
    pval.pObjectInterface->vfptr->SetDisplayInfo(
      pval.pObjectInterface,
      *(void **)&pval.mValue.NValue,
      (Scaleform::GFx::Value::DisplayInfo *)&v14);
  }
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
}

