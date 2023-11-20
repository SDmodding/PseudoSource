// File Line: 146
// RVA: 0x5EE7F0
char __fastcall IsRemappable(unsigned int hash)
{
  unsigned int v1; // edx
  const unsigned int *v2; // rax

  v1 = 0;
  v2 = NonRemappable;
  while ( hash != *v2 )
  {
    ++v1;
    ++v2;
    if ( v1 >= 0x28 )
      return 1;
  }
  return 0;
}

// File Line: 161
// RVA: 0x5EEA60
char __fastcall UIHKDictionary::KeyTextureReplaced(unsigned int hash, UFG::qString *keyStr)
{
  UFG::qString *v2; // r14
  unsigned int v3; // edi
  int v4; // er15
  __int64 v5; // r8
  const unsigned int *v6; // rax
  int v7; // er15
  const char *v8; // rax
  char v9; // al
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  unsigned int v12; // ecx
  const unsigned int *v13; // rax
  unsigned int *v14; // rsi
  const char **v15; // rbx
  signed __int64 v16; // r12
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  const char *v19; // rax
  char v20; // al
  UFG::qString *v21; // rax
  UFG::qString *v22; // rax
  UFG::UI::eButtons v23; // ebx
  char v24; // al
  char *v25; // rax
  char v26; // al
  UFG::UI::eButtons v27; // ecx
  unsigned int v28; // eax
  char *v29; // rdx
  char v30; // al
  const char **v32; // rbx
  signed __int64 v33; // rdi
  UFG::qString rhs; // [rsp+30h] [rbp-A8h]
  UFG::qString v35; // [rsp+58h] [rbp-80h]
  const char *v36; // [rsp+80h] [rbp-58h]
  const char *v37; // [rsp+88h] [rbp-50h]
  const char *v38; // [rsp+90h] [rbp-48h]
  const char *v39; // [rsp+98h] [rbp-40h]
  char *v40; // [rsp+A0h] [rbp-38h]
  const char *v41; // [rsp+A8h] [rbp-30h]
  char *v42; // [rsp+B0h] [rbp-28h]
  char *v43; // [rsp+B8h] [rbp-20h]
  const char *v44; // [rsp+C0h] [rbp-18h]
  const char *v45; // [rsp+C8h] [rbp-10h]
  const char *v46; // [rsp+D0h] [rbp-8h]
  const char *v47; // [rsp+D8h] [rbp+0h]
  const char *v48; // [rsp+E0h] [rbp+8h]
  const char *v49; // [rsp+E8h] [rbp+10h]
  UFG::qString attribute; // [rsp+F8h] [rbp+20h]
  __int64 v51; // [rsp+120h] [rbp+48h]
  UFG::qString v52; // [rsp+128h] [rbp+50h]
  UFG::qString result; // [rsp+150h] [rbp+78h]
  UFG::qString v54; // [rsp+178h] [rbp+A0h]
  UFG::qString v55; // [rsp+1A0h] [rbp+C8h]

  v51 = -2i64;
  v2 = keyStr;
  v3 = hash;
  UFG::qString::ReplaceString(keyStr, "\"", "", 0);
  v4 = 0;
  v5 = 0i64;
  v6 = MeleeHints;
  while ( v3 != *v6 )
  {
    v5 = (unsigned int)(v5 + 1);
    ++v6;
    if ( (unsigned int)v5 >= 5 )
      goto LABEL_8;
  }
  UFG::qString::qString(&v35, "BUTTON_MOUSE_M", v5);
  v7 = UFG::qString::ReplaceString(v2, "BUTTON_R_STICK", v35.mData, 0);
  v8 = &customWorldMapCaption;
  if ( REMAP_ID_MELEE_ATTACK_2 != REMAP_ID_INVALID_2 )
  {
    v9 = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_MELEE_ATTACK_2);
    v8 = UFG::KeyToTextureName(v9);
  }
  UFG::qString::qString(&rhs, v8);
  v10 = UFG::operator+(&result, "", &rhs);
  v11 = UFG::operator+(&v52, v10, "");
  UFG::qString::Set(&rhs, v11->mData, v11->mLength, 0i64, 0);
  UFG::qString::~qString(&v52);
  UFG::qString::~qString(&result);
  v4 = (unsigned __int64)UFG::qString::ReplaceString(v2, "BUTTON_R2", rhs.mData, 0) + v7;
  UFG::qString::~qString(&rhs);
  UFG::qString::~qString(&v35);
LABEL_8:
  v12 = 0;
  v13 = DrivingHints;
  while ( v3 != *v13 )
  {
    ++v12;
    ++v13;
    if ( v12 >= 0x1B )
      goto LABEL_18;
  }
  v35.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_R2";
  v35.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_L2";
  *(_QWORD *)&v35.mMagic = &customWorldMapCaption;
  v35.mData = &customWorldMapCaption;
  *(_QWORD *)&v35.mStringHash32 = "BUTTON_BACK";
  v36 = "BUTTON_R1";
  v37 = "BUTTON_L1";
  v38 = "BUTTON_BUTTON1";
  v39 = "BUTTON_R3";
  v40 = &customWorldMapCaption;
  v41 = "BUTTON_ACCEPT";
  v42 = &customWorldMapCaption;
  v43 = &customWorldMapCaption;
  v14 = (unsigned int *)DrivingRemapIds_0;
  v15 = (const char **)&v35;
  v16 = 13i64;
  do
  {
    UFG::qString::qString(&rhs, *v15);
    if ( rhs.mLength )
    {
      v17 = UFG::operator+(&v52, "", &rhs);
      v18 = UFG::operator+(&result, v17, "");
      UFG::qString::Set(&rhs, v18->mData, v18->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v52);
      v19 = &customWorldMapCaption;
      if ( *v14 != REMAP_ID_INVALID_2 )
      {
        v20 = UFG::UIHKScreenOptionsButtonMapping::GetKey(*v14);
        v19 = UFG::KeyToTextureName(v20);
      }
      UFG::qString::qString(&v35, v19);
      v21 = UFG::operator+(&v54, "", &v35);
      v22 = UFG::operator+(&v55, v21, "");
      UFG::qString::Set(&v35, v22->mData, v22->mLength, 0i64, 0);
      UFG::qString::~qString(&v55);
      UFG::qString::~qString(&v54);
      v4 += UFG::qString::ReplaceString(v2, rhs.mData, v35.mData, 0);
      UFG::qString::~qString(&v35);
    }
    UFG::qString::~qString(&rhs);
    ++v15;
    ++v14;
    --v16;
  }
  while ( v16 );
LABEL_18:
  v23 = 1;
  do
  {
    v24 = IsRemappable(v3);
    v25 = UFG::UI::GetGamepadButtonTextureName(v23, v24);
    UFG::qString::qString(&rhs, v25);
    v26 = IsRemappable(v3);
    v27 = v23;
    if ( !v26 )
      goto LABEL_24;
    v28 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v23, 0);
    v29 = &customWorldMapCaption;
    if ( v28 != REMAP_ID_INVALID_2 )
    {
      v30 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v28);
      v29 = (char *)UFG::KeyToTextureName(v30);
    }
    if ( !*v29 )
    {
      v27 = v23;
LABEL_24:
      v29 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v27);
    }
    UFG::qString::qString(&v35, v29);
    v4 += UFG::qString::ReplaceString(v2, rhs.mData, v35.mData, 0);
    UFG::qString::~qString(&v35);
    UFG::qString::~qString(&rhs);
    ++v23;
  }
  while ( (unsigned int)v23 < 0x1B );
  if ( !v4 )
    return 0;
  v35.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_ARROW_LR";
  v35.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_ARROW_UD";
  *(_QWORD *)&v35.mMagic = "BUTTON_BACKSLASH";
  v35.mData = "BUTTON_BACKSPACE";
  *(_QWORD *)&v35.mStringHash32 = "BUTTON_CAPSLOCK";
  v36 = "BUTTON_CTRL";
  v37 = "BUTTON_LCTRL";
  v38 = "BUTTON_RCTRL";
  v39 = "BUTTON_ENTER";
  v40 = "BUTTON_NUMZERO";
  v41 = "BUTTON_SHIFT";
  v42 = "BUTTON_LSHIFT";
  v43 = "BUTTON_RSHIFT";
  v44 = "BUTTON_SPACE";
  v45 = "BUTTON_TAB";
  v46 = "BUTTON_MOUSE4";
  v47 = "BUTTON_MOUSE5";
  v48 = "BUTTON_LALT";
  v49 = "BUTTON_RALT";
  UFG::qString::qString(&attribute, "width=");
  v32 = (const char **)&v35;
  v33 = 19i64;
  do
  {
    UIHKDictionary::AdjustAttribute(v2, *v32, &attribute, 2.0);
    ++v32;
    --v33;
  }
  while ( v33 );
  UFG::qString::Set(&attribute, "vspace=");
  UIHKDictionary::AdjustAttribute(v2, attribute.mData, &attribute, 0.5);
  UFG::qString::~qString(&attribute);
  return 1;
}

// File Line: 251
// RVA: 0x5D31B0
void __fastcall UIHKDictionary::AdjustAttribute(UFG::qString *strKey, const char *marker, UFG::qString *attribute, float adjustment)
{
  UFG::qString *v4; // rbx
  const char *v5; // rdi
  UFG::qString *v6; // r13
  UFG::qString *v7; // rax
  const char *v8; // rsi
  int v9; // er12
  int i; // edi
  unsigned int v11; // er14
  unsigned int v12; // esi
  unsigned int v13; // er15
  int v14; // esi
  signed int v15; // eax
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  int v19; // eax
  UFG::qString rhs; // [rsp+30h] [rbp-98h]
  UFG::qString result; // [rsp+58h] [rbp-70h]
  char *nptr; // [rsp+90h] [rbp-38h]
  UFG::qString lhs; // [rsp+A0h] [rbp-28h]
  UFG::qString v24; // [rsp+C8h] [rbp+0h]
  UFG::qString v25; // [rsp+F0h] [rbp+28h]
  UFG::qString v26; // [rsp+118h] [rbp+50h]
  UFG::qString v27; // [rsp+140h] [rbp+78h]
  char *str; // [rsp+1C0h] [rbp+F8h]
  char *v29; // [rsp+1C8h] [rbp+100h]

  rhs.mData = (char *)-2i64;
  v4 = attribute;
  v5 = marker;
  v6 = strKey;
  v7 = UFG::qString::ToUpper(attribute, &result);
  UFG::qString::ReplaceString(v6, v7->mData, v4->mData, 0);
  UFG::qString::~qString(&result);
  v8 = v4->mData;
  v29 = v4->mData;
  v9 = v4->mLength;
  for ( i = UFG::qString::find(v6, v5); i != UFG::qString::npos; v8 = v29 )
  {
    UFG::qString::Substring(v6, &rhs, i, -1);
    v11 = UFG::qString::find(&rhs, v8);
    UFG::qString::Substring(&rhs, &result, v11 + v9, -1);
    v12 = UFG::qString::find(&result, "");
    if ( v12 != UFG::qString::npos )
      v12 += v11 + v9;
    v13 = UFG::qString::find(&rhs, ">");
    if ( v12 == UFG::qString::npos || v11 >= v12 || v13 == UFG::qString::npos || v11 >= v13 )
    {
      i = UFG::qString::npos;
    }
    else
    {
      v14 = v12 - v11 - v9;
      UFG::qString::Substring(v6, &lhs, 0, v9 + v11 + i);
      UFG::qString::Substring(v6, (UFG::qString *)((char *)&rhs + 32), v9 + i + v14 + v11, -1);
      UFG::qString::Substring(v6, (UFG::qString *)((char *)&result + 32), v9 + v11 + i, v14);
      v15 = atol(nptr);
      v16 = UFG::qString::FormatEx(&v27, "%d", (unsigned int)(signed int)(float)((float)v15 * adjustment));
      v17 = UFG::operator+(&v26, &lhs, v16);
      v18 = UFG::operator+(&v25, v17, (UFG::qString *)((char *)&rhs + 32));
      UFG::qString::Set(v6, v18->mData, v18->mLength, 0i64, 0);
      UFG::qString::~qString(&v25);
      UFG::qString::~qString(&v26);
      UFG::qString::~qString(&v27);
      UFG::qString::Substring(v6, &v24, v13 + i, -1);
      v19 = UFG::qString::find(&v24, str);
      if ( v19 == UFG::qString::npos )
        i = UFG::qString::npos;
      else
        i += v13 + v19;
      UFG::qString::~qString(&v24);
      UFG::qString::~qString((UFG::qString *)((char *)&result + 32));
      UFG::qString::~qString((UFG::qString *)((char *)&rhs + 32));
      UFG::qString::~qString(&lhs);
    }
    UFG::qString::~qString(&result);
    UFG::qString::~qString(&rhs);
  }
}

// File Line: 302
// RVA: 0x5C3F00
void __fastcall UIHKGFxTranslator::UIHKGFxTranslator(UIHKGFxTranslator *this)
{
  UIHKGFxTranslator *v1; // rsi
  UFG::qString *v2; // rbx
  signed __int64 v3; // rdi

  v1 = this;
  UFG::UIGfxTranslator::UIGfxTranslator((UFG::UIGfxTranslator *)&this->vfptr);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UIHKGFxTranslator::`vftable;
  v2 = v1->mTranslatedStrings;
  v3 = 512i64;
  `eh vector constructor iterator(
    v1->mTranslatedStrings,
    0x28ui64,
    512,
    (void (__fastcall *)(void *))UFG::qString::qString);
  v1->mCurrentStringIndex = 0;
  do
  {
    UFG::qString::Set(v2, &customWorldMapCaption);
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 316
// RVA: 0x612DE0
void __fastcall UIHKGFxTranslator::Translate(UIHKGFxTranslator *this, Scaleform::GFx::Translator::TranslateInfo *ptranslateInfo)
{
  Scaleform::GFx::Translator::TranslateInfo *v2; // rbx
  UIHKGFxTranslator *v3; // r14
  const wchar_t *v4; // rsi
  int v5; // eax
  int v6; // edi
  char *v7; // rax
  char *v8; // rbp
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  char *v12; // rax
  char *v13; // rsi
  bool v14; // di
  void *v15; // rcx
  unsigned int v16; // eax
  unsigned int v17; // er14
  unsigned int v18; // er15
  UFG::allocator::free_link *v19; // rax
  wchar_t *v20; // rdi
  UFG::qString keyStr; // [rsp+28h] [rbp-40h]

  if ( ptranslateInfo )
  {
    v2 = ptranslateInfo;
    v3 = this;
    v4 = ptranslateInfo->pKey;
    v5 = UFG::qStringLength(ptranslateInfo->pKey);
    v6 = v5;
    if ( v5 )
    {
      if ( v3->mLanguage )
      {
        if ( *v4 == 36 && v5 != 1 )
          goto LABEL_13;
      }
      else
      {
        if ( !gUIShowIconsInBlankLoc || (unsigned __int16)(*v4 - 48) > 9u && *v4 != 45 )
        {
LABEL_13:
          v7 = (char *)UFG::qMalloc(v5, &customWorldMapCaption, 0i64);
          v8 = v7;
          if ( !v7 )
            return;
          v9 = v6 - 1;
          UFG::qWideStringCopy(v7, v4 + 1);
          if ( v8[v9 - 1] == 13 )
            v8[v9 - 1] = 0;
          UFG::qString::qString(&keyStr);
          v10 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
          v11 = v10;
          v12 = UFG::UIGfxTranslator::Translate((UFG::UIGfxTranslator *)&v3->vfptr, v10);
          UFG::qString::Set(&keyStr, v12);
          if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController == 1 )
            UIHKDictionary::KeyTextureReplaced(v11, &keyStr);
          v13 = keyStr.mData;
          v14 = keyStr.mData != 0i64;
          if ( v3->mLanguage
            || gUIShowIconsInBlankLoc
            && keyStr.mData
            && !(unsigned int)UFG::qStringCompareInsensitive(keyStr.mData, "<img", 4) )
          {
            if ( v14 )
            {
              v16 = UFG::qStringLength(v13);
              v17 = v16;
              v18 = 2 * v16 + 2;
              v19 = UFG::qMalloc(v18, &customWorldMapCaption, 0i64);
              v20 = (wchar_t *)v19;
              if ( v19 )
              {
                UFG::qMemSet(v19, 0, v18);
                Scaleform::UTF8Util::DecodeString(v20, v13, v17);
                if ( v2->Flags & 4 )
                {
                  Scaleform::GFx::Translator::TranslateInfo::SetResult(v2, v20, v17);
                  v2->Flags |= 2u;
                }
                else
                {
                  Scaleform::GFx::Translator::TranslateInfo::SetResult(v2, v20, v17);
                }
                operator delete[](v8);
                v15 = v20;
                goto LABEL_30;
              }
            }
          }
          else
          {
            Scaleform::GFx::Translator::TranslateInfo::SetResult(v2, &customWorldMapCaption, 0i64);
          }
          v15 = v8;
LABEL_30:
          operator delete[](v15);
          UFG::qString::~qString(&keyStr);
          return;
        }
        if ( v2->Flags & 4 )
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(v2, v4, v5);
          v2->Flags |= 2u;
        }
        else
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(v2, v4, v5);
        }
      }
    }
  }
}

// File Line: 419
// RVA: 0x612D30
char *__fastcall UIHKGFxTranslator::Translate(UIHKGFxTranslator *this, unsigned int hash)
{
  unsigned int v2; // edi
  UIHKGFxTranslator *v3; // rbx
  char *result; // rax
  const char *v5; // rdx
  signed int v6; // eax

  v2 = hash;
  v3 = this;
  result = UFG::UIGfxTranslator::Translate((UFG::UIGfxTranslator *)&this->vfptr, hash);
  v5 = result;
  if ( result )
  {
    v6 = ++v3->mCurrentStringIndex;
    if ( v6 >= 512 )
      v6 = 0;
    v3->mCurrentStringIndex = v6;
    UFG::qString::Set((UFG::qString *)&(&v3->vfptr)[v6 + 4i64 * v6 + 18], v5);
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController == 1 )
      UIHKDictionary::KeyTextureReplaced(
        v2,
        (UFG::qString *)&(&v3->vfptr)[v3->mCurrentStringIndex + 4i64 * v3->mCurrentStringIndex + 18]);
    result = v3->mTranslatedStrings[v3->mCurrentStringIndex].mData;
  }
  return result;
}

