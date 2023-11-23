// File Line: 22
// RVA: 0x15AB8F0
__int64 UFG::_dynamic_initializer_for__UI_HASH_PLAY_SOUND__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PLAY_SOUND", -1);
  UI_HASH_PLAY_SOUND = result;
  return result;
}

// File Line: 23
// RVA: 0x15AABF0
__int64 UFG::_dynamic_initializer_for__UI_HASH_AUDIO_MESSAGE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("AUDIO_MESSAGE", -1);
  UI_HASH_AUDIO_MESSAGE = result;
  return result;
}

// File Line: 24
// RVA: 0x15AB610
__int64 UFG::_dynamic_initializer_for__UI_HASH_LOCALIZE_STRING__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LOCALIZE_STRING", -1);
  UI_HASH_LOCALIZE_STRING = result;
  return result;
}

// File Line: 25
// RVA: 0x15AAAD0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_TWEEN_TO__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_TWEEN_TO", -1);
  UI_HASH_ADD_TWEEN_TO = result;
  return result;
}

// File Line: 26
// RVA: 0x15AAA90
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_TWEEN_FROM__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_TWEEN_FROM", -1);
  UI_HASH_ADD_TWEEN_FROM = result;
  return result;
}

// File Line: 27
// RVA: 0x15AAAB0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_TWEEN_TEXT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_TWEEN_TEXT", -1);
  UI_HASH_ADD_TWEEN_TEXT = result;
  return result;
}

// File Line: 28
// RVA: 0x15AB590
__int64 UFG::_dynamic_initializer_for__UI_HASH_KILL_TWEENS__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("KILL_TWEENS", -1);
  UI_HASH_KILL_TWEENS = result;
  return result;
}

// File Line: 30
// RVA: 0x15AA800
__int64 dynamic_initializer_for__UFG::UIGfxExternalInterface::mCallbackFuncList__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::UIGfxExternalInterface::mCallbackFuncList.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIGfxExternalInterface::mCallbackFuncList__);
}

// File Line: 79
// RVA: 0xA24940
void __fastcall UFG::UIGfxExternalInterface::Callback(
        UFG::UIGfxExternalInterface *this,
        Scaleform::GFx::Movie *movieView,
        const char *methodName,
        Scaleform::GFx::Value *args)
{
  UFG::UIMessage *v6; // rdi
  int v7; // r14d
  unsigned int v8; // eax
  unsigned int v9; // r15d
  const char *pString; // rcx
  unsigned int v11; // ebx
  __int64 v12; // rax
  const char *v13; // rax
  unsigned int mStringHashUpper32; // eax
  void (__fastcall *m_audioCallback)(const char *, unsigned int, unsigned int, unsigned int); // r10
  const char *v16; // rcx
  unsigned int v17; // edi
  unsigned int UIValue; // ebx
  __int64 v19; // rax
  const char *v20; // rax
  unsigned int v21; // eax
  void (__fastcall *v22)(const char *, unsigned int, unsigned int, unsigned int); // r10
  const char *v23; // r14
  const char *v24; // r15
  unsigned int v25; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  Scaleform::GFx::Value::ValueUnion mValue; // rbx
  Scaleform::GFx::Value::ValueUnion v28; // r9
  Scaleform::GFx::Value::ValueUnion v29; // r8
  unsigned int v30; // eax
  const char *v31; // r8
  UFG::qBaseTreeRB *v32; // rax
  char v33; // bl
  Scaleform::GFx::Value *v34; // rbx
  UFG::UIMessage *v35; // rax
  signed int mStringHash32; // r12d
  Scaleform::GFx::Value *v37; // r13
  float Float; // xmm0_4
  __int64 v39; // rax
  __int64 v40; // rsi
  int v41; // eax
  float v42; // xmm0_4
  int v43; // eax
  float v44; // xmm0_4
  int v45; // eax
  float v46; // xmm0_4
  float v47; // xmm6_4
  unsigned int v48; // r14d
  unsigned int v49; // r12d
  int v50; // eax
  char v51; // r13
  char v52; // r13
  int v53; // r14d
  __int64 v54; // r12
  const char *v55; // r8
  int v56; // eax
  float v57; // xmm0_4
  int v58; // eax
  float v59; // xmm6_4
  float v60; // xmm7_4
  int v61; // eax
  int v62; // eax
  const char *v63; // rdx
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *p_m_activeTweens; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rax
  int check_null; // [rsp+20h] [rbp-B8h]
  int check_nulla; // [rsp+20h] [rbp-B8h]
  int check_nullb; // [rsp+20h] [rbp-B8h]
  int check_nullc; // [rsp+20h] [rbp-B8h]
  int check_nulld; // [rsp+20h] [rbp-B8h]
  int check_nulle; // [rsp+20h] [rbp-B8h]
  int check_nullf; // [rsp+20h] [rbp-B8h]
  int check_nullg; // [rsp+20h] [rbp-B8h]
  int check_nullh; // [rsp+20h] [rbp-B8h]
  int check_nulli; // [rsp+20h] [rbp-B8h]
  int check_nullj; // [rsp+20h] [rbp-B8h]
  int check_nullk; // [rsp+20h] [rbp-B8h]
  int check_nulll; // [rsp+20h] [rbp-B8h]
  int check_nullm; // [rsp+20h] [rbp-B8h]
  int check_nulln; // [rsp+20h] [rbp-B8h]
  int check_nullo; // [rsp+20h] [rbp-B8h]
  int check_nullp; // [rsp+20h] [rbp-B8h]
  int check_nullq; // [rsp+20h] [rbp-B8h]
  int check_nullr; // [rsp+20h] [rbp-B8h]
  int check_nulls; // [rsp+20h] [rbp-B8h]
  int check_nullt; // [rsp+20h] [rbp-B8h]
  int check_nullu; // [rsp+20h] [rbp-B8h]
  int check_nullv; // [rsp+20h] [rbp-B8h]
  int check_nullw; // [rsp+20h] [rbp-B8h]
  UFG::qString result; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v91; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::Value v92; // [rsp+60h] [rbp-78h] BYREF
  unsigned int args_24; // [rsp+90h] [rbp-48h]
  __int64 args_32; // [rsp+98h] [rbp-40h]
  __int64 v95; // [rsp+A8h] [rbp-30h]
  void *retaddr; // [rsp+138h] [rbp+60h]

  v95 = -2i64;
  v6 = 0i64;
  v7 = 0;
  LODWORD(v92.pObjectInterface) = 0;
  v8 = UFG::qStringHashUpper32(methodName, -1);
  v9 = v8;
  if ( UI_HASH_PLAY_SOUND == v8 )
  {
    if ( (args->Type & 0x40) != 0 )
      pString = *args->mValue.pStringManaged;
    else
      pString = args->mValue.pString;
    v11 = UFG::qStringHashUpper32(pString, -1);
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))movieView->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(movieView);
    v13 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 96i64))(v12);
    UFG::qString::qString((UFG::qString *)&v92.Type, v13);
    UFG::qString::GetFilenameWithoutExtension((UFG::qString *)&v92.Type, &result);
    mStringHashUpper32 = result.mStringHashUpper32;
    if ( result.mStringHashUpper32 == -1 )
    {
      mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, -1);
      result.mStringHashUpper32 = mStringHashUpper32;
    }
    m_audioCallback = UFG::UIScreenManager::s_instance->m_audioCallback;
    if ( m_audioCallback )
      m_audioCallback(result.mData, mStringHashUpper32, UI_HASH_PLAY_SOUND, v11);
LABEL_9:
    UFG::qString::~qString(&result);
    UFG::qString::~qString((UFG::qString *)&v92.Type);
    return;
  }
  if ( UI_HASH_AUDIO_MESSAGE == v8 )
  {
    if ( (args->Type & 0x40) != 0 )
      v16 = *args->mValue.pStringManaged;
    else
      v16 = args->mValue.pString;
    v17 = UFG::qStringHashUpper32(v16, -1);
    UIValue = args[1].mValue.UIValue;
    v19 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))movieView->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(movieView);
    v20 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 96i64))(v19);
    UFG::qString::qString((UFG::qString *)&v92.Type, v20);
    UFG::qString::GetFilenameWithoutExtension((UFG::qString *)&v92.Type, &result);
    v21 = result.mStringHashUpper32;
    if ( result.mStringHashUpper32 == -1 )
    {
      v21 = UFG::qStringHashUpper32(result.mData, -1);
      result.mStringHashUpper32 = v21;
    }
    v22 = UFG::UIScreenManager::s_instance->m_audioCallback;
    if ( v22 )
      v22(result.mData, v21, v17, UIValue);
    goto LABEL_9;
  }
  if ( UI_HASH_LOCALIZE_STRING == v8 )
  {
    if ( !(_DWORD)retaddr || (args->Type & 0x8F) != 6 )
      return;
    v92.DataAux = 0i64;
    args_24 = 0;
    if ( (args->Type & 0x40) != 0 )
      v23 = *args->mValue.pStringManaged;
    else
      v23 = args->mValue.pString;
    if ( v23 )
    {
      if ( *v23 == 36 )
        ++v23;
      v25 = UFG::qStringHashUpper32(v23, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v24 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v25)) == 0i64 )
        v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    if ( (_DWORD)retaddr == 1 )
    {
      Scaleform::GFx::Movie::CreateString(movieView, (Scaleform::GFx::Value *)&v92.Type, v24);
LABEL_51:
      Scaleform::GFx::Movie::SetExternalInterfaceRetVal(movieView, (Scaleform::GFx::Value *)&v92.Type);
      v30 = args_24 >> 6;
LABEL_52:
      if ( (v30 & 1) != 0 )
      {
        (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)v92.DataAux
                                                                                              + 16i64))(
          v92.DataAux,
          &v92.Type,
          args_32);
        v92.DataAux = 0i64;
      }
      args_24 = 0;
      return;
    }
    if ( (_DWORD)retaddr == 2 )
    {
      if ( (args[1].Type & 0x8F) != 6 )
        goto LABEL_51;
      if ( (args[1].Type & 0x40) != 0 )
        mValue = *(Scaleform::GFx::Value::ValueUnion *)args[1].mValue.pString;
      else
        mValue = args[1].mValue;
      UFG::qString::qString(&result);
      UFG::qString::Format(&result, v24, mValue.pString);
      Scaleform::GFx::Movie::CreateString(movieView, (Scaleform::GFx::Value *)&v92.Type, result.mData);
    }
    else
    {
      if ( (_DWORD)retaddr != 3 || (args[1].Type & 0x8F) != 6 || (args[2].Type & 0x8F) != 6 )
        goto LABEL_51;
      UFG::qString::qString(&result);
      if ( (args[2].Type & 0x40) != 0 )
        v28 = *(Scaleform::GFx::Value::ValueUnion *)args[2].mValue.pString;
      else
        v28 = args[2].mValue;
      if ( (args[1].Type & 0x40) != 0 )
        v29 = *(Scaleform::GFx::Value::ValueUnion *)args[1].mValue.pString;
      else
        v29 = args[1].mValue;
      UFG::qString::Format(&result, v24, v29.pString, v28.pString);
      Scaleform::GFx::Movie::CreateString(movieView, (Scaleform::GFx::Value *)&v92.Type, result.mData);
    }
    UFG::qString::~qString(&result);
    goto LABEL_51;
  }
  if ( UI_HASH_ADD_TWEEN_TO == v8 || UI_HASH_ADD_TWEEN_FROM == v8 || UI_HASH_ADD_TWEEN_TEXT == v8 )
  {
    if ( (unsigned int)retaddr >= 3
      && (args->Type & 0x8F) == 6
      && (args[1].Type & 0x8F) == 5
      && (args[2].Type & 0x8F) == 8 )
    {
      *(_QWORD *)&result.mMagic = 0i64;
      LODWORD(result.mData) = 0;
      mStringHash32 = 6;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, bool))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "ease",
             &result,
             (args[2].Type & 0x8F) == 10) )
      {
        mStringHash32 = result.mStringHash32;
      }
      v37 = (Scaleform::GFx::Value *)UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
      v92.pNext = v37;
      if ( v37 )
      {
        if ( (args->Type & 0x40) != 0 )
          UFG::qString::qString((UFG::qString *)&v92.Type, *args->mValue.pStringManaged);
        else
          UFG::qString::qString((UFG::qString *)&v92.Type, args->mValue.pString);
        v7 = 1;
        LODWORD(v92.pObjectInterface) = 1;
        Float = UFG::UI::GetFloat(args + 1);
        UFG::UITween::UITween(
          (UFG::UITween *)v37,
          movieView,
          (UFG::qString *)&v92.Type,
          Float,
          (UFG::UITween::eTweenType)mStringHash32);
        v40 = v39;
      }
      else
      {
        v40 = 0i64;
      }
      if ( (v7 & 1) != 0 )
      {
        LODWORD(v92.pObjectInterface) = v7 & 0xFFFFFFFE;
        UFG::qString::~qString((UFG::qString *)&v92.Type);
      }
      LOBYTE(check_null) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "delay",
             &result,
             check_null) )
      {
        v41 = (__int64)result.mData & 0x8F;
        if ( v41 == 3 )
        {
          v42 = (float)(int)result.mStringHash32;
        }
        else if ( v41 == 4 )
        {
          v42 = (float)(int)result.mStringHash32;
        }
        else
        {
          v42 = *(double *)&result.mStringHash32;
        }
        *(float *)(v40 + 216) = v42;
      }
      LOBYTE(check_nulla) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "step",
             &result,
             check_nulla) )
      {
        v43 = (__int64)result.mData & 0x8F;
        if ( v43 == 3 )
        {
          v44 = (float)(int)result.mStringHash32;
        }
        else if ( v43 == 4 )
        {
          v44 = (float)(int)result.mStringHash32;
        }
        else
        {
          v44 = *(double *)&result.mStringHash32;
        }
        *(float *)(v40 + 220) = v44;
      }
      LOBYTE(check_nullb) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "loopType",
             &result,
             check_nullb) )
      {
        *(_DWORD *)(v40 + 224) = result.mStringHash32;
      }
      LOBYTE(check_nullc) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "loopCount",
             &result,
             check_nullc) )
      {
        *(_DWORD *)(v40 + 228) = result.mStringHash32;
      }
      LOBYTE(check_nulld) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "loopDelay",
             &result,
             check_nulld) )
      {
        v45 = (__int64)result.mData & 0x8F;
        if ( v45 == 3 )
        {
          v46 = (float)(int)result.mStringHash32;
        }
        else if ( v45 == 4 )
        {
          v46 = (float)(int)result.mStringHash32;
        }
        else
        {
          v46 = *(double *)&result.mStringHash32;
        }
        *(float *)(v40 + 232) = v46;
      }
      v47 = 0.0;
      v48 = 0;
      v49 = 0;
      LOBYTE(check_nulle) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "roughRange",
             &result,
             check_nulle) )
      {
        v50 = (__int64)result.mData & 0x8F;
        if ( v50 == 3 )
        {
          v47 = (float)(int)result.mStringHash32;
        }
        else if ( v50 == 4 )
        {
          v47 = (float)(int)result.mStringHash32;
        }
        else
        {
          v47 = *(double *)&result.mStringHash32;
        }
      }
      LOBYTE(check_nullf) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "roughPoints",
             &result,
             check_nullf) )
      {
        if ( ((__int64)result.mData & 0x8F) == 5 )
          v48 = (int)*(double *)&result.mStringHash32;
        else
          v48 = result.mStringHash32;
      }
      LOBYTE(check_nullg) = (args[2].Type & 0x8F) == 10;
      v51 = 1;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "roughRandom",
             &result,
             check_nullg) )
      {
        v51 = result.mStringHash32;
      }
      LOBYTE(check_nullh) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "roughTaper",
             &result,
             check_nullh) )
      {
        if ( ((__int64)result.mData & 0x8F) == 5 )
          v49 = (int)*(double *)&result.mStringHash32;
        else
          v49 = result.mStringHash32;
      }
      *(float *)(v40 + 236) = v47;
      *(_DWORD *)(v40 + 240) = v48;
      *(_BYTE *)(v40 + 244) = v51;
      *(_DWORD *)(v40 + 248) = v49;
      LOBYTE(check_nulli) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onInit",
             &result,
             check_nulli) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v40, ONINIT, &v92);
      }
      LOBYTE(check_nullj) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onInitParams",
             &result,
             check_nullj) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v40, ONINIT, &v92);
      }
      LOBYTE(check_nullk) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onStart",
             &result,
             check_nullk) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        v52 = 1;
        UFG::UITween::SetCallback((UFG::UITween *)v40, ONSTART, &v92);
      }
      else
      {
        v52 = 1;
      }
      LOBYTE(check_nulll) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onStartParams",
             &result,
             check_nulll) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v40, ONSTART, &v92);
      }
      LOBYTE(check_nullm) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onUpdate",
             &result,
             check_nullm) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v40, ONUPDATE, &v92);
      }
      LOBYTE(check_nulln) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onUpdateParams",
             &result,
             check_nulln) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v40, ONUPDATE, &v92);
      }
      LOBYTE(check_nullo) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onLoop",
             &result,
             check_nullo) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v40, ONLOOP, &v92);
      }
      LOBYTE(check_nullp) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onLoopParams",
             &result,
             check_nullp) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v40, ONLOOP, &v92);
      }
      LOBYTE(check_nullq) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onOscillateComplete",
             &result,
             check_nullq) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v40, ONOSCILLATECOMPLETE, &v92);
      }
      LOBYTE(check_nullr) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onOscillateCompleteParams",
             &result,
             check_nullr) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v40, ONOSCILLATECOMPLETE, &v92);
      }
      LOBYTE(check_nulls) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onComplete",
             &result,
             check_nulls) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v40, ONCOMPLETE, &v92);
      }
      LOBYTE(check_nullt) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "onCompleteParams",
             &result,
             check_nullt) )
      {
        v92.pNext = &v92;
        v92.pObjectInterface = 0i64;
        v92.Type = (Scaleform::GFx::Value::ValueType)result.mData;
        v91 = *(_QWORD *)&result.mStringHash32;
        v92.pPrev = *(Scaleform::GFx::Value **)&result.mStringHash32;
        if ( ((__int64)result.mData & 0x40) != 0 )
        {
          v92.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v92);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v40, ONCOMPLETE, &v92);
      }
      if ( UI_HASH_ADD_TWEEN_TO == v9 || UI_HASH_ADD_TWEEN_FROM == v9 )
      {
        v53 = 0;
        v54 = v40 + 76;
        while ( 2 )
        {
          switch ( v53 )
          {
            case 0:
              v55 = "x";
              goto LABEL_196;
            case 1:
              v55 = "y";
              goto LABEL_196;
            case 2:
              v55 = "z";
              goto LABEL_196;
            case 3:
              v55 = "alpha";
              goto LABEL_196;
            case 4:
              v55 = "scaleX";
              goto LABEL_196;
            case 5:
              v55 = "scaleY";
              goto LABEL_196;
            case 6:
              v55 = "scaleZ";
              goto LABEL_196;
            case 7:
              v55 = "rotation";
              goto LABEL_196;
            case 8:
              v55 = "rotationX";
              goto LABEL_196;
            case 9:
              v55 = "rotationY";
              goto LABEL_196;
            case 10:
              v55 = "fov";
LABEL_196:
              LOBYTE(check_nullu) = (args[2].Type & 0x8F) == 10;
              if ( !(*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
                      args[2].pObjectInterface,
                      args[2].mValue,
                      v55,
                      &result,
                      check_nullu) )
                goto LABEL_212;
              if ( UI_HASH_ADD_TWEEN_TO == v9 )
              {
                v56 = (__int64)result.mData & 0x8F;
                if ( v56 == 3 )
                {
                  v57 = (float)(int)result.mStringHash32;
                }
                else if ( v56 == 4 )
                {
                  v57 = (float)(int)result.mStringHash32;
                }
                else
                {
                  v57 = *(double *)&result.mStringHash32;
                }
                *(_DWORD *)(v54 - 4) = -1082130432;
                *(float *)v54 = v57;
              }
              else
              {
                if ( UI_HASH_ADD_TWEEN_FROM != v9 )
                  goto LABEL_212;
                v58 = (__int64)result.mData & 0x8F;
                if ( v58 == 3 )
                {
                  v57 = (float)(int)result.mStringHash32;
                }
                else if ( v58 == 4 )
                {
                  v57 = (float)(int)result.mStringHash32;
                }
                else
                {
                  v57 = *(double *)&result.mStringHash32;
                }
                *(float *)(v54 - 4) = v57;
                *(_DWORD *)v54 = -1082130432;
              }
              *(_BYTE *)(v54 + 4) = v57 != -1.0;
LABEL_212:
              ++v53;
              v54 += 12i64;
              if ( v53 >= 12 )
                break;
              continue;
            default:
              goto LABEL_212;
          }
          break;
        }
      }
      v59 = FLOAT_N1_0;
      v60 = FLOAT_N1_0;
      LOBYTE(check_nullu) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "txtStart",
             &result,
             check_nullu) )
      {
        v61 = (__int64)result.mData & 0x8F;
        if ( v61 == 3 )
        {
          v59 = (float)(int)result.mStringHash32;
        }
        else if ( v61 == 4 )
        {
          v59 = (float)(int)result.mStringHash32;
        }
        else
        {
          v59 = *(double *)&result.mStringHash32;
        }
      }
      LOBYTE(check_nullv) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "txtEnd",
             &result,
             check_nullv) )
      {
        v62 = (__int64)result.mData & 0x8F;
        if ( v62 == 3 )
        {
          v60 = (float)(int)result.mStringHash32;
        }
        else if ( v62 == 4 )
        {
          v60 = (float)(int)result.mStringHash32;
        }
        else
        {
          v60 = *(double *)&result.mStringHash32;
        }
      }
      if ( v59 != -1.0 && v60 != -1.0 )
      {
        *(float *)(v40 + 204) = v59;
        *(float *)(v40 + 208) = v60;
        if ( v59 == v60 )
          v52 = 0;
        *(_BYTE *)(v40 + 212) = v52;
      }
      LOBYTE(check_nullw) = (args[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, UFG::qString *, int))&args[2].pObjectInterface->vfptr->gap8[24])(
             args[2].pObjectInterface,
             args[2].mValue,
             "txtFormat",
             &result,
             check_nullw) )
      {
        if ( ((__int64)result.mData & 0x40) != 0 )
          v63 = **(const char ***)&result.mStringHash32;
        else
          v63 = *(const char **)&result.mStringHash32;
        UFG::qString::Set((UFG::qString *)(v40 + 944), v63);
      }
      p_m_activeTweens = &UFG::UIScreenManager::s_instance->m_activeTweens;
      mPrev = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)v40;
      *(_QWORD *)v40 = mPrev;
      *(_QWORD *)(v40 + 8) = p_m_activeTweens;
      p_m_activeTweens->mNode.mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)v40;
      if ( ((__int64)result.mData & 0x40) != 0 )
        (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&result.mMagic + 16i64))(
          *(_QWORD *)&result.mMagic,
          &result,
          *(_QWORD *)&result.mStringHash32);
    }
  }
  else
  {
    if ( UI_HASH_KILL_TWEENS == v8 )
    {
      if ( !(_DWORD)retaddr || (args->Type & 0x8F) != 6 )
        return;
      if ( (args->Type & 0x40) != 0 )
        v31 = *args->mValue.pStringManaged;
      else
        v31 = args->mValue.pString;
      UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManager::s_instance, movieView, v31);
    }
    if ( v9 )
    {
      v32 = UFG::qBaseTreeRB::Get(&UFG::UIGfxExternalInterface::mCallbackFuncList.mTree, v9);
      if ( v32 )
      {
        if ( v32 != (UFG::qBaseTreeRB *)8 )
        {
          v92.DataAux = 0i64;
          args_24 = 0;
          v33 = (**(__int64 (__fastcall ***)(__int64, Scaleform::GFx::Movie *, Scaleform::GFx::Value *, _QWORD, Scaleform::GFx::Value::ValueType *))&v32[-1].mCount)(
                  (__int64)&v32[-1].mCount,
                  movieView,
                  args,
                  (unsigned int)retaddr,
                  &v92.Type);
          Scaleform::GFx::Movie::SetExternalInterfaceRetVal(movieView, (Scaleform::GFx::Value *)&v92.Type);
          v30 = args_24 >> 6;
          if ( v33 )
            goto LABEL_52;
          if ( (args_24 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)v92.DataAux
                                                                                                  + 16i64))(
              v92.DataAux,
              &v92.Type,
              args_32);
            v92.DataAux = 0i64;
          }
          args_24 = 0;
        }
      }
    }
    v34 = (Scaleform::GFx::Value *)UFG::qMemoryPool::Allocate(
                                     &gScaleformMemoryPool,
                                     0x68ui64,
                                     "UIGfxExternalInterface::Callback",
                                     0i64,
                                     1u);
    v92.pNext = v34;
    if ( v34 )
    {
      UFG::qString::qString((UFG::qString *)&v92.Type, &customCaption);
      v7 = 2;
      LODWORD(v92.pObjectInterface) = 2;
      UFG::UIMessageFlash::UIMessageFlash((UFG::UIMessageFlash *)v34, v9, movieView, (UFG::qString *)&v92.Type);
      v6 = v35;
    }
    if ( (v7 & 2) != 0 )
    {
      LODWORD(v92.pObjectInterface) = v7 & 0xFFFFFFFD;
      UFG::qString::~qString((UFG::qString *)&v92.Type);
    }
    UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, v6);
  }
}

