// File Line: 22
// RVA: 0x15AB8F0
__int64 UFG::_dynamic_initializer_for__UI_HASH_PLAY_SOUND__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PLAY_SOUND", 0xFFFFFFFF);
  UI_HASH_PLAY_SOUND = result;
  return result;
}

// File Line: 23
// RVA: 0x15AABF0
__int64 UFG::_dynamic_initializer_for__UI_HASH_AUDIO_MESSAGE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("AUDIO_MESSAGE", 0xFFFFFFFF);
  UI_HASH_AUDIO_MESSAGE = result;
  return result;
}

// File Line: 24
// RVA: 0x15AB610
__int64 UFG::_dynamic_initializer_for__UI_HASH_LOCALIZE_STRING__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LOCALIZE_STRING", 0xFFFFFFFF);
  UI_HASH_LOCALIZE_STRING = result;
  return result;
}

// File Line: 25
// RVA: 0x15AAAD0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_TWEEN_TO__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_TWEEN_TO", 0xFFFFFFFF);
  UI_HASH_ADD_TWEEN_TO = result;
  return result;
}

// File Line: 26
// RVA: 0x15AAA90
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_TWEEN_FROM__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_TWEEN_FROM", 0xFFFFFFFF);
  UI_HASH_ADD_TWEEN_FROM = result;
  return result;
}

// File Line: 27
// RVA: 0x15AAAB0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_TWEEN_TEXT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_TWEEN_TEXT", 0xFFFFFFFF);
  UI_HASH_ADD_TWEEN_TEXT = result;
  return result;
}

// File Line: 28
// RVA: 0x15AB590
__int64 UFG::_dynamic_initializer_for__UI_HASH_KILL_TWEENS__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("KILL_TWEENS", 0xFFFFFFFF);
  UI_HASH_KILL_TWEENS = result;
  return result;
}

// File Line: 30
// RVA: 0x15AA800
__int64 dynamic_initializer_for__UFG::UIGfxExternalInterface::mCallbackFuncList__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::UIGfxExternalInterface::mCallbackFuncList.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::UIGfxExternalInterface::mCallbackFuncList__);
}

// File Line: 79
// RVA: 0xA24940
void __fastcall UFG::UIGfxExternalInterface::Callback(UFG::UIGfxExternalInterface *this, Scaleform::GFx::Movie *movieView, const char *methodName, Scaleform::GFx::Value *args)
{
  Scaleform::GFx::Value *v4; // rbx
  Scaleform::GFx::Movie *v5; // rsi
  UFG::UIMessage *v6; // rdi
  signed int v7; // er14
  unsigned int v8; // eax
  unsigned int v9; // er15
  const char *v10; // rcx
  unsigned int v11; // ebx
  __int64 v12; // rax
  const char *v13; // rax
  int v14; // edx
  unsigned int v15; // eax
  void (__fastcall *v16)(const char *, unsigned int, unsigned int, unsigned int); // r10
  const char *v17; // rcx
  unsigned int v18; // edi
  int v19; // ebx
  __int64 v20; // rax
  const char *v21; // rax
  int v22; // edx
  unsigned int v23; // eax
  void (__fastcall *v24)(const char *, unsigned int, unsigned int, unsigned int); // r10
  const char *v25; // r14
  const char *v26; // r15
  unsigned int v27; // eax
  UFG::UIGfxTranslator *v28; // rcx
  long double v29; // rbx
  long double v30; // r9
  long double v31; // r8
  int v32; // eax
  const char *v33; // r8
  UFG::qBaseTreeRB *v34; // rax
  __int64 v35; // rbx
  UFG::allocator::free_link *v36; // rbx
  UFG::UIMessage *v37; // rax
  signed int v38; // er12
  UFG::allocator::free_link *v39; // r13
  const char *v40; // rdx
  float v41; // xmm0_4
  __int64 v42; // rax
  __int64 v43; // rsi
  int v44; // eax
  float v45; // xmm0_4
  int v46; // eax
  float v47; // xmm0_4
  int v48; // eax
  float v49; // xmm0_4
  float v50; // xmm6_4
  unsigned int v51; // er14
  unsigned int v52; // er12
  int v53; // eax
  char v54; // r13
  char v55; // r13
  signed int v56; // er14
  signed __int64 v57; // r12
  const char *v58; // r8
  int v59; // eax
  float v60; // xmm0_4
  int v61; // eax
  char v62; // al
  float v63; // xmm6_4
  float v64; // xmm7_4
  int v65; // eax
  int v66; // eax
  const char *v67; // rdx
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v68; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v69; // rax
  __int64 check_null[2]; // [rsp+20h] [rbp-B8h]
  __int64 check_nulla; // [rsp+20h] [rbp-B8h]
  __int64 check_nullb; // [rsp+20h] [rbp-B8h]
  __int64 check_nullc; // [rsp+20h] [rbp-B8h]
  __int64 check_nulld; // [rsp+20h] [rbp-B8h]
  __int64 check_nulle; // [rsp+20h] [rbp-B8h]
  __int64 check_nullf; // [rsp+20h] [rbp-B8h]
  __int64 check_nullg; // [rsp+20h] [rbp-B8h]
  __int64 check_nullh; // [rsp+20h] [rbp-B8h]
  __int64 check_nulli; // [rsp+20h] [rbp-B8h]
  __int64 check_nullj; // [rsp+20h] [rbp-B8h]
  __int64 check_nullk; // [rsp+20h] [rbp-B8h]
  __int64 check_nulll; // [rsp+20h] [rbp-B8h]
  __int64 check_nullm; // [rsp+20h] [rbp-B8h]
  __int64 check_nulln; // [rsp+20h] [rbp-B8h]
  __int64 check_nullo; // [rsp+20h] [rbp-B8h]
  __int64 check_nullp; // [rsp+20h] [rbp-B8h]
  __int64 check_nullq; // [rsp+20h] [rbp-B8h]
  __int64 check_nullr; // [rsp+20h] [rbp-B8h]
  __int64 check_nulls; // [rsp+20h] [rbp-B8h]
  __int64 check_nullt; // [rsp+20h] [rbp-B8h]
  __int64 check_nullu; // [rsp+20h] [rbp-B8h]
  __int64 check_nullv; // [rsp+20h] [rbp-B8h]
  __int64 check_nullw; // [rsp+20h] [rbp-B8h]
  UFG::qString result; // [rsp+30h] [rbp-A8h]
  __int64 v95; // [rsp+58h] [rbp-80h]
  __int64 v96; // [rsp+60h] [rbp-78h]
  __int64 *v97; // [rsp+68h] [rbp-70h]
  __int64 v98; // [rsp+70h] [rbp-68h]
  UFG::qString argsa; // [rsp+78h] [rbp-60h]
  __int64 v100; // [rsp+A8h] [rbp-30h]
  void *retaddr; // [rsp+138h] [rbp+60h]

  v100 = -2i64;
  v4 = args;
  v5 = movieView;
  v6 = 0i64;
  v7 = 0;
  LODWORD(v98) = 0;
  v8 = UFG::qStringHashUpper32(methodName, 0xFFFFFFFF);
  v9 = v8;
  if ( UI_HASH_PLAY_SOUND == v8 )
  {
    if ( ((unsigned int)v4->Type >> 6) & 1 )
      v10 = *v4->mValue.pStringManaged;
    else
      v10 = v4->mValue.pString;
    v11 = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))v5->vfptr[1].__vecDelDtor)(v5);
    v13 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 96i64))(v12);
    UFG::qString::qString(&argsa, v13);
    UFG::qString::GetFilenameWithoutExtension(&argsa, &result);
    v15 = result.mStringHashUpper32;
    if ( result.mStringHashUpper32 == -1 )
    {
      v15 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v14);
      result.mStringHashUpper32 = v15;
    }
    v16 = UFG::UIScreenManager::s_instance->m_audioCallback;
    if ( v16 )
      v16(result.mData, v15, UI_HASH_PLAY_SOUND, v11);
    UFG::qString::~qString(&result);
    UFG::qString::~qString(&argsa);
    return;
  }
  if ( UI_HASH_AUDIO_MESSAGE == v8 )
  {
    if ( ((unsigned int)v4->Type >> 6) & 1 )
      v17 = *v4->mValue.pStringManaged;
    else
      v17 = v4->mValue.pString;
    v18 = UFG::qStringHashUpper32(v17, 0xFFFFFFFF);
    v19 = v4[1].mValue.IValue;
    v20 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))v5->vfptr[1].__vecDelDtor)(v5);
    v21 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v20 + 96i64))(v20);
    UFG::qString::qString(&argsa, v21);
    UFG::qString::GetFilenameWithoutExtension(&argsa, &result);
    v23 = result.mStringHashUpper32;
    if ( result.mStringHashUpper32 == -1 )
    {
      v23 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v22);
      result.mStringHashUpper32 = v23;
    }
    v24 = UFG::UIScreenManager::s_instance->m_audioCallback;
    if ( v24 )
      v24(result.mData, v23, v18, v19);
    UFG::qString::~qString(&result);
    UFG::qString::~qString(&argsa);
    return;
  }
  if ( UI_HASH_LOCALIZE_STRING == v8 )
  {
    if ( !(_DWORD)retaddr || (v4->Type & 0x8F) != 6 )
      return;
    *(_QWORD *)&argsa.mMagic = 0i64;
    LODWORD(argsa.mData) = 0;
    if ( ((unsigned int)v4->Type >> 6) & 1 )
      v25 = *v4->mValue.pStringManaged;
    else
      v25 = v4->mValue.pString;
    if ( v25 )
    {
      if ( *v25 == 36 )
        ++v25;
      v27 = UFG::qStringHashUpper32(v25, 0xFFFFFFFF);
      v28 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v28
        || (v26 = (const char *)v28->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, v27)) == 0i64 )
      {
        v26 = v25;
      }
    }
    else
    {
      v26 = 0i64;
    }
    if ( (_DWORD)retaddr == 1 )
    {
      Scaleform::GFx::Movie::CreateString(v5, (Scaleform::GFx::Value *)&argsa, v26);
LABEL_51:
      Scaleform::GFx::Movie::SetExternalInterfaceRetVal(v5, (Scaleform::GFx::Value *)&argsa);
      v32 = LODWORD(argsa.mData) >> 6;
LABEL_52:
      if ( v32 & 1 )
      {
        (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&argsa.mMagic + 16i64))(
          *(_QWORD *)&argsa.mMagic,
          &argsa,
          *(_QWORD *)&argsa.mStringHash32);
        *(_QWORD *)&argsa.mMagic = 0i64;
      }
      LODWORD(argsa.mData) = 0;
      return;
    }
    if ( (_DWORD)retaddr == 2 )
    {
      if ( (v4[1].Type & 0x8F) != 6 )
        goto LABEL_51;
      if ( ((unsigned int)v4[1].Type >> 6) & 1 )
        v29 = *(double *)v4[1].mValue.pString;
      else
        v29 = v4[1].mValue.NValue;
      UFG::qString::qString(&result);
      UFG::qString::Format(&result, v26, v29);
      Scaleform::GFx::Movie::CreateString(v5, (Scaleform::GFx::Value *)&argsa, result.mData);
    }
    else
    {
      if ( (_DWORD)retaddr != 3 || (v4[1].Type & 0x8F) != 6 || (v4[2].Type & 0x8F) != 6 )
        goto LABEL_51;
      UFG::qString::qString(&result);
      if ( ((unsigned int)v4[2].Type >> 6) & 1 )
        v30 = *(double *)v4[2].mValue.pString;
      else
        v30 = v4[2].mValue.NValue;
      if ( ((unsigned int)v4[1].Type >> 6) & 1 )
        v31 = *(double *)v4[1].mValue.pString;
      else
        v31 = v4[1].mValue.NValue;
      UFG::qString::Format(&result, v26, v31, v30);
      Scaleform::GFx::Movie::CreateString(v5, (Scaleform::GFx::Value *)&argsa, result.mData);
    }
    UFG::qString::~qString(&result);
    goto LABEL_51;
  }
  if ( UI_HASH_ADD_TWEEN_TO == v8 || UI_HASH_ADD_TWEEN_FROM == v8 || UI_HASH_ADD_TWEEN_TEXT == v8 )
  {
    if ( (unsigned int)retaddr >= 3 && (v4->Type & 0x8F) == 6 && (v4[1].Type & 0x8F) == 5 && (v4[2].Type & 0x8F) == 8 )
    {
      *(_QWORD *)&result.mMagic = 0i64;
      LODWORD(result.mData) = 0;
      v38 = 6;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, bool))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "ease",
             &result,
             (v4[2].Type & 0x8F) == 10) )
      {
        v38 = result.mStringHash32;
      }
      v39 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
      v97 = (__int64 *)v39;
      if ( v39 )
      {
        if ( ((unsigned int)v4->Type >> 6) & 1 )
          v40 = *v4->mValue.pStringManaged;
        else
          v40 = v4->mValue.pString;
        UFG::qString::qString(&argsa, v40);
        v7 = 1;
        LODWORD(v98) = 1;
        v41 = UFG::UI::GetFloat(v4 + 1);
        UFG::UITween::UITween((UFG::UITween *)v39, v5, &argsa, v41, (UFG::UITween::eTweenType)v38);
        v43 = v42;
      }
      else
      {
        v43 = 0i64;
      }
      if ( v7 & 1 )
      {
        LODWORD(v98) = v7 & 0xFFFFFFFE;
        UFG::qString::~qString(&argsa);
      }
      LOBYTE(check_null[0]) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "delay",
             &result,
             check_null[0]) )
      {
        v44 = (_QWORD)result.mData & 0x8F;
        if ( v44 == 3 )
        {
          v45 = (float)(signed int)result.mStringHash32;
        }
        else if ( v44 == 4 )
        {
          v45 = (float)(signed int)result.mStringHash32;
        }
        else
        {
          v45 = *(double *)&result.mStringHash32;
        }
        *(float *)(v43 + 216) = v45;
      }
      LOBYTE(check_nulla) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "step",
             &result,
             check_nulla) )
      {
        v46 = (_QWORD)result.mData & 0x8F;
        if ( v46 == 3 )
        {
          v47 = (float)(signed int)result.mStringHash32;
        }
        else if ( v46 == 4 )
        {
          v47 = (float)(signed int)result.mStringHash32;
        }
        else
        {
          v47 = *(double *)&result.mStringHash32;
        }
        *(float *)(v43 + 220) = v47;
      }
      LOBYTE(check_nullb) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "loopType",
             &result,
             check_nullb) )
      {
        *(_DWORD *)(v43 + 224) = result.mStringHash32;
      }
      LOBYTE(check_nullc) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "loopCount",
             &result,
             check_nullc) )
      {
        *(_DWORD *)(v43 + 228) = result.mStringHash32;
      }
      LOBYTE(check_nulld) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "loopDelay",
             &result,
             check_nulld) )
      {
        v48 = (_QWORD)result.mData & 0x8F;
        if ( v48 == 3 )
        {
          v49 = (float)(signed int)result.mStringHash32;
        }
        else if ( v48 == 4 )
        {
          v49 = (float)(signed int)result.mStringHash32;
        }
        else
        {
          v49 = *(double *)&result.mStringHash32;
        }
        *(float *)(v43 + 232) = v49;
      }
      v50 = 0.0;
      v51 = 0;
      v52 = 0;
      LOBYTE(check_nulle) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "roughRange",
             &result,
             check_nulle) )
      {
        v53 = (_QWORD)result.mData & 0x8F;
        if ( v53 == 3 )
        {
          v50 = (float)(signed int)result.mStringHash32;
        }
        else if ( v53 == 4 )
        {
          v50 = (float)(signed int)result.mStringHash32;
        }
        else
        {
          v50 = *(double *)&result.mStringHash32;
        }
      }
      LOBYTE(check_nullf) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "roughPoints",
             &result,
             check_nullf) )
      {
        if ( ((_QWORD)result.mData & 0x8F) == 5 )
          v51 = (signed int)*(double *)&result.mStringHash32;
        else
          v51 = result.mStringHash32;
      }
      LOBYTE(check_nullg) = (v4[2].Type & 0x8F) == 10;
      v54 = 1;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "roughRandom",
             &result,
             check_nullg) )
      {
        v54 = result.mStringHash32;
      }
      LOBYTE(check_nullh) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "roughTaper",
             &result,
             check_nullh) )
      {
        if ( ((_QWORD)result.mData & 0x8F) == 5 )
          v52 = (signed int)*(double *)&result.mStringHash32;
        else
          v52 = result.mStringHash32;
      }
      *(float *)(v43 + 236) = v50;
      *(_DWORD *)(v43 + 240) = v51;
      *(_BYTE *)(v43 + 244) = v54;
      *(_DWORD *)(v43 + 248) = v52;
      LOBYTE(check_nulli) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onInit",
             &result,
             check_nulli) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v43, 0, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullj) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onInitParams",
             &result,
             check_nullj) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v43, 0, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullk) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onStart",
             &result,
             check_nullk) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        v55 = 1;
        UFG::UITween::SetCallback((UFG::UITween *)v43, ONSTART, (Scaleform::GFx::Value *)&v96);
      }
      else
      {
        v55 = 1;
      }
      LOBYTE(check_nulll) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onStartParams",
             &result,
             check_nulll) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v43, ONSTART, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullm) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onUpdate",
             &result,
             check_nullm) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v43, ONUPDATE, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nulln) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onUpdateParams",
             &result,
             check_nulln) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v43, ONUPDATE, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullo) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onLoop",
             &result,
             check_nullo) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v43, ONLOOP, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullp) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onLoopParams",
             &result,
             check_nullp) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v43, ONLOOP, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullq) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onOscillateComplete",
             &result,
             check_nullq) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v43, ONOSCILLATECOMPLETE, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullr) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onOscillateCompleteParams",
             &result,
             check_nullr) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v43, ONOSCILLATECOMPLETE, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nulls) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onComplete",
             &result,
             check_nulls) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallback((UFG::UITween *)v43, ONCOMPLETE, (Scaleform::GFx::Value *)&v96);
      }
      LOBYTE(check_nullt) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "onCompleteParams",
             &result,
             check_nullt) )
      {
        v97 = &v96;
        v98 = 0i64;
        LODWORD(argsa.mPrev) = result.mData;
        v95 = *(_QWORD *)&result.mStringHash32;
        v96 = *(_QWORD *)&result.mStringHash32;
        if ( (LODWORD(result.mData) >> 6) & 1 )
        {
          v98 = *(_QWORD *)&result.mMagic;
          (*(void (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)&result.mMagic + 8i64))(
            *(_QWORD *)&result.mMagic,
            &v96);
        }
        UFG::UITween::SetCallbackParams((UFG::UITween *)v43, ONCOMPLETE, (Scaleform::GFx::Value *)&v96);
      }
      if ( UI_HASH_ADD_TWEEN_TO == v9 || UI_HASH_ADD_TWEEN_FROM == v9 )
      {
        v56 = 0;
        v57 = v43 + 76;
        while ( 1 )
        {
          switch ( v56 )
          {
            case 0:
              v58 = "x";
              goto LABEL_196;
            case 1:
              v58 = "y";
              goto LABEL_196;
            case 2:
              v58 = "z";
              goto LABEL_196;
            case 3:
              v58 = "alpha";
              goto LABEL_196;
            case 4:
              v58 = "scaleX";
              goto LABEL_196;
            case 5:
              v58 = "scaleY";
              goto LABEL_196;
            case 6:
              v58 = "scaleZ";
              goto LABEL_196;
            case 7:
              v58 = "rotation";
              goto LABEL_196;
            case 8:
              v58 = "rotationX";
              goto LABEL_196;
            case 9:
              v58 = "rotationY";
              goto LABEL_196;
            case 10:
              v58 = "fov";
LABEL_196:
              LOBYTE(check_nullu) = (v4[2].Type & 0x8F) == 10;
              if ( !(*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
                      v4[2].pObjectInterface,
                      *(_QWORD *)&v4[2].mValue.NValue,
                      v58,
                      &result,
                      check_nullu) )
                goto LABEL_214;
              if ( UI_HASH_ADD_TWEEN_TO == v9 )
              {
                v59 = (_QWORD)result.mData & 0x8F;
                if ( v59 == 3 )
                {
                  v60 = (float)(signed int)result.mStringHash32;
                }
                else if ( v59 == 4 )
                {
                  v60 = (float)(signed int)result.mStringHash32;
                }
                else
                {
                  v60 = *(double *)&result.mStringHash32;
                }
                *(_DWORD *)(v57 - 4) = -1082130432;
                *(float *)v57 = v60;
              }
              else
              {
                if ( UI_HASH_ADD_TWEEN_FROM != v9 )
                  goto LABEL_214;
                v61 = (_QWORD)result.mData & 0x8F;
                if ( v61 == 3 )
                {
                  v60 = (float)(signed int)result.mStringHash32;
                }
                else if ( v61 == 4 )
                {
                  v60 = (float)(signed int)result.mStringHash32;
                }
                else
                {
                  v60 = *(double *)&result.mStringHash32;
                }
                *(float *)(v57 - 4) = v60;
                *(_DWORD *)v57 = -1082130432;
              }
              v62 = 1;
              if ( v60 == -1.0 )
                v62 = 0;
              *(_BYTE *)(v57 + 4) = v62;
LABEL_214:
              ++v56;
              v57 += 12i64;
              if ( v56 >= 12 )
                goto LABEL_215;
              break;
            default:
              goto LABEL_214;
          }
        }
      }
LABEL_215:
      v63 = FLOAT_N1_0;
      v64 = FLOAT_N1_0;
      LOBYTE(check_nullu) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "txtStart",
             &result,
             check_nullu) )
      {
        v65 = (_QWORD)result.mData & 0x8F;
        if ( v65 == 3 )
        {
          v63 = (float)(signed int)result.mStringHash32;
        }
        else if ( v65 == 4 )
        {
          v63 = (float)(signed int)result.mStringHash32;
        }
        else
        {
          v63 = *(double *)&result.mStringHash32;
        }
      }
      LOBYTE(check_nullv) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "txtEnd",
             &result,
             check_nullv) )
      {
        v66 = (_QWORD)result.mData & 0x8F;
        if ( v66 == 3 )
        {
          v64 = (float)(signed int)result.mStringHash32;
        }
        else if ( v66 == 4 )
        {
          v64 = (float)(signed int)result.mStringHash32;
        }
        else
        {
          v64 = *(double *)&result.mStringHash32;
        }
      }
      if ( v63 != -1.0 && v64 != -1.0 )
      {
        *(float *)(v43 + 204) = v63;
        *(float *)(v43 + 208) = v64;
        if ( v63 == v64 )
          v55 = 0;
        *(_BYTE *)(v43 + 212) = v55;
      }
      LOBYTE(check_nullw) = (v4[2].Type & 0x8F) == 10;
      if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, UFG::qString *, __int64))&v4[2].pObjectInterface->vfptr->gap8[24])(
             v4[2].pObjectInterface,
             *(_QWORD *)&v4[2].mValue.NValue,
             "txtFormat",
             &result,
             check_nullw) )
      {
        if ( (LODWORD(result.mData) >> 6) & 1 )
          v67 = **(const char ***)&result.mStringHash32;
        else
          v67 = *(const char **)&result.mStringHash32;
        UFG::qString::Set((UFG::qString *)(v43 + 944), v67);
      }
      v68 = &UFG::UIScreenManager::s_instance->m_activeTweens;
      v69 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
      v69->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)v43;
      *(_QWORD *)v43 = v69;
      *(_QWORD *)(v43 + 8) = v68;
      v68->mNode.mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)v43;
      if ( (LODWORD(result.mData) >> 6) & 1 )
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
      if ( (unsigned int)retaddr < 1 || (v4->Type & 0x8F) != 6 )
        return;
      if ( ((unsigned int)v4->Type >> 6) & 1 )
        v33 = *v4->mValue.pStringManaged;
      else
        v33 = v4->mValue.pString;
      UFG::UIScreenManagerBase::killTweens(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v5,
        v33);
    }
    if ( v9 )
    {
      v34 = UFG::qBaseTreeRB::Get(&UFG::UIGfxExternalInterface::mCallbackFuncList.mTree, v9);
      if ( v34 )
      {
        if ( v34 != (UFG::qBaseTreeRB *)8 )
        {
          *(_QWORD *)&argsa.mMagic = 0i64;
          LODWORD(argsa.mData) = 0;
          v35 = (**(unsigned __int8 (__fastcall ***)(signed __int64, Scaleform::GFx::Movie *, Scaleform::GFx::Value *, _QWORD, UFG::qString *))&v34[-1].mCount)(
                  (signed __int64)&v34[-1].mCount,
                  v5,
                  v4,
                  (unsigned int)retaddr,
                  &argsa);
          Scaleform::GFx::Movie::SetExternalInterfaceRetVal(v5, (Scaleform::GFx::Value *)&argsa);
          v32 = LODWORD(argsa.mData) >> 6;
          if ( (_BYTE)v35 )
            goto LABEL_52;
          if ( v32 & 1 )
          {
            (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&argsa.mMagic + 16i64))(
              *(_QWORD *)&argsa.mMagic,
              &argsa,
              *(_QWORD *)&argsa.mStringHash32);
            *(_QWORD *)&argsa.mMagic = 0i64;
          }
          LODWORD(argsa.mData) = 0;
        }
      }
    }
    v36 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x68ui64, "UIGfxExternalInterface::Callback", 0i64, 1u);
    v97 = (__int64 *)v36;
    if ( v36 )
    {
      UFG::qString::qString(&argsa, &customWorldMapCaption);
      v7 = 2;
      LODWORD(v98) = 2;
      UFG::UIMessageFlash::UIMessageFlash((UFG::UIMessageFlash *)v36, v9, v5, &argsa);
      v6 = v37;
    }
    if ( v7 & 2 )
    {
      LODWORD(v98) = v7 & 0xFFFFFFFD;
      UFG::qString::~qString(&argsa);
    }
    UFG::UIScreenManagerBase::queueMessageEx((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, v6);
  }
}

